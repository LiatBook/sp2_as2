//212736417
//bookliat@gmail.com
#include "Graph.hpp" 
#include <unordered_set>
#include <iostream>
#include <vector>
#include <limits> 
#include <queue>
#include <string>
#pragma once
using std::vector;
using std::string;
using std::pair;
namespace ariel 
{

class Algorithms    
{
    public:
    static bool isConnected(const Graph& g);
    static void dfs(size_t v, vector<bool>& visited,const Graph& g);
    static string isContainsCycle(const Graph& g);
    static string isBipartite(const Graph& g);
    static bool isBipartiteUtil(const Graph& g, size_t src, vector<int>& color, vector<int>& verticesInSetA, vector<int>& verticesInSetB) ;
    static string containsCycleUtil(const Graph& g, size_t v, int parent, vector<bool>& visited);
    static string shortestPath(const Graph& g, size_t start, size_t end);
    static  void bfs(const Graph & graph, size_t start, vector<bool>& visited, vector<int>& distance, vector<int>& parent);
    // static string bfs(const Graph &graph,size_t start, size_t end);
    static bool bellmanFord(const Graph& g,size_t source,vector<int> &distance,vector<int> &parent);
    static bool negativeCycle(const Graph& g, size_t start);

};

};