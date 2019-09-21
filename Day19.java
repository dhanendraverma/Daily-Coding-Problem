public int minCostII(int[][] costs) {
    if(costs==null || costs.length==0)
        return 0;
 
    int preMin=0;
    int preSecond=0;
    int preIndex=-1; 
 
    for(int i=0; i<costs.length; i++){
        int currMin=Integer.MAX_VALUE;
        int currSecond = Integer.MAX_VALUE;
        int currIndex = 0;
 
        for(int j=0; j<costs[0].length; j++){
            if(preIndex==j){
                costs[i][j] += preSecond;
            }else{
                costs[i][j] += preMin;
            }
 
            if(currMin>costs[i][j]){
                currSecond = currMin;
                currMin=costs[i][j];
                currIndex = j;
            } else if(currSecond>costs[i][j] ){
                currSecond = costs[i][j];
            }
        }
 
        preMin=currMin;
        preSecond=currSecond;
        preIndex =currIndex;
    }
 
    int result = Integer.MAX_VALUE;
    for(int j=0; j<costs[0].length; j++){
        if(result>costs[costs.length-1][j]){
            result = costs[costs.length-1][j];
        }
    }
    return result;
}
