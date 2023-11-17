// 0-1 Knapsack Problem Solved using Dynamic Programming

#include <bits/stdc++.h>
using namespace std;

int recursive(int index, int bagWeight, int profits[], int weights[])
{
    // Base Case
    if (index == 0)
    {
        if (bagWeight >= weights[index])
            return profits[index];
        else
            return 0;
    }

    // Skip the Item
    int notPick = 0 + recursive(index - 1, bagWeight, profits, weights);

    // Pick the Item
    int pick = INT_MIN; // Initialize with Lower Value
    if (bagWeight >= weights[index])
    {
        pick = profits[index] + recursive(index - 1, bagWeight - weights[index], profits, weights);
    }

    return max(pick, notPick);
    // Return with the Maximum out of these possibilities
}

int memoized(int index, int bagWeight, int profits[], int weights[], vector<vector<int>> &dp)
{
    // Memoized Approach to Dynamic Programming - Top-Down
    // We check if the Problem has been already solved for this state

    // Base Case
    if (index == 0)
    {
        if (bagWeight >= weights[index])
            return profits[index];
        else
            return 0;
    }

    if (dp[index][bagWeight] != -1)
    {
        return dp[index][bagWeight];
    }

    // Skip the Item
    int notPick = 0 + recursive(index - 1, bagWeight, profits, weights);

    // Pick the Item
    int pick = INT_MIN; // Initialize with Lower Value
    if (bagWeight >= weights[index])
    {
        pick = profits[index] + recursive(index - 1, bagWeight - weights[index], profits, weights);
    }

    return dp[index][bagWeight] = (pick, notPick);
    // Return with the Maximum out of these possibilities
}

int tabulated(int n, int bagWeight, int profits[], int weights[])
{
    // Tabulated Approach to Dynamic Programming - Bottom-Up
    vector<vector<int>> dp(n, vector<int>(bagWeight + 1, 0));

    for (int w = weights[0]; w <= bagWeight; w++)
    {
        dp[0][w] = profits[0];
    }
    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= bagWeight; w++)
        {
            int notPick = 0 + dp[index - 1][bagWeight];
            int pick = -1000000; // Initialize with Lower Value
            if (bagWeight >= weights[index])
            {
                pick = profits[index] + dp[index - 1][bagWeight - weights[index]];
            }
            dp[index][bagWeight] = max(pick, notPick);
        }
    }
    return dp[n - 1][bagWeight];
}

int main()
{
    int n = 3;                    // Number of Items
    int profits[] = {30, 40, 60}; // Profit from Each item
    int weights[] = {3, 2, 5};    // Weight of Each item
    int bagWeight = 6;

    cout << "Maximum Attainable Profit : " << endl;
    cout << "Recursive : " << recursive(n - 1, bagWeight, profits, weights) << endl;

    vector<vector<int>> dp(n, vector<int>(bagWeight + 1, -1));
    cout << "DP with Memoization : " << memoized(n - 1, bagWeight, profits, weights, dp) << endl;
    cout << "DP with Tabulation : " << tabulated(n, bagWeight, profits, weights);

    // Recursive Solution :
    // Time Complexity : O(2^n)
    // Space Complexity : O(N)

    // Memoized Dynamic Programming :
    // Time Complexity : O(n*bagWeight)
    // Space Complexity : O(n*bagWeight) + O(n)

    // Tabulated Dynamic Programming :
    // Time Complexity : O(n*bagWeight)
    // Space Complexity : O(n*bagWeight)
}

// #include <bits/stdc++.h>
// using namespace std;

// int dynamicKnapsack(vector<pair<int, int>> Items, int n, int weight) {
//     vector<int> dp(weight + 1, 0);

//     for(int i = 0; i < n; i++) {
//         for(int j = weight; j >=0; j--) {
//             if(Items[i].first <= j) {
//                 dp[j] = max(dp[j], dp[j - Items[i].first] + Items[i].second);
//             }
//         }
//     }

//     return dp[weight];
// }

// int main() {
//     int n;
//     cout << "Enter no of items: ";
//     cin >> n;

//     vector<pair<int, int>> Items(n);
//     for(int i = 0; i < n; i++) {
//         cout << "Enter Weight and Profit for each Item: ";
//         cin>>Items[i].first>>Items[i].second;
//     }
//     // int price[items + 1] = {0, 3, 7, 2, 9};
//     // int wt[items + 1] = {0, 2, 2, 4, 5};

//     int weight;
//     cout << "Enter Capacity of Knapsack: ";
//     cin >> weight;

//     cout << "Maximum Profit Possible: " << dynamicKnapsack(Items, n, weight);
//     return 0;
// }