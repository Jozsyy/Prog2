//
// Created by Jozsi on 10/27/2021.
//

#ifndef TESZT_FUNCTIONS_H
#define TESZT_FUNCTIONS_H
#include <stdlib.h>
#include <stdio.h>

///1. feladat
void read_rec(FILE *, int *, int , int );
int sum_pair(int *, int, int);
int sum_impair(int *, int, int);

///2.feladat
int int_cmp(const void *, const void *);
int binary_search(int *, int , int , int );
int maxindex(int *,int ,int);
int power(int, int );
#endif //TESZT_FUNCTIONS_H
