#pragma once
#include <string>

class Slope{
    public:
        void SetSlope(double slope_v);
        void SetMass(double mass_v);
        void SetGravity(double gravity_v);
        void ApplyControlInput(double control_input_v);
        std::string Display();
        double MeasureX();
        void ProgressStep();
    private:
        double _x = 0;
        double _y = 0;
        double _vx = 0;
        double _vy = 0;
        double _slope = 0;
        double _mass = 1;
        double _gravity_meter_per_sec_square = 9.8;
        double _step_milliseconds = 10;
};