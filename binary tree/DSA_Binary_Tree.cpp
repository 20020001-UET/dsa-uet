#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> tree;
vector<int> level;
bool result;

void input()
{
    cin >> n;
    tree.resize(n);
    for (int i = 0; i < n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
    }
}

void init()
{
    level.clear();
    level.resize(n, 0);
    result = true;
}

void checkTree(int u, int lastLevel)
{   
    level[u] = lastLevel+1;
    for (int v : tree[u]) 
    {
        if (level[v] == 0)
        {
            checkTree(v, level[u]);
        }
        else
        {
            result = false;
        }
    }
}

bool checkBinaryTree()
{
    for (int u = 0; u < tree.size(); u++)
    {
        if (tree[u].size() > 2)
        {
            return false;
        }
    }

    init();

    checkTree(0, 0);

    return result;
}

void solve()
{
    if (checkBinaryTree())
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}

int main()
{
    input();
    solve();
    return 0;
}