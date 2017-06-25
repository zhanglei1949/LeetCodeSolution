#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};
ListNode* partition(ListNode* head, int x)
{
    //the idea is to iteratively move the elements larger than x to the back;
    ListNode *new_head = new ListNode(-1);
    ListNode *tmp1;
    ListNode *tmp2;
    new_head->next = head;
    if (head==NULL) return NULL;
    ListNode *cur_pre = new_head;
    ListNode *knownFarthestLarge = cur_pre->next;
    while (knownFarthestLarge){
        //cout<<"cur_pre: "<<cur_pre->val<<endl;
        //cout<<"knownFarthestLarge: "<<knownFarthestLarge->val<<endl;
        if (cur_pre->next->val >= x){
            while (knownFarthestLarge->next && knownFarthestLarge->next->val >= x){
                knownFarthestLarge = knownFarthestLarge->next;
            }
            if (!knownFarthestLarge->next) break;
            //cout<<"known: "<<knownFarthestLarge->val<<endl;
            //known->next is less than x
            tmp1 = cur_pre->next;
            tmp2 = knownFarthestLarge->next;
            knownFarthestLarge->next = knownFarthestLarge->next->next;
            cur_pre->next = tmp2;
            cur_pre->next->next = tmp1;
            //ok

        }
        cur_pre = cur_pre->next;
        knownFarthestLarge = cur_pre->next;
    }
    return new_head->next;
}
int main()
{
    ListNode *head;
    ListNode *tmp;
    head = new ListNode(5);
    tmp = head;
    tmp->next = new ListNode(4);
    tmp = tmp->next;

    tmp->next = new ListNode(3);
    tmp = tmp->next;

    tmp->next = new ListNode(2);
    tmp = tmp->next;

    tmp->next = new ListNode(5);
    tmp = tmp->next;

    tmp->next = new ListNode(1);
    tmp = head;

    ListNode *res = partition(head, 2);
    tmp = res;
    while (tmp){
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
}
