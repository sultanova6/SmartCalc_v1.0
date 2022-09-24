// Copyright 2022 myrebean

#include "s21_smartcalc.h"

// валидация
// парсер и калькулятор
// обратная польская нотация

// валидация

int s21_valid_math(char* math) {
    int retu_valya = SUCCESS;
    int smech = 0, count = 0;
    char* trig = "cstalx";
    char* dei = "+-*/^";
    int dlina = (int)strlen(math);
    int LEVAYA = 0, PRAVAYA = 0;
    int dei_count = 0, err_count = 0;
    math = s21_probeli(math);

    if (!s21_samoe_vashnoe(math, dlina, dei, trig)) {
        retu_valya = FAIL;
    }

    if (dlina > 255 || dlina < 3) {
        retu_valya = FAIL;
    }

    for (int i = 0; i < dlina; i++) {  // катаемся по строке
        switch (math[i]) {
            case '(':
                    LEVAYA++;
                    if (math[i+1] == ')') {
                        retu_valya = FAIL;
                    }
                    break;
            case ')':
                    PRAVAYA++;
                    if (math[i+1] == '(') {
                        retu_valya = FAIL;
                    }
                    break;
            case '.':
                    if (math[i+1] <= '0' && math[i+1] >= '9') {
                        retu_valya = FAIL;
                    }
                    break;
            case '-':
                    if (math[i-1] <= '0' && math[i-1] >= '9') {
                        if (math[i-1] != '(' && math[i-1] != ')') {
                            if (math[i-1] != 'x') {
                                retu_valya = FAIL;
                            }
                        }
                    }
                    break;
            case 'm':
                    if (s21_proverka("mod", math, i, &smech)) {
                        if ((math[i-1] <= '0' && math[i-1] >= '9')
                        || (math[i+3] <= '0' && math[i+3] >= '9')) {
                            retu_valya = FAIL;
                        }
                    } else {
                        retu_valya = FAIL;
                    }
                    break;
            }

        for (int p = 0; trig[p] != '\0'; p++) {
            if (math[i] == trig[p]) {
                if (!s21_trig(i, math, &smech)) {  // корректна ли триг-я
                    retu_valya = FAIL;
                }
                if (smech && math[i + smech + 1] != '(') {  // корректно ли написаны триг-е штуки
                    retu_valya = FAIL;
                }
            }
        }

        count = 0;
        for (int y = 0; dei[y] != '\0'; y++) {  // смотрим знаки действий
            if (math[i] == ')' && math[i+1] != dei[y]
            && math[i+1] != '\0' && math[i+1] != ')') {
                count++;
                if (count == (int)strlen(dei)) {
                    retu_valya = FAIL;
                }
                }
            if (math[dlina-1] == dei[y]) {
                    retu_valya = FAIL;
            }

            dei_count = 0;
            if (math[i] == dei[y]) {
                dei_count++;
                err_count = 0;
                for (int w = 0; trig[w] != '\0'; w++) {
                    if ((math[i+1] <= '0' && math[i+1] >= '9')  // чтобы после плюса все было адекватно
                    && math[i+1] != '(' && math[i+1] != trig[w]) {
                        err_count++;
                    }
                    if ((math[i-1] <= '0' && math[i-1] >= '9')  // чтобы до плюса все было адекватно
                    && math[i-1] != ')' && math[i-1] != trig[w]) {
                        err_count++;
                    }
                }

                if (err_count == (int)strlen(trig)) {
                        retu_valya = FAIL;
                    }

                for (int t = 0; dei[t] != '\0'; t++) {
                    if (math[i+1] == dei[t]) {
                        retu_valya = FAIL;
                    }
                }
            }
        }
        i += smech;
        smech = 0;
    }
    if (LEVAYA != PRAVAYA) {  // корректное количество скобок
        retu_valya = FAIL;
    }

    free(math);

    return retu_valya;
}

char* s21_probeli(char* math) {
    char* retu_math = calloc(strlen(math), sizeof(char));

    for (int i = 0, j = 0; i < (int)strlen(math); i++) {  // пробелы
        if (math[i] != ' ') {
            retu_math[j++] = math[i];
        }
    }
    return retu_math;
}

int s21_samoe_vashnoe(char* math, int dlina, char* dei, char* trig) {
    int retu_valya = SUCCESS;
    int dei_prov = 0, trig_prov = 0;

    for (int i = 0; i < dlina; i++) {
        for (int j = 0; dei[j] != '\0'; j++) {
            if (dei[j] == math[i]) {
                dei_prov++;
            }
        }
        for (int y = 0; trig[y] != '\0'; y++) {
            if (trig[y] == math[i] || math[i] == 'm') {
                trig_prov++;
            }
        }
    }

    if (!trig_prov && !dei_prov) {
        retu_valya = FAIL;
    }
    return retu_valya;
}

int s21_proverka(char* trig, char* math, int count, int* smech) {  // проверяем
    int retu_valya = FAIL;
    int prov = 0, j = 0;
    int dlina = (int)strlen(trig);
    int i = count;

    while (i < count + dlina) {
        if (math[i] == trig[j]) {
            prov++;
            j++;
        }
        i++;
    }

    if (prov == dlina) {
        retu_valya = SUCCESS;
        *smech = dlina - 1;
    }

    return retu_valya;
}

int s21_trig(int count, char* math, int* smech) {  // смотрим триг-ю
    int retu_valya = SUCCESS;
    int prov = 0;
    switch (math[count]) {
    case 'c':
            prov += s21_proverka("cos", math, count, smech);
            break;
    case 's':
            if (math[count+1] == 'i') {
                prov += s21_proverka("sin", math, count, smech);
            } else {
                prov += s21_proverka("sqrt", math, count, smech);
            }
            break;
    case 'a':
            if (math[count+1] == 'c') {
                prov += s21_proverka("acos", math, count, smech);
            } else if (math[count+1] == 's') {
                prov += s21_proverka("asin", math, count, smech);
            } else {
                prov += s21_proverka("atan", math, count, smech);
            }
            break;
    case 'l':
            if (math[count+1] == 'n') {
                prov += s21_proverka("ln", math, count, smech);
            } else {
                prov += s21_proverka("log", math, count, smech);
            }
            break;
    case 't':
            prov += s21_proverka("tan", math, count, smech);
            break;
    case 'x':
            prov += s21_proverka("x", math, count, smech);
            break;
    }
    if (!prov) {
        retu_valya = FAIL;
    }
    return retu_valya;
}

int s21_graphics(long double xMAX, long double xMIN,
                long double yMIN, long double yMAX) {
    int retu_valya = SUCCESS;
    if (xMIN >= xMAX || yMIN >= yMAX) {
        retu_valya = FAIL;
    }
    return retu_valya;
}

// // парсер и калькулятор

// int main() {
//    long double res = 0;
//    s21_calc("atan(1000000)", 0, &res);
//    printf("%d\n", s21_valid_math("atan(1000000)"));
//    printf("%Lf", res);
// }

void s21_pushBack(long double value, int prior, type_t type, stack **perv_el) {
    stack *p = malloc(sizeof(stack));
    p->value = value;
    p->prior = prior;
    p->next = *perv_el;
    p->type = type;
    *perv_el = p;
}

void s21_popBack(stack **posl_el) {
    stack *p = NULL;
    p = (*posl_el)->next;
    free(*posl_el);
    (*posl_el) = p;
}

void s21_next_popBack(stack **posl_el) {
    stack *p = NULL;
    p = (*posl_el)->next->next;
    free((*posl_el)->next);
    (*posl_el)->next = p;
}

void s21_next_next_popBack(stack **posl_el) {
    stack *p = NULL;
    p = (*posl_el)->next->next->next;
    free((*posl_el)->next->next);
    free((*posl_el)->next);
    (*posl_el)->next = p;
}

int s21_calc(char* math, long double value, long double *result) {
     int retu_valya = FAIL;

    if (s21_valid_math(math)) {
        retu_valya = SUCCESS;
        stack* rev_perv_el = NULL;

        for (int i = 0; math[i] != '\0'; i++) {
            s21_zapolnyaem_stack(math, &i, &rev_perv_el, value);
        }

        stack* perv_el = NULL;
        s21_perevorachivaem_stack(&rev_perv_el, &perv_el);

        stack* RPN_num = NULL;
        stack* RPN_sup = NULL;
        s21_RPN(&perv_el, &RPN_num, &RPN_sup);
        // обратная польская нотация

        stack* res = NULL;
        s21_perevorachivaem_stack(&RPN_num, &res);

        stack* calc_stack = NULL;
        s21_smartcalc(&res, &calc_stack);

        *result = calc_stack->value;
        s21_popBack(&calc_stack);
    }
    return retu_valya;
}

void s21_smartcalc(stack** res, stack** calc_stack) {
    int prov = 0, num_prov = 0;

    while (1) {
            switch ((*res)->type) {
            case plus:
                    s21_popBack(res);
                    s21_pushBack(((*calc_stack)->next->value
                    + (*calc_stack)->value), 0, number, calc_stack);
                    s21_next_next_popBack(calc_stack);
                    break;
            case minus:
                    s21_popBack(res);
                    s21_pushBack((*calc_stack)->next->value
                    - (*calc_stack)->value, 0, number, calc_stack);
                    s21_next_next_popBack(calc_stack);
                    break;
            case umn:
                    s21_popBack(res);
                    s21_pushBack((*calc_stack)->next->value
                    * (*calc_stack)->value, 0, number, calc_stack);
                    s21_next_next_popBack(calc_stack);
                    break;
            case DIV:
                    s21_popBack(res);
                    s21_pushBack((*calc_stack)->next->value
                    / (*calc_stack)->value, 0, number, calc_stack);
                    s21_next_next_popBack(calc_stack);
                    break;
            case MOD:
                    s21_popBack(res);
                    s21_pushBack(fmod((*calc_stack)->next->value,
                    (*calc_stack)->value), 0, number, calc_stack);
                    s21_next_next_popBack(calc_stack);
                    break;
            case pedegree:
                    s21_popBack(res);
                    s21_pushBack(pow((*calc_stack)->next->value,
                    (*calc_stack)->value), 0, number, calc_stack);
                    s21_next_next_popBack(calc_stack);
                    break;
            case SIN:
                    s21_popBack(res);
                    s21_pushBack(sin((*calc_stack)->value),
                    0, number, calc_stack);
                    s21_next_popBack(calc_stack);
                    break;
            case COS:
                    s21_popBack(res);
                    s21_pushBack((cos((*calc_stack)->value)),
                    0, number, calc_stack);
                    s21_next_popBack(calc_stack);
                    break;
            case TAN:
                    s21_popBack(res);
                    s21_pushBack(tan((*calc_stack)->value),
                    0, number, calc_stack);
                    s21_next_popBack(calc_stack);
                    break;
            case ACOS:
                    s21_popBack(res);
                    s21_pushBack(acos((*calc_stack)->value),
                    0, number, calc_stack);
                    s21_next_popBack(calc_stack);
                    break;
            case ASIN:
                    s21_popBack(res);
                    s21_pushBack(asin((*calc_stack)->value),
                    0, number, calc_stack);
                    s21_next_popBack(calc_stack);
                    break;
            case ATAN:
                    s21_popBack(res);
                    s21_pushBack(atan((*calc_stack)->value),
                    0, number, calc_stack);
                    s21_next_popBack(calc_stack);
                    break;
            case SQRT:
                    s21_popBack(res);
                    s21_pushBack(sqrt((*calc_stack)->value),
                    0, number, calc_stack);
                    s21_next_popBack(calc_stack);
                    break;
            case LOG:
                    s21_popBack(res);
                    s21_pushBack(log((*calc_stack)->value),
                    0, number, calc_stack);
                    s21_next_popBack(calc_stack);
                    break;
            case LN:
                    s21_popBack(res);
                    s21_pushBack(log10((*calc_stack)->value),
                    0, number, calc_stack);
                    s21_next_popBack(calc_stack);
                    break;
            default:
                    break;
            }

            if (*res) {
                if ((*res)->type == number || (*res)->type == X) {
                    num_prov++;
                    s21_pushBack((*res)->value,
                    (*res)->prior, (*res)->type, calc_stack);
                    s21_popBack(res);
                }
            }

            if (!*res || prov) {
                break;
            }

            if (!(*res)->next) {
                prov++;
            }
        }
}

int s21_cifri(char* math, char* chislo, int* i) {
    int g = 0;
    int prov = 0;
    int ret_val = 0;

    while (math[*i] != '\0') {
            if ((math[*i] >= '0' && math[*i] <= '9') || math[*i] == '.') {
                chislo[g++] = math[*i];
                if ((math[*i+1] < '0' ||math[*i+1] > '9')
                && math[*i+1] != '.') {
                    prov++;
                }
            }
            if (prov) {
                break;
            }
            (*i)++;
        }
        if (math[*i] == '\0') {
            ret_val++;
        }
        return ret_val;
}

void s21_zapolnyaem_stack(char* math, int* i,
                        stack **perv_el, long double value) {
    char chislo[256] = {'\0'};

    if (math[*i] >= '0' && math[*i] <= '9') {
        s21_cifri(math, chislo, i);
        long double celoe_chislo = 0;
        sscanf(chislo, "%Lf", &celoe_chislo);
        s21_pushBack(celoe_chislo, 0, number, perv_el);
    }

    switch (math[*i]) {
        case 'X':
        case 'x':
            s21_pushBack(value, 0, X, perv_el);
            break;
        case '(':
            s21_pushBack(0, -1, LEVAYA, perv_el);
            break;
        case ')':
            s21_pushBack(0, -1, PRAVAYA, perv_el);
            break;
        case '+':
            if (!*i || (*perv_el)->type == LEVAYA) {
                s21_pushBack(0, 0, number, perv_el);
            }
            s21_pushBack(0, 1, plus, perv_el);
            break;
        case '-':
            if (!*i || (*perv_el)->type == LEVAYA) {
                s21_pushBack(0, 0, number, perv_el);
            }
            s21_pushBack(0, 1, minus, perv_el);
            break;
        case '*':
            s21_pushBack(0, 2, umn, perv_el);
            break;
        case '/':
            s21_pushBack(0, 2, DIV, perv_el);
            break;
        case 'm':
            s21_pushBack(0, 2, MOD, perv_el);
            *i += 2;
            break;
        case '^':
            s21_pushBack(0, 3, pedegree, perv_el);
            break;
        case 'c':
            s21_pushBack(0, 4, COS, perv_el);
            *i += 2;
            break;
        case 's':
                if (math[*i+1] == 'i') {
                    s21_pushBack(0, 4, SIN, perv_el);
                    *i += 2;
                } else {
                    s21_pushBack(0, 4, SQRT, perv_el);
                    *i += 3;
                }
            break;
        case 't':
            s21_pushBack(0, 4, TAN, perv_el);
            *i += 2;
            break;
        case 'l':
                if (math[*i+1] == 'n') {
                    s21_pushBack(0, 4, LN, perv_el);
                    *i += 1;
                } else {
                    s21_pushBack(0, 4, LOG, perv_el);
                    *i += 2;
                }
            break;
        case 'a':
                if (math[*i+1] == 'c') {
                    s21_pushBack(0, 4, ACOS, perv_el);
                    *i += 3;
                } else if (math[*i+1] == 's') {
                    s21_pushBack(0, 4, ASIN, perv_el);
                    *i += 3;
                } else {
                    s21_pushBack(0, 4, ATAN, perv_el);
                    *i += 3;
                }
            break;
    }
}

void s21_perevorachivaem_stack(stack **perv_el, stack **otvet) {
    int prov = 0;

    while (1) {
            s21_pushBack((*perv_el)->value,
            (*perv_el)->prior, (*perv_el)->type, otvet);
            s21_popBack(perv_el);

            if (prov) {  // если закончились элементы стека, то стопаем
                break;
            }

            if (!(*perv_el)->next) {
                prov++;
            }
        }
}

// обратная польская нотация

void s21_RPN(stack** perv_el, stack** RPN_num, stack** RPN_sup) {
    int prov = 0;

    while (1) {
        if ((*perv_el)) {
            if ((*perv_el)->type == PRAVAYA) {
                s21_popBack(perv_el);
                while ((*RPN_sup)->type != LEVAYA) {
                    s21_pushBack((*RPN_sup)->value, (*RPN_sup)->prior,
                    (*RPN_sup)->type, RPN_num);
                    s21_popBack(RPN_sup);
                }
                s21_popBack(RPN_sup);
            } else {
                if ((*perv_el)->type == number || (*perv_el)->type == X) {
                    s21_pushBack((*perv_el)->value, (*perv_el)->prior,
                    (*perv_el)->type, RPN_num);
                    s21_popBack(perv_el);
                } else {
                    if (*RPN_sup) {
                        if ((*perv_el)->prior != -1) {
                            if ((*perv_el)->prior <= (*RPN_sup)->prior) {
                                s21_pushBack((*RPN_sup)->value,
                                (*RPN_sup)->prior,
                                (*RPN_sup)->type, RPN_num);
                                s21_popBack(RPN_sup);
                            }
                        }
                    }
                    s21_pushBack((*perv_el)->value, (*perv_el)->prior,
                    (*perv_el)->type, RPN_sup);
                    s21_popBack(perv_el);
                }
            }
        }
        if (!*perv_el || prov) {
            break;
        }
        if (!(*perv_el)->next) {
            prov++;
        }
    }

    prov = 0;
    if (*RPN_sup) {
        while (1) {
            s21_pushBack((*RPN_sup)->value,
            (*RPN_sup)->prior, (*RPN_sup)->type, RPN_num);
            s21_popBack(RPN_sup);
            if (prov || !*RPN_sup) {
                break;
            }
            if (!(*RPN_sup)->next) {
                prov++;
            }
        }
    }
}
