#include "Book.hpp"
#include "Library.hpp"
#include <iostream>



using namespace std;

int main2() {
	string a="Diune", t="Hubert";
	Book e;
	cout << "e: "<< e << endl;
	Book b1 = {a, t};
	cout << "b1: "<< b1 << endl;
	Book b2 = {"Hisashiburi","Atashi"};
	cout << "b2: "<< b2 << endl;
	Book b3 = b1;
	cout << "b3: "<< b3 << "b1: " << b1 << endl;
	e = std::move(b2);
	cout << "e: "<< e << "b2:" << b2 << endl;
	e.SetAuthor("僕の幻の彼女");
	cout << "e: "<< e << endl;
	e.SetTitle("あらあら");
	cout << "e: "<< e << endl;
	return 1;
}

int main() {
	Library e;
	cout << "e: "<< e << endl;
	Library l1 = {{"<?>", "<?>"},
		      {"<?>", "<?>"},
		      {"<?>", "<?>"}};
	cout << "l1:\n"<< l1 << endl;
	Library l2(2);
	cout << "l2:\n"<< l2 << endl;
	l2[0] = {"86", "Asato"};
	l2[1] = {"SICP", "YN"};
	cout << "l2:\n"<< l2 << endl;
	e = std::move(l2);
	cout << "e:\n" << e << "l2:\n"<< l2 << endl;
	l1[0] = std::move(e[1]);
	cout << "l1:\n" << l1 << "e:\n"<< e << endl;
	return 0;
}
