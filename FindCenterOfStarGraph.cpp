class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        for(int i=0; i<2; i++) {
            if(edges[0][0] == edges[1][i] || edges[0][1] == edges[1][i]) {
                return edges[1][i];
            }
        }
        return 0;
    }
};


int init = [] {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ofstream out("user.out");
	cout.rdbuf(out.rdbuf());
	for (string line; getline(cin, line); cout << '\n') {
		istringstream ss(line);
		char ch;
		int a, b, c, d;
		ss >> ch >> ch >> a >> ch >> b >> ch >> ch >> ch >> c >> ch >> d;
		if (a == c || a == d) cout << a;
		else cout << b;
	}
	exit(0);
	return 0;
}();
