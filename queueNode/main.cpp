#include <iostream>
#include <string.h>

using namespace std;

struct node
{
    int id;
    char name[255];
    node* next;
    node* prev;
};
struct data
{
    int id;
    char name[255];
};
class ll
{
    node* head;
    node* tail;


//============================================================
    public:
        ll()
        {
            head = NULL;
            tail = NULL;
        }

        void enque(int _id,char _name[])
        {
            node* temp = new node;
            temp->id = _id;
            strcpy(temp->name,_name);
            if(head==NULL)
            {
                temp->next = NULL;
                temp->prev = NULL;
                head = temp;
                tail = temp;

            }
            else
            {
                temp->next = NULL;
                temp->prev = tail;
                tail->next = temp;
                tail = temp;
            }
        }
        data dequ()
        {
            data d;
            d.id=-1;
            strcpy(d.name,"");
            if(head == NULL)
            {
                return d;
            }
            else if(head == tail)
            {
                d.id = head->id;
                strcpy(d.name,head->name);
                delete head;
                head = tail = NULL;
                return d;
            }
            else
            {
                node* temp = head;
                head = temp->next;
                head->prev = NULL;
                d.id = temp->id;
                strcpy(d.name,temp->name);
                delete temp;
                return d;
            }

        }
        void diplay()
        {
            node* temp = head;
            while(temp != NULL)
            {
                cout<<"id : "<<temp->id<<" name : "<<temp->name<<endl;
                temp = temp->next;
            }
        }


        //destroy

        ~ll()
        {
            node* temp = head;
            node* d;
            while(temp != NULL)
            {
                d = temp;
                temp = temp->next;
                delete d;
            }
        }

};
int main()
{
    ll l;
    l.enque(5,"asas");
    l.enque(6,"hkjk");
    data d;
    d =l.dequ();
    cout<<d.id;
    return 0;
}
