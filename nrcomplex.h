#define inf 1000000
class Matrice_Complexa;
class Numar_Complex
{
double pi,pr;
public:
    friend class Matrice_Complexa;
    friend std::istream& operator>> (std::istream& is, Numar_Complex& op);
    friend std::ostream& operator<< (std::ostream& is, Numar_Complex& op);
    friend Numar_Complex  operator + (const Numar_Complex& nr1, const Numar_Complex& nr2);
    friend Numar_Complex  operator * (const Numar_Complex& nr1, const Numar_Complex& nr2);

    friend Numar_Complex  operator / (const Numar_Complex& nr1, const Numar_Complex& nr2);
    Numar_Complex(double x = 0, double y = 0):pr(x),pi(y)
    {

    }
    Numar_Complex(const Numar_Complex&ob):pi(ob.pi),pr(ob.pr)
    {
    }
    Numar_Complex& operator = (const Numar_Complex& ob);
    ~Numar_Complex()
    {
        pi = 0;
        pr = 0;
    }
    void set_Numar_Complex(double x, double y)
    {
        pi = x;
        pr = y;
    }
    void afisare()
    {
        if (pi == 0 && pr == 0)
            std::cout<<0;
        else if (pr == 0 && pi <0)
            std::cout<<"-i*"<<(-pi);
        else if (pr == 0 && pi > 0)
            std::cout<<"i"<<pi;
        else if (pi == 0)
            std::cout<<pr;
        else if (pr != 0 && pi > 0)
            std::cout<<pr<<"+i*"<<pi;
        else if (pr != 0 && pi < 0)
            std::cout<<pr<<"-i*"<<(-pi);
        std::cout << std::endl;
    }
    double modul()
    {
        return sqrt(pr * pr + pi * pi);
    }

    double radical()
    {
        double r = modul();
        Numar_Complex temp(pr+r,pi);
        double aux = temp.modul();
        return sqrt(r)*(temp.pr+temp.pi)/aux;

    }
};

Numar_Complex operator + (const Numar_Complex& nr1, const Numar_Complex& nr2)
{
    return Numar_Complex(nr1.pr+nr2.pr,nr1.pi+nr2.pi);
}
Numar_Complex operator * (const Numar_Complex& nr1, const Numar_Complex& nr2)
{
    return Numar_Complex(nr1.pr*nr2.pr,nr1.pi*nr2.pi);
}
Numar_Complex operator / (const Numar_Complex& nr1, const Numar_Complex& nr2)
{
    if (nr2.pr == 0 || nr2.pi == 0)
        return Numar_Complex(inf,inf);
    return Numar_Complex(nr1.pr/nr2.pr,nr2.pi/nr2.pi);
}

Numar_Complex& Numar_Complex  :: operator = (const Numar_Complex& ob)
{
    if(this != &ob)
    {
        pi = ob.pi;
        pr = ob.pr;
    }
    return *this;

}

std::istream& operator>> (std::istream& is, Numar_Complex& op)
    {
                    std::cout << "Parte reala:";
                    is >> op.pr;
                    std::cout << "Parte imaginara:";
                    is >> op.pi;

    return is;
    }
std::ostream& operator << (std::ostream& os, Numar_Complex& op)
    {
                os << "(" << op.pr << "," << op.pi <<")";
                std::cout << std::endl;

    return os;
    }





