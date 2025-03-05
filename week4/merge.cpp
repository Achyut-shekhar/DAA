#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &vec, int low, int mid, int high, int &comparisons, int &inversions)
{
    vector<int> temp;
    int left = low, right = mid + 1;
    int local_comparisons = 0, local_inversions = 0;

    while (left <= mid && right <= high)
    {
        local_comparisons++;
        if (vec[left] <= vec[right])
        {
            temp.push_back(vec[left]);
            left++;
        }
        else
        {
            temp.push_back(vec[right]);
            local_inversions += (mid - left + 1); // All elements from left to mid are greater than vec[right]
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(vec[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(vec[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        vec[i] = temp[i - low];
    }

    comparisons += local_comparisons;
    inversions += local_inversions;
    return 0;
}

int mergesort(vector<int> &vec, int low, int high, int &comparisons, int &inversions)
{
    if (low >= high)
    {
        return 0;
    }
    int mid = (low + high) / 2;
    mergesort(vec, low, mid, comparisons, inversions);
    mergesort(vec, mid + 1, high, comparisons, inversions);
    merge(vec, low, mid, high, comparisons, inversions);
    return 0;
}

int main()
{
    int n, ele;
    vector<int> vec;
    cout << "Input the number of elements" << "\n";
    cin >> n;
    cout << "Input the elements" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        vec.push_back(ele);
    }

    int comparisons = 0, inversions = 0;
    mergesort(vec, 0, n - 1, comparisons, inversions);

    cout << "Sorted Array: ";
    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Total Comparisons: " << comparisons << endl;
    cout << "Total Inversions: " << inversions << endl;

    return 0;
}
