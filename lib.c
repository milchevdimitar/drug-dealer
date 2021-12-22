#include "lib.h"

int fillin_prices(int prices[MAX_SIZE][MAX_SIZE]){
    
    int i, j;
    
    for(i=0; i<MAX_SIZE; i++) {
        for(j=0;j<MAX_SIZE;j++) {
            printf("Enter value for my shits[%d][%d]:", i, j);
            scanf("%d", &prices[i][j]);
        }
    }

}

int check_money(int money){
    return money;
}