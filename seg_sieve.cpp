
vector<ll> seg_seive(ll l, ll r) {
	vector<bool> dum(r - l + 1, true);
	ll sq = sqrt(r);
	vll vec;
	for (ll i = 2; i <= sq; i++) {
		for (ll j = max(i * i, ((l + i - 1) / i) * i); j <= r; j += i) {
			dum[j - l] = false;
		}
	}
	if (l == 1) dum[0] = false;
	for (ll i = l; i <= r; i++) {
		if (dum[i - l]) vec.pb(i);
	}
	return vec;
}
