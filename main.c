//Да се реализира програма пресъздаваща живота на един дилър (продавач).
//Всеки дилър има шеф. Всеки дилър може да провери колко пари има натрупани. Всеки дилър има списък с редовни клиенти. Всеки дилър има инвентар и може да проверява всеки продукт, който продава, каква е неговата наличност. Всеки продукт има стандартна цена и цена за "приятели". Всеки дилър има шанс да бъде обран и да изгуби натрупаният оборот.
//Да се създадат структури, които да отговарят на нуждата на програмата
//Да се реализират функции позволяващи гореописаните неща
//Всяка от функциите да бъде използвана така че да се пресъздаде живота на един дилър

#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dealer dealer = {

    0,
    
    {
    
        "Kaloyan Venkov",
        "Slavi Trifonov",
        "Petq Ivanova", //Preslava
        "Boris Soltariiski",
        "Cvetelina Grahich",
    
    },
    
        {
        
        (struct item) {
        
        "Weed",
        20,
        15,
        10,

        },

        (struct item) {
            
        "Heroin",
        50,
        42,
        10,

        },

        (struct item) {
            
        "Drug",
        120,
        99,
        10,

        },

    }

};

struct person person = {
    
    1000,
    "Customer",
    
};

int main(){

    printf("Available drugs:\n");
    printf("Weed\n");
    printf("Drug\n");
    printf("Heroin\n");

    printf("-------------------------------\n");

    char type_drug[MAX_SIZE];
    printf("Drugs type:");
    fgets(type_drug, 49, stdin);
    type_drug[strlen(type_drug)-1] = 0;

    float amount;
    printf("Amount: ");
    scanf("%f", &amount);
    
    printf("-------------------------------\n");

    dealer_buy(&dealer, &person, type_drug , amount);
    dealer_is_now_poor(&dealer);

}