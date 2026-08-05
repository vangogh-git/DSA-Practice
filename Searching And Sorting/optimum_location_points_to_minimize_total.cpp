// time complexity : O(n)
// space complexity : O(1)
// pattern : ternary search

class Solution {
    private :
    double function(tuple<int,int,int> l , vector<pair<int,int>> p , double x) {
        
        
        int a = get<0>(l);
        int b = get<1>(l);
        int c = get<2>(l);
        
        // we need y here
        double y;
        y = (-c - a*x)/ (double)b;
        
        // we need to compute the sum here
        double sum = 0;
        for(auto &pt : p) {
            double dx = pt.first - x;
            double dy = pt.second - y;
            sum += sqrt(dx*dx + dy*dy);
        }
        return sum;
    }
  public:
    double findOptimumCost(tuple<int, int, int> l, vector<pair<int, int>> p, int n) {
        int a = get<0>(l);
        int b = get<1>(l);
        int c = get<2>(l);
        
        // edge case : if b == 0
        if(b == 0) {
            // x is fixed
            double sum=0;
            double x = -c/(double)a;
            
            for(auto &pt : p) {
                double dx = pt.first - x;
                double dy = pt.second;
                sum += sqrt(dx*dx + dy*dy);
            }
            
            return sum;
        }
        
        double low = -1e6;
        double high = 1e6;
        
        for(int i=0 ; i<100 ; i++) {
            double m1 = low + (high - low)/3;
            double m2 = high - (high - low)/3;
            
            if(function(l , p , m1) < function(l , p , m2) ) {
                high = m2;
            }
            else {
                low = m1;
            }
        }
        
        double x = (low + high)/2;
        return function(l , p , x);
    }
};
