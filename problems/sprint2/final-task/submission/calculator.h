// Ваше решение задачи о калькуляторе с классом.
#pragma once
#include <cmath>

using Number = double;

bool ReadNumber(Number& result);

bool RunCalculatorCycle ();

class Calculator {
public:
    void SetLeftOperand(Number value){
        left_operand_ = value;
    }

    void SetRightOperand(Number value) {
        right_operand_ = value;
    }

    Number GetLeftOperand(){
        return left_operand_;
    }
    Number Add() const {
        return left_operand_ + right_operand_;
    }
    Number Sub() const {
        return left_operand_ - right_operand_;
    }
    Number Mul() const {
        return left_operand_ * right_operand_;
    }
    Number Div() const {
        if (right_operand_ == 0){
            return 1;
        }
        return left_operand_ / right_operand_;
    }
    Number Pow() const {
        return pow(left_operand_, right_operand_);
    }

private:
    Number left_operand_ = 0.0;
    Number right_operand_ = 0.0;
};
