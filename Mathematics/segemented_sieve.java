import java.util.*;
public class Main {
    static ArrayList<Integer> simpleSieve(int limit) {
        boolean[] isPRIME = new boolean[limit+1];
        
        Arrays.fill(isPRIME , true);
        
        isPRIME[0] = false;
        isPRIME[1] = false;
        
        for(int i=2 ; i*i<=limit ; i++) {
            if(isPRIME[i]) {
                for(int j = i*i ; j<= limit ; j+=i) {
                    isPRIME[j] = false;
                }
            }
        }
        
        ArrayList<Integer> primes = new ArrayList<>();
        for(int i=2 ; i<=limit ; i++) {
            if(isPRIME[i]) {
                primes.add(i);
            }
        }
        
        return primes;
    }
    
    static void segmentedSieve(int L , int R) {
        int limit = (int)Math.sqrt(R);
        ArrayList<Integer> primes = simpleSieve(limit);
        
        // now we create a boolean array
        boolean[] isPrime = new boolean[R-L+1];
        
        // now we fill it with true  values initially
        Arrays.fill(isPrime , true);
        
        for(int p : primes) {
            int firstMultiple = ((L/p) * p );
            if(firstMultiple < L) firstMultiple += p;
            for(int j = Math.max(p*p , firstMultiple) ; j<=R ; j+= p) {
                isPrime[j-L] = false;
            }
        }
        
        //now we need to extract the primes 
        for(int i=L ; i<=R ; i++) {
            if(isPrime[i-L] == true) {
                System.out.print(i + " ");
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int L = sc.nextInt();
        int R = sc.nextInt();
        
        segmentedSieve(L,R);
    }
}45
