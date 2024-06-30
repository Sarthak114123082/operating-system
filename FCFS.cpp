#include<iostream>
#include<vector>
using namespace std;

int main() {
    int items;
    cout<<"Enter number of items: ";
    cin>>items;

    vector<int> AT(items);
    vector<int> BT(items);

    cout<<"Enter arrival times and burst times for each item: ";
    for(int i=0;i<items;i++){
        cout<<"item "<<(i+1)<<" Arrival Time: ";
        cin >> AT[i];
        cout << "item " << (i + 1) << " Burst Time: ";
        cin >> BT[i];
    }

    vector<int> completion_time(items);
    vector<int> waiting_time(items);
    vector<int> turnaround_time(items);

    completion_time[0] = AT[0] + BT[0];
    turnaround_time[0] = completion_time[0] - AT[0];
    waiting_time[0] = turnaround_time[0] - BT[0];

    for (int i = 1; i < items; ++i) {
        completion_time[i] = completion_time[i - 1] + BT[i];
        turnaround_time[i] = completion_time[i] - AT[i];
        waiting_time[i] = turnaround_time[i] - BT[i];
    }

    double avg_waiting_time = 0;
    double avg_turnaround_time = 0;
    for (int i = 0; i < items; ++i) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= items;
    avg_turnaround_time /= items;

    cout << "\nitem\t Arrival Time\t Burst Time\t Completion Time\t Waiting Time\t Turnaround Time\n";
    for (int i = 0; i < items; ++i) {
        cout << "P" << (i + 1) << "\t\t " << AT[i] << "\t\t " << BT[i] << "\t\t "
             << completion_time[i] << "\t\t\t " << waiting_time[i] << "\t\t\t " << turnaround_time[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << avg_waiting_time << endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;

    return 0;
}
