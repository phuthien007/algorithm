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
void OddEven(List* Numlist) {
	int CountOdd = 0, CountEven = 0;
	List* p = Numlist;
	while (p != NULL)
	{
		if (p->Inf % 2 == 0)
			CountOdd += 1;
		else CountEven += 1;
		p = p->Next;
	}
	cout <<endl<< "So chan: " << CountOdd << " " << "So le: " << CountEven;
}
int main()
{
	List* Numlist=NULL;
	Numlist = add(Numlist, 3);
	Numlist = add(Numlist, 1);
	Numlist = add(Numlist, 5);
	Numlist = add(Numlist, 2);
	Numlist = add(Numlist, 4);
	print(Numlist);
	OddEven(Numlist);
	return 0;
}