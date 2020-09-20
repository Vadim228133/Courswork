#include "read_tariff.h"

#include "stdio.h"
#include "stdlib.h"

int Fill_Data_Tariff(service** tariff, int* quantity_tariff)
{
	FILE* file = NULL;
	service* buffer = NULL;
	char symbol_buffer = '0';
	file = fopen(FILE_NAME,READ_ONLY);
	if(file == NULL)
	{
		MESSEGE_ERROR_OPEN_TARIFF_BASE;
		return ERROR_OPEN_TARIFF_BASE;
	}
	fscanf(file,"%d",quantity_tariff);
	buffer = (service*) calloc (*quantity_tariff, sizeof(service));
	for(short int i = 0; i < *quantity_tariff; i++)
	{
		symbol_buffer = getc(file);
		for(short int j = 0; symbol_buffer != SEPARATOR; j++)
		{
			buffer[i].company[j] = symbol_buffer;
			symbol_buffer = getc(file);
		}
		symbol_buffer = getc(file);
		for(short int j = 0; symbol_buffer != SEPARATOR; j++)
		{
			buffer[i].name[j] = symbol_buffer;
			symbol_buffer = getc(file);
		}
		fscanf(file,"%d",&buffer[i].minutes);
		symbol_buffer = getc(file);
		fscanf(file,"%d",&buffer[i].minutes_intercity);
		symbol_buffer = getc(file);
		fscanf(file,"%f",&buffer[i].internet);
		symbol_buffer = getc(file);
		fscanf(file,"%d",&buffer[i].sms);
		symbol_buffer = getc(file);
		fscanf(file,"%d",&buffer[i].cost);
	}
	*tariff = buffer;
	return 0;
}