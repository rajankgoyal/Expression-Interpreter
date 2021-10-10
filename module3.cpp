#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments();

int main()
{

    Expression* expression;
    char paren, comma;
    ifstream file("../expressions.txt");
    string statement;
    while (getline(file, statement)){
        // injects file statement into the cin buffer
        istringstream oss(statement);
        cin.rdbuf(oss.rdbuf());
        // Prints the statement from the file
        cout << statement;
        // reads in the statement and breaks it down to be evaluated
        cin >> paren;
        expression = SubExpression::parse();
        cin >> comma;
        parseAssignments();
        cout << " Value = " << expression->evaluate() << endl;
        // Clears the Symbol table for next statement evaluation
        symbolTable.clear();
    }
    return 0;
}

void parseAssignments()
{
    char assignop, delimiter;
    string variable;
    double value;
    do
    {
        variable = parseName();
        cin >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    }
    while (delimiter == ',');
}