#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define STR_LEN 50

typedef struct reasonList
{
	char** proReasons;
	char** conReasons;
	int proNumReasons;
	int conNumReasons;
} reasonList;

void myFgets(char str[], int n);

void printMenu(reasonList* list);
void addProReason(reasonList* list);
void addConReason(reasonList* list);
void printReasons(reasonList* list);

int main(void)
{
	reasonList list = {0, 0, 0, 0};
	char dillema[STR_LEN] = { 0 };
	printf("What is your dillema?\n");
	myFgets(dillema, STR_LEN);
	list.proReasons = (char**)malloc(sizeof(char*));
	if (!list.proReasons)
	{
		printf("Unsuccessful malloc!");
		return 1;
	}
	list.conReasons = (char**)malloc(sizeof(char*));
	if (!list.conReasons)
	{
		printf("Unsuccessful malloc!");
		return 1;
	}
	printMenu(&list);
	free(list.proReasons);
	free(list.conReasons);
	return 0;
}


void myFgets(char str[], int n)
{
	fgets(str, n, stdin);
	str[strcspn(str, "\n")] = 0;
}


void printMenu(reasonList* list)
{
	int option = 0;
	printf("Choose Option:\n");
	printf("1 - Add PRO reason\n");
	printf("2 - Add CON reason\n");
	printf("3 - Print reasons\n");
	printf("4 - Exit\n");
	scanf("%d", &option);
	getchar();
	while (option < 0 || option > 4)
	{
		printf("Invalid option, enter a number between 1-4: ");
		scanf("%d", &option);
		getchar();
	}
	switch (option)
	{
		case 1:
			addProReason(list);
			break;
		case 2:
			addConReason(list);
			break;
		case 3:
			printReasons(list);
			break;
		case 4:
			break;
		default:
			break;
	}
}

void addProReason(reasonList* list)
{
	list->proNumReasons += 1;
	list->proReasons = (char**)realloc(list->proReasons, list->proNumReasons * sizeof(char*));
	list->proReasons[list->proNumReasons - 1] = (char*)malloc(STR_LEN * sizeof(char));
	printf("Enter a reason to add to list PRO:\n");
	myFgets(list->proReasons[list->proNumReasons - 1], STR_LEN);
	printMenu(list);
}

void addConReason(reasonList* list)
{
	list->conNumReasons += 1;
	list->conReasons = (char**)realloc(list->conReasons, list->conNumReasons * sizeof(char*));
	list->conReasons[list->conNumReasons - 1] = (char*)malloc(STR_LEN * sizeof(char));
	printf("Enter a reason to add to list CON:\n");
	myFgets(list->conReasons[list->conNumReasons - 1], STR_LEN);
	printMenu(list);
}

void printReasons(reasonList* list)
{
	int i = 0;
	printf("List PRO\n");
	printf("---------\n");
	for (i = 0; i < list->proNumReasons; i++)
	{
		printf("%s\n", list->proReasons[i]);
	}
	printf("\n");
	printf("List CON\n");
	printf("---------\n");
	for (i = 0; i < list->conNumReasons; i++)
	{
		printf("%s\n", list->proReasons[i]);
	}
	printf("\n");
	printMenu(list);
}