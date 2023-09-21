#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>
#include <limits>

using std::pair;
using std::vector;
using std::numeric_limits;

class graph
{
protected:
    int n;

private:
    vector<vector<int> > adjacent_lists;

public:
    graph(int _n, vector<pair<int, int> > edges) : n(_n), adjacent_lists(_n)
    {
#if __cplusplus >= 201703L
        for (auto [a, b] : edges)
        {
#else
        for (vector<pair<int, int> >::iterator itr = edges.begin(); itr != edges.end(); itr++)
        {
            int a = itr->first, b = itr->second;
#endif
            adjacent_lists[a].push_back(b);
            adjacent_lists[b].push_back(a);
        }
    }

    vector<int> bfs(int) const; // Perform BFS traversal on a graph.
};

class tree : public graph
{
public:
    tree(int n, vector<pair<int, int> > edges) : graph(n, edges) {}
    int diameter() const; // Find the diameter by BFS traversal.
};

#endif // FUNCTION_H


vector<int> graph::bfs(int source) const
{
    // TODO: Perform BFS traversal on a graph.
}

int tree::diameter() const
{
    // TODO: Find the diameter by BFS traversal.
}
