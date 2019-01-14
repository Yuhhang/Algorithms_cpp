#include <string>

using namespace std;

int compare(double x, double y);
class Node
{
    public:
        Node(double _key = 0.0, string _val = "", int _N = 0)
        {   key = _key; val = _val; N = _N;}
        double key;
        string val;
        int N;      //number of child-nodes, including the current node
        Node* left;
        Node* right;
};

class BST
{
private:
    Node root;

public:
    int BST::size(Node* x)
    {
        if(x == nullptr)    return 0;  
        return x->N;
    }
    string BST::get(double key)
    {
        Node* x = &root;
        while(x != nullptr)
        {
            int cmp = compare(key, x->key);
            if(cmp < 0)         x = x->left;
            else if(cmp > 0)    x = x->right;
            else                return x->val;
        }
        return nullptr;
    }
    void BST::put(double key, string val)
    {
        Node*x = &root;
        while(x != nullptr)
        {
            int cmp = compare(key, x->key);
            if(cmp < 0)         x = x->left;
            else if(cmp > 0)    x = x->right;
            else                x->val = val;
        }
        
    }

};


int compare(double x, double y)
{
    if(x<y) return -1;
    else if (x>y)   return 1;
    else    return 0;
}