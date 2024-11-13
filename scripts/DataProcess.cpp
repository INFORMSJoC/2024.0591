#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define PII pair<int, int>

struct Edge
{
    int to;
    double p;
    Edge(int a = 0, double b = 0) : to(a), p(b) {}
};

int main()
{
    string fileName, outName;
    cin >> fileName;
    fileName = "../data/" + fileName;
    outName = "../data/processed-" + fileName;
    ifstream in(fileName.c_str());
    ofstream out(outName.c_str());
    int n, m;
    in >> n >> m;
    out << n << "\t" << m << endl;
    vector<PII> E;
    unordered_map<int, int> name2id;
    int id = 0;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        in >> x >> y;
        if (name2id.find(x) == name2id.end())
            name2id[x] = id, id++;
        if (name2id.find(y) == name2id.end())
            name2id[y] = id, id++;
        x = name2id[x];
        y = name2id[y];
        E.push_back(PII(x, y));
        out << x << "\t" << y << endl;
    }
    return 0;
}