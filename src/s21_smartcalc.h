// Copyright 2022 myrebean

#ifndef SRC_S21_SMARTCALC_H_
#define SRC_S21_SMARTCALC_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef enum type {
    X,
    number,
    plus,
    minus,
    umn,
    DIV,
    MOD,
    pedegree,  // степень
    SIN,
    COS,
    TAN,
    ACOS,
    ASIN,
    ATAN,
    SQRT,
    LOG,
    LN,
    LEVAYA,
    PRAVAYA
} type_t;

typedef struct stack_n {
    long double value;
    int prior;
    struct stack_n* next;
    type_t type;
} stack;

enum datchic {
    FAIL,
    SUCCESS
};

int s21_valid_math(char* math);
char* s21_probeli(char* math);
int s21_samoe_vashnoe(char* math, int dlina, char* dei, char* trig);
int s21_proverka(char* trig, char* math, int count, int* smech);
int s21_trig(int count, char *math, int* smech);
int s21_graphics(long double xMAX, long double xMIN, long double yMIN, long double yMAX);
void s21_pushBack(long double value, int prior, type_t type, stack **perv_el);
void s21_smartcalc(stack** result, stack** calc_stack);
void s21_popBack(stack **posl_el);
void s21_next_popBack(stack **posl_el);
void s21_next_next_popBack(stack **posl_el);
int s21_calc(char* math, long double value, long double *result);
void s21_zapolnyaem_stack(char* math, int* i, stack **perv_el, long double X);
void s21_perevorachivaem_stack(stack **perv_el, stack **result);
void s21_RPN(stack** perv_el, stack** RPN_num, stack** RPN_sup);



// Обратная польская нотация

// (8 + 2 * 5) / (1 + 3 * 2 - 4)
// 8 2 5 * + 1 3 2 * + 4 - /
// 8 10 + 1 3 2 * + 4 - /
// 18 1 3 2 * + 4 - /
// 18 1 6 + 4 - /
// 18 7 4 - /
// 18 3 /
// 6

#endif  // SRC_S21_SMARTCALC_H_
