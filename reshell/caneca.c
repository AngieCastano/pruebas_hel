#include "shell.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list.
 * @head: double pointer to the head of the list
 * @mugre: number to add
 * Return: the address of the new element, or NULL if it failed
 */
caneca *add_nodeint_end(caneca **head, char *mugre, char **mugre2)
{
	caneca *new_end_list;
	caneca *temp = *head;

	new_end_list = malloc(sizeof(caneca));
	if (!new_end_list)
		return (NULL);
	new_end_list->mugre = mugre;
	new_end_list->mugre2 = mugre2;
	new_end_list->next = NULL;
	if (!*head)
	{
		*head = new_end_list;
	}
	else
	{
		while (temp && temp->next)
		{
			temp = temp->next;
		}
		temp->next = new_end_list;
	}
	return (*head);
}

/**
 * print_listint - prints all the elements of a listint_t list.
 * @h: head of the list
 * Return: the number of nodes.
 */
void print_listint(caneca *h)
{
	int num_of_nodes = 0;

	while (h)
	{
		printf("%p\n", h->mugre);
		h = h->next;
		num_of_nodes++;
	}
	printf("el numero de nodos es: %i\n", num_of_nodes);
}
/**
 * free_list -function that frees a list_t list.
 * @head: head of the list
 */
void free_list(caneca *head, int retorno)
{
	caneca *copy_head;

	while (head)
	{
		copy_head = head->next;
		free(head->mugre);
		free(head->mugre2);
		free(head);
		head = copy_head;
	}
	if (retorno == 1)
		return;
	if (retorno == 2)
		exit(0);
}
