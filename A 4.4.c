#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 3
#define BALANCE_THRESHOLD 100

struct customer {
    int account_no;
    char name[50];
    float balance;
};

void print_customers_with_low_balance(struct customer customers[], int num_customers);

int main() {
    struct customer customers[MAX_CUSTOMERS];
    int i;

   
    for (i = 0; i < MAX_CUSTOMERS; i++) {
        printf("Enter details for customer %d:\n", i+1);
        printf("Account no: ");
        scanf("%d", &customers[i].account_no);
        printf("Name: ");
        scanf("%s", customers[i].name);
        printf("Balance: ");
        scanf("%f", &customers[i].balance);
    }

   
    printf("\nCustomers with balance less than Rs. %d:\n", BALANCE_THRESHOLD);
    print_customers_with_low_balance(customers, MAX_CUSTOMERS);

    return 0;
}

void print_customers_with_low_balance(struct customer customers[], int num_customers) {
    int i;

    for (i = 0; i < num_customers; i++) {
        if (customers[i].balance < BALANCE_THRESHOLD) {
            printf("Account no: %d, Name: %s\n", customers[i].account_no, customers[i].name);
        }
    }
}

