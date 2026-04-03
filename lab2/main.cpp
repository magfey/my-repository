#include <iostream>
#include <string>
using namespace std;

class BigInt {
	char m_value[1000];
	short m_size;
	bool m_negative;

	void NoZeros() {
		while (m_size > 1 && m_value[m_size - 1] == 0)
			--m_size;
		if (m_size == 1 && m_value[0] == 0)
			m_negative = false;
	}

public:
	BigInt() : m_size(1), m_negative(false) {
		for (int i = 0; i < 1000; ++i) m_value[i] = 0;
		m_value[0] = 0;
	}

	BigInt(const string& s) {
		for (int i = 0; i < 1000; ++i) m_value[i] = 0;
		m_negative = false;
		size_t start = 0;
		if (s[0] == '-') {
			m_negative = true;
			start = 1;
		}
		while (start < s.size() && s[start] == '0') ++start;
		if (start == s.size()) {
			m_size = 1;
			m_value[0] = 0;
			m_negative = false;
			return;
		}
		m_size = s.size() - start;
		for (size_t i = 0; i < m_size; ++i)
			m_value[i] = s[s.size() - 1 - i] - '0';
	}

	BigInt(const BigInt& other) {
		for (int i = 0; i < 1000; ++i) m_value[i] = other.m_value[i];
		m_size = other.m_size;
		m_negative = other.m_negative;
	}

	BigInt& operator=(const BigInt& other) {
		if (this != &other) {
			for (int i = 0; i < 1000; ++i) m_value[i] = other.m_value[i];
			m_size = other.m_size;
			m_negative = other.m_negative;
		}
		return *this;
	}

	BigInt operator-() const {
		BigInt res = *this;
		if (!(res.m_size == 1 && res.m_value[0] == 0))
			res.m_negative = !res.m_negative;
		return res;
	}

	BigInt& operator+=(const BigInt& other) {
		if (m_negative == other.m_negative) {
			int carry = 0;
			int maxSize;
			if (m_size > other.m_size)
				maxSize = m_size;
			else
				maxSize = other.m_size;
			for (int i = 0; i < maxSize; ++i) {
				int sum = m_value[i] + other.m_value[i] + carry;
				m_value[i] = sum % 10;
				carry = sum / 10;
			}
			if (carry) {
				m_value[maxSize] = carry;
				++maxSize;
			}
			m_size = maxSize;
		}
		else {
			bool Plus = false;
			if (m_size != other.m_size) {
				if (m_size > other.m_size)
					Plus = true;
				else
					Plus = false;
			}
			else {
				for (int i = m_size - 1; i >= 0; --i) {
					if (m_value[i] != other.m_value[i]) {
						if (m_value[i] > other.m_value[i])
							Plus = true;
						else
							Plus = false;
						break;
					}
				}
			}

			if (Plus) {
				int t = 0;
				for (int i = 0; i < m_size; ++i) {
					int dif = m_value[i] - t - (i < other.m_size ? other.m_value[i] : 0);
					if (dif < 0) {
						dif += 10;
						t = 1;
					}
					else {
						t = 0;
					}
					m_value[i] = dif;
				}
				NoZeros();
			}
			else {
				int t = 0;
				int newSize = other.m_size;
				char tmp[1000] = { 0 };
				for (int i = 0; i < other.m_size; ++i) {
					int dif = other.m_value[i] - t - (i < m_size ? m_value[i] : 0);
					if (dif < 0) {
						dif += 10;
						t = 1;
					}
					else {
						t = 0;
					}
					tmp[i] = dif;
				}
				while (newSize > 1 && tmp[newSize - 1] == 0) --newSize;
				for (int i = 0; i < newSize; ++i) m_value[i] = tmp[i];
				m_size = newSize;
				m_negative = other.m_negative;
			}
		}
		if (m_size == 1 && m_value[0] == 0) m_negative = false;
		return *this;
	}

	BigInt operator+(const BigInt& other) const {
		BigInt res = *this;
		res += other;
		return res;
	}

	BigInt& operator-=(const BigInt& other) {
		*this += (-other);
		return *this;
	}

	BigInt operator-(const BigInt& other) const {
		BigInt res = *this;
		res -= other;
		return res;
	}

	BigInt operator*(const BigInt& other) const {
		BigInt res;
		res.m_size = m_size + other.m_size;
		for (int i = 0; i < res.m_size; ++i) res.m_value[i] = 0;

		for (int i = 0; i < m_size; ++i) {
			int carry = 0;
			for (int j = 0; j < other.m_size; ++j) {
				int temp = res.m_value[i + j] + m_value[i] * other.m_value[j] + carry;
				res.m_value[i + j] = temp % 10;
				carry = temp / 10;
			}
			if (carry) {
				res.m_value[i + other.m_size] += carry;
			}
		}
		res.NoZeros();
		if (m_negative != other.m_negative)
			res.m_negative = true;
		else
			res.m_negative = false;
		if (res.m_size == 1 && res.m_value[0] == 0) res.m_negative = false;
		return res;
	}

	BigInt& operator*=(const BigInt& other) {
		*this = *this * other;
		return *this;
	}

	bool operator<(const BigInt& other) const {
		if (m_negative != other.m_negative) {
			if (m_negative) return true;
			else return false;
		}
		if (!m_negative) {
			if (m_size != other.m_size) {
				if (m_size < other.m_size) return true;
				else return false;
			}
			for (int i = m_size - 1; i >= 0; --i) {
				if (m_value[i] != other.m_value[i]) {
					if (m_value[i] < other.m_value[i]) return true;
					else return false;
				}
			}
			return false;
		}
		else {
			if (m_size != other.m_size) {
				if (m_size > other.m_size) return true;
				else return false;
			}
			for (int i = m_size - 1; i >= 0; --i) {
				if (m_value[i] != other.m_value[i]) {
					if (m_value[i] > other.m_value[i]) return true;
					else return false;
				}
			}
			return false;
		}
	}

	bool operator>(const BigInt& other) const {
		return other < *this;
	}

	bool operator==(const BigInt& other) const {
		if (m_negative != other.m_negative) return false;
		if (m_size != other.m_size) return false;
		for (int i = 0; i < m_size; ++i)
			if (m_value[i] != other.m_value[i]) return false;
		return true;
	}

	bool operator!=(const BigInt& other) const {
		return !(*this == other);
	}

	friend ostream& operator<<(ostream& out, const BigInt& a);
	friend istream& operator>>(istream& in, BigInt& a);
};

istream& operator>>(istream& in, BigInt& a) {
	string s;
	in >> s;
	a = BigInt(s);
	return in;
}

ostream& operator<<(ostream& out, const BigInt& a) {
	if (a.m_negative) out << '-';
	for (int i = a.m_size - 1; i >= 0; --i)
		out << static_cast<short>(a.m_value[i]);
	return out;
}

int main() {
	setlocale(LC_ALL, "RU");
	BigInt x, y;
	int e;
	cout << "Введите x: ";
	cin >> x;
	cout << "Введите y: ";
	cin >> y;
	cout << "x = " << x << "\ny = " << y << endl;

	do {
		cout << "1 - сложение, 2 - сложение с присваиванием, 3 - вычитание, 4 - умножение, 5 - умножение с присваиванием, 6 - равенство, 7 - неравенство, 8 - больше, 9 - меньше, 0 - выход: ";
		cin >> e;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Ошибка ввода\n";
			continue;
		}
		switch (e) {
		case 1: cout << x << " + " << y << " = " << x + y << endl; break;
		case 2: {
			BigInt old = x;
			cout << old << " += " << y << " = " << (x += y) << endl;
			break;
		}
		case 3: cout << x << " - " << y << " = " << x - y << endl; break;
		case 4: cout << x << " * " << y << " = " << x * y << endl; break;
		case 5: {
			BigInt old = x;
			cout << old << " *= " << y << " = " << (x *= y) << endl;
			break;
		}
		case 6: cout << x << (x == y ? " равно " : " не равно ") << y << endl; break;
		case 7: cout << x << (x != y ? " не равно " : " равно ") << y << endl; break;
		case 8: cout << x << (x > y ? " больше " : " не больше ") << y << endl; break;
		case 9: cout << x << (x < y ? " меньше " : " не меньше ") << y << endl; break;
		case 0: cout << "выход\n"; break;
		}
	} while (e != 0);

	return 0;
}