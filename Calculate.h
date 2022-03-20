#pragma once
#include <iostream>
#include <cstring>
#include "LinkedStack.h"

int power(int a, int k)
{
    int r = 1;
    while (k)
    {
        if (k & 1)
            r *= a;
        a *= a;
        k >>= 1;
    }
    return r;
}

class Calculate
{
private:
    enum operation
    {
        OPA, // (
        ADD, // +
        SUB, // -
        MUL, // *
        DIV, // /
        EXP, // ^
        CPA, // )
        VAL, // value
        EOL  // flag
    };
    char* expression, * current;
    operation getOperation(int& value);
    void doOperation(operation type, LinkedStack<int>& stack);

public:
    Calculate(char* sequence);
    ~Calculate();
    int getResult();
};

Calculate::operation Calculate::getOperation(int& value)
{
    while (*current && *current == ' ')
        current++;
    if (!*current)
        return EOL;
    if ('0' <= *current && *current <= '9')
    {
        value = 0;
        while ('0' <= *current && *current <= '9')
        {
            value = value * 10 + *current - '0';
            current++;
        }
        return VAL;
    }
    switch (*current)
    {
    case '(':
        current++;
        return OPA;
    case ')':
        current++;
        return CPA;
    case '+':
        current++;
        return ADD;
    case '-':
        current++;
        return SUB;
    case '*':
        current++;
        return MUL;
    case '/':
        current++;
        return DIV;
    case '^':
        current++;
        return EXP;
    }
    return EOL;
}

void Calculate::doOperation(operation type, LinkedStack<int>& stack)
{
    int x, y;
    if (stack.empty())
        throw "Right operand is missing!";
    else
        y = stack.pop();
    if (stack.empty())
        throw "Left operand is missing!";
    else
        x = stack.pop();
    switch (type)
    {
    case ADD:
        stack.push(x + y);
        break;
    case SUB:
        stack.push(x - y);
        break;
    case MUL:
        stack.push(x * y);
        break;
    case DIV:
        if (y == 0)
            throw "Divided by 0!";
        else
            stack.push(x / y);
        break;
    case EXP:
        stack.push(power(x, y));
        break;
    }
}

Calculate::Calculate(char* sequence)
{
    current = expression = new char[strlen(sequence) + 1];
    strcpy(expression, sequence);
}

Calculate::~Calculate()
{
    delete[] expression;
}

int Calculate::getResult()
{
    LinkedStack<operation> OperatorStack;
    LinkedStack<int> OperandStack;
    operation last, top;
    int value;
    while ((last = getOperation(value)) != EOL)
    {
        switch (last)
        {
        case VAL:
            OperandStack.push(value);
            break;
        case OPA:
            OperatorStack.push(OPA);
            break;
        case CPA:
            while (!OperatorStack.empty() && (top = OperatorStack.pop()) != OPA)
                doOperation(top, OperandStack);
            if (top != OPA)
                throw "Left operand is missing!";
            break;
        case EXP:
            OperatorStack.push(EXP);
            break;
        case MUL:
        case DIV:
            while (!OperatorStack.empty() && OperatorStack.top() >= MUL)
                doOperation(OperatorStack.pop(), OperandStack);
            OperatorStack.push(last);
            break;
        case ADD:
        case SUB:
            while (!OperatorStack.empty() && OperatorStack.top() != OPA)
                doOperation(OperatorStack.pop(), OperandStack);
            OperatorStack.push(last);
            break;
        }
    }
    while (!OperatorStack.empty())
        doOperation(OperatorStack.pop(), OperandStack);
    if (OperandStack.empty())
        throw "Too few operands!";
    int result = OperandStack.pop();
    if (!OperandStack.empty())
        throw "Too few operators!";
    return result;
}