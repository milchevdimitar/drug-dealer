#include "lib.h"

int strequ(char a[], char b[]) {

    while (*a == *b) {

        if (!*a) return 1;
        *a++;
        *b++;

    }

return 0;
}

void dealer_buy(struct dealer* dealer, char name[], char product[], float amount){

    struct item *item = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        
        if (strequ(product, dealer->items[i].name)){

            item = &dealer->items[i];
            break;
        
        }

    }    

    if (!item) {

        printf("I don't have %s. Srry. \n", product);
        return; 

    }

    float price = item->n_price;

    for (int i = 0; i < MAX_SIZE; i++) {
        
        if (strequ(name, dealer->best_clients[i])){

            price = item->f_price;
            break;
        
        }
    
    }

    price *= amount;

    if (item->amount < amount) {

        printf("I don't have so much drugs 4 u buddy\n");
        return;

    }

    item->amount -= amount;
    dealer->money += price;

    printf("Succesful purchase ;)\n");
    printf("-------------------------------\n");
    printf("Remaining amount for sale: %.2f\n", item->amount);
    printf("New balance: %.2f\n", dealer->money);

}

void dealer_is_now_poor(struct dealer* dealer) {

    for (int i = 0; i < MAX_SIZE; i++) {

        dealer->items[i].amount = 0;

    }

    dealer->money = 0;

}

void dealer_restock(struct dealer* dealer) {

    int selected;
    float amount;

    printf("Select item to restock\n");

    for (int i = 0 ; i < MAX_SIZE; i++) {

        if (dealer->items[i].name[0] == 0) break;

        printf("%d - %s\n", i + 1, dealer->items[i].name, dealer->items[i].amount);

    }

    do {

        printf("$ ");
        scanf("%d", &selected);
        getchar();

    } while (selected < 1 || selected > MAX_SIZE);

    printf("How much to restock\n$ ");
    scanf("%f", &amount);
    getchar();

    dealer->items[--selected].amount += amount;

    printf("Restocked %s, now %f\n", dealer->items[selected].name, dealer->items[selected].amount);

}