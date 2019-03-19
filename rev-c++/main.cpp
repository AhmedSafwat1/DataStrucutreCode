#include <iostream>
#include <string.h>
using namespace std;
class Test
{
    public:
    Test()
    {
      cout<<"www";
    }


};
void call(Test x)
{
  cout<<"";
}

int main( )
{
	Test t;
	Test g = t;
	call(t);

}
