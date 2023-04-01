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
    int val;                //�ƭ�
    node *left;             //�����I
    node *right;            //�k���I
};

void PrintTree(node *root);         //���L����
void DFS_Recursive(node *root);     //Recursive DFS ���j
void DFS_Iterative(node *root);     //Iterative DFS ���N
void BFS_queue(node *root);         //BFS �ϥ�queue

/*
        1
       / \
      2   3
     / \   \
    4   5   6
*/
int main(){
    //========<�ؾ�>========
    node *node4 = new node(4);
    node *node5 = new node(5);
    node *node6 = new node(6);
    node *node2 = new node(2, node4, node5);
    node *node3 = new node(3, node6);
    node *node1 = new node(1, node2, node3);

    node *pRoot = node1;

    PrintTree(pRoot);         //���L����
	cout << endl;
    DFS_Recursive(pRoot);       //Recursive DFS ���j
	cout << endl;
    DFS_Iterative(pRoot);       //Iterative DFS ���N
	cout << endl;
    BFS_queue(pRoot);             //BFS �ϥ�queue
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
