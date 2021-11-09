

**Final Project Proposal**

Question

Our aim is to find the smallest amount of time it would take to visit the 40 of the

most popular cities to visit/travel through in the world. A potential passenger inputs their

desired starting city and ending city, and in return will get an output of the path with

minimum flight time spent based on optimal predicted times or realistic flight times. We

also give the passenger two options, a path that randomly visits all 40 destinations or a

path that is continent restricted(passenger visits all of the cities within a continent before

moving on to another one).

Cities Used:

[https://docs.google.com/spreadsheets/d/10qROWMp9avkBSwOBKGd6O9PxxSMO2SQ](https://docs.google.com/spreadsheets/d/10qROWMp9avkBSwOBKGd6O9PxxSMO2SQRJCa5j3WpNPQ/edit?usp=sharing)

[RJCa5j3WpNPQ/edit?usp=sharing](https://docs.google.com/spreadsheets/d/10qROWMp9avkBSwOBKGd6O9PxxSMO2SQRJCa5j3WpNPQ/edit?usp=sharing)

Dataset Acquisition and Processing

We will be using the airport data from the open flights airport database to get

anything relevant such as airport code, destination, number of stops, etc. Once we have

retrieved said information, we can further import the data as a csv file in which case

processing can be treated similar to string and array processing. In addition to getting

information that is not included within the **open flights** database, like that of flight time,

we will explore other options, like <https://www.flightsfrom.com/LOS/destinations>. In this

case, the data will be added manually and added to the csv files from the open flights

data.

Algorithms

Traversals(BFS/DFS) are used to decide the order of updating distance of

neighboring cities. By analyzing, the traversal method chosen doesn’t affect time

complexity of the algorithm or the result.

Dijkstra’s Algorithm decides the minimum path from one predetermined starting

point to any of the other 50 cities. From the starting city, each neighbor has a cumulative

distance from it’s previous visited site. When a shorter value presents, the current

distance is updated. It has time complexity of O(E\*log(V)) with E representing edges, V





representing vertices. In this scenario, (40 cities) vertices and (Number of flights

available between those cities) edges.

The Floyd–Warshall algorithm finds the minimum path among all pairs of starting

points and ending cities. The algorithm differs from that of Dijkstra as it incorporates

bidirectional edges with varying weights that stimulate real time flight paths between

airports. Optimal runtimes for this case is O(n^3) whereas a more realistic algorithm

runtime is O(n\*(n+e)\*log n). Other than the simple difference in weight accounting and

bidirectional approach, the solution is relatively the same for both algorithms in terms of

solving for shortest paths.

Timeline

**Week 1(11/8-11/14) :**

● Find the bi-directional data for all possible airport flight times and link

corresponding data

● Clean and find any extraneous data points that weren’t previously found

**Week 2 (11/15-11/21):**

● Complete the written code for the algorithms and begin base testing for small

scale trips utilizing just the Floyd-Warshall Algorithm to fulfill realistic flight time

paths. (Team 1)

● Complete the algorithm necessary for Djikstra in order to satisfy requirements of

optimal predicted time. (Team 2)

**Week 3 (11/22- 11/28 Thanksgiving):**

● No task to celebrate indians

**Week 4 (11/29 - 12/5):**

● Test and improve the code and algorithms, creating/running tests to ensure

validity of code

**Final Week (12/6-12/13):**

● Finalize all presentation materials, report, final video, and presentation, conduct

extreme last minute testing to make sure the code works as expected

