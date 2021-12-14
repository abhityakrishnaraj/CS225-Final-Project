# CS225 Fall 2021 Final Project

Abhitya Krishnaraj, Tony Wei, Vivian Choi, Yusong Wang

## Overview

Our project looks at the data obtained from flightsfrom.com that details the length of flight routes 

between cities combined with general data about the location of airports within cities to determine

the shortest path between two cities based on a users input. The user will input a desired start city

and end city from the list of chosen cities (Tokyo, Delhi, Shanghai, Sao Paulo, Mexico City, Cairo, 

Mumbai, Beijing, Dhaka, Osaka, New York City, Karachi, Chongqing, Istanbul, Buenos Aires, Kolkata, Lagos, 

Dubai, Manila, Tianjin, Paris, Rome, Lima, Athens, Phnom Penh, Toronto, London, Jakarta, Sydney, Prague, 

Atlanta, Los Angeles, Chicago	, Hong Kong, Amsterdam, Guangzhou, Frankfurt, Singapore, Seoul, and Denver).

The program will output two ordered list of cities, one for the BFS algorithm and one for the Djikstra

algorithm, create two PNGs that displays the lists given by the two algorithms, and display a GIF that

marks out the exact route to take as dictated by the Djikstra algorithm.
 
***

## Location of Code

All the major code is located within the main folder.

Main.cpp contains the main function that is run. It takes care of reading data in from the csv files, 

formatting that data, and calling the functions that are declared in the other .cpp files.

The documentation folder contains any text files like the DEVELOPMENT, GOALS, and Team Contract.

The data folder contains most of the csv files that were used in the project, allroutes.csv and 

map.png are the two sources of data that are outside of the folder.

The video presentation is the mp4 file in the main folder called "Final Video.mp4".

***
### Use of CSV
The csv files we use in this project is all written on the main function. The file allroutes.csv in root folder is used to create adjacency list of cities and file cities.csv, which is in the Data folder, is used to store the information(city name, airport code, continent, etc.) in the order of cities in the adjacency list(0, 39).  airport.csv file in the Data folder is used to get the longitude and latitude information of each city airports as an input for the maptocoord function. 

### Testing, Inputs, and Outputs

The code can be compiled in terminal when within the main folder like this: 

```
$ make
$ ./visualize
```

This will prompt the user to first enter the name of a start city and then the destination. The inputs

are only recognized if they are in the same format as expected, with the city's name being in proper

case format ex: New York City.

The output seen in the terminal consists of two written shortest path lists of cities Ex: New York

City Paris Cairo, for the BFS output and the Djikstra's output. The other output of the code is seen in 

PNG and GIF format. The BFS route is seen in "BFS Route.png" and the Djikstra's route is in "NonanimatedSolution.png".

The GIF file can be seen on GitHub at "AnimatedSolution.gif". Unfortunately the gif sometimes doesn't work

as intended while looking at it withing the cloned folder in EWS, however; it works normally fine once it is 

pushed to GitHub. The PNG files that make up the GIF file are found within the frames folder.
