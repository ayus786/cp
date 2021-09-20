// the main trick is to just pick the fill the digits in reverse order (like this mod of 10 and then divide it by 10 and then mod of 10).
int mul(int size, int ar[1000], int x) {
	int car = 0;
	for (int i = 0; i < size; i++) {
		int p = (ar[i] * x) + car;
		ar[i] = p % 10;
		car = p / 10;
	}
	while (car > 0) {
		ar[size] = car % 10;
		car /= 10;
		size++;
	}
	return size;
}

void solve() {
	int ar[1000];
	int size = 1;
	ar[0] = 1;
	int z = 0;
	for (int i = 2; i <= 100; i++) {
		size = mul(size, ar, i);
	}
	for (int i = size - 1; i >= 0; i--) {
// 		z += ar[i];
    cout<<ar[i];
	}
// 	cout << z << endl;
	return;
}
