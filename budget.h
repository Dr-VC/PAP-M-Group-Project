#ifndef BUDGET_H
#define BUDGET_H

#define MAX_BUDGETS 50
#define STR_LEN 50

typedef struct {
    char department[STR_LEN];
    double allocatedBudget;
    double expenditure;
    double remainingBudget;
    int isOverBudget; // 0 = Within, 1 = Exceeded
} Budget;

extern Budget budgets[MAX_BUDGETS];
extern int budgetCount;

void addBudget(void);
void addExpenditure(void);
void displayBudgets(void);
void calculateBudgetStatus(void);
void budgetMenu(void);

#endif