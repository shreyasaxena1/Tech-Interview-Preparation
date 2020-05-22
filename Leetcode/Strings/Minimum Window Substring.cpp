class Solution {
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char, int> map;
        for(char c: t)
            map[c]++;
        
        int start = 0, end = 0, n = s.length(), minstart = 0, remaining = t.size(), minlen = INT_MAX;
        
        while(end<n)
        {   
            // If char in s exists in t, decrease remaining
            if(map[s[end]] > 0)
                remaining--;
            // Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.    
            map[s[end]]--;
            end++;
            
            // When we found a valid window, move start to find smaller window.
            while(remaining == 0)
            {
                if(end-start < minlen)
                {
                    minlen = end-start;
                    minstart = start;
                }
                map[s[start]]++;
                // When char exists in t, increase remaining.
                if(map[s[start]] > 0)
                    remaining++;
                start++;
            }
        }
        
        if(minlen != INT_MAX)
            return s.substr(minstart, minlen);
        else
            return "";
    }
};