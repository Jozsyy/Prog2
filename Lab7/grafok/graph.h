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

///Iranyitatlan szomszedsagi lista
void u_adjacency_list(const char*);
///Iranyitott szomszedsagi lista
void d_adjacency_list(const char*);

///Illeszkedesi matrix
void u_incidence_matrix(const char*);

///Ellista
void u_el_list(const char*);

#endif //GRAFOK_GRAPH_H
