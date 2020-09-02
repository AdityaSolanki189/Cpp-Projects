#include<iostream>
using namespace std;
#define s 20

class matrix {
protected:
	int a[s][s],b[s][s],res[s][s],x1,y1,x2,y2,xr,yr;
public:
	void get_matrix();
	void display_matrix();
	void add_matrix();
    void sub_matrix();
    void multi_matrix();
};

void matrix :: get_matrix(){
    cout << "\nEnter Order Of Matrix A : ";
    cin >> x1 >> y1;
	for (int i = 0; i < x1; i++) {
		for (int j = 0; j < y1; j++) {
			cout << "Enter Element At " << "[" << i + 1 << "," << j + 1 << "] : ";
			cin >> a[i][j];
		}
	}
    cout << "\nEnter Order Of Matrix B : ";
    cin >> x2 >> y2;
	for (int i = 0; i < x2; i++) {
		for (int j = 0; j < y2; j++) {
			cout << "Enter Element At " << "[" << i + 1 << "," << j + 1 << "] : ";
			cin >> b[i][j];
		}
	}
}

void matrix :: display_matrix(){
    cout<<"\nThe Resultant Matrix : \n"<<endl;
    for (int i = 0; i < xr; i++) {
		for (int j = 0; j < yr; j++) {
			cout<<" "<<res[i][j]<<" ";
		}
        cout<<endl;
	}
    cout<<endl;
}

void matrix :: add_matrix(){
    if(x1==x2 && y1==y2){
        xr = x1;
        yr = y1;
        res[xr][yr];
        for (int i = 0; i < xr; i++) {
		    for (int j = 0; j < yr; j++) {
			    res[i][j] = a[i][j] + b[i][j];
		    }
	    }
        display_matrix();
    }
    else{
        cout<<"Matrix Addition Not Possible!";
    }
}

void matrix :: sub_matrix(){
    if(x1==x2 && y1==y2){
        xr = x1;
        yr = y1;
        res[xr][yr];
        for (int i = 0; i < xr; i++) {
		    for (int j = 0; j < yr; j++) {
			    res[i][j] = a[i][j] - b[i][j];
		    }
	    }
        display_matrix();
    }
    else{
        cout<<"Matrix Subtraction Not Possible!";
    }
}

void matrix :: multi_matrix(){
    if(x1 != y2 && y1 != x2){
        cout<<"\nMatrix Multiplication Not Possible!\n";
        return;
    }
    else{
        xr = x1;
        yr = y2;
        res[xr][yr];
        for (int i = 0; i < x1; i++) {
		    for (int j = 0; j < y2; j++) {
                res[i][j]=0;
			    for (int k = 0; k<y1; k++) {
				    res[i][j] += a[i][k] * b[k][j];
			    }
		    }
	    }
        display_matrix();
    }
}

int main(){
    char op;
	matrix obj;
	int t = 1;
	while (t) {
		cout << "\nSelect Option :\n1.Matrix Addition\n2.Matrix Subtraction\n3.Matrix Multiplication\n4.Exit\n";
		cin >> op;
		switch (op) {
		case '1':
			cout << "\nMatrix Addition\n";
			obj.get_matrix();
            obj.add_matrix();
			break;

		case '2':
			cout << "\nMatrix Subtraction\n";
			obj.get_matrix();
            obj.sub_matrix();
			break;

		case '3':
			cout << "\nMatrix Multpication\n";
			obj.get_matrix();
            obj.multi_matrix();
			break;

		case '4':
			cout << "Press any key to exit\n"<<endl;
			t = 0;
			break;

		default:
			cout << "Enter a valid option\n"<<endl;
		}
	}
    return 0;
}