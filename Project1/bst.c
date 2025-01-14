#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

// create an empty bst
BST new_bst() {
	BST temp;
	temp.root = NULL;
	return temp;
}

// recursive function to find a value and return the containing node
BSTNodePtr find_bst_node(BSTNodePtr self, int n) {
	if (self == NULL || (n == self->data_item)) { /* not present, or here */
		return self;
	}
	else if (n < self->data_item) {
		return find_bst_node(self->left, n);
	}
	else {
		return find_bst_node(self->right, n);
	}
}

// find a value in the tree and return the node
BSTNodePtr find_bst(BST* self, int n) {
	return find_bst_node(self->root, n);
}

// recursive function to insert a value
BSTNodePtr insert_bst_node(BSTNodePtr self, int n) {
	if (self == NULL) { /* found where to put it*/
		self = malloc(sizeof * self);
		self->data_item = n;
		self->left = self->right = NULL;
	}
	else if (n < self->data_item) {
		self->left = insert_bst_node(self->left, n);
	}
	else if (n > self->data_item) {
		self->right = insert_bst_node(self->right, n);
	}
	return self;
}

// insert a value into the tree
void insert_bst(BST* self, int n) {
	self->root = insert_bst_node(self->root, n);
}

// helper function for delete
BSTNodePtr min_node(BSTNodePtr self) {
	BSTNodePtr current = self;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

// recursive function to delete a value
BSTNodePtr delete_bst_node(BSTNodePtr self, int n) {
	if (self != NULL) {
		if (n == self->data_item) { // found item 
			if (self->left != NULL && self->right != NULL) {
				// two child case 
				BSTNodePtr successor = min_node(self->right);
				self->data_item = successor->data_item;
				self->right = delete_bst_node(self->right, self->data_item);
			}
			else { // one or zero child case 
				BSTNodePtr to_free = self;
				if (self->left) {
					self = self->left;
				}
				else {
					self = self->right;
				}
				free(to_free);
			}
		}
		else if (n < self->data_item) {
			self->left = delete_bst_node(self->left, n);
		}
		else {
			self->right = delete_bst_node(self->right, n);
		}
	}
	return self;
}


// delete a value from the tree
void delete_bst(BST* self, int n) {
	self->root = delete_bst_node(self->root, n);
}

// recursive function to print in order
void print_in_order_bst_node(BSTNodePtr self) {
	if (self == NULL) {
		printf_s("_");
	}
	else {
		printf_s("(");
		print_in_order_bst_node(self->left);
		printf_s(" %d ", self->data_item);
		print_in_order_bst_node(self->right);
		printf_s(")");
	}
}

// print the tree in order
void print_in_order_bst(BST* self) {
	print_in_order_bst_node(self->root);
}


void print_pre_order_bst_recursive(BSTNodePtr node) {
	if (node != NULL) {
		printf("%d ", node->data_item);
		print_pre_order_bst_recursive(node->left);
		print_pre_order_bst_recursive(node->right);
	}
}

void print_pre_order_bst(BST* self) {
	print_pre_order_bst_recursive(self->root);
}

void print_post_order_bst_recursive(BSTNodePtr node) {
	if (node != NULL) {
		print_post_order_bst_recursive(node->left);
		print_post_order_bst_recursive(node->right);
		printf("%d ", node->data_item);
	}
}

void print_post_order_bst(BST* self) {
	print_post_order_bst_recursive(self->root);
}


int height_bst_node(BSTNodePtr node) {
	if (node == NULL) {
		return -1; // Empty tree has height -1
	}
	else {
		int left_height = height_bst_node(node->left);
		int right_height = height_bst_node(node->right);
		return 1 + max(left_height, right_height);
	}
}

int height_bst(BST* self) {
	return height_bst_node(self->root);
}



// recursive function to detroy all node
void destroy_bst_node(BSTNodePtr self) {
	if (self != NULL) {
		destroy_bst_node(self->left);
		self->left = NULL;
		destroy_bst_node(self->right);
		self->right = NULL;
		free(self);
	}
}

// destroy the tree
void destroy_bst(BST* self) {
	destroy_bst_node(self->root);
	self->root = NULL;
}

void bst_test() {
	BST tree = new_bst();
	int quit = 0;
	int data;
	while (quit == 0) {
		printf_s("Enter some data: ");
		scanf_s("%d", &data);

		if (data != 0) {
			insert_bst(&tree, data);
		}
		else {
			quit = 1;
		}
	}
	printf_s("In-Order:");
	print_in_order_bst(&tree);
	printf_s("\n");


	printf_s("Pre-Order:");
	print_pre_order_bst(&tree);
	printf_s("\n");


	printf_s("Post-Order:");
	print_post_order_bst(&tree);
	printf_s("\n");

	int tree_height = height_bst(&tree);
	printf("Height of the tree: %d\n", tree_height);
}

