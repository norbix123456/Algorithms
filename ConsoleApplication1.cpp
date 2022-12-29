#include <iostream>
struct lista {
	lista* next;
	lista* prev;
	int id;
	int r;
};
void swap(int* a, int* b)
{
	int t = *a; *a = *b; *b = t;
}
lista* lastNode(lista* root)
{
	while (root && root->next)
		root = root->next;
	return root;
}
lista* partition(lista* l, lista* h)
{
	int x = h->r;
	lista* i = l->prev;
	for (lista* j = l; j != h; j = j->next)
	{
		if (j->r <= x)
		{
			i = (i == NULL) ? l : i->next;
			swap(&(i->r), &(j->r));
			swap(&(i->id), &(j->id));
		}
	}
	i = (i == NULL) ? l : i->next;
	swap(&(i->r), &(h->r));
	swap(&(i->id), &(h->id));
	return i;
}
void _quickSort(lista* l, lista* h)
{
	if (h != NULL && l != h && l != h->next)
	{
		lista* p = partition(l, h);
		_quickSort(l, p->prev);
		_quickSort(p->next, h);
	}
}
void quickSort(lista* head)
{
	lista* h = lastNode(head);
	_quickSort(head, h);
}
void push(lista** head_ref, int new_data, int iden)
{
	lista* new_node = new lista;
	new_node->r = new_data;
	new_node->id = iden;
	new_node->prev = NULL;
	new_node->next = (*head_ref);
	if ((*head_ref) != NULL) (*head_ref)->prev = new_node;
	(*head_ref) = new_node;
}
void goback(lista** head)
{
	while (*head && (*head)->next)
	{
		*head = (*head)->next;
	}
}
int main()
{
	int n, p, r, id;
	scanf_s("%i", &n);
	scanf_s("%i", &p);
	lista* head;
	lista* head2;
	lista* head3;
	head = (lista*)malloc(sizeof(lista));
	head = NULL;
	head2 = (lista*)malloc(sizeof(lista));
	head2 = NULL;
	head3 = (lista*)malloc(sizeof(lista));
	head3 = NULL;
	int x = 0, y = 0, licz = 0;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%i", &id);
		scanf_s("%i", &r);
		push(&head, r, id);
	}
	quickSort(head);
	while (head)
	{
		x = x + head->r;
		if (x <= p)
		{
			push(&head2, head->id, head->r);
			licz++;
			head = head->next;
		}
		else
		{
			break;
		}
	}
	while (head)
	{
		y = y + head->r;
		if (y <= p)
		{
			push(&head3, head->id, head->r);
			licz++;
			head = head->next;
		}
		else
		{
			break;
		}
	}
	x = 0;
	y = 0;
	quickSort(head2);
	quickSort(head3);
	goback(&head2);
	goback(&head3);
	printf("%i\n", licz);
	printf("1: ");
	while (head2)
	{
		printf("%i ", head2->r);
		head2 = head2->prev;
	}
	printf("\n2: ");
	while (head3)
	{
		printf("%i ", head3->r);
		head3 = head3->prev;
	}
}

