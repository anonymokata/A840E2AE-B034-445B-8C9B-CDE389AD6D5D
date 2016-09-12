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
  ck_assert_int_eq(parseRomeNum("XVI"), 16);
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

Suite * rome_suite(void)
{
  Suite *s;
  TCase *tc_parse_num, *tc_parse_whole_num, *tc_add_test, *tc_sub_test;

  s = suite_create("This is Rome!");
  tc_parse_num = tcase_create("Parse Numbers Test");
  tc_parse_whole_num = tcase_create("Parse Whole Numbers Test");
  tc_add_test = tcase_create("Addition Test");
  tc_sub_test = tcase_create("Subtraction Test");


  tcase_add_test(tc_parse_num, test_numeral_parse);
  tcase_add_test(tc_parse_whole_num, test_whole_number_parse);
  tcase_add_test(tc_add_test, test_add_numerals);
  tcase_add_test(tc_sub_test, test_sub_numerals);
  
  suite_add_tcase(s, tc_parse_num);
  suite_add_tcase(s, tc_parse_whole_num);
  suite_add_tcase(s, tc_add_test);
  suite_add_tcase(s, tc_sub_test);

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
