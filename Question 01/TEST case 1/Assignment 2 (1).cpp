
#include <stdio.h>

int main()
{
    double price, qty;
    double gross, discount, taxable, tax;
    double total, net;
    int senior, count = 0;

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

    if (total > 1000)
        net = total - 50;
    else
        net = total;

    count++;

    printf("\nGross Amount = Rs. %.2f", gross);
    printf("\nDiscount = Rs. %.2f", discount);
    printf("\nTaxable Amount = Rs. %.2f", taxable);
    printf("\nGST = Rs. %.2f", tax);
    printf("\nTotal Amount = Rs. %.2f", total);
    printf("\nNet Amount = Rs. %.2f", net);
    printf("\nCount = %d\n", count);

    return 0;
}

