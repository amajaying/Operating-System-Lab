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
