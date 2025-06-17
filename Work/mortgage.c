#include <stdio.h>

typedef struct 
{
    float principal;
    float rate;
    float payment;
    float total_paid;
    int month;
    int extra_payment_start_month;
    int extra_payment_end_month;
    int extra_payment;
} Mortgage;

void calculate(Mortgage mortgage);

Mortgage mortgage = {500000.0, 0.05, 2684.11, 0.0, 0, 61, 108, 1000};

int main(void)
{
    calculate(mortgage);
    return 0;
}

void calculate(Mortgage mortgage)
{
    while (mortgage.principal > mortgage.payment)
    {
        if (mortgage.month < mortgage.extra_payment_start_month || mortgage.month >= mortgage.extra_payment_end_month)
        {
            mortgage.principal = mortgage.principal * (1 + mortgage.rate / 12) - mortgage.payment;
            mortgage.total_paid += mortgage.payment;
        }
        else if (mortgage.month >= mortgage.extra_payment_start_month && 
                 mortgage.month < mortgage.extra_payment_end_month)
        {
            mortgage.principal = mortgage.principal * (1 + mortgage.rate / 12) - mortgage.payment - mortgage.extra_payment;
            mortgage.total_paid += mortgage.payment + mortgage.extra_payment;
        }
        mortgage.month++;
        printf("Month %d: Principal = %.2f, Total Paid = %.2f\n", 
                mortgage.month, mortgage.principal, mortgage.total_paid);
    }

    float last_payment = mortgage.principal * (1 + mortgage.rate / 12);
    mortgage.total_paid += last_payment; 
    mortgage.principal = 0.0; // Mortgage is paid off
    mortgage.month++;
    printf("Month %d: Final Payment = %.2f, Total Paid = %.2f\n", 
           mortgage.month, last_payment, mortgage.total_paid);
    return;
}