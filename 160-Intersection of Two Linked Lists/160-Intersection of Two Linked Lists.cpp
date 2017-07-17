#include<iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};
ListNode *_getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL) return NULL;
    ListNode *a = headA, *b = headB;
    while (a != b){
        cout<<a->val<<" "<<b->val<<endl;
        a = a->next;
        b = b->next;
        if (a==b) return a;
        //provide out path for no intersection
        if (a==NULL) a = headB;
        if (b==NULL) b = headA;
    }
    return a;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    //get the length of two linked list;
    //the part after intersection must be the same
    if (headA == NULL || headB ==NULL) return NULL;
    int lenA = 0;
    int lenB = 0;
    ListNode *a = headA;
    ListNode *b = headB;
    while (a){
        a = a->next;
        lenA++;
    }
    while (b){
        b = b->next;
        lenB++;
    }
    a = headA;
    b = headB;
    while (lenA > lenB){
        a = a->next;
        lenA--;
    }
    while (lenB > lenA){
        b = b->next;
        lenB--;
    }
    while (a != b){
        a = a->next;
        b = b->next;
    }
    return a;
}
int main()
{
    ListNode *headA = new ListNode(1);
    ListNode *headB = new ListNode(5);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    //headB->next = headA->next->next;

    //headB->next->next = new ListNode(4);
    ListNode *res = getIntersectionNode(headA, headB);
    //cout<<res->val<<endl;
    return 0;
}
