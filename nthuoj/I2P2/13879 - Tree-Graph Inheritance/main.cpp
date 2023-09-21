#include "function.h"

#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> edges(n - 1);
#if __cplusplus >= 201703L
    for (auto &[a, b] : edges)
    {
#else
    for (vector<pair<int, int>>::iterator itr = edges.begin(); itr != edges.end(); itr++)
    {
        int &a = itr->first, &b = itr->second;
#endif
        cin >> a >> b;
    }
    tree t(n, edges);
#if __cplusplus >= 201703L
    for (int i : t.bfs(0))
        cout << i << ' ';
#else
    vector<int> d = t.bfs(0);
    for (auto itr = d.begin(); itr != d.end(); itr++)
        cout << *itr << ' ';
#endif
    cout << '\n'
         << t.diameter() << '\n';
    return 0;
}
