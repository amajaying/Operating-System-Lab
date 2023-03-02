#include <stdio.h>

struct Process{
    int AT;
    int BT;
    int WT;
    int visited;
};

int main()
{
    int n;
    printf("ENter the number of process : ");
    scanf("%d",&n);
    struct Process P[n];
    
    printf("Enter the AT and BT of the process ");
    for(int i=0;i<n;i++){
        scanf("%d%d",&P[i].AT,&P[i].BT);
        P[i].visited=0;
    }
for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(P[i].AT > P[j].AT){
                int temp = P[i].AT;
                P[i].AT = P[j].AT;
                P[j].AT=temp;
                
                temp = P[i].BT;
                P[i].BT = P[j].BT;
                P[j].BT=temp;
            }
            else if(P[i].AT == P[j].AT){
                if(P[i].BT > P[j].BT){
                    temp = P[i].BT;
                    P[i].BT = P[j].BT;
                    P[j].BT=temp;
                    
                }
                
            }
        }
        
    }
int current_time=P[0].AT;
    int total_waiting=0;
    
    int index=0;
    int a=0,temp=1;
    while(temp==1){
        
        if(a==0){
            index=a;
            current_time+=P[index].BT;
            P[index].WT=0;
            P[index].visited=1;
            a++;
        }
        else{
            index=-1;
            int minimum_job=1000000000;
            for(int i=1;i<n;i++){
if(P[i].AT <= current_time && P[i].visited==0){
                    if(P[i].BT < minimum_job){
                        index=i;
                        minimum_job=P[i].BT;
                    }
                }
            }
            if(index!=-1){
               
                P[index].WT=0;
                P[index].visited=1;
                P[index].WT=current_time-P[index].AT;
                int waiting = current_time - P[index].AT;
                total_waiting= total_waiting + waiting;
                current_time+=P[index].BT;
                a++;
            }
            else{
                current_time++;
            }
            
        }
        
        if(a==n){
            temp=0;
        }
    }
    
    
    printf("\nTotal Waiting time : %d",total_waiting);
    
    
    
    
    
}
