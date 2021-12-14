#pragma once

#include "cs225/PNG.h"
#include <vector>
#include "Animation.h"

using namespace cs225;

class gifFunction {
    public:
    
    // void makeGif(vector<PNG> input); //the function that takes in a vector of PNGS to generate one GIF.
    void makeGif(vector<PNG> input) {
        Animation animation;
        for (unsigned i = 0; i < input.size(); i++) {
            animation.addFrame(input[i]);
            animation.addFrame(input[i]);
            animation.addFrame(input[i]);
            animation.addFrame(input[i]);
        }
        //   PNG Frame1;
        //   Frame1.readFromFile("worldMap[1].png");
        //   animation.addFrame(Frame1);
        //   PNG Frame2;
        //   Frame2.readFromFile("worldMap[2].png");
        //   animation.addFrame(Frame2);
        //   PNG Frame3;
        //   Frame3.readFromFile("worldMap[3].png");
        //   animation.addFrame(Frame3);
        //   PNG Frame4;
        //   Frame4.readFromFile("worldMap[2150].png");
        //   animation.addFrame(Frame4);
        animation.write("AnimatedSolution.gif");
        
        PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
        lastFrame.writeToFile("NonanimatedSolution.png");
    }
};