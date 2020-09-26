#include "ctest.h"
#include "find.h"
#include "read_tariff.h"

CTEST(FIND, CHECK_EQUALLY_COMPANY)
{
    ASSERT_EQUAL(0,Equally_Company("aaa","bbb",3));
    ASSERT_EQUAL(0,Equally_Company("bbb","aaa",3));
    ASSERT_EQUAL(0,Equally_Company("aba","aaa",3));
    ASSERT_EQUAL(0,Equally_Company("aab","aaa",3));
    ASSERT_EQUAL(0,Equally_Company("aaa","bbbbbb",3));
    ASSERT_EQUAL(0,Equally_Company("aaaaa","aaa",5));
    ASSERT_EQUAL(1,Equally_Company("aaa","aaa",3));
    ASSERT_EQUAL(1,Equally_Company("aaa","aaaaa",3));
    ASSERT_EQUAL(1,Equally_Company("aaa","aaabbb",3));
}

CTEST(READ_TARIFF, CHECK_OPEN_FILE)
{
    service* tariff = NULL;
    int quantity_tariff = 0;
    ASSERT_EQUAL(ERROR_OPEN_TARIFF_BASE, Fill_Data_Tariff(NULL, &tariff, &quantity_tariff));
    ASSERT_EQUAL(0,Fill_Data_Tariff(FILE_NAME, &tariff, &quantity_tariff));
}