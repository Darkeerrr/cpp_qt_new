// Ваше решение задачи о калькуляторе с классом.
#pragma once
#include <cmath>

using Number = double;

bool ReadNumber(Number& result);

bool RunCalculatorCycle ();

class Calculator {
public:
    void SetLeftOperand(double value){
        left_operand_ = value;
    }
    double GetLeftOperand(){
        return left_operand_;
    }
    double Add(double right_operand) const {
        return left_operand_ + right_operand;
    }
    double Sub(double right_operand) const {
        return left_operand_ - right_operand;
    }
    double Mul(double right_operand) const {
        return left_operand_ * right_operand;
    }
    double Div(double right_operand) const {
        if (right_operand == 0){
            return 1;
        }
        return left_operand_ / right_operand;
    }
    double Pow(double right_operand) const {
        return pow(left_operand_, right_operand);
    }

private:
    double left_operand_ = 0.0;
};
