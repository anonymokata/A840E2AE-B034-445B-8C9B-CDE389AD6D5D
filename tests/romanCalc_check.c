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

Suite * rome_suite(void)
{
  Suite *s;
  TCase *tc_parse_num;

  s = suite_create("This is Rome!");
  tc_parse_num = tcase_create("Parse Numbers Test");

  tcase_add_test(tc_parse_num, test_numeral_parse);
  suite_add_tcase(s, tc_parse_num);

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