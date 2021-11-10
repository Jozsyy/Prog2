#include "graph.h"

int main() {
    init(&n,&m);
    bool_matrix(m);
    print_bool(adj_m,n);
    print_dad(n);
    print_color(n);
    melysegi_bejaras();
    print_dad(n);
    print_color(n);

    return 0;
}
