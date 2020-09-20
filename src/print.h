#ifndef PRINT_H

#define PRINT_H

#define PRINT_TABLE_HEAD                                                                                                  \
	printf("--------------------------------------------------------------------------------------------------------\n"); \
	printf("|Operator|         Tarif name         | Minutes |Minutes for intercity|Internet GB|     SMS     | Cost |\n"); \
	printf("--------------------------------------------------------------------------------------------------------\n");

void Print_Tariff(service* tariff, int quantity_tariff);

#endif