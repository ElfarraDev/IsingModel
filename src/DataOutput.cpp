#include "DataOutput.h"

DataOutput::DataOutput(const std::string& filename) {
    dataFile.open(filename);
    dataFile << "Step,Magnetism,Temperature\n";
}

DataOutput::~DataOutput() {
    if (dataFile.is_open()) {
        dataFile.close();
    }
}

void DataOutput::writeData(int step, double magnetism, double temperature) {
    dataFile << step << "," << magnetism << "," << temperature << "\n";
}
