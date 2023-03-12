char** findLongestSubarray(char** array, int arraySize, int* returnSize){
    int cacheCount = arraySize*2+1;
    int prefix[cacheCount];
    int sum = 0;
    
    for (int i = 0; i < cacheCount; ++i) {
        prefix[i] = -2;
    }
    prefix[arraySize] = -1;

    int maxCount = 0;
    int startIndex = 0;
    for (int i = 0; i < arraySize; ++i) {
        if (array[i][0] >= '0' && array[i][0] <= '9') {
            sum -= 1; 
        } else {
            sum += 1;
        }
        if (prefix[sum+arraySize] != -2) {
             int count = i-prefix[sum+arraySize];
             if (count > maxCount) {
                 maxCount = count;
                 startIndex = prefix[sum+arraySize]+1;
             }
        } else {
            prefix[sum+arraySize] = i;
        }
    }

    *returnSize = maxCount;
    return array+startIndex;
}