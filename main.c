#include <stdio.h>
#include <stdlib.h>
#include "printgrid.h"
int main()
{
    int input = 0;
    printGrid(0);
    for(int i = 0; i < 4; i++){
        printf("\r\nenter value:");
        scanf("%d", &input);
        if(input){
            system("clear");
            printGrid(input);
        }
    }

    return 0;
}
