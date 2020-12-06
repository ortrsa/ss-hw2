//
//  myBank.c
//  ss_hw2
//
//  Created by Or Trabelsi on 22/11/2020.
//

#include "myBank.h"
matrix mat;

int NewAc(double deposit){
    int j = 1;
    
    while (mat[0][j]!=0) {
        j++;
        if(j>50)return -1;
    }
    mat[0][j]=1;
    mat[1][j]=deposit;
    
    return 900+j;
}

double Balance(int Anum){
    if(Anum<901||Anum>950){return -1;}
    int AccountNum = Anum-900;
    if(mat[0][AccountNum]==0)return -1;
    return mat[1][AccountNum];
}

double Deposit(int Anum, double amount){
    if(Anum<901||Anum>950){return -1;}
    if(amount<0)return -2;
    int AccountNum = Anum-900;
    if(mat[0][AccountNum]==0)return -1;
    mat[1][AccountNum]= mat[1][AccountNum] + amount;
    return mat[1][AccountNum];
}

double Draw(int Anum, double amount){
    if(Anum<901||Anum>950){return -1;}
  //  if(amount<0)return -2;
    int AccountNum = Anum-900;
    if(mat[0][AccountNum]==0 || mat[1][AccountNum]<amount)return -3;
    mat[1][AccountNum] = mat[1][AccountNum] - amount;
    return mat[1][AccountNum];
}

int closeAc(int Anum){
    if(Anum<901||Anum>950){return -1;}
    int AccountNum = Anum-900;
    if(mat[0][AccountNum]==0)return -1;
    mat[0][AccountNum]=0;
    mat[1][AccountNum]=0;
    return 1;
}

void AddRate(int rate){
    int j=1;
    if(rate<0)return;
    while(j<=50){
        if(mat[0][j]==1){
            mat[1][j]=mat[1][j]*(1+rate/100);
            
        }
        j++;
        }
}

void PrintAll(){
   // int isEmpty = 1;
    int i = 1;
    while (i<=50) {
        if(mat[0][i]==1){
            printf("The balance in account %d is %0.2lf \n", 900+i, mat[1][i]);
            //isEmpty=0;
        }
        i++;
    }
   // if(isEmpty) printf("No open accounts\n ");
}
int IsOpen(int Anum){
 if(mat[0][Anum-900]!=1)return 0;
 return 1;
 }

int Exit(){
    int i=1;
    while (i<=50) {
        mat[0][i]=0;
        mat[1][i]=0;
        i++;
    }
    printf("All accounts have been closed !\n");
    return -10;
}

