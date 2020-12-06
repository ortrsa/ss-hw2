//
//  myBank.h
//  ss_hw2
//
//  Created by Or Trabelsi on 22/11/2020.
//

#ifndef myBank_h
#define myBank_h

#include <stdio.h>

#define N 2
#define M 50


typedef double matrix[N][M];

int NewAc(double deposit);
double Balance(int Anum);
double Deposit(int Anum, double amount);
double Draw(int Anum, double amount);
int closeAc(int Anum);
void AddRate(int rate);
void PrintAll();
int Exit();
int IsOpen(int Anum);

#endif /* myBank_h */
