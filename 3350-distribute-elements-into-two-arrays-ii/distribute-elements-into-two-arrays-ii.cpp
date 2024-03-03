#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {

        int n = nums.size();

        vector<int> arr1, arr2, arr3;
        ordered_set st1, st2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        st1.insert({nums[0], 0});
        st2.insert({nums[1], 1});

        for (int i = 2; i < n; i++) {
            int g1 = arr1.size() - st1.order_of_key({nums[i] + 1, 0});
            int g2 = arr2.size() - st2.order_of_key({nums[i] + 1, 0});

            if (g1 > g2 || (g1 == g2 && arr1.size() <= arr2.size())) {
                arr1.push_back(nums[i]);
                st1.insert({nums[i], i});
            } else {
                arr2.push_back(nums[i]);
                st2.insert({nums[i], i});
            }
        }
        for (int i = 0; i < arr1.size(); i++)
            arr3.push_back(arr1[i]);
        for (int i = 0; i < arr2.size(); i++)
            arr3.push_back(arr2[i]);

        return arr3;
    }
};