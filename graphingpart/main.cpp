#include "Animation.h"
#include "cs225/PNG.h"
#include "gifFunction.hpp"
#include "visualize.h"
#include <vector>
using namespace cs225;

int main(){
    std::vector<std::string> temp;
    std::vector<PNG> vec;
    std::vector<std::string> input = {"NRT", "DEL", "LAX", "JFK", "PEK"};
    Visualize v;
    v.visualize(input).writeToFile("Final Route.png");
    //do vector of PNGs
    PNG base;
    base.readFromFile("map.png");
    vec.push_back(base);
    for (unsigned i = 1; i < input.size(); i++) {
        for (unsigned j = 0; j <= i; j++) {
            temp.push_back(input[j]);
        }
        
        vec.push_back(v.visualize(temp));
        temp.clear();
    }
    
    gifFunction x;
    x.makeGif(vec);

}