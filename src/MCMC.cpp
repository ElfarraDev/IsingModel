#include "MCMC.h"
#include <iostream>
#include <sstream>

MCMC::MCMC(IsingModel& model, double temperature, DataOutput& dataOutput)
    : model(model), kT(temperature), rng(time(0)), window(sf::VideoMode(model.getSize() * cellSize, model.getSize() * cellSize), "Ising Model Simulation"), dataOutput(dataOutput) {
    dist = std::uniform_int_distribution<int>(0, model.getSize() - 1);
    dist_double = std::uniform_real_distribution<double>(0.0, 1.0);

    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Could not load font\n";
    }

    magnetismText.setFont(font);
    magnetismText.setCharacterSize(14);
    magnetismText.setFillColor(sf::Color::Red);
    magnetismText.setPosition(10, 10);

    temperatureText.setFont(font);
    temperatureText.setCharacterSize(14);
    temperatureText.setFillColor(sf::Color::Red);
    temperatureText.setPosition(10, 30);
}

void MCMC::run() {
    int stepCount = 0;
    while (window.isOpen()) {
        handleEvents();
        step();
        writeData(stepCount);
        render();
        stepCount++;
    }
}

void MCMC::step() {
    int L = model.getSize();
    for (int i = 0; i < L * L; ++i) {
        int x = dist(rng);
        int y = dist(rng);
        int dE = model.deltaE(x, y);

        if (dE < 0 || dist_double(rng) < std::exp(-dE / kT)) {
            model.flipSpin(x, y);
        }
    }
}

void MCMC::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                kT += 0.1;
            } else if (event.key.code == sf::Keyboard::Down) {
                kT -= 0.1;
            }
        }
    }
}

void MCMC::render() {
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
    int L = model.getSize();
    for (int x = 0; x < L; ++x) {
        for (int y = 0; y < L; ++y) {
            cell.setPosition(x * cellSize, y * cellSize);
            cell.setFillColor(model.getSpin(x, y) == 1 ? sf::Color::White : sf::Color::Black);
            window.draw(cell);
        }
    }

    double magnetism = model.calculateMagnetism();
    std::ostringstream magnetismStream;
    magnetismStream << "Magnetism: " << magnetism;
    magnetismText.setString(magnetismStream.str());

    std::ostringstream temperatureStream;
    temperatureStream << "Temperature (kT): " << kT;
    temperatureText.setString(temperatureStream.str());

    window.draw(magnetismText);
    window.draw(temperatureText);
    window.display();
}

void MCMC::writeData(int step) {
    double magnetism = model.calculateMagnetism();
    dataOutput.writeData(step, magnetism, kT);
}
