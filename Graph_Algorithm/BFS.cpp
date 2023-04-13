//2023/03/25 kerong
/*
	Algorithm: BFS (Breadth-First Search)
	 Time complexity => O(V)
	Space complexity => O(W)
	
	W: The maximum width of the tree (i.e., the maximum number of nodes at any level of the tree)
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
void BFS_queue(node *root);         //BFS using queue

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

    BFS_queue(pRoot);             //BFS using queue
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

void BFS_queue(node *root){
    if(root==NULL){
        return;
    }
    queue<node *> Q;
    Q.push(root);

    while(!Q.empty()){
        node *node = Q.front();
        cout << node->val << " ";
        Q.pop();
        if(node->left!=NULL){
            Q.push(node->left);
        }
        if(node->right!=NULL){
            Q.push(node->right);
        }
    }
}
