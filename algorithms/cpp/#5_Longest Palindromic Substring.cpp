class Solution {
public:
    
    int expandFromCenter(const string& s, int left, int right){
        int length = s.length();
        while(left>=0 && right<length && s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
    
    string longestPalindrome(string s) {
        int start=0, end=0;
    
        for(int i=0; i<s.length(); i++){
            int len1 = expandFromCenter(s, i, i);
            int len2 = expandFromCenter(s, i, i+1);
            int len = len1>len2?len1:len2;
            
            if(len>end-start+1){
                start = i-(len-1)/2;
                end = i+len/2;
            }
        }
        
        return s.substr(start, end-start+1);
    }
};
