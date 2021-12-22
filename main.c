#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    int money;
    int prices[MAX_SIZE][MAX_SIZE];
    char best_clients[MAX_SIZE][MAX_SIZE] = {
        "Ivan, "
        "Pesho, "    
        "Miro, "
        "Kaponkata "
    };

int main(){

    int op;
    scanf("%d", &op);

    switch(op){

        case 1:
        printf("------------------------Info------------------------\n");
        printf("Money: %d\n", check_money(money));
        printf("Best clients: %s\n", best_clients);
    
        case 2:


    }

}

/*
да сравнява 2 стринга - символ по символ и дължина
минава се през имената на доверените и го сравнява с даденото име - 0,1
*/
