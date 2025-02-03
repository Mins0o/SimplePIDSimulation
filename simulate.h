#pragma once

#include "controller.h"
#include "slope.h"

class Simulation{
    public:
        void Run();
        void SetUp();
    private:
        void Display();
        void HandleUserInput();
        void ProgressStep();
    private:
        Controller controller_;
        Slope slope_;
        double goal_ = 0;
        double step_milliseconds_ = 10;
};