#include "controller.h"

#include <sstream>

void Controller::SetP(double p_value){
    _p_value=p_value;
}

void Controller::SetI(double i_value){
    _i_value=i_value;
}

void Controller::SetD(double d_value){
    _d_value=d_value;
}

void Controller::ModifyP(double amount){
    _p_value+=amount;
}

void Controller::ModifyI(double amount){
    _i_value+=amount;
}

void Controller::ModifyD(double amount){
    _d_value+=amount;
}

std::string Controller::Display(){
    std::stringstream output;
    output << "P: " << _p_value 
        << " I: " << _i_value 
        << " D: " << _d_value;
    return output.str();
}

double Controller::CalculateControlInput(double goal_measurement_discrepency, uint64_t step_milliseconds){
    _derivative = (goal_measurement_discrepency - _proportion)/ (step_milliseconds / 1000.0);
    _integral = _integral + (goal_measurement_discrepency + _proportion) * step_milliseconds / 2000;
    _proportion = goal_measurement_discrepency;

    return _p_value * _proportion + _i_value * _integral + _d_value * _derivative;
}