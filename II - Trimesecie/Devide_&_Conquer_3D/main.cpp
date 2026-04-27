#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Point {
    double x,y,z;
};

bool compareByY(Point a, Point b) {
    if (a.y==b.y) {
        return a.z<b.z;
    }
    return a.y<b.y;
}

bool compareByX(Point a, Point b) {
    return a.x<b.x;
}

double dist(Point a,Point b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
}

double bruteForce(vector<Point>&p, int l, int r) {
    double mn=INT_MAX;

    for (int i=l; i<=r; i++) {
        for (int j=i+1; j<=r; j++) {
            mn=min(mn, dist(p[i],p[j]));
        }
    }
    return mn;
}

double DevideConquer(vector<Point>&p, int l, int r) {
    if (r-l<=3) {
        return bruteForce(p, l, r);
    }
    //Devide
    int mid=(l+r)/2;
    double midX=p[mid].x;
    //Conquer
    double d=min(DevideConquer(p, l, mid),DevideConquer(p, mid+1, r));
    //Combine
    vector<Point>strip; //tocki blisku do srednata linija
    for (int i=l; i<=r; i++) {
        if (abs(p[i].x - midX) < d) {
            strip.push_back(p[i]);
        }
    }
    //Sort po y ili z
    sort(strip.begin(), strip.end(), compareByY);
    //Proverka vo strip
    for (int i=0; i<strip.size(); i++) {
        for (int j=i+1; j<strip.size() && (strip[j].y - strip[i].y)<d; j++) {
            d=min(d, dist(strip[i], strip[j]));
        }
    }
    return  d;
}

double closestPair(vector<Point>& p) {
    sort(p.begin(), p.end(), compareByX);
    return DevideConquer(p, 0, p.size()-1);
}
int main() {
    int n;
    cin>>n;
    vector<Point>points(n);
    for (int i=0; i<n; i++) {
        cin>>points[i].x>>points[i].y>>points[i].z;
    }
    cout<<fixed<<setprecision(6)<<closestPair(points)<<endl;

return 0;
}
