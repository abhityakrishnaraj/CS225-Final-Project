#pragma once
#include "stdio.h"
#include "limits.h"
#include "vector"
#include "stack"
#include "iostream"

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

void getPath(int parent[], int goal, vector<int>& path){
    if(parent[goal] == -1)
        return;
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

int main(){
    int start;
    int goal;
    int graph[V][V];
    vector<int> path = djikstra(graph, start, goal);
    return 0;
}
