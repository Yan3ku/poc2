#pragma once
#include "Book.hpp"
#include <iostream>
#include <initializer_list>

class Library {
	Book *books = nullptr;
	size_t len = 0;
public:
	Library();
	Library(int);
	Library(std::initializer_list<Book> list);
	Library(const Library& orig);
	Library(Library&& orig);
	Library& operator=(const Library& right);
	Library& operator=(Library&& right);
	Book& operator[](std::size_t index);
	const Book& operator[](std::size_t index) const;
	friend std::ostream &operator<<(std::ostream &out, const Library &lib);
	std::size_t GetSize() const;
	~Library();
};
