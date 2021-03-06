#include "find.h"
#include "print.h"
#include "read_tariff.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    service* tariff = NULL;
    char* file_name = FILE_NAME;
    int quantity_tariff = 0;
    int error_flag = 0b0;
    error_flag = (error_flag | Fill_Data_Tariff(file_name, &tariff, &quantity_tariff));
    error_flag = (error_flag | Find_Suitable_Tariff(&tariff, &quantity_tariff));
    Print_Tariff(tariff, quantity_tariff);
    return error_flag;
}