#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(int argc, char const *argv[])
{

    int t, k;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        string res;
        int i, n;
        cin >> n;
        vector<pair<int, pair<int, int>>> v;
        int s[n], e[n];
        for (int i = 0; i < n; i++)
        {

            cin >> s[i] >> e[i];
            v.push_back({s[i], {e[i], i}});
            res += 'C';
        }

        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i].first << ' ' << v[i].second.first << ' ' << v[i].second.second << endl;
        }
        int c = 0, j = 0, flag = 0;//c,j = last ending time for c and j respectively
        for (int i = 0; i < v.size(); i++)
        {

            if (v[i].first >= c)
            {
                res[v[i].second.second] = 'C';
                c = v[i].second.first;
            }

            else if (v[i].first >= j)
            {
                res[v[i].second.second] = 'J';
                j = v[i].second.first;
            }

            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            cout << "Case #" << k + 1 << ": "
                      << "IMPOSSIBLE" << endl;
            continue;
        }
        cout << "Case #" << k + 1 << ": " << res << endl;
    }
    return 0;
}