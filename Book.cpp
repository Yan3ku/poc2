#include "Book.hpp"

std::ostream &operator<<(std::ostream &out, const Book &bk) {
	return out << "TITLE: " << bk.title << " AUTHOR: " << bk.author << "\n";
}
