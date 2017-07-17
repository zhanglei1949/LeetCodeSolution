#include<iostream>
#include<stack>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};
void reorderList(ListNode* head)
{
    //1. find the middle of the list, cut into two parts;
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return ;
    ListNode *first = head;
    ListNode *second = head;
    while (second){
        if (second->next==NULL || second->next->next==NULL) break;
        first = first->next;

        second = second->next->next;
    }
    //cout<<first->next->val<<endl;

    //2. reverse the latter one
    ListNode *s = first;
    ListNode *tmp = new ListNode(0);
    ListNode *tem;
    while (first->next){
        tem = tmp->next;
        tmp->next = first->next;
        first->next = first->next->next;
        tmp->next->next = tem;

    }
    //3. merge two lists;
    ListNode *cur = head;
    while (tmp->next){
        tem = cur->next;
        cur->next = tmp->next;
        tmp->next = tmp->next->next;
        cur->next->next = tem;
        cur = cur->next->next;
    }
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    reorderList(head);
    while (head){
        cout<<head->val<<" ";
        head = head->next;
    }
    return 0;
}
