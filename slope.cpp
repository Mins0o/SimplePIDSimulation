#include "slope.h"
#include <stdexcept>
#include <sstream>

void Slope::SetSlope(double slope_v){
    _slope = slope_v;
}

void Slope::SetMass(double mass_v){
    if (! mass_v > 0){
        throw std::runtime_error("mass_v should be bigger than 0.");
    }
    _mass = mass_v; 
}

void Slope::SetGravity(double gravity_meter_per_sec_square_v){
    if (! gravity_meter_per_sec_square_v > 0){
        throw std::runtime_error("gravity_v should be bigger than 0.");
    }
    _gravity_meter_per_sec_square = gravity_meter_per_sec_square_v;
}

void Slope::ApplyControlInput(double control_input_v){
    _slope = control_input_v;
}

std::string Slope::Display(){
    std::stringstream output_stream;
    output_stream << "x: " << _x << " y: " << _y << " slope: " << _slope;
    return output_stream.str();
}

double Slope::MeasureX(){
    return _x;
}

void Slope::ProgressStep(){
    _x = _x + _vx*_step_milliseconds/1000 
        - _slope/(_slope*_slope + 1) 
        * _gravity_meter_per_sec_square 
        * _step_milliseconds / 1000
        * _step_milliseconds / 2000;
    _y = _x * _slope;
    _vx = _vx 
        - _slope / (_slope * _slope + 1) 
        * _gravity_meter_per_sec_square
        * _step_milliseconds / 1000;
    _vy = _vx * _slope;
}