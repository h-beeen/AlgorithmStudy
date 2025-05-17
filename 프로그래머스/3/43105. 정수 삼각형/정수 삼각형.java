class Solution {
    
    static int[][] dpTriangle = new int[502][502];
    static int depth;
    
    static int dp(int y, int x, int[][] source){
        if(y > depth || x > depth) return 0;
        
        if(dpTriangle[y][x] != 0 && !(y == 0 && x == 0)) {
            return dpTriangle[y][x];
        } else {
            int result = Math.max(dp(y + 1, x, source), dp(y + 1, x + 1, source)) + source[y][x];
            dpTriangle[y][x] = result;
            // System.out.println("y=" + y + " x =" + x + "result= " +result);
        
            return result;
        }
    }
    
    public int solution(int[][] source) {
        depth = source.length -1;
        dpTriangle[0][0] = source[0][0];
        
        return dp(0, 0, source);
    }
}