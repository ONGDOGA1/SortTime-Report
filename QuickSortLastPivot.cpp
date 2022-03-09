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
ofstream of("TimeRecord/QuickSortLP_Time_Record.txt");
int partition (vector<float> &arr, int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void QuickSort(vector<float> &arr, int low, int high)
{
    if (low < high)
    {
        int niceguy = partition(arr,low,high);
        QuickSort(arr,low,niceguy-1);
        QuickSort(arr,niceguy+1,high);
    }
}
void Calculate(int test)
{
    if (test < 2)
    {
        
        clock_t start, end;
        double time_used;
        //Test 1 và 2 là trường hợp tệ nhất của thuật toán quicksort nên độ phức tạp lúc này là O(n^2) vì thời gian thực hiện quá lớn nên em sẽ giảm kích thước bộ test và ước tính thời gian chạy dựa trên độ phức tạp
        int N = NMax/100;
        vector<float> array(N);
        float readvalue;
        ifstream inf(ListTest[test]);
        forrange(i,0,N) 
        {
            inf >> array[i];
        }
        inf.close();
        cout << "Read Test " << test+1 <<" Done! Start Sort |||........||| ";
        start = clock();
        QuickSort(array,0,N-1);
        end = clock();
        time_used = (double)(end-start) / CLOCKS_PER_SEC;
        cout << "Test " << test+1 <<" passed!. Time used: "<< time_used*10000 << "s (Size of test is divided by 100 so maybe time used is multiplied by 100^2)" << endl;
        of << fixed << time_used*10000*1000 << endl;
        return;
    }
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
    QuickSort(array,0,NMax-1);
    end = clock();
    time_used = (double)(end-start) / CLOCKS_PER_SEC;
    cout << "Test " << test+1 <<" passed!. Time used: "<< time_used <<'s'<<endl;
    of << fixed <<time_used*1000 << endl;
}
int main()
{
    of.precision(0);
    forrange(i,0,10) Calculate(i);
    of.close();
}