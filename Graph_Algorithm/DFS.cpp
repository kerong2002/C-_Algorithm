//2023/03/25 kerong
/*
    Algorithm : DFS(Depth-First Search)
	 Time complexity => O(b^m)
	Space complexity => O(bm)

	b: The average number of child nodes for each node in the tree.
	m: The maximum depth (i.e., the number of levels) of the tree.
*/
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node{
public:
    node(int rVal=0, node *rLeft=NULL, node *rRight = NULL)
    {
        val = rVal;
        left = rLeft;
        right = rRight;
    }
    int val;                //Value
    node *left;             //Left child node
    node *right;            //Right child node
};

void PrintTree(node *root);         //Print tree data
void DFS_Recursive(node *root);     //Recursive DFS
void DFS_Iterative(node *root);     //Iterative DFS


/*
        1
       / \
      2   3
     / \   \
    4   5   6
*/
int main(){
    //========<Build Tree>========
    node *node4 = new node(4);
    node *node5 = new node(5);
    node *node6 = new node(6);
    node *node2 = new node(2, node4, node5);
    node *node3 = new node(3, node6);
    node *node1 = new node(1, node2, node3);

    node *pRoot = node1;

    PrintTree(pRoot);         //Print tree data
	cout << endl;

    DFS_Recursive(pRoot);       //Recursive DFS
	cout << endl;
    DFS_Iterative(pRoot);       //Iterative DFS
	cout << endl;

    return 0;
}

void PrintTree(node *root){
    if(root == NULL){
        return ;
    }
    cout << root->val << " ";
    if(root->left!=NULL){
        PrintTree(root->left);
    }
    if(root->right!=NULL){
        PrintTree(root->right);
    }
}

void DFS_Recursive(node *root){
    if(root == NULL){
        return;
    }
    else{
        cout << root->val << " ";
        DFS_Recursive(root->left);
        DFS_Recursive(root->right);
    }
}

void DFS_Iterative(node *root){
    if(root==NULL){
        return;
    }
    stack<node *> S;
    S.push(root);

    while(!S.empty()){
        node *node = S.top();
        cout << node->val <<" ";
        S.pop();
        if(node->left!=NULL){
            S.push(node->left);
        }
        if(node->right!=NULL){
            S.push(node->right);
        }
    }
}

