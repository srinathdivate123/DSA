// https://leetcode.com/problems/contains-duplicate/

// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

// Brute is to run nested for loop & check
// Better is to sort the array & check, suplicate elements will be adjacent
// Best is below

#include<bits/stdc++.h>
using namespace std;
    
bool containsDuplicate(vector<int> nums) {
 
    set<int> myset;
    
    for(int i = 0; i<nums.size();i++){
        myset.insert(nums[i]);
    }
    
    // if it contains duplicate then the size of 
    // set will not equal to the length of the array
    if(myset.size() < nums.size())
        return true;
    
    return false;
}
    
int main () {
	    
    vector<int> nums {1, 2, 3, 1};
    
    bool res = containsDuplicate(nums);
    
    // printing the result
    if(res== 1)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}