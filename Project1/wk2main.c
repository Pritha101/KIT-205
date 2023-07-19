
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


/*int main() {
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
*/

int main() {
    List my_list = new_list();
    int quit = 0;
    while (!quit) {
        int option;
        printf_s("If you press 0 : Quit  press 1 : insert data press2 : delete data Press 3: print ");
        scanf_s("%d", &option);

        if (option == 1) {
            option_insert(&my_list);
        }
        if (option == 2) {
            option_delete(&my_list);
        }
        if (option == 3) {
            option_print(&my_list);
        }

    }
    destroy_list(&my_list);


    return 0;
}

