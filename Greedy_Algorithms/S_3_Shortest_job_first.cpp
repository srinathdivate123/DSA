/*
Geek is a software engineer. He is assigned with the task of calculating average waiting time of all the processes by following shortest job first policy.

The shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting process with the smallest execution time to execute next.

Given an array of integers bt of size n. Array bt denotes the burst time of each process. Calculate the average waiting time of all the processes and return the nearest integer which is smaller or equal to the output.

Note: Consider all process are available at time 0.
*/

#include <bits/stdc++.h>
using namespace std;

int best(vector<int> jobs)
{
    sort(jobs.begin(), jobs.end());

    float waitTime = 0;
    int totalTime = 0;
    int n = jobs.size();

    for (int i = 0; i < n; ++i)
    {
        waitTime += totalTime;
        totalTime += jobs[i];
    }

    return waitTime / n;
}

int main()
{
    vector<int> jobs = {4, 3, 7, 1, 2};
    cout << best(jobs);
}