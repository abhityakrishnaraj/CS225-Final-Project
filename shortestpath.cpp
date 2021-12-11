#pragma once
#include "stdio.h"
#include "limits.h"

#define V 40

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

vector<int> getPath(int parent[], int goal){
    vector<int> path;
    if(parent[goal] == -1)
        return NULL;
    getPath(parent, parent[goal]);
    path.push_back(goal);
    printf("%d", goal);
}

void djikstra(int graph[V][V], int start, int goal){
    int dist[V];
    int parent[V];
    bool visit[V];

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
    getPath(parent, goal);
}

int main(){
    int start;
    int goal;
    int graph[V][V];
    djikstra(graph, start, goal);
    return 0;
}