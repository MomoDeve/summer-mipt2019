#include<iostream>
#include <vector>
#include <cmath>
#include <set>
#include <functional>

#define EMPTY -1

using namespace std;

vector<vector<int> > Gr;
vector<int> pr, used;

bool dfs(int v)
{
	if (used[v]) return false;
	used[v] = true;
	for (int u : Gr[v])
	{
		if (pr[u] == EMPTY || dfs(pr[u]))
		{
			pr[u] = v;
			return true;
		}
	}
	return false;
}

int main ()
{
	int n, m, ans = 0;
	cin >> n >> m;
	used.resize(n);
	pr.assign(m, EMPTY);
	Gr.resize(n);
	int v;
	for (int i = 0; i < n; i++)
	{
		while (cin >> v)
		{
			if (v == 0) break;
			Gr[i].push_back(v - 1);
		}
	}
	for (int i = 0; i < n; i++)
	{
		used.assign(n, false);
		if (dfs(i))
		{
			ans++;
		}
	}
	cout << ans << endl;

	for (int i = 0; i < pr.size(); i++)
	{
		if (pr[i] != EMPTY)
		{
			cout << pr[i] + 1 << ' ' << i + 1 << endl;
		}
	}
}
