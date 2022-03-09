#include <iostream>
#include <algorithm>
#include <fstream>
#include <random>
#include <string>
#define ull unsigned long long
#define ll long long
#define ldb long double
#define fort(i,a,b) for (int i = a; i<=b; i++)
#define ford(i,a,b) for (int i = a; i>=b; i--)
#define forrange(i,a,b) for (int i = a; i<b; i++)
#define NMax 1000000
using namespace std;
random_device rd;
mt19937 rng(rd());
uniform_real_distribution<float> uni(0,999999);
string ListTest[10] {
      "Test1.txt", 
      "Test2.txt", 
      "Test3.txt", 
      "Test4.txt", 
      "Test5.txt", 
      "Test6.txt", 
      "Test7.txt", 
      "Test8.txt", 
      "Test9.txt", 
      "Test10.txt", 
    };
void GenerateTest12()
{
    vector<float> arr(NMax);
    forrange(i,0,NMax) arr[i] = uni(rng);
    sort(arr.begin(),arr.end());
    ofstream of(ListTest[0]);
    forrange(i,0,NMax) of << arr[i] << ' ';
    of.close();
    forrange(i,0,NMax/2) swap(arr[i],arr[NMax-i-1]);
    ofstream of1(ListTest[1]);
    forrange(i,0,NMax) of1 << arr[i] << ' ';
    of1.close();
}
void GenerateTest(int test)
{
    ofstream of(ListTest[test]);
    fort(i,1,NMax) of << uni(rng) << ' ';
    of.close();
}
int main()
{
    GenerateTest12();
    forrange(i,2,10) GenerateTest(i);
    return 0;
}

