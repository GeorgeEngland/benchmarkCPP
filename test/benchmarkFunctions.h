#include <vector>

int parrallelsortVector(std::vector<int> vec);

int sortVector(std::vector<int> vec);

namespace dataPrep{
    struct gen_rand { 
        double range;
    public:
        gen_rand(double r=1.0) : range(r) {}
        double operator()();
    };
};