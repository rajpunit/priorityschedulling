//Priority Scheduling (Non Preeemptive) of given 3 processes as given in Problem

#include<stdio.h> 
int i,j,total_time=0;
float avgtat=0,avgwt=0;
int base=60;
void finding(struct data a[]);
void display(struct data a[]);
struct data
{
int at,bt,ct,tat,wt;           // at ->Arrival time , bt->Burst time, ct->Completion time, tat->Turnaround time, wt->waiting time
char pname[20];      //pname -> process name , 
int pr; //priority
int cpu_usage;
}temp;
main()
{
printf("\t\t\t\t ** PRIORITY SCHEDULING**\n\n ");
struct data aa[3];
aa[0].cpu_usage=40;
aa[1].cpu_usage=18;
aa[2].cpu_usage=40;
for(i=0;i<3;i++)
{
aa[i].pr=(aa[i].cpu_usage/2)+base;	        //calcuting priority by given formula 
}

printf("Number of process : 3\n");                   //9 processes Given in Project's Question

for(i=0;i<3;i++)
{
printf("-------------\n\n");
printf("Priority : %d\n",aa[i].pr);
printf("Enter Name of Process : "); 
scanf("%s",&aa[i].pname);
printf("Enter Arrival time : ");
scanf("%d",&aa[i].at);
printf("Enter Burst time : ");
scanf("%d",&aa[i].bt);
}
printf("\n-------------\n");
//sorting of Arrival time
for(i=0;i<3;i++)
{
for(j=i;j>=1;j--)
{
if(aa[j].at<aa[j-1].at)
{
temp=aa[j-1];
aa[j-1]=aa[j];
aa[j]=temp;
}
}
}
//finding the total time
total_time+=aa[0].at+aa[0].bt;
for(i=1;i<3;i++)
{
if(aa[i].at>total_time)
total_time=aa[i].at;//coz if the next process arives after a while after the b4 process has //complted
total_time+=aa[i].bt;
}

finding(aa);            //calculating the completion time
}
void finding(struct data a[])
{
//if(n==1)sum_st+=a[0].at;//coz the sum of all sevice time also includes waiting time
int time=0,x,c=0;//,procs[n];x for storing rh selected process
//c is for counter 
while(time<total_time)
{
j=0;
for(i=0;i<3;i++)
{	if(a[i].at<=time)
{
j=i+1;
}//sorring the list of processes that have arrived

}
if(j>0)
{
int x=0,min_pr=a[0].pr;//min priority
for(i=1;i<j;i++)
{
if(min_pr>a[i].pr)
{
x=i;
min_pr=a[i].pr;
}
else if(min_pr==a[i].pr)
{
if(a[x].at>a[i].at)
{
x=i;
min_pr=a[i].pr;
}
else if(a[x].at==a[i].at)
{
if(a[x].bt>a[i].bt)
{
x=i;
min_pr=a[i].pr;
}
}
}
}
time+=a[x].bt;//x is the process with min service time
a[x].ct=time;
a[x].pr+=1000;//so that it not selected again
a[x].at+=1000;//so that it not selected again based on arival time if its the only process

}
else
{
time++;
}

}
for(i=0;i<3;i++)
{
a[i].pr-=1000;
a[i].at-=1000;
}//so that its values return back to narmal
display(a);  // to display table of schedulling processes
}

void display(struct data a[])
{
for(i=0;i<3;i++)
{
a[i].tat=a[i].ct-a[i].at;
a[i].wt=a[i].tat-a[i].bt;
}
for(i=0;i<3;i++)
{
avgtat+=a[i].tat;
avgwt+=a[i].wt;
}
avgtat=avgtat/3;
avgwt=avgwt/3;

printf("\nSchedulling of Processes :  ");
for(i=0;i<3;i++)
{
printf("%s |",a[i].pname);
}
printf("\n-------------\n\n");
printf("Pr\tPName\tAT\tBT\tCT\tTAT\tWT\n");
for(i=0;i<3;i++)
{
printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t\n",a[i].pr,a[i].pname,a[i].at,a[i].bt,a[i].ct,a[i].tat);
}
printf("\n-------------\n");
printf("\nAverage Turnaround time =%f\n\nAverage Waiting Time=%f\n",avgtat,avgwt);
}

