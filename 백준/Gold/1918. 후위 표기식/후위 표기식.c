// 중위 표기식 -> 후위 표기식
// !(Not) 연산도 같이 할 수 있도록 설계

// 경제학부 201811210 변해빈
// IDE = CLion;
// Compiler = Clang 16.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s) {
    s->top = -1;
}

int is_empty(StackType *s) {
    return (s->top == -1);
}

int is_full(StackType *s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    } else s->data[++(s->top)] = item;
}

element pop(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    } else return s->data[(s->top)--];
}

element peek(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    } else
        return s->data[s->top];
}

int prec(char op) {
    switch (op) {
        case '(':
        case ')':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return -1;
}

void infix_to_postfix(char exp[]) {
    char ch, top_op;
    int len = strlen(exp);
    StackType s;

    init_stack(&s);
    for (int i = 0; i < len; i++) {
        ch = exp[i];
        switch (ch) {
            case '+':
            case '-':
            case '*':
            case '/':
                while (!is_empty(&s) && prec(ch) <= prec(peek(&s)))
                    printf("%c", pop(&s));
                push(&s, ch);
                break;
            case '(':
                push(&s, ch);
                break;
            case ')':
                top_op = pop(&s);
                while (top_op != '(') {
                    printf("%c", top_op);
                    top_op = pop(&s);
                }
                break;
            default:
                printf("%c", ch);
                break;
        }
    }
    while (!is_empty(&s))
        printf("%c", pop(&s));
}

int main(void) {
    char *s;
    s = malloc(sizeof(char) * 100);
    scanf("%s", s);
    infix_to_postfix(s);
    return 0;
}