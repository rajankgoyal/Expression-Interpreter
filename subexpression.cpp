#include <iostream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "equals.h"
#include "greater.h"
#include "less.h"
#include "and.h"
#include "or.h"
#include "negate.h"
#include "conditional.h"

SubExpression::SubExpression(Expression* left)
{
    this->left = left;
}
SubExpression::SubExpression(Expression* left, Expression* right)
{
    this->left = left;
    this->right = right;
}

SubExpression::SubExpression(Expression *left, Expression *right, Expression *condition) {
    this->left = left;
    this->right = right;
    this->condition = condition;
}

Expression* SubExpression::parse()
{
    Expression* left;
    Expression* right;
    Expression* condition;
    char operation, paren;

    left = Operand::parse();
    cin >> operation;
    if (operation == '!'){
        cin >> paren;
        return new Negate(left);
    }
    else if(operation == ':'){
        right = Operand::parse();
        cin >> paren;
        condition = Operand::parse();
        cin >> paren;
        return new Conditional(left, right, condition);
    }
    else{
        right = Operand::parse();
        cin >> paren;
    }

    switch (operation)
    {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);
        case '*':
            return new Times(left, right);
        case '/':
            return new Divide(left, right);
        case '=':
            return new Equals(left, right);
        case '>':
            return new Greater(left, right);
        case '<':
            return new Less(left, right);
        case '&':
            return new And(left, right);
        case '|':
            return new Or(left, right);
    }
    return 0;
}
