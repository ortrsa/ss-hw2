//
//  main.c
//  ss_hw2
//
//  Created by Or Trabelsi on 22/11/2020.
//

#include <stdio.h>
#include "myBank.h"

int main(int argc, const char * argv[]) {
    char action = ' ';
    double amount;
    int account;
    int rate;
    
   
    
  
    while (action!=-10){
        printf("\nPlease choose a transaction type:\n");
        printf("O-Open Account\nB-Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
    
        
        scanf(" %c",&action);
        while ((action != 'I') && (action != 'B') && (action != 'D') && (action != 'W')&& (action != 'C') && (action != 'O') && (action != 'P') && (action != 'E')) {
        printf("invalid transaction type\n");
               break;
        }
  
        switch (action) {
                
            case 'O':
                printf("Please enter amount for deposit: ");
               
                if( scanf(" %lf",&amount)!=1){
                    printf("Failed to read the amount\n");
                    break;
                    
                }else{
                if(amount<0){
                printf("Invalid amount\n");
                break;
                }
                int acnum =NewAc(amount);
                if(acnum==-1){
                    printf("Unable to open account!\n");
                }
                else{ printf("New account number is: %d\n",acnum);
                    
                }
                break;
                }
            case 'B':
                printf("Please enter the account number: ");
                if( scanf("%d", &account)!=1){
                    printf("failed to read the account number\n");
                    break;
                    
                }
                double balance =Balance(account);
                if(balance==-1){
                    printf("This account is closed!\n");
                }
                else printf("The balance of account %d is: %0.2lf\n",account,balance);
                break;
                
            case 'D':
                printf("Please enter account number: ");
                if( scanf("%d", &account)!=1){
                printf("Failed to read the account number\n");
                   break;
                }
                if(account>950||account<901){
                printf("Invalid account number\n");
                break;}
                if(IsOpen(account)!=1){
                printf("this account is closed\n");
                break;
                }
                printf("amount to deposit is : ");
                if(scanf("%lf", &amount)!=1){
                printf("Failed to read the amount\n");
                break;
                }
                double dep = Deposit(account, amount);
                if(dep ==-1){
                    printf("This acount is closed!\n");
                    break;
                }
                else if(dep ==-2){
                    printf("Cannot deposit negative amount!\n");
                    break;
                }
                else{
                printf("The new balance is: %0.2lf\n", dep );
                }
                break;
                
            case 'W':
                printf("Please enter account number: ");
                if( scanf("%d", &account)!=1){
                    printf("failed to read the account number\n");
                    break;
                }
                 if(account>950||account<901){
                printf("Invalid account number\n");
                break;}
                if(IsOpen(account)!=1){
                printf("this account is closed\n");
                break;
                }
                printf("Please enter the amount to withdraw: ");
                scanf("%lf", &amount);
                double draw = Draw(account, amount);
                if(draw==-1){
                    printf("It is not possible to withdraw money from this account!\n");
                }
                else if(draw==-2){
                    printf("Amount mast be bigger than 0!\n");
                }
                else if(draw==-3){
                    printf("Cannot withdraw more than the balance\n");
                }
                else{
                printf("Your new balance is: %0.2lf\n",draw);
                }
                break;
                
            case 'C':
                printf("Please enter the account number : ");
                if( scanf("%d", &account)!=1){
                    printf ("failed to read the account number\n");
                    break;
                }
                 if(account>950||account<901){
                printf("Invalid account number\n");
                break;}
                if(IsOpen(account)!=1){
                printf("this account is closed\n");
                break;
                }
                if(closeAc(account)==-1){
                    printf("This account is closed!\n");
                }
                else printf("The account was cloase successfully!\n");
                break;
                
            case 'I':
                printf("Please enter interest rate : ");
                if( scanf(" %d",&rate)!=1){
                 printf("Failed to read the interest rate\n");
                 break;
                }
           	 if(rate<0){
          	  printf("Invalid intrest rate\n");
         	   break;
         	   }
                AddRate(rate);
                printf("Rate added!\n");
                break;
                
            case 'P':
                PrintAll();
                break;
                
            case 'E':
                Exit();
                action=-10;
                break;
                
                
            default:
                
                break;
        }
    }
    
    return 0;
}
