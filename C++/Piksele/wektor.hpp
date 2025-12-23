class wektor
{
private:
    int x, y;

public:
    wektor();
    wektor(int nx, int ny);

    void set_x(int xval);
    void set_y(int yval);

    int get_x() const;
    int get_y() const;    
};