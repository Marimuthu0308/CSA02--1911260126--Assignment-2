
#include <stdio.h>

int main(void)
{
    double price, qty, gross, discount;
    double taxable, tax, total, net;
    int senior;

    printf("Enter price: ");
    scanf("%lf", &price);

    printf("Enter quantity: ");
    scanf("%lf", &qty);

    printf("Senior citizen? (1-Yes, 0-No): ");
    scanf("%d", &senior);

    gross = price * qty;

    if (senior == 1)
        discount = gross * 15.0 / 100.0;
    else
        discount = 0.0;

    taxable = gross - discount;
    tax = taxable * 5.0 / 100.0;

    total = taxable + tax;

    net = (total > 1000.0) ? total - 50.0 : total;

    printf("\nGross Amount = Rs. %.2f\n", gross);
    printf("Discount = Rs. %.2f\n", discount);
    printf("Taxable Amount = Rs. %.2f\n", taxable);
    printf("GST = Rs. %.2f\n", tax);
    printf("Total Amount = Rs. %.2f\n", total);
    printf("Net Amount = Rs. %.2f\n", net);

    return 0;
}

