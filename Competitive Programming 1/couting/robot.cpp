/*
    @description
        - n robot, robot thứ i làm công vieẹc từ x[i] đến y[i], cần y[i] - x[i] (l) sơn
        - tìm robot thứ x sao cho (n - 1) robot còn lại hoàn thành công việc từ L --> R;
    @Input & Output
        - Input: 
            + n, L, R; 
            + n cặp số nguyên x, y. miêu tả công việc;
        - Output:
            + Lượng son của con robot được điều đi;
    @algorithms
        - Ý tưởng 1:
            + Xet n robot; duyệt từ x[i] --> y[i]; worst case: 10^5 * 10^9;
        - Ý tưởng 2; 
            + sử dụng nén số, nén giá trị của x, y, L, R; 
            + lưu giá trị lượng sơn, rồi duyệt từ x' --> y'; worst case: 10^5 * 10^5;
        - Ý tườngr 3; 
            + Sử dụng nén số, nén giá trị của x, y, L , R; --> 1 <= x, y, L ,R <= n;
            + Quan tâm đến giá trị 2 đầu mút để tính couting;  
                --> bài toán prefix_sum: PS[i] = PS[i-1] + A[i];
        --> Được mnangr couting từ L --> R; duyệt mảng cnt để tìm vị trí không thể bỏ đi được (cnt[i] <= 1);

*/

#include <bits/stdc++.h>
using namespace std;
// Nén số 
void comp(vector <int> &a, int x[], int y[], int n, int &L, int &R){
    vector <int> b;
    for (int i = 0; i < int(a.size()); i++){
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    unordered_map <int, int> zip;
    int index = 1;
    for (int i = 0; i < int(b.size()); i++){
        if (i == 0 || b[i] != b[i-1]){
            zip[b[i]] = index;
            index ++;
        }
    }
    L = zip[L]; // nén giá trị L;
    R = zip[R]; // nén giá trị R;
    for (int i = 0; i < n; i++){
        x[i] = zip[x[i]];   // nén tập x và y;
        y[i] = zip[y[i]];
    }
}

int main(){
    int n;
    cin >> n;
    int L, R;
    cin >> L >> R;
    vector <int> a = {L, R};
    int x[n];
    int y[n];
    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        a.push_back(x[i]);
        a.push_back(y[i]);
    }
    // lưu gía trị lượng sơn cuar từng robot trước khi nén;
    int len[n];
    for (int i = 0; i < n; i++){
        len[i] = y[i] - x[i];
    }
    
    comp(a, x, y, n, L, R); 
    /* kĩ thuật prefix_sum:
        ps[L-->R]; 
        ps[L] = 1; 
        ps[R+1] = -1;
        couting L--> R; ps[i] = ps[i-1] + ps[i];
    */
    vector <int> ps(2 * pow(10, 5) + 2, 0);
    for (int i = 0; i < n; i++){
        ps[x[i]] += 1;            // gán ps[L] += 1
        ps[y[i] + 1] -= 1;         // gán ps[R+1] -= 1
    }
    
    for (int i = 1 ; i < ps.size(); i++){
        ps[i] = ps[i-1] + ps[i];
    }
    
    vector <int> index; // chưa vị trí không thể bỏ đi được;
    for (int i = L; i <= R; i++){
        if (ps[i] < 2 ){
            index.push_back(i);
        }
    }
    //for (int i = 0; i < index.size(); i++) cout << index[i] << " ";
    int result = 0;
    for (int i = 0; i < n; i++){

        int ans = lower_bound(index.begin(), index.end(), x[i]) - index.begin();  // giả sử có x[i] <= index <= y[i] -->> không thể bỏ được; 
        if ((ans < index.size()) && index[ans] <= y[i]) continue;
        else result = max(result, len[i]);
        //cout << result << " " << ans;
    }
    cout << result << '\n';
    return 0;
}
