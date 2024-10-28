#ifndef DATAOUTPUT_H
#define DATAOUTPUT_H

#include <fstream>
#include <string>

class DataOutput {
public:
    DataOutput(const std::string& filename);
    ~DataOutput();
    void writeData(int step, double magnetism, double temperature);

private:
    std::ofstream dataFile;
};

#endif // DATAOUTPUT_H
