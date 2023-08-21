// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // includes malloc(),free()
#include <string.h> // includes strlen(), memcpy()
#include <ctype.h>	// includes toupper(), tolower()

// user-defined header files
#include "node.h" // do not modify this file

// put your function prototypes for additional helper functions below:

// implementation
void insert_node_before(list *lst, int index, char *word)
{
    node *new_node = malloc(sizeof(node));
    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->word = word;

    if (lst->head == NULL)
    {
        lst->head = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
        return;
    }
    node *temp = lst->head;
    if(index > 0){
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
    }
    else if(index < 0){
        for (int i = index; i < 0; i++)
        {
            temp = temp->prev;
        }
    }
    new_node->next = temp;
    new_node->prev = temp->prev;
    temp->prev->next = new_node;
    temp->prev = new_node;
}

void insert_node_after(list *lst, int index, char *word)
{
	node *new_node = malloc(sizeof(node));
    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->word = word;
	if (lst->head == NULL)
	{
		lst->head = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
        return;
	}
	node *temp = lst->head;
    if(index > 0){
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
    }
	else if(index < 0){
        for (int i = index; i < 0; i++)
        {
            temp = temp->prev;
        }
    }
    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next->prev = new_node;
    temp->next = new_node;
}

char *list_to_sentence(list *lst)
{
	// TODO
	char *sentence = malloc(sizeof(char) * 100);
	node *temp = lst->head;
	int i = 0;
	while (temp != NULL)
	{
		for (int j = 0; j < (int)strlen(temp->word); j++)
		{
			sentence += temp->word[j];
		}
		sentence[i] = ' ';
		i++;
		temp = temp->next;
	}
	return sentence;
}

void delete_node(list *lst, int index)
{
    if(lst->head == NULL){
        printf("noting to delete !");
        return;
    }
    if(index == 0){
        node* temp = lst->head;
        lst->head = lst->head->next;
        lst->head->prev = lst->head->prev->prev;
        lst->head->prev->next = lst->head;
        free(temp);
        return;
    }
	node *temp = lst->head;
    if(index > 0){
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
    }else if (index < 0){
        for (int i = index; i < 0; ++i) {
            temp = temp->prev;
        }
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void delete_list(list *lst)
{
	// TODO
	node *temp = lst->head;
	while (temp != NULL)
	{
		node *temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
}

// TODO
