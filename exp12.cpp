#include <stdio.h>
#include <ctype.h>

char input[100];
int index = 0;
int error = 0;

void E();
void E_prime();
void T();
void T_prime();
void F();
void match(char expected);

void E() {
    T();
    E_prime();
}

void E_prime() {
    if (input[index] == '+') {
        match('+');
        T();
        E_prime();
    }
}

void T() {
    F();
    T_prime();
}

void T_prime() {
    if (input[index] == '*') {
        match('*');
        F();
        T_prime();
    }
}

void F() {
    if (input[index] == '(') {
        match('(');
        E();
        match(')');
    } else if (isalpha(input[index])) {
        match(input[index]);
    } else {
        error = 1;
    }
}

void match(char expected) {
    if (input[index] == expected) {
        index++;
    } else {
        error = 1;
    }
}

int main() {
    printf("Enter an expression: ");
    scanf("%s", input);

    E();

    if (error || input[index] != '\0') {
        printf("Error: Invalid expression!\n");
    } else {
        printf("string is accepted!\n");
    }

    return 0;
}
