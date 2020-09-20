#include "read_tariff.h"
#include "print.h"

#include <stdio.h>

void Print_Tariff(service* tariff, int quantity_tariff)
{
	printf("Quantity suitable tariff: %d\n",quantity_tariff);
	PRINT_TABLE_HEAD;
	for(short int i = 0; i < quantity_tariff; i++)
	{
		for(short int j = 0; j < MAX_SIZE_OPERATOR_NAME; j++)
		{
			printf("%c",tariff[i].company[j]);
		}
		printf("     ");
		for(short int j = 0; j < MAX_SIZE_TARIFF_NAME; j++)
		{
			printf("%c",tariff[i].name[j]);
		}
		printf("   ");
		printf("%6.1d",tariff[i].minutes);
		if(tariff[i].internet == -1) {
			printf("        unlimited");
		} else {
			printf("%17.1d",tariff[i].minutes_intercity);
		}
		if(tariff[i].internet == -1.0) {
			printf("        unlimited");
		} else {
			printf("%15.2f",tariff[i].internet);	
		}
		if(tariff[i].internet == -1) {
			printf("        unlimited");
		} else {
			printf("%10.1d",tariff[i].sms);	
		}
		printf("%7.d",tariff[i].cost);
		printf("\n");
	}
	printf("\n");
}