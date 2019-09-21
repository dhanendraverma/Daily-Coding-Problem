/***************************************************************************************************************************************
This problem was asked by Facebook.
A builder is looking to build a row of N houses that can be of K different colors. 
He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.
Given an N by K matrix where the nth row and kth column represents the cost to build the nth house with kth color, 
return the minimum cost which achieves this goal.
****************************************************************************************************************************************/



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
