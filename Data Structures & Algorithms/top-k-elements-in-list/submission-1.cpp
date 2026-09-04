class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for(int num : nums){
            mp[num]++;
        }

        vector<vector<int>> buckets(n+1);
        for(auto it : mp){
            int num = it.first;
            int freq = it.second;
            buckets[freq].push_back(num);
        }

        vector<int> ans;
        for(int i=n; i>=0; i--){
            for(int num : buckets[i]){
                ans.push_back(num);
            }
            if(ans.size()==k) break;
        }
        return ans;
    }
};
