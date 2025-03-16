#include <iostream>
using namespace std;

char findMaxOccurringAlphabet(string arr) {
    int freq[26] = {0}; // Frequency array for 26 alphabets

    // Count occurrences of each alphabet
    for (char ch : arr) {
        freq[ch - 'a']++; // Convert char to index (0-25)
    }

    // Find the alphabet with the maximum occurrence
    int maxFreq = 0;
    char maxChar;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxChar = 'a' + i; // Convert index back to character
        }
    }

    return maxChar;
}

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "\nEnter number of alphabets in the array: ";
        cin >> n;

        string arr;
        cout << "Enter the alphabets (without spaces): ";
        cin >> arr;

        if (arr.length() != n) {
            cout << "Error: Input length doesn't match given n. Please retry.\n";
            continue;
        }

        char maxChar = findMaxOccurringAlphabet(arr);
        cout << "The alphabet with maximum occurrences is: " << maxChar << endl;
    }

    return 0;
}
