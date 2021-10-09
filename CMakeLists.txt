cmake_minimum_required(VERSION 3.20)
project(hw330)

set(CMAKE_CXX_STANDARD 14)

add_executable(hw330
        expression.h
        subexpression.cpp subexpression.h
        operand.cpp operand.h
        variable.cpp variable.h
        literal.h
        parse.cpp parse.h
        plus.h minus.h times.h divide.h
        equals.h greater.h less.h
        and.h or.h
        module3.cpp
        symboltable.cpp symboltable.h)
