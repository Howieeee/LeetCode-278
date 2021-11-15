// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1)
            return 1;
        if(isBadVersion(1))
            return 1;
        
        long left = 1 , right = n;
        //int mid = (left+right)/2+1 ; // mid =6
        //cout << isBadVersion(mid);
        //G G G G B B B B B B B // n =11 
        long mid = 0;
        // B G
        while(left < right){
            mid = (left+right)/2 + 1;
            bool if_bad = isBadVersion(mid);
            if(if_bad) // B
                right = mid - 1;
            else if(!if_bad)
                left = mid + 1;
            //cout << left << " " << right << endl;
        }
        //cout << mid << endl;
        if(isBadVersion(left))//B 就回傳
            return left;
        else
            return left+1;
        
        //return mid;
    }
};
