#include<iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode * sortedListToBST(ListNode * head, ListNode * tail)
{
    if (head==NULL) cout<<"NULL ";
    else cout<<head->val<<" ";
    if (tail==NULL) cout<<"NULL ";
    else cout<<tail->val<<" ";
    cout<<endl;
    TreeNode *root;
    if (head==tail) return NULL;
    if (head->next == tail){
        root = new TreeNode(head->val);
        return root;
    }
    ListNode *fast, *slow;
    fast = slow = head;
    while (fast!=tail){
        if (fast->next==tail){
            fast = fast->next;
        }
        else {
            fast = fast->next->next;
            slow = slow->next;
        }
    }
    root = new TreeNode(slow->val);
    root->left = sortedListToBST(head, slow);
    root->right = sortedListToBST(slow->next, tail);
    return root;
}
TreeNode* sortedListToBST(ListNode* head)
{
    return sortedListToBST(head, NULL);
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    TreeNode *res = sortedListToBST(head);
    cout<<res->val<<" "<<res->left->val<<" "<<res->right->val;
}
