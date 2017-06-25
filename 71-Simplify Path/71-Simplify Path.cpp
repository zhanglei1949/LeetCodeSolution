#include<iostream>
#include<stack>
using namespace std;

string simplifyPath(string path)
{
    stack<string> directory;
    string token;
    int cur = 0;
    int tmp = 0;
    while (cur < path.size()){
        while (path[cur]=='/') cur++;
        tmp = cur;
        while (tmp < path.size() && path[tmp]!='/') tmp++;
        token = path.substr(cur, tmp-cur);
        //cout<<token<<endl;
        cur = tmp;
        while (path[cur]=='/') cur++;
        if (token==".."){
            if (!directory.empty()) directory.pop();
        }
        else if (token!=".") directory.push(token);

    }
    string res;
    if (directory.empty()){
        return "/";
    }
    while (!directory.empty()){
        res = '/'+directory.top()+res;
        directory.pop();
    }
    return res;
}

int main()
{
    string path;
    cin>>path;
    cout<<simplifyPath(path);
}
