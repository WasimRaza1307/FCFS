#include<iostream> 
using namespace std; 
#include<conio.h>
void WaitingTime(int processes[], int n, float bt[], float wt[], float at[]) 
{ 
    float service_time[n]; 
    service_time[0] = 0; 
    wt[0] = 0; 
    //to calculate waiting time 
    for (int i = 1; i < n ; i++) 
    { 
        service_time[i] = service_time[i-1] + bt[i-1];//adding BT of previous processes 
        wt[i] = service_time[i] - at[i];//waiting time of current process. 
        if (wt[i] < 0)
            wt[i] = 0; 
    } 
} 
void TurnAroundTime(int processes[], int n, float bt[], float wt[], float tat[]) 
{  
    for (int i = 0; i < n ; i++) 
        tat[i] = bt[i] + wt[i];//TurnaroundTime=BurstTime+WaitingTime 
} 
void AvgWaitTime(int processes[], int n, float bt[], float at[]) 
{ 
    float wt[n], tat[n]; 
    WaitingTime(processes, n, bt, wt, at);//waiting time of all processes  
    TurnAroundTime(processes, n, bt, wt, tat);//turn around time for all processes  
    cout << "Processes " << " Burst Time " << " Arrival Time "<< " Waiting Time " << " Turn-Around Time "<< " Completion Time \n"; 
    float total_wt = 0, total_tat = 0; 
    for (int i = 0 ; i < n ; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        float compl_time = tat[i] + at[i]; 
        cout << " " << i+1 << "\t\t" << bt[i] << "\t\t"<< at[i] << "\t\t" << wt[i] << "\t\t "<< tat[i]  <<  "\t\t " << compl_time << endl; 
    } 
    cout << "Average waiting time = "<< (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n; 
} 
int main() 
{ 
    int processes[] = {1, 2, 3}; 
    int n = sizeof processes / sizeof processes[0];  
    float burst_time[] = {8, 4, 1};//BT of Processes
    float arrival_time[] = {0.0,0.4,1.0}; //AT of processes
    AvgWaitTime(processes, n, burst_time, arrival_time); 
    getch();
    return 0; 
} 
