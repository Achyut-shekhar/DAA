#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tsk {
    int tim, ddl;
    Tsk(int t, int d) {
        tim = t;
        ddl = d;
    }
};

int maxTsk(vector<Tsk>& arr) {
    int len = arr.size();

    sort(arr.begin(), arr.end(), [](Tsk a, Tsk b) {
        return a.ddl < b.ddl;
    });

    int mxDdl = 0;
    for (Tsk t : arr)
        mxDdl = max(mxDdl, t.ddl);

    vector<int> dp(mxDdl + 1, 0);

    for (Tsk t : arr) {
        for (int i = t.ddl; i >= t.tim; i--) {
            dp[i] = max(dp[i], dp[i - t.tim] + 1);
        }
    }

    int res = 0;
    for (int i : dp)
        res = max(res, i);

    return res;
}

int main() {
    int n;
    cout << "Ent num of tsks: ";
    cin >> n;

    vector<Tsk> arr;
    vector<int> tim(n), ddl(n);

    cout << "Ent time for tsks:\n";
    for (int i = 0; i < n; i++)
        cin >> tim[i];

    cout << "Ent ddl for tsks:\n";
    for (int i = 0; i < n; i++)
        cin >> ddl[i];

    for (int i = 0; i < n; i++)
        arr.push_back(Tsk(tim[i], ddl[i]));

    int res = maxTsk(arr);
    cout << "Max tsks done: " << res << endl;

    return 0;
}
