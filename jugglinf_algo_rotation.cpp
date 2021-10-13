int n, k;
	cin >> n >> k;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) cin >> ar[i];
	for (int i = 0; i < k; i++) {
		int temp = ar[i];
		for (int j = i; j < n - k + i; j += k) {
			ar[j] = ar[j + k];
		}
		ar[n - k + i] = temp;
	}
	for (auto i : ar) cout << i << " ";
