#include<iostream>
#include<vector>
using namespace std;

bool check(int y, const vector<int>& ans, const vector<pair<int, int> >& depend){
    int check=0;
    for(int i=0;i<ans.size();i++){
        if(ans[i]==depend[i].first){
            check+=1;
        }
    }
    if(check==y){
        return true;
    }
    return false;
}
bool check_deadlock(int y, const vector<pair<int, int> >& depend){
    vector<int> ans;
    ans.push_back(depend[0].first);
    for(int i=0;i<y-1;i++){
        if(depend[i].second==depend[i+1].first){
            ans.push_back(depend[i].second);
        }
    }
    if(check(y, ans, depend)){
        return true;
    }
    return false;
}
int main()
{
    int x, y;
    cout<<"Enter total number of processes: ";
    cin>>x;
    cout<<"Enter total number of dependence of 1 process on another: ";
    cin>>y;

    vector<pair<int, int> > depend;

    cout<<"Enter input in this manner: (1 2 means 1 depends on 2):"<<endl;
    for(int i=0;i<y;i++){
        int stpt, enpt;
        cin>>stpt>>enpt;
        depend.push_back(make_pair(stpt, enpt));
    }
    if(depend[0].first==depend[y-1].second){
        if(check_deadlock(y,depend)){
            cout<<"Deadlock detected"<<endl;
            return 0;
        }
    }
    cout<<"Deadlock not detected";
    return 0;
}