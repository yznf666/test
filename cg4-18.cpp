#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<string>
#include<climits>
#include<map>
#include<stdio.h>
#include<unordered_map>
using namespace std;


int main(){
   
        int n=0,k=0;
        cin>>n>>k;
       vector<int>nums(n);
       for(int i=0;i<n;i++)cin>>nums[i];

         vector<vector<vector<int>>>memo(n,vector<vector<int>>(k+1,vector<int>(n+1,-1)));
        auto dfs=[&](auto&&dfs,int i,int target,int last)->bool{
            if(target==0)return true;
            if(i<0)return false;
            int&res=memo[i][target][last];
            if(res!=-1)return res;
            int x=min(nums[i],last);
            return res=dfs(dfs,i-1,target,last)||dfs(dfs,i-1,target-x,last);
        };

        vector<bool>ans;
        
        for(int i=1;i<=n;i++){
            ans.push_back(dfs(dfs,n-1,k,i));
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
}
