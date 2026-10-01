#include <stdio.h>
#include <string.h>
#include "suppliers.h"

Supplier suppliers[MAX_SUPPLIERS];
int supplierCount = 0;

static void cleanNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') str[len - 1] = '\0';
}

void addSupplier(void) {
    if (supplierCount >= MAX_SUPPLIERS) {
        printf("\n[ERROR] Supplier list full.\n");
        return;
    }
    Supplier s;
    printf("\nEnter Supplier ID: ");
    scanf("%d", &s.id);
    getchar();

    printf("Enter Supplier Name: ");
    fgets(s.name, STR_LEN, stdin);
    cleanNewline(s.name);

    printf("Enter Email: ");
    fgets(s.email, STR_LEN, stdin);
    cleanNewline(s.email);

    printf("Enter Phone: ");
    fgets(s.phone, STR_LEN, stdin);
    cleanNewline(s.phone);

    printf("Enter Town/Location: ");
    fgets(s.location, STR_LEN, stdin);
    cleanNewline(s.location);

    suppliers[supplierCount++] = s;
    printf("[SUCCESS] Supplier registered successfully.\n");
}

void displaySuppliers(void) {
    if (supplierCount == 0) {
        printf("\nNo suppliers registered.\n");
        return;
    }
    printf("\n%-5s %-20s %-25s %-15s %-15s\n", "ID", "Name", "Email", "Phone", "Location");
    printf("-------------------------------------------------------------------------------------\n");
    for (int i = 0; i < supplierCount; i++) {
        printf("%-5d %-20s %-25s %-15s %-15s\n",
               suppliers[i].id, suppliers[i].name, suppliers[i].email, suppliers[i].phone, suppliers[i].location);
    }
}

void searchSupplier(void) {
    if (supplierCount == 0) {
        printf("\nNo suppliers available to search.\n");
        return;
    }
    char query[STR_LEN];
    int found = 0;
    getchar();
    printf("\nEnter Supplier Name or Town to search: ");
    fgets(query, STR_LEN, stdin);
    cleanNewline(query);

    for (int i = 0; i < supplierCount; i++) {
        if (strstr(suppliers[i].name, query) != NULL || strcmp(suppliers[i].location, query) == 0) {
            printf("\nFound -> ID: %d | Name: %s | Location: %s | Phone: %s\n",
                   suppliers[i].id, suppliers[i].name, suppliers[i].location, suppliers[i].phone);
            found = 1;
        }
    }
    if (!found) printf("No matching supplier found.\n");
}

void supplierMenu(void) {
    int choice;
    do {
        printf("\n=== SUPPLIER MANAGEMENT ===\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search/Compare Supplier\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addSupplier(); break;
            case 2: displaySuppliers(); break;
            case 3: searchSupplier(); break;
            case 4: break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);
}