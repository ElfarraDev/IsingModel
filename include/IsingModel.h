#ifndef ISINGMODEL_H
#define ISINGMODEL_H

#include <vector>

class IsingModel {
public:
    IsingModel(int size);

    int index(int x, int y) const;
    int deltaE(int x, int y) const;
    void flipSpin(int x, int y);
    double calculateMagnetism() const;
    int getSpin(int x, int y) const;
    int getSize() const;

private:
    const int L;
    const int N;
    std::vector<int> spins;
};

#endif // ISINGMODEL_H
