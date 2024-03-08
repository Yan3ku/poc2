#include "Library.hpp"

Library::Library() {
	books = nullptr;
	len = 0;
}

Library::Library(int n) {
	books = new Book[n];
	len = n;
}

Library::Library(std::initializer_list<Book> list) {
	len = list.size();
	books = new Book[len];
	int i = 0;
	for (auto b : list) {
		books[i++] = b;
	}
}

Library::Library(const Library& orig) {
	*this = orig;
}

Library::Library(Library&& orig) {
	books = std::move(orig.books);
	len = std::move(orig.len);
}

Library& Library::operator=(const Library& right) {
	Library lib = right;
	std::swap(books, lib.books);
	std::swap(len, lib.len);
	return *this;
}

Library& Library::operator=(Library&& right) {
	books = right.books;
	len = right.len;
	right.books = nullptr;
	right.len = 0;
	return *this;
}

Book& Library::operator[](std::size_t index) {
	return books[index];
}

const Book& Library::operator[](std::size_t index) const {
	return books[index];
}

std::size_t Library::GetSize() const {
	return len;
}

std::ostream &operator<<(std::ostream &out, const Library &lib) {
	for (int i = 0; i < lib.len; i++) {
		out << lib.books[i];
	}
	return out;
}

Library::~Library() {
	if (books) delete[] books;
	books = nullptr;
}
