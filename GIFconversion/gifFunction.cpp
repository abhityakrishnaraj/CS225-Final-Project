#include "cs225/PNG.h"
#include "gifFunction.h"
#include "Animation.h"

using namespace cs225;

void makeGif(vector<PNG> input) {
  Animation animation;
  for (unsigned i = 0; i < input.length(); i++) {
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
  animation.write("GifRoute.gif");
  
  PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
  lastFrame.writeToFile("Non/animatedSolution.png");
}