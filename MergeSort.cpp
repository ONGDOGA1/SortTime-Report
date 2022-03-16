#include <iostream>
#include <algorithm>
#include <fstream>
#include <random>
#include <string>
#include <time.h>
#define ull unsigned long long
#define ll long long
#define ldb long double
#define fort(i,a,b) for (int i = a; i<=b; i++)
#define ford(i,a,b) for (int i = a; i>=b; i--)
#define forrange(i,a,b) for (int i = a; i<b; i++)
#define NMax 1000000
using namespace std;
string ListTest[10] {
      "TestData/Test1.txt", 
      "TestData/Test2.txt", 
      "TestData/Test3.txt", 
      "TestData/Test4.txt", 
      "TestData/Test5.txt", 
      "TestData/Test6.txt", 
      "TestData/Test7.txt", 
      "TestData/Test8.txt", 
      "TestData/Test9.txt", 
      "TestData/Test10.txt", 
};
ofstream of("TimeRecord/MergeSort_Time_Record.txt");
void merge(vector<float> &arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    vector<float> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0; 
    j = 0;
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(vector<float> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
void Calculate(int test)
{
    clock_t start, end;
    double time_used;
    vector<float> array(NMax);
    float readvalue;
    ifstream inf(ListTest[test]);
    forrange(i,0,NMax) 
    {
        inf >> array[i];
    }
    inf.close();
    cout << "Read Test " << test+1 <<" Done! Start Sort |||........||| ";
    start = clock();
    mergeSort(array,0,array.size()-1);
    end = clock();
    time_used = (double)(end-start) / CLOCKS_PER_SEC;
    cout << "Test " << test+1 <<" passed!. Time used: "<< time_used << 's' << endl;
    of << time_used*1000 << endl;
}
int main()
{
    cout << "Start MergeSort" << '\n';
    forrange(i,0,10) Calculate(i);
    of.close();
    cout << "End MergeSort" << '\n';
    return 0;
}