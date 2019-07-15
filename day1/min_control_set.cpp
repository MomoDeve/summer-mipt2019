#include<iostream>
#include <vector>
#include <cmath>
#include <set>
#include <functional>
#include <sstream>

#define EMPTY -1

using namespace std;

vector<vector<int> > Gr_l, Gr_r;
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

int main()
{
	int n, m, k;
	cin >> n >> m;
	par_l.resize(n, EMPTY);
	par_r.resize(m, EMPTY);
	Gr_l.resize(n);
	Gr_r.resize(m);
	used_l.resize(n);
	used_r.resize(m);
	int v;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> v;
			Gr_l[i].push_back(v - 1);
			Gr_r[v - 1].push_back(i);
		}
	}
	for (int i = 0; i < n; i++)
	{
		cin >> v;
		if(v != 0)
		{
			par_l[i] = v - 1;
			par_r[v - 1] = i;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (par_l[i] == EMPTY)
		{
			dfs(i, LEFT);
		}
	}
	stringstream ss_l, ss_r;
	int size_l= 0, size_r = 0;
	for (int i = 0; i < used_l.size(); i++)
	{
		if (!used_l[i])
		{
			size_l++;
			ss_l << i + 1 << ' ';
		}
	}
	for (int i = 0; i < used_r.size(); i++)
	{
		if (used_r[i])
		{
			size_r++;
			ss_r << i + 1 << ' ';
		}
	}
	cout << size_l + size_r << endl;
	cout << size_l << ' ' << ss_l.str() << endl;
	cout << size_r << ' ' << ss_r.str() << endl;
	system("pause");
}
