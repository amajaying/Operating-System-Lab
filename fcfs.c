#include<stdio.h>
struct fcfs
{
    int process;
    int arrival;
    int burst;
    int waiting;
};

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct fcfs p[n];

    printf("Enter the process number, arrival time & burst time: ");
    
    for(int i=0; i<n; i++){
        printf("Enter process no: ");
        scanf("%d", &p[i].process);

        printf("Enter arrival time: ");
        scanf("%d", &p[i].arrival);

        printf("Enter burst time: ");
        scanf("%d", &p[i].burst);
    }

    int start = 0; 
    for(int i=0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(p[i].arrival == start){
                p[i].waiting = start;
                start = start + p[i].burst;
            }
            else{
                start++;
            }
        }
    }

    int sum = 0, temp = 0;
    p[0].waiting = 0;
    for(int i = 0; i<n ;i++){
        temp = p[i].burst+temp;
        // printf("%d\n", p[i].waiting);
        p[i+1].waiting = temp - p[i].arrival-1;
        sum += p[i].waiting;
    }

    float ans = (float)sum/n;

    printf("The Average Waiting time is: %f", ans);

}

