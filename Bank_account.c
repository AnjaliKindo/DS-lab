#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int acno;
    char name[50];
    float balance;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void create(int n) {
    struct node *temp, *ptr;
    int i;
    for (i = 0; i < n; i++) {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter account number: ");
        scanf("%d", &temp->acno);
        printf("Enter name: ");
        scanf("%s", temp->name);
        printf("Enter balance: ");
        scanf("%f", &temp->balance);
        temp->next = NULL;
        temp->prev = NULL;
        if (head == NULL)
            head = temp;
        else {
            ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = temp;
            temp->prev = ptr;
        }
    }
}

float total_balance() {
    struct node *temp = head;
    float total = 0;
    while (temp != NULL) {
        total += temp->balance;
        temp = temp->next;
    }
    return total;
}

void display_all() {
    struct node *temp = head;
    printf("All Account Details:");
    printf("AC No	Name		Balance");
    while (temp != NULL) {
        printf("%d	%s		%.2f", temp->acno, temp->name, temp->balance);
        temp = temp->next;
    }
}

int main() {
    int n;
    printf("Enter number of accounts: ");
    scanf("%d", &n);
    create(n);
    display_all();
    printf("Total balance of all accounts: %.2f", total_balance());
    return 0;
}