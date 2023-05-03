import java.util.Scanner;

public class Solution {
    public String switchAlphabet(String str){
        String result = "";
        for(int i = 0; i < str.length(); i++){
            char c = str.charAt(i);
            if(c >= 'a' && c <= 'z')
                c -= 32;
            else
                c += 32;
            result += c;
        }
        return result;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        Solution sol = new Solution();
        String b = sol.switchAlphabet(a);
        System.out.println(b);
    }
}
