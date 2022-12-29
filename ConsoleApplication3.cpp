#include <iostream>
#include <string>
#include <sstream>
struct Node
{
	int numb;
	Node* next;
	Node* prev;
};
void push(Node** head, int numb, Node** end, Node** front, Node** back, int* size, int* count)
{
	if (*head == NULL)
	{
		Node* current = new Node();
		*head = current;
		(*head)->next = NULL;
		(*head)->prev = NULL;
		(*head)->numb = numb;
		*size = 1;
		*count = 1;
		*front = *head;
		*back = *head;
		*end = *head;
	}
	else
	{
		if (*front == NULL)
		{
			*back = *end;
			*front = *end;
			(*back)->numb = numb;
			*count = *count + 1;
		}
		else if ((*front)->next == *back || ((*front)->next == NULL && (*back)->prev == NULL))// Tutaj jeśli jest sama kolejka
		{
			Node* current = new Node();
			current->numb = numb;
			*size = *size + 1;
			*count = *count + 1;
			if (*head == *back)
			{
				current->next = *back;
				current->prev = NULL;
				(*back)->prev = current;
				*head = current;
				*back = current;
			}
			else
			{
				current->next = *back;
				current->prev = (*back)->prev;
				(*back)->prev->next = current;
				(*back)->prev = current;
				*back = current;
			}
		}
		else /// Tutaj jeśli jest lista bez kolejki
		{
			if (*back == *head)
			{
				*back = *end;
				(*back)->numb = numb;
				*count = *count + 1;
			}
			else
			{
				*back = (*back)->prev;
				(*back)->numb = numb;
				*count = *count + 1;
			}
		}
	}
}
void pop(Node** head, Node** end, Node** front, Node** back, int* size, int* count)
{
	if (*front == NULL)
	{
		printf("NULL\n");
		return;
	}
	printf("%d\n", (*front)->numb);
	*count = *count - 1;
	if (*front == *back)
	{
		*front = NULL;
		*back = NULL;
	}
	else
	{
		if ((*front)->prev == NULL)
		{
			*front = *end;
		}
		else
		{
			*front = (*front)->prev;
		}
	}
}
void print_queue(Node* front, Node* back, Node* head, Node* end)
{
	if (front == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		Node* current = front;
		if (back == front)
		{
			printf("%d\n", current->numb);
			return;
		}
		if (back == head)
		{
			while (current != NULL)
			{
				printf("%d ", current->numb);
				current = current->prev;
			}
			printf("\n");
		}
		else
		{
			if (front = back->prev)
			{
				printf("%d ", current->numb);
				if (current->prev == NULL)
				{
					current = end;
				}
				else
				{
					current = current->prev;
				}
			}
			while (current != back->prev)
			{
				printf("%d ", current->numb);
				if (current->prev == NULL)
				{
					current = end;
				}
				else
				{
					current = current->prev;
				}
			}
			printf("\n");
		}
	}
}
void countr(int count)
{
	printf("%d\n", count);
}
void sizer(int size)
{
	printf("%d\n", size);
}
void print_forward(Node* head, Node* end)
{
	if (head == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		Node* current = head;
		if (head == end)
		{
			printf("%d\n", current->numb);
			return;
		}
		while (current != NULL)
		{
			printf("%d ", current->numb);
			current = current->next;
		}
		printf("\n");
	}
}
void print_backward(Node* head, Node* end)
{
	if (head == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		Node* current = end;
		if (head == end)
		{
			printf("%d\n", current->numb);
			return;
		}
		while (current != NULL)
		{
			printf("%d ", current->numb);
			current = current->prev;
		}
		printf("\n");
	}
}
void add_beg(Node** head, int numb, Node** end, Node** front, Node** back, int* size, int* count)
{
	if (*head == NULL)
	{
		Node* current = new Node();
		current->next = NULL;
		current->prev = NULL;
		current->numb = numb;
		*head = current;
		*end = current;
		*size = *size + 1;
	}
	else
	{
		Node* current = NULL;
		current = *front;
		if (*front != *back)
		{
			while (current != NULL && current != *back)
			{
				current = current->prev;
			}
			if (current == NULL)
			{
				Node* nowy = new Node();
				nowy->next = *head;
				nowy->prev = NULL;
				nowy->numb = numb;
				(*head)->prev = nowy;
				*size = *size + 1;
				*count = *count + 1;
				*head = nowy;
				return;
			}
		}
		Node* nowy = new Node();
		nowy->next = *head;
		nowy->prev = NULL;
		nowy->numb = numb;
		(*head)->prev = nowy;
		*size = *size + 1;
		*head = nowy;
	}
}
void add_end(Node** head, int numb, Node** end, Node** front, Node** back, int* size, int* count)
{
	if (*head == NULL)
	{
		Node* current = new Node();
		current->next = NULL;
		current->prev = NULL;
		current->numb = numb;
		*head = current;
		*end = current;
		*size = *size + 1;
	}
	else
	{
		Node* current = NULL;
		current = *front;
		if (*front != *back)
		{
			while (current != *back && current != *end)
			{
				if (current == NULL)
				{
					current = *end;
				}
				else
				{
					current = current->prev;
				}
			}
			if (current == *end)
			{
				Node* nowy = new Node();
				nowy->next = NULL;
				nowy->prev = *end;
				nowy->numb = numb;
				(*end)->next = nowy;
				*size = *size + 1;
				*count = *count + 1;
				*end = nowy;
				return;
			}
		}
		Node* nowy = new Node();
		nowy->next = NULL;
		nowy->prev = *end;
		nowy->numb = numb;
		(*end)->next = nowy;
		*size = *size + 1;
		*end = nowy;
	}
}
void garbage_soft(Node** head, Node** end, Node** front, Node** back)
{
	Node* current = NULL;
	current = *back;
	if (*head == NULL)
	{
		return;
	}
	if (*front == NULL)
	{
		current = *head;
		while (current != NULL)
		{
			current->numb = 0;
			current = current->next;
		}
		return;
	}
	while (current != *front)
	{
		current = current->prev;
		if (current == NULL)
		{
			current = *end;
		}
		if (current != *front)
		{
			current->numb = 0;
		}
	}
}
void garbage_hard(Node** head, Node** end, Node** front, Node** back)
{
	Node* current = NULL;
	Node* usun = NULL;
	current = *back;
	usun = current;
	if (*head == NULL)
	{
		return;
	}
	if (*front == NULL)
	{
		if (*head == *end)
		{
			usun = *head;
			delete usun;
			*head = NULL;
			*end = NULL;
			return;
		}
		current = *head;
		usun = current;
		while (current != NULL)
		{
			current = current->next;
			delete usun;
			current->prev = NULL;
			usun = current;
		}
		*head = NULL;
		*end = NULL;
		return;
	}
	current = current->prev;
	usun = current;
	while (current != *front)
	{
		if (current == NULL && *front != *end)
		{
			current = *end;
			usun = current;
			*end = (*end)->prev;
			current = *end;
			current->next = NULL;
			delete usun;
			continue;
		}
		if (current == NULL && *front == *end)
		{
			return;
		}
		if (current != *front)
		{
			usun = current;
			if (current == *head)
			{
				current = *end;
				*head = (*head)->next;
				(*head)->prev = NULL;
				delete usun;
			}
			else
			{
				current->next->prev = current->prev;
				current = current->prev;
				current->next = usun->next;
				delete usun;
			}
		}
	}
}
void del_end(Node** head, Node** end, Node** front, Node** back, int* size, int* count)
{
	if (*head == NULL)
	{
		return;
	}
	Node* current = NULL;
	if (*head == *end)
	{
		current = *end;
		delete current;
		*head = NULL;
		*end = NULL;
		if (*front == NULL)
		{
			*size = *size - 1;
		}
		else
		{
			*front = NULL;
			*back = NULL;
			*size = *size - 1;
			*count = *count - 1;
		}
	}
	else if (*end == *front)
	{
		if (*front == *back)
		{
			current = *end;
			*end = (*end)->prev;
			(*end)->next = NULL;
			delete current;
			*front = NULL;
			*back = NULL;
			*size = *size - 1;
			*count = *count - 1;
		}
		else
		{
			current = *end;
			*end = (*end)->prev;
			(*end)->next = NULL;
			*front = *end;
			delete current;
			*size = *size - 1;
			*count = *count - 1;
		}
	}
	else if (*end == *back)
	{
		if (*front == *back)
		{
			current = *end;
			*end = (*end)->prev;
			(*end)->next = NULL;
			delete current;
			*front = NULL;
			*back = NULL;
			*size = *size - 1;
			*count = *count - 1;
		}
		else
		{
			current = *end;
			*end = (*end)->prev;
			(*end)->next = NULL;
			*back = *head;
			delete current;
			*size = *size - 1;
			*count = *count - 1;
		}
	}
	else
	{
		current = *end;
		while (current != (*back))
		{
			if (current == *front)
			{
				current = *end;
				*end = (*end)->prev;
				(*end)->next = NULL;
				delete current;
				*size = *size - 1;
				return;
			}
			current = current->prev;
		}
		if (current == *front)
		{
			current = *end;
			*end = (*end)->prev;
			(*end)->next = NULL;
			delete current;
			*size = *size - 1;
		}
		else
		{
			current = *end;
			*end = (*end)->prev;
			(*end)->next = NULL;
			delete current;
			*size = *size - 1;
			*count = *count - 1;
		}
	}
}
void del_beg(Node** head, Node** end, Node** front, Node** back, int* size, int* count)
{
	if (*head == NULL)
	{
		return;
	}
	Node* current = NULL;
	if (*head == *end)
	{
		current = *end;
		delete current;
		*head = NULL;
		*end = NULL;
		if (*front == NULL)
		{
			*size = *size - 1;
		}
		else
		{
			*front = NULL;
			*back = NULL;
			*size = *size - 1;
			*count = *count - 1;
		}
	}
	else if (*head == *front)
	{
		if (*front == *back)
		{
			current = *head;
			*head = (*head)->next;
			(*head)->prev = NULL;
			delete current;
			*front = NULL;
			*back = NULL;
			*size = *size - 1;
			*count = *count - 1;
		}
		else
		{
			current = *head;
			*head = (*head)->next;
			(*head)->prev = NULL;
			*front = *end;
			delete current;
			*size = *size - 1;
			*count = *count - 1;
		}
	}
	else if (*head == *back)
	{
		if (*front == *back)
		{
			current = *head;
			*head = (*head)->next;
			(*head)->prev = NULL;
			delete current;
			*front = NULL;
			*back = NULL;
			*size = *size - 1;
			*count = *count - 1;
		}
		else
		{
			current = *head;
			*head = (*head)->next;
			(*head)->prev = NULL;
			*back = *head;
			delete current;
			*size = *size - 1;
			*count = *count - 1;
		}
	}
	else
	{
		current = *head;
		while (current != (*front))
		{
			if (current == *back)
			{
				current = *head;
				*head = (*head)->next;
				(*head)->prev = NULL;
				delete current;
				*size = *size - 1;
				return;
			}
			current = current->next;
		}
		if (current == *back)
		{
			current = *head;
			*head = (*head)->next;
			(*head)->prev = NULL;
			delete current;
			*size = *size - 1;
		}
		else
		{
			current = *head;
			*head = (*head)->next;
			(*head)->prev = NULL;
			delete current;
			*size = *size - 1;
			*count = *count - 1;
		}
	}
}
int main()
{
	int x;
	std::string napis;
	std::string napis1;
	Node* head = NULL;
	Node* end = NULL;
	Node* front = NULL;
	Node* back = NULL;
	int size = 0;
	int count = 0;
	while (true)
	{
		getline(std::cin, napis1);
		if (!std::cin)
			break;
		std::istringstream iss(napis1);
		iss >> napis;
		if (napis == "ADD_BEG")
		{
			iss >> x;
			add_beg(&head, x, &end, &front, &back, &size, &count);
		}
		else if (napis == "ADD_END")
		{
			iss >> x;
			add_end(&head, x, &end, &front, &back, &size, &count);
		}
		else if (napis == "DEL_BEG")
		{
			del_beg(&head, &end, &front, &back, &size, &count);
		}
		else if (napis == "DEL_END")
		{
			del_end(&head, &end, &front, &back, &size, &count);
		}
		else if (napis == "PRINT_FORWARD")
		{
			print_forward(head, end);
		}
		else if (napis == "PRINT_BACKWARD")
		{
			print_backward(head, end);
		}
		else if (napis == "SIZE")
		{
			sizer(size);
		}
		else if (napis == "PUSH")
		{
			iss >> x;
			push(&head, x, &end, &front, &back, &size, &count);
		}
		else if (napis == "POP")
		{
			pop(&head, &end, &front, &back, &size, &count);
		}
		else if (napis == "PRINT_QUEUE")
		{
			print_queue(front, back, head, end);
		}
		else if (napis == "COUNT")
		{
			countr(count);
		}
		else if (napis == "GARBAGE_SOFT")
		{
			garbage_soft(&head, &end, &front, &back);
		}
		else if (napis == "GARBAGE_HARD")
		{
			garbage_hard(&head, &end, &front, &back);
		}
		else
		{
			break;
		}
		napis = "";
	}

}