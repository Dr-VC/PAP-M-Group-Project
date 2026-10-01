#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100
#define STR_LEN 50

typedef struct {
    int id;
    char name[STR_LEN];
    char email[STR_LEN];
    char phone[STR_LEN];
    char location[STR_LEN];
} Supplier;

extern Supplier suppliers[MAX_SUPPLIERS];
extern int supplierCount;

void addSupplier(void);
void displaySuppliers(void);
void searchSupplier(void);
void supplierMenu(void);

#endif