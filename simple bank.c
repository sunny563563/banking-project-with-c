#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Bank Account
struct BankAccount {
    int accountNumber;
    char name[50];
    float balance;
};

// Function prototypes
void createAccount(struct BankAccount *acc);
void deposit(struct BankAccount *acc, float amount);
void withdraw(struct BankAccount *acc, float amount);
void displayAccount(struct BankAccount acc);

int main() {
    struct BankAccount account;
    int choice;
    float amount;

    printf("?? Simple Banking System in C\n");
    createAccount(&account);

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Display Account\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(&account, amount);
                break;

            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(&account, amount);
                break;

            case 3:
                displayAccount(account);
                break;

            case 4:
                printf("Thank you for using our Banking System!\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function Definitions
void createAccount(struct BankAccount *acc) {
    printf("Enter Account Number: ");
    scanf("%d", &acc->accountNumber);
    printf("Enter Account Holder Name: ");
    scanf("%s", acc->name);
    acc->balance = 0.0;
    printf("? Account Created Successfully!\n");
}

void deposit(struct BankAccount *acc, float amount) {
    if (amount > 0) {
        acc->balance += amount;
        printf("? Deposited: %.2f | New Balance: %.2f\n", amount, acc->balance);
    } else {
        printf("? Invalid amount!\n");
    }
}

void withdraw(struct BankAccount *acc, float amount) {
    if (amount > 0 && amount <= acc->balance) {
        acc->balance -= amount;
        printf("? Withdrawn: %.2f | Remaining Balance: %.2f\n", amount, acc->balance);
    } else {
        printf("? Insufficient Balance or Invalid amount!\n");
    }
}

void displayAccount(struct BankAccount acc) {
    printf("\n--- Account Details ---\n");
    printf("Account Number : %d\n", acc.accountNumber);
    printf("Account Holder : %s\n", acc.name);
    printf("Balance        : %.2f\n", acc.balance);
}

