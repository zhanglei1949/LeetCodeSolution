#include<iostream>

using namespace std;
struct TreeLinkNode{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
TreeLinkNode * findNextNotNull(TreeLinkNode *father, int flag)
{
    //flag==0, start from father->left
    //flag==1, start from father->right
    TreeLinkNode *res;
    TreeLinkNode *curFather = father;
    if (flag==0){
        res = curFather->left;
        if (res) return res;
        while (!res){
            res = curFather->right;
            if (res) return res;
            curFather = curFather->next;
            if (!curFather) return NULL;
            res = curFather->left;
            if (res) return res;
        }
    }
    if (flag==1){

        do{
            res = curFather->right;
            if (res) return res;
            curFather = curFather->next;
            if (!curFather) return NULL;
            res = curFather->left;
            if (res) return res;
        }while (!res);
    }
    return NULL;
}
void connect(TreeLinkNode *root) {
    if (!root) return ;
    TreeLinkNode *pre = root;
    TreeLinkNode *cur = NULL;
    TreeLinkNode *thisFather = NULL;
    //first find the first element in this level
    while (true){
        int flag = -1;
        cur = findNextNotNull(pre, 0, thisFather, flag);
        if (flag==0)
            cur->next = findNextNotNull(thisFather, 1, thisFather, flag);
        else
            cur->next = findNextNotNull(thisFather->next, 0, thisFather, flag);
        if (thisFather==NULL)
    }
    //then find the next and next
}

int main()
{
    TreeLinkNode *root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->left->left = new TreeLinkNode(4);
    //root->left->right = new TreeLinkNode(5);
    root->right = new TreeLinkNode(3);
    root->right->left = new TreeLinkNode(6);
    root->right->right = new TreeLinkNode(7);
    root->left->next = root->right;
    cout<<(findNextNotNull(root,0)->val)<<endl;
    cout<<findNextNotNull(root->left,0)->val<<endl;
    cout<<findNextNotNull(root->left,1)->val<<endl;
    cout<<findNextNotNull(root->right,0)->val<<endl;;
    cout<<findNextNotNull(root->right,1)->val<<endl;;
}
