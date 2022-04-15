class Solution {
public:
	void striplz(char s[]) {
		while (*s == '0') {
			s++;
		}
	}
	int str2i(char s[], int sign) {
		int ans = 0, temp;
		while (*s) {

			temp = *s++ - '0';
			if (sign == 1 && (~(1 << 31) - temp) / 10 >= ans) {
				ans *= 10;
				ans += temp;
			}
			else if (sign == -1 && ((1 << 31) + temp) / 10 <= ans) {
				ans *= 10;
				ans -= temp;
			}
			else return 0;
		}
		return ans;
	}
	void swap(char* a, char* b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}
	void reverse(char* s, char* e) {
		while (s < e) {
			swap(s++, --e);
		}
	}
	int reverse(int x) {
		if (x == 0)return 0;

		int sign = x < 0 ? -1 : 1;

		char num[11], count = 0;
		while (x) {
			num[count++] = sign * (x % 10) + '0';
			x /= 10;
		}
		num[count] = 0;
		//reverse(num, num + count);
		x = str2i(num, sign);

		return x;



	}
};