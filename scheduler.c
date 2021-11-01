// C program for implementation of FCFS
// scheduling
#include<stdio.h>
enum week{Mon, Tue, Wed};
enum categoryTypes{kneeSurgery, backSurgery,legSurgery,ankleSurgery, brainSurgery, eyeSurgery};
// Function to find the waiting time for all
// processes
void findWaitingTime(int processes[], int n,
						int bt[], int wt[])
{
	// waiting time for first process is 0
	wt[0] = 0;

	// calculating waiting time
	for (int i = 1; i < n ; i++ )
		wt[i] = bt[i-1] + wt[i-1];

}

// Function to calculate turn around time
void findTurnAroundTime( int processes[], int n,
				int bt[], int wt[], int tat[])
{
	// calculating turnaround time by adding
	// bt[i] + wt[i]
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}

//Function to calculate average time
void findavgTime( int processes[], int n, int bt[],char **categories)
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	//Function to find waiting time of all processes
	findWaitingTime(processes, n, bt, wt);

	//Function to find turn around time for all processes
	findTurnAroundTime(processes, n, bt, wt, tat);

	//Display processes along with all details
	printf("Processes Burst time Waiting time Turn around time categories\n");

	// Calculate total waiting time and total turn
	// around time
	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf(" %d ",(i+1));
		printf("\t  %d  ", bt[i] );
		printf("\t    %d",wt[i] );
		printf("\t  %d",tat[i] );
        printf("\t\t  %s\n",categories[i] );
	}
	int s=(float)total_wt / (float)n;
	int t=(float)total_tat / (float)n;
	printf("Average waiting time = %d",s);
	printf("\n");
	printf("Average turn around time = %d ",t);
}

// Driver code
int main()
{
	//process id's
	int processes[] = {1,2,3,4,5,6,7,8};
	int n = sizeof processes / sizeof processes[0];

	//Burst time of all processes
	int burst_time[] = {10, 5, 8,7,3,4,8,9};

    char *categories[6] ={"knee surgery", "back surgery","leg surgery","ankle surgery","brain surgery", "eye surgery"};

    char *categoryList[8] = {categories[kneeSurgery], categoryList[kneeSurgery],
                             categoryList[2], categories[eyeSurgery],
                             categories[ankleSurgery], categories[brainSurgery],
                             categories[eyeSurgery], categories[backSurgery] 
                             };

	findavgTime(processes, n, burst_time,categoryList);
	return 0;
}
// This code is contributed by Shivi_Aggarwal
