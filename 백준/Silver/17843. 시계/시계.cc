#include <bits/stdc++.h>

using namespace std;

double A_h = 30;
double A_m = 1.0/2;
double A_s = 1.0/120;

double B_m = 6;
double B_s = 1.0/10;

double C_s = 6;

int main() {
    int T;
    cin >> T;

    for(int i=0; i<T; i++) {
        double A, B, C;
        vector<double> v(3);
        cin >> A >> B >> C;

        v[0] = A*A_h + B*A_m + C*A_s;
        v[1] = B*B_m + C*B_s;
        v[2] = C*C_s;

        sort(v.begin(), v.end());

        vector<double> diff(3);

        diff[0] = min(v[1]-v[0], 360-v[1]+v[0]);
        diff[1] = min(v[2]-v[1], 360-v[2]+v[1]);
        diff[2] = min(v[2]-v[0], 360-v[2]+v[0]);

        sort(diff.begin(), diff.end());

        cout << fixed << setprecision(6) << diff[0] << '\n';
    
    }

    return 0;
}
