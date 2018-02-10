//  Copyright © 2018 Stepan. All rights reserved.

#include <iostream>

const char* s = "(5*(5+2)-5)/2";
int p = 0;

int G();

int getE();
int getT();
int getP();
int getN();

int main() {
    const int val = G();
    printf("%s=%d\n", s, val);
    return 0;
}

int G () {
    p = 0;
    const int val = getE();
    if (s[p] != '\0') {std::cout << "aaa!";};
    return val;
    
}

int getE() {
    int val = getT();
    while (s[p] == '+' || s[p] == '-') {
        const char op = s[p]; p++;
        int val2 = getT();
        if (op == '+') {
            val = val+val2;
        }
        else {
            val = val-val2;
        }
    }
    return val;
}

int getT() {
    int val = getP();
    while (s[p] == '*' || s[p] == '/') {
        const char op = s[p]; p++;
        int val2 = getP();
        if (op == '*') {
            val = val*val2;
        }
        else {
            val = val/val2;
        }
    }
    return val;
}


int getP() {
    // TODO: maybe '&' implementation
    if (s[p] == '(') {
        p++;
        int val = getE();
        p++;
        return val;
    }
    else {
        return getN();
    }
}

int getN() {
    // TODO: negative numbers
    // TODO: check old and new val (or smth with 'do while')
    int val = 0;
    while (s[p] >= '0' && s[p] <= '9') {
        val = val*10+s[p]-'0';
        p++;
    }
    return val;
}
