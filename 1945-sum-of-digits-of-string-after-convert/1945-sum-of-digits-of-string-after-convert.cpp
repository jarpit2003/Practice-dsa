class Solution {
public:
    int getLucky(string s, int k) {
       /* #Sabse pehle alphabet ko converrt karke product banao
        # Iske baad aap for loop lagao and k ko traverse karoa che se utou can use whiel as well
        return the answer kao fir uske baad return kardo*/
        int sum=0;
        for(char c:s)
        {
            int position = c-'a'+1;
         while(position>0)
        {
            sum+=position%10;
           position = position/10;
        }    
    }
        
       
      for(int i = 1;i<k;i++)
      {
          int newsum = 0;
          while(sum>0)
          {
              newsum +=sum%10;
              sum = sum/10;
          }
          sum = newsum;
      }
        return sum;
    }
};