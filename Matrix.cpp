#include <iostream>
using namespace std;

class matrix{
    protected:
        int a[10][10],rows,columns;
    public:
        void get();
        void display();

};

int main(){
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