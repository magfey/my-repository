#include <iostream>
#include <string>
using namespace std;


class BigInt {
	char m_value[1000];
	short m_size = 0;

public:
	BigInt() {
		for (int i = 0; i < 1000; i++) {
			m_value[i] = 0;
		}
		m_size = 1;
	}

	~BigInt() {

	}

	BigInt(const string& value) {
		size_t len = value.length();
		for (int i = 0; i < len; i++)
			m_value[i] = value[len - i - 1] - '0';
		for (int i = len; i < 1000; i++) {
			m_value[i] = 0;
		}
		m_size = len;
	}

	BigInt(const BigInt& other) {
		for (int i = 0; i < 1000; i++) {
			m_value[i] = other.m_value[i];
		}
		m_size = other.m_size;
	}

	BigInt& operator+=(const BigInt& other) {
		for (int i = 0; i < m_size; i++) {
			m_value[i] += other.m_value[i];
			if (m_value[i] > 9) {
				m_value[i] -= 10;
				m_value[i + 1]++;
				if (i + 1 == m_size) {
					m_size++;
				}
			}
		}
		return *this;
	}

	BigInt operator+(const BigInt& other) {
		BigInt result(*this);
		result += other;
		return result;
	}

	BigInt& operator-=(const BigInt& other) {
		for (int i = 0; i < m_size; i++) {
			m_value[i] -= other.m_value[i];
			if (m_value[i] < 0) {
				m_value[i] += 10;
				m_value[i + 1]--;
			}
		}
		while (m_size > 1 && m_value[m_size - 1] == 0) {
			m_size--;
		}
		return *this;
	}

	BigInt operator-(const BigInt& other) {
		BigInt result(*this);
		result -= other;
		return result;
	}

	BigInt operator*(const BigInt& other) {
		BigInt result;
		result.m_size = m_size + other.m_size;
		for (int i = 0; i < result.m_size; i++) {
			result.m_value[i] = 0;
		}
		for (int i = 0; i < m_size; i++) {
			for (int j = 0; j < other.m_size; j++) {
				result.m_value[i + j] = m_value[i] * other.m_value[j];
				if (result.m_value[i + j] > 9) {
					result.m_value[i + j + 1] = result.m_value[i + j] / 10;
					result.m_value[i + j] %= 10;
				}
			}
		}
		while (result.m_size > 1 && result.m_value[result.m_size - 1] == 0) {
			result.m_size--;
		}
		return result;
	}

	bool operator<(const BigInt& other) {
		if (m_size < other.m_size) {
			return true;
		}
		if (m_size > other.m_size) {
			return false;
		}
		for (int i = m_size - 1; i >= 0; i--) {
			if (m_value[i] < other.m_value[i]) {
				return true;
			}
			if (m_value[i] > other.m_value[i]) {
				return false;
			}
		}
		return false;
	}

	bool operator>(const BigInt& other) {
		if (m_size > other.m_size) {
			return true;
		}
		if (m_size < other.m_size) {
			return false;
		}
		for (int i = m_size - 1; i >= 0; i--) {
			if (m_value[i] > other.m_value[i]) {
				return true;
			}
			if (m_value[i] < other.m_value[i]) {
				return false;
			}
		}
		return false;
	}

	bool operator==(const BigInt& other) {
		if (m_size != other.m_size) {
			return false;
		}
		for (int i = m_size - 1; i >= 0; i--) {
			if (m_value[i] != other.m_value[i]) {
				return false;
			}
		}
		return true;
	}

	bool operator!=(const BigInt& other) {
		if (m_size != other.m_size) {
			return true;
		}
		for (int i = m_size - 1; i >= 0; i--) {
			if (m_value[i] != other.m_value[i]) {
				return true;
			}
		}
		return false;
	}

	void Print() {
		for (int i = 0; i < m_size; i++) {
			std::cout << static_cast<short>(m_value[m_size - i - 1]);
		}
	}

	friend ostream& operator<<(ostream& out, const BigInt& other);

	friend istream& operator>>(istream& in, BigInt& other);
};

istream& operator>>(istream& in, BigInt& other) {
	string s;
	in >> s;
	other = BigInt(s);
	return in;
}

ostream& operator<<(ostream& out, const BigInt& other) {
	for (int i = 0; i < other.m_size; i++) {
		out << static_cast<short>(other.m_value[other.m_size - i - 1]);
	}
	return out;
}

int main() {
	setlocale(LC_ALL, "RU");
	BigInt x("26");
	BigInt y("8");
	cout << (x * y) << endl;
	cout << (x + y) << endl;
	cout << (x - y) << endl;
	x += y;
	cout << x << endl;
	cout << "введите новый y: ";
	cin >> y;
	cout << "\nновый y: " << y << endl;
	cout << (x * y) << endl;
	cout << (x + y) << endl;
	cout << (x - y) << endl;
	x += y;
	cout << x << endl;

	return 0;
}
