#include <fstream>
#include <sstream>
#include <cstdio>
#include <climits>
#include <stack>
#include <iostream>
#include "cs225/PNG.h"
#include "gifFunction.hpp"
#include "visualize.h"
#include <vector>

#define V 40

using namespace cs225;
using namespace std;

int minDist(const int dist[], const bool visit[]){
    int min = INT_MAX, idx;

    for(int i = 0; i < V; i++)
        if(!visit[i] && dist[i] <= min){
            min = dist[i];
            idx = i;
        }
    return idx;
}

void getPath(int parent[], int goal, vector<int>& path){
    if(parent[goal] == -1){
        path.push_back(goal);
        printf("%d", goal);
        return;
    }
    
    getPath(parent, parent[goal], path);
    path.push_back(goal);
    printf("%d, ", goal);
}

// void getPath(int parent[], int goal, vector<int>& path){
//     std::cout<<goal;
//     if(parent[goal] == -1){
//         path.push_back(goal);
//         printf("%d", goal);
//         return;
//     }
//     while()
//     getPath(parent, parent[goal], path);
//     path.push_back(goal);
//     printf("%d, ", goal);
// }

vector<int> djikstra(int graph[V][V], int start, int goal){
    int dist[V];
    int parent[V];
    bool visit[V];
    vector<int> path;

    for(int i = 0; i < V; i++){
        dist[i] = INT_MAX;
        visit[i] = false;
    }
    parent[start] = -1;
    dist[start] = 0;
    for(int j = 0; j < V-1; j++){
        int m = minDist(dist, visit);
        visit[m] = true;
        for(int k = 0; k < V; k++){
            if(!visit[k] && graph[m][k] && (dist[m] + graph[m][k]) < dist[k]){
                parent[k] = m;
                dist[k] = dist[m] + graph[m][k];
            }
        }
    }
    getPath(parent, goal, path);
    return path;
}

bool isValid(bool vis[][V], int row, int col) {
    if (row < 0 || col < 0 || row >= V || col >= V)
        return false;

    if (vis[row][col]) {
        return false;
    }
    return true;
}

void dfs(int row, int col, int grid[V][V], bool vis[][V]) {
    int direction_row[] = { 0, 1, 0, -1 };
    int direction_col[] = { -1, 0, 1, 0 };
    
    stack<pair<int, int> > s;
    s.push({row, col});
    
    while (!s.empty()) {
        pair<int, int> curr = s.top();
        s.pop();
        int r = curr.first;
        int c = curr.second;

        if (!isValid(vis, r, c)) {
            continue;
        }

        vis[row][col] = true;
        std::cout << grid[r][c] << " ";

        for (int i = 0; i < V; i++) {
            int x = r + direction_row[i];
            int y = c + direction_col[i];
            s.push({x, y});
        }
     }
}

bool BFS(vector<int> adj[V], int start, int goal, int parent[], int dist[]){
    queue<int> q;
    bool visit[V];
    for(int i = 0; i < V; i++){
        visit[i] = false;
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    
    visit[start] = true;
    dist[start] = 0;
    q.push(start);
    
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(int i = 0; i < adj[f].size(); i++){
            if(visit[adj[f][i]] == false){
                visit[adj[f][i]] = true;
                dist[adj[f][i]] = dist[f] + 1;
                parent[adj[f][i]] = f;
                q.push(adj[f][i]);
                if(adj[f][i] == goal)
                    return true;
            }
        }
    }
    return false;
}

int getCity(string input, string cities[V]) {
    /*string cities[40] = {"Tokyo", "Delhi", "Shanghai", "Sao Paulo", "Mexico City", "Cairo", "Mumbai", "Beijing", 
                         "Dhaka", "Osaka", "New York City", "Karachi", "Chongqing", "Istanbul", "Buenos Aires", 
                         "Kolkata", "Lagos", "Dubai", "Manila", "Tianjin", "Paris", "Rome", "Lima", "Athens", 
                         "Phnom Penh", "Toronto", "London", "Jakarta", "Sydney", "Prague", "Atlanta", "Los Angeles", 
                         "Chicago", "Hong Kong", "Amsterdam", "Guangzhou", "Frankfurt", "Singapore", "Seoul", "Denver"};*/
    
    for (int i = 0; i < V; i++) {
        if (cities[i] == input) {
            return i;
        }
    }
    cout << "Not a Valid City! \n";
    return -1;
}


// int main(){
//     /*
//     std::vector<std::string> temp;
//     std::vector<PNG> vec;
//     std::vector<std::string> input = {"NRT", "DEL", "LAX", "JFK", "PEK"};
//     Visualize v;
//     v.visualize(input).writeToFile("Final Route.png");
//     //do vector of PNGs
//     PNG base;
//     base.readFromFile("map.png");
//     vec.push_back(base);
//     for (unsigned i = 1; i < input.size(); i++) {
//         for (unsigned j = 0; j <= i; j++) {
//             temp.push_back(input[j]);
//         }

//         vec.push_back(v.visualize(temp));
//         temp.clear();
//     }

//     gifFunction x;
//     x.makeGif(vec);
//     */
    
//     int graph[V][V];
//     /*
//     string cities[40] = {"Tokyo", "Delhi", "Shanghai", "Sao Paulo", "Mexico City", "Cairo", "Mumbai", "Beijing",
//                          "Dhaka", "Osaka", "New York City", "Karachi", "Chongqing", "Istanbul", "Buenos Aires",
//                          "Kolkata", "Lagos", "Dubai", "Manila", "Tianjin", "Paris", "Rome", "Lima", "Athens",
//                          "Phnom Penh", "Toronto", "London", "Jakarta", "Sydney", "Prague", "Atlanta", "Los Angeles",
//                          "Chicago", "Hong Kong", "Amsterdam", "Guangzhou", "Frankfurt", "Singapore", "Seoul", "Denver"};
//     */
//     ifstream rout("routes.csv");
//     vector<int> row;
//     string line, word;
//     int count = 0;
//     while (rout >> line) {
//         row.resize(0);
//         stringstream s(line);

//         for (int i = 0; i < V; i++) {
//             getline(s, word, ',');
//             stringstream w(word);
//             int x = 0;
//             w >> x;
//             row.push_back(x);
//         }
//         copy(row.begin(), row.end(), graph[count]);
//         count++;
//     }
    
<<<<<<< HEAD
//     string cities[V];
//     string countries[V];
//     string continents[V];
//     string codes[V];
=======
    vector<int> adj[V];
    int lmtgraph[V][V];
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(graph[i][j]<600 && graph[i][j]>0){
                lmtgraph[i][j] = graph[i][j];
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
            else
                lmtgraph[i][j] = 0;
        }
    }
    
    string cities[V];
    string countries[V];
    string continents[V];
    string codes[V];
>>>>>>> dfae74047b3b5f39aff2897147151984e7219b6f
    
//     ifstream air("cities.csv");
//     count = 0;
//     while(air >> line){
//         stringstream s(line);
//         for(int i = 0; i < 4; i++){
//             getline(s, word, ',');
//             if(i == 0)
//                 cities[count] = word;
//             else if(i == 1)
//                 countries[count] = word;
//             else if(i == 2)
//                 continents[count] = word;
//             else
//                 codes[count] = word;
//         }
//         count ++;
//     }
    
//     int start = -1;
//     int end = -1;
    
//     while (start < 0) {
//         string in1;
//         cout << "Starting: ";
//         cin >> in1;
//         start = getCity(in1, cities);
//     }
    
//     while (end < 0) {
//         string in2;
//         cout << "Destination: ";
//         cin >> in2;
//         end = getCity(in2, cities);
//     }

//     vector<int> path = djikstra(graph, start, end);
//     vector<string> codepath;
//     for(int i = 0; i < path.size(); i++){
//         codepath.push_back(codes[path.at(i)]);
//     }
//     return 0;
// }
