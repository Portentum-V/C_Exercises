#include <stdio.h>

#define CHAPTER_CHAR "2"
#define PROJECT_NAME "fundamentals"

void print_checkmark() {
    printf("\n\tExercise 1: Checkmark\n");
    printf("       *\n");
    printf("      *\n");
    printf("     *\n");
    printf("*   *\n");
    printf(" * *\n");
    printf("  *\n");    
    return;
}

float _sv(float radius) {
    const float PI = 3.141593f;
    const float FR = 4.0f/3.0f;
    const float R3 = radius * radius * radius;
    float result = FR * PI * R3;
    return result;
}

void sphere_volume() {
    float radius = 0.0f;
    printf("\n\tExercise 3: Enter the radius of a sphere and return volume\n");
    printf("Enter radius: ");
    scanf_s("%f", &radius);
    printf("A sphere with a radius of %f has a volume of %f\n", radius, _sv(radius));
    return;
}

void tax() {
    float amount = 0.0f;
    float tax = 1.05f;
    printf("\n\tExercise 4: Enter a dollar amount and add 5%% tax\n");
    printf("Amount: $");
    scanf_s("%f", &amount);
    printf("Amount with tax: $%.2f\n", amount * tax);
    return;
}

int power(int base, unsigned int exponent) {
    int temp = 0;
    if (exponent == 0)
        return 1;
    else if (exponent % 2) /* Not divisable by two */
        return base * power(base, exponent - 1);
    else {
        temp = power(base, exponent / 2);
        return temp * temp;
    }
}

void polynomial() {
    /* 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 */
    int x = 0;
    int result = 0;
    printf("\n\tExercise 5: Return 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6\n");
    printf("Int X: ");
    scanf_s("%d", &x);
    result  = 3 * power(x, 5);
    result += 2 * power(x, 4);
    result -= 5 * power(x, 3);
    result -= x * x;
    result += 7 * x - 6;
    printf("Result: %d\n", result);
    return;
}

void horners() {
    /* ((((3x + 2)x - 5)x - 1)x + 7) - 6 */
    int x = 0;
    int result = 0;
    printf("\n\tExercise 6: Return ((((3x + 2)x - 5)x - 1)x + 7) - 6\n");
    printf("Int X: ");
    scanf_s("%d", &x);
    result = 3*x + 2;
    result = result * x - 5;
    result = result * x - 1;
    result = result * x + 7;
    result = result * x - 6;
    printf("Result: %d\n", result);
    return;
}

void least_bills() {
    int x = 0;
    int twenty = 0;
    int ten = 0;
    int five = 0;
    printf("\n\tExercise 7: Least number of 20, 10, 5, and 1 increments to meet input\n");
    printf("Input whole dollar amount: $");
    scanf_s("%d", &x);
    twenty = x - (x % 20);
    x -= twenty;
    ten = x - (x % 10);
    x -= ten;
    five = x - (x % 5);
    x -= five;
    printf("$20 bills: %d\n", twenty / 20);
    printf("$10 bills: %d\n", ten / 10);
    printf(" $5 bills: %d\n", five / 5);
    printf(" $1 bills: %d\n", x);
    return;
}

void loan() {
    float loan = 0.0f;
    float rate = 0.0f;
    float pay = 0.0f;
    int count = 1;
    printf("\n\tExercise 8: Loan balance after 3 payments\n");
    printf("Loan amount: $");
    scanf_s("%f", &loan);
    printf("Interest rate: ");
    scanf_s("%f", &rate);
    printf("Monthly Payment: $");
    scanf_s("%f", &pay);

    do {
        loan -= pay;
        loan = loan * (1 + (rate / 100) / 12);
        printf("After month %d: $%.2f\n", count, loan);
    } while (++count < 4);
    return;
}

int main(int argc, char **argv) {
    if(argc != 1) {
        printf("%s takes no arguments.\n", argv[0]);
        return 1;
    }
    printf("Back to Basics: KNK chapter %s %s.\n", CHAPTER_CHAR, PROJECT_NAME);
    print_checkmark();
    printf("\n\tExercise 2:The volume of a 10m sphere: %f\n", _sv(10));
    sphere_volume();
    tax();
    polynomial();
    horners();
    least_bills();
    loan();
    return 0;
}
