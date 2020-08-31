#include<iostream>
using namespace std;
#define s 20

class matrix {
protected:
	int a[s][s], x, y;
public:
	void get_matrix();
	void display_matrix();
	matrix operator + (matrix);
	matrix operator - (matrix);
	matrix operator * (matrix);
	matrix transpose();
	int sumofdiagonals();
	void Check_Upper();
	void Check_Lower();
};

void matrix::get_matrix() {
	cin >> x >> y;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << "Enter Element At " << "[" << i + 1 << "," << j + 1 << "] : ";
			cin >> a[i][j];
		}
	}
}


void matrix::display_matrix() {
	cout << "\nThe Final Matrix is : \n" << endl;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << a[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << endl;
}

matrix matrix :: operator + (matrix b) {
	matrix r;
	if ((x != b.x) || (y != b.y)) {
		cout << "\nMatrix Addition Not Possible!\n";
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


matrix matrix :: operator - (matrix b) {
	matrix r;
	if ((x != b.x) || (y != b.y)) {
		cout << "\nMatrix Subraction Not Possible!\n";
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

matrix matrix :: operator * (matrix b) {
	matrix r;
	if ((x != b.y) || (y != b.x)) {
		cout << "\nMatrix Multiplication Not Possible!";
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

int matrix :: sumofdiagonals(){
	int sum =0;
	if(x==y){
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
				if(i==j){
					sum += a[i][j]; 
				}
			}
		}
		int j = y-1;
		for(int i=0;i<x;i++,j--){
			sum += a[i][j];
		} 
	}
	else {
		cout<<"\nRows & Columns Are NOT Same!\n";
	}
	return sum;
}

void matrix :: Check_Upper(){
	if(x == y){
		for(int i=1;i<x;i++){
			for(int j=0;j<i;j++){
				if(a[i][j] != 0){
					cout<<"\nNot An Upper Triangular Matrix!\n";
					return;
				}
			}
		}
		cout<<"\nIt Is An Upper Triangular Matrix!\n";
	}
	else{
		cout<<"\nThe Dimensions Are Not Equal!\n";
	}	
}

void matrix :: Check_Lower(){
	if(x == y){
		int j=x-1;
		for(int i=0;i<x,j>i;i++,j--){
			if(a[i][j] != 0){
				cout<<"\nNot A Lower Triangular Matrix!\n";
				return;
			}
		}
		cout<<"\nIt Is A Lower Triangular Matrix!\n";
	}
	else{
		cout<<"\nThe Dimensions Are Not Equal!\n";
	}
}

int main() {
	char op;
	matrix a, b, c;
	int t = 1;
	while (t) {
		cout << "Select Option :\n1.Matrix Addition\n2.Matrix Subtration\n3.Matrix Multiplication\n4.Matrix Transponse\n5.Sum OF Diagonals\n6.Upper Triangular\n7.Lower Triangular\n8.Exit\n";
		cin >> op;
		switch (op) {
		case '1':
			cout << "\nMatrix Addition\n";
			cout << "\nEnter Order Of Matrix A[x,y] : ";
			a.get_matrix();
			cout << "\nEnter Order Of Matrix B[x,y] : ";
			b.get_matrix();
			c = a + b;
			c.display_matrix();
			break;

		case '2':
			cout << "\nMatrix Subtration\n";
			cout << "\nEnter Order Of Matrix A[x,y] : ";
			a.get_matrix();
			cout << "\nEnter Order Of Matrix B[x,y] : ";
			b.get_matrix();
			c = a - b;
			c.display_matrix();
			break;

		case '3':
			cout << "\nMatrix Multpication\n";
			cout << "\nEnter Order Of Matrix A[x,y] : ";
			a.get_matrix();
			cout << "\nEnter Order Of Matrix B[x,y] : ";
			b.get_matrix();
			c = a * b;
			c.display_matrix();
			break;

		case '4':
			cout << "\nMatrix Transpose\n";
			cout << "\nEnter Order Of Matrix A[x,y] : ";
			a.get_matrix();
			c = a.transpose();
			c.display_matrix();
			break;

		case '5':
			cout<<"\nSum Of Diagonals Of The Matrix :\n";
			cout << "\nEnter Order Of Matrix A[x,y] : ";
			a.get_matrix();
			cout<<"\nSum Of Diagonals : "<<a.sumofdiagonals()<<endl;
			break;

		case '6':
			cout << "\nCheck For Upper Triangular :\n";
			cout<<"\nSum Of Diagonals Of The Matrix :\n";
			cout << "\nEnter Order Of Matrix A[x,y] : ";
			a.get_matrix();
			a.Check_Upper();
			break;

		case '7':
			cout << "\nCheck For Lower Triangular :\n";
			cout<<"\nSum Of Diagonals Of The Matrix :\n";
			cout << "\nEnter Order Of Matrix A[x,y] : ";
			a.get_matrix();
			a.Check_Lower();
			break;
		
		case '8':
			cout << "Press any key to exit\n"<<endl;
			t = 0;
			break;
			
		default:
			cout << "Enter a valid option\n"<<endl;
		}
	}
	return 0;
}
