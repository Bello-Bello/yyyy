#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
        double loan, interest;
        int time, i;
        double loan_1, rate;
        double d, loan_2, f;

        if(argc < 4) {
                printf("Invalid number of command line arguments!");
                return 1;
                }
        loan = atof(argv[1]);
        interest = atof(argv[2]);
        time = atoi(argv[3]);
        rate = interest / 1200;
        loan_1  = loan * ((rate * pow(1 + rate, time)) / (pow(1 + rate, time) - 1));
        loan_2  = loan;
        printf("\nMontly payment should be %lf\n", loan_1 - loan_2 * rate);
        for (i = 0; i < 24; i++)
        printf("=");
        printf("AMORTIZATION SCHEDULE");
        for (i = 0; i < 24; i++)
        printf("=");
        printf("\n");
        printf("# \t Payment \t Principal \t Interest \t Balance\n");
        for (i = 1; i <= time; i++) {
                d = loan_2 * rate;
                f = loan_1 - d;
                loan_2 = loan_2 - f;
                printf("%d \t $%0.2lf \t $%0.2lf \t $%0.2lf ", i, loan_1, f, d);
                if (d / 10.0 < 1.0)
                printf("\t\t $%0.2lf", loan_2);
                else
                printf("\t $%0.2lf", loan_2);
                printf("\n");
        }
        return 0;
}