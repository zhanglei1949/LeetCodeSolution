#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites)
{
    //equivalent to determine whether have a cycle
    queue<int> q;
    vector<int> flag(numCourses, 0);
    vector<pair<int,int> > prerequire(prerequisites);
    //flag[i]==0 means it can be traversed.
    //flag[i]==1 means it is already finished
    //flag[i] < 0 means it can not be traversed, the number is its prerequisites
    for (int i = 0; i < prerequire.size(); ++i){
        flag[prerequire[i].second] += -1;
    }
    for (int i = 0 ; i< numCourses; ++i){
        if (flag[i]==0){
            q.push(i);
            //cout<<"push: "<<i<<endl;
            flag[i] = 1;
        }
    }
    while (q.size() > 0){
        int head = q.front();
        q.pop();
        //cout<<"pop: "<<head<<endl;

        for (vector<pair<int,int> >::iterator iter = prerequire.begin(); iter != prerequire.end(); ){
            //cout<<"prerequisites "<<iter->first<<" "<<iter->second<<endl;
            if (head == iter->first){
                flag[iter->second] += 1;
                iter  = prerequire.erase(iter);
                for (int i = 0; i < numCourses; ++i){
                    if (flag[i]==0){
                        q.push(i);
                        //cout<<"push: "<<i<<endl;
                        flag[i] = 1;
                    }
                }
            }
            else iter++;
        }
        // update
    }
    for (int i = 0; i < numCourses; ++i){
        if (flag[i] < 0) return false;
    }
    return true;
}
int main()
{
    int numCourses = 2;
    vector<pair<int, int> >  prerequisites;
    prerequisites.push_back(pair<int, int> (0,1));
    prerequisites.push_back(pair<int, int> (1,0));
//    prerequisites.push_back(pair<int, int> (0,2));
//    prerequisites.push_back(pair<int, int> (2,3));
//    prerequisites.push_back(pair<int, int> (1,3));
//    prerequisites.push_back(pair<int, int> (3,4));
//    prerequisites.push_back(pair<int, int> (4,1));
//    for (int i = 0; i < prerequisites.size(); ++i){
//        cout<<prerequisites[i].first<<" "<<prerequisites[i].second<<endl;
//    }
//    //prerequisites.erase(prerequisites.begin()+3);
//    cout<<endl;
//    for (int i = 0; i < prerequisites.size(); ++i){
//        cout<<prerequisites[i].first<<" "<<prerequisites[i].second<<endl;
//    }
    cout<<canFinish(numCourses, prerequisites);
}
