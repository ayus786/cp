vector<int> tree(40000, 0);
void make_tree(int l, int r, int pos, vector<int>& v) {
	if (l == r) {
		tree[pos] = v[l];
	}
	else {
		int mid = (l + r) / 2;
		make_tree(l, mid, 2 * pos + 1 , v);
		make_tree(mid + 1, r, 2 * pos + 2, v);
		// tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
		// tree[pos] = min(tree[2 * pos + 1], tree[2 * pos + 2]);
	}
}
int find_max(int pos, int l, int r, int left, int right) {
	if (r < left || right < l) return INT_MIN;
	if (l == r) {
		return tree[pos];
	}
	else if (left == l && r == right) return tree [pos];
	else {
		int mid = (l + r) / 2;
		int l_left = find_max(2 * pos + 1, l, mid, left, right);
		int r_right = find_max(2 * pos + 2, mid + 1, r, left, right);
		// return max(l_left, r_right);
		// return min(l_left, r_right);
	}
}
