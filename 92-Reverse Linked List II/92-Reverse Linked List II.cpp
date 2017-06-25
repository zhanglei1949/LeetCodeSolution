#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
};
ListNode *reverseBetween(ListNode *head, int m_, int n_)
{
    int m = m_ - 1;
    int n = n_ - 1;
    ListNode *newHead = new ListNode(0);
    newHead->next = head;
    ListNode *node_m_pre;
    ListNode *cur_pre;
    ListNode *tmp2;
    if (m == n){
        return head;
    }
    else {
        node_m_pre = newHead;
        for (int i = 0; i < m; ++i){
            node_m_pre = node_m_pre ->next;
        }
        //node_m = node_m_pre->next;
        cur_pre = node_m_pre->next;
        //node m is node_m_pre->next
        for (int i = m; i < n; ++i){
            //cout<<cur_pre->next->val<<endl;
            tmp2 = node_m_pre->next;
            node_m_pre->next = cur_pre->next;
            cur_pre->next = cur_pre->next->next;
            node_m_pre->next->next = tmp2;

        }
    }
    return newHead->next;
}
int main()
{
    ListNode *head = new ListNode(1);
    ListNode *cur = head;
    for (int i = 2; i <= 5; ++i){
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    cur = head;
    while (cur){
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;
    ListNode *res = reverseBetween(head, 4,5);
    while (res){
        cout<<res->val<<" ";
        res = res->next;
    }
}
