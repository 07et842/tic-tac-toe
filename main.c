#include <stdio.h>
#include <stdlib.h>
#include "printgrid.h"

extern int user_array[5];
extern int cpu_array[4];

int main()
{
    int user_array_index = 0, cpu_array_index = 0;
    int user_input = 0, cpu_input = 0, x;
    
    printGrid();
    printf("\r\nyour turn:");
    scanf("%d", &user_input);
    if(user_input){
        update_array(user_array, &user_array_index, user_input);
        printGrid();
        cpu_input = user_input + 1;
        update_array(cpu_array, &cpu_array_index, cpu_input);
        printGrid();
    } else {
        exit(0);
    }

    for(int i = 0; i < 4; i++){
        printf("\r\nyour turn:");
        scanf("%d", &user_input);
        if(user_input){
            while(user_input != update_array(user_array, &user_array_index, user_input)){
                scanf("%d", &user_input);
            }
            printGrid();
            if(check_for_triplet(user_array)){
                printf("\r\n----you won----");
                exit(0);
            }
            cpu_input = check_for_possible_triplet(user_array);
            printf("\r\nusr3: %d\r\n", cpu_input);
            if(!cpu_input){
                cpu_input = check_for_possible_triplet(cpu_array);
                printf("\r\ncpu3: %d\r\n", cpu_input);
            }
            update_array(cpu_array, &cpu_array_index, cpu_input);
            printf("\r\ncpu's turn:");
            // scanf("%d", &x);
            printGrid();
            if(check_for_triplet(cpu_array)){
                printf("\r\n----cpu won----");
                exit(0);
            }
        } else {
            exit(0);
        }
    }
    return 0;
}
