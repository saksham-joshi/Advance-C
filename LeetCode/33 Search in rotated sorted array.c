inline static int search(int* __nums, int __numsSize, int __target) {
    
    for(int i = 0 ; i < __numsSize ; ++i , ++__nums) if (*__nums == __target) return i;

    return -1;
}