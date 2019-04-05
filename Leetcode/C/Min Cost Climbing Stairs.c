int minCostClimbingStairs(int* cost, int costSize) {
    int pos0, pos1, pos;
    pos = cost[0];
    pos0 = pos1 = 0;
    
    for(int i=2; i<costSize + 1; i++){
        pos = (pos0 + cost[i-2] < pos1 + cost[i-1])? pos0 + cost[i-2] : pos1 + cost[i-1];
        pos0 = pos1;
        pos1 = pos;
    }
    
    return pos;
}