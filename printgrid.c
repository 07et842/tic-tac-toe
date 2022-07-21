#include "printgrid.h"
int grid[9] = {6, 7, 2, 1, 5, 9, 8, 3, 4};
int user_array[5] = {0}, cpu_array[4] = {0};

void printGrid(){
    system("clear");
    printf("\r");
    for(int i = 0; i < 9; i++){
        if(check_value_in_array(user_array, grid[i])){
            printf (" x ");
        } else if(check_value_in_array(cpu_array, grid[i])){
            printf (" o ");
        } else {
            printf(" %d ", grid[i]);
        }
        if(i < 8){
            if((i+1) % 3 == 0){
                printf("\r\n---+---+---\r\n");
            } else {
                printf("|");
            }
        }
    }
#if 0
    printf("\r\nusr: ");
    int i = 0;
    while(user_array[i]){
        printf("%d ", user_array[i++]);
    }
    printf("\r\ncpu: ");
    i = 0;
    while(cpu_array[i]){
        printf("%d ", cpu_array[i++]);
    }
#endif
}

int update_array(int *array, int *array_index, int num)
{
    int ret_val = num;
    if((check_value_in_array(user_array, num)) || (check_value_in_array(cpu_array, num))){
        printf("\r\nnumber exist\r\n");
        return 0;
    } else {
        array[*array_index] = num;
        (*array_index)++;
    }
    return ret_val;
}

int check_value_in_array(int *array, int value)
{
    int i = 0, present = 0;
    for(int i = 0; i < 5; i++){
        if(value == array[i]){
            present = 1;
            break;
        }
    }
    return present;
}

int check_for_triplet(int *array)
{
    for(int i = 0; i < 3; i++){
        for(int j = i+1; j < 4; j++){
            for(int k = j+1; k < 5; k++){
                if(array[i]+array[j]+array[k] == 15){
                    if(array[i] && array[j] && array[k])
                        // printf("\r\n----you won----");
                        return 1;
                }
            }
        }
    }
    return 0;
}
int check_for_possible_triplet(int *array)
{
    int possiblity = 0;
    for(int i = 0; i < 3; i++){
        for(int j = i+1; j < 4; j++){
            possiblity = 15 - (array[i] + array[j]);
            if((!check_value_in_array(user_array, possiblity)) && \
            (!check_value_in_array(cpu_array, possiblity)) &&\
            (possiblity > 0) && (possiblity <= 9)){
                // printf("\r\n -> %d", possiblity);
                return possiblity;
            }
        }
    }
    return 0;
}
