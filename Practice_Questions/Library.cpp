/**  Problem: Library and Book Classes (Copy Constructor with Nested Objects)
    You are to design a system with two classes:
    Book: Represents a book with a title and author.
    Library: Holds a dynamic array of Book objects and a name.

Your tasks:
    Implement both classes.
    In Library, manage an array of Book objects with dynamic memory (new Book[...]).

Implement:
    A proper copy constructor in both classes.
    A destructor in both classes.

In main():
    Create a Library with 3 books.
    Copy it using the copy constructor.
    Modify a book in the original library and show the copied one remains unchanged.
 */

#include<iostream>
#include<string>

class Book {
private:
    std::string title;
    std::string author;

public:
    Book() : title(""), author("") {};
    Book(const std::string& title, const std::string& author) : title(title), author(author){};
    Book(const Book& other) {
        this->title = other.title;
        this->author = other.author;
    }; // Copy constructor

    ~Book() {
        std::cout << "Book destructor called" << std::endl;
    };

    void print() const {
        std::cout << "Title of the book is : " << title << std::endl;
        std::cout << "Author of the book is : " << author << std::endl;
    };

    void setTitle(const std::string& newTitle) {
        title = newTitle;
    };
};

class Library {
private:
    std::string name;
    Book* books;
    int bookCount;

public:
    Library(const std::string& name, const Book* books, int count) : name(name), bookCount(count) {
        this->books = new Book[count];
        for (int i = 0; i < count; i++) {
            this->books[i] = books[i];
        }
    };

    Library(const Library& other) {
        this->name = other.name;
        this->bookCount = other.bookCount;
        this->books = new Book[other.bookCount];
        for (int i = 0; i < bookCount; i++) {
            this->books[i] = other.books[i];
        }
    }; // Copy constructor

    Library& operator=(const Library& other) {
        if (this != &other) {
            delete[] books; // Free existing resource
            name = other.name;
            bookCount = other.bookCount;
            books = new Book[bookCount];
            for (int i = 0; i < bookCount; i++) {
                books[i] = other.books[i];
            }
        }
        return *this;
    }
    ~Library() {
        delete[] books;
        std::cout << "Library destructor called" << std::endl;
    };
    void print() const {
        for (int i = 0; i < bookCount; i++) {
           books[i].print();
        } 
    };
    void setBookTitle(int index, const std::string& newTitle) {
        if (index < 0 || index >= bookCount) {
            std::cout << "Index overflow when setting book title" << std::endl;
            return;
        }
        books[index].setTitle(newTitle);
    };
};

int main() {
    Book bookArray[] = {
        Book("1984", "George Orwell"),
        Book("To Kill a Mockingbird", "Harper Lee"),
        Book("The Great Gatsby", "F. Scott Fitzgerald")
    };
    Library originalLibrary("Met", bookArray, 3);

    Library copiedLibrary = Library(originalLibrary);
    copiedLibrary.setBookTitle(0, "Brave New World");
    std::cout << "Original Library:" << std::endl;
    originalLibrary.print();
    std::cout << "Copied Library:" << std::endl;
    copiedLibrary.print();
    return 0;
}
