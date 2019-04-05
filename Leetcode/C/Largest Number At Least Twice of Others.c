int dominantIndex(int* nums, int numsSize) {
    int lagest, second;
    int index = 0;
        
    lagest = second = 0;
    
    for(int i=0; i<numsSize; i++){
        if(nums[i] > lagest){
            second = lagest;
            lagest = nums[i];
            index = i;
        }
        else if(nums[i] > second)
            second = nums[i];
    }
            
    
    if(numsSize == 1)
        return 0;
    
    return lagest >= 2*second? index : -1; 
}