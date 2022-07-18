#include "printgrid.h"

int grid[9] = {6, 7, 2, 1, 5, 9, 8, 3, 4};

void printGrid(int index){
    for(int i = 0; i < 9; i++){
        if(index == grid[i]){
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
