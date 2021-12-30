#include "lib.h"

int strequ(char a[], char b[]) {

    while (*a == *b) {

        if (!*a) return 1;
        *a++;
        *b++;

    }

return 0;
}

void dealer_buy(struct dealer* dealer, struct person* person, char product[], float amount){

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
        
        if (strequ(person->name, dealer->best_clients[i])){

            price = item->f_price;
            break;
        
        }
    
    }

    price *= amount;

    if (person->money < price) {

        printf("U r poor silly XDXDXD\n");
        return;

    }

    if (item->amount < amount) {

        printf("I don't have so much drugs 4 u buddy\n");
        return;

    }

    person->money -= price;
    item->amount -= amount;

    printf("Succesful purchase ;)\n");
    printf("-------------------------------\n");
    printf("Remaining amount for sale:%.f\n", item->amount);
    printf("Remaining money:%.f\n", person->money);   

}

void dealer_is_now_poor(struct dealer* dealer) {

    if (!(rand()%10)) {
        
        for (int i = 0; i < MAX_SIZE; i++) {

            dealer->items[i].amount = 0;
        
        }

        printf("U were robbed, so go f*ck urself\n");

    }

}



