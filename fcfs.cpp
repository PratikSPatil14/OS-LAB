
#include<iostream>
using namespace std;


void findWaitingTime(int processes[], int n,
						int bt[], int wt[], int at[])
{
	// waiting time for first process is 0
	wt[0] = 0;

	
	for (int i = 1; i < n ; i++ )
		wt[i] = bt[i-1] + wt[i-1] ;
}

// Function to calculate turn around time
void findTurnAroundTime( int processes[], int n,
				int bt[], int wt[], int tat[])
{
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}


void findavgTime( int processes[], int n, int bt[], int at[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	findWaitingTime(processes, n, bt, wt, at);

	findTurnAroundTime(processes, n, bt, wt, tat);


	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n";


	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] <<endl;
	}

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
}

// Driver code
int main()
{
	
	int processes[] = { 1, 2, 3};
	int n = sizeof processes / sizeof processes[0];
	int burst_time[] = {2, 2, 3};
    int arrival_time[] = {0, 1, 5};

	findavgTime(processes, n, burst_time, arrival_time);
	return 0;
}
