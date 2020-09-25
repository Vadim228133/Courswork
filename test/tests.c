#include "ctest.h"
#include "find.h"

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