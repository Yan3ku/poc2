#pragma once
#include <string>
#include <iostream>

class Book {
private:
	std::string title;
	std::string author;
public:
	Book() {}
	Book(const std::string &title, const std::string &author) :
		author(author), title(title) {};
	Book(std::string &&title, const std::string &&author) :
		author(std::move(author)), title(std::move(title)) {};
	Book(const Book &book) {
		this->title = book.title;
		this->author = book.author;
	}
	Book(Book &&book) {
		this->title = std::move(book.title);
		this->author = std::move(book.author);
	}
	Book &operator=(const Book &book) {
		Book tmp = book;
		std::swap(this->title, tmp.title);
		std::swap(this->author, tmp.author);
		return *this;
	}
	Book &operator=(Book &&book) {
		this->title = std::move(book.title);
		this->author = std::move(book.author);
		return *this;
	}
	std::string GetTitle() { return this->title; }
	std::string GetAuthor() { return this->author; }
	void SetTitle(std::string &&ti) { this->title = ti; }
	void SetAuthor(std::string &&au) { this->author = au; }
	void SetTitle(const std::string &ti) { this->title = ti; }
	void SetAuthor(const std::string &au) { this->author = au; }
	friend std::ostream &operator<<(std::ostream &out, const Book &book);
};
