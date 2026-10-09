class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<2) return false;

        int prefix =0;
        unordered_map<int,int> m; //rem idx
        m[0] =-1;

        for(int i = 0; i<n; i++){
            prefix+= nums[i];
            int rem =prefix % k;

            if(m.find(rem) != m.end()){
                if(i - m[rem] >= 2)return true;
            }else{
                m[rem] = i;
                }
        }
        return false;
    }
};