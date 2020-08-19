#include<iostream>
using namespace std;
#define s 20

class matrix {
protected:
	int a[s][s], x, y;
public:
	void get();
	void put();
	matrix operator+(matrix);
	matrix operator-(matrix);
	matrix operator*(matrix);
	matrix transpose();
};

void matrix::get() {
	cout << "Enter the order of Matrix " << " :\n";
	cin >> x >> y;
	cout << "Enter the Matrix " << " :\n";
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> a[i][j];
		}
	}
}


void matrix::put() {
	cout << "The Ans is:\n";
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++)
			cout << a[i][j] << " ";
	}
}

matrix matrix::operator+(matrix b) {
	matrix r;
	if ((x != b.x) || (y != b.y)) {
		cout << "\nMatrix Addition is not possible\n";
		r.x = 0;
		r.y = 0;
	}
	else {
		r.x = x;
		r.y = y;
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			r.a[i][j] = a[i][j] + b.a[i][j];
		}
	}
	return r;
}


matrix matrix::operator-(matrix b) {
	matrix r;
	if ((x != b.x) || (y != b.y)) {
		cout << "\nMatrix subtraction is not possible\n";
		r.x = 0;
		r.y = 0;
	}
	else {
		r.x = x;
		r.y = y;
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			r.a[i][j] = a[i][j] - b.a[i][j];
		}
	}
	return r;
}

matrix matrix::operator*(matrix b) {
	matrix r;
	if ((x != b.y) || (y != b.x)) {
		cout << "\nMatrix Multiplication is not possible\n";
		r.x = 0;
		r.y = 0;
	}
	else {
		r.x = x;
		r.y = b.y;
	}
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			r.a[i][j] = 0;
		}
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < b.y; j++) {
			for (int k = 0; (k < y) || (k < b.x); k++) {
				r.a[i][j] += a[i][k] * b.a[k][j];
			}
		}
	}
	return r;
}

matrix matrix::transpose() {
	matrix r;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			r.a[i][j] = a[j][i];
			r.x = x;
			r.y = y;
		}
	}
	return r;
}


int main() {
	char op;
	matrix a, b, c;
	int t = 1;
	while (t) {
		cout << "Select Option :\n1.Matrix Addition\n2.Matrix Subtration\n3.Matrix Multiplication\n4.Matrix Transponse\n5.Exit\n";
		cin >> op;
		switch (op) {
		case '1':
			cout << "\nMatrix Addiation\n";
			a.get();
			b.get();
			c = a + b;
			c.put();
			break;

		case '2':
			cout << "\nMatrix Subtration\n";
			a.get();
			b.get();
			c = a - b;
			c.put();
			break;

		case '3':
			cout << "\nMatrix Multpication\n";
			a.get();
			b.get();
			c = a * b;
			c.put();
			break;

		case '4':
			cout << "\nMatrix Transpose\n";
			a.get();
			c = a.transpose();
			c.put();
			break;

		case '5':
			cout << "\nPress any key to exit\n";
			t = 0;
			break;

		default:
			cout << "\nEnter a valid option\n";
		}
	}
	return 0;
}
