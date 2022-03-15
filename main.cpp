/// Tema Laborator 1 SD Sortari


#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <ctime>
#include <random>

using namespace std;

/// Radix Sort
void Radix(long int v[], long int ordin, long int nr)
{
    long int put = 1, vnou[nr];
    for (long int k = 0; k < ordin; k++)
    {
        long int index = 0;
        for (long int i = 0; i <= 9; i++)
        {
            for (long int j = 0; j < nr; j++)
            {
                if ((v[j] / put) % 10 == i)
                    vnou[index++] = v[j];
            }
        }
        for (long int i = 0; i < nr; i++)
            v[i] = vnou[i];
        put *= 10;
    }
}

void Radix_Sort(long int v[], long int n)
{
    long int maxim =-1, ord=0;
    for (long int i = 0; i < n; i++)
        if (maxim < v[i])
            maxim = v[i];
    do {
        maxim /= 10;
        ord++;
    } while (maxim>0);
    Radix(v, ord, n);
}


/// Merge Sort
void inter(long int v[], long int st, long int dr)
{
    int i, j, m, w[101], k=st;
    m=(st+dr)/2;
    i=st;
    j=m+1;
    while(i<=m && j<=dr)
        if(v[i]>v[j])
        {
            w[k]=v[j];
            k++;
            j++;
        }
        else
        {
            w[k]=v[i];
            k++;
            i++;
        }
    while(i<=m)
    {
        w[k]=v[i];
        k++;
        i++;
    }
    while(j<=dr)
    {
        w[k]=v[j];
        k++;
        j++;
    }
    for(i=st;i<=dr;i++)
        v[i]=w[i];
}

void Merge_Sort(long int v[], long int st, long int dr)
{
    if(dr-st==1)
        if(v[st]>v[dr])
            swap(v[st],v[dr]);
    if(dr-st>0)
    {
        long int m=(st+dr)/2;
        Merge_Sort(v,st,m);
        Merge_Sort(v,m+1,dr);
        inter(v,st,dr);
    }
}


/// Shell Sort
void Shell_Sort(long int v[], long int n)
{
    int i,j,pas,aux;
    for(pas=n/2;pas>0;pas/=2)
        for(i=pas;i<n;i+=1)
        {
            aux=v[i];
            for(j=i;j>=pas&&v[j-pas]>aux;j-=pas)
                v[j]=v[j-pas];
            v[j]=aux;
        }
}


/// Quick Sort
int pivot(long int v[], long int st, long int dr)
{
    int x=v[st];
    while(st<dr)
    {
        while(st<dr && v[dr]>=x)
            dr--;
        v[st]=v[dr];
        while(st<dr && v[st]<=x)
            st++;
        v[dr]=v[st];
    }
    v[st]=x;
    return st;
}

void Quick_Sort(long int v[], long int st, long int dr)
{
    int p=pivot(v,st,dr);
    if(p-st>1)
        Quick_Sort(v,st,p-1);
    if(dr-p>1)
        Quick_Sort(v,p+1,dr);
}


/// Bubble Sort
void Bubble_Sort(long int v[], long int n)
{
    int i, j;
    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
            if(v[j]>v[j+1])
                swap(v[j],v[j+1]);
}


/// Testarea Algoritmilor de Sortare
int Test_Sort(long int v[], long int n)
{
    long int i;
    for(i=1;i<n;i++)
        if(v[i-1]>v[i])
            return 0;
    return 1;
}


/// Copierea unui vector in al vector
void Copie_Vector(long int v[], long int n, long int w[])
{
    long int i;
    for(i=0;i<n;i++)
        w[i]=v[i];
}


int main()
{

    ifstream fin("test.txt");

    long int n;
    fin>>n;
    long int nmax;
    fin>>nmax;
    long int v[n], i, w[n];
    for(i=0;i<n;i++)
    {
        v[i]=rand()%nmax;
    }

    clock_t startTime, endTime;

    /// Radix Sort - not working
    Copie_Vector(v,n,w);
    startTime=time(nullptr);
    Radix_Sort(w,n);
    endTime=time(nullptr);
    cout<<"Radix Sort:"<<" "<<endTime-startTime<<'\n';
    cout<<"Verificare Sortare: "<<Test_Sort(w,n);
    cout<<'\n'<<'\n';

    /// Merge Sort
    Copie_Vector(v,n,w);
    startTime=time(nullptr);
    Merge_Sort(w,0,n-1);
    endTime=time(nullptr);
    cout<<"Merge Sort:"<<" "<<endTime-startTime<<'\n';
    cout<<"Verificare Sortare: "<<Test_Sort(w,n);
    cout<<'\n'<<'\n';

    /// Shell Sort
    Copie_Vector(v,n,w);
    startTime=time(nullptr);
    Shell_Sort(w,n);
    endTime=time(nullptr);
    cout<<"Shell Sort:"<<" "<<endTime-startTime<<'\n';
    cout<<"Verificare Sortare: "<<Test_Sort(w,n);
    cout<<'\n'<<'\n';

    /// Quick Sort
    Copie_Vector(v,n,w);
    startTime=time(nullptr);
    Quick_Sort(w,0,n-1);
    endTime=time(nullptr);
    cout<<"Quick Sort:"<<" "<<endTime-startTime<<'\n';
    cout<<"Verificare Sortare: "<<Test_Sort(w,n);
    cout<<'\n'<<'\n';

    /// Bubble Sort
    Copie_Vector(v,n,w);
    startTime=time(nullptr);
    Bubble_Sort(w,n);
    endTime=time(nullptr);
    cout<<"Bubble Sort:"<<" "<<endTime-startTime<<'\n';
    cout<<"Verificare Sortare: "<<Test_Sort(w,n);
    cout<<'\n'<<'\n';

    fin.close();

    return 0;
}
