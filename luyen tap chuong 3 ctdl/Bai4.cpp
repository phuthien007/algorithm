#include <iostream>
using namespace std;
struct PolyNode {
	int coeff; //chua he so
	int pow; //chua so mu
	struct PolyNode* link;
};
typedef struct PolyNode Polynom;
// x^2 +1
// x^4 + x^2 + x + 1
Polynom* create(int x, int y) {
	Polynom* p = new Polynom;
	p->coeff = x;
	p->pow = y;
	p->link = NULL;
	return p;
}
// tao listPoly
Polynom* add(Polynom* Poly, int x, int y) {
	PolyNode* p = create(x, y);
	if (Poly == NULL)
		return p;
	else {
		Poly->link = add(Poly->link, x, y);
	}
	return Poly;
}
// in
void print(Polynom* Poly1) {
	Polynom* temp = Poly1;
	while (temp->link != NULL)
	{
		cout << temp->coeff << "x^" << temp->pow << " + ";
		temp = temp->link;
	}
	cout << temp->coeff << "x^" << temp->pow;
}
Polynom* PolySum(Polynom* Poly1, Polynom* Poly2) {
	Polynom* newPoly = NULL;
	while (Poly1 != NULL && Poly2 != NULL) {
		if (Poly1->pow > Poly2->pow) {
			newPoly = add(newPoly, Poly1->coeff, Poly1->pow);
			Poly1 = Poly1->link;
		}
		else if (Poly1->pow < Poly2->pow) {
			newPoly = add(newPoly, Poly2->coeff, Poly2->pow);
			Poly2 = Poly2->link;
		}
		else {
			newPoly = add(newPoly, Poly1->coeff + Poly2->coeff, Poly1->pow);
			Poly1 = Poly1->link;
			Poly2 = Poly2->link;
		}
	}
	while (Poly1 != NULL)
	{
		newPoly = add(newPoly, Poly1->coeff, Poly1->pow);
		Poly1 = Poly1->link;
	}
	while (Poly2 != NULL)
	{
		newPoly = add(newPoly, Poly2->coeff, Poly2->pow);
		Poly2 = Poly2->link;
	}
	return newPoly;
}
Polynom* PolyMutil(Polynom* Poly1, Polynom* Poly2) {
	Polynom* result = NULL;
	for (auto i = Poly1; i != NULL; i = i->link)
	{
		PolyNode* p=NULL;
		for (auto j = Poly2; j != NULL; j = j->link)
		{
			p = add(p, i->coeff * j->coeff, i->pow + j->pow);
		}
		result = PolySum(result, p);
	}
	return result;
}
int main()
{
	Polynom* Poly1 = NULL, * Poly2 = NULL;
	Poly1 = add(Poly1, 1, 2);
	Poly1 = add(Poly1, 1, 0);
	Poly2 = add(Poly2, 1, 4);
	Poly2 = add(Poly2, 1, 2);
	Poly2 = add(Poly2, 1, 1);
	Poly2 = add(Poly2, 1, 0);
	print(Poly1);
	cout << endl;
	print(Poly2);
	cout << endl;
	print(PolySum(Poly1, Poly2));
	cout << endl;
	cout << endl;
	print(PolyMutil(Poly1, Poly2));
	return 0;
}