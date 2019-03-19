#include <iostream>

using namespace std;
void print(int* a)
{
    for(int i=0;i<=10;i++)
    {
        cout<<a[i]<<" ";
    }
}
int* myfun2(int a[],int q1,int e1,int e2)
{
    int q2 = e1+1;
    int s = e2-q1;
    int* sorta = new int[s+1];
    for(int i=0;i<=s;i++)
    {
        if(a[q1]<a[q2] && q1<=e1)
        {
         sorta[i] = a[q1];
         q1++;
        }
        else
        {
         sorta[i] = a[q2];
         q2++;
        }
    }
 return sorta;
}
int main()
{
    int arr[11] = {5,10,20,30,40,20,28,35,50,70,80};
    int* sor = myfun2(arr,0,4,10);
    print(sor);
    return 0;
}
