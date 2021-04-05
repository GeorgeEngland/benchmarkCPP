#include <string>

class Parser{
    std::string m_dataPath;
    int m_dataSize;
    public:
        int parseInput(int argc,char const* argv[]);

        void usage(const char *argv[]);
        
        std::string getDataPath();
        int getDataSize();
};
