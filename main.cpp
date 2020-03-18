#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstring>
using namespace std;
///istream fin("date.in");
///ofstream fout("date.out");
#define nmax 1001
class Nod
{
public:
    int info;
    Nod *next;
    Nod(const int x=0,Nod *urmatoru=NULL)
    {
        info = x;
        next = urmatoru;
    }
    ~Nod()
    {
        next = NULL;
    }
};
class Lista_circulara
{
private:
    Nod *first=NULL;
    Nod *last;
    Nod *copie_de_parcurs;
public:
    void Adauga_element(int element)
    {
        Nod *nod_nou=new Nod;
        nod_nou->info=element;
        if(first==NULL)
        {
            first=nod_nou;
            last=first;
        }
        else
        {
            /*int cnt=1;
            copie_de_parcurs=first;
            while(cnt+1!=pozitie)
            {
                cnt++;
                copie_de_parcurs=copie_de_parcurs->next;
                ///first=first->next;
            }
            nod_nou->next=copie_de_parcurs->next;
            copie_de_parcurs->next=nod_nou;*/
            last->next=nod_nou;
            last=nod_nou;
        }
    }
    void Stergere_element(int pozitie)
    {
        Nod *nod_nou;
        if(pozitie==1)
        {
            nod_nou=first;
            first=first->next;
            delete(nod_nou);
        }
        else
        {
            int cnt=1;
            copie_de_parcurs=first;
            while(cnt+1!=pozitie)
            {
                ++cnt;
                copie_de_parcurs=copie_de_parcurs->next;
                ///first=first->next;
            }
            nod_nou=copie_de_parcurs->next;
            copie_de_parcurs->next=copie_de_parcurs->next->next;
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
            list = list->next;
            temporara->next = inversa;
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
            cout<<copie_de_parcurs->info<<endl;
            copie_de_parcurs=copie_de_parcurs->next;
        }

    }
    void Transforma_in_Circulara()
    {
        copie_de_parcurs=first;
        while(copie_de_parcurs->next)
            copie_de_parcurs=copie_de_parcurs->next;
        copie_de_parcurs->next=first;
        last=copie_de_parcurs;
        copie_de_parcurs=first;
    }
    void Elimina_elemente(int k)
    {
        bool poz[nmax];
        memset(poz,0,sizeof(poz));
        copie_de_parcurs=first->next;
        int total=1,eliminate=0,i=1;
        while(copie_de_parcurs!=first)
        {
            ++total;
            copie_de_parcurs=copie_de_parcurs->next;
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
                    cout<<copie_de_parcurs->info<<" ";
                    contor=0;
                    ++eliminate;
                    poz[i]=true;
                }
                copie_de_parcurs=copie_de_parcurs->next;
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
        while(copie_de_parcurs)
        {
            lista_finala.Adauga_element(copie_de_parcurs->info);
            copie_de_parcurs=copie_de_parcurs->next;
        }
        copie_de_parcurs = lista_de_adaugat.first;
        while(copie_de_parcurs)
        {
            lista_finala.Adauga_element(copie_de_parcurs->info);
            copie_de_parcurs=copie_de_parcurs->next;
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
        output<<curent->info<<' ';
        curent=curent ->next;
    }
    return output;
}
istream& operator >> (istream& input,  Lista_circulara &lista)
{
    int valoare;
    input >> valoare;
    lista.Adauga_element(valoare);
    return input;
}
Lista_circulara& operator >> (Lista_circulara &lista,  int valoare)
{
    lista.Adauga_element(valoare);
    return lista;
}
int main()
{
    int a=11;
    Lista_circulara lista2,lista3,lista4;
    lista2.Adauga_element(1);
    lista2.Adauga_element(2);
    lista2.Adauga_element(3);
    lista2.Adauga_element(4);
    lista3>>9>>10;
    lista2>>5>>6>>7>>8;
    lista4=lista2+lista3;
    cout<<lista4<<endl;
    lista4.Transforma_in_Circulara();
    lista4.Elimina_elemente(3);

    return 0;
}
