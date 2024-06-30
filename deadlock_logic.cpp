#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

bool CycleDeadlock(int index, const vector<vector<int> >& connections, vector<int>& visit, vector<int>& insideRecursion){
    if(insideRecursion[index]){
        return true;
    }
    if(visit[index]){
        return false;
    }

    visit[index]=1;
    insideRecursion[index]=1;

    for(size_t i=0;i<connections[index].size();i++){
        int side=connections[index][i];
        if(CycleDeadlock(side, connections, visit, insideRecursion)){
            return true;
        }
    }
    insideRecursion[index]=0;
    return false;
}

bool findDeadlock(int x, const vector<pair<int, int> >& depend){
    vector<vector<int> > connections(x + 1); 
    for(size_t i=0;i<depend.size();i++){
        int first=depend[i].first;
        int second=depend[i].second;
        connections[first].push_back(second);
    }

    vector<int> visit(x+1, 0);
    vector<int> insideRecursion(x+1, 0);

    for(int i=1;i<=x;i++){
        if(!visit[i]){
            if(CycleDeadlock(i, connections, visit, insideRecursion)){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int x, y;
    cout<<"Enter total number of processes: ";
    cin>>x;
    cout<<"Enter total number of dependencies (process 1 depends on process 2): ";
    cin>>y;

    vector<pair<int, int> > depend;
    cout<<"Enter dependencies in this manner (1 2 means process 1 depends on process 2):"<<endl;
    for(int i=0;i<y;i++){
        int stpt, enpt;
        cin>>stpt>>enpt;
        depend.push_back(make_pair(stpt, enpt));
    }

    if(findDeadlock(x, depend)){
        cout<<"Deadlock detected"<<endl;
    }else{
        cout<<"Deadlock not detected"<<endl;
    }

    return 0;
}
