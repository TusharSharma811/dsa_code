class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=numBottles ; 
        int emptyBottles = ans ; 

        while(numExchange <= emptyBottles){
            emptyBottles -= numExchange ; 
            ans++ ;
            emptyBottles++ ;
            numExchange++ ;
        }

        return ans ; 
    }
};