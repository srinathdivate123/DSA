// There is one meeting room in a firm. You are given two arrays, start and end each of size N.For an index ‘i’, start[i] denotes the starting time of the ith meeting while end[i]  will denote the ending time of the ith meeting. Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a  particular time. Print the order in which these meetings will be performed.

// Say if you have two meetings, one which gets over early and another which gets over late. Which one should we choose?  If our meeting lasts longer the room stays occupied and we lose our time. On the other hand, if we choose a meeting that finishes early we can accommodate more meetings. Hence we should choose meetings that end early and utilize the remaining time for more meetings.

#include <bits/stdc++.h>
using namespace std;

struct meeting
{
   int start;
   int end;
   int num;
};

bool static comparator(struct meeting m1, meeting m2)
{
   if (m1.end < m2.end)
      return true;
   else if (m1.end > m2.end)
      return false;
   else if (m1.num < m2.num)
      return true;
   return false;
}

// TC = N + N*log(N) + N
// SC = 3*N + N
void maxMeetings(int s[], int e[], int n)
{
   struct meeting meet[n];
   for (int i = 0; i < n; i++)
   {
      meet[i].start = s[i], meet[i].end = e[i], meet[i].num = i + 1;
   }

   sort(meet, meet + n, comparator);

   vector<int> answer;

   int getsFreedAt = meet[0].end; // Meeting room gets freed at
   answer.push_back(meet[0].num);

   for (int i = 1; i < n; i++)
   {
      if (meet[i].start > getsFreedAt)
      {
         getsFreedAt = meet[i].end;
         answer.push_back(meet[i].num);
      }
   }
   cout << "The order in which the meetings will be performed is " << endl;
   for (int i = 0; i < answer.size(); i++)
   {
      cout << answer[i] << " ";
   }
}

int main()
{
   int n = 6;
   int start[] = {1, 3, 0, 5, 8, 5};
   int end[] = {2, 4, 5, 7, 9, 9};
   maxMeetings(start, end, n);
   return 0;
}