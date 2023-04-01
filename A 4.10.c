#include <stdio.h>

#define PI 3.14159265358979323846

typedef union {
    double radius;
    struct {
        double length;
        double width;
    } rectangle;
} shape;

int main() {
    char choice;
    shape s;
    double area;

    printf("Calculate area of a circle or a rectangle? (c/r) ");
    scanf("%c", &choice);

    if (choice == 'c') {
        printf("Enter radius: ");
        scanf("%lf", &s.radius);

        area = PI * s.radius * s.radius;
    } else if (choice == 'r') {
        printf("Enter length: ");
        scanf("%lf", &s.rectangle.length);

        printf("Enter width: ");
        scanf("%lf", &s.rectangle.width);

        area = s.rectangle.length * s.rectangle.width;
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Area: %lf\n", area);

    return 0;
}

