#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void knapsackcal(vector<int>& p, vector<int>& w, int maxcap) {
    int n = p.size();
    vector<pair<float, pair<int, int>>> items;

    for (int i = 0; i < n; i++) {
        float ratio = (float)p[i] / w[i];
        items.push_back({ratio, {p[i], w[i]}});
    }

    sort(items.begin(), items.end(), [](const pair<float, pair<int, int>>& a, const pair<float, pair<int, int>>& b) {
        return a.first > b.first;
    });

    int currentWeight = 0;
    float totalProfit = 0.0;

    for (const auto& item : items) {
        int profit = item.second.first;
        int weight = item.second.second;

        if (currentWeight + weight <= maxcap) {
            currentWeight += weight;
            totalProfit += profit;
        } else {
            int remainingCapacity = maxcap - currentWeight;
            totalProfit += profit * ((float)remainingCapacity / weight);
            break;
        }
    }

    cout << "Total Profit: " << totalProfit << endl;
}

int main() {
    int n, maxcap;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> profit(n), weight(n);
    cout << "Enter profits of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter maximum capacity of knapsack: ";
    cin >> maxcap;

    knapsackcal(profit, weight, maxcap);
    return 0;
}
