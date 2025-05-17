import java.util.*;

class Solution {
    
    int targetY;
    int targetX;
    
    int[][] map = new int[102][102];
    int[][] board = new int[102][102];
    boolean[][] visit = new boolean[102][102];
    
    
    int[][] dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    
    class Node {
        int y;
        int x;
        
        public Node(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
    
    void bfs(){
        Queue<Node> queue = new LinkedList<>();
        Node startNode = new Node(targetY, targetX);
        
        queue.add(startNode);
        visit[targetY][targetX] = true;
        
        while(!queue.isEmpty()){
            Node em = queue.poll();
            
            for(int i = 0; i < 4; i++){
                int dy = em.y + dir[i][0];
                int dx = em.x + dir[i][1];
                
                // 인덱스 바깥일 경우 continue
                if (dy < 0 || dx < 0 || dy > targetY || dx > targetX) continue;
                
                // 벽이 세워진 부분이라면 continue
                if (board[dy][dx] == -1) continue;
                
                // 기 탐색한 부분이라면 continue
                if (visit[dy][dx]) continue;
                
                board[dy][dx] = board[em.y][em.x] + 1;
                visit[dy][dx] = true;
                queue.add(new Node(dy, dx));
            }   
        }
        
        for (int y = 0; y <= targetY; y++){
            for (int x = 0; x <= targetX; x++){
                // System.out.print(String.format("%02d ",board[y][x]));
            }
            // System.out.println();
        }
        
    }
    
    public int solution(int[][] maps) {
        targetY = maps.length - 1;
        targetX = maps[0].length - 1;
        
        for (int y = 0; y <= targetY; y++){
            for(int x = 0; x <= targetX; x++){
                board[y][x] = maps[y][x] - 1;
                // System.out.print(String.format("%02d ", board[y][x]));
            }
            // System.out.println();
        }
        
        bfs();

        return board[0][0] == 0 ? -1 : board[0][0] + 1;
    }
}