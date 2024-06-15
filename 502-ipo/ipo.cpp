using ll = long long;
class Solution {
public:
    int cm_bin(int low, int high, const vector<pair<int, int>>& cp, int key) {
        int ans = low - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (cp[mid].first <= key) {
                ans = max(ans, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        int n = p.size();
        vector<pair<int, int>> cp(n);
        for (int i = 0; i < n; ++i) {
            cp[i] = {c[i], p[i]};
        }
        sort(cp.begin(), cp.end());

        priority_queue<int> max_heap;
        int ind = cm_bin(0, n - 1, cp, w);

        for (int i = 0; i <= ind; ++i) {
            max_heap.push(cp[i].second);
        }
        
        while (k > 0 && !max_heap.empty()) {
            w += max_heap.top();
            max_heap.pop();
            --k;
            int pre = ind;
            ind = cm_bin(ind + 1, n - 1, cp, w);
            if(pre == ind) continue;
            for (int i = pre + 1; i <= ind; ++i) {
                max_heap.push(cp[i].second);
            }
        }

        return w;
    }
};