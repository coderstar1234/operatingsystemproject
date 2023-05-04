#include<stdio.h>
 
struct times
{
       int p,art,but,wtt,tat,rnt;
};
 
 
void sortart(struct times a[],int pro)
{
       int i,j;
       struct times temp;
       for(i=0;i<pro;i++)
       {
              for(j=i+1;j<pro;j++)
              {
                     if(a[i].art > a[j].art)
                     {
                           temp = a[i];
                           a[i] = a[j];
                           a[j] = temp;
                     }
              }
       }
       return;
}
 
int main()
{
       int i,j,pro,time,remain,flag=0,ts;
       struct times a[100];
       float avgwt=0,avgtt=0;
       printf("Round Robin Scheduling Algorithm\n");
       printf("Note -\n1. Arrival Time of at least on process should be 0\n2. CPU should never be idle\n");
       printf("Enter Number Of Processes : ");
       scanf("%d",&pro);
       remain=pro;
       for(i=0;i<pro;i++)
       {
              printf("Enter arrival time and Burst time for Process P%d : ",i);
              scanf("%d%d",&a[i].art,&a[i].but);
              a[i].p = i;
              a[i].rnt = a[i].but;
       }
       sortart(a,pro);
       printf("Enter Time Slice OR Quantum Number : ");
       scanf("%d",&ts);
       printf("\n***************************************\n");
       printf("Gantt Chart\n");
       printf("0");
       for(time=0,i=0;remain!=0;)
       {
              if(a[i].rnt<=ts && a[i].rnt>0)
              {
                     time = time + a[i].rnt;
                     printf(" -> [P%d] <- %d",a[i].p,time);
                     a[i].rnt=0;
                     flag=1;
              }
              else if(a[i].rnt > 0)
              {
                     a[i].rnt = a[i].rnt - ts;
                     time = time + ts;
                     printf(" -> [P%d] <- %d",a[i].p,time);
              }
              if(a[i].rnt==0 && flag==1)
              {
                     remain--;
                     a[i].tat = time-a[i].art;
                     a[i].wtt = time-a[i].art-a[i].but;
                     avgwt = avgwt + time-a[i].art-a[i].but;
                     avgtt = avgtt + time-a[i].art;
                     flag=0;
              }
              if(i==pro-1)
                     i=0;
              else if(a[i+1].art <= time)
                     i++;
              else
                     i=0;
       }
       printf("\n\n");
       printf("***************************************\n");
       printf("Pro\tArTi\tBuTi\tTaTi\tWtTi\n");
       printf("***************************************\n");
       for(i=0;i<pro;i++)
       {
              printf("P%d\t%d\t%d\t%d\t%d\n",a[i].p,a[i].art,a[i].but,a[i].tat,a[i].wtt);
       }
       printf("***************************************\n");
       avgwt = avgwt/pro;
       avgtt = avgtt/pro;
       printf("Average Waiting Time : %.2f\n",avgwt);
       printf("Average Turnaround Time : %.2f\n",avgtt);
       return 0;
}
 
 
/*
Inputs
4
2 8
1 3
0 5
3 6
3
*/
 
 
 
/*
Round Robin Scheduling Algorithm
Note -
1. Arrival Time of at least on process should be 0
2. CPU should never be idle
Enter Number Of Processes : 4
Enter arrival time and Burst time for Process P0 : 2 8
Enter arrival time and Burst time for Process P1 : 1 3
Enter arrival time and Burst time for Process P2 : 0 5
Enter arrival time and Burst time for Process P3 : 3 6
Enter Time Slice OR Quantum Number : 3
 
***************************************
Gantt Chart
0 -> [P2] <- 3 -> [P1] <- 6 -> [P0] <- 9 -> [P3] <- 12 -> [P2] <- 14 -> [P0] <- 17 -> [P3] <- 20 -> [P0] <- 22
 
***************************************
Pro     ArTi    BuTi    TaTi    WtTi
***************************************
P2      0       5       14      9
P1      1       3       5       2
P0      2       8       20      12
P3      3       6       17      11
***************************************
Average Waiting Time : 8.50
Average Turnaround Time : 14.00
*/

