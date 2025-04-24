// Ваше решение задачи о калькуляторе с классом.
#include "calculator.h"
#include <iostream>
#include <cmath>
#include <string>

bool ReadNumber (Number& result){
    if (std::cin >> result){
        return true;
    } else {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
}

bool RunCalculatorCycle (){
    Number right_number = 0.;
    Number result = 0.;
    Number save_number = 0.;
    std::string operation;
    bool free_space = true; // для проверки свободного места в памяти ячейки save_number
    // Ввёл число и проверил является ли оно числом
    if (!ReadNumber(result)){
        return false;
    }
    // Цикл с работой операторов
    while (operation != "q"){
        std::cin >> operation;
        if (operation == "+"){
            if (!ReadNumber(right_number)){
                return false;
            }
            result += right_number;
        } else if (operation == "-"){
            if(!ReadNumber(right_number)){
                return false;
            }
            result -= right_number;
        } else if (operation == "*"){
            if(!ReadNumber(right_number)){
                return false;
            }
            result *= right_number;
        } else if (operation == "/"){
            if(!ReadNumber(right_number)){
                return false;
            }
            result /= right_number;
        } else if (operation == "**"){
            if(!ReadNumber(right_number)){
                return false;
            }
            result = pow(result, right_number);
        } else if (operation == ":") {
            if(!ReadNumber(result)){
                return false;
            }
        } else if (operation == "="){
            std::cout << result << std::endl;
        } else if (operation == "c"){
            result = false;
        } else if (operation == "q"){
            return true;
        } else if (operation == "s"){
            save_number = result;
            free_space = false;
        } else if (operation == "l"){
            if (free_space == false){
                result = save_number;
            } else {
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            }
        } else {
            std::cerr << "Error: Unknown token " << operation << std::endl;
            return false;
        }
    }
    return true;
}
