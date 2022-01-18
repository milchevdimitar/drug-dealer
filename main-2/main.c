#include <stdio.h>

#define PRODUCTS_COUNT 4
#define PRODUCTS_NAME_LENGHT 10

#define BOSS_CUT 30;
#define RESTOCK_DISCOUNT 25
#define FRIEND_DISCOUNT 18
#define POCKET_SIZE 10

char product_names [PRODUCTS_COUNT][PRODUCTS_NAME_LENGHT] = {
    "Weed",
    "Vodka",
    "Durex",
    "Jack"
};

int product_price [PRODUCTS_COUNT] = {
    120,
    50,
    5,
    70
};

int product_amount [PRODUCTS_COUNT] = {
    0,
    0,
    0,
    0
};

struct dealer {

    int money;
    int profit;

} about_dealer;

void print_invetory ( int *money ) {

    for (int i = 0; i < PRODUCTS_COUNT; ++i ) {
        printf( "%d) Item name: %s Price: %d $ In stock:%d \n",i+1 , product_names[i], product_price[i], product_amount[i] );
    }

    printf ( "My money: %d $\n", *money );
}

void print_main_menu () {

    printf ( "1) - Restock\n" );
    printf ( "2) - List products\n" );
    printf ( "3) - Sell\n");
    printf ( "4) - Sell for friends\n" );
    printf ( "5) - Be robbed\n");
    printf ( "Any - Exit\n");

}

int restock_price_calc ( int i ) {

    int restock_discount = product_price [i];
    restock_discount -= ( product_price [i] * RESTOCK_DISCOUNT ) / 100;
    return restock_discount;

}

int friend_price_calc ( int i ) {

    int friend_discount = product_price [i];
    friend_discount -= ( product_price [i] * FRIEND_DISCOUNT ) / 100;
    return friend_discount;

}

int restock ( int *money ) {

    for (int i = 0; i < PRODUCTS_COUNT; ++i) {
    
        int needed_amount = POCKET_SIZE - product_amount [i]; 
        product_amount [i] = POCKET_SIZE;
        int restock_discount = restock_price_calc ( i );
        int final_price = needed_amount * product_price [i];        
        final_price -= restock_discount;
        *money -= final_price;

    }

}

int sell () {

    int op = 0;
    int amount = 0;
    
    print_invetory ( &about_dealer.money ); 
    
    printf ( "What do u want to buy:" );
    scanf ( "%d", &op );
    op--;

    printf ( "How much do u want:" );
    scanf ( "%d", &amount );

    if ( amount <= product_amount[op] ){

        product_amount[op] -= amount;

        int final_price = 0;
        final_price = amount * product_price [op];

        printf ( "Succesfull purchase\n" );

    }
    else {

        printf ( "I don't have so much\n" );

    }

}

int sell_for_friends () {

    int op = 0;
    int amount = 0;
    
    print_invetory ( &about_dealer.money ); 
    
    printf ( "What do u want to buy:" );
    scanf ( "%d", &op );
    op--;

    printf ( "How much do u want:" );
    scanf ( "%d", &amount );

    if ( amount <= product_amount[op] ){

        product_amount[op] -= amount;
        int final_price = 0;
        int friend_discount = friend_price_calc ( op );
        final_price = amount * product_price [op];
        final_price -= friend_discount;
        printf ( "Succesfull purchase\n" );

    }
    else {

        printf ( "I don't have so much\n" );

    }

}

int rob ( int *money ) {

    for (int i = 0; i < PRODUCTS_COUNT; ++i) {
    
        *money = 0;
        product_amount [i] = 0; 

    }

}

int boss_cut () {}

int main () {

    int looping_main = 1;
    int op = 0;

    while ( looping_main ) {

        print_main_menu ();
        printf ( "Option:" );
        scanf ( "%d", &op );

        switch (op) {
        
        case 1:
            restock ( &about_dealer.money );
            break;

        case 2:
            print_invetory ( &about_dealer.money );
            break;

        case 3:
            sell ();
            break;
        
        case 4:
            sell_for_friends ();
            break;

        case 5:
            rob ( &about_dealer.money );
            break;

        default: 
            looping_main = 0;
            break;

        }

    }

}