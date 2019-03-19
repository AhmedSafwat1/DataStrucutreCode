#include <iostream>

using namespace std;
class x
{
    static int y;
    public:
    static int gety()
    {
        return y;
    }
};
int x::y = 5;
int main()
{
    x u;
    cout<<u.gety();
    cout << "Hello world!" << endl;
    return 0;
}
