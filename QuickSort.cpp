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

void QuickSort(vector<float> &arr, int left, int right)
{
    int i = 0,j = 0,pivot = 0;
    pivot = arr[(left+right)/2];
    i= left; j = right;
    while (i<j)
    {
        while (arr[i] < pivot && i<right) i++;
        while (arr[j] > pivot && j>left) j--;
        if (i<=j) 
        {
            swap(arr[i],arr[j]);
            i++; j--;
        }
    }
    if (j>left) QuickSort(arr,left,j);
    if (i<right) QuickSort(arr,i,right);    
}
ofstream of("TimeRecord/QuickSort_Time_Record.txt");
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
    int n = NMax;
    start = clock();
    QuickSort(array,0,n-1);
    end = clock();
    time_used = (double)(end-start) / CLOCKS_PER_SEC;
    cout << "Test " << test+1 <<" passed!. Time used: "<< time_used << 's' << endl;
    of << time_used*1000 << endl;
}
int main()
{
    cout << "Start QuickSort" << '\n';
    forrange(i,0,10) Calculate(i);
    of.close();
    cout << "End QuickSort" << '\n';
    return 0;
}