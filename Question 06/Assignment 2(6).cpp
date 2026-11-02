
#include <stdio.h>

int main(void)
{
    double balance = 10000.0;
    double rate = 2.0;
    double repayment = 2000.0;

    double interest, payment;
    double totalInterest = 0.0;
    double openingBalance;

    int month = 0;
    int limit = 360;

    printf("Month\tOpening\t\tInterest\tPayment\t\tClosing\n");

    while (balance > 0.0 && month < limit)
    {
        openingBalance = balance;

        interest = balance * rate / 100.0;

        if (repayment <= interest)
        {
            printf("\nRepayment is not enough to reduce the loan.\n");
            break;
        }

        balance = balance + interest;
        totalInterest += interest;

        if (balance <= repayment)
            payment = balance;
        else
            payment = repayment;

        balance = balance - payment;

        if (balance < 0.005)
            balance = 0.0;

        month++;

        printf("%d\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",
               month, openingBalance, interest, payment, balance);
    }

    printf("\nTotal Months = %d\n", month);
    printf("Total Interest = Rs. %.2f\n", totalInterest);

    if (balance == 0.0)
        printf("Loan fully repaid.\n");
    else if (month >= limit)
        printf("Safety limit reached. Loan not fully repaid.\n");
    else
        printf("Loan is still outstanding.\n");

    return 0;
}

