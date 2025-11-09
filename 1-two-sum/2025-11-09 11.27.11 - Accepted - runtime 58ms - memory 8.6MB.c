/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
     *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));

  
    int mapKeys[10000];
    int mapValues[10000];
    int mapSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

      
        for (int j = 0; j < mapSize; j++) {
            if (mapKeys[j] == complement) {
                result[0] = mapValues[j];
                result[1] = i;
                return result;
            }
        }

       
        mapKeys[mapSize] = nums[i];
        mapValues[mapSize] = i;
        mapSize++;
    }

    return NULL; 
}
