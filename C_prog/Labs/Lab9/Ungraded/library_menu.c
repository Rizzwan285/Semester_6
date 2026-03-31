#include <stdio.h>
#include <string.h>

struct Book {
    int book_id;
    char title[50];
    int is_issued;
};

struct IssueLog {
    int book_id;
    int user_id;
};

struct Book books[100];
int book_count = 0;

int findBook(int id) {
    for (int i = 0; i < book_count; i++) {
        if (books[i].book_id == id) return i;
    }
    return -1;
}

void addBook() {
    printf("Enter Book ID: ");
    scanf("%d", &books[book_count].book_id);

    printf("Enter Title: ");
    scanf("%s", books[book_count].title);

    books[book_count].is_issued = 0;
    book_count++;

    printf("Book added\n");
}

void issueBook() {
    int id, user;
    printf("Enter Book ID: ");
    scanf("%d", &id);

    int idx = findBook(id);

    if (idx == -1) {
        printf("Book not found\n");
        return;
    }

    if (books[idx].is_issued) {
        printf("Already issued\n");
        return;
    }

    printf("Enter User ID: ");
    scanf("%d", &user);

    books[idx].is_issued = 1;
    printf("Book issued\n");
}

void returnBook() {
    int id;
    printf("Enter Book ID: ");
    scanf("%d", &id);

    int idx = findBook(id);

    if (idx == -1) return;

    books[idx].is_issued = 0;
    printf("Book returned\n");
}

void searchBook() {
    int id;
    printf("Enter Book ID: ");
    scanf("%d", &id);

    int idx = findBook(id);

    if (idx == -1) {
        printf("Not found\n");
        return;
    }

    printf("Title: %s | Status: %s\n",
           books[idx].title,
           books[idx].is_issued ? "Issued" : "Available");
}

void displayBooks() {
    for (int i = 0; i < book_count; i++) {
        printf("%d %s %s\n",
               books[i].book_id,
               books[i].title,
               books[i].is_issued ? "Issued" : "Available");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1.Add 2.Issue 3.Return 4.Search 5.Display 6.Exit\n");
        scanf("%d", &choice);

        if (choice == 6) break;

        switch (choice) {
            case 1: addBook(); break;
            case 2: issueBook(); break;
            case 3: returnBook(); break;
            case 4: searchBook(); break;
            case 5: displayBooks(); break;
        }
    }

    return 0;
}