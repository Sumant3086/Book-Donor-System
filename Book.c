#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    //Defining a set of Macros which can be reused
#define MAX_BOOKS 100
#define MAX_NAME_LENGTH 50
#define MAX_AUTHOR_LENGTH 50
#define MAX_PUBLISHER_LENGTH 50

typedef struct Book { //Structure of Book
    int id;
    char name[MAX_NAME_LENGTH]; 
    char author[MAX_AUTHOR_LENGTH];
    char publisher[MAX_PUBLISHER_LENGTH];
    int year;
} Book;

Book books[MAX_BOOKS]; //Creating an array of Structs
int num_books = 0; //Starting index of Array

void add_book() {
    if (num_books >= MAX_BOOKS) {
        printf("Error: Maximum number of books reached\n");
        return;
    }
    Book book;
    book.id = num_books + 1;
    char temp[MAX_NAME_LENGTH];
    printf("Enter book name: ");
    fgets(temp, MAX_NAME_LENGTH, stdin);
    temp[strcspn(temp, "\n")] = '\0'; // Remove trailing space! ultra imp change or else \n would be considered tooo!!!!
    strcpy(book.name, temp);
    printf("Enter author name: ");
    fgets(temp, MAX_NAME_LENGTH, stdin);
    temp[strcspn(temp, "\n")] = '\0'; // Remove trailing space! ultra imp change or else \n would be considered tooo!!!!
    strcpy(book.author, temp);
    printf("Enter publisher name: ");
    fgets(temp, MAX_NAME_LENGTH, stdin);
    temp[strcspn(temp, "\n")] = '\0'; // Remove trailing space! ultra imp change or else \n would be considered tooo!!!!
    strcpy(book.publisher, temp);
    printf("Enter year of publication: ");
    scanf("%d", &book.year);
    books[num_books] = book;
    num_books++;
    printf("Book added successfully\n");
}

void list_books() {
    printf("ID\tName\tAuthor\tPublisher\tYear\n");
    int i;
    for (i = 0; i < num_books; i++) {
        Book book = books[i];
        printf("%d\t%s\t%s\t%s\t%d\n", book.id, book.name, book.author, book.publisher, book.year);
    }
}

void search_book() {
    char name[MAX_NAME_LENGTH];
    printf("Enter book name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove trailing space! ultra imp change or else \n would be considered tooo!!!!
    int i;
	for (i = 0; i < num_books; i++) {
        Book book = books[i];
        if (strcmp(book.name, name) == 0) {
            printf("ID\tName\tAuthor\tPublisher\tYear\n");
            printf("%d\t%s\t%s\t%s\t%d\n", book.id, book.name, book.author, book.publisher, book.year);
            return;
        }
    }
    printf("Book not found\n");
}

void delete_book(){
           int id;
    printf("Enter book ID: ");
    scanf("%d", &id);
    getchar(); // to clear the newline character in the input buffer
    int i;
	for (i = 0; i < num_books; i++) {
        if (books[i].id == id) {
            // shift all books after the removed book back by one position
            int j;
            for (j = i; j < num_books - 1; j++) {
                books[j] = books[j+1];
            }
            num_books--;
            printf("Book removed successfully\n");
            return;
        }
    }
    printf("Book not found\n");
}

void update_book(){
    int choice,i;
            printf("Enter the ID of record you want to update: ");
            scanf("%d",&i);
            i--;
            printf("Enter the value corresponding to the field that you want to update:\n1. Name \n2. Author \n3. Publisher\n4. Year\nEnter:");
            scanf("%d",&choice);
            char s[MAX_AUTHOR_LENGTH];
            if(choice!=4){
            printf("Enter New value: ");
            scanf("%s",s);
            }
            switch(choice){
                case 1:{
                	int j;
                    for(j=0;j<strlen(books[i].name);j++){
                        books[i].name[j]=s[j];
                    };
                        break;
                }
                case 2:{
                	int j;
                    for(j=0;j<strlen(books[i].name);j++){
                        books[i].author[j]=s[j];
                    };
                        break;
                }
                case 3:{
                	int j;
                    for(j=0;j<strlen(books[i].name);j++){
                        books[i].publisher[j]=s[j];
                    };
                    break;
                }
                case 4:{
                        int years;
                        printf("Enter the year: ");
                        scanf("%d",&years);
                        books[i].year=years;
                        break;
                    
                }
            }
            
        
            printf("\nfield updated!\n");
}

int main() {
    int choice;
    do {
        printf("\n--Book Donor System--\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Search Book\n");
        printf("4. Delete\n");
        printf("5. Update\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to clear the newline character in the input buffer
        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                list_books();
                break;
            case 3:
                search_book();
                break;
            case 4:
                delete_book();
                break;
            case 5:
                update_book();
                break;
            case 6:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1); // continue looping while true
    return 0;
}