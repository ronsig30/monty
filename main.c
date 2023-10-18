#include "monty.h"
stack_t *head = NULL;

/**
 * main - Entry point of the Monty program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: Always returns 0.
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    open_file(argv[1]);
    free_nodes();
    return (0);
}

/**
 * create_node - Creates a new stack node.
 * @n: Integer value to be stored in the node.
 * Return: A pointer to the newly created node, or NULL on failure.
 */
stack_t *create_node(int n)
{
    stack_t *node;

    node = malloc(sizeof(stack_t));
    if (node == NULL)
        err(4);
    node->next = NULL;
    node->prev = NULL;
    node->n = n;
    return (node);
}

/**
 * free_nodes - Frees memory associated with the stack nodes.
 */
void free_nodes(void)
{
    stack_t *tmp;

    if (head == NULL)
        return;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: Line number of the opcode.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
    stack_t *tmp;

    if (new_node == NULL || *new_node == NULL)
        exit(EXIT_FAILURE);
    if (head == NULL)
    {
        head = *new_node;
        return;
    }
    tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = *new_node;
    (*new_node)->prev = tmp;
}
