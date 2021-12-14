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
#include <queue>

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
        return;
    }
    getPath(parent, parent[goal], path);
    path.push_back(goal);
}

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

vector<int> BFS(vector<int> adj[V], int start, int goal){
    int parent[V];
    int dist[V];
    queue<int> q;
    vector<int> path;
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
        for(unsigned i = 0; i < adj[f].size(); i++){
            if(!visit[adj[f][i]]){
                visit[adj[f][i]] = true;
                dist[adj[f][i]] = dist[f] + 1;
                parent[adj[f][i]] = f;
                q.push(adj[f][i]);
                if(adj[f][i] == goal){
                    getPath(parent, goal, path);
                    return path;
                }
            }
        }
    }
    for (auto it = path.begin(); it != path.end();) {
        path.erase(it);
    }
    return path;
}

int getCity(string input, string cities[V]) {
    for (int i = 0; i < V; i++) {
        if (cities[i] == input) {
            return i;
        }
    }
    cout << "Not a Valid City! \n";
    return -1;
}

