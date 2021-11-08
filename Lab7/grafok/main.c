#include <stdio.h>
#include "graph.h"

int main() {
    u_adjacency_matrix("input.txt");
    printf("\n");
    d_adjacency_matrix("input2.txt");
    return 0;
}
