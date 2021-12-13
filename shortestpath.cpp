#pragma once
#include "stdio.h"
#include "limits.h"

#define V 5

using namespace std;

int minDist(int dist[], bool visit[]){
    int min = INT_MAX, idx;

    for(int i = 0; i < V; i++)
        if(visit[i] == false && dist[i] <= min){
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
    printf("%d", goal);
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
    parent[0] = -1;
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

int main(){
    int start = 0;
    int goal = 4;
    int graph[V][V] = {{0, 0, 1, 0, 2},
                       {0, 0, 0, 3, 4}, 
                       {2, 0, 0, 5, 2},
                       {1, 4, 4, 0, 2}, 
                       {3, 3, 3, 3, 0}};
    vector<int> path = djikstra(graph, start, goal);
    return 0;
}
