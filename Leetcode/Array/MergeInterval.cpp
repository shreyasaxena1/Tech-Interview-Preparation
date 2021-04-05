#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter n" << endl;
    cin >> n;
    cout << "Enter Pairs :" << endl;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }

    sort(a.begin(), a.end());
    stack<pair<int, int>> s;
    s.push({a[0].first, a[0].second});
    for (int i = 1; i < n; i++)
    {
        int start1 = s.top().first;
        int end1 = s.top().second;

        int start2 = a[i].first;
        int end2 = a[i].second;

        if (end1 < start2)
            s.push({start2, end2});
        else
        {
            s.pop();
            end1 = max(end1, end2);
            s.push({start1, end1});
        }
    }
    cout << "Pairs are as followed :" << endl;
    while (!s.empty())
    {
        cout << s.top().first << " " << s.top().second << endl;
        s.pop();
    }

    return 0;
}


/**
 
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end(), compare);
    int i,a;
    a = intervals.size();
    Interval I;
    I.start = intervals[0].start;
    I.end = intervals[0].end;
    
    vector<Interval> ans;
    for(i=1;i<a;i++){
        if(intervals[i].start < I.end){
            I.end = max(I.end, intervals[i].end);
        }
        else {
            ans.push_back(I);
            I.start = intervals[i].start;
            I.end = intervals[i].end;
        }
    }
    ans.push_back(I);
    return ans;
}
**/