#include <stdio.h>
#include <stdlib.h>
#include "printgrid.h"
int main()
{
    int input = 0, array[9] = {0}, array_index = 0;
    printGrid(array, 0);
    for(int i = 0; i < 9; i++){
        printf("\r\nenter value:");
        scanf("%d", &input);
        if(input){
            system("clear");
            printGrid(array, input);
            update_array(array, &array_index, input);
        }
    }
    return 0;
}
