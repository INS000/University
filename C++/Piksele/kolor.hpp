#include<string>

class kolor
{
protected:
    unsigned char r, g, b;
    
public:
    kolor();
    kolor(int red, int green, int blue);

    unsigned char get_r() const;
    unsigned char get_g() const;
    unsigned char get_b() const;

    void set_r(int red);
    void set_g(int green);
    void set_b(int blue);

    void saturation(int val);

    static kolor fusion(const kolor &col1, const kolor &col2);

    friend std::ostream& operator<<(std::ostream& stream, const kolor &c);
};

std::ostream& operator<<(std::ostream& stream, const kolor &c);

class kolortransparentny : public virtual kolor{
protected:
    unsigned char alfa;

public:
    kolortransparentny(); 
    kolortransparentny(int red, int green, int blue, int a); 

    unsigned char get_alfa() const;

    void set_alfa(int a);   

    friend std::ostream& operator<<(std::ostream& stream, const kolortransparentny &c);
};

std::ostream& operator<<(std::ostream& stream, const kolortransparentny &c);

class kolornazwany : public virtual kolor{
    std::string name;

public:
    kolornazwany();
    kolornazwany(int red, int green, int blue, std::string nam);

    std::string get_name() const;

    void set_name(std::string nam);

    friend std::ostream& operator<<(std::ostream& stream, const kolornazwany &c);
};

std::ostream& operator<<(std::ostream& stream, const kolornazwany &c);

class kolornt : public kolortransparentny, public kolornazwany{
public:
    kolornt();
    kolornt(int red, int green, int blue, int a, std::string nam);

    friend std::ostream& operator<<(std::ostream& stream, const kolornt &c);
};

std::ostream& operator<<(std::ostream& stream, const kolornt &c);