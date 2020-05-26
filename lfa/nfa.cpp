#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

ifstream fin("nfa.in");
ofstream fout("nfa.out");

const int MAXN = 1005;
const int MAXL = 155;
int n, m, nr;
int st;
bool final[MAXN];
string s;
bool found;
vector<pair<int, char>> v[MAXN];
bool visited[MAXN][MAXL];

void solve(int node, int cr) {
    if (cr == s.length()) {
        if (final[node]) {
            found = 1;
        }
    }
    else {
        for (int i = 0; i < v[node].size(); ++i) {
            if (v[node][i].second == s[cr]) {
                if (visited[v[node][i].first][cr] == false) {
                    visited[v[node][i].first][cr] = true;
                    solve(v[node][i].first, cr + 1);
                }
            }
        }
    }
}

int main() {

    fin >> n >> m >> nr;
    fin >> st;
    for (int i = 0; i < nr; ++i) {
        int a;
        fin >> a;
        final[a] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        fin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }
    int q;
    fin >> q;
    for (int var = 0; var < q; ++var) {
        fin >> s;
        found = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= s.size(); ++j) {
                visited[i][j] = 0;
            }
        }
        solve(st, 0);
        fout << found << '\n';
    }

    fout.close();
    return 0;
}