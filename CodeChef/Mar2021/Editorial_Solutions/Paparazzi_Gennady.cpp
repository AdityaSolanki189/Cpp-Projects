
//Pre-requisites - Convex Hull / Geometry
// Naive Approach - Brute Force O(n^3) Time Complexity
// Efficient Approach - Convex Hull + Vector Cross Product
/* Make the Convex Hull set of point (i, A_i)(i,Ai). 
And answer - Maximum of their neighboring distances */
#include <iostream>
#include <vector>

using namespace std;

struct pt {
	int x, y;
	pt() {}
	pt(int a, int b) {x = a, y = b;}
};

long long operator*(pt a, pt b) {
	return (long long) a.x * b.y - (long long) a.y * b.x;
}

pt operator-(pt a, pt b) {
	return pt(a.x - b.x, a.y - b.y);
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	vector<pt> ch = {pt(a[0], 0), pt(a[1], 1)};
	int ans = 1;
	for (int i = 2; i < n; ++i) {
		pt now = pt(a[i], i);
		while (ch.size() > 1 && (now - ch[ch.size() - 2]) * (ch[ch.size() - 1] - ch[ch.size() - 2]) >= 0)
			ch.pop_back();
		ans = max(ans, i - ch.back().y);
		ch.push_back(now);
	}
	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}