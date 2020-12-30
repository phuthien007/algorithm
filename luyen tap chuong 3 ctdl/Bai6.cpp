#include <iostream>
using namespace std;
struct Node {
	int Inf;
	struct Node* Next;
};
typedef struct Node List;
Node* create(int x) {
	Node* p = new Node;
	p->Inf = x;
	p->Next = NULL;
	return p;
}
List* add(List* Numlist, int x) {
	if (Numlist == NULL)
		return create(x);
	Numlist->Next = add(Numlist->Next, x);
	return Numlist;
}
// in
void print(List* Numlist) {
	List* p = Numlist;
	while (p != NULL)
	{
		cout << p->Inf << " ";
		p = p->Next;
	}
}
List* removeDup(List* Numlist) {
	List* p = Numlist;
	while (p->Next != NULL)
	{
		Node* q = p->Next;
		while(p->Inf == q->Inf)
		{
			p->Next = q->Next;
			q = p->Next;
		}
		p = p->Next;
	}
	return Numlist;
}
int main()
{
	List* Numlist = NULL;
	Numlist = add(Numlist, 1);
	Numlist = add(Numlist, 1);
	Numlist = add(Numlist, 3);
	Numlist = add(Numlist, 3);
	Numlist = add(Numlist, 4);
	Numlist = add(Numlist, 4);
	Numlist = add(Numlist, 4);
	Numlist = add(Numlist, 5);
	print(Numlist);
	Numlist = removeDup(Numlist);
	cout << endl;
	print(Numlist);
	return 0;
}