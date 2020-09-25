#ifndef PRINT_H

#define PRINT_H

#include "read_tariff.h"

#define PRINT_TABLE_HEAD                                                       \
    printf("-----------------------------------------------------------------" \
           "--------------------------------\n");                              \
    printf("Operator;Tarif name;Free minutes;Free minutes for intercity;Free " \
           "internet GB;Free SMS;Tariff cost\n");                              \
    printf("-----------------------------------------------------------------" \
           "--------------------------------\n");

void Print_Tariff(service* tariff, int quantity_tariff);

#endif