class Solution {
public:
    int help(int n, int flag, int start, int jump) {
        // cout << n << " " << flag << " " << start << " " << jump << endl;
        if (n == 1)
            return start;
        if (flag) {
            // cout<<"h1"<<endl;
            return help(n / 2, flag ^ 1, start + jump, 2 * jump);
        }
        if (n % 2 == 0)
            {
                // cout<<"h2"<<endl;
                return help(n / 2, flag ^ 1, start, 2 * jump);}
        return help(n / 2, flag ^ 1, start + jump, 2 * jump);
    }
    int lastRemaining(int n) {
        return help(n,1,1,1);
    }
};