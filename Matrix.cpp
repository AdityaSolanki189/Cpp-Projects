#include <iostream>
using namespace std;

class matrix{
    protected:
        int a[10][10],r[10][10],rows,columns;
    public:
        void get(int,int);
        void display(int,int);
        void addition(int,int);
};

void matrix :: get(int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
}
void matrix :: display(int r,int c){
        
}
int main(){
    char opt;
	matrix obj;
	int t = 1,rows,columns;
	while (t) {
		cout << "Select Option :\n1.Matrix Addition\n2.Matrix Subtration\n3.Matrix Multiplication\n4.Matrix Transponse\n5.Exit\n";
		cin >> opt;
		switch (opt) {
		case '1':
			cout << "\nMatrix Addiation\n";
            cout<<"Enter Matrix Dimensions : ";
            cin>>rows>>columns;
			obj.get(rows,columns);
            obj.add(rows,columns);
            obj.display(rows,columns);
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