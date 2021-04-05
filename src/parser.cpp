#include <iostream>
#include "parser.h"

void Parser::usage(const char *argv[]){
    std::cerr << std::endl << std::endl;
    std::cerr << "USAGE:" << std::endl;
    std::cerr << argv[0] << " --data DATA_FILE_PATH" << std::endl;
    std::cerr << std::endl;
    std::cerr << "--data DATA_FILE_PATH  relative path to data, e.g. ./data/data_256.csv" << std::endl;
    std::cerr << "--data-size LENGTH_OF_ROW_OF_SQUARE DATA  The length of a side of the grid e.g. 256" << std::endl;
    std::cerr << std::endl;
}

int Parser::parseInput(int argc,char const* argv[]){
     if (argc <= 3) {
        std::cerr << "Not enough arguments, usage:";
        usage(argv);
        return 1;
    }
    for (int i = 1; i <= argc - 2; i += 2) {
        const std::string opt(argv[i]);
        if (opt == "--data") {
            m_dataPath = argv[i + 1];
        } 
        else if(opt == "--data-size"){
            m_dataSize = std::stoi(argv[i + 1]);
        }
        else {
            std::cerr << "Unknown option " << opt << ", usage:"; usage(argv); exit(1);
        }
    }
    std::clog<<"Data Path: '"<< m_dataPath<<"'"<<std::endl;   

}
std::string Parser::getDataPath(){
    return m_dataPath;
}
int Parser::getDataSize(){
    return m_dataSize;
}