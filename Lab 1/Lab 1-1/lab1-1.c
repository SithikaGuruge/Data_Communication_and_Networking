// general purpose standard C lib



// user-defined header files // // #include "node.h"
#include "node.h"

// macros

#define INSERT_BEFORE 1
#define INSERT_AFTER 2
#define DELETE_NODE 3
#define DELETE_LIST 4

// function prototypes
void print_list(list *lst);
void run(list *lst);

int main()
{
    list *lst = (list *)malloc(sizeof(list));
    lst->head = NULL;
    run(lst);
    print_list(lst);
    free(lst);
    return 0;
}

// parse the input
void run(list *lst) {
    char* input = (char*)malloc(1024*sizeof(char));
    printf("Enter a comma seperated word: ");
    scanf("%s", input);

    int i = -1;
    char *token = strtok(input, ",");
    while (token != NULL) {
        insert_node_after(lst, i++, token);
        token = strtok(NULL, ",");
    }

    int op = 1;
    while (true) {
        printf("Enter a space seperated values: ");
        scanf("%d", &op);
        int index;
        if(op == 0){
            break;
        }
        else if (op == 1) {
            char *word = (char*) malloc(MAX_WORD_LENGTH*sizeof(char));
            scanf("%d", &index);
            scanf("%s", word);
            insert_node_before(lst, index, word);
        } else if (op == 2) {
            char *word = (char*) malloc(MAX_WORD_LENGTH*sizeof(char));
            scanf("%d", &index);
            scanf("%s", word);
            insert_node_after(lst, index, word);

        } else if (op == 3) {

            scanf("%d", &index);
            delete_node(lst, index);
        } else if (op == 4) {
            delete_list(lst);
        }
    }
}

void print_list(list *lst)
{
    node *curr = lst->head;
    while (true)
    {
        printf("%s ", curr->word);
        curr = curr->next;
        if(lst->head == curr){
            break;
        }
    }
    printf("\n");
}
