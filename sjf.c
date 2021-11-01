// name: Kyung Cheol Koh 568849
// this program implements first come shortest job first algorithm using medical procedures

#include<stdio.h>

struct pcb{
	int process;
	int burst_time;
	int waiting_time;
	char* categories;
	int priorities;
};

enum categoryTypes{kneeSurgery, backSurgery,legSurgery,ankleSurgery, brainSurgery, eyeSurgery};

int main()
{
	//basic configurations
	// first set
	int processes[] = {1,2,3,4,5,6,7,8};
	int n = sizeof processes / sizeof processes[0];
	struct pcb pList[8];
	int burst_time1[] = {5, 9, 4,3,4,12,2,8};
	int priorities1[] = {2,5,3,2,1,5,3,4};
    char *categories[6] ={"knee surgery", "back surgery","leg surgery","ankle surgery","brain surgery", "eye surgery"};
    char *categoryList[8] = {categories[kneeSurgery], categories[backSurgery],
                             categories[legSurgery], categories[eyeSurgery],
                             categories[ankleSurgery], categories[brainSurgery],
                             categories[eyeSurgery], categories[backSurgery]};

	// assigning to the struct lists
	for (int i = 0; i < n ; i++){
		pList[i].process = processes[i];
		pList[i].burst_time= burst_time1[i];
		pList[i].waiting_time = i;
		pList[i].categories= categoryList[i];
		pList[i].priorities = priorities1[i];
	}


	printf("First Set======================================================\n");
    arrangeSJF(pList,n);
	printProcesses(pList,n);


	// second Set
	n = sizeof processes / sizeof processes[0];

	int burst_time2[8] = {8,7,1,2,2,4,2,7};
	int priorities2[8] = {5,5,1,2,2,3,1,4};
    char *categoryList2[8] = {categories[brainSurgery], categories[brainSurgery],
                             categories[legSurgery], categories[legSurgery],
                             categories[backSurgery], categories[backSurgery],
                             categories[eyeSurgery], categories[legSurgery]};


	// assigning to the struct lists
	for (int i = 0; i < n ; i++){
		pList[i].process = processes[i];
		pList[i].burst_time= burst_time2[i];
		pList[i].waiting_time = i;
		pList[i].categories= categoryList2[i];
		pList[i].priorities = priorities2[i];
	}


	printf("Second Set======================================================\n");
    arrangeSJF(pList,n);
	printProcesses(pList,n);


	
	// second Set
	n = sizeof processes / sizeof processes[0];
	pList[8];
	int burst_time3[] = {1,2,3,2,3,2,10,3};
	int priorities3[] = {1,1,3,1,2,2,5,1};
   
    char *categoryList3[8] = {categories[eyeSurgery], categories[ankleSurgery],
                             categories[legSurgery], categories[ankleSurgery],
                             categories[kneeSurgery], categories[kneeSurgery],
                             categories[brainSurgery], categories[legSurgery]};

	// assigning to the struct lists
	for (int i = 0; i < n ; i++){
		pList[i].process = processes[i];
		pList[i].burst_time= burst_time3[i];
		pList[i].waiting_time = i;
		pList[i].categories= categoryList3[i];
		pList[i].priorities = priorities3[i];
	}


	printf("Third Set======================================================\n");
    arrangeSJF(pList,n);
	printProcesses(pList,n);


	return 0;
}



void arrangeSJF(struct pcb pList[],  int n){
  
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (pList[j].burst_time < pList[min_idx].burst_time)
                min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        swap(&pList[min_idx], &pList[i]);
    }

}

// swapping between two pcb pointers
void swap(struct pcb *p1, struct pcb *p2){
    struct pcb temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}



//calculate waiting time 
void calculateWaitingTime(int processes[], int n,
						int burst_time[], int waiting_time[])
{
	// first process waiting time = 0
	waiting_time[0] = 0;
	// calculating waiting time
	for (int i = 1; i < n ; i++ )
		waiting_time[i] = burst_time[i-1] + waiting_time[i-1];

}

void printProcesses(struct pcb pList[],  int n)
{
	int processes[8];
	int burst_time[8];
	char *categories[8];
	int priorities[8];
	int waiting_time[n], total_waiting_time = 0;

	for (int i = 0; i < n ; i++){
		processes[i] = pList[i].process;
		burst_time[i] = pList[i].burst_time;
		categories[i] = pList[i].categories;
		priorities[i] = pList[i].priorities;
	}


	calculateWaitingTime(processes, n, burst_time, waiting_time);

	printf("Processes Burst time Waiting time categories     priorities\n");

	
	for (int i=0; i<n; i++)
	{
		total_waiting_time = total_waiting_time + waiting_time[i];
		
		printf("%d  ",processes[i]);
		printf("\t  %d", burst_time[i] );
		printf("\t\t%d",waiting_time[i] );
        printf("\t  %s",categories[i]);
		printf("\t  %d\n",priorities[i]);
	}
}


