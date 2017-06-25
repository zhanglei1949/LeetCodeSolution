#include<iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* deleteDuplicates(ListNode* head)
{
    if (head==NULL) return NULL;
    ListNode *head_pre = new ListNode(-1);
    head_pre->next = head;
    ListNode *cur = head_pre;
    ListNode *tmp = head->next;
    ListNode *todelete;
    //starting from cur-Next
    //1-2-3
    while (cur->next){
        tmp = cur->next->next;
        //bool flag = false;
        while (tmp && tmp->val ==cur->next->val){
            todelete = cur->next;
            cur->next = tmp;
            tmp = tmp->next;
            delete todelete;
            //flag = true;
        }
        cur = cur->next;
    }
    return head_pre->next;
}

int main()
{
    ListNode * head = new ListNode(1);
    ListNode * tmp = new ListNode(2);
    head->next = tmp;
    tmp->next = new ListNode(2);
    tmp->next->next = new ListNode(3);
    tmp->next->next->next = new ListNode(3);
    ListNode *res = deleteDuplicates(head);
    tmp = res;
    while (tmp){
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
}
