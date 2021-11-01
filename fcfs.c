// C program for implementation of FCFS
// scheduling
#include<stdio.h>

struct pcb{
	int process;
	int burst_time;
	int waiting_time;
	int turn_around;
	char* categories;
	int priorities;
};

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
// (int processes[], int n, int bt[],char **categories,int priorities[])
void findavgTime(struct pcb pList[],  int n)
{
	int processes[8];
	int bt[8];
	char *categories[8];
	int priorities[8];
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	for (int i = 0; i < n ; i++){
		processes[i] = pList[i].process;
		bt[i] = pList[i].burst_time;
		categories[i] = pList[i].categories;
		priorities[i] = pList[i].priorities;
	}

	// for (int i = 0; i < n ; i++){
	// 	printf("%d ",pList[i].process);
	// 	printf("%d ",pList[i].burst_time);
	// 	// printf("%d ",pList[i].waiting_time);
	// 	// printf("%d ",pList[i].turn_around);
	// 	printf("%s ",pList[i].categories);
	// 	printf("%d\n",pList[i].priorities);
	// }
	

	//Function to find waiting time of all processes
	findWaitingTime(processes, n, bt, wt);

	//Function to find turn around time for all processes
	findTurnAroundTime(processes, n, bt, wt, tat);

	//Display processes along with all details
	printf("Processes Burst time Waiting time Turn around time categories     priorities\n");

	// Calculate total waiting time and total turn
	// around time
	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf("%d  ",(i+1));
		printf("\t  %d", bt[i] );
		printf("\t\t%d",wt[i] );
		printf("\t  %d",tat[i] );
        printf("\t\t  %s",categories[i]);
		printf("\t  %d\n",priorities[i]);
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
	struct pcb pList[8];
	//Burst time of all processes
	int burst_time[] = {5, 9, 4,3,4,12,2,8};
	int priorities[] = {2,5,3,2,1,5,3,4};
    char *categories[6] ={"knee surgery", "back surgery","leg surgery","ankle surgery","brain surgery", "eye surgery"};

    char *categoryList[8] = {categories[kneeSurgery], categories[backSurgery],
                             categories[legSurgery], categories[eyeSurgery],
                             categories[ankleSurgery], categories[brainSurgery],
                             categories[eyeSurgery], categories[backSurgery]};


	// assigning to the struct lists
	for (int i = 0; i < n ; i++){
		pList[i].process = processes[i];
		pList[i].burst_time= burst_time[i];
		pList[i].waiting_time = i;
		pList[i].turn_around= i;
		pList[i].categories= categoryList[i];
		pList[i].priorities = priorities[i];
	}


	// for (int i = 0; i < n ; i++){
	// 	printf("%d ",pList[i].process);
	// 	printf("%d ",pList[i].burst_time);
	// 	printf("%d ",pList[i].waiting_time);
	// 	printf("%d ",pList[i].turn_around);
	// 	printf("%s ",pList[i].categories);
	// 	printf("%d\n",pList[i].priorities);
	// }
	
	findavgTime(pList,n);
	return 0;
}
