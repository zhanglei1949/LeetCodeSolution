#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};
bool hasCycle(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;

    do{
        fast = fast->next;
        if (!fast) return false;
        else fast = fast->next;
        if (!fast) return false;
        slow = slow->next;
    }while (fast != slow);
    //when fast == slow, they must meet at the conjuction point
    return true;
}
int main()
{
    ListNode * head = new ListNode(1);
    //head->next = new ListNode(2);
    //head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(4);
    //head->next->next->next->next = new ListNode(5);
    //head->next->next->next->next->next = head->next->next;
    cout<<hasCycle(head);
}
