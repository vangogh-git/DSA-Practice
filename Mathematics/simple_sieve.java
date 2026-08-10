import java.util.*;
public class Main {
    
    static void simpleSieve(int n) {
        boolean[] isPrime = new boolean[n+1];
        Arrays.fill(isPrime, true);
        
        isPrime[0] = false;
        isPrime[1] = true;
        
        for(int i = 2 ; i*i <= n ; i++) {
            if(isPrime[i]) {
                for(int j=i*i ; j<= n ; j+=i) {
                    isPrime[j] = false;
                }
            }
        }
        
        for(int i=2 ; i<=n ; i++) {
            if(isPrime[i]) {
                System.out.print(i + " ");
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        simpleSieve(n);
    }
}
