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
    stack<ListNode *> s;
    if (head == NULL || head->next == NULL || head->next->next == NULL) return ;
    ListNode *first = head;
    ListNode *second = head;
    s.push(head);
    bool flag = 0;
    //0 for even, 1 for odd
    while (true)
    {
        if (second->next==NULL){
            flag = 1;
            s.pop();
            //odd
            break;
        }
        else if (second->next->next==NULL){
            flag = 0;
            //even

            break;
        }
        first = first->next;
        s.push(first);
        second = second->next->next;
    }
    ListNode *a;
    ListNode *b;
    cout<<flag<<endl;
    //put b->next at a->next;
    if (flag==1){
        a = s.top();
        s.pop();
        b = a->next;
    }
    else {
        a = s.top();
        s.pop();
        b = a;
    }
    while (true){
        cout<<a->val<<" "<<b->next->val<<endl;
        ListNode *tmp = b->next;
        b->next = tmp->next;
        tmp->next = a->next;
        a->next = tmp;
        //b doesn't have to move
        if (s.empty()) break;
        a = s.top();
        s.pop();
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
/*
void reorderList(ListNode* head)
{
    stack<ListNode *> s;
    if (head == NULL || head->next == NULL || head->next->next == NULL) return ;
    ListNode *first = head;
    ListNode *second = head;
    s.push(head);
    bool flag = 1;
    while (true){
        if (second->next==NULL){
            s.pop();
            flag = 1;
            //odd
            break;
        }
        else if (second->next->next==NULL){
            flag = 0;
            s.pop();
            //even
            break;
        }
        first = first->next;
        s.push(first);
        second = second->next->next;
    }
    if (!s.empty()){
        ListNode *l = s.top();
        s.pop();
        cout<<"flag: "<<flag<<endl;
        ListNode *cur;
        if (flag==1){
            cur = l;
        }
        else {
            cur = l->next;
        }
        while (!s.empty()){
            //put cur->next at s.top()'s right
            cout<<l->val<<" "<<cur->next->val<<endl;
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            tmp->next = l->next;
            l->next = tmp;

            cur = cur->next;
            l = s.top();
            s.pop();
        }
    }
}
*/
