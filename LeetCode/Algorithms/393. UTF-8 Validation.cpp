class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for(const auto &val: data){
            if (!count){
                if((val>>5) == 0b110) count =1;
                else if((val>>4) == 0b1110) count = 2;
                else if((val>>3) == 0b11110) count =3;
                else if(val>>7) return false;
                continue;
            }
            if((val>>6) !=0b10) {return false; }
            count--;
        }
        if(count==0)
            return true;
        return false;
    }
};