#include<iostream>

using namespace std;
class Trie
{
private:

    struct Node
    {
        bool end_of_str = false;
        Node *next[26]={NULL};
    };
    Node *root = NULL;
    void insert(Node *node, string word)
    {
        if (word==""){
            node->end_of_str = true;
            return ;
        }
        if (node->next[word[0]-'a'] == NULL){
            node->next[word[0]-'a'] = new Node();
        }
        insert(node->next[word[0]-'a'], word.substr(1));
    }
    bool search(Node *node, string word)
    {
        if (word==""){
            return node->end_of_str;
        }
        if (node->next[word[0]-'a'] == NULL) return false;
        return search(node->next[word[0]-'a'], word.substr(1));
    }
    bool startWith(Node *node, string prefix)
    {
        if (prefix.size()==1){
            return node->next[prefix[0]-'a'] != NULL;
        }
        if (node->next[prefix[0]-'a']){
            return startWith(node->next[prefix[0]-'a'], prefix.substr(1));
        }
        return false;
    }
public:

    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        insert(root, word);
    }
    bool search(string word)
    {
        return search(root, word);
    }
    bool startsWith(string prefix)
    {
        if (prefix=="") return true;
        return startWith(root, prefix);
    }
};
int main()
{
    Trie obj;
    //string word = "abc";
    //string prefix = "";
    obj.insert("abc");
    cout<<obj.search("abc")<<endl;
    cout<<obj.search("ab")<<endl;
    obj.insert("ab");
    cout<<obj.search("ab")<<endl;
}
