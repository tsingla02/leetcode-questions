class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        queue<int> q;
        int wi = image[0].size();
        
        for(int i=0 ; i<image.size() ; i++)
        {
            int w = image[i].size();
            for(int j = w-1 ; j>=0; j--)
            {
                int s = image[i].size();
                int t = image[i][s-1];
                q.push(t);
                image[i].pop_back();
            }
            
        }
        for(int i=0 ; i<image.size() ; i++)
        {
            
            for(int j = wi-1 ; j>=0; j--)
            {
                image[i].push_back(q.front());
                q.pop();
            }
            
        }
        
        
        for(int i=0;i<image.size();i++)
        {
            for( int j =0; j<image[i].size(); j++)
            {
                if(image[i][j]==1)
                {
                    image[i][j] = 0;
                }
                else if(image[i][j]==0)
                {
                    image[i][j] = 1;
                }
            }
        }
        return image;
    }
};