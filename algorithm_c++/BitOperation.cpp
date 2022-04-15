class BitOperation {
public:
	int get_bit(int x, int i) {
		return (x >> i) & 1;
	}
	void flip_bit(int& x, int i) {
		x ^= (1 << i);
	}
	void set_bit(int& x, int i, int val) {

		if (get_bit(x, i) ^ val) flip_bit(x, i);
	}
	void swap_bit(int& x, int a, int b) {
		int temp = get_bit(x, a);
		set_bit(x, a, get_bit(x, b));
		set_bit(x, b, temp);
	}
	int first_not_zerobit(int x) {
		for (int i = 30; i >= 0; i--) {
			if (get_bit(x, i))return i;
		}
		return -1;
	}
	int reverse(int x) {
		if (x == 0)return 0;
		int fnotz = first_not_zerobit(x);
		for (int i = fnotz; i > fnotz / 2; i--) {
			swap_bit(x, i, fnotz - i);
		}
		return x;



	}
};