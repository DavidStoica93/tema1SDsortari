/// Tema Laborator 1 SD Sortari


#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <ctime>
#include <random>
#include <chrono>

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


int main()
{

    ifstream fin("test.txt");

    long int n;
    fin>>n;
    long int nmax;
    fin>>nmax;
    long int v[n], i;

    for(i=0;i<n;i++)
    {
        v[i]=rand()%nmax;
    }

    auto begin = std::chrono::high_resolution_clock::now();

//    Radix_Sort(w,n);
//    Merge_Sort(w,0,n-1);
//    Shell_Sort(w,n);
//    Quick_Sort(w,0,n-1);
    Bubble_Sort(w,n);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    cout<<"Timp de Sortare:"<<elapsed.count() * 1e-9<<'\n';
    cout<<"Verificare Sortare: "<<Test_Sort(w,n);

    fin.close();

    return 0;
}
