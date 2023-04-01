#include <stdio.h>


union Data {
    int intValue;
    float floatValue;
};

int main() {
    union Data data; 

    printf("Enter an integer or float value: ");
    if (scanf("%d", &data.intValue) == 1) { 
        printf("The value you entered is an integer: %d\n", data.intValue);
    }
    else if (scanf("%f", &data.floatValue) == 1) { 
        printf("The value you entered is a float: %f\n", data.floatValue);
    }
    else { 
        printf("Invalid input.\n");
    }

    return 0;
}

