#include <iostream>
using namespace std;

int n, M, m[100], v[100];
int x[100], best, sumV, sumM, All[100];

void init(){
    for (int i = n; i >= 1; --i){
        All[i] = All[i+1] + v[i]; // all -> All
    }
}

void print() {
    cout << best;
}

void process(int i){
    if (sumV + All[i] <= best || sumM > M) return; // all -> All, return 0; -> return;
    if (i > n){
        best = sumV; // them dau ; vao sau sumV
        return; // return 0; -> return;
    }
    process(i+1);
    sumM += m[i];
    sumV += v[i];
    process(i+1);
    sumM -= m[i];
    sumV -= v[i];
}

int main() {
    cout << "\nHo Sy The - 20200614\n\n";

    cin >> n >> M;
    for (int i = 1; i <= n; ++i)
        cin >> m[i] >> v[i];
    init();
    process(1);
    print();
    return 0;
}