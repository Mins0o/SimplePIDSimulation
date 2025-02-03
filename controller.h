#pragma once
#include <string>

class Controller{
    public:
        void SetP(double p_value);
        void SetI(double i_value);
        void SetD(double d_vallue);
        void ModifyP(double amount);
        void ModifyI(double amount);
        void ModifyD(double amount);
        std::string Display();
        double CalculateControlInput(double goal_measurement_discrepency, uint64_t step_milliseconds);
    private:
        double _p_value=1;
        double _i_value=1;
        double _d_value=1;
        double _proportion;
        double _integral;
        double _derivative;
};