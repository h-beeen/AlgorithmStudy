import java.util.*;

class Solution {
    
    static final int videoStart = 0;
    static int videoEnd;
    static int currentPos;
    static int opStart;
    static int opEnd;
    
    static void opening() {
        if(opStart <= currentPos && currentPos <= opEnd){
            currentPos = opEnd;
        }
    }
    
    static void prev() {  
        currentPos = Math.max(currentPos - 10, 0);
        
        opening();
    }
    
    static void next(){
        currentPos = Math.min(currentPos + 10, videoEnd);
        opening();
    }
    
    static int calculateTotalSec(String rawTime){
        String minute = rawTime.substring(0,2);
        String second = rawTime.substring(3,5);
        
        Integer minuteInt = Integer.parseInt(minute) * 60;
        Integer secondInt = Integer.parseInt(second);
        
        return minuteInt + secondInt;
    }
    
    
    public String solution(
        String video_len, 
        String pos, 
        String op_start, 
        String op_end, 
        String[] commands)
    {
        opStart = calculateTotalSec(op_start);
        opEnd = calculateTotalSec(op_end);
        videoEnd = calculateTotalSec(video_len);
        currentPos = calculateTotalSec(pos);
        
        opening();
        
        for (String func : commands) {
            if (func.equals("next"))
                next();
            else if (func.equals("prev"))
                prev();
        }
        
        int resMin = currentPos / 60;
        int resSec = currentPos % 60;
    
        String finalResMin = String.format("%02d", resMin);
        String finalResSec = String.format("%02d", resSec);
        
        
        return finalResMin + ":" + finalResSec;
    }
}