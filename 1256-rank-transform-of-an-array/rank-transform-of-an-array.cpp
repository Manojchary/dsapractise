class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int , int> , vector<pair<int , int>>, greater<pair<int , int>>>pq;
        unordered_map<int , int>freq;
        for(int i = 0 ; i<arr.size() ;i++){
            freq[arr[i]]++;
            pq.push({arr[i] , i});
        }
        vector<int>res(arr.size() , -1);
        int rank = 1;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int ele = p.first;
            int idx = p.second;
            res[idx] = rank;
            freq[ele]--;
            if(freq[ele]==0) rank++;

        }
        return res;
    }
};