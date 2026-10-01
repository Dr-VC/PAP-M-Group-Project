#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100
#define STR_LEN 50

typedef struct {
    int id;
    char name[STR_LEN];
    char type[STR_LEN];
    double purchaseValue;
    char department[STR_LEN];
    char condition[STR_LEN];
} Asset;

extern Asset assets[MAX_ASSETS];
extern int assetCount;

void addAsset(void);
void displayAssets(void);
void searchAsset(void);
void assetMenu(void);

#endif
