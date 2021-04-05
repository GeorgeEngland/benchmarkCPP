#include <string>
#include <vector>
#include <memory>

class Grid{
        std::vector<std::vector<int>> grid;
    public:
        void loadGridFromDataPath(std::string path);
        void displayGrid();
        
        Grid(int aSize){
            grid.reserve(aSize*aSize*2);
            std::vector< std::vector<int> > g(aSize, std::vector<int>(aSize));            
            grid=std::move(g);
            
            };
        Grid()=delete;
};

