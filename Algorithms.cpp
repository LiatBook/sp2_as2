//212736417
//bookliat@gmail.com
#include "Algorithms.hpp"

using namespace ariel;

using std::queue;
using std::vector;

void Algorithms::dfs(size_t v, vector<bool> &visited, const Graph &g)
{
    // Mark the current vertex as visited
    visited[v] = true;
    // Traverse all adjacent vertices of v
    for (size_t u = 0; u < visited.size(); ++u)
    {
        if (g.getGraph()[v][u] != 0 && !visited[u])
        {
            dfs(u, visited, g); // Recursive DFS call for unvisited adjacent vertices
        }
    }
}

bool Algorithms::isConnected(const Graph &g)
{
    // Check if the graph has been loaded
    if (g.getGraph().empty())
    {
        std::cout << "Error: Graph is not loaded." << std::endl;
        return false;
    }

    // Create a vector to mark visited vertices
    vector<bool> visited(g.getGraph().size(), false);

    // Perform depth-first search (DFS) starting from the first vertex
    dfs(0, visited, g);

    // Check if all vertices are visited
    for (bool v : visited)
    {
        if (!v)
        {
            return false; // If any vertex is not visited, the graph is not connected
        }
    }

    return true; // If all vertices are visited, the graph is connected
}

string Algorithms::isContainsCycle(const Graph &g)
{
    vector<bool> visited(g.getGraph().size(), false);
    for (size_t i = 0; i < g.getGraph().size(); ++i)
    {
        if (!visited[i])
        {
            string cycle = containsCycleUtil(g, i, -1, visited);
            if (!cycle.empty())
            {
                return cycle;
            }
        }
    }
    return "0";
}

string Algorithms::containsCycleUtil(const Graph &g, size_t v, int parent, vector<bool> &visited)
{
    visited[v] = true;
    for (size_t u = 0; u < g.getGraph().size(); ++u)
    {
        if (g.getGraph()[v][u] != 0)
        {
            if (!visited[u])
            {
                string cycle = containsCycleUtil(g, u, v, visited);
                if (!cycle.empty())
                {
                    // Append the current vertex to the cycle
                    return (v == stoi(cycle.substr(0, cycle.find("->"))) ? cycle : std::to_string(v) + "->" + cycle);
                }
            }
            else if (u != parent)
            {
                // Cycle detected, return the cycle
                return std::to_string(v) + "->" + std::to_string(u);
            }
        }
    }
    visited[v] = false; // Resetting visited status for backtracking
    return "";
}

string Algorithms::isBipartite(const Graph &g)
{
    std::vector<int> color(g.getGraph().size(), -1);
    std::vector<int> verticesInSetA, verticesInSetB;
    verticesInSetA.push_back(0);

    for (size_t i = 0; i < g.getGraph().size(); ++i)
    {
        if (color[i] == -1)
        {
            if (!isBipartiteUtil(g, i, color, verticesInSetA, verticesInSetB))
            {
                return "0";
            }
        }
    }

    // create the result string
    string result = "The graph is bipartite: A={";
    for (size_t i = 0; i < verticesInSetA.size() - 1; i++)
    {
        result += std::to_string(verticesInSetA[i]);
        result += ", ";
    }
    if (!verticesInSetA.empty())
        result += std::to_string(verticesInSetA.back());

    result += "}, B={";
    for (size_t i = 0; i < verticesInSetB.size() - 1; i++)
    {
        result += std::to_string(verticesInSetB[i]);
        result += ", ";
    }
    if (!verticesInSetB.empty())
        result += std::to_string(verticesInSetB.back());

    result += "}";
    return result;
}

bool Algorithms::isBipartiteUtil(const Graph &g, size_t src, vector<int> &color, vector<int> &verticesInSetA, vector<int> &verticesInSetB)
{
    color[src] = 1; // Color the source vertex with 1
    std::queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        size_t u = (size_t)q.front();
        q.pop();

        for (size_t v = 0; v < g.getGraph().size(); ++v)
        {
            if (g.getGraph()[u][v] != 0)
            {
                if (color[v] == -1)
                {
                    color[v] = 1 - color[u]; // Assign alternate color to this adjacent vertex
                    q.push(v);
                    if (color[v] == 0)
                        verticesInSetB.push_back(v);
                    else
                        verticesInSetA.push_back(v);
                }
                else if (color[v] == color[u])
                {
                    return false; // If adjacent vertices have the same color, the graph is not bipartite
                }
            }
        }
    }
    return true;
}

bool Algorithms::negativeCycle(const Graph &g, size_t start)
{

    vector<int> distance(g.getGraph().size(), std::numeric_limits<int>::infinity());
    vector<int> parent(g.getGraph().size(), -1);
    return !bellmanFord(g, start, distance, parent);
}

void Algorithms::bfs(const Graph &graph, size_t start, vector<bool> &visited, vector<int> &distance, vector<int> &parent)
{
    size_t size = graph.getGraph().size();
    queue<int> q;
    q.push(start);
    visited[start] = true;
    distance[start] = 0;

    while (!q.empty())
    {
        size_t u = (size_t)q.front();
        q.pop();

        for (size_t v = 0; v < size; v++)
        {
            if (graph.getGraph()[u][v] != 0 && !visited[v])
            {
                visited[v] = true;
                distance[v] = distance[u] + 1;
                parent[v] = u; // Update the parent of v
                q.push(v);
            }
        }
    }
}
string Algorithms::shortestPath(const Graph &g, size_t start, size_t end)
{

    vector<bool> visited(g.getGraph().size(), false);
    vector<int> distance(g.getGraph().size(), std::numeric_limits<int>::infinity()); // TODO: change to INF
    vector<int> parent(g.getGraph().size(), -1);   // This is will be the path that we will print to see the shortest path

    // If the graph is not weighted, use BFS to find the shortest path
    if (!g.getWeighted())
    {
        // return bfs(g,start,end);
        bfs(g, start, visited, distance, parent);

        if (distance[end] != std::numeric_limits<int>::infinity()) // TODO change to INF
        {
            string path = std::to_string(end);
            int p = parent[end];
            while (p != -1)
            {
                path.insert(0, std::to_string(p) + "->");
                p = parent[(size_t)p];
            }
            return path;
        }
        else
        {
            return "-1";
        }
    }
    else
    {
        if (bellmanFord(g, start, distance, parent))
        {

                if(distance[end]==std::numeric_limits<int>::infinity())
                {
                    return "-1";
                }

            string path = std::to_string(end);
            int p = parent[end];
            while (p != -1)
            {
                path.insert(0, std::to_string(p) + "->");
                p = parent[(size_t)p];
            }
            return path;
        }

        else
        {
            return "-1";
        }
    }
}

bool Algorithms::bellmanFord(const Graph &g, size_t source, vector<int> &distance, vector<int> &parent)
{

    distance[source] = 0;
    // Relax edges repeatedly
    for (size_t i = 0; i < g.getGraph().size() - 1; ++i)
    {
        for (size_t u = 0; u < g.getGraph().size(); ++u)
        {
            for (size_t v = 0; v < g.getGraph().size(); ++v)
            {
                if (g.getGraph()[u][v] != 0 && distance[u] != std::numeric_limits<int>::infinity() && distance[u] + g.getGraph()[u][v] < distance[v])
                {
                    distance[v] = distance[u] + g.getGraph()[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (size_t u = 0; u < g.getGraph().size(); ++u)
    {
        for (size_t v = 0; v < g.getGraph().size(); ++v)
        {
            if (g.getGraph()[u][v] != 0 && distance[u] != std::numeric_limits<int>::infinity() && distance[u] + g.getGraph()[u][v] < distance[v])
            {
                std::cout << "Graph contains negative-weight cycle\n";
                return false;
            }
        }
    }

    return true;
}
