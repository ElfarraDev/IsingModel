#ifndef MCMC_H
#define MCMC_H

#include <SFML/Graphics.hpp>
#include <random>
#include "IsingModel.h"
#include "DataOutput.h"

class MCMC {
public:
    MCMC(IsingModel& model, double temperature, DataOutput& dataOutput);
    void run();

private:
    IsingModel& model;
    double kT;
    const int cellSize = 5;
    std::mt19937 rng;
    std::uniform_int_distribution<int> dist;
    std::uniform_real_distribution<double> dist_double;
    sf::RenderWindow window;
    sf::Font font;
    sf::Text magnetismText;
    sf::Text temperatureText;
    DataOutput& dataOutput;

    void step();
    void handleEvents();
    void render();
    void writeData(int step); // Update this function
};

#endif // MCMC_H
