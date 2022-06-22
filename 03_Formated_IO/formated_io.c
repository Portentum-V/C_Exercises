#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHAPTER_CHAR "3"
#define PROJECT_NAME "formated IO"
#define SUCCESS 0
#define ERROR 1


void clear_input(void) {
    while ( getchar() != '\n' );
    return;
}

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

int string_date(struct Date *date, char **str_date) {
    int size = 0;
    size = snprintf(NULL, 0, "%d%02d%02d", date->year, date->month, date->day);
    size++;
    *str_date = (char *)malloc(size);
    memset(*str_date, 0, size);
    snprintf(*str_date, size, "%d%02d%02d", date->year, date->month, date->day);
    return size;
}

int date_format(struct Date *date) {
    int retval = ERROR;
    retval = scanf_s("%2d/%2d/%4d", &date->month, &date->day, &date->year);
    clear_input();
    if (retval == 3) {
        retval = SUCCESS;
    }
    return retval;
}

void reformat_date() {
    int retval = ERROR;
    char *str_date = NULL;
    Date date;
    date.day = 0;
    date.month = 0;
    date.year = 0;
    printf("\tExercise 1: Format Date\n");
    printf("Enter a date in mm/dd/yyyy format: ");
    retval = date_format(&date);
    if (retval == ERROR) {
        printf("Error!\n");
        goto EXIT;
    }
    printf("Year: %d\nMonth: %d\nDay: %d\n", date.year, date.month, date.day);
    string_date(&date, &str_date);
    printf("Corrected date: %s", str_date);
EXIT:
    return;
}


void product() {
    printf("\tExercise 2: Product entry\n");
    int retval = ERROR;
    int item = 0;
    float price = 0.0f;
    char *str_date = NULL;
    Date date = {0};
    printf("Enter item number: ");
    scanf_s("%d", &item);
    clear_input();
    printf("Enter unit price: ");
    scanf_s("%f", &price);
    clear_input();
    printf("Enter purchase date: ");
    retval = date_format(&date);
    if (retval != SUCCESS) {
        printf("Error!\n");
        goto EXIT;
    }
    string_date(&date, &str_date);
    printf("Item\tUnit\tPurchase\n");
    printf("\tPrice\tDate\n");
    printf("%d\t%.02f\t%s\t\n", item, price, str_date);
EXIT:
    return;
}

typedef struct Book {
    short prefix;       /* 3 digits: 978 or 979 */
    short registration; /* 1-5 digits */
    int registrant;     /* Up to 7 digits */
    int publication;    /* Up to 6 digits */
    short check;        /* Modulus 10 */
} Book;

void print_book(Book *book) {
    printf("Prefix (3 digits): %hu\n", book->prefix);
    printf("Registration group (1-5 digits): %hu\n", book->registration);
    printf("Registrant (Up to 7 digits): %u\n", book->registrant);
    printf("Publication (Up to 6 digits): %u\n", book->publication);
    printf("Check digit (Final single digit): %hu\n", book->check);
    return;
}

void book() {
    Book book = {0};
    printf("\tExercise 3: Book entry\n");
    printf("Enter ISBN: ");
    scanf_s("%3hu%*c%5hu%*c%7u%*c%6u%*c%1hu", &book.prefix, &book.registration, &book.registrant, &book.publication, &book.check);
    clear_input();
    print_book(&book);
    return;
}

void phone_number() {
    short area = 0;
    short pre = 0;
    short post = 0;
    printf("\tExercise 4: Phone Number\n");
    printf("Enter phone number [(XXX) XXX-XXXX]: ");
    scanf_s("(%3hu) %3hu-%4hu", &area, &pre, &post);
    clear_input();
    printf("Standardized: %hu.%hu.%hu\n", area, pre, post);
    return;
}

void number_thing() {
    printf("\tExercise 5: 16 numbers\n");
    
    return;
}

void addfrac() {
    int num1, denom1, num2, denom2, result_num, result_denom;
    printf("\tExercise 6: Fractions\n");
    printf("Enter first fraction: ");
    scanf("%d/%d", &num1, &denom1);
    printf("Enter second fraction: ");
    scanf("%d/%d", &num2, &denom2);
    result_num = num * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;
    printf("Sum: %d/%d\n", result_num, result_denom);
    return 0;
}

int menu() {
    int retval = ERROR;
    int selection = 0;
    void (*projects[])() = {reformat_date, product, book, phone_number, number_thing, addfrac};
    int size = sizeof(projects) / sizeof(projects[0]); 
    printf("\n- Menu -\n");
    printf("0 - Format Date\n");
    printf("1 - Product entry\n");
    printf("2 - Book entry\n");
    printf("3 - Phone number\n");
    printf("4 - 16 numbers\n");
    printf("5 - Add Fractions\n");
    printf("6 - Exit\n");
    printf("Selection: ");
    scanf_s(" %d", &selection);
    clear_input();
    if (selection < size) {
        projects[selection]();
        retval = SUCCESS;
    }
    else {
        printf("We are done here\n");
    }
    return retval;
}


int main(int argc, char **argv) {
    int retval = 0;
    if(argc != 1) {
        printf("%s takes no arguments.\n", argv[0]);
        return 1;
    }
    printf("Back to Basics: KNK chapter %s %s.\n", CHAPTER_CHAR, PROJECT_NAME);
    do {
        retval = menu();
    } while (retval != ERROR);

    return 0;
}
