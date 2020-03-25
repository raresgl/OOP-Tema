
class Matrice_Complexa{
private:
int l,c;
Numar_Complex **M;

public:
    Matrice_Complexa(Numar_Complex x, int y = 0, int z = 0)
    {
        l=y;
        c=z;
        M = new Numar_Complex *[y+1];
        for(int i = 1; i <= y; i++)
            M[i]=new Numar_Complex[z+1];
        for(int i = 1; i <= y; i++ )
            for(int j= 1;j<=z;j++)
                M[i][j] = x;
    }
     Matrice_Complexa(int y = 0, int z = 0)
    {
        l=y;
        c=z;
         M = new Numar_Complex *[y+1];
        for(int i = 1; i <= y; i++)
            M[i]=new Numar_Complex[z+1];
        for(int i = 1; i <= y; i++ )
            for(int j= 1;j<=z;j++)
                M[i][j] = (0,0);
    }
        Matrice_Complexa(Matrice_Complexa &ob)
        {
            l = ob.l;
            c = ob.c;
            for(int i=1;i<=l;i++)
                for(int j=1;j<=c;j++)
                {
                    M[i][j] = ob.M[i][j];
                }
        }


         ~Matrice_Complexa()
        {
            for(int i = 1; i <= l; i++ )
                delete[] M[i];
            delete[] M;
        }
friend  std::istream& operator>> (std::istream& is, Matrice_Complexa& op);
friend  std::ostream& operator << (std::ostream& os, Matrice_Complexa& op);
friend Matrice_Complexa operator+ (Matrice_Complexa &m1, Matrice_Complexa &m2 );
friend Matrice_Complexa operator* (Matrice_Complexa &m1, Matrice_Complexa &m2 );


};

std::istream& operator>> (std::istream& is, Matrice_Complexa& op)
    {
    for(int i = 1; i <= op.l; i++ )
            for(int j= 1;j<=op.c;j++)
                {   std::cout << "M[" << i << "][" << j << "]" << std::endl;
                    is >> op.M[i][j];
                }
    return is;
    }
std::ostream& operator << (std::ostream& os, Matrice_Complexa& op)
    {
    std::cout << std::endl;
    for(int i = 1; i <= op.l; i++ )
            {
                for(int j= 1;j<=op.c;j++)
                    os << op.M[i][j];
                std::cout << std::endl;
            }
    return os;
    }

Matrice_Complexa operator+ (Matrice_Complexa &m1, Matrice_Complexa &m2 )
{
    Matrice_Complexa rez(m1.l,m1.c);
    for(int i=1;i<=m1.l;i++)
                for(int j=1;j<=m1.c;j++)
                {
                    rez.M[i][j] = m1.M[i][j] + m2.M[i][j];
                }
    return rez;
}
Matrice_Complexa operator* (Matrice_Complexa &m1, Matrice_Complexa &m2 )
{
    Matrice_Complexa rez(m1.l,m1.c);
    for(int i=1;i<=m1.l;i++)
                for(int j=1;j<=m1.c;j++)
                {
                    rez.M[i][j] = m1.M[i][j] * m2.M[i][j];
                }
    return rez;
}
