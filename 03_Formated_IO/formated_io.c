#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHAPTER_CHAR "3"
#define PROJECT_NAME "formated IO"
#define SUCCESS 0
#define ERROR 1

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

void clear_input(void) {
    while ( getchar() != '\n' );
    return;
}

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
    printf("Enter unit price: ");
    scanf_s("%f", &price);
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

void book() {
    printf("\tExercise 3: Book entry\n");
    return;
}

void phone_number() {
    printf("\tExercise 4: Phone Number\n");
    return;
}

void number_thing() {
    printf("\tExercise 5: 16 numbers\n");
    return;
}

void addfrac() {
    printf("\tExercise 6: Fractions\n");
    return;
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
