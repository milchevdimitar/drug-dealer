//include
#include <stdio.h>

//define 
#define RESTOCK_AMOUNT 10
#define BOSS_CUT 30 //percent
#define FRIENDS_DISCOUNT 20 //percent
#define RESTOCK_DISCOUNT 35 //percent

#define VODKA_PRICE 50
#define JACK_PRICE 70
#define DUREX_PRICE 5
#define WEED_PRICE 120

//struct
struct dealer {

    int money;
    
};

struct vodka_s_uteha {
    
    int price;
    
    int restock_price;
    
    int amount;
    
};

struct uncle_jack {

    int price;

    int restock_price;

    int amount;

};

struct weed {

    int price;

    int restock_price;

    int amount;

};

struct condoms {

    int price;

    int restock_price;

    int amount;

};

struct dealer d;

struct vodka_s_uteha vodka;

struct uncle_jack jack;

struct condoms durex;

struct weed weed;

//rob
int u_were_robbed ( int *item_amount ) {

    *item_amount = 0;

}
//free restock
int free_restock ( int *item_amount ) {

    printf ( "Last amount  %d\n", *item_amount );                

    *item_amount += RESTOCK_AMOUNT ; 

    printf ( "Now u have %d\n", *item_amount );                

}

//restock
int restock ( int *money, int *item_amount, int *item_restock_price ) {

    int final_price = 0;

    printf ( "Last amount  %d\n", *item_amount );                

    final_price = RESTOCK_AMOUNT * *item_restock_price;

    if ( final_price <= *money) {

        *item_amount += RESTOCK_AMOUNT ; 

        printf ( "Now u have %d\n", *item_amount );                

    }

    else {

        printf( "I don't have so much money :(\n");

    }
 
}

//sell
int sell ( int *money, int *item_amount, int *item_price ) {

    int i_amount = 0;
    int final_price = 0;

    printf ( "How much of this shit do u want:\n" );
    scanf ( "%d", &i_amount );
    
    if ( *item_amount >= i_amount ) {
    
        final_price = i_amount * *item_price;
        *item_amount -= i_amount;

    }
    
    *money += final_price;

    printf ( "Now I have %d$ and %d from this shit\n", *money, *item_amount );

}
//sell for friends
int sell_for_friends ( int *money, int *item_amount, int *item_price ) {

    int i_amount = 0;
    int final_price = 0;

    printf ( "How much of this shit do u want:\n" );
    scanf ( "%d", &i_amount );
    
    if ( *item_amount >= i_amount ) {
    
        final_price = i_amount * *item_price;
        *item_amount -= i_amount;

    }
    
    *money += final_price;
    
    printf ( "For everyone the price is %d\n", final_price );
    
    final_price -= ( final_price * FRIENDS_DISCOUNT ) / 100;
    
    int discount = FRIENDS_DISCOUNT;

    printf ( "But for you the price is %d ( -%d% )\n", final_price, discount );
    
    printf ( "Now I have %d$ and %d from this shit\n", *money, *item_amount );

}
//your boss is taking big part of your profit
int low_profit ( int *money ) {

    *money -= ( *money * BOSS_CUT ) /100;

    int boss_cut = BOSS_CUT;

    printf ( "Boss: I took my part of your profit ( -%d% )\n", boss_cut );

}

//print inventory for normal sale 
void print_inventory_sell ( int *vodka_price, int *jack_price, int *durex_price, int *weed_price, int *vodka_amount, int *jack_amount, int *durex_amount, int *weed_amount ) {

    printf ( "_____________________________________________________\n" );

    printf ( "1) - Vodka ( %d$ ) I have %d\n", *vodka_price, *vodka_amount );
    
    printf ( "2) - Jack ( %d$ ) I have %d\n", *jack_price, *jack_amount );
    
    printf ( "3) - Durex ( %d$ ) I have %d \n", *durex_price, *durex_price );
    
    printf ( "4) - Weed ( %d$ ) I have %d\n", *weed_price, *weed_amount );

    printf ( "5) - I don't more shit\n" );

    printf ( "_____________________________________________________\n" );

}

//print invetory for friends sale
void print_inventory_sell_friends ( int *vodka_price, int *jack_price, int *durex_price, int *weed_price, int *vodka_amount, int *jack_amount, int *durex_amount, int *weed_amount ) {

    *vodka_price -= ( *vodka_price * FRIENDS_DISCOUNT ) / 100;

    *jack_price -= ( *jack_price * FRIENDS_DISCOUNT ) / 100;

    *durex_price -= ( *durex_price * FRIENDS_DISCOUNT ) / 100;

    *weed_price -= ( *weed_price * FRIENDS_DISCOUNT ) / 100;

    printf ( "_____________________________________________________\n" );

    printf ( "1) - Vodka ( %d$ ) I have %d\n", *vodka_price, *vodka_amount );
    
    printf ( "2) - Jack ( %d$ ) I have %d\n", *jack_price, *jack_amount );
    
    printf ( "3) - Durex ( %d$ ) I have %d \n", *durex_price, *durex_price );
    
    printf ( "4) - Weed ( %d$ ) I have %d\n", *weed_price, *weed_amount );

    printf ( "5) - I don't more shit\n" );

    printf ( "_____________________________________________________\n" );

}

//print invetory for resrock
void print_inventory_restock ( int *vodka_price, int *jack_price, int *durex_price, int *weed_price, int *vodka_amount, int *jack_amount, int *durex_amount, int *weed_amount ) {

    printf ( "_____________________________________________________\n" );

    printf ( "1) - Vodka ( %d$ ) I have %d\n", *vodka_price, *vodka_amount );
    
    printf ( "2) - Jack ( %d$ ) I have %d\n", *jack_price, *jack_amount );
    
    printf ( "3) - Durex ( %d$ ) I have %d \n", *durex_price, *durex_amount );
    
    printf ( "4) - Weed ( %d$ ) I have %d\n", *weed_price, *weed_amount );

    printf ( "5) - I don't more shit\n" );

    printf ( "_____________________________________________________\n" );

}

//print main menu
void print_main_menu () {

    printf ( "_____________________________________________________\n" );

    printf ( "1) - Restock\n" );
    
    printf ( "2) - U were robbed\n" );
    
    printf ( "3) - Sell\n" );

    printf ( "4) - Free restock\n" );

    printf ( "5) - Sell for friends\n" );

    printf ( "6) - Boss cut\n" );

    printf ( "7) - About me, my money and my boss\n" );

    printf ( "8) - Info about my stock\n" );

    printf ( "Any key - Exit\n");

    printf ( "_____________________________________________________\n" );

}

//money check
int money_check ( int *money ) {

    if ( *money == 0) {

        printf ( "Balance: You have nothing in common with money XDXD\n" );

    }

    else {

        printf ( "Balance: %d\n", *money);

    }

}
//print story
void story () {

    printf("I'm from Sofia, also I'm live saver, cuz i sell \ncondoms, vodka, jack and weed - the most needed thigs \nfor a men after breakup\n");

}


//main
int main () {

    char name[] = {"Malkata granadka"};
    char boss_name[] = {"BOMBATA"};

    vodka.price = VODKA_PRICE;
    vodka.restock_price = VODKA_PRICE - ( VODKA_PRICE * RESTOCK_DISCOUNT ) /100;
    vodka.amount = 0;

    jack.price = JACK_PRICE;
    jack.restock_price = JACK_PRICE - ( JACK_PRICE * RESTOCK_DISCOUNT ) /100;
    jack.amount = 0;

    durex.price = DUREX_PRICE;
    durex.restock_price = DUREX_PRICE - ( DUREX_PRICE * RESTOCK_DISCOUNT ) /100;
    durex.amount = 0;

    weed.price = WEED_PRICE;
    weed.restock_price = WEED_PRICE - ( WEED_PRICE * RESTOCK_DISCOUNT ) /100;
    weed.amount = 0; 

    int looping_main = 1;

    int op_sec = 0;
    int looping_sec = 1;


    while ( looping_main ) {
        
        print_main_menu ();
        int op = 0;
        printf("Option:\n");
        scanf("%d", &op);

        switch ( op ) {

            case 1:
                
                while ( looping_sec ) {
                    
                    print_inventory_restock ( &vodka.restock_price, &jack.restock_price, &durex.restock_price, &weed.restock_price, &vodka.amount, &jack.amount, &durex.amount, &weed.amount );
                    printf ("What do u want 2 restock ?\n");                 
                    scanf("%d", &op_sec);

                    switch ( op_sec ) {

                        case 1: 
                        
                            restock ( &d.money, &vodka.amount, &vodka.restock_price );
                            break;

                        case 2:

                            restock ( &d.money, &jack.amount, &jack.restock_price );
                            break;

                        case 3:

                            restock ( &d.money, &durex.amount, &durex.restock_price );
                            break;

                        case 4:

                            restock ( &d.money, &weed.amount, &weed.restock_price );
                            break;
                        
                        default: looping_sec = 0;
                    }

                }

                looping_sec = 1;             
                break;

            case 2:
                
                printf ( "U were robbed silly\n" );

                u_were_robbed ( &vodka.amount );
                u_were_robbed ( &jack.amount );
                u_were_robbed ( &durex.amount );
                u_were_robbed ( &weed.amount );
            
                break;
            
            case 3:

                while ( looping_sec ) {

                    print_inventory_sell ( &vodka.price, &jack.price, &durex.price, &weed.price, &vodka.amount, &jack.amount, &durex.amount, &weed.amount );
                    printf ("What do u want 2 sell ?\n");                 
                    scanf("%d", &op_sec);

                    switch ( op_sec ) { 
                    
                        case 1:
                
                            sell ( &d.money, &vodka.amount, &vodka.price ); 
                            break;

                        case 2:    
                
                            sell ( &d.money, &jack.amount, &jack.price );
                            break;
                    
                        case 3:
                
                            sell ( &d.money, &durex.amount, &durex.price );
                            break;
                    
                        case 4:
                
                            sell ( &d.money, &weed.amount, &weed.price );
                            break;

                        default: looping_sec = 0;

                    }

                }
                
                looping_sec = 1;
                break;
        
            case 4:
                    
                while ( looping_sec ) {
                    
                    print_inventory_restock ( &vodka.restock_price, &jack.restock_price, &durex.restock_price, &weed.restock_price, &vodka.amount, &jack.amount, &durex.amount, &weed.amount );
                    printf ("What do u want 2 restock ?\n");                 
                    scanf("%d", &op_sec);

                    switch ( op_sec ) {

                        case 1: 
                        
                            free_restock ( &vodka.amount );
                            break;

                        case 2:

                            free_restock ( &jack.amount );
                            break;

                        case 3:

                            free_restock ( &durex.amount );
                            break;

                        case 4:

                            free_restock ( &weed.amount );
                            break;
                        
                        default: looping_sec = 0;

                    }
            
                }

                looping_sec = 1;
                break;

            case 5:
                
                while ( looping_sec ) {

                    print_inventory_sell_friends ( &vodka.price, &jack.price, &durex.price, &weed.price, &vodka.amount, &jack.amount, &durex.amount, &weed.amount );
                    printf ("What do u want 2 sell ?\n");                 
                    scanf("%d", &op_sec);

                    switch ( op_sec ) { 
                    
                        case 1:
                
                            sell_for_friends ( &d.money, &vodka.amount, &vodka.price ); 
                            break;

                        case 2:    
                
                            sell_for_friends ( &d.money, &jack.amount, &jack.price );
                            break;
                    
                        case 3:
                
                            sell_for_friends ( &d.money, &durex.amount, &durex.price );
                            break;
                    
                        case 4:
                
                            sell_for_friends ( &d.money, &weed.amount, &weed.price );
                            break;

                        default: looping_sec = 0;

                    }

                }

                break;

            case 6:

                low_profit ( &d.money );

                break;

            case 7: 

                printf ( "My name is %s\n", name );

                printf ( "My boss's name is %s\n", boss_name );

                story ();

                money_check ( &d.money ) ;
                
                break;
            
            case 8:

                print_inventory_sell ( &vodka.price, &jack.price, &durex.price, &weed.price, &vodka.amount, &jack.amount, &durex.amount, &weed.amount );

                break;

            default: looping_main = 0;

        }


    }

return 0;

}