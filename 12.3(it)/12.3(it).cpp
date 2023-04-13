#include <iostream>
using namespace std;
typedef int Info;

struct Elem
{
	Elem* next,
		* prev;
	Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value);
int dequeue(Elem*& first, Elem*& last);
void print(Elem* first);
int Sum(Elem* L);

void enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->next = NULL;
	if (last != NULL)
		last->next = tmp;
	tmp->prev = last;
	last = tmp;
	if (first == NULL)
		first = tmp;
}
Info dequeue(Elem*& first, Elem*& last)
{
	Elem* tmp = first->next; // 1
	Info value = first->info; // 2
	delete first; // 3
	first = tmp; // 4
	if (first == NULL)
		last = NULL; // 5
	else
		first->prev = NULL; // 6
	return value; // 7
}
void print(Elem* first) {

	Elem* current = first;

	while (current != NULL) {
		cout << current->info << " ";
		current = current->next;
	}
	cout << endl;
}
int Sum(Elem* L)
{
	int S = 0;
	while (L != NULL)
	{
		if (L->info % 2 == 0)
		{
			S += L->info;
		}
		L = L->next;
	}
	return S;
}
int main()
{
	Elem* first = NULL,
		* last = NULL;

	for (int i = 1; i <= 20; i++)
	{
		enqueue(first, last, i);
	}
	cout << "list: ";
	print(first);
	cout << Sum(first) << endl;
	while (first != NULL)
		dequeue(first, last);
	return 0;
}
