#include <stdio.h>
#include <string.h>
#include "assets.h"

Asset assets[MAX_ASSETS];
int assetCount = 0;

static void cleanNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') str[len - 1] = '\0';
}

void addAsset(void) {
    if (assetCount >= MAX_ASSETS) {
        printf("\n[ERROR] Asset register full.\n");
        return;
    }
    Asset a;
    printf("\nEnter Asset ID: ");
    scanf("%d", &a.id);
    getchar();

    printf("Enter Asset Name: ");
    fgets(a.name, STR_LEN, stdin);
    cleanNewline(a.name);

    printf("Enter Asset Type (Vehicle/Building/Computer/etc.): ");
    fgets(a.type, STR_LEN, stdin);
    cleanNewline(a.type);

    do {
        printf("Enter Purchase Value (N$): ");
        scanf("%lf", &a.purchaseValue);
        if (a.purchaseValue < 0) printf("[VALIDATION] Value cannot be negative!\n");
    } while (a.purchaseValue < 0);
    getchar();

    printf("Enter Department: ");
    fgets(a.department, STR_LEN, stdin);
    cleanNewline(a.department);

    printf("Enter Condition (Good/Fair/Poor): ");
    fgets(a.condition, STR_LEN, stdin);
    cleanNewline(a.condition);

    assets[assetCount++] = a;
    printf("[SUCCESS] Asset registered in register.\n");
}

void displayAssets(void) {
    if (assetCount == 0) {
        printf("\nNo assets registered.\n");
        return;
    }
    printf("\n%-5s %-20s %-15s %-15s %-15s %-10s\n", "ID", "Name", "Type", "Value(N$)", "Department", "Condition");
    printf("------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < assetCount; i++) {
        printf("%-5d %-20s %-15s %-15.2f %-15s %-10s\n",
               assets[i].id, assets[i].name, assets[i].type, assets[i].purchaseValue, assets[i].department, assets[i].condition);
    }
}

void searchAsset(void) {
    if (assetCount == 0) {
        printf("\nNo assets available.\n");
        return;
    }
    char query[STR_LEN];
    int found = 0;
    getchar();
    printf("\nEnter Asset Name or Department to search: ");
    fgets(query, STR_LEN, stdin);
    cleanNewline(query);

    for (int i = 0; i < assetCount; i++) {
        if (strstr(assets[i].name, query) != NULL || strcmp(assets[i].department, query) == 0) {
            printf("\nFound -> ID: %d | Name: %s | Value: N$%.2f | Condition: %s\n",
                   assets[i].id, assets[i].name, assets[i].purchaseValue, assets[i].condition);
            found = 1;
        }
    }
    if (!found) printf("No matching assets found.\n");
}

void assetMenu(void) {
    int choice;
    do {
        printf("\n=== ASSET MANAGEMENT ===\n");
        printf("1. Add Asset\n");
        printf("2. Display Asset Register\n");
        printf("3. Search Assets\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addAsset(); break;
            case 2: displayAssets(); break;
            case 3: searchAsset(); break;
            case 4: break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);
}