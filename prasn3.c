#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{    //**********Process Initialisation*************************************
    int Burst_time[20],Arrival_time[10],Starting_time[10],Finishing_time[10];
	int Waiting_time[10],Turnaround_time[10];    
    int n,i,j,temp;
	int Total_Waiting_time=0,Total_Turnaround_time=0;                                        
    float Average_Waiting_Time,Average_Turnaround_Time;          
    char pn[10][10],t[10];
    
   //*****Taking input from the user************ 
    printf("Enter the number of process:\n");
    scanf("%d",&n);
    
    //*****for loop for as many  number of process**********
    for(i=0; i<n; i++)   
    {
    	re:

        printf("Enter the process name:");
        scanf("%s",pn[i]);
        printf("Enter the Arrival time of %s :",pn[i]);
        scanf("%d",&Arrival_time[i]);
        printf("Enter the Burst time of %s :",pn[i]);
         scanf("%d",&Burst_time[i]);
         printf("\n");
         
    //****As per given Question process with  Arrival time =0 is discarded***********
        if(Arrival_time[i]==0)                                    
        {
        	printf("Arrival time cant be zero\nPlease Re-enter\n");
        	goto re;
		}
    }
    //*** Sorting of the Process according to their Burst Time*********
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
        	if(Arrival_time[i]<=Arrival_time[j])
            if(Burst_time[i]<Burst_time[j])
            {
                temp=Arrival_time[i];                //***Simultaneously we are Attaching Arrival time and process
				Arrival_time[i]=Arrival_time[j];       // according to Burst Time ***************
			    Arrival_time[j]=temp;
			    
                temp=Burst_time[i];                  
                Burst_time[i]=Burst_time[j];
                Burst_time[j]=temp;
                
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)
    {   //*****if it is the first process its Arrival time will only be equal to its Starting time**********
        if(i==0)
            Starting_time[i]=Arrival_time[i];
        //*******Calculationn of Waiting time and Turnaround Time
        else 
		//*****As per Question + 2 units of time after completion of each process********
			                                                
            Starting_time[i]=Finishing_time[i-1]+2;
			 
        Waiting_time[i]=Starting_time[i]-Arrival_time[i]; 
        
        Finishing_time[i]=Starting_time[i]+Burst_time[i];
        Turnaround_time[i]=Finishing_time[i]-Arrival_time[i];
        
        //******Calculationn of Total Waiting time and Total Turnaround Time*******
        Total_Waiting_time+=Waiting_time[i];          
        Total_Turnaround_time+=Turnaround_time[i];
	}
	//**********to calculate Average Waiting time and Average Turnaround Time*********
    Average_Waiting_Time=(float)Total_Waiting_time/n;
    Average_Turnaround_Time=(float)Total_Turnaround_time/n;
    
    //*****For printing the Table***
    printf("\nProcessname\tArrivaltime\tExecutiontime\tTotal_Waitingtime\tTotalt_Turnaroundtime");
    for(i=0; i<n; i++)
      printf("\n%s\t\t%5d\t\t%5d\t\t\t%5d\t\t%5d",pn[i],Arrival_time[i],Burst_time[i],Waiting_time[i],Turnaround_time[i]);
      //****Display final***
      printf("\n");
    printf("\nAverage waiting time is:%f",Average_Waiting_Time);
    printf("\nAverage turnaroundtime is:%f",Average_Turnaround_Time);
   // getch();
}
