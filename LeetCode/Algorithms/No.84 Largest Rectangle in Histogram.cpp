  /*  Time Limit Exceeded o(n^2)
  int largestRectangleArea(vector<int>& height) {
        vector<int> width;
        int maxSize =0;
        for(int i =0; i<height.size();++i){
            int tmpWidth=1;
            for(int j=i+1;j<height.size();++j){
                if(height[j]>=height[i]){
                    ++tmpWidth;
                }else{
                  break;
                }
            }
            for(int j=i-1;j>=0;--j){
                if(height[j]>=height[i]){
                    ++tmpWidth;
                }else{
                  break;
                }
            }
            width.push_back(tmpWidth);
        }
        int tmpSize = 0;
        for(int i=0;i<width.size();i++){
            tmpSize = height[i]*width[i];
            if(tmpSize>maxSize)
                maxSize = tmpSize;
        }
        return maxSize;
    }
    */
    // o(n) using stack
    int largestRectangleArea(vector<int>& height) {
         stack<int> s;
         int area = 0;
         for( int i =0 ; i<height.size();i++){
            if(s.empty()||height[s.top()]<height[i]){
                s.push(i);
            }else{
              int start =s.top();
              s.pop();
              int width = s.empty()?i:i-s.top()-1;
              area = max(area,height[start]*width);
              i--;
            }
         }
     while (!s.empty()) {
      int start = s.top();
      s.pop();
      int width = s.empty() ? height.size() : height.size() - s.top() - 1;
      area = max(area, height[start] * width);
  }
         return area;
    }
