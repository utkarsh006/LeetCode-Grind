// Sum of Number and Its Reverse
class Solution {
private:
    // reverse the number
    int rev(int num) {
        int rev_num = 0;
        while(num > 0) {
            rev_num = rev_num * 10 + num % 10;
            num /= 10;
        }
        return rev_num;
    }
    
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i=0; i<=num; i++) {
            if(i + rev(i) == num) return true;
        }
        return false;
    }
};