#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _patient {
	char* name;
	struct _patient* nextPtr;
}patient;

void enqueue(patient** hPtr, patient** tPtr, char* name) {
	patient* newPtr = malloc(sizeof(patient));
	newPtr->name = malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(newPtr->name, name);
	if(*hPtr == NULL) {
		newPtr->nextPtr = *hPtr;
		*hPtr = newPtr;
		*tPtr = newPtr;
	}
	else {
		(*tPtr)->nextPtr = newPtr;
		newPtr->nextPtr = NULL;
		*tPtr = newPtr;
	}
}

void pop(patient** hPtr) {
	patient* tempPtr = *hPtr;
	*hPtr = (*hPtr)->nextPtr;
	free(tempPtr->name);
	free(tempPtr);
}

void initialize(char** remain, int dim) {
	for(int i = 0; i < dim; i ++) {
		remain[i] = NULL;
	}
}

void insert(patient* hPtr, char** remain) {
	int i=0;
	patient* currPtr = hPtr;
	while(currPtr != NULL) {
		remain[i] = currPtr->name;
		currPtr = currPtr->nextPtr;
		i++;
	}
}

void print(char** remain, int dim) {
	for(int i = 0; i < dim; i ++) {
		printf("%s\n", remain[i]);
	}
	printf("$\n");
}

int compare(const void *a, const void *b) {
	return strcmp(*(char**)a,*(char**)b);
}

void freeList(patient* hPtr) {
	while(hPtr != NULL) {
		patient* tempPtr = hPtr;
		hPtr = hPtr->nextPtr;
		free(tempPtr->name);
		free(tempPtr);
	}
}

int main() {
	patient *hPtr = NULL, *tPtr = NULL;
	int e;
	char name[100];
	int patients = 0;
	scanf("%d", &e);
	while(e != 0) {
		if(e == 1) {
			scanf("%s", name);
			patients ++;
			enqueue(&hPtr, &tPtr, name);	
		}
		else if (e == 2) {
			pop(&hPtr);
			patients --;
		}
		scanf("%d", &e);
	}
	char** remain = malloc(sizeof(char*) * patients);
	initialize(remain, patients);
	insert(hPtr, remain);
	qsort(remain, patients, sizeof(char*), compare);
	print(remain, patients);
	freeList(hPtr);
	free(remain);
	return 0;
}
