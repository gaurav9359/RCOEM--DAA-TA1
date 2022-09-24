#include <bits/stdc++.h>
using namespace std;
 

 bool cmp(pair<int, int>& a,pair<int, int>& b);
 int comp1(pair<int, int>& a,pair<int, int>& b,pair<int, int>& c);
 int comp2(pair<int, int>& a,pair<int, int>& b,pair<int, int>& c);
 vector<pair<int, int> > convex_Hull(vector<pair<int, int> >& v);
 bool insideOrOutside(vector<pair<int, int> > five_Dimensional_Point,pair<int, int> point_Iterating);


 int main()
{
  int matrix[30][30];
  for(int a=0;a<30;a++){
    for(int b=0;b<30;b++){
        matrix[a][b]=rand()%10;
    }
  }

    int n = 5;
    vector<pair<int, int> > five_Dimensional_Point;

 
    five_Dimensional_Point = { { 1, 1 }, { 4, 10}, { 10, 7 },
               { 15, 3 }, { 20, 18 }};

    // five_Dimensional_Point = { { 1, 1 }, { 4, 10}, { 10, 7 },
    //            { 13, 3 }, { 12, 9 }};

    // five_Dimensional_Point = { { 1, 3 }, { 4,5}, { 8, 7 },
    //            { 9, 3 }, { 12, 12 }};
    
    // five_Dimensional_Point = { { 5, 1 }, { 4, 4}, { 9, 7 },
    //            { 3, 3 }, { 12, 12 }};
 
    // five_Dimensional_Point = { { 14, 1 }, { 14, 4}, { 9, 7 },
    //            { 5, 3 }, { 6, 12 }};

    // five_Dimensional_Point = { { 13, 1 }, { 4, 4}, { 11, 9 },
    //            { 5, 11 }, { 1, 3}};
   
   int ans=0;
   for(int a=0;a<30;a++){
    for(int b=0;b<30;b++){
         pair<int, int> point_Iterating = { a, b };
    if (insideOrOutside(five_Dimensional_Point, point_Iterating)) {
        ans+=matrix[a][b];
     }
    }
  }
  cout<<ans<<endl;
    return 0;
}

bool cmp(pair<int, int>& a,pair<int, int>& b){
 
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int comp1(pair<int, int>& a,pair<int, int>& b,pair<int, int>& c){
 
    int p = a.first * (b.second - c.second)
            + b.first * (c.second - a.second)
            + c.first * (a.second - b.second);
 
    return p < 0ll;
}

int comp2(pair<int, int>& a,pair<int, int>& b,pair<int, int>& c){
 
    int p = a.first * (b.second - c.second)+ b.first * (c.second - a.second)+ c.first * (a.second - b.second);
    return p > 0ll;
}
 
vector<pair<int, int> > convex_Hull(vector<pair<int, int> >& v){
    sort(v.begin(),v.end(), cmp);
 
    int n = v.size();
    if (n <= 3)
        return v;
    pair<int, int> p1 = v[0];
    pair<int, int> p2 = v[n - 1];
    vector<pair<int, int> > up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < n; i++) {
 
        if (i == n - 1 || !comp2(p1, v[i], p2)) {
 
            while (up.size() > 1&& comp2(up[up.size() - 2],up[up.size() - 1],v[i])) {
                up.pop_back();
            }
            up.push_back(v[i]);
        }
 
        if (i == n - 1 || !comp1(p1, v[i], p2)) {
 
            while (down.size() > 1&& comp1(down[down.size() - 2],down[down.size() - 1],v[i])) {
                down.pop_back();
            }
            down.push_back(v[i]);
        }
    }
 
    for (int i = down.size() - 2;i > 0; i--){
        up.push_back(down[i]);
    }

    up.resize(unique(up.begin(),up.end())- up.begin());
 
    return up;
}

bool insideOrOutside(vector<pair<int, int> > five_Dimensional_Point,pair<int, int> point_Iterating){

    five_Dimensional_Point.push_back(point_Iterating);

    five_Dimensional_Point = convex_Hull(five_Dimensional_Point);

    for (auto x : five_Dimensional_Point) {

        if (x == point_Iterating)
            return false;
    }
    return true;
}

