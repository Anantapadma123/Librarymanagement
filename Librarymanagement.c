#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
};

void addBook(struct Book *b, int id, char *title, char *author) {
    b->id = id;
    strcpy(b->title, title);
    strcpy(b->author, author);
}

void displayBook(struct Book *b) {
    printf("ID: %d\nTitle: %s\nAuthor: %s\n", b->id, b->title, b->author);
}

int main() {
    struct Book books[10];
    int choice, count = 0, id;
    char title[100], author[100];

    while (1) {
        printf("\nLibrary Management\n1. Add Book\n2. Display Books\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            if (count < 10) {
                printf("Enter ID: ");
                scanf("%d", &id);
                getchar();  // to consume the newline left by scanf
                printf("Enter title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // remove the newline
                printf("Enter author: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = '\0'; // remove the newline
                addBook(&books[count], id, title, author);
                count++;
            } else {
                printf("Library is full!\n");
            }
        } else if (choice == 2) {
            for (int i = 0; i < count; i++) {
                displayBook(&books[i]);
            }
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
     return 0;
}
