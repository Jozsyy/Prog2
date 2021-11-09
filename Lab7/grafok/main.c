#include <stdio.h>
#include "graph.h"

int main() {
    printf("Iranyitatlan szomszedsagi matrix:\n");
    u_adjacency_matrix("input.txt");
    printf("\nIranyitott szomszedsagi matrix:\n");
    d_adjacency_matrix("input2.txt");

    printf("\nIranyitatlan szomszedsagi lista:\n");
    u_adjacency_list("input.txt");
    printf("\nIranyitott szomszedsagi lista:\n");
    d_adjacency_list("input3.txt");

    printf("\nIranyitatlan illeszkedesi matrix:\n");
    u_incidence_matrix("input.txt");

    printf("\nIranyitatlan ellista:\n");
    u_el_list("input.txt");
    return 0;
}
