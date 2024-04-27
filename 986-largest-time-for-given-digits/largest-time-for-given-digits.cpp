class Solution {
public:
    int hmx = -1;
    int mmx = -1;
    void help(string st, vector<int> arr) {
        if (st.length() == 4) {
            int hh = (st[0] - '0');
            hh = hh * 10 + (st[1] - '0');
            int mm = (st[2] - '0');
            mm = mm * 10 + (st[3] - '0');
            if (hh <= 23 && mm <= 59) {
                if (hmx < hh) {
                    hmx = hh;
                    mmx = mm;
                } else if (hmx == hh)
                    mmx = max(mmx, mm);
            }
            return;
        }
        for (int i = 0; i < 4; i++) {
            if (arr[i] < 10) {
                int k = arr[i];
                arr[i] = 10;
                help(st + to_string(k), arr);
                arr[i] = k;
            }
        }
    }
    string largestTimeFromDigits(vector<int>& arr) {
        string st;
        help("",arr);
        if(hmx!=-1) {
            string hh = to_string(hmx);
            if(hh.length()==1) hh= "0"+hh;
            st+=hh;
            st+=":";
            string mm = to_string(mmx);
            if(mm.length()==1) mm= "0"+mm;
            st+=mm;
            return st;
        }
        return "";
    }
};