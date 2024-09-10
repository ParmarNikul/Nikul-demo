#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *buildtree(node *root)
{
    int data;
    cout << "enter data" << endl;
    cin >> data;
    root = new node(data);
    if (data == -1)
        return NULL;

    cout << "ENter data for the left of" << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter data for the right of" << data << endl;
    root->right = buildtree(root->right);

    return root;
}
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelOrderTraversal(root);
}