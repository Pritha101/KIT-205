#include <stdio.h>
#include <stdlib.h>
#include "list.h"


// Function to create and return a new empty list.
List new_list() {
	List temp;
	temp.head = NULL;
	return temp;
}

// Function to print the contents of a list.
void print_list(List* self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		printf("%d", current->data);
		current = current->next;

		if (current != NULL)
			printf(", ");
	}
	printf("\n");
}

// Function to insert a new node with given data at the front of the list.
void insert_at_front(List* self, int data) {
	ListNodePtr new_node = malloc(sizeof * new_node);

	new_node->data = data;
	new_node->next = self->head;
	self->head = new_node;
}

// Function to insert a new node with given data in the list in ascending order.
void insert_in_order(List* self, int data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	ListNodePtr new_node = malloc(sizeof * new_node);
	new_node->data = data;
	new_node->next = NULL;

	while (current != NULL && current->data < data) {
		prev = current;
		current = current->next;
	}

	if (current == self->head) { // at front
		new_node->next = current;
		self->head = new_node;
	}
	else {                     // middle
		new_node->next = current;
		prev->next = new_node;
	}
}

// Function to delete the first occurrence of a node with given data from the list.
void delete_list(List* self, int data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	while (current != NULL) {
		if (current->data == data) {
			if (prev == NULL) {        // front of list
				self->head = current->next;
				free(current);
				current = self->head;
			}
			else {                    // middle of list
				prev->next = current->next;
				free(current);
				current = prev->next;
			}
		}
		else {
			prev = current;
			current = current->next;
		}
	}
}

// Function to free the memory allocated to a list and all its nodes.
void destroy_list(List* self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		ListNodePtr to_free = current;
		current = current->next;
		free(to_free);
	}
	self->head = NULL;
}


// Function to reverse the given list and return a new list
List reverse(List* self) {
	List reversed_list;
	reversed_list.head = NULL;

	ListNodePtr current = self->head;

	while (current != NULL) {
		// Create a new node for the reversed list
		ListNodePtr new_node = malloc(sizeof(*new_node));
		new_node->data = current->data;
		new_node->next = NULL;

		// Insert the new node at the front of the reversed list
		if (reversed_list.head == NULL) {
			reversed_list.head = new_node;
		}
		else {
			new_node->next = reversed_list.head;
			reversed_list.head = new_node;
		}

		current = current->next;
	}

	return reversed_list;
}



// Function to merge two ordered lists into a new ordered list
List merge(List* list1, List* list2) {
	List merged_list;
	merged_list.head = NULL;

	ListNodePtr current1 = list1->head;
	ListNodePtr current2 = list2->head;

	while (current1 != NULL && current2 != NULL) {
		if (current1->data < current2->data) {
			// Insert the current node from list1 into the merged_list in order
			insert_in_order(&merged_list, current1->data);
			current1 = current1->next;
		}
		else {
			// Insert the current node from list2 into the merged_list in order
			insert_in_order(&merged_list, current2->data);
			current2 = current2->next;
		}
	}

	// Append the remaining nodes from list1, if any
	while (current1 != NULL) {
		insert_in_order(&merged_list, current1->data);
		current1 = current1->next;
	}

	// Append the remaining nodes from list2, if any
	while (current2 != NULL) {
		insert_in_order(&merged_list, current2->data);
		current2 = current2->next;
	}

	return merged_list;
}
