int val(char c) {
	if ('0' <= c && c <= '9') return c - '0';
	return c - 'A' + 10;
}

int reVal(int num) {
	if (0 <= num && num <= 9) return (char)(num + '0');
	return (char)(num - 10 + 'A');
}

string baseChange(string num, int from_base, int to_base) {
	ll base10 = 0, power = 1;
	for (int i = num.size() - 1; i >= 0; --i) {
		base10 += val(num[i]) * power;
		power *= from_base;
	}
	char res[100];
	int idx = 0;
	while (base10 > 0) {
		res[idx++] = reVal(base10 % to_base);
		base10 /= to_base;
	}
	res[idx] = '\0';
	string ret(res);
	reverse(ret.begin(), ret.end());
	return ret;
}
