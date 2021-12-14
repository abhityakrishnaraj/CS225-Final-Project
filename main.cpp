#include "cs225/PNG.h"
#include "gifFunction.hpp"
#include "visualize.h"
#include <vector>
#include "shortestpath.cpp"
#include <queue>

using namespace cs225;
using namespace std;

int main(){
    int graph[V][V];
    ifstream rout("Data/routes.csv");
    vector<int> row;
    string line, word;
    int count = 0;
    rout>>line;
    while (rout >> line) {
        row.resize(0);
        stringstream s(line);
        getline(s, word, ',');      
        for (int i = 0; i < V; i++) {
            getline(s, word, ',');
            stringstream w(word);
            int x = 0;
            w >> x;
            row.push_back(x);
        }
        copy(row.begin(), row.end(), graph[count]);
        count++;
    }
    
    vector<int> adj[V];
    int lmtgraph[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] < 600 && graph[i][j] > 0) {
                lmtgraph[i][j] = graph[i][j];
                adj[i].push_back(j);
            } else {
                lmtgraph[i][j] = 0; 
            }
        }
    }
    
    string cities[V];
    string countries[V];
    string continents[V];
    string codes[V];
    
    
    ifstream air("Data/cities.csv");
    count = 0;
    while(air >> line){
        istringstream s;
        s.str(line);
        for(int i = 0; i < 4; i++){
            getline(s, word, ',');
            if(i == 0) {
                string temp;
                string temp2;
                int lastCap = 0;
                for(unsigned i = 1; i < word.size(); i++){
                    if(isupper(word.at(i)) && word.at(i-1) != ' '){
                        temp = word.substr(i);
                        temp2 = word.substr(lastCap, i-lastCap);
                        word = temp2 + " " + temp;
                        // cout<<word;
                    }
                }
                cities[count] = word;
            }
            else if(i == 1){
                string temp;
                string temp2;
                int lastCap = 0;
                for(unsigned i = 1; i < word.size(); i++){
                    if(isupper(word.at(i)) && word.at(i-1) != ' '){
                        temp = word.substr(i);
                        temp2 = word.substr(lastCap, i-lastCap);
                        word = temp2 + " " + temp;
                        // cout<<word;
                    }
                }
                countries[count] = word;
            }
            else if(i == 2)
                continents[count] = word;
            else
                codes[count] = word;
        }
        count ++;
    }
    
    int start = -1;
    int end = -1;
    while (start < 0) {
        string in1;
        cout << "Starting: ";
        cin >> in1;
        start = getCity(in1, cities);
    }
    
    while (end < 0) {
        string in2;
        cout << "Destination: ";
        cin >> in2;
        end = getCity(in2, cities);
    }
    vector<int> path = BFS(adj, start, end);
    
    if(path.empty())
        std::cout<<"No possible routes between" <<cities[start]<<"and"<<cities[end];
    
    vector<string> strpath;
    for(unsigned i = 0; i < path.size(); i++){
        cout << cities[path.at(i)] + " ";
        strpath.push_back(codes[path.at(i)]);
    }
    
    vector<string> & input2 = strpath;
                          
    Visualize v;
                          
    v.visualize(input2).writeToFile("BFS Route.png");
            
    path = djikstra(lmtgraph, start, end);
                          
    vector<string> codepath;
    for(unsigned i = 0; i < path.size(); i++) {
        cout << cities[path.at(i)] + " ";
        codepath.push_back(codes[path.at(i)]);
    }
    vector<string> & input = codepath;
    vector<string> temp;
    vector<PNG> vec;
    // v.visualize(input).writeToFile("Final Route.png");
    //do vector of PNGs
    PNG base;
    base.readFromFile("map.png");
    vec.push_back(base);
    for (unsigned i = 1; i < input.size(); i++) {
        for (unsigned j = 0; j <= i; j++) {
            temp.push_back(input[j]);
        }
        
        vec.push_back(v.visualize(temp));
        temp.clear();
    }
    
    gifFunction x;
    x.makeGif(vec);

}
