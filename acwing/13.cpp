// offer 
// 暴力解法，时空复杂度皆为O(n)
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int length = nums.size();
        int count[1010] = {0};

        // 遍历数组，对每个元素出现次数进行计数
        for(int i = 0;i < length;i++){
            if(nums[i] < 0 || nums[i] >= length) {
                return -1;
            }
            count[nums[i]]++;
        }

        for(int i = 0;i < length;i++){
            if(count[i] > 1) return i;
        }

        return -1;
    }
};

// 总体思路为调整数组令 nums[nums[i]] == nums[i], 如果在调整之后遇到nums[i] != i, 说明nums[i] == nums[nums[i]]
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int length = nums.size();
        
        for(int i = 0;i < length;i++){
            if(nums[i] < 0 || nums[i] >= length) {
                return -1;
            }
        }
        
        for(int i = 0;i < length;i++){
            // 循环调整，确保数组中nums[x] = x (x = numx[i])，原先nums[x]处的值调整到nums[i]
            // 不会陷入死循环，while最多进行n - 1次， 时间复杂度为O(n) 
			while(nums[nums[i]] != nums[i]) swap(nums[i], nums[nums[i]]);
            
            // 若此时nums[i] != i，说明最后一次调整时nums[x] == nums[i]          
			if(nums[i] != i) return nums[i]; 	
		}
        
        return -1;
    }
};

