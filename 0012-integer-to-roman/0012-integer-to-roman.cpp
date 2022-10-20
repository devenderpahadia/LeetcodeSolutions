class Solution {
public:
    string intToRoman(int num) {
        string res = "";
            if(num/1000 > 0){
                int x = num/1000;
                while(x--){
                    res+="M";
                }
                num%=1000;
            }
            if(num/500 > 0){
                int x = num/100;
                if(x==9){
                    res+="CM";
                }
                else{
                    res+="D";
                    if(x>5){
                        x=x-5;
                        while(x--){
                            res+="C";
                        }
                    }
                }
                num = num%100;
            }
            if(num/100 > 0){
                int x = num/100;
                if(x==4){
                    res+="CD";
                }
                else{
                    if(x>0){
                        while(x--){
                            res+="C";
                        }
                    }
                }
                num = num%100;
            }
            if(num/50 > 0){
                int x = num/10;
                if(x==9){
                    res+="XC";
                }
                else{
                    res+="L";
                    if(x>5){
                        x=x-5;
                        while(x--){
                            res+="X";
                        }
                    }
                }
                num = num%10;
            }
            if(num/10 > 0){
                int x = num/10;
                if(x==4){
                    res+="XL";
                }
                else{
                    if(x>0){
                        while(x--){
                            res+="X";
                        }
                    }
                }
                num = num%10;
            }
            if(num/5 > 0){
                int x = num;
                if(x==9){
                    res+="IX";
                }
                else{
                    res+="V";
                    if(x>5){
                        x=x-5;
                        while(x--){
                            res+="I";
                        }
                    }
                }
                num = num%1;
            }
            if(num > 0){
                int x = num;
                if(x==4){
                    res+="IV";
                }
                else{
                    if(x>0){
                        while(x--){
                            res+="I";
                        }
                    }
                }
                num = num%1;
            }
         
        return res;
    }
};