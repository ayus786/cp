// path compression already achieves the time complexity O(logn) per call on average.
// There is a second modification called ranking, that will make it even faster.
struct DSU
{
	vector<int> para, ranks;
	DSU(int n) {
		para.resize(n + 1);
		ranks.resize(n + 1);
		for (int i = 0; i <= n; i++) {
			para[i] = i;
			ranks[i] = 0;
		}
	}


	int find(int x) {
		if (para[x] != x) {
			para[x] = find(para[x]);
		}
		return para[x];
	}

	void uni(int x, int y) {
		int first = find(x);
		int second = find(y);
		// if (first == second) return;
		if (ranks[first] < ranks[second]) {
			para[first] = second;
		}
		else if (ranks[first] > ranks[second]) {
			para[second] = first;
		}
		else {
			para[second] = first;
			ranks[first]++;
		}
	}
};
