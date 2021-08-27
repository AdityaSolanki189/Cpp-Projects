/* Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number. */

#include <bits/stdc++.h>
using namespace std;

int getDuplicate(vector<int>& array, int n){
    int low=1;
    int high=n-1;
    int mid;
    while(low<high){
        mid=(low+high)/2;
        int count=0;
        for(int num:array){
            if(num<=mid) 
                count++;
        }
        if(count>mid) 
            high=mid;
        else 
            low=mid+1; 
    }
    return low;
}

/*  IF we were allowed to make changes in the array:
    int getDuplicate(vector<int>& v){
    int n = v.size();
    for(int i=0;i<n;i++){
        int m = abs(v[i])-1;
        if(v[m]>0)
            v[m] = -v[m];
        else    
            return abs(m)-1;
    }
    return -1;
} */

int main(){
    int n;
    cin >> n;
    vector<int> array;
    int val;
    for(int i=0;i<n;i++){    
        cin >> val;
        array.push_back(val);
    }
    cout << "The Duplicate Number : " << getDuplicate(array, n);

    return 0;
}

/*  Method 2 : Linked List Cycle 
Use two pointers the fast and the slow. The fast one goes forward two steps each time, while the slow one goes only step each time. They must meet the same item when slow==fast. In fact, they meet in a circle, the duplicate number must be the entry point of the circle when visiting the array from nums[0]. Next we just need to find the entry point. We use a point(we can use the fast one before) to visit form begining with one step each time, do the same job to slow. When fast==slow, they meet at the entry point of the circle.  

    int findDuplicate3(vector<int>& nums){
        if (nums.size() > 1){
            int slow = nums[0];
            int fast = nums[nums[0]];
            while (slow != fast){
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            fast = 0;
            while (fast != slow){
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
	    return -1;
    }

*/