#include "IsingModel.h"

IsingModel::IsingModel(int size)
    : L(size), N(size * size), spins(N, 1) {}

int IsingModel::index(int x, int y) const {
    return (x + L) % L + ((y + L) % L) * L;
}

int IsingModel::deltaE(int x, int y) const {
    int s = spins[index(x, y)];
    int sum = spins[index(x + 1, y)] + spins[index(x - 1, y)] + spins[index(x, y + 1)] + spins[index(x, y - 1)];
    return 2 * s * sum;
}

void IsingModel::flipSpin(int x, int y) {
    spins[index(x, y)] *= -1;
}

double IsingModel::calculateMagnetism() const {
    int sum = 0;
    for (int s : spins) {
        sum += s;
    }
    return static_cast<double>(sum) / N;
}

int IsingModel::getSpin(int x, int y) const {
    return spins[index(x, y)];
}

int IsingModel::getSize() const {
    return L;
}
