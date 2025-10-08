#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Structure to represent a book
struct Book {
    string title;
    string author;
    int yearPublished;
    int id;
};

//Function to list books (not in task, but could be useful)
void listBooks(const vector<Book>& books) {
    if (books.empty()) {
        cout << "Няма налични книги в библиотеката." << endl;
        return;
    }
    
    cout << "Списък на наличните книги:\n";
    for (const Book& book : books) {
        cout << "ID: " << book.id 
             << ", Заглавие: " << book.title 
             << ", Автор: " << book.author 
             << ", Година на публикуване: " << book.yearPublished 
             << endl;
    }
}

// Function to add a new book
void addBook(vector<Book>& books) {
    Book newBook;
    
    cout << "Въведи заглавие: ";
    cin.ignore();
    getline(cin, newBook.title);

    cout << "Въведи автор: ";
    getline(cin, newBook.author);

    cout << "Въведи година на публикуване: ";
    cin >> newBook.yearPublished;

    cout << "Въведи ID на книгата: ";
    cin >> newBook.id;
    
    // Check if ID already exists
    for (const Book& book : books) {
        if (book.id == newBook.id) {
            cout << "Грешка: ID на книгата вече съществува!" << endl;
            return;
        }
    }
    
    books.push_back(newBook);
    cout << "Книгата беше добавена успешно." << endl;
}

// Function to search for a book by title
void searchBook(const vector<Book>& books) {
    string searchTitle;
    cout << "Въведи заглавие на книгата за търсене: ";
    cin.ignore();
    getline(cin, searchTitle);
    
    bool found = false;
    for (const Book& book : books) {
        if (book.title == searchTitle) {
            cout << "Книгата беше намерена!\n";
            cout << "Заглавие: " << book.title << endl;
            cout << "Автор: " << book.author << endl;
            cout << "Година на публикуване: " << book.yearPublished << endl;
            cout << "ID: " << book.id << endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "Книгата не беше намерена." << endl;
    }
}

// Function to delete a book by ID
void deleteBook(vector<Book>& books) {
    int deleteId;
    cout << "Въведи ID на книгата за изтриване: ";
    cin >> deleteId;
    
    auto it = find_if(books.begin(), books.end(),
                     [deleteId](const Book& book) { return book.id == deleteId; });
    
    if (it != books.end()) {
        books.erase(it);
        cout << "Книгата беше намерена и изтрита." << endl;
    } else {
        cout << "Книгата не беше намерена." << endl;
    }
}

int main() {
    vector<Book> books;
    string command;

    cout << "Система за управление на библиотека\n";
    cout << "Налични команди: add, search, delete, list, exit\n";

    while (true) {
        cout << "\nВъведи команда: ";
        cin >> command;
        
        if (command == "add") {
            addBook(books);
        }
        else if (command == "search") {
            searchBook(books);
        }
        else if (command == "delete") {
            deleteBook(books);
        }
        else if (command == "list") {
            listBooks(books);
        }
        else if (command == "exit") {
            cout << "Излизане от програмата." << endl;
            break;
        }
        else {
            cout << "Невалидна команда. Налични команди: add, search, delete, list, exit" << endl;
        }
    }
    
    return 0;
}
