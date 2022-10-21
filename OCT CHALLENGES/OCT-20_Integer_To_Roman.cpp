/* EXPLANATION :
In this question we have to convert Integer to Roman. For instance we are given a 
number 1234, so its Roman form is MCCXXXIV.Now coming onto the approach, we have to take 4 strings ie,
for storing ones value, tens value, hundred value, thousand value. In the string ones all the digits
from 1-9 will lie, in the string tens all tens numbers will lie, simlarily in hundred string we will store
numbers lying in 100 n for thousand we will store the numbers lying in thousands. 

We took example as 1234, now we can write it as 1000+200+30+4. But the question arises is that how can
can we bring symbols ? So to find corresponding symbols at thousand place divide it by 1000, for hundred
place divide it bby 100, for tens place divide it by 10 and for one place divide by 1.

Now at hundred place take modulus(%) of 1000, at tens place take modulus of 100 and at ones place take
modulus of 10.
 
TIME COMPLEXITY : O(N)
SPACE COMPLEXITY : O(1)

*/

class Solution {
public:
    string intToRoman(int num) 
    {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};