#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    long long n;
    cout<<"Enter total number of process = ";
    cin>>n;

    queue<int> fifoQueue;
    long long index;
    for(int i=0;i<n;i++){
        cout<<"process ";
        cin>>index;
        fifoQueue.push(index);
    }

    cout<<"First element: process "<<fifoQueue.front()<<endl;

    vector<pair<long long,long long> > ATBT;

    long long sp=0, ep=0;
    cout<<"enter arrival time in vector.first and burst time in vector.second "<<endl;
    for(long long i=0;i<n;i++){
        cin>>sp>>ep;
        ATBT.push_back(make_pair(sp, ep));
    }

    vector<long long> TAT(n);
    vector<long long> WT(n);
    
    WT[0]=ATBT[0].first;
    TAT[0]=ATBT[0].second-ATBT[0].first;
    long long BT=ATBT[0].second;
    
    for(long long i=1;i<n;i++){
        WT[i]=BT-ATBT[i].first;
        BT+=ATBT[i].second;
        TAT[i]=BT-ATBT[i].first;
        cout<<"Removing element: process "<<fifoQueue.front()<<endl;
        fifoQueue.pop(); 
    }

    cout<<"Removing element: process 6"<<endl;
    
    double avg_WT=0;
    double avg_TAT=0;
    
    for(long long i=0;i<n;i++){
        avg_WT+=WT[i];
        avg_TAT+=TAT[i];
    }
    
    avg_WT/=n;
    avg_TAT/=n;
    
    cout<<"Average waiting time = "<<avg_WT<<endl;
    cout<<"Average turn around time = "<<avg_TAT<<endl;
    
    return 0;
}
