/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int solution(int &start,int &last )
    {
        int mid = start + (last- start)/2;
        if(guess(mid) == 0)
        {
            return mid;
        }
        else if(guess(mid) == 1)
        {
            mid = mid+1;
            return solution(mid, last);
        }
        else if(guess(mid) == -1)
        {
            mid = mid -1;
            return solution(start, mid);
        }
        return 0;
    }
    int guessNumber(int n) {
        if(guess(n) == 0)
            return n;
        int t = 1;
        return solution(t,n);
        
    }
};