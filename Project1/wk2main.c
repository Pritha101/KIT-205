
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main() {
   //List list = new_list();

    //insert_at_front(&list, 1);
    //insert_at_front(&list, 2);
    //print_list(&list); // this is the first testing part.

    List list = new_list();
    int i = -1;
   

    while (i != 0) {
        scanf_s("%d", &i);
        insert_at_front(&list, i);
        
    }

    print_list(&list);

    destroy_list(&list);

    return 0;
}

/*int main() {
    List my_list = new_list();
    int quit


    return 0;
}*/

