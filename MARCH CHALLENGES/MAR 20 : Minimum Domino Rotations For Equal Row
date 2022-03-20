class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
        int n=tops.size();
        //Count the occurence of each number in tops row
        vector<int> countA(7,0);
        //Count the occurence of each number in bottom row
        vector<int> countB(7,0);
        //Count the occurence of numbers which are same in tops and bottom at same index
        vector<int> same(7,0);
        
        //Iterate from 0 to n
        for(int i=0;i<n;i++)
        {
            //Increment the count of tops[i]
            countA[tops[i]]++;
            //Increment the count of bottoms[i]
            countB[bottoms[i]]++;
            //Increment the count if both are same
            if(tops[i]==bottoms[i])
                same[tops[i]]++;
        }
        
        for(int i=0;i<7;i++)
        {
            if((countA[i]+countB[i]-same[i])==n)
                return n-max(countA[i],countB[i]);
            
        }
        return -1;
    }
};
