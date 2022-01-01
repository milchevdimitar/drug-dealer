/*
ДАДЕНО:
 ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––--
|-1- | Да се реализира програма пресъздаваща живота на един дилър (продавач).                                    |check
|––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––--|
|-2- | Всеки дилър има шеф.                                                                                      |check
|––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––--|
|-3- | Всеки дилър може да провери колко пари има натрупани.                                                     |check
|––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––--|
|-4- | Всеки дилър има списък с редовни клиенти.                                                                 |check
|––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––--|
|-5- | Всеки дилър има инвентар и може да проверява всеки продукт, който продава, каква е неговата наличност.    |check
|––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––--|
|-6- | Всеки продукт има стандартна цена и цена за "приятели".                                                   |check
|––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––--|
|-7- | Всеки дилър има шанс да бъде обран и да изгуби натрупаният оборот.                                        |check
|––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––--|
|-8- | Да се създадат структури, които да отговарят на нуждата на програмата                                     |check
|––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––--|
|-9- | Да се реализират функции позволяващи гореописаните неща                                                   |check
|--––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––|
|-10-| Всяка от функциите да бъде използвана така че да се пресъздаде живота на един дилър                       |check
 ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––--
*/

#include "lib.h"//custom библиотеката
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_dealer(struct dealer* dealer) {

    printf("What's your name\n$ ");
    fgets(dealer->name, MAX_SIZE, stdin);

    dealer->name[strlen(dealer->name) - 1] = 0;

    int maxClients = 0, maxProducts;

    do {

        printf("Clients count\n$ ");
        scanf("%d", &maxClients);

    } while (maxClients < 1 || maxClients > MAX_SIZE);
    
    fgetc(stdin);

    do {

        printf("Products count\n$ ");
        scanf("%d", &maxProducts);

    } while (maxProducts < 1 || maxProducts > MAX_SIZE);
    
    fgetc(stdin);

    for (int i = 0; i < maxClients; i++) {

        printf("What's your trusted client %d's name\n$ ", i + 1);
        fgets(dealer->best_clients[i], MAX_SIZE, stdin);
        dealer->best_clients[i][strlen(dealer->best_clients[i]) - 1] = 0;

    }

    for (int i = 0; i < maxProducts; i++) {
        
        printf("Input of product %d\nName: ", i + 1);
        fgets(dealer->items[i].name, MAX_SIZE, stdin);
        dealer->items[i].name[strlen(dealer->items[i].name) - 1] = 0;

        if (dealer->items[i].name[0] != 0) {

            printf("Price: ");
            scanf("%f", &dealer->items[i].n_price);

            printf("Friends price: ");
            scanf("%f", &dealer->items[i].f_price);
            fgetc(stdin);

            dealer->items[i].amount = 0;

        }

    }

    for (int i = maxClients; i < MAX_SIZE; i++) {

        dealer->best_clients[i][0] = 0;

    }

    for (int i = maxProducts; i < MAX_SIZE; i++) {

        dealer->items[i].name[0] = 0;

    }


    dealer->money = 0;

}

void print_info(struct dealer *dealer) {

    printf("Name: %s\nMoney: %.2f\nProducts:\n", dealer->name, dealer->money);

    for (int i = 0; i < MAX_SIZE; i++) {

        if (!dealer->items[i].name[i]) break;

        printf("%d. %s (%f amount)\n", i + 1, dealer->items[i].name, dealer->items[i].amount);

    }

}

void buy(struct dealer *dealer) {

    char name[MAX_SIZE];
    char product[MAX_SIZE];
    float amount;
    int i = 0;

    printf("Name of client\n$ ");
    fgets(name, MAX_SIZE, stdin);
    name[strlen(name) - 1] = 0;
    
    printf("Drug to sell\n$ ");
    fgets(product, MAX_SIZE, stdin);
    product[strlen(product) - 1] = 0;

    printf("Amount\n$ ");
    scanf("%f", &amount);
    fgetc(stdin);

    dealer_buy(dealer, name, product, amount);

}

int main(){

    struct dealer dealer;
    int looping = 1;

    input_dealer(&dealer);

    while (looping) {
        printf("-------------------------------\n");
        printf("Select action:\n");
        printf("1 - Show info\n");
        printf("2 - Sell item\n");
        printf("3 - I've been robbed\n");
        printf("4 - Restock\n");
        printf("Any - Exit\n");
        printf("-------------------------------\n");
        printf("$ ");
    
        int op = getchar();
        getchar();

        switch (op) {
            
            case '1':
                printf("-------------------------------\n");
                print_info(&dealer);
                break;
            
            case '2':
                printf("-------------------------------\n");
                buy(&dealer);
                break;
            
            case '3':
                printf("-------------------------------\n");
                dealer_is_now_poor(&dealer);
                break;
                
            case '4':
                printf("-------------------------------\n");
                dealer_restock(&dealer);
                break;
            
            default:
                looping = 1;
                break;

        }

    }

}