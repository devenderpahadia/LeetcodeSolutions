class Solution {
public:

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       int k=0;
        if(flowerbed.size()==1)
        {
            if(flowerbed[0]==0&&(n==1||n==0))
                return true;
            if(flowerbed[0]==1&&n==0)
                return true;
            return false;
        }
      if(flowerbed[0]==0&&flowerbed[1]==0)
      {
          k++;
          flowerbed[0]=1;
      }
        for(int i=1;i<flowerbed.size()-1;i++)
        {
          if(k==n||n==0)
              return true;
            if(flowerbed[i]==0&&flowerbed[i+1]==0&&flowerbed[i-1]==0)
            {
                k++;
                flowerbed[i]=1;
            }
        }       
            if(flowerbed.size()>2&&flowerbed[flowerbed.size()-1]==0&&flowerbed[flowerbed.size()-2]==0&&k+1==n)
                return true;
          if(k==n)
              return true;
       
        return false;
    }
};