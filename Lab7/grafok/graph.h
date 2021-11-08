//
// Created by Jozsi on 11/3/2021.
//

#ifndef GRAFOK_GRAPH_H
#define GRAFOK_GRAPH_H
#include <stdlib.h>
#include <stdio.h>

///Iranyitatlan szomszedsagi matrix
void u_adjacency_matrix(const char*);  //u=undirected
///Iranyitott szomszedsagi matrix (sulyozott)
void d_adjacency_matrix(const char*);  //d=directed


typedef struct {
    int data;
    struct Node* next;
} Node;

Node* createNode();
void insert(Node** front, char *nev, int data);
void print_list(Node *myNode);

void adjacency_list(Node* , const char*);

#endif //GRAFOK_GRAPH_H
