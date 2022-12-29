
#include <iostream>
#include <string>
#include <sstream>
struct Node
{
	int numb;
	Node* npx;
};
Node* XOR(Node* a, Node* b)
{
	return (struct Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}
void actual(Node* act)
{
	if (act)
	{
		printf("%i\n", act->numb);
	}
	else
	{
		printf("NULL\n");
	}
}
void prev(Node** act, Node** actnext, Node** actprev, Node** end, Node** head)
{
	if (*act)
	{
		if (*actnext == NULL && *actprev == NULL)
		{
			printf("%i\n", (*act)->numb);
		}
		else
		{
			if (*actprev == NULL)
			{
				*actnext = *act;
				*act = *end;
				*actprev = XOR((*end)->npx, NULL);
				printf("%i\n", (*act)->numb);
			}
			else
			{
				if (*head == *actprev)
				{
					*actnext = *act;
					*act = *actprev;
					*actprev = *end;
				}
				else if (*head == *act)
				{
					*actnext = *act;
					*act = *actprev;
					*actprev = XOR((*actprev)->npx, NULL);
				}
				else
				{
					*actnext = *act;
					*act = *actprev;
					*actprev = XOR((*actprev)->npx, *actnext);
				}
				printf("%i\n", (*act)->numb);
			}
		}
	}
	else
	{
		printf("NULL\n");
	}
}
void next(Node** act, Node** actnext, Node** actprev, Node** head, Node** end)
{
	if (*act)
	{
		if (*actnext == NULL && *actprev == NULL)
		{
			printf("%i\n", (*act)->numb);
		}
		else
		{
			if (*actnext == NULL)
			{
				*actprev = *act;
				*act = *head;
				*actnext = XOR((*head)->npx, NULL);
				printf("%i\n", (*act)->numb);
			}
			else
			{
				if (*end == *actnext)
				{
					*actprev = *act;
					*act = *actnext;
					*actnext = *head;
				}
				else if (*end == *act)
				{
					*actprev = *act;
					*act = *actnext;
					*actnext = XOR((*actnext)->npx, NULL);
				}
				else
				{
					*actprev = *act;
					*act = *actnext;
					*actnext = XOR((*actnext)->npx, *actprev);
				}

				printf("%i\n", (*act)->numb);
			}
		}
	}
	else
	{
		printf("NULL\n");
	}
}
void add_act(int numb, Node** act, Node** actprev, Node** head)
{
	Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->numb = numb;


	if (*act == *head)
	{
		*head = new_node;
		(*act)->npx = XOR(new_node, (*act)->npx);
		new_node->npx = *act;
		*actprev = new_node;
	}
	else
	{
		(*act)->npx = XOR(new_node, XOR((*act)->npx, *actprev));
		new_node->npx = XOR(*actprev, *act);
		(*actprev)->npx = XOR(new_node, XOR((*actprev)->npx, *act));
		*actprev = new_node;
	}
}
void add_beg(Node** head, int numb, Node** end, Node** act, Node** actprev, Node** actnext)
{
	Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->numb = numb;
	new_node->npx = *head;
	if (*head != NULL)
	{
		(*head)->npx = XOR(new_node, (*head)->npx);
		if (*head == *act)
		{
			*actprev = new_node;
		}
		if (actnext == NULL)
		{
			*actnext = new_node;
		}
	}
	else
	{
		*end = new_node;
		*act = new_node;
	}
	*head = new_node;
}
void add_end(Node** head, int numb, Node** end, Node** act, Node** actnext, Node** actprev)
{
	Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->numb = numb;
	new_node->npx = *end;
	if (*end != NULL)
	{
		(*end)->npx = XOR(new_node, (*end)->npx);
		if (*end == *act)
		{
			*actnext = new_node;
		}
		if (*actprev == NULL)
		{
			*actprev = new_node;
		}
	}
	else
	{
		*head = new_node;
		*act = new_node;
	}

	*end = new_node;
}
void del_end(Node** head, Node** end, Node** act, Node** actnext, Node** actprev)
{
	Node* curr = NULL;
	curr = *end;
	if (curr == NULL)
	{
		return;
	}
	else
	{
		if (curr == *act)
		{
			if (*actprev == NULL)
			{
				free(curr);
				*head = NULL;
				*end = NULL;
				*act = NULL;
			}
			else if (XOR((*actprev)->npx, *act) == NULL)
			{
				free(curr);
				*end = *actprev;
				(*end)->npx = NULL;
				*act = *actprev;
				*actprev = NULL;
				*actnext = NULL;
			}
			else
			{
				(*actprev)->npx = XOR((*actprev)->npx, *act);
				free(curr);
				*end = *actprev;
				*act = *actprev;
				*actprev = XOR((*actprev)->npx, NULL);
				*actnext = *head;
			}
		}
		else if (curr == *actprev)
		{
			if (*actprev == *actnext)
			{
				free(curr);
				*end = *act;
				(*end)->npx = NULL;
				*actprev = NULL;
				*actnext = NULL;
			}
			else
			{
				XOR((*actprev)->npx, NULL)->npx = XOR(*actprev, (*actprev)->npx);
				*end = (*actprev)->npx;
				*actprev = (*actprev)->npx;
				free(curr);
			}
		}
		else if (curr == *actnext)
		{
			if (*actprev == *actnext)
			{
				free(curr);
				*end = *act;
				(*end)->npx = NULL;
				*actprev = NULL;
				*actnext = NULL;
			}
			else
			{
				free(curr);
				*end = *act;
				(*act)->npx = *actprev;
				*actnext = *head;
			}
		}
		else
		{
			(*end)->npx->npx = XOR(*end, (*end)->npx->npx);
			*end = (*end)->npx;
			free(curr);
		}
	}
}
void del_beg(Node** head, Node** end, Node** act, Node** actnext, Node** actprev)
{
	Node* curr = NULL;
	curr = *head;
	if (curr == NULL)
	{
		return;
	}
	else
	{
		if (curr == *act)
		{
			if (*actnext == NULL)
			{
				free(curr);
				*head = NULL;
				*end = NULL;
				*act = NULL;
			}
			else if (XOR((*actnext)->npx, *act) == NULL)
			{
				free(curr);
				*head = *actnext;
				(*head)->npx = NULL;
				*act = *actnext;
				*actnext = NULL;
				*actprev = NULL;
			}
			else
			{
				(*actnext)->npx = XOR((*actnext)->npx, *act);
				free(curr);
				*head = *actnext;
				*act = *end;
				*actprev = (*end)->npx;
			}
		}
		else if (curr == *actnext)
		{
			if (*actnext == *actprev)
			{
				free(curr);
				*head = *act;
				(*head)->npx = NULL;
				*actnext = NULL;
				*actprev = NULL;
			}
			else
			{
				XOR((*actnext)->npx, NULL)->npx = XOR(*actnext, (*actnext)->npx);
				*head = (*actnext)->npx;
				*actnext = (*actnext)->npx;
				free(curr);
			}
		}
		else if (curr == *actprev)
		{
			if (*actnext == *actprev)
			{
				free(curr);
				*head = *act;
				(*head)->npx = NULL;
				*actnext = NULL;
				*actprev = NULL;
			}
			else
			{
				free(curr);
				*head = *act;
				(*act)->npx = *actnext;
				*actprev = *end;
			}
		}
		else
		{
			(*head)->npx->npx = XOR(*head, (*head)->npx->npx);
			*head = (*head)->npx;
			free(curr);
		}
	}
}
void del_act(Node** head, Node** end, Node** act, Node** actnext, Node** actprev)
{
	Node* curr = NULL;
	curr = *act;
	if (curr == NULL)
	{
		return;
	}
	else
	{
		if (*head == *act)
		{
			if (*end == *act)
			{
				free(curr);
				*head = NULL;
				*end = NULL;
				*act = NULL;
			}
			else if (*actnext == *end)
			{
				free(curr);
				*act = *actnext;
				(*act)->npx = NULL;
				*end = *actnext;
				*actnext = NULL;
				*actprev = NULL;
			}
			else
			{
				(*actnext)->npx = XOR((*actnext)->npx, *act);
				free(curr);
				*head = *actnext;
				*act = *end;
				*actprev = (*end)->npx;
			}
		}
		else if (*end == *act)
		{
			if (*head == *act)
			{
				free(curr);
				*head = NULL;
				*end = NULL;
				*act = NULL;
			}
			else if (*actprev == *head)
			{
				free(curr);
				*end = *actprev;
				(*end)->npx = NULL;
				*act = *actprev;
				*actprev = NULL;
				*actnext = NULL;
			}
			else
			{
				(*actprev)->npx = XOR((*actprev)->npx, *act);
				free(curr);
				*end = *actprev;
				*act = *actprev;
				*actprev = XOR((*actprev)->npx, NULL);
			}

		}
		else if (*actprev == *head)
		{
			(*actprev)->npx = *actnext;
			(*actnext)->npx = XOR(*actprev, XOR(*act, (*actnext)->npx));
			free(curr);
			*act = *actprev;
			*actprev = *end;
		}
		else
		{
			(*actnext)->npx = XOR(*actprev, XOR(*act, (*actnext)->npx));
			(*actprev)->npx = XOR(*actnext, XOR(*act, (*actprev)->npx));
			free(curr);
			*act = *actprev;
			*actprev = XOR(*actnext, (*actprev)->npx);
		}
	}
}
void del_val(Node** head, int numb, Node** end, Node** act, Node** actnext, Node** actprev)
{
	Node* curr = NULL;
	struct Node* prev = NULL;
	struct Node* next;
	curr = *head;
	if (curr == NULL)
	{
		return;
	}
	else
	{
		while (curr != NULL)
		{
			next = XOR(prev, curr->npx);
			if (curr->numb == numb)
			{
				if (curr == *act)
				{
					del_act(head, end, act, actnext, actprev);
					if (prev == *end)
					{
						break;
					}
					else
					{
						curr = next;
						continue;
					}
				}
				else if (curr == *head)
				{
					del_beg(head, end, act, actnext, actprev);
					if (prev == *end)
					{
						break;
					}
					else
					{
						curr = next;
						continue;
					}
				}
				else if (curr == *end)
				{
					del_end(head, end, act, actnext, actprev);
					if (prev == *end)
					{
						break;
					}
					else
					{
						curr = next;
						continue;
					}
				}
				else if (curr == *actnext)
				{
					XOR((*actnext)->npx, *act)->npx = XOR(*act, XOR(*actnext, XOR((*actnext)->npx, *act)->npx));
					(*act)->npx = XOR(XOR(*actnext, (*act)->npx), XOR((*actnext)->npx, *act));
					*actnext = XOR((*actnext)->npx, *act);
					free(curr);
					if (prev == *end)
					{
						break;
					}
					else
					{
						curr = next;
						continue;
					}
				}
				else if (curr == *actprev)
				{
					XOR((*actprev)->npx, *act)->npx = XOR(*act, XOR(*actprev, XOR((*actprev)->npx, *act)->npx));
					(*act)->npx = XOR(XOR(*actprev, (*act)->npx), XOR((*actprev)->npx, *act));
					*actprev = XOR((*actprev)->npx, *act);
					free(curr);
					if (prev == *end)
					{
						break;
					}
					else
					{
						curr = next;
						continue;
					}
				}
				else
				{
					XOR(curr->npx, prev)->npx = XOR(XOR(curr, XOR(curr->npx, prev)->npx), prev);
					prev->npx = XOR(XOR(prev->npx, curr), XOR(curr->npx, prev));
					free(curr);
					if (prev == *end)
					{
						break;
					}
					else
					{
						curr = next;
						continue;
					}
				}
			}

			prev = curr;
			curr = next;
		}
	}
}
void print_forward(struct Node* head)
{
	struct Node* curr = head;
	struct Node* prev = NULL;
	struct Node* next;
	if (head == NULL)
	{
		printf("NULL");
	}
	while (curr != NULL)
	{
		printf("%d ", curr->numb);
		next = XOR(prev, curr->npx);
		prev = curr;
		curr = next;
	}
	printf("\n");
}
void print_backward(struct Node* end)
{
	struct Node* curr = end;
	struct Node* next = NULL;
	struct Node* prev;
	if (end == NULL)
	{
		printf("NULL");
	}
	while (curr != NULL)
	{
		printf("%d ", curr->numb);
		prev = XOR(next, curr->npx);
		next = curr;
		curr = prev;
	}
	printf("\n");
}
int main()
{
	int x;
	std::string napis;
	std::string napis1;
	Node* head = NULL;
	Node* act = NULL;
	Node* actnext = NULL;
	Node* actprev = NULL;
	Node* end = NULL;
	while (true)
	{
		getline(std::cin, napis1);
		if (!std::cin)
			break;
		std::istringstream iss(napis1);
		iss >> napis;
		if (napis == "ACTUAL")
		{
			actual(act);
		}
		else if (napis == "NEXT")
		{
			next(&act, &actnext, &actprev, &head, &end);
		}
		else if (napis == "PREV")
		{
			prev(&act, &actnext, &actprev, &end, &head);
		}
		else if (napis == "ADD_BEG")
		{
			iss >> x;
			add_beg(&head, x, &end, &act, &actprev, &actnext);
		}
		else if (napis == "ADD_END")
		{
			iss >> x;
			add_end(&head, x, &end, &act, &actnext, &actprev);
		}
		else if (napis == "ADD_ACT")
		{
			iss >> x;
			add_act(x, &act, &actprev, &head);
		}
		else if (napis == "DEL_BEG")
		{
			del_beg(&head, &end, &act, &actnext, &actprev);
		}
		else if (napis == "DEL_END")
		{
			del_end(&head, &end, &act, &actnext, &actprev);
		}
		else if (napis == "DEL_VAL")
		{
			iss >> x;
			del_val(&head, x, &end, &act, &actnext, &actprev);
		}
		else if (napis == "DEL_ACT")
		{
			del_act(&head, &end, &act, &actnext, &actprev);
		}
		else if (napis == "PRINT_FORWARD")
		{
			print_forward(head);
		}
		else if (napis == "PRINT_BACKWARD")
		{
			print_backward(end);
		}
		else
		{
			break;
		}
		napis = "";

	}
}
