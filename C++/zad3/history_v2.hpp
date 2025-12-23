
class liczba
{
    private:
    double actual;
    const static int his_size = 3;
    double *history;
    int contain, element;

    public:
    liczba(double l);
    liczba();
    liczba(const liczba& l);
    liczba(liczba && l);
    const liczba& operator=(const liczba& l);
    const liczba& operator=(liczba&& l);
    ~liczba();
    double get_val();
    void set_val(double l);
    double undo();
};