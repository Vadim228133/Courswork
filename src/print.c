#include "print.h"
#include "read_tariff.h"

#include <stdio.h>

void Print_Tariff(service* tariff, int quantity_tariff)
{
    printf("Quantity suitable tariff: %d\n", quantity_tariff);
    PRINT_TABLE_HEAD;
    for (short int i = 0; i < quantity_tariff; i++) {
        for (short int j = 0; j < MAX_SIZE_OPERATOR_NAME; j++) {
            printf("%c", tariff[i].company[j]);
        }
        printf(";");
        for (short int j = 0; j < MAX_SIZE_TARIFF_NAME; j++) {
            printf("%c", tariff[i].name[j]);
        }
        printf(";");
        if (tariff[i].minutes == UNLIMITED) {
            printf("unlimited;");
        } else {
            printf("%4.1d;", tariff[i].minutes);
        }
        if (tariff[i].minutes_intercity == UNLIMITED) {
            printf("unlimited;");
        } else {
            printf("%4.1d;", tariff[i].minutes_intercity);
        }
        if (tariff[i].internet == UNLIMITED) {
            printf("unlimited;");
        } else {
            printf("%4.2f;", tariff[i].internet);
        }
        if (tariff[i].sms == UNLIMITED) {
            printf("unlimited;");
        } else {
            printf("%4.1d;", tariff[i].sms);
        }
        printf("%4.1d\n", tariff[i].cost);
    }
    printf("\n");
}