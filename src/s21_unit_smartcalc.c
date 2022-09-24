#include <check.h>
#include <limits.h>

#include "s21_smartcalc.h"

START_TEST(smartcalc_tests) {
    char *input_expression;
    long double result;
    int retu_valya;

    input_expression = ")cos)(17+4)*";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, FAIL);

    input_expression = "16*sin(2)";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, SUCCESS);

    input_expression = "3.5-acos(0.5))";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, FAIL);

    input_expression = "acos()";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, FAIL);

    input_expression = "1+2/(1";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, FAIL);

    input_expression = "sqrt(0.25)";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, SUCCESS);

    input_expression = "0+sqrt(0.25)";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, SUCCESS);

    input_expression = "-sqrt(0.25)";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, SUCCESS);

    input_expression = "(ln(25.9))";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, SUCCESS);

    input_expression = "-log(982.465)";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, SUCCESS);

    input_expression = "+(-1+(+1))";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, SUCCESS);

    input_expression = "7*(2)*1";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, SUCCESS);

    input_expression = "2^sin(3)/1";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, SUCCESS);

    input_expression = "sin(-1000000)";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, SUCCESS);

    input_expression = "cos(123456)";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, SUCCESS);

    input_expression = "atan(1000000)";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, SUCCESS);

    input_expression = "tan(2)+ln(40)";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, SUCCESS);

    input_expression = "log(2)+log(3)";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, SUCCESS);

    input_expression = "(-0)";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, SUCCESS);

    input_expression = "(-1*0)";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, SUCCESS);

    input_expression = "(0*(-1))";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, SUCCESS);

    input_expression = "(0*(-1))";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, SUCCESS);

    input_expression =
        "sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin("
        "10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+"
        "sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin("
        "10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)+sin(10)";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, SUCCESS);

    input_expression = "";
    retu_valya = s21_calc(input_expression, 0, &result);
    ck_assert_int_eq(retu_valya, FAIL);
}
END_TEST

int main() {
    Suite *s1 = suite_create("Core");
    TCase *s21_test = tcase_create("Test");
    SRunner *sr = srunner_create(s1);
    suite_add_tcase(s1, s21_test);

    tcase_add_test(s21_test, smartcalc_tests);

    srunner_run_all(sr, CK_VERBOSE);
    int errors = srunner_ntests_failed(sr);
    srunner_free(sr);

    return errors == 0 ? 0 : 1;
}
