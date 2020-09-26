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

CTEST(FIND, CHECK_CHOICE_COMPANY)
{
    service preferences;
    ASSERT_EQUAL(3,Choice_Company(&preferences, '1'));
    ASSERT_EQUAL(7,Choice_Company(&preferences, '2'));
    ASSERT_EQUAL(7,Choice_Company(&preferences, '3'));
    ASSERT_EQUAL(5,Choice_Company(&preferences, '4'));
    ASSERT_EQUAL(1,Choice_Company(&preferences, '5'));
    ASSERT_EQUAL(1,Choice_Company(&preferences, 'g'));
}

CTEST(READ_TARIFF, CHECK_OPEN_FILE)
{
    service* tariff = NULL;
    int quantity_tariff = 0;
    ASSERT_EQUAL(ERROR_OPEN_TARIFF_BASE, Fill_Data_Tariff(NULL, &tariff, &quantity_tariff));
    ASSERT_EQUAL(0,Fill_Data_Tariff(FILE_NAME, &tariff, &quantity_tariff));
}