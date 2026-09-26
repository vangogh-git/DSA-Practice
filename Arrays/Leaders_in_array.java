class Solution {
    static ArrayList<Integer> leaders(int arr[]) {
        
        ArrayList<Integer> ans = new ArrayList<>();
        int n = arr.length;
        
        ans.add(arr[n-1]);
        int maxi = arr[n-1];
        for(int i=n-2 ; i>=0 ; i--) {
            if(arr[i] >= maxi) {
                maxi = arr[i];
                ans.add(maxi);
            }
        }
        
        Collections.reverse(ans);
        return ans;
    }
}
