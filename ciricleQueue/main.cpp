#include <iostream>

using namespace std;

class Cqueue
{
  int rear;
  int Front;
  int s;
  int arr[5];
  public:
    Cqueue()
    {
        rear = Front = -1;
        s = 5;
    }
    void enqueue(int _val)
    {
        if((rear == s-1 && Front == 0) || Front == rear+1)
          return;
        if(Front == -1)
        {
            rear = Front = 0;
            arr[rear] = _val;
        }
        else if(rear == s-1)
        {
            rear = 0;
            arr[rear] = _val;
        }
        else
        {
            rear++;
            arr[rear] = _val;
        }
    }
    int dequee(int& x )
    {
        if(Front == -1)
        {
            return 0;
        }
        x = arr[Front];
        if(Front == rear)
        {
               rear = Front = -1;
        }
        else if(Front == s-1)
        {
            Front = 0;
        }
        else
        {
            Front++;
        }
        return 1;
    }
};

int main()
{
    Cqueue l;
    l.enqueue(5);
    int x;
    l.dequee(x);
    cout<<x;
    cout << "Hello world!" << endl;
    return 0;
}
