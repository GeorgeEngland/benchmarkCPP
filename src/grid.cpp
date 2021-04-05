#include <string>
#include <fstream>
#include "grid.h"
#include <sstream>
#include <iostream>
#include <exception>
#include <limits>
#include <utility>
#include <algorithm>
#include <numeric>

inline int fast_atoi( const char * str )
{
    int val = 0;
    while( *str ) {
        val *=10 + (*str++ - '0');
    }
    return val;
}

inline int8_t fast_stoi( const std::string &str )
{
    int8_t val = 0;
    for(auto &i : str){
        val *=10 + (i - '0');       
    }
    return val;
}

void Grid::loadGridFromDataPath(std::string path){
    std::ifstream  data(path);
    int i=0,j=0;
    if (data.is_open()){
        std::string cell;
        while(std::getline(data,cell))
        {              
            j=0;
            int val = 0;
            for(auto c : cell){
                if(c==','){
                    grid[i][j]=val;
                    val=0;
                    ++j;
                }
                else{
                    val =val*10+(c-'0');
                }
            }
            grid.at(i).at(j)=val;
            i++;  
        }
        
        if(i<grid.size()){
            std::cerr<<"ERROR: Assigned grid is larger than data passed"<<std::endl;exit(-1);
        }
        
    }
    data.close();
}
void Grid::displayGrid(){
        for (size_t i = 0; i < grid.size(); i=i+grid.size()/30)
        {
            for (size_t j = 0; j < grid.size()-(grid.size()/100); j=j+grid.size()/100)
                {
                    int val = grid[i][j];
                    val=std::accumulate(grid[i].begin()+j,grid[i].begin()+j+grid.size()/100,0)/(grid.size()/100);
                    if(val <30)std::clog<<"_";
                    else if(val <50)std::clog<<".";
                    else if(val <60)std::clog<<"x";
                    else std::clog<<"X";    
                } 
            std::clog<<std::endl;  
        }
        
    }




