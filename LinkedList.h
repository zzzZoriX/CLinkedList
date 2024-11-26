#pragma once
#include <stdlib.h>

struct LinkedList{

	int val;
	struct LinkedList* next_cell_addr;

};

struct LinkedList* CreateList(int val) {

	struct LinkedList* newList = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	if(newList == NULL){

		perror("Memory alocate error: ");

		exit(1);
	}

	newList->val = val;
	newList->next_cell_addr = NULL;

	return newList;
}

void Display(struct LinkedList* list) {

	struct LinkedList* current = list;
	int i = 0;

	while (current != NULL) {

		printf("index %d: %d\n", i, current->val);
		current = current->next_cell_addr;
		++i;
	}
}

void DisplayOnlyThis(struct LinkedList* list){

	printf("index 0: %d\n", list->val);
}

int GetItemCount(struct LinkedList* list){

	struct LinkedList* current = list;
	int itemCount = 1;

	while(current->next_cell_addr != NULL){

		current = current->next_cell_addr;
		++itemCount;
	}

	return itemCount;
}

int GetValue(struct LinkedList* list, int index){

	struct LinkedList* current = list;
	int value = 0;
	int i = 0;

	while(current->next_cell_addr != NULL && i != index - 1){

		current = current->next_cell_addr;
		++i;
	}

	value = current->val;
	return value;
}

struct LinkedList* GetCellAtValue(struct LinkedList* list, int value){

	struct LinkedList* current = list;

	while(current->next_cell_addr != NULL){

		if(current->val = value) return current;

		current = current->next_cell_addr;
	}

	return NULL;
}

struct LinkedList* GetCellAtIndex(struct LinkedList* list, int index){

	struct LinkedList* current = list;
	int i = 0;

	while(current->next_cell_addr != NULL && i != index - 1) current = current->next_cell_addr;

	if(current->next_cell_addr == NULL) return NULL;
	return current;
}

void AddAtBeggin(struct LinkedList** list, int val) {

	struct LinkedList* newList = CreateList(val);
	
	newList->next_cell_addr = *list;
	*list = newList;
}

void Append(struct LinkedList** list, int val){

	struct LinkedList* newCell = CreateList(val);
	struct LinkedList* current = *list;

	while(current->next_cell_addr != NULL) current = current->next_cell_addr;

	current->next_cell_addr = newCell;
}

void Insert(struct LinkedList** list, int val, int index){

	if(index < 0) index = 0;
	if(index == 0){ AddAtBeggin(list, val); return; }

	int i = 0;
	struct LinkedList* newCell = CreateList(val);
	struct LinkedList* current = *list;
	struct LinkedList* tp;

	while(current->next_cell_addr != NULL && i < index - 1){

		current = current->next_cell_addr;
		++i;
	}

	tp = current->next_cell_addr;
	current->next_cell_addr = newCell;
	newCell->next_cell_addr = tp;
}

void DeleteFirst(struct LinkedList** list){

	struct LinkedList* delete = *list;
	*list = (*list)->next_cell_addr;

	free(delete);
}

void DeleteLast(struct LinkedList** list){

	struct LinkedList* current = *list;

	while(current->next_cell_addr->next_cell_addr != NULL) current = current->next_cell_addr;

	struct LinkedList* last = current->next_cell_addr;

	current->next_cell_addr = NULL;
	free(last);
}

void Delete(struct LinkedList** list, int index){

	if(index <= 1){ DeleteFirst(list); return; }

	int i = 0;
	struct LinkedList* current = *list;
	struct LinkedList* delete;

	while(current->next_cell_addr != NULL && i < index - 2){

		current = current->next_cell_addr;
		++i;
	}

	if(current->next_cell_addr == NULL){ DeleteLast(list); return; }
	
	delete = current->next_cell_addr;
	current->next_cell_addr = current->next_cell_addr->next_cell_addr;

	free(delete);
}

void Remove(struct LinkedList** list, int value){

	int index = 1;
	struct LinkedList* current = *list;

	while(current->next_cell_addr != NULL && current->val != value){

		current = current->next_cell_addr;
		++index;
	}
	
	if(current->next_cell_addr == NULL) return;
	else Delete(list, index);
}

void DeleteList(struct LinkedList** list){

	struct LinkedList* current = *list;
	struct LinkedList* delete;

	while(current->next_cell_addr != NULL){

		delete = current;
		current = current->next_cell_addr;

		free(delete);
	}

	free(current);
}