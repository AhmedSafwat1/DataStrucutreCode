#include <iostream>

using namespace std;
lass base
{
public:
	void say() {cout << "\n I’m base \n";}
};
class derived:public base
{
public:
	void say() {cout << "\n I’m derived \n";}
	};

int main()
{
base *pb;
base mybase;
derived myd
erived;

pb=&mybase;
pb->say();
pb=&myderived;
pb->say();
    cout << "Hello world!" << endl;
    return 0;
}
