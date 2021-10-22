// bst implemntandtraversal
#include<bits/stdc++.h>
using namespace std;

struct node {

    char key;
    struct node *left = NULL;
    struct node *right = NULL;

};

struct node* newNode(char item)
{
    struct node* temp = new node();

    temp->key = item;
    temp->left = temp->right = NULL;

    return temp;
}

struct node* insert(struct node* node, char key)
{

    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);

    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

bool search (struct node* node , char key )
{
   if(node == NULL)
    return false;

   else if (node -> key == key)
    return true;

   else if(key < node->key)
    return search(node -> left , key );
   
   else
    return search(node -> right , key );
}
void printPostorder(struct node* node)
{

    if (node == NULL)
        return;

    printPostorder(node->left);

    printPostorder(node->right);

    cout << node-> key << " ";
}

void printInorder(struct node* node)
{

    if (node == NULL)
        return;

    printInorder(node->left);

    cout << node-> key << " ";

    printInorder(node->right);
}

void printPreorder(struct node* node)
{

    if (node == NULL)
         return;

    cout << node-> key << " ";

    printPreorder(node->left);

    printPreorder(node->right);
}

int main()
{

    int n;
    cout << "Enter the number of characters to create the Binary search tree:\n";
    cin >> n;

    char ch;
    cout << "\n\nEnter the characters : \n";

    struct node *root = NULL;
     

    for(int i = 0 ; i < n ; i++)
    {
       cin >> ch;
       root = insert(root,ch);
    }
  
    cout << "\nEnter the element to be searched :\n";
    cin >> ch;
    if(search(root , ch))
    cout << ch << " Found!";
    
    else
    cout << ch << " Not Found!";

    cout << "\n\nInorder Traversal :\n";
    printInorder(root);

    cout << "\n\nPreorder Traversal :\n";
    printPreorder(root);

    cout << "\n\nPostorder Traversal :\n";
    printPostorder(root);

    return 0;
}

