#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstring>
using namespace std;
///istream fin("date.in");
///ofstream fout("date.out");
const int nmax=1001;
class Nod
{
    int info;
    Nod *next;
public:
    Nod(const int x=0,Nod *urmator=NULL)
    {
        info = x;
        next = urmator;
    }
    ~Nod()
    {
        next = NULL;
    }
    inline Nod* get_next() const
    {
        return next;
    }
    inline int get_info() const
    {
        return info;
    }
    void set_next(Nod* urmator)
    {
        next = urmator;
    }
    void set_info(const int x)
    {
        info = x;
    }
};
int poz;
class Lista_circulara
{
private:
    Nod *first=NULL;
    Nod *last;
    Nod *copie_de_parcurs;
public:
    Lista_circulara circulara()
    {
        first=NULL;
    }
    void Adauga_element(int element,int pozitie)
    {
        Nod *nod_nou=new Nod;
        nod_nou->set_info(element);
        if(first==NULL)
        {
            first=nod_nou;
            last=first;
        }
        else
        {
            int cnt=1;
            copie_de_parcurs=first;
            while(cnt+1!=pozitie)
            {
                cnt++;
                copie_de_parcurs=copie_de_parcurs->get_next();
                ///first=first->next;
            }
            nod_nou->set_next(copie_de_parcurs->get_next());
            copie_de_parcurs->set_next(nod_nou);
        }
    }
    void Stergere_element(int pozitie)
    {
        Nod *nod_nou;
        if(pozitie==1)
        {
            nod_nou=first;
            first=first->get_next();
            delete(nod_nou);
        }
        else
        {
            int cnt=1;
            copie_de_parcurs=first;
            while(cnt+1!=pozitie)
            {
                ++cnt;
                copie_de_parcurs=copie_de_parcurs->get_next();
                ///first=first->next;
            }
            nod_nou=copie_de_parcurs->get_next();
            copie_de_parcurs->set_next(copie_de_parcurs->get_next()->get_next());
            delete(nod_nou);

        }
    }
    void Inversare_legaturi()
    {
        Nod *list=first;
        Nod *temporara = list;
        Nod *inversa = NULL;
        while(temporara != NULL)
        {
            list = list->get_next();
            temporara->set_next(inversa);
            inversa = temporara;
            temporara = list;
        }
        first=inversa;
    }
    void afisare()
    {
        copie_de_parcurs=first;
        while(copie_de_parcurs!=NULL)
        {
            cout<<copie_de_parcurs->get_info()<<endl;
            copie_de_parcurs=copie_de_parcurs->get_next();
        }

    }
    void Transforma_in_Circulara()
    {
        copie_de_parcurs=first;
        while(copie_de_parcurs->get_next())
            copie_de_parcurs=copie_de_parcurs->get_next();
        copie_de_parcurs->set_next(first);
        last=copie_de_parcurs;
        copie_de_parcurs=first;
    }
    void Elimina_elemente(int k)
    {
        bool poz[nmax];
        memset(poz,0,sizeof(poz));
        copie_de_parcurs=first->get_next();
        int total=1,eliminate=0,i=1;
        while(copie_de_parcurs!=first)
        {
            ++total;
            copie_de_parcurs=copie_de_parcurs->get_next();
        }
        copie_de_parcurs=first;
        int contor=0;
        while(total!=eliminate)
        {
            while(copie_de_parcurs)
            {
                if(!poz[i])
                    contor++;
                if(contor==k)
                {
                    cout<<copie_de_parcurs->get_info()<<" ";
                    contor=0;
                    ++eliminate;
                    poz[i]=true;
                }
                copie_de_parcurs=copie_de_parcurs->get_next();
                ++i;
                if(i>total)
                    i-=total;
                if(eliminate==total)
                    break;
            }
        }

    }
    Lista_circulara operator + (const Lista_circulara &lista_de_adaugat)
    {
        Lista_circulara lista_finala;
        copie_de_parcurs = first;
        int cnt=1;
        while(copie_de_parcurs)
        {
            lista_finala.Adauga_element(copie_de_parcurs->get_info(),cnt++);
            copie_de_parcurs=copie_de_parcurs->get_next();
        }
        copie_de_parcurs = lista_de_adaugat.first;
        while(copie_de_parcurs)
        {
            lista_finala.Adauga_element(copie_de_parcurs->get_info(),cnt++);
            copie_de_parcurs=copie_de_parcurs->get_next();
        }
        return lista_finala;
    }
    friend istream &operator >> (istream& input,Lista_circulara &lista);
    friend ostream &operator << (ostream& output,const Lista_circulara &lista);
};
ostream& operator << (ostream& output,const Lista_circulara &lista)
{
    Nod* curent = lista.first;
    while(curent != NULL)
    {
        output<<curent->get_info()<<' ';
        curent=curent ->get_next();
    }
    return output;
}
istream& operator >> (istream& input,  Lista_circulara &lista)
{
    int valoare,pozitie;
    input >> valoare >> pozitie;
    lista.Adauga_element(valoare,pozitie);
    return input;
}
Lista_circulara& operator >> (Lista_circulara &lista,  int valoare)
{
    ++poz;
    lista.Adauga_element(valoare,poz);
    return lista;
}
int main()
{
    int a=11;
    Lista_circulara lista2,lista3,lista4;
    lista2.Adauga_element(1,1);
    lista2.Adauga_element(2,2);
    lista2.Adauga_element(3,3);
    lista2.Adauga_element(4,4);
    lista2.Adauga_element(5,2);
    cout<<lista2<<endl;
    lista3>>5>>6;
    cout<<lista3<<endl;
    lista4=lista2+lista3;
    cout<<lista4<<endl;
    lista4.Inversare_legaturi();
    cout<<lista4;
    return 0;
}
