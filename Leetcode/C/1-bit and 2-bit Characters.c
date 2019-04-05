bool isOneBitCharacter(int* bits, int bitsSize) {
    if(bitsSize == 1)
        return 1;
    
    int i = bitsSize - 2;
    int sum = 0;
    
    while(bits[i] == 1 && i>=0){
        sum += 1;
        i--;
    }
    
    return (sum-1)% 2;
}