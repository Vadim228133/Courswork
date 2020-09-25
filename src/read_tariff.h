#ifndef READ_H

#define READ_H

#define ERROR_OPEN_TARIFF_BASE 0b00000001

#define MAX_SIZE_OPERATOR_NAME 7
#define MAX_SIZE_TARIFF_NAME 50

#define UNLIMITED -1

#define FILE_NAME "base/tariff_base.txt"
#define READ_ONLY "r"
#define SEPARATOR ';'

#define MESSEGE_ERROR_OPEN_TARIFF_BASE                                       \
    printf("Error: file tariff base dont open, cant read data about tariff " \
           "plains\n");

typedef struct service_package {
    char company[MAX_SIZE_OPERATOR_NAME];
    char name[MAX_SIZE_TARIFF_NAME];
    int minutes;
    int minutes_intercity;
    float internet;
    int sms;
    int cost;
} service;

int Fill_Data_Tariff(service** tariff, int* quantity_tariff);

#endif