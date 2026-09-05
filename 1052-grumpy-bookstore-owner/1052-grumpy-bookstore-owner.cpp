class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int left=0;
        int base=0;
        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==0) base+=customers[i];
        }
        int gain=0;
        int maxgain=INT_MIN;

        for(int right=0;right<customers.size();right++){

            //adding condition
            if(grumpy[right]==1){
                gain+=customers[right];
            }

            //checking window size
            //if it exceeds size
            if(right-left+1>minutes){
                if (grumpy[left] == 1) {
                    gain -= customers[left];
                }

                left++;
            }

            // if in size
            if(right-left+1==minutes){
                maxgain=max(gain,maxgain);
            }
        }
        return base+maxgain;
    }
};