import java.util.*;
public class Main {
    public static boolean Palindrome(int x) {
        String s = Integer.toBinaryString(x);
        
        int i = 0;
        int j = s.length()-1;
        while(i <= j) {
            if(s.charAt(i) != s.charAt(j)) return false;
            i++;
            j--;
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n =sc.nextInt();
        System.out.print("is Binary Palindrome : " + Palindrome(n));
    }
}
