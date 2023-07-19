//first testing part
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main() {
    List list = new_list();

    insert_at_front(&list, 1);
    insert_at_front(&list, 2);
    print_list(&list);
}
