#include "IsingModel.h"
#include "MCMC.h"
#include "DataOutput.h"

int main() {
    int latticeSize = 100;
    double temperature = 2.0;

    IsingModel model(latticeSize);
    DataOutput dataOutput("ising_data.csv");
    MCMC mcmc(model, temperature, dataOutput);
    mcmc.run();

    return 0;
}
