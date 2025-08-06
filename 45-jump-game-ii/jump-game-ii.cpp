class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size() ;
        if(n==1 )return 0 ;
        
         queue<int> q ; 

         vector<int> vis(n , 0) ;

         q.push(0) ;
         vis[0]=1 ;
         int count = 0 ; 

         while(!q.empty()){
            int sz = q.size() ;
            for(int i=0 ; i<sz ; i++){
                int l = q.front() ;
                q.pop() ;
                
                for(int i=1 ; i<=nums[l] ; i++){
                    int x = l+i ;
                    if(x == n-1){
                       return count+1 ; 
                    }
                    if(x<n && vis[x] == 0){
                        q.push(x) ;
                        vis[x] = 1;
                    }
                    else if(x == n-1){
                        return count;
                    }
                }
            }
            count++ ;
         }
         return -1 ;
    }
};