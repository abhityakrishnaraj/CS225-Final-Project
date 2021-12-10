#include "visualize.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <math.h>
#include "circle.h"
#include "line.h"
#include "vector2.h"
#include "color.h"
#include <fstream>

using namespace cs225;
using namespace std;

//input: sorted vector of airport ids output: gif file
//find coordinates of airport -> create a dictionary that takes airport id as key and coordinate as a value.
//function that convert longitude and latitude into coordinate in map
//input: latitude and longitude variable, ouput: coordinates
//function that changes the color of pixel of the coordinates -> to create a point for the airport position
//input: coordinate class variable, reference to the png variable output: void
//function that draws a line between two coordinates
//input: coordinate class variable start, coordinate class variable end, reference to the png variable output:void



Vector2 Visualize::maptocoord(double longitude, double latitude){
    int height = 318;
    int width = 637;
    double latRad = latitude * M_PI/180;
    double mercN = log(tan((M_PI/4)+(latRad/2)));

    int x = fmod((width*(180+longitude)/360), (width + (width/2)));
    int y = (height/2) - (width*mercN/(2*M_PI));

    return Vector2(x, y);
}

//create a circle with radius 5 and draw on png
void Visualize::drawPixel(int x, int y, PNG & png){
    Circle circle(Vector2(x, y), color::BLUE, 2);
    circle.draw(&png);
}    

     

void Visualize::drawLine(int x1, int y1, int x2, int y2, PNG & png){
    Line line(Vector2(x1, y1), Vector2(x2, y2), color::DARKGRAY);
    line.draw(&png);
}

void Visualize::visualize(std::vector<std::string> input) {
    PNG* map = new PNG();
    map->readFromFile("map.png");
    unsigned width = map->width();
    unsigned height = map->height();
    PNG* output = new PNG(*map);
    
    std::unordered_map<std::string, Vector2> airportLocations;
    // airportLocations[''] = Coordinate(30, 10); template for the map
    // airportLocations['']
    std::ifstream fin("airport.csv");
    int count = 0;
  
    std::vector<std::string> row;
    std::string line, word, temp;
    fin>>temp;
    while (fin >> line) {
  
        row.clear();
        std::stringstream s(line);
  
        while (std::getline(s, word, ',')) {
            row.push_back(word);
        }
        Vector2 cur = maptocoord(stod(row[5]),stod(row[4]));
        airportLocations[row[3]] = cur;
        
    }
    

    for(int i = 0; i < (int)input.size()-1; i++){
        Vector2 & cur = airportLocations[input[i]];
        Vector2 & next = airportLocations[input[i+1]];
        drawPixel(cur.x(), cur.y(), *output);
        drawPixel(next.x(), next.y(), *output);
        drawLine(cur.x(), cur.y(), next.x(), next.y(), *output);
    }

    output -> writeToFile("answer.png");

    delete output;
    delete map;
}