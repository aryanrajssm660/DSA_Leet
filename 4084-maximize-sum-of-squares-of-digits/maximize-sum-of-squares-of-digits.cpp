class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // long long digit = 1;
        // long long i = 1;
        // while (i < num) {
        //     digit *= 10;
        //     i++;
        // }
        string answer = "";
        long long temp = sum;
        while (num > 0 ) {
            int unit = temp >= 9 ? 9 : temp;
            temp = temp - unit;
            answer+=to_string(unit);
            num--;
        }
        // if(digit!=0||temp!=0){
        //     return "";
        // }
        if (temp != 0) {
            return "";
        }
        return answer;
    }
};