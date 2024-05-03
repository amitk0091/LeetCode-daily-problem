class Solution {
public:
    int compareVersion(string v1, string v2) {
        long long i = 0, j = 0;
        while (i < v1.length() && j < v2.length()) {
            long long num1 = 0, num2 = 0;
            while (i < v1.length() && v1[i] != '.') {
                num1 *= 10;
                num1 += (v1[i] - '0');
                i++;
            }
            while (j < v2.length() && v2[j] != '.') {
                num2 *= 10;
                num2 += (v2[j] - '0');
                j++;
            }
            cout<<num1<<" "<<num2<<endl;

            if (num1 > num2)
                return 1;
            else if (num1 < num2)
                return -1;
            i++;
            j++;
        }
        while (i < v1.length()) {
             if (v1[i] >= '1' && v1[i] <='9')
                return 1;
            i++;
        }
        while (j < v2.length()) {
            if (v2[j] >= '1' && v2[j] <='9')
                return -1;
            j++;
        }
        return 0;
    }
};