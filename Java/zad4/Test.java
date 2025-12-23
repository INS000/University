import asoc.*;

public class Test {
    public static void main(String[] args) {
        ArraySetVar vars = new ArraySetVar(3);

        vars.set("x", 2.5);
        vars.set("y", 10.0);

        vars.addPair(new PairProb("p", 0.7));

        System.out.println("Zawartość (AssociativeCollection format): " + vars.toString());

        System.out.println("size() = " + vars.size());
        System.out.println("search('x') = " + vars.search("x"));
        System.out.println("search('z') = " + vars.search("z"));
        System.out.println("get('y') = " + vars.get("y"));
        System.out.println("names:");
        for (String n : vars.names()) System.out.print(n + " ");

        System.out.println();
        vars.del("y");
        System.out.println("Po del('y'), zawartość: " + vars.toString() + ", size=" + vars.size());

        ArraySetVar cloned = vars.clone();
        System.out.println("Sklonowany: " + cloned.toString());

        cloned.set("x", 99.99);
        System.out.println("Po zmianie w klonie: clon=" + cloned.toString() + ", orig=" + vars.toString());

        try {
            new PairProb("q", 1.5);
        } catch (IllegalArgumentException ex) {
            System.out.println("Poprawnie wykryto niepoprawne prawdopodobieństwo: " + ex.getMessage());
        }

        try {
            new Pair("InvalidKey", 1.0);
        } catch (IllegalArgumentException ex) {
            System.out.println("Poprawnie wykryto niepoprawny klucz: " + ex.getMessage());
        }

        cloned.clear();
        System.out.println("Po clear() na klonie: clon size=" + cloned.size() + ", clon=" + cloned.toString());
        System.out.println("Oryginał nadal: orig size=" + vars.size() + ", orig=" + vars.toString());
    }
}
