#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "LibraryManagementSystem.h";

using namespace std;




struct book *start_lib=NULL; //pointer to a linked list of books
struct student *start=NULL; //pointer to a linked list of students
struct review* reviews = NULL; //pointer to a linked list of reviews



int main(){
    start_lib=initialize_lib(start_lib);
    greetings();
    main_menu();
    return 0;
}

void greetings(){
    printf("\n\n");
    printf("\t\t\t     ****************************************\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *     ----------------------------     *\n");
    printf("\t\t\t     *      WELCOME TO STUDENT LIBRARY      *\n");
    printf("\t\t\t     *     ----------------------------     *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     ****************************************\n");
    printf("\n\n");
    printf("\t\t\t     ****************************************\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *       ------------------------       *\n");
    printf("\t\t\t     *           STUDENT LIBRARY            *\n");
    printf("\t\t\t     *       ------------------------       *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *            Cal Poly Pomona           *\n");
    printf("\t\t\t     *  Edited By: Brandon D., Cheyenne V.  *\n");
    printf("\t\t\t     *               Ethan T.               *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     ****************************************\n");
    printf("\n\n\t\t\t             Press any key to continue: ");
    _getch();
}

void main_menu(){
    int choice;
    do{
        printf("\n\n");
        printf("\n\t\t\t*************************************************\n");
        printf("\n\t\t\t\t      MAIN MENU: ");
        printf("\n\t\t\t\t     1.ISSUE OF BOOKS ");
        printf("\n\t\t\t\t     2.WRITE REVIEW OF BOOKS ");
        printf("\n\t\t\t\t     3.VIEW REVIEWS OF BOOKS ");
        printf("\n\t\t\t\t     4.AVG RATINGS OF BOOKS ");
        printf("\n\t\t\t\t     5.RETURN OF BOOKS ");
        printf("\n\t\t\t\t     6.DISPLAY STUDENT DETAILS ");
        printf("\n\t\t\t\t     7.EXIT\n ");
        printf("\n\t\t\t*************************************************\n");
        printf("\n\t\t\t\t      Enter your choice: ");
        scanf_s("%d",&choice);
        switch(choice){
            case 1:{
                start=book_issue(start);
                break;
            }
            case 2: {
                start = write_review(start);
                break;
            }
            case 3:{
                view_previous_reviews();
                break;
            }
            case 4: {
            int bookID;
            cout << "Enter the Book ID to view its average rating: ";
            cin >> bookID;


            double avg = average_rating(bookID, reviews);


            if(avg ==0.0){
                cout << "No reviews found for this book yet.\n";
            } else{
                cout << "Average rating for Book ID " << bookID << " is: " << avg << " stars\n";
            }
            break;
            }

            case 5: {
                start = book_return(start);
                break;
            }
            case 6:{
                display(start);
                break;
            }
            case 7:{
                exit(1);
            }
            default:{
                printf("\n\t\t\t\t      ...Invalid Option!...\n");
                printf("\n\t\t\t\t      Press any key to try again: ");
                _getch();
            }
        }
    }while(choice!=7);
}

struct book *initialize_lib(struct book *start){
    struct book *ptr,*new_book1,*new_book2,*new_book3,*new_book4,*new_book5;

    new_book1=(struct book *)malloc(sizeof(struct book));
    new_book1->next=NULL;
    start_lib=new_book1;
    strcpy_s(new_book1->name,"The Kite Runner");
    strcpy_s(new_book1->author,"Khaled Hosseini");
    new_book1->id=101;
    ptr=new_book1;

    new_book2=(struct book*)malloc(sizeof(struct book));
    new_book2->next=NULL;
    strcpy_s(new_book2->name,"To Kill A Mockingbird");
    strcpy_s(new_book2->author,"Harper Lee");
    new_book2->id=102;
    ptr->next=new_book2;
    ptr=new_book2;

    new_book3=(struct book*)malloc(sizeof(struct book));
    new_book3->next=NULL;
    strcpy_s(new_book3->name,"The Alchemist");
    strcpy_s(new_book3->author,"Paulo Coelho");
    new_book3->id=103;
    ptr->next=new_book3;
    ptr=new_book3;

    new_book4=(struct book*)malloc(sizeof(struct book));
    new_book4->next=NULL;
    strcpy_s(new_book4->name,"Pride And Prejudice");
    strcpy_s(new_book4->author,"Jane Austen");
    new_book4->id=104;
    ptr->next=new_book4;
    ptr=new_book4;

    new_book5=(struct book*)malloc(sizeof(struct book));
    new_book5->next=NULL;
    strcpy_s(new_book5->name,"A Tale Of Two Cities");
    strcpy_s(new_book5->author,"Charles Dickens");
    new_book5->id=105;
    ptr->next=new_book5;

    return start_lib;
}

struct student *book_issue(struct student *start){
    struct book *ptr;
    struct student *ptr2,*new_student;
    int i=1,id,flag=0;
    if(start_lib==NULL){
        printf("\n\t\t\t\t No books left in the library to issue!\n\t\t\t\t Sorry for the inconvenience!\n");
    }else{
        system("cls");
        ptr=start_lib;
        printf("\n\t*************** Books Available: ****************\n");
        while(ptr!=NULL){ //lists all the books in the library that are not checked out
            printf("\n\t_________________________________________________\n");
            printf("\n\t Book %d",i);
            printf("\n\t Book Title: %s",ptr->name);
            printf("\n\t Name of Author: %s",ptr->author);
            printf("\n\t Book ID: %d",ptr->id);
            printf("\n\t_________________________________________________\n");
            ptr=ptr->next;
            i++;
        }
        printf("\n\n\t Enter the Book ID: ");
        scanf_s("%d",&id);
        ptr=start_lib;
        while(ptr!=NULL){
            if(ptr->id==id){
                flag=1;
                break;
            }
            ptr=ptr->next;
        }
        if(flag==1){
            ptr=start_lib;
            while(ptr->id!=id){
                ptr=ptr->next;
            }
            new_student=(struct student *)malloc(sizeof(struct student));
            printf("\n\t Enter Student Details:\n ");
            printf("\n\t Enter your Name: ");
            scanf("%s",new_student->name);
            printf("\n\t Enter your Email: ");
            scanf("%s",new_student->email);
            strcpy_s(new_student->book,ptr->name);
            strcpy_s(new_student->a,ptr->author);
            new_student->id=ptr->id;
            new_student->next=NULL;
            printf("\n\t Issue of Book ID %d done successfully!\n",new_student->id);
            printf("\n\n\t*************************************************\n");
            if(start==NULL){
                start=new_student;
            }else{
                ptr2=start;
                while(ptr2->next!=NULL){
                    ptr2=ptr2->next;
                }
                ptr2->next=new_student;
            }
            start_lib=delete_book(new_student->id);
            printf("\n\n\t Press any key to go to the main menu: ");
            _getch();
            system("cls");
        }else{
            printf("\n\t\t      ...Invalid Option!...\n");
            printf("\n\t\t      Press any key to try again: ");
            _getch();
            system("cls");
        }
    }
    return start;
}

struct student *write_review(struct student *start) {
    struct student* ptr, * preptr;
    struct review* rev;
    rev = (struct review*)malloc(sizeof(struct review));
    int id, flag = 0; 
    bool valid1 = false; //valids are for giving in-range star rating and written reviews

    printf("Enter the ID of the Book you want to review: ");
    scanf_s("%d", &id);
    ptr = start;
    while (ptr != NULL) {
        if (ptr->id == id) {
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }

    if (flag == 1) {
        rev->bookID = id;
        while (!valid1) {
        printf("On a scale of 0-5, how many stars would you give this book? ");
        scanf_s("%d", &rev->stars);
            if ((rev->stars) < 0 || (rev->stars) > 5) {
                printf("Sorry, that's out of range. Give a 0-5 rating please.\n");
            }
            else {
                printf("You gave this book %d stars", rev->stars);
                valid1 = true;
            }
        }

        
        printf("\nIn 254 characters or less, type a written review of this book: \n");
        fgets(rev->written, 255, stdin); //this is to clear keyboard buffer of enter key
        fgets(rev->written, 255, stdin);
        printf("Your review: %s", rev->written);

        add_review(rev); //adding this review to the linked list
    }
    else {
        printf("Whoops, looks like we can't verify that you've checked out that book, are you sure you checked it out?");
    }

    return start;
}

struct review* add_review(review* rvw) {
    review* ptr = reviews; //ptr to linked list of reviews, which in this case is first review
    rvw->next = ptr; //setting next review ptr to what was first
    reviews = rvw; //inserting this review to beginning of linked list
    return rvw;
}

void view_previous_reviews() {
    int bID=0;
    printf("\n\t\t\t\t     Enter the book ID (101,102,103,104,105): ");
    scanf_s("%d", &bID);
    struct review* first = reviews;
     if (bID == 101) {
        while (first != nullptr) {
            printf("Rating: %d Stars\n", first->stars);
            printf("Review:\n\t%s\n\n", first->written);
            first = first->next;
        }
    }
    else if (bID == 102) {
        while (first != nullptr) {
            printf("Rating: %d Stars\n", first->stars);
            printf("Review:\n\t%s\n\n", first->written);
            first = first->next;
        }
    }
    else if (bID == 103) {
        while (first != nullptr) {
            printf("Rating: %d Stars\n", first->stars);
            printf("Review:\n\t%s\n\n", first->written);
            first = first->next;
        }
    }
    else if (bID == 104) {
        while (first != nullptr) {
            printf("Rating: %d Stars\n", first->stars);
            printf("Review:\n\t%s\n\n", first->written);
            first = first->next;
        }
    }
    else if (bID == 105) {
        while (first != nullptr) {
            printf("Rating: %d Stars\n", first->stars);
            printf("Review:\n\t%s\n\n", first->written);
            first = first->next;
        }
    }
    else {printf("Invalid Book or No Reviews! Try Again.");}
}


    double average_rating(int bookID, review * head) {
        int count = 0;
        int sum = 0;

        struct review* current = reviews;

        while (current != nullptr) {
            if (current->bookID == bookID) {
                sum += current->stars;
                count++;
            }
            current = current->next;
        }

        if (count == 0) {
            return 0.0;
        }
        return static_cast <double> (sum) / count;
    }



struct student *book_return(struct student *start){
    struct student *ptr,*preptr = NULL;
    char bookname[30],authorname[30];
    int flag=0,id,identity,c=0,d=1;
    printf("\n\n\t*************** Books Submission: ****************\n");
    printf("\n\n\t Enter your Book ID: ");
    scanf_s("%d",&identity);
    ptr=start;
    while(ptr!=NULL){
        if(ptr->id==identity){
            flag=1;
            break;
        }
        ptr=ptr->next;
    }
    if(flag==1){
        ptr=start;
        while(ptr!=NULL){
            c++;
            ptr=ptr->next;
        }
        ptr=start;
        while(ptr->id!=identity){
                d++;
            ptr=ptr->next;
        }
        ptr=start;
        if( d==1 ){
            printf("\n\t_________________________________________________\n");
            printf("\n\t Student Name: %s",start->name);
            printf("\n\t Student Email: %s",start->email);
            printf("\n\t Name of Book Issued: %s",start->book);
            printf("\n\t_________________________________________________\n");
            printf("\n\n\t Return of Book ID %d done successfully!\n",identity);
            printf("\n\n\t*************************************************\n");
            strcpy_s(bookname,start->book);
            strcpy_s(authorname,start->a);
            id=start->id;
            start=start->next;
            free(ptr);
            add_book(bookname,authorname,id);
        }else{
            ptr=start;
            while(ptr->id!=identity){
                preptr=ptr;
                ptr=ptr->next;
            }
            printf("\n\t_________________________________________________\n");
            printf("\n\t Student Name: %s",ptr->name);
            printf("\n\t Student Email: %s",ptr->email);
            printf("\n\t Name of Book Issued: %s",ptr->book);
            printf("\n\t Book ID: %d",ptr->id);
            printf("\n\t_________________________________________________\n");
            strcpy_s(bookname,ptr->book);
            strcpy_s(authorname,ptr->a);
            id=ptr->id;
            preptr->next=ptr->next;
            free(ptr);
            add_book(bookname,authorname,id);
        }
        printf("\n\t Thank you! \n\t Do visit again! ");
        printf("\n\n\t Press any key to go to the main menu: ");
        _getch();
        system("cls");
    }else{
        printf("\n\tSorry the book doesn't exist! Please recheck the entered ID");
        printf("\n\t\t\t\t      Press any key to try again: ");
        _getch();
        system("cls");
    }
    return start;
}

void display(struct student *start){
    struct student *ptr;
    ptr=start;
    while(ptr!=NULL){
        printf("\n\t************* Details of Students: **************\n");
        printf("\n\t_________________________________________________\n");
        printf("\n\t\t Student Name: %s",ptr->name);
        printf("\n\t\t Student Email: %s",ptr->email);
        printf("\n\t\t Name of Book Issued: %s",ptr->book);
        printf("\n\t\t Book ID: %d",ptr->id);
        printf("\n\t_________________________________________________\n");
        printf("\n\n\t*************************************************\n");
        ptr=ptr->next;
    }
    printf("\n\n\t Press any key to go to the main menu: ");
    _getch();
    system("cls");
}

struct book *delete_book(int id){
    struct book *ptr,*preptr = NULL;
    int c=0;
    ptr=start_lib;
    while(ptr!=NULL){
        c++;
        ptr=ptr->next;
    }
    if(c==1){
        ptr=start_lib;
        start_lib=NULL;
        free(ptr);
    }else if(start_lib->id==id){
        ptr=start_lib;
        start_lib=start_lib->next;
        free(ptr);
    }else{
        ptr=start_lib;
        while(ptr->id!=id){
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
    }
    return start_lib;
}

struct book *add_book(char bookname[30],char authorname[30],int id){
    struct book *ptr,*new_book;
    new_book=(struct book *)malloc(sizeof(struct book));
    strcpy_s(new_book->name,bookname);
    strcpy_s(new_book->author,authorname);
    new_book->id=id;
    new_book->next=NULL;
    if(start_lib==NULL){
        start_lib=new_book;
    }else{
        ptr=start_lib;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=new_book;
    }
    return start_lib;
}
