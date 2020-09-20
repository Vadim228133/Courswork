#include "read_tariff.c"
#include "print.c"

#include <stdio.h>
#include <stdlib.h>

int main()
{
	service* tariff = NULL;
	int quantity_tariff = 0;
	int error_flag = 0b0;
	error_flag = Fill_Data_Tariff(&tariff, &quantity_tariff);
	Print_Tariff(tariff, quantity_tariff);
	return error_flag;
}