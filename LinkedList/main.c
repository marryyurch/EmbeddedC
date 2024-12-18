#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[255];
    double price;
    int pages;
    char language[50];
    double weight;
    int year;
    struct Book* next;
} Book;

Book* createBook(const char* title, double price, int pages, const char* language, double weight, int year) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    if (!newBook) {
        perror("Failed to allocate memory for a new book");
        exit(EXIT_FAILURE);
    }

    strncpy(newBook->title, title, sizeof(newBook->title) - 1);
    newBook->title[sizeof(newBook->title) - 1] = '\0';
    newBook->price = price;
    newBook->pages = pages;
    strncpy(newBook->language, language, sizeof(newBook->language) - 1);
    newBook->language[sizeof(newBook->language) - 1] = '\0';
    newBook->weight = weight;
    newBook->year = year;
    newBook->next = NULL;

    return newBook;
}

void printBooks(const Book* head) {
    const Book* current = head;
    int count = 1;

    while (current) {
        printf("Book %d:\n", count++);
        printf("  Title: %s\n", current->title);
        printf("  Price: $%.2f\n", current->price);
        printf("  Pages: %d\n", current->pages);
        printf("  Language: %s\n", current->language);
        printf("  Weight: %.2f kg\n", current->weight);
        printf("  Year: %d\n", current->year);
        printf("-----------------------------\n");

        current = current->next;
    }
}

void freeBooks(Book* head) {
    while (head) {
        Book* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Book* book1 = createBook("Harry Potter and the Philosopher's Stone", 9.99, 223, "English", 0.5, 1997);
    Book* book2 = createBook("Harry Potter and the Chamber of Secrets", 10.99, 251, "English", 0.6, 1998);
    Book* book3 = createBook("Harry Potter and the Prisoner of Azkaban", 11.99, 317, "English", 0.7, 1999);

    book1->next = book2;
    book2->next = book3;

    printf("Harry Potter Book Series Information:\n\n");
    printBooks(book1);
    freeBooks(book1);

    return 0;
}
