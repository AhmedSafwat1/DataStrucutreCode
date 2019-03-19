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

class ll
{
    node* head;
    node* tail;

    node* searchByName(char a[])
    {
        node* temp = head;
        while(temp != NULL)
        {
            if(strcasecmp(temp->name,a) == 0)
            {
                return temp;
            }
            temp = temp->next;
        }
        return temp;
    }

     node* searchById(int s)
    {
        node* temp = head;
        while(temp != NULL)
        {
            if(temp->id == s)
            {
                return temp;
            }
            temp = temp->next;
        }
        return temp;
    }

//============================================================
    public:
        ll()
        {
            head = NULL;
            tail = NULL;
        }
        ll(ll& x)
        {
            tail = head = NULL;

            node* temp = x.head;
            while(temp != NULL)
            {
                append(temp->id,temp->name);
                temp = temp->next;
            }
        }
        void append(int _id,char _name[])
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
        void diplay()
        {
            node* temp = head;
            while(temp != NULL)
            {
                cout<<"id : "<<temp->id<<" name : "<<temp->name<<endl;
                temp = temp->next;
            }
        }
        void test()
        {
            node* o = searchById(25);


        }
        void deleteById(int i)
        {
            node* out = searchById(i);
            if(out != NULL)
            {
                if(head == tail && head == out)
                {
                    head=tail=NULL;
                }
                else if(out == head)
                {
                    head->next->prev = NULL;
                    head = out->next;
                    delete out;
                }
                else if(out == tail)
                {
                    out->prev->next = NULL;
                    tail = out->prev;
                    delete out;
                }
                else
                {
                    out->prev->next = out->next;
                    out->next->prev = out->prev;
                    delete out;
                }
            }
            else
              cout<<"not found this is "<<i<<endl;
        }
        void deleteByName(char a[])
        {
            node* out = searchByName(a);
            if(out != NULL)
            {
               if(head == tail && head == out)
               {
                    head=tail=NULL;
               }
               else if(out == head )
                {
                    head->next->prev = NULL;
                    head = out->next;
                    delete out;
                }
                else if(out == tail)
                {
                    out->prev->next = NULL;
                    tail = out->prev;
                    delete out;
                }
                else
                {
                    out->prev->next = out->next;
                    out->next->prev = out->prev;
                    delete out;
                }
            }
            else
              cout<<"not found this is "<<a<<endl;
        }
        node * operator[](int i)
        {
            node* temp = head;
            int count = 0;
            while(temp != NULL)
            {
                if(count == i)
                {
                    return temp;
                }
                temp = temp->next;
                count++;
            }
            return temp;
        }

        void insertAfterID(int i,int _id,char _name[])
        {
           node* out = searchById(i);
           node* temp = new node;
           temp->id = _id;
           strcpy(temp->name,_name);
           if(out != NULL)
            {
               if(out == tail || tail==head && out == tail)
                {
                    append(_id,_name);
                }
                else
                {
                    temp->next = out->next;
                    out->next = temp;
                    temp->prev = out;
                    temp->next->prev = temp;
                }
            }
            else
              cout<<"not found this is "<<i<<endl;
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
    l.append(1,"ahmed");
    l.append(2,"ahmed");
    ll l2 = l;
    l.diplay();
    l.test();
    l.deleteById(1);
    l.deleteById(2);
    l.diplay();
    cout<<"============="<<endl;
    l2.insertAfterID(1,5,"asdjkjd");
    l2.diplay();
    cout<<l2[1]->name<<endl;
    return 0;
}
