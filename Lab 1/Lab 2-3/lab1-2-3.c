// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // stdlib includes malloc() and free()
#include <string.h>
// user-defined header files
//#include "chain.h"
#include "chain.c"

// function prototypes
void print_chain(chain * chn); 
void run(chain * chn);


int main()
{
    chain * chn = (chain *) malloc(sizeof(chain));
    chn->head = NULL;
	run(chn);
    print_chain(chn);
    free(chn);
	return 0;
}

// parse the input
void run(chain *chn) 
{
    node * temp = malloc(sizeof(node));
    int numOfRows;
    scanf("%d", &numOfRows); // Read the number of rows in the initial matrix
    getchar();
    char inputRow[20];
    int firstRow[20];
    fgets(inputRow, sizeof(inputRow), stdin);

    if (inputRow[strlen(inputRow) - 1] == '\n')   inputRow[strlen(inputRow) - 1] = '\0';

    int numOfColumns = 0;
    char *token = strtok(inputRow, " "); // Split input into tokens using space as delimiter
    while (token != NULL) {
        firstRow[numOfColumns] = atoi(token); // Convert token to integer and store in array
        numOfColumns++;
        token = strtok(NULL, " "); // Get the next token
    }


    matrix *baseMatrix = create_matrix(numOfRows, numOfColumns);

    for (int j = 0; j < numOfColumns; ++j)  baseMatrix->data[0][j] = firstRow[j];


    for (int i = 1; i < numOfRows; ++i) for (int j = 0; j < numOfColumns; ++j)  scanf("%d", &baseMatrix->data[i][j]);


    int index = 0;
    insert_node_after(chn, 0, baseMatrix);
    temp = chn->head;
    int opSelect;

    while(1){
        int opearand;
        scanf("%d", &opSelect);
        if (!opSelect) break;
        switch (opSelect)
        {
            case 2:
                insert_node_after(chn, index, temp->mat);
                temp = temp->next;
                int *newRow = (int *)malloc(temp->mat->num_cols * sizeof(int));
                for (int i = 0; i < temp->mat->num_cols; ++i)   scanf("%d", &newRow[i]);
                add_row(temp->mat, newRow); // Add the new row to the matrix
                break;
            case 3:
                insert_node_after(chn, index, temp->mat);
                temp = temp->next;
                int *newColumn = (int *)malloc(temp->mat->num_rows * sizeof(int));
                for (int i = 0; i < temp->mat->num_rows; ++i)   scanf("%d", &newColumn[i]);
                add_col(temp->mat, newColumn); // Add the new column to the matrix
                break;
            case 4:
                insert_node_after(chn, index, temp->mat);
                temp = temp->next;
                scanf("%d", &opearand);
                increment(temp->mat, opearand); // Add the number to each element of the matrix
                break;
            case 5:
                insert_node_after(chn, index, temp->mat);
                temp = temp->next;
                scanf("%d", &opearand);
                scalar_multiply(temp->mat, opearand); // Multiply the number to each element of the matrix
                break;
            case 6:
                insert_node_after(chn, index, temp->mat);
                temp = temp->next;
                scanf("%d", &opearand);
                scalar_divide(temp->mat, opearand); // Divide the number to each element of the matrix
                break;
            case 7:
                insert_node_after(chn, index, temp->mat);
                temp = temp->next;
                scanf("%d", &opearand);
                scalar_power(temp->mat, opearand); // Raise each element of the matrix to the power of the number
                break;
            case 8:
                delete_matrix(temp->mat); // Delete the matrix
            default:
                break;
        }
        index++;
    }
	
}

//Print the chain
void print_chain(chain * chn)
{
    node * tempNode = chn->head;
    while (tempNode != NULL) {
        print_matrix(tempNode->mat);
        tempNode = tempNode->next;
        printf("\n");
    }
}

