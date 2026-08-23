class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int oddcount = 0;
        int subarrays = 0;
        int ini = 0;
        int firstodd = -1;
        int lastodd = -1;
        for (int fin = 0; fin < nums.size(); fin++) {
            if (nums[fin] % 2 == 1) {
                oddcount++;
                if (oddcount == 1) {
                    firstodd = fin;
                }
                if (oddcount == k) {
                    lastodd = fin;
//                    cout << ( << firstodd << , << lastodd << )\t;
                }
                if (oddcount == k + 1) {
//                    cout << [ << (firstodd - ini + 1) << , << (fin - lastodd) << ]
;
                    subarrays += (firstodd - ini + 1)*(fin - lastodd);
                    lastodd = fin;
                }
                while (oddcount >= k + 1) {
                    if (nums[ini] % 2 == 1) {
                        oddcount--;
                        firstodd = ini + 1;
                        while (nums[firstodd] % 2 == 0) {
                            firstodd++;
                        }
                    }
//                    cout << ( << firstodd << , << lastodd << )\t;
                    ini++;
                }
            }
        }
        if (oddcount == k) {
//            cout << [ << (firstodd - ini + 1) << , << (nums.size() - lastodd) << ]+
;
            subarrays += (firstodd - ini + 1)*(nums.size() - lastodd);
        }
        return subarrays;
    }
};