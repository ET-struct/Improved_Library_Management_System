#pragma once


struct book {
    char name[256];
    char author[256];
    int id;
    struct book* next;
    //create LinkedList of review structs for each book somehow
};

struct review {
    int bookID;
    int stars; //1-5 star rating
    char written[256]; //written review of book
    struct review* next;
};

struct student {
    char name[256];
    char email[256];
    char book[256];
    char a[256];
    int id;
    struct student* next;
};


int lib_main();

struct book* initialize_lib(struct book*);
struct student* book_issue(struct student*);
struct student* book_return(struct student*);
struct book* diplay_lib(struct book*);
struct book* delete_book(int);
struct book* add_book(char[ ], char[ ], int);
struct student* write_review(struct student*);
struct review* add_review(review*);
extern struct review* reviews; //pointer to a linked list of reviews
void view_previous_reviews(void);
double average_rating(int, struct review*);

void display(struct student*);
void greetings();
void main_menu();
