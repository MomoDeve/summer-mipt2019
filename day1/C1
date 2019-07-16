#include<iostream>
#include <vector>
#include <cmath>
#include <set>
#include <functional>
#include <sstream>
#include <algorithm>

#define EMPTY -1

using namespace std;

vector<vector<int> > tmp, Gr_l, Gr_r;
vector<int> used_l, used_r, par_l, par_r;

#define LEFT 1
#define RIGHT 0

void dfs(int v, bool isLeft)
{
	if (isLeft)
	{
		if (used_l[v]) return;
		used_l[v] = true;
		for (int u : Gr_l[v])
		{
			if (par_l[v] != u)
			{
				dfs(u, RIGHT);
			}
		}
	}
	else
	{
		if (used_r[v]) return;
		used_r[v] = true;
		for (int u : Gr_r[v])
		{
			if (par_r[v] == u)
			{
				dfs(u, LEFT);
			}
		}
	}
}

bool parsoch_dfs(int v)
{
	if (used_l[v]) return false;
	used_l[v] = true;
	for (int u : Gr_l[v])
	{
		if (par_r[u] == EMPTY || parsoch_dfs(par_r[u]))
		{
			par_r[u] = v;
			par_l[v] = u;
			return true;
		}
	}
	return false;
}

void make_parsoch(int n)
{
	for (int i = 0; i < n; i++)
	{
		used_l.assign(n, false);
		parsoch_dfs(i);
	}
	used_l.assign(n, false);
}

int main()
{
	int n, m, k;

	cin >> k;
	for (int y = 0; y < k; y++)
	{
		cin >> n >> m;
		par_l.resize(n, EMPTY);
		par_r.resize(m, EMPTY);
		Gr_l.resize(n);
		Gr_r.resize(m);
		tmp.resize(n);
		used_l.resize(n);
		used_r.resize(m);

		int v;
		for (int i = 0; i < n; i++)
		{
			while (cin >> v)
			{
				if (v == 0) break;
				tmp[i].push_back(v - 1);
			}
		}

		for (int i = 0; i < n; i++)
		{
			if(tmp[i].size() > 1)
				sort(tmp[i].begin(), tmp[i].end());
		}

		for (int i = 0; i < n; i++)
		{
			int t = 0;
			for (int j = 0; j < m; j++)
			{
				if (t < tmp[i].size() && tmp[i][t] == j)
				{
					t++;
				}
				else
				{
					Gr_l[i].push_back(j);
					Gr_r[j].push_back(i);
				}
			}
		}

		make_parsoch(n);

		for (int i = 0; i < n; i++)
		{
			if (par_l[i] == EMPTY)
			{
				dfs(i, LEFT);
			}
		}
		stringstream ss_l, ss_r;
		int size_l = 0, size_r = 0;
		for (int i = 0; i < used_l.size(); i++)
		{
			if (used_l[i])
			{
				size_l++;
				ss_l << i + 1 << ' ';
			}
		}
		for (int i = 0; i < used_r.size(); i++)
		{
			if (!used_r[i])
			{
				size_r++;
				ss_r << i + 1 << ' ';
			}
		}
		cout << size_l + size_r << endl;
		cout << size_l << ' ' << size_r << endl;
		cout << ss_l.str() << endl;
		cout << ss_r.str() << endl;

		par_l.clear();
		par_r.clear();
		Gr_l.clear();
		Gr_r.clear();
		tmp.clear();
		used_l.clear();
		used_r.clear();
	}
	system("pause");
}
