// You are given a set of numJobs jobs where each job comes with a deadline and profit. The profit can only be earned upon completing the job within its deadline. Find the number of jobs done and the maximum profit that can be obtained. Each job takes a single unit of time and only one job can be performed at a time.

#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int deadline;
    int profit;
};

// Rules for defining comparator function: It should return true if the first argument should come before the second; otherwise, it should return false.
bool static comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

// TC = O(N*log(N)) + N*maxDeadline, SC = O(maxDeadlilne)
pair<int, int> JobScheduling(Job arr[], int numJobs)
{

    sort(arr, arr + numJobs, comparison);
    int maxDeadline = -1;

    for (int i = 0; i < numJobs; i++)
        maxDeadline = max(maxDeadline, arr[i].deadline);

    vector<int> hash(maxDeadline + 1, -1); // Basically to store on which day we are performing which job

    int countJobs = 0, jobProfit = 0;

    for (int i = 0; i < numJobs; i++)
    {
        // The below inner loop can be initialized using DSU (Disjoint Set Union) with TC=O(1). A concept of CP
        for (int j = arr[i].deadline; j > 0; j--) // j is the deadline counter
        {
            if (hash[j] == -1)
            {
                hash[j] = i;
                countJobs++;
                jobProfit += arr[i].profit;
                break; // Because you don't need to find if the job can be done on any of the previous days
            }
        }
    }

    return make_pair(countJobs, jobProfit);
}

int main()
{
    int numJobs = 4;
    Job arr[numJobs] = {{1, 4, 20}, {2, 1, 10}, {3, 2, 40}, {4, 2, 30}};

    pair<int, int> ans = JobScheduling(arr, numJobs);
    cout << ans.first << " " << ans.second << endl;
}