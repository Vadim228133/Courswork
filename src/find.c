#include "find.h"
#include "read_tariff.h"

#include <stdio.h>
#include <stdlib.h>

service Get_User_Preferences(service preferences, int* length_company_name)
{
    char key_preferens = '0';
    printf("Пожалуйста выберете желаемого оператора\n");
    printf("1) MTS\n");
    printf("2) Beeline\n");
    printf("3) Megafon\n");
    printf("4) Tele2\n");
    printf("Нажмите любую другую кнопку если оператор не имеет значения\n");
    scanf(" %c", &key_preferens);
    switch (key_preferens) {
    case ('1'): {
        preferences.company[0] = 'M';
        preferences.company[1] = 'T';
        preferences.company[2] = 'S';
        *length_company_name = 3;
        break;
    }
    case ('2'): {
        preferences.company[0] = 'B';
        preferences.company[1] = 'e';
        preferences.company[2] = 'e';
        preferences.company[3] = 'l';
        preferences.company[4] = 'i';
        preferences.company[5] = 'n';
        preferences.company[6] = 'e';
        *length_company_name = 7;
        break;
    }
    case ('3'): {
        preferences.company[0] = 'M';
        preferences.company[1] = 'e';
        preferences.company[2] = 'g';
        preferences.company[3] = 'a';
        preferences.company[4] = 'F';
        preferences.company[5] = 'o';
        preferences.company[6] = 'n';
        *length_company_name = 7;
        break;
    }
    case ('4'): {
        preferences.company[0] = 'T';
        preferences.company[1] = 'e';
        preferences.company[2] = 'l';
        preferences.company[3] = 'e';
        preferences.company[4] = '2';
        *length_company_name = 5;
        break;
    }
    default: {
        preferences.company[0] = NOT_IMPORTENT;
        break;
    }
    }
    printf("Пожалуйста введите желаемое количество бесплатных минут\n");
    scanf("%d", &preferences.minutes);
    printf("Пожалуйста введите желаемое количество бесплатных минут по "
           "межгороду\n");
    scanf("%d", &preferences.minutes_intercity);
    printf("Пожалуйста введите желаемое количество бесплатных гигабайт "
           "интернета\n");
    scanf("%f", &preferences.internet);
    printf("Пожалуйста введите желаемое количество бесплатных смс\n");
    scanf("%d", &preferences.sms);
    printf("Пожалуйста введите желаемую стоимость тарифа\n");
    scanf("%d", &preferences.cost);
    printf("\n");
    return preferences;
}

int Equally_Company(
        char* preferences_company,
        char* tariff_company,
        int length_company_name)
{
    for (short int i = 0; i < length_company_name; i++) {
        if (preferences_company[i] != tariff_company[i]) {
            return 0;
        }
    }
    return 1;
}

int Find_Suitable_Tariff(service** tariff, int* quantity_tariff)
{
    service* buffer = NULL;
    service preferences;
    int quantity_suitable_tariff = 0;
    int length_company_name = 0;
    buffer = (service*)malloc((*quantity_tariff) * sizeof(service));
    preferences = Get_User_Preferences(preferences, &length_company_name);
    for (short int i = 0; i < *quantity_tariff; i++) {
        char* temp = (*tariff)[i].company;
        if ((preferences.company[0] == NOT_IMPORTENT)
            || (Equally_Company(
                    preferences.company, temp, length_company_name))) {
            if (((*tariff)[i].minutes >= preferences.minutes)
                || ((*tariff)[i].minutes == UNLIMITED)) {
                if (((*tariff)[i].minutes_intercity
                     >= preferences.minutes_intercity)
                    || ((*tariff)[i].minutes_intercity == UNLIMITED)) {
                    if (((*tariff)[i].internet >= preferences.internet)
                        || ((*tariff)[i].internet == UNLIMITED)) {
                        if (((*tariff)[i].sms >= preferences.sms)
                            || ((*tariff)[i].sms == UNLIMITED)) {
                            if ((*tariff)[i].cost <= preferences.cost) {
                                buffer[quantity_suitable_tariff] = (*tariff)[i];
                                quantity_suitable_tariff++;
                            }
                        }
                    }
                }
            }
        }
    }
    free((*tariff));
    (*tariff) = NULL;
    (*tariff) = (service*)malloc(quantity_suitable_tariff * sizeof(service));
    for (short int i = 0; i < quantity_suitable_tariff; i++) {
        (*tariff)[i] = buffer[i];
    }
    free(buffer);
    buffer = NULL;
    *quantity_tariff = quantity_suitable_tariff;
    return 0;
}