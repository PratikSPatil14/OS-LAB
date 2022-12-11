#include<iostream>
using namespace std;
int main() {
    int n,bt[20],wt[20],tat[20], arrvt[20], ct[20], i,j;
    float avwt=0, avtat=0;
    cout<<"Enter total number of processes(maximum 20):";
    cin>>n;
    cout<<"\nEnter Process Burst Time\n";
    for (i=1;i<=n;i++) {
        cout<<"P["<<i<<"]:";
        cin>>bt[i];
    }
    cout<<"\nEnter Process Arrival Time\n";
    for (i=1;i<=n;i++) {
        cout<<"P["<<i<<"]:";
        cin>>arrvt[i];
    }
    wt[0]=0;
    ct[0] = 0;
    ct[1] = bt[1] + arrvt[1];
    for (i=2; i<=n; i++){
        
        if(ct[i-1]>arrvt[i]){
            ct[i] = bt[i] + ct[i-1];
        }
        else{
            ct[i] = bt[i] + arrvt[i];
        }
    }
    cout<<"\nProcess4\tArrival time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time";
    //calculating turnaround time
    for (i=1;i<=n;i++) {
        tat[i]=ct[i] - arrvt[i];
        wt[i] = tat[i] - bt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<arrvt[i]<<"\t\t"<<bt[i]<<"\t\t"<<ct[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
    }
    avwt/=n;
    avtat/=n;
    cout<<"\n\nAverage Waiting Time:"<<avwt;
    cout<<"\nAverage Turnaround Time:"<<avtat;
    return 0;
}
