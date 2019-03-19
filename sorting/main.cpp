#include <iostream>
// sorting = searching =  bst.add.display n order preorder postorder search delete
using namespace std;
void swapf(int& a,int&b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void sort1(int arr[],int s)//selection
{
    int m = 0;
    for(int i=0;i<s-1;i++)
    {
        m = i;
        for(int j = i+1;j<s;j++)
        {
            if(arr[i]>arr[j])
            {
                m = j;
            }
        }
        swapf(arr[i],arr[m]);
    }
}
void sort2(int arr[],int s)//bubble
{
    int flag = 0;
    for(int i=0;i<s-1;i++)
    {
        flag= 0;
        for(int j = i+1;j<s;j++)
        {
            if(arr[i]>arr[j])
            {
                swapf(arr[i],arr[j]);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            break;
        }

    }
}
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swapf(arr[j], arr[j+1]);
}
void sort3(int arr[],int s)//insert
{
    int j = 0;
    for(int i=1;i<s;i++)
    {
        j=i;
        while(j > 0 && arr[j] < arr[j-1])
        {
            swapf(arr[j],arr[j-1]);
            j--;
        }
    }
}
//==========migrate
void myfun2(int a[],int q1,int e1,int e2)
{
    int q2 = e1+1;
    int s = e2-q1;
    int j = q1;
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
         if(q2<=e2)
         {
            sorta[i] = a[q2];
            q2++;
         }
         else if(q1<=e1)
         {
             sorta[i] = a[q1];
             q1++;
         }
        }
    }
  for(int i=0;i<=s;i++)
  {
    a[j] = sorta[i];
    j++;
  }
};
void migrateSort(int a[],int s,int e)
{
    if(s >= e)
        return;
    int md = (s+e)/2;
    migrateSort(a,s,md);
    migrateSort(a,md+1,e);
    myfun2(a,s,md,e);
}
// ========================= srearching ==================================================

int binarySearch(int arr[],int s,int e,int key)
{
    if(s > e)
        return -1;
    else
    {
        int md = (s+e)/2;
        if(key>arr[md])
        {
            binarySearch(arr,md+1,e,key);
        }
        else if(key == arr[md])
        {
            return md;
        }
        else
        {
            binarySearch(arr,s,md-1,key);
        }
    }

}
//===========================================================================================
void print(int a[],int s)
{
    for(int i=0;i<s;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int a[6] = {10,5,7,12,4,9};
    //sort1(a,5);
    migrateSort(a,0,5);
   // int arr[11] = {5,10,20,30,40,20,28,35,50,70,80};
    //myfun2(arr,0,4,10);
    print(a,6);
    cout<<binarySearch(a,0,5,7);
    return 0;
}
