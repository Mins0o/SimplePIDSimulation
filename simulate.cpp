#include "simulate.h"
#include <iostream>
#include <chrono>

void Simulation::SetUp(){
    std::cout << "Setting up" << std::endl;
    slope_.SetSlope(0);
    slope_.SetMass(1);
    slope_.SetGravity(9.8);
    goal_ = 1.0;
    step_milliseconds_ = 10;
}
void Simulation::Run(){
    auto last_time = std::chrono::high_resolution_clock::now();
    
    std::cout << "Running" << std::endl;
    while (true){
        auto current_time = std::chrono::high_resolution_clock::now();
        double delta_time = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_time).count();
        if (delta_time >= (step_milliseconds_)){
            Display();
            HandleUserInput();
            ProgressStep();
            last_time = std::chrono::high_resolution_clock::now();;
        }
    }
}

void Simulation::Display(){
    std::cout << slope_.Display() << std::endl;
    std::cout << controller_.Display() << std::endl;
}

void Simulation::HandleUserInput(){

}

void Simulation::ProgressStep(){
    double measurement = slope_.MeasureX();
    double control_input = controller_.CalculateControlInput(goal_ - measurement, step_milliseconds_);
    slope_.ApplyControlInput(-control_input);
    slope_.ProgressStep();
}

int main(int argc, char* argv[]){
    Simulation simulation;
    simulation.SetUp();
    simulation.Run();
}