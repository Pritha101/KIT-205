
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

void option_insert(List* self) {
    int data;
    printf_s("Write data to insert: ");
    scanf_s("%d", &data);
    insert_at_front(self, data);
}

void option_delete(List* self) {
    int data;
    printf_s("Write data to delete: ");
    scanf_s("%d", &data);
    delete_list(self, data);
}

void option_print(List* self){
    print_list(self);
}

int main() {
    List my_list = new_list();
    int quit = 0;
    while (!quit) {
        int option;
        printf_s("Options:\n");
        printf_s("1. Insert\n");
        printf_s("2. Delete\n");
        printf_s("3. Print\n");
        printf_s("0. Exit\n");
        printf_s("Enter option: ");
        scanf_s("%d", &option);

        switch (option) {
        case 1:
            option_insert(&my_list);
            break;
        case 2:
            option_delete(&my_list);
            break;
        case 3:
            option_print(&my_list);
            break;
        case 0:
            printf_s("Exiting...\n");
            break;
        default:
            printf_s("Invalid option. Try again.\n");
        }

    }
    destroy_list(&my_list);


    return 0;
}

