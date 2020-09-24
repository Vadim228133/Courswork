#ifndef FIND_H

#define FIND_H

#include "read_tariff.h"

#define NOT_IMPORTENT 'z'

int Equally_Company(
        char* preferences_company,
        char* tariff_company,
        int length_company_name);
int Find_Suitable_Tariff(service** tariff, int* quantity_tariff);
service Get_User_Preferences(service preferens, int* length_company_name);

#endif