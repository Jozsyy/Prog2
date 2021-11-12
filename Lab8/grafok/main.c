#include "graph.h"

int main() {
    init(&n,&m);
    bool_matrix(m);
    print_bool(adj_m,n);
    melysegi_bejaras();
    printf("\nApa tomb:\n");
    print_array(dad,n);
    printf("\nSzin tomb:\n");
    print_array(color,n);
    return 0;
}
