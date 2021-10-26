//
// Created by Jozsi on 10/13/2021.
//

#ifndef REKURZIO_FUNCTIONS_H
#define REKURZIO_FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
///Iterativ
//n elemű számsorozat beolvasása iteratívan
void read(FILE *f, int *a, int n);
//n elemű számsorozat kiírása iteratívan
void print(FILE *f, int *a, int n);

//n elemű számsorozat elemeinek összege iteratívan
int sum(int *a,int n);

//n elemű számsorozatban előfordul-e a nulla iteratívan
int is_in_array(int *a,int n);

///Rekurziv
//n elemű számsorozat beolvasása rekurzívan
void read_rec(FILE *f, int *a, int n, int i);
//n elemű számsorozat kiírása rekurzívan
void print_rec(FILE *f, int *a, int n, int i);

//n elemű számsorozat elemeinek összege rekurzívan
int sum_rec(int *a,int n,int i);

//n elemű számsorozatban előfordul-e a nulla rekurzívan
int is_in_array_rec(int *a,int n, int i);

//szám számjegyeinek a kiírása
void print_digit_number(int n);
//szám számjegyeinek a száma
int number_digit_number(int n);
//szám páros számjegyeinek a kitörlése
int delete_digit_number(int n);
//szám páros számjegyei után a 9-es számjegy beszúrása
int insert_digit_number(int n);

int power(int, int);
int power2(int, int);

///labor5
int *maxkereses(int *a, int n);
int max_kereses(int *a, int n);
int binariskereses(int *a, int ah, int fh, int szam);
bool letezik_e(int *a, int n, int szam);
int hatvanyozas_1(int b, int exp);
int hatvanyozas_2(int b, int exp);
int lnko(int a, int b);
#endif //REKURZIO_FUNCTIONS_H
