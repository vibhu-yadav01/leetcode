class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i =0; i <nums.size(); i++){
            if(!m.count(nums[i])){
                int n = target - nums[i];
                m[n] = i;
            }else{
                ans.push_back(i);
                ans.push_back(m[nums[i]]);
            }
        }

        return ans;
    }
};