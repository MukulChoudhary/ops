#include<stdio.h>
#include<conio.h>
int main()
{
  long int n,i=0,j=0,pos=0;
  printf("\t\t\t----------------------- Scheduling -----------------------\n\n\n\n"); 
  printf("Enter Number of Processes : ");
  scanf("%ld",&n ); 
  double process[n],bt[n],at[n],waitingTime[n],priority[n],turnaroundTime[n];
  double swap,temp,first,first1, completionTime[n],sum=0,wait_total, turnaround_total,sum1=0, wait_avg, turnaround_avg,awt,atat;
  for(i=0;i<n;i++)
  {
    printf("\nEnter Burst Time for Process [%d] : ", i+1 );
    scanf("%lf", &bt[i]);
    printf("Enter Arrival Time for Process [%d] : ", i+1 );
    scanf("%lf", &at[i] );
    process[i]=i+1;           // contain process number
  }

   for(i=0;i<n;i++)            // sorting
  {
    for(j=0;j<n;j++)
    {
      if(at[i]<at[j])
      {
        
        swap = bt[j];
        bt[j] = bt[i];
        bt [i] = swap;
	
	      swap = process[j];
        process[j] = process[i];
        process[i] = swap;

	      swap = at[j];
        at[j] = at[i];
        at[i] = swap;
      
      }
    }
  }
  printf("\n\n Sorting  according to Arrivaltime \n");
  printf("\n| Process   | Arrival Time    | Burst Time    |\n\n");
  for(i=0;i<n;i++)
  {
    printf("|  P[%0.1f]   |       %0.02f      |     %0.02f      |\n",process[i],at[i],bt[i]);
	}
      // arranging according burst time
  long int p = 1;
  double time = 0;
  for(j=0;j<n;j++)
  {
    time = time + bt[j];
    first = bt[p];

    for(i=p;i<n;i++)
    {
      if((time >= at[i])&&(bt[i]<first))
      {
        swap = bt[p];
        bt[p] = bt[i];
        bt[i] = swap;

        swap = at[p];
        at[p] = at[i];
        at[i] = swap;

        swap = process[p];
        process[p] = process[i];
        process[i] = swap;
      }
    }
    p++;
  }
  waitingTime[0] = 0;     // waiting time for first process will be zero
  
  for(i=1;i<n;i++)           //calculating waiting time
  {
    sum =sum + bt[i-1];
    waitingTime[i] = sum - at[i];
    wait_total =wait_total + waitingTime[i]; 
  }
  wait_avg = wait_total/n;
  
  for(i=0;i<n;i++)
  {
    sum1 =sum1 + bt[i];
    turnaroundTime[i] = sum1 - at[i];
    turnaround_total =turnaround_total + turnaroundTime[i];
  }
  turnaround_avg=turnaround_total/n;
  
printf("\n    Now  Values \n\n");
  printf("| Process   | Arrival Time    | Burst Time    |  Waiting Time     |  Turn Around Time  \n");
  for(i=0;i<n;i++)
  {
    printf("|  P[%0.1f]   |       %0.02f      |     %0.02f      |        %0.02f       |         %0.02f         \n",process[i],at[i],bt[i],waitingTime[i],turnaroundTime[i]);
  }
  
  // prioritize the processes according to the formula:
  
  completionTime[0] = bt[0];
  for(i=1;i<n;i++)
  {
    completionTime[i] = completionTime[i-1] + bt[i];
  }

  for(i=0;i<n;i++)
  {
    priority[i] =( 1+waitingTime[i])/completionTime[i];
    
    printf("\n P[%0.1f] = %2f",process[i],priority[i]);
  }

  printf("\n\n    Final Value  \n");
  printf("\n");
  printf("| Process   | Arrival Time    | Burst Time    |    Priority   |  Waiting Time     |  Turn Around Time   \n");
  printf("|  P[%0.1f]   |       %0.02f      |     %0.02f      |     %0.02f      |        %0.02f       |         %0.02f        \n",process[0],at[0],bt[0],priority[0],waitingTime[0],turnaroundTime[0]);
  for(i=n-1;i>0;i--)
  {
    printf("|  P[%0.1f]   |       %0.02f      |     %0.02f      |     %0.02f      |        %0.02f       |         %0.02f        \n",process[i],at[i],bt[i],priority[i],waitingTime[i],turnaroundTime[i]);
  }
  printf("\n\n\tTotal turnaround Time = %1f",turnaround_total);
  printf("\n\tAverage Turn Around Time : %lf",turnaround_avg);
  printf("\n\n\tTotal waiting Time = %1f",wait_total);
  printf("\n\tAverage Waiting Time  : %lf\n\n",wait_avg);
 
  getch();
  return 0;
}

