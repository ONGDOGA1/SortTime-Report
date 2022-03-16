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
ofstream of("TimeRecord/HeapSort_Time_Record.txt");
void heapify(vector<float> &arr, int n, int i) 
{ 
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2; 
  
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
    } 
} 
void heapSort(vector<float> &arr, int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    for (int i=n-1; i>0; i--) 
    { 
        swap(arr[0], arr[i]); 
  
        heapify(arr, i, 0); 
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
    heapSort(array,array.size());
    end = clock();
    time_used = (double)(end-start) / CLOCKS_PER_SEC;
    cout << "Test " << test+1 <<" passed!. Time used: "<< time_used << 's' << endl;
    of << time_used*1000 << endl;
}
int main()
{
    cout << "Start HeapSort" << '\n';
    forrange(i,0,10) Calculate(i);
    of.close();
    cout << "End HeapSort" << '\n';
    return 0;
}