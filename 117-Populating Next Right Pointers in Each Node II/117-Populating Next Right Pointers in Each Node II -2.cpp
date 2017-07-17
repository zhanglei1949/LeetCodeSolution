#include<iostream>
#include<queue>
using namespace std;
struct TreeLinkNode{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


void _connect(TreeLinkNode *root) {
    //using one queue, each time push a node in, connect it to the last one
    //exit when the queue is empty
    //only use constant place?

    //in fact, a queue is not necessary, because the nodes on the next level are already connected
    //by next pointer
    if (!root) return ;
    queue<TreeLinkNode *> q;
    q.push(root);

    while (!q.empty()){
        int q_size = q.size();
        TreeLinkNode *previous = NULL;
        for (int i = 0; i < q_size; ++i){
            TreeLinkNode * tmp = q.front();
            q.pop();
            //cout<<tmp->val<<" ";

            if (tmp->left){
                q.push(tmp->left);
                if (previous){
                    previous->next = tmp->left;
                }
                previous = tmp->left;
            }
            if (tmp->right){
                q.push(tmp->right);
                if (previous){
                    previous->next = tmp->right;
                }
                previous = tmp->right;
            }
        }
    }
}
void connect(TreeLinkNode *root) {
    //in fact, a queue is not necessary, because the nodes on the next level are already connected
    //by next pointer
    if (!root) return ;
    //queue<TreeLinkNode *> q;
    //q.push(root);
    TreeLinkNode *headOfNextLevel = NULL;
    TreeLinkNode *previous = NULL;
    TreeLinkNode *cur = root;
    while (cur){
        while (cur){
            if (cur->left){
                //q.push(cur->left);
                if (previous){
                    previous->next = cur->left;
                }
                else headOfNextLevel = cur->left;
                previous = cur->left;
            }
            if (cur->right){
                //q.push(cur->right);
                if (previous){
                    previous->next = cur->right;
                }
                else headOfNextLevel = cur->right;
                previous = cur->right;
            }
            cur = cur->next;
        }
        cur = headOfNextLevel;
        headOfNextLevel = NULL;
        previous = NULL;
    }
}
void connectTraversal(TreeLinkNode *root)
{
    TreeLinkNode *leftMost = root;
    while (leftMost){
        TreeLinkNode *tmp = leftMost;
        while (tmp){
            cout<<tmp->val<<" ";
            tmp = tmp->next;
        }
        cout<<endl;
        leftMost = leftMost->left;
        //only available in my test case!
    }
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
    connect(root);
    connectTraversal(root);
    return 0;
}
