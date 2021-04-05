#include <iostream>
#include <fstream>
#include "parser.h"
#include "grid.h"
int main(int argc, char const *argv[])
{
    Parser p;
    p.parseInput(argc, argv);
    Grid g(p.getDataSize());
    g.loadGridFromDataPath(p.getDataPath());
    g.displayGrid();
}