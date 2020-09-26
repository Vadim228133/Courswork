#include "read_tariff.h"

#include "stdio.h"
#include "stdlib.h"

int Fill_Data_Tariff(const char* file_name, service** tariff, int* quantity_tariff)
{
    FILE* file = NULL;
    char symbol_buffer = '0';
    file = fopen(file_name, READ_ONLY);
    if (file == NULL) {
        MESSEGE_ERROR_OPEN_TARIFF_BASE;
        return ERROR_OPEN_TARIFF_BASE;
    }
    fscanf(file, "%d", quantity_tariff);
    symbol_buffer = getc(file);
    *tariff = (service*)malloc(*quantity_tariff * sizeof(service));
    for (short int i = 0; i < *quantity_tariff; i++) {
        symbol_buffer = getc(file);
        for (short int j = 0; symbol_buffer != SEPARATOR; j++) {
            (*tariff)[i].company[j] = symbol_buffer;
            symbol_buffer = getc(file);
        }
        symbol_buffer = getc(file);
        for (short int j = 0; symbol_buffer != SEPARATOR; j++) {
            (*tariff)[i].name[j] = symbol_buffer;
            symbol_buffer = getc(file);
        }
        fscanf(file, "%d", &(*tariff)[i].minutes);
        symbol_buffer = getc(file);
        fscanf(file, "%d", &(*tariff)[i].minutes_intercity);
        symbol_buffer = getc(file);
        fscanf(file, "%f", &(*tariff)[i].internet);
        symbol_buffer = getc(file);
        fscanf(file, "%d", &(*tariff)[i].sms);
        symbol_buffer = getc(file);
        fscanf(file, "%d", &(*tariff)[i].cost);
        symbol_buffer = getc(file);
    }
    fclose(file);
    return 0;
}