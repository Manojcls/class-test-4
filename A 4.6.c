#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct book {
    char title[50];
    char author[50];
    int id;
};

// Global variables
struct book library[MAX_BOOKS];
int num_books = 0;

// Function prototypes
void add_book();
void display_books();
void list_books_by_author();
void list_book_count();

int main() {
    int choice;

    do {
        printf("\n*** Library Menu ***\n");
        printf("1. Add book details\n");
        printf("2. Display book details\n");
        printf("3. List all books of given author\n");
        printf("4. List the count of books in the library\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                list_books_by_author();
                break;
            case 4:
                list_book_count();
                break;
            case 5:
                printf("\nGoodbye!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void add_book() {
    if (num_books >= MAX_BOOKS) {
        printf("\nError: Library is full. Cannot add more books.\n");
        return;
    }

    printf("\nEnter book title: ");
    scanf("%s", library[num_books].title);
    printf("Enter book author: ");
    scanf("%s", library[num_books].author);
    printf("Enter book ID: ");
    scanf("%d", &library[num_books].id);

    printf("\nBook added successfully.\n");
    num_books++;
}

void display_books() {
    int i;

    if (num_books == 0) {
        printf("\nLibrary is empty.\n");
        return;
    }

    printf("\n%-10s%-20s%-20s\n", "Book ID", "Title", "Author");
    printf("-------------------------------------------\n");

    for (i = 0; i < num_books; i++) {
        printf("%-10d%-20s%-20s\n", library[i].id, library[i].title, library[i].author);
    }
}

void list_books_by_author() {
    int i;
    char author[50];
    int count = 0;

    if (num_books == 0) {
        printf("\nLibrary is empty.\n");
        return;
    }

    printf("\nEnter author name: ");
    scanf("%s", author);

    printf("\nBooks by author %s:\n", author);

    for (i = 0; i < num_books; i++) {
        if (strcmp(library[i].author, author) == 0) {
            printf("%s\n", library[i].title);
            count++;
        }
    }

    if (count == 0) {
        printf("\nNo books found by author %s.\n", author);
    }
}

void list_book_count() {
    printf("\nNumber of books in the library: %d\n", num_books);
}

