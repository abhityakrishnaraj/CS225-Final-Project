

**Final Project Proposal**

Question

Our aim is to find the shortest path it would take to visit the 40 of the most

popular cities to visit/travel throughout the world. We specifically selected 40 cities

based on their population, tourist population, and airport traffic numbers.

([https://docs.google.com/spreadsheets/d/10qROWMp9avkBSwOBKGd6O9PxxSMO2S](https://docs.google.com/spreadsheets/d/10qROWMp9avkBSwOBKGd6O9PxxSMO2SQRJCa5j3WpNPQ/edit?usp=sharing)

[QRJCa5j3WpNPQ/edit?usp=sharing](https://docs.google.com/spreadsheets/d/10qROWMp9avkBSwOBKGd6O9PxxSMO2SQRJCa5j3WpNPQ/edit?usp=sharing)).

We set up a graph where each node represents the selected cities and each

edge represents the flight time between two cities. We are creating a scenario where

the passenger at hand does not want to spend more than 12 hours (720 minutes) on a

flight (essentially no overnight flights).This passenger inputs their desired starting city

and ending city, and in return will get an output of the shortest path based on optimal

predicted flight times. He will also be shown a map of the Minimum Spanning Tree that

encompases all 40 cities in question.

Dataset Acquisition and Processing

We will be using the airport data from the open flights airport database to get

relevant information about the airports in the 40 cities, such as airport, city, country,

continent, IATA code, latitude, and longitude. We will be filtering out the necessary

airports from the list of thousands of airports found on the open flights database. To find

data on flight times and routes between cities we will be manually inputting data from

<https://www.flightsfrom.com/>[ ](https://www.flightsfrom.com/)into a separate database, adding information about the

route between two cities including: departure airport code, departure city, flight time in

minutes, destination airport code, and destination city.

**Sample airport data:** "London Heathrow Airport", "London", "United Kingdom",

“Europe”, "LHR", 51.4706, -0.461941

**Sample Route Data for shortest path:** “LGW”, “London”, 75, “CDG”, “Paris” / “CDG”,

“Paris”, 65, “LGW”, “London” (directed paths between cities)

**Sample Route Data for MST:** “LGW”, “London”, “65”, “CDG”, “Paris” / “CDG”, “Paris”,

65, “LGW”, “London” (undirected path between cities)

Our graph will be created by each airport representing a node/vertex and each

route from one city to another will either be a directional edge (for shortest path) or

undirected edge (for MST) connecting those nodes.

Algorithms

Traversals(BFS/DFS) are used to decide the order of updating distance of

neighboring cities. By analyzing, the traversal method chosen doesn’t affect time

complexity of the algorithm or the result.

Dijkstra’s Algorithm decides the minimum path from one predetermined starting

point to any of the other 40 cities. From the starting city, each neighbor has a cumulative





distance from it’s previous visited site. When a shorter value presents, the current

distance is updated. It has a time complexity of O(V^2), V representing vertices. In this

scenario, (40 cities) vertices and (Duration of a flight between those cities) edges.

Dijkstra’s Algorithm gives us the shortest path connected by flights between two cities

without restriction on the number of places visited.

Dijkstra’s Input: 2D array with directed paths representing routes from one city to

another.

Output: List of cities and airports visited, time it takes to go from one city to

another, total time.

We will be using Kruskal’s algorithm to build a minimum spanning tree by sorting

edges in ascending order. An array is used to store the weighted edges, and disjoint

sets to keep track of nodes that are connected. First the edges are sorted, then

separate disjoint sets are initialized for each vertex. For each edge connecting two

vertices, if the two vertices are in different sets, union the two sets that contain the

vertices. Add that path(edge) to the solution. Kruskal’s algorithm has O(E\*log(E))

running time, where E is the number of edges.

Kruskal’s input: 2D array with an undirected path representing routes that

connect one city to another.

Output: A graph highlighting the routes that represent the minimum spanning tree

of the input airports and routes.

Timeline

**Week 1(11/8-11/14) :**

● Clean the airport data, cutting out extraneous data points and columns from the

openflights database

● Create the undirected and directed databases from the FlightsFrom data

**Week 2 (11/15-11/21):**

● Start working on the written code for the Kruskal algorithm (Team 1)

● Start working on the written code for the Djikstra algorithm (Team 2)

**Week 3 (11/22- 11/28 Thanksgiving):**

● Finish the Kruskal and Djikstra algorithms and test the each algorithm with basc

test to ensure they are working

● Start work on displaying a map of the world with points indicating locations of

airports

**Week 4 (11/29 - 12/5):**

● Test and improve the code and algorithms running test on the full sets of data

● Work on adding paths atop the map of the world to display the shortest path and

MST

**Final Week (12/6-12/13):**

● Finalize all presentation materials, report, final video, and presentation, conduct

extreme last minute testing to make sure the code works as expected

