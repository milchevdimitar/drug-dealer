//Lib for my custom drug dealer
//Copyright Dimitar Milchev

//include
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE (20)

struct item {

    char name [MAX_SIZE];
    //n_prices (normal_prices)
    float n_price;
    //f_prices (friend_prices)
    float f_price; 
    float amount;

};

struct dealer {

    char name[MAX_SIZE];
    float money;
    char best_clients[MAX_SIZE][MAX_SIZE];
    struct item items[MAX_SIZE];

};

int strequ(char a[], char b[]);
void dealer_buy(struct dealer* dealer, char name[], char product[], float amount);
void dealer_is_now_poor(struct dealer* dealer);
void dealer_restock(struct dealer* dealer);