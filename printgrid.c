#include "printgrid.h"

int grid[9] = {6, 7, 2, 1, 5, 9, 8, 3, 4};

void printGrid(int *array, int grid_index){
    for(int i = 0; i < 9; i++){
        if((grid_index == grid[i]) || (check_array(array, grid[i]))){
            printf (" x ");
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
}

void update_array(int *array, int *array_index, int num)
{
    if(check_array(array, num)){
        printf("\r\nnumber exist\r\n");
    } else {
        array[*array_index] = num;
        (*array_index)++;
    }
    printf("\r\n");
    for(int i = 0; i < *array_index; i++){
        printf("%d ", array[i]);
    }
    if(check_for_triplet(array)){
        exit(0);
    }
}

int check_array(int *array, int value)
{
    int i = 0, present = 0;
    for(int i = 0; i < 9; i++){
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
                    printf("\r\n----you won----");
                    return 1;
                }
            }
        }
    }
    return 0;
}
