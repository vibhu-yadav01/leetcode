class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int n = nums.size();
      int count =0;
      vector<int> preSum(n, 0);
      unordered_map<int,int> m; //PS, freq

      preSum[0] = nums[0];
      for(int i=1; i<n; i++){
        preSum[i] = preSum[i-1] + nums[i]; 
      }

      for(int j =0; j<n; j++){
        if(preSum[j]==k) count++;

        int val= preSum[j] - k;
        if(m.find(val) != m.end()){
            count+= m[val];
        }

        if(m.find(preSum[j])== m.end()){
            m[preSum[j]];
        }
        m[preSum[j]]++;

      }
       return count;  
    }
};