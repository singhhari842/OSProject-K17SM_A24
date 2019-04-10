#include<stdio.h>
int main()
{
int i,process[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,b_time=0;
int burst_time[10],temp,j,arrival_time[10],waiting_time[10],taround_time[10],ta=0,sum=0;
float wavg=0,tavg=0,tsum=0,wsum=0;

 
for(i=0;i<4;i++)
{

printf("Enter the arrival time of %d process :",i+1);
scanf(" %d",&arrival_time[i]);
printf("Enter the burst time of %d process :",i+1);
scanf(" %d",&burst_time[i]);
}
 
/*Sorting According to Arrival Time*/
 //**********only 4 process has been taken because it is given in question*********
for(i=0;i<4;i++)
{
for(j=0;j<4;j++)
{
if(arrival_time[i]<arrival_time[j])
{
temp=process[j];
process[j]=process[i];
process[i]=temp;

temp=arrival_time[j];
arrival_time[j]=arrival_time[i];
arrival_time[i]=temp;

temp=burst_time[j];
burst_time[j]=burst_time[i];
burst_time[i]=temp;
}
}
}
 
/*Arranging the table according to Burst time,
Execution time and Arrival Time
Arrival time <= Execution time
*/
 
for(j=0;j<4;j++)
{
b_time=b_time+burst_time[j];
min=burst_time[k];

for(i=k;i<4;i++)
{
if (b_time>=arrival_time[i] && burst_time[i]<min)
{
temp=process[k];
process[k]=process[i];
process[i]=temp;

temp=arrival_time[k];
arrival_time[k]=arrival_time[i];
arrival_time[i]=temp;

temp=burst_time[k];
burst_time[k]=burst_time[i];
burst_time[i]=temp;
}
}
k++;
}
waiting_time[0]=0;

for(i=1;i<4;i++)
{
sum=sum+burst_time[i-1];
waiting_time[i]=sum-arrival_time[i];
wsum=wsum+waiting_time[i];
}
 
wavg=(wsum/4);

for(i=0;i<4;i++)
{
ta=ta+burst_time[i];
taround_time[i]=ta-arrival_time[i];
tsum=tsum+taround_time[i];
}
 
tavg=(tsum/4);
 

printf("\n RESULT:-");
printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
for(i=0;i<4;i++)
{
printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",process[i],burst_time[i],arrival_time[i],waiting_time[i],taround_time[i]);
}
 
printf("\n\nAVERAGE WAITING TIME : %f",wavg);
printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
return 0;
}
