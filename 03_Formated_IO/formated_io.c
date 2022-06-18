#include <stdio.h>

#define CHAPTER_CHAR "3"
#define PROJECT_NAME "formated IO"
#define SUCCESS 0
#define ERROR 1

void clear_input(void) {
    while ( getchar() != '\n' );
    return;
}

void date_format() {
    int retval = ERROR;
    int m = 0;
    int d = 0;
    int y = 0;
    printf("\tExercise 1: Format Date\n");
    printf("Enter a date in mm/dd/yyyy format: ");
    retval = scanf_s("%2d/%2d/%4d", &m, &d, &y);
    clear_input();
    printf("y: %d\nm: %d\nd: %d\n", y, m, d);
    printf("RetVal: %d\n", retval);
    if (retval == 3) {
        printf("Corrected date: %d%02d%02d\n", y, m, d);
    }
    else {
        printf("Error\n");
    }
    return;
}


void product() {
    printf("\tExercise 2: Product entry\n");
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
    void (*projects[])() = {date_format, product, book, phone_number, number_thing, addfrac};
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
