import java.util.*;
public class Main {
    
    static int gcd(int a , int b) {
        while(b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    static int phi(int n) {
        int result = n;
        
        for(int i=2 ; i*i <= n ; i++) {
            if(n % i == 0) {
                while(n%i == 0) {
                    n /= i;
                }
                result -= result / i;
            }
        }
        
        if(n > 1) {
            result -= result / n;
        }
        
        return result;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        
        int result = phi(n);
        System.out.println(result);
        
        for(int i=1 ; i<= n ; i++) {
            if(gcd(i,n) == 1) {
                System.out.print(i + " ");
            }
        }
    }
}
