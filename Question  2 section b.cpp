#include <stdio.h>

int main() {
    float hours, rate, gross_pay, tax, net_pay;

    // Input hours worked and hourly rate
    printf("Enter hours worked in a week: ");
    scanf("%f", &hours);
    printf("Enter hourly wage: ");
    scanf("%f", &rate);

    // Calculate gross pay
    if (hours <= 40)
        gross_pay = hours * rate;
    else
        gross_pay = (40 * rate) + ((hours - 40) * rate * 1.5);

    // Calculate taxes
    if (gross_pay <= 600)
        tax = 0.15 * gross_pay;
    else
        tax = (0.15 * 600) + (0.20 * (gross_pay - 600));

    // Calculate net pay
    net_pay = gross_pay - tax;

    // Output results
    printf("\nGross Pay: $%.2f", gross_pay);
    printf("\nTaxes: $%.2f", tax);
    printf("\nNet Pay: $%.2f\n", net_pay);

    return 0;
}