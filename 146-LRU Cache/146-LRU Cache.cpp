#include<iostream>
#include<map>

using namespace std;
class LRUCache
{
    map<int, int> m;
    int capacity;
    int curLen;// number of cached items

    struct Node
    {
        Node *next;
        int key;
        Node(int x = 0):next(NULL), key(x) {}
    };
    Node *head; //head itself doesn't store key
    Node *tail;
public:
    LRUCache(int capac)
    {
        capacity = capac;
        curLen = 0;
        head = new Node();
        tail = head;
    }
    int moveToTail(int key)
    {
        //
        Node * tmp = head;
        while (tmp->next){
            if (tmp->next->key == key){
                break;
            }
            tmp = tmp->next;
        }
        if (tmp->next==NULL){
            cout<<"didn't find: "<<tmp->key<<endl;
            return -1;
        }
        else {
            if (tmp->next==tail) return 1;
            Node *res = tmp->next;
            tmp->next = tmp->next->next;
            tail->next = res;
            tail = tail->next;
            tail->next = NULL;
            cout<<"success, tail: "<<tail->key<<endl;
            return 1;
        }
    }
    int get(int key)
    {
        cout<<"--------------------------------------------"<<endl;
        //do cache only if the key exists
        //if exist, find the key in the list, move it to the tail
        if (m.count(key)==0){
            return -1;
        }
        else {
            //find the key in the linked list, and move it to the tail
            if (moveToTail(key)==-1)
                return -1;
            return m[key];
        }
    }
    void put(int key, int value)
    {
        cout<<"--------------------------------------------"<<endl;
        cout<<"put: "<<key<<" "<<value<<endl;
        //don't have to check whether exists
        //need to check the length of linked list
        if (m.count(key)==0){
            cout<<"key haven't appeared"<<endl;
            m[key] = value;
            if (curLen == capacity){
                cout<<"capacity reached:"<< curLen<<endl;
                //evict the first one;
                Node * tmp = head->next;
                head->next = head->next->next;
                cout<<"pop: "<<tmp->key<<endl;
                if (tmp == tail){
                    tail = head;
                    cout<<"tmp==tail"<<endl;
                }
                m.erase(tmp->key);
                delete tmp;
                //add this one
                tail->next = new Node(key);
                tail = tail->next;
                cout<<"push: "<<tail->key<<endl;
                //curLen does not change;
            }
            else {
                //i.e. <
                cout<<"capacity: "<<capacity<<" current length: "<<curLen<<endl;
                tail->next = new Node(key);
                tail = tail->next;
                curLen ++;
                cout<<"after operation, length: "<<curLen<<"; tail: "<<tail->key<<endl;
            }
        }
        else {
            cout<<"key have appeared"<<endl;
            m[key] = value;
            moveToTail(key);
        }
    }
    void print()
    {
        Node *tmp = head->next;
        while (tmp){
            cout<<tmp->key<<" ";
            tmp = tmp->next;
        }
        cout<<endl;
    }
};
int main()
{
    LRUCache cache(1);
    cache.put(2,1);
    cache.print();
    cout<<cache.get(2)<<endl;
    cache.print();
    cache.put(3,2);
    cout<<cache.get(2)<<endl;
    cache.print();
    cout<<cache.get(3)<<endl;
}
