#include <check.h>
#include <stdlib.h>
#include "../src/romanCalc.h"

START_TEST(test_numeral_parse)
{
  ck_assert_int_eq(parseRomeNum("I"), 1);
  ck_assert_int_eq(parseRomeNum("V"), 5);
  ck_assert_int_eq(parseRomeNum("X"), 10);
  ck_assert_int_eq(parseRomeNum("L"), 50);
  ck_assert_int_eq(parseRomeNum("C"), 100);
  ck_assert_int_eq(parseRomeNum("D"), 500);
  ck_assert_int_eq(parseRomeNum("M"), 1000);
}
END_TEST

START_TEST(test_whole_number_parse)
{
  ck_assert_int_eq(parseRomeNum("III"), 3);
  ck_assert_int_eq(parseRomeNum("XIV"), 14);
  ck_assert_int_eq(parseRomeNum("xvi"), 16);
  ck_assert_int_eq(parseRomeNum("MMMCMXCIX"), 3999);
}
END_TEST

START_TEST(test_add_numerals)
{
  ck_assert_int_eq(addNumbers("V","V"), 10);
  ck_assert_int_eq(addNumbers("XX","XIV"), 34);
}
END_TEST

START_TEST(test_sub_numerals)
{
  ck_assert_int_eq(subNumbers("V","V"), 0);
  ck_assert_int_eq(subNumbers("XX","XIV"), 6);
  ck_assert_int_eq(subNumbers("XIV","XX"), -6);
}
END_TEST

START_TEST(test_int_to_numeral)
{
  char test[100];

  parseIntNum(3,test);
  ck_assert_str_eq(test, "III");
  parseIntNum(14,test);
  ck_assert_str_eq(test, "XIV");
  parseIntNum(16,test);
  ck_assert_str_eq(test, "XVI");
  parseIntNum(3999,test);
  ck_assert_str_eq(test, "MMMCMXCIX");
  parseIntNum(4000,test);
  ck_assert_str_eq(test, "No true Roman would use a number that large");
}
END_TEST

START_TEST(test_final_functionality)
{
  char test[100];

  char test1[] = "X + V";
  char test2[] = "X-IV";
  char test3[] = "\"dxi\" +\"XIV\"";

  strcpy(test, test1);
  romanMath(test);
  ck_assert_str_eq(test, "XV");
  strcpy(test, test2);
  romanMath(test);
  ck_assert_str_eq(test, "VI");
  strcpy(test, test3);
  romanMath(test);
  ck_assert_str_eq(test, "DXXV");
}
END_TEST

Suite * rome_suite(void)
{
  Suite *s;
  TCase *tc_parse_num, *tc_parse_whole_num, *tc_add_test, *tc_sub_test, *tc_int_to_num, *tc_final;

  s = suite_create("This is Rome!");
  tc_parse_num = tcase_create("Parse Numbers Test");
  tc_parse_whole_num = tcase_create("Parse Whole Numbers Test");
  tc_add_test = tcase_create("Addition Test");
  tc_sub_test = tcase_create("Subtraction Test");
  tc_int_to_num = tcase_create("Int to Numeral Test");
  tc_final = tcase_create("Final functionality Test");


  tcase_add_test(tc_parse_num, test_numeral_parse);
  tcase_add_test(tc_parse_whole_num, test_whole_number_parse);
  tcase_add_test(tc_add_test, test_add_numerals);
  tcase_add_test(tc_sub_test, test_sub_numerals);
  tcase_add_test(tc_int_to_num, test_int_to_numeral);
  tcase_add_test(tc_final, test_final_functionality);
  
  
  suite_add_tcase(s, tc_parse_num);
  suite_add_tcase(s, tc_parse_whole_num);
  suite_add_tcase(s, tc_add_test);
  suite_add_tcase(s, tc_sub_test);
  suite_add_tcase(s, tc_int_to_num);
  suite_add_tcase(s, tc_final);

  return s;
}

int main(void)
{
  int failed;
  Suite *s;
  SRunner *sr;

  s = rome_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
