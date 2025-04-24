class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> fre;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            fre[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        for(auto i : fre){
            minheap.push({i.second, i.first});
            if(minheap.size() > k){
                minheap.pop();
            }
        }
        while(!minheap.empty()){
            res.push_back(minheap.top().second);
            minheap.pop();
        }
        return res;
    }
};