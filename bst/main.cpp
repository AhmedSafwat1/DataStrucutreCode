#include <iostream>

using namespace std;

struct node
{
 int id;
 node* left;
 node* right;
};
class Bst
{
    node* root;

    public:
        Bst()
        {
            root = NULL;
        }
        void add(int key)
        {
            node* temp = new node;
            temp->id = key;
            temp->left = temp->right = NULL;
            if(root == NULL)
            {
                root = temp;
            }
            else
            {
                node* t = root;
                node* p = root;
                while(t != NULL)
                {
                    p = t;
                    if(key > t->id)
                    {
                        t = t->right;
                    }
                    else
                    {
                        t = t->left;
                    }
                }
                if(key > p->id)
                    p->right = temp;
                else
                    p->left = temp;
            }
        }
        //add rec ===========================
        void add2(int key)
        {
            addrec(key,root);
        }
        void addrec(int key,node*& r)
        {
            if(r == NULL)
            {
                node* temp = new node;
                temp->left = temp->right = NULL;
                temp->id = key;
                r = temp;
            }
            else if(key < r->id)
            {
                addrec(key,r->left);
            }
            else
            {
                addrec(key,r->right);
            }

        }
        // void display
        void callDisplay()
        {
            displayOrder(root);
        }
        void displayOrder(node* r)
        {
            if(r == NULL)
                return;
            displayOrder(r->left);
            cout<<r->id <<" ";
            displayOrder(r->right);
        }
        void displayPreOrder(node* r)
        {
            if(r == NULL)
                return;
            cout<<r->id <<" ";
            displayOrder(r->left);
            displayOrder(r->right);
        }
        void displayPostOrder(node* r)
        {
            if(r == NULL)
                return;
            displayOrder(r->left);
            displayOrder(r->right);
            cout<<r->id <<" ";
        }

    // search
    void callSearch(int key)
    {
        searching(root,key);
    }
    void searching(node* r ,int key)
    {
        if(r == NULL)
        {
         cout<<endl<<"not found"<<endl;
         return;
        }
        else if(r->id == key)
        {
             cout<<endl<<"found"<<endl;
        }
        else if(r->id > key)
            searching(r->left,key);
        else
             searching(r->right,key);
    }
    //delete
    node * minValueNode(node* r)
    {
        node* current = r;

        while (current->left != NULL)
            current = current->left;

        return current;
    }
    //==================
    node* calldel(int id)
    {
        return deleteId(root,id);
    }
    node* deleteId(node* r,int key)
    {
        if(r == NULL)
            return NULL;
        else if( r->id > key)
        {
            r->left = deleteId(r->left,key);

        }
        else if(r->id < key)
        {
            r->right = deleteId(r->right,key);
        }
        else
        {
            if(r->left == NULL)
            {
                node * temp = r->right;
                delete r;
                return temp;
            }
            else if(r->right == NULL)
            {
               node * temp = r->left;
               delete r;
               return temp;
            }
            else if(r->left == NULL && r->right == NULL)
            {
                delete r;
                return NULL;
            }
            else
            {
                node * temp = minValueNode(r->right);
                r->id = temp->id;
                r->right = deleteId(temp->right,temp->id);
                return r;
            }
        }
        return r;
    }


};
int main()
{
    Bst b;
    b.add2(10);
    b.add2(5);
    b.add2(3);
    b.add2(6);
    b.add2(20);
    b.callDisplay();
    b.callSearch(13);
    cout<<b.calldel(20)->id<<endl;
    b.callDisplay();

    return 0;
}
