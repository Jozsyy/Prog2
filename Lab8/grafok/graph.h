//
// Created by Jozsi on 11/10/2021.
//

#ifndef GRAFOK_GRAPH_H
#define GRAFOK_GRAPH_H
#include <stdio.h>
#include <stdlib.h>

int n,m,*dad,**adj_m,*color;
void init(int *, int *);
void bool_matrix( int );
void print_bool(int**, int);
void print_dad(int);
void print_color(int);
void melysegi_menet(int);
void melysegi_bejaras();

#endif //GRAFOK_GRAPH_H
