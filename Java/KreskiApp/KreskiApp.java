import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;

/**
 * Aplikacja AWT do rysowania kolorowych kresek (odcinków).
 * - Kreska: dwa punkty + kolor
 * - Powierzchnia: Canvas rysujący kolekcję kresek i umożliwiający tworzenie przez drag
 * - Po prawej: wybór koloru (List oraz radiobuttony CheckboxGroup)
 * - Klawiatura: Backspace = usuń wszystkie; F = usuń pierwszą; B lub L = usuń ostatnią
 */
public class KreskiApp {

    public static class Kreska {
        protected Point poczatek, koniec;
        protected Color kolor;

        public Kreska(Point pocz, Point kon, Color kol) {
            this.poczatek = new Point(pocz);
            this.koniec = new Point(kon);
            this.kolor = kol;
        }
    }

    public static class Powierzchnia extends Canvas implements MouseListener, MouseMotionListener {
        private final ArrayList<Kreska> rysunek;
        private Point startPoint = null;
        private Point currentPoint = null;
        private boolean dragging = false;
        private boolean leftDuringDrag = false;
        private Color currentColor = Color.BLACK;

        public Powierzchnia(ArrayList<Kreska> rysunek) {
            this.rysunek = rysunek;
            setBackground(Color.WHITE);
            addMouseListener(this);
            addMouseMotionListener(this);

            setFocusable(true); // odbieranie event z klawiatury
        }

        public void setCurrentColor(Color c) {
            if (c != null) currentColor = c;
        }

        @Override
        public void paint(Graphics gr) {
            synchronized (rysunek) {
                for (Kreska k : rysunek) {
                    gr.setColor(k.kolor);
                    gr.drawLine(k.poczatek.x, k.poczatek.y, k.koniec.x, k.koniec.y);
                }
            }

            if (dragging && startPoint != null && currentPoint != null) {
                gr.setColor(Color.LIGHT_GRAY);
                gr.drawLine(startPoint.x, startPoint.y, currentPoint.x, currentPoint.y);
            }
        }

        @Override
        public void mousePressed(MouseEvent e) {
            if ((e.getModifiersEx() & MouseEvent.BUTTON1_DOWN_MASK) != 0) {
                requestFocus(); // żeby potem działała obsługa klawiatury
                startPoint = new Point(e.getX(), e.getY());
                currentPoint = new Point(startPoint);
                dragging = true;
                leftDuringDrag = false;
                repaint();
            }
        }

        @Override
        public void mouseReleased(MouseEvent e) {
            if (!dragging) return;
            int x = e.getX(), y = e.getY();
            boolean inside = x >= 0 && y >= 0 && x < getWidth() && y < getHeight();

            if (!leftDuringDrag && inside) {
                Point kon = new Point(x, y);
                Point pocz = new Point(startPoint);
                Kreska k = new Kreska(pocz, kon, currentColor);
                synchronized (rysunek) {
                    rysunek.add(k);
                }
            }

            dragging = false;
            startPoint = null;
            currentPoint = null;
            repaint();
        }

        @Override
        public void mouseDragged(MouseEvent e) {
            if (!dragging) return;
            currentPoint = new Point(e.getX(), e.getY());
            repaint();
        }

        @Override
        public void mouseExited(MouseEvent e) {
            if (dragging) {
                leftDuringDrag = true;
            }
        }

        @Override
        public void mouseEntered(MouseEvent e) { /* nie wracamy leftDuringDrag */ }

        @Override
        public void mouseClicked(MouseEvent e) { /* nieużywane */ }

        @Override
        public void mouseMoved(MouseEvent e) { /* nieużywane */ }
    }

    public static class GlowneOkno extends Frame implements KeyListener {
        private final ArrayList<Kreska> rysunek = new ArrayList<>();
        private final Powierzchnia powierzchnia;

        private static final String[] colorNames = {
                "Czarny", "Czerwony", "Zielony", "Niebieski", "Żółty", "Magenta", "Cyan", "Pomarańczowy", "Szary"
        };
        private static final Color[] colors = {
                Color.BLACK, Color.RED, Color.GREEN, Color.BLUE, Color.YELLOW, Color.MAGENTA, Color.CYAN, Color.ORANGE, Color.GRAY
        };

        public GlowneOkno() {
            super("Kreskownik");
            setLayout(new BorderLayout());
            setSize(900, 600);
            setLocationRelativeTo(null);

            // Workspace
            powierzchnia = new Powierzchnia(rysunek);
            add(powierzchnia, BorderLayout.CENTER);

            // Panel Kolorów
            Panel prawy = new Panel();
            prawy.setLayout(new BorderLayout());
            prawy.setPreferredSize(new Dimension(180, 0));

            Label instrukcja = new Label("< Wybierz kolor >", Label.CENTER);
            prawy.add(instrukcja, BorderLayout.NORTH);

            final List listaKolorow = new List();
            for (String n : colorNames) listaKolorow.add(n);
            listaKolorow.select(0);

            listaKolorow.addItemListener(new ItemListener() {
                @Override
                public void itemStateChanged(ItemEvent e) {
                    int idx = listaKolorow.getSelectedIndex();
                    if (idx >= 0 && idx < colors.length) {
                        powierzchnia.setCurrentColor(colors[idx]);
                    }
                }
            });
            prawy.add(listaKolorow, BorderLayout.CENTER);

            Panel radioPanel = new Panel();
            radioPanel.setLayout(new GridLayout(colors.length, 1));
            CheckboxGroup cbg = new CheckboxGroup();
            for (int i = 0; i < colorNames.length; i++) {
                Checkbox c = new Checkbox(colorNames[i], cbg, i == 0);
                final int idx = i;
                c.addItemListener(new ItemListener() {
                    @Override
                    public void itemStateChanged(ItemEvent e) {
                        if (c.getState()) {
                            powierzchnia.setCurrentColor(colors[idx]);
                            listaKolorow.select(idx);
                        }
                    }
                });
                radioPanel.add(c);
            }
            prawy.add(radioPanel, BorderLayout.SOUTH);

            add(prawy, BorderLayout.EAST);

            addKeyListener(this);
            powierzchnia.addKeyListener(this);

            addWindowListener(new WindowAdapter() {
                public void windowClosing(WindowEvent we) {
                    dispose();
                    System.exit(0);
                }
            });

            setVisible(true);

            powierzchnia.requestFocus();
        }

        @Override
        public void keyTyped(KeyEvent e) { /* nieużywane */ }

        @Override
        public void keyPressed(KeyEvent e) {
            int code = e.getKeyCode();
            boolean changed = false;


            if (code == KeyEvent.VK_BACK_SPACE) {
                synchronized (rysunek) {
                    if (!rysunek.isEmpty()) {
                        rysunek.clear();
                        changed = true;
                    }
                }
            } else {
                char ch = e.getKeyChar();
                if (Character.toUpperCase(ch) == 'F') {
                    synchronized (rysunek) {
                        if (!rysunek.isEmpty()) {
                            rysunek.remove(0);
                            changed = true;
                        }
                    }
                }
                if (Character.toUpperCase(ch) == 'B' || Character.toUpperCase(ch) == 'L') {
                    synchronized (rysunek) {
                        if (!rysunek.isEmpty()) {
                            rysunek.remove(rysunek.size() - 1);
                            changed = true;
                        }
                    }
                }
            }

            if (changed) {
                powierzchnia.repaint();
            }
        }

        @Override
        public void keyReleased(KeyEvent e) { /* nieużywane */ }
    }

    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                new GlowneOkno();
            }
        });
    }
}
