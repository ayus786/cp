// here steps is the __gcd(n,k) this is very necessary condition many time it will take more time when its __gcd will be one
	// we can rotate our array in O(n) with O(1) extra space
	int n, k;
	cin >> n >> k;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) cin >> ar[i];
	for (int i = 0; i < __gcd(n, k); i++) {
		int j = i, temp = ar[i], d = -1;
		while (1) {
			d = (j + k) % n;
			if (d == i) {
				break;
			}
			ar[j] = ar[d];
			j = d;
		}
		ar[j] = temp;
	}
	for (auto i : ar) cout << i << " ";
