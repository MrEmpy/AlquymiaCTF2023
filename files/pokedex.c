#include <stdio.h>
#include <stdlib.h>
int main()
{
    int con;
    con = 0;
    int account_balance = 1100;
    while(con == 0){
        
        printf("Bem-vindo à loja de trocas de Pokémon\n");
        printf("Aqui trocamos Pokémons\n\n");

        printf("1. Verificar saldo de moedas\n");
        printf("2. Trocar por Pokémons\n");
        printf("3. Sair\n\n");
        
        int menu;
        
        printf("Escolha uma opção no menu: ");
        fflush(stdout);
        fflush(stdin);
        scanf("%d", &menu);
        if(menu == 1){
            printf("\n - Saldo: %d \n\n", account_balance);
        }
        else if(menu == 2){
            printf("\nAtualmente disponíveis para troca: \n\n");
            printf("1. Pikachu\n");
            printf("2. Charizard 1337\n\n");
            printf("Escolha: ");
            fflush(stdout);
            int auction_choice;
            fflush(stdin);
            scanf("%d", &auction_choice);
            if(auction_choice == 1){
                printf("\nEsse Pokémom custa 900 moedas cada, insira a quantidade desejada: ");
                fflush(stdout);
                int number_pokemons = 0;
                fflush(stdin);
                scanf("%d", &number_pokemons);
                if(number_pokemons > 0){
                    int total_cost = 0;
                    total_cost = 900*number_pokemons;
                    printf("\nO custo final é: %d\n", total_cost);
                    
                    if(total_cost <= account_balance){
                        account_balance = account_balance - total_cost;
                        printf("\nSeu saldo atual após a transação: %d\n\n", account_balance);
                    }
                    else{
                        printf("Saldo insuficiente para completar a transação\n");
                    }
                    fflush(stdout);
                }
            }
            else if(auction_choice == 2){
                printf("\nCharizard 1337 custa 100000 moedas, e só temos 1 em estoque.\n\n");
                printf("Digite 1 para comprar: ");
                int bid = 0;
                fflush(stdout);
                fflush(stdin);
                scanf("%d", &bid);
                
                if(bid == 1){
                    
                    if(account_balance > 100000){
                        FILE *f = fopen("flag.txt", "r");
                        if(f == NULL){
                            printf("Flag não encontrada, por favor execute isso no servidor.\n");
                            exit(0);
                        }
                        char buf[64];
                        fgets(buf, 63, f);
                        printf("SEU POKEMON É: %s\n", buf);
                        }
                    
                    else{
                        printf("\n - Saldo insuficiente para a transação.\n\n");
                    }}
            }
            fflush(stdout);
        }
        else{
            con = 1;
        }

    }
    fflush(stdout);
    return 0;
}
