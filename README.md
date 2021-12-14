CS225 Fall 2021 Final Project

Abhitya Krishnaraj, Tony Wei, Vivian Choi, Yusong Wang

Overview

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

All the major code is located within the main folder.

Main.cpp contains the main function that is run.

The documentation folder contains any text files like the DEVELOPMENT, GOALS, and Team Contract.

The data folder contains most of the csv files that were used in the project, the only csv file that is outside of the folder is the allroutes.csv file.

The frames folder contains the PNG's that make up the outputted GIF file.

