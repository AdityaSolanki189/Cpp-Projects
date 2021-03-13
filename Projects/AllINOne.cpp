#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;
int main(){
cout << "\t\t   -------------------------------------------------------------------------------" << endl;
cout << "\t\t   -��������������-��������������-������---------��������������-------------------" << endl;
cout << "\t\t   -��������������-��������������-������---------��������������-------------------" << endl;
cout << "\t\t   -��������������-��������������-������---------��������������-------------------" << endl;
cout << "\t\t   -������---------������--������-������---------������---------------------------" << endl;
cout << "\t\t   -������---------��������������-������---------������------------��������������-" << endl;
cout << "\t\t   -������---------��������������-������---------������------------��������������-" << endl;
cout << "\t\t   -������---------��������������-������---------������------------��������������-" << endl;
cout << "\t\t   -������---------������--������-������---------������---------------------------" << endl;
cout << "\t\t   -��������������-������--������-��������������-��������������-------------------" << endl;
cout << "\t\t   -��������������-������--������-��������������-��������������-------------------" << endl;
cout << "\t\t   -��������������-������--������-��������������-��������������-------------------" << endl;
cout << "\t\t   -------------------------------------------------------------------------------" << endl;
cout << " ----------------------------------------------------------------------------------------------------------------------" << endl;
cout << " -������----------������-������--������-������---------��������������-��������������-��������������-����������������---" << endl;
cout << " -����������������������-������--������-������---------��������������-��������������-��������������-����������������---" << endl;
cout << " -����������������������-������--������-������---------��������������-��������������-��������������-����������������---" << endl;
cout << " -����������������������-������--������-������---------������--������-----������-----������--������-������----������---" << endl;
cout << " -������--������--������-������--������-������---------��������������-----������-----������--������-����������������---" << endl;
cout << " -������--������--������-������--������-������---------��������������-----������-----������--������-����������������---" << endl;
cout << " -������--������--������-������--������-������---------��������������-----������-----������--������-����������������---" << endl;
cout << " -������----------������-������--������-������---------������--������-----������-----������--������-������--������-----" << endl;
cout << " -������----------������-��������������-��������������-������--������-----������-----��������������-������--����������-" << endl;
cout << " -������----------������-��������������-��������������-������--������-----������-----��������������-������--����������-" << endl;
cout << " -������----------������-��������������-��������������-������--������-----������-----��������������-������--����������-" << endl;
cout << " ----------------------------------------------------------------------------------------------------------------------" << endl;
cout << "                                             _______________________________                                           " << endl;
cout << "                                             | PRESS ENTER TO CONTINUE.... |                                           " << endl;
cout << "                                             |_____________________________|                                           " << endl;
cin.ignore();
system("cls");
string hello = "Hello User...";
string askname = "I don't know you yet.... Please provide your name here --> ";
string name1 = "Hello there ";
string name2 = ".... :) ";
string provide = "\n\nWelcome to the CALC-MULATOR...\n\nA Calculation Simulator that can provide you the answers you wanted to know.... ";
string menu = "I will provide you the MENU for this program in ";
string count = "3 2 1";

int x=0;
string name;
while ( hello[x] != '\0')
{
	cout << hello[x];;
	Sleep(100);
	x++;
};
cout << "\n";
cout << "Press Enter to contiue..\n";
cin.ignore();
x = 0;
while ( askname[x] != '\0')
{
	cout << askname[x];;
	Sleep(50);
	x++;
};
getline(cin, name);
x = 0;
cout << "\n";
while ( name1[x] != '\0')
{
	cout << name1[x];;
	Sleep(100);
	x++;
};
x = 0;
while ( name[x] != '\0')
{
	cout << name[x];;
	Sleep(100);
	x++;
};
x = 0;
while ( name2[x] != '\0')
{
	cout << name2[x];;
	Sleep(100);
	x++;
};
x = 0;
while ( provide[x] != '\0')
{
	cout << provide[x];;
	Sleep(100);
	x++;
};
x = 0;
cout << "\n\n";
while ( menu[x] != '\0')
{
	cout << menu[x];;
	Sleep(100);
	x++;
};
x = 0;
//cout << "\n";
while ( count[x] != '\0')
{
	cout << count[x];;
	Sleep(500);
	x++;
};
system("cls");
int choice;
MENU:
cout << "\t\t\t\t\t----------NUMBER THEORIES: ----------\n";
cout << "\t\t\t\t\t---------[1] Divisibility------------\n";
cout << "\t\t\t\t\t------[2] Prime and Composite--------\n";
cout << "\t\t\t\t\t------[3] Division Algorithm---------\n";
cout << "\t\t\t\t\t----[4] Greatest Common Divisors-----\n";
cout << "\t\t\t\t\t----[5] Least Common Multiples-------\n";
cout << "\t\t\t\t\t---[6] Representations of Integers---\n";
cout << "\t\t\t\t\t----------[7] Matrices---------------\n";
cout << "\n\t\t\t\t\t   Enter your choice here --> ";
cin >> choice;
system("cls");
if(choice == 3){
	int dividend,divisor,quotient,remainder;	
	cout << "--------------- Division Algorithm ---------------";
	cout << "\nInput the Dividend -> ";
	cin >> dividend;
	cout << "\nInput the Divisor -> ";
	cin >> divisor;
	cout << "\n\nWhen we divide " << dividend << " by " << divisor << ", we have : " << endl;
	quotient = dividend / divisor;
	remainder = dividend % divisor;
	cout << dividend << " = " << divisor << " * " << quotient << " + " << remainder << endl;
	cout <<"\t" << dividend<< " is the Dividend\n";
	cout <<"\t" << divisor<< " is the Divisor\n";
	cout <<"\t" << quotient<< " is the Quotient\n";
	cout <<"\t" << remainder<< " is the Remainder\n";
}else if (choice == 5){
	int num1,num2,remainder,dividend = 0,divisor = 0,lcm,num11,num22,num3,max = 0,min = 0;
	cout << "--------------- Least Common Multiples ---------------\n";
	cout << "Input the first number -> ";
	cin >> num1;
	cout << "Input the second number -> ";
	cin >> num2;
	num11 = num1; // clone for num1
	num22 = num2; // clone for num2
	
if(num2 != 0 && num1 !=0){
		if(num1 > num2){
			max += num1;
			min += num2;
		}else if(num1 < num2){
			max += num2;
			min += num1;
		}else if(num1 == num2){
			max += num1;
			min += num2;
		}
		num3 = (max) / (min);
		int min2 = min;
		remainder = (max) % (min); 
		cout << endl << '\t' << max << " = " << min << " * " << (max)/(min) << " + " << remainder<< endl;
		while(remainder != 0){
		
			dividend += min2;
			divisor = remainder;
			remainder = dividend % divisor;
			cout <<'\t'<< dividend << " = " << divisor << " * " << (dividend)/(divisor) << " + " << remainder << endl;
			min2 = divisor;	
			dividend = 0;
			divisor = 0;
			
		}
	lcm = ((max) * (min)) / (min2);
	cout << endl << '\t' << num11 << " * " << num22 << " = " << (max) * (min) << endl;
	cout << '\t' << (max) * (min) << " / " <<  min2 << " = " << lcm << "\n\n";
	cout << "The LCM of " << num11 << " and " << num22 << " is " << lcm;
}else if(num1 == 0 && num2 == 0){
	cout << "\n\t" << num1 <<" = " << 1 << " * " << num2 << " + " << 1 * num1;
	cout << "\n\n\t" << num1 << " * " << num2 << " = " << num1 * num2;
	cout << "\n\t" << num1 << " / " << 1 << " = " << num2 / 1;
	cout << "\n\nThe LCM of " << num1 << " and " << num2 << " is " << num1 * num2;
}
}else if(choice == 1){
	
	int num,num2 = num,sum,sum2,sum3,sum4,temp,temp2,temp3,temp4;
	sum = sum2 = sum3 = sum4 = 0;
	bool test = false;
	
	cout << "---------------Divisibility---------------" << endl;
	cout << "Enter a number: ";
	cin >> num;
	for(int i = 2; i <= 12;i++){
		if(num % i == 0){
			cout << "Divisible by " << i << endl;
			test = true;
			if(i == 2){
				cout << "\tThe last digit should be an even number." << endl;
				cout << "\tThe last digit of " << num << " is " << num%10 << endl;
			} else if(i == 3){
				cout << "\tThe sum of all digits should be divisible by 3" << endl;
				temp = num;
				while (temp != 0)
			    {
			        sum = sum + temp % 10;
			        temp = temp / 10;
			    }
			    cout << "\tThe sum of the digits of " << num << " = " << sum << endl;
				cout << "\t" << sum << " divided by " << 3 << " = " << sum/3 << endl;
			} else if(i == 4){
				cout << "\tIf the Tens Digit is an even number, ";
				if((num/10)% 2 == 0){
					cout << "the Ones Digit should be (0,4,8)." << endl;
				} else{
					cout << "the Ones Digit should be (2,6)." << endl;
				}
				cout << "\tThe Tens Digit of " << num << " is " << (num/10) % 10;
				cout << "\n\tThe Ones Digit of " << num << " is " << num%10 << endl;
			} else if(i == 5){
				cout << "\tThe last digit should be either 0 or 5" << endl;
				cout << "\tThe last digit of " << num << " is " << num%10 << endl;
			} else if(i == 6){
				cout << "\tThe number should be both divisible by 2 and 3." << endl;
			} else if(i == 7){
				if(num > 99){
					cout << "\tThe twice of the last digit then subtracted "; 
					cout << "from the remaining digits should be equal to 0 or divisible by 7." << endl;
					cout << "\tThe twice of the last digit of " << num << " = " << (num%10) * 2 << endl;
					cout << "\tThe remaining digits of " << num << " = " << num/10 << endl;
					cout << "\t" << num/10 << " minus " << num%10 << " = " << (num/10) - ((num%10) * 2) << endl;
					cout << "\t" << (num/10) - ((num%10) * 2) << " divided by " << 7 << " = " << ((num/10) - ((num%10) * 2)) / 7 << endl;
				} else{
					cout << "\tThe number divided by 7 should have no remainder." << endl;
					cout << "\t" << num << " divided by 7 = " << num/7 << endl;
				}
			} else if(i == 8){
				if(num > 100){
					cout << "\tThe last three digit of the number should be divisible by 8." << endl;
					cout << "\tThe last three digit of " << num << " = " << num % 1000 << endl;
					cout << "\t" << num % 1000 << " divided by " << 8 << " = " << (num % 1000) / 8 << endl; 
				} else{
					cout << "\tThe number divided by 8 should have no remainder." << endl;
					cout << "\t" << num << " divided by 8 = " << num/8 << endl;
				}
			} else if(i == 9){
				cout << "\tThe sum of all digits should be divisible by 9" << endl;
				temp2 = num;
				while (temp2 != 0)
			    {
			        sum2 = sum2 + temp2 % 10;
			        temp2 = temp2 / 10;
			    }
			    cout << "\tThe sum of the digits of " << num << " = " << sum2 << endl;
				cout << "\t" << sum2 << " divided by " << 9 << " = " << sum2/9 << endl;
			} else if(i == 10){
				cout << "\tThe last digit should be 0." << endl;
				cout << "\tThe last digit of " << num << " is " << num%10;
			} else if(i == 11){
				cout << "\tThe sum of every second digit subtracted from all the other digits should be equal to 0 or divisible by 11." << endl;
				temp3 = num;
				while (temp3 != 0)
			    {
			        sum3 = sum3 + temp3 % 100/10;
			        temp3 = temp3 / 100;
			    }
			    cout << "\tThe sum of every second digit of " << num << " = " << sum3 << endl;
			    
			    temp4 = num;
				while (temp4 != 0)
			    {
			        sum4 = sum4 + temp4 % 1000/100;
			        temp4 = temp4 / 100;
			    }
			    cout << "\tThe sum of all other digit of " << num << " = " << sum4 + num%10 << endl;
				cout << "\t" << sum3 << " minus " << sum4 + num%10 << " = " << sum3 - (sum4 + num%10) << endl;
			} else if(i == 12){
				cout << "\tThe number should be both divisible by 3 and 4." << endl;
			}
		} 
	}
	
	if(test == false){
		cout << "\t" << num << " is not divisible from 1 - 12";
	}	
}else if(choice == 4){
int i,j,num_1,num_2,great_com,remainder;
int min=0,max=0,min2=0,dividend=0,divisor;
int num_11,num_22;
cout << "--------------- Greatest Common Divisors ---------------"<<endl;
// start of input
cout << "\nPlease Enter First Number: ";
cin >> num_1;

cout << "\nPlease Enter Second Number: ";
cin >> num_2;


if (num_1 !=0 && num_2 !=0){
	//declaring min and max for the gcd
	if (num_1 > num_2){
		max	+= num_1;
		min	+= num_2;
	}else if (num_1 < num_2){
		
		max	+= num_2;
		min	+= num_1;
		
	}else if (num_1 == num_2){
		
		max += num_1;
		min += num_2;
	}
	
	remainder = (max) % (min); // declare to get the remainder of max and min
	cout << endl << "  " << max << " = " << min << " * " <<  (max) / (min) << " + " << remainder << endl;
	while (remainder !=0){
		
		dividend += min;
		divisor = remainder;
		remainder = dividend % divisor;
		cout << "  " << dividend << " = " << divisor << " * " << (dividend) / (divisor) << " + " << remainder << endl;
		min = divisor;
		dividend =0;
		divisor =0;

		
	} 
	
		
} 

cout << endl;
cout << "The GCD of "<< num_1 << " and "<< num_2 << " is:  " << min <<endl;
if (min == 1 ){ // TO FIND IF NUM 1 AND NUM_2 IS COPRIME OR RELATIVELY PRIME
	
	cout << num_1 << " and " << num_2 << " is also Relatively Prime Integers "; 
}	
}else if(choice == 2){
	int n,d=0,f=0,r;	
	cout<<"--------------- Prime & Composite ---------------"<<endl;
	cout<<"Enter a number: "<<endl;
	cin>>n;
	d=n/2;
	
	for(int i=2;i<=d;i++){
		if(n%i==0){
			cout<<"It's a Composite Number!"<<endl;
			f=1;
	cout<<"The factors of "<<n<<" are "<<endl;
	for(i=2; i<=n; i++){
		while(n%i==0)
 {
   n /= i;
   
   cout<<i<<" ";
		}
	}
			break;
		}	
	}
	if(f==0){
		cout<<"It's a Prime Number!";
	}
}else if(choice == 7){
int choice,num1,num2,num3,num4;
int arr[10][10];
int arr2[10][10];
int arr3[10][10];
int trans[10][10];
int expo[10][10];
int expo2[10][10];
cout << "--------------- Matrices ---------------\n\n";
cout << "\t[1] Trace Matrix\n";
cout << "\t[2] Identity Matrix\n";
cout << "\t[3] Transposition of Matrix\n";
cout << "\t[4] Power of Matrix\n";
cout << "\t[5] Matrix Addition\n";
cout << "\t[6] Matrix Multiplication\n";
cout << "\t[7] Zero-One Matrix\n";
cout << "\n\n\t Enter your choice here -> ";
cin >> choice;
cout << endl << endl;
if(choice == 1){
	cout << "\tEnter # of Rows: ";
	cin >> num1;
	cout << "\tEnter # of Columns: ";
	cin >> num2;
	cout << endl;
	if(num1 == num2){
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num2; j++){
			cout << "\tEnter R[" << i << "]C[" << j <<"]: ";
			cin >> arr[i][j];
		}
	}
	cout << endl << endl << "\tThe Given Matrix:\n\t";
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num2; j++){
			cout <<  arr[i][j] << " ";
		}
		cout << endl<<'\t';
	}
	cout << endl ;
	int sum = 0;
	cout << "\t";
	for(int i = 1;i <= num1; i++){
		int j = i;
		if(i == j){
			cout <<arr[i][j] ;
			sum += arr[i][j];
			if(i == num1){
				break;
			}else{
				cout << " + ";
			} 
		}
		
	}
	cout <<"\n\tTrace Matrix = "<<sum;
}else{
	cout << "\tPlease Enter a Square Matrix.";
}
}else if(choice == 3){
	cout << "\tEnter # of Rows: ";
	cin >> num1;
	cout << "\tEnter # of Columns: ";
	cin >> num2;
	cout << endl;

	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num2; j++){
			cout << "\tEnter R[" << i << "]C[" << j <<"]: ";
			cin >> arr[i][j];
		}
	}
	cout << endl << "\tThe Given Matrix:\n\t";
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num2; j++){
			cout <<  arr[i][j] << " ";
		}
		cout << endl<<'\t';
	}
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num2; j++){
			trans[j][i] = arr[i][j];	
		}
	}	
	cout << endl << "\tTransposed Matrix:\n\t";
	for(int i = 1;i <= num2; i++){
		for(int j = 1;j <= num1; j++){
			cout <<  trans[i][j] << " ";
		}
		cout << endl<<'\t';
	}
}else if(choice == 5){
	cout << "\tEnter # of Rows for Matrix A: ";
	cin >> num1;
	cout << "\tEnter # of Columns for Matrix A: ";
	cin >> num2;
	cout << endl;
	cout << "\tEnter # of Rows for Matrix B: ";
	cin >> num3;
	cout << "\tEnter # of Columns for Matrix B: ";
	cin >> num4;
	cout << endl;
	if(num1 == num3 && num2 == num4){
	cout << "\tEnter elements of Matrix A: \n";
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num2; j++){
			cout << "\tEnter R[" << i << "]C[" << j <<"]: ";
			cin >> arr[i][j];
		}
	}
	cout << endl << "\tEnter elements of Matrix B: \n";
	for(int i = 1;i <= num3; i++){
		for(int j = 1;j <= num4; j++){
			cout << "\tEnter R[" << i << "]C[" << j <<"]: ";
			cin >> arr2[i][j];
		}
	}	
	cout << endl << "\tMatrix A:\n\t";
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num2; j++){
			cout <<  arr[i][j] << " ";
		}
		cout << endl<<'\t';
	}
	cout << endl << "\tMatrix B:\n\t";
	for(int i = 1;i <= num3; i++){
		for(int j = 1;j <= num4; j++){
			cout <<  arr2[i][j] << " ";
		}
		cout << endl<<'\t';
	}
	cout << endl << "\tMatrix A + B:\n\t";
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num4; j++){
			cout <<  arr[i][j] + arr2[i][j] << " ";
		}
		cout << endl<<'\t';
	}	
}else{
	cout << "\tPlease Enter Equal Matrices";
}
}else if(choice == 6){
	cout << "\tEnter # of Rows for Matrix A: ";
	cin >> num1;
	cout << "\tEnter # of Columns for Matrix A: ";
	cin >> num2;
	cout << endl;
	cout << "\tEnter # of Rows for Matrix B: ";
	cin >> num3;
	cout << "\tEnter # of Columns for Matrix B: ";
	cin >> num4;
	cout << endl;
	if(num1 == num3 && num2 == num4){
	cout << "\tEnter elements of Matrix A: \n";
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num2; j++){
			cout << "\tEnter R[" << i << "]C[" << j <<"]: ";
			cin >> arr[i][j];
		}
	}
	cout << endl << "\tEnter elements of Matrix B: \n";
	for(int i = 1;i <= num3; i++){
		for(int j = 1;j <= num4; j++){
			cout << "\tEnter R[" << i << "]C[" << j <<"]: ";
			cin >> arr2[i][j];
		}
	}	
	cout << endl << "\tMatrix A:\n\t";
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num2; j++){
			cout <<  arr[i][j] << " ";
		}
		cout << endl<<'\t';
	}
	cout << endl << "\tMatrix B:\n\t";
	for(int i = 1;i <= num3; i++){
		for(int j = 1;j <= num4; j++){
			cout <<  arr2[i][j] << " ";
		}
		cout << endl<<'\t';
	}
	int mult[10][10];
	for(int i = 1;i <= num1;i++){
		for(int j = 1;j <= num4;j++){
			mult[i][j] = 0;
		}
	}
	//multiply array 1 and array 2 and stores it to mult-array
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num4; j++){
			for(int k = 1;k <= num2;k++){
				mult[i][j] += arr[i][k] * arr2[k][j];
			}
		}
	}
	cout << endl << "\tMatrix A * B:\n\t";
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num4; j++){
			cout <<  mult[i][j] << " ";
		}
		cout << endl<<'\t';
	}		
}else{
	cout << "\tPlease Enter Equal Matrices";
}
	
}else if(choice == 4){
	int expnt;
	cout << "\tEnter # of Rows: ";
	cin >> num1;
	cout << "\tEnter # of Columns: ";
	cin >> num2;
	cout << "\tEnter the exponent for the elements of your array: ";
	cin >> expnt;
	cout << endl;

	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num2; j++){
			cout << "\tEnter R[" << i << "]C[" << j <<"]: ";
			cin >> arr[i][j];
		}
	}
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num2; j++){
			expo[i][j] = arr[i][j];
		}
	}
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num2; j++){
			expo2[i][j] = 0;
		}
	}
int h = 1;
while(h != expnt){
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num2; j++){
			for(int k = 1;k <= num2;k++){
				expo2[i][j] += arr[i][k] * expo[k][j];						
			}		
		}	
	}
	for(int i = 1; i <= num1; i++){
		for(int j = 1; j <= num2; j++){
			arr[i][j] = expo2[i][j];
			expo2[i][j] = 0;
		}
	}
	
	h++;
}

	cout << endl << "\tThe Given Matrix raised to " << expnt << "\n\t";
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num2; j++){
			cout <<  arr[i][j] << " ";
		}
		cout << endl<<'\t';
	}	
}else if(choice == 7){
	int choice2;
	cout << "\tEnter # of Rows for Matrix A: ";
	cin >> num1;
	cout << "\tEnter # of Columns for Matrix A: ";
	cin >> num2;
	cout << endl;
	cout << "\tEnter # of Rows for Matrix B: ";
	cin >> num3;
	cout << "\tEnter # of Columns for Matrix B: ";
	cin >> num4;
	cout << endl;
if(num1 == num3 && num2 == num4){ // TO CHECK IF THE 2 MATRICES ARE EQUAL
	cout << "\t[1] Meet Matrix" << endl;
	cout << "\t[2] Join Matrix" << endl;
	cout << endl << "\tChoose the number from the choices: ";
	cin >> choice2;
	if(choice2 == 1){
	cout << "\tEnter elements of Matrix A: \n";
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num2; j++){
			cout << "\tEnter R[" << i << "]C[" << j <<"]: ";
			cin >> arr[i][j];
		}
	}
	cout << endl << "\tEnter elements of Matrix B: \n";
	for(int i = 1;i <= num3; i++){
		for(int j = 1;j <= num4; j++){
			cout << "\tEnter R[" << i << "]C[" << j <<"]: ";
			cin >> arr2[i][j];
		}
	}	
	cout << endl << "\tMatrix A:\n\t";
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num2; j++){
			cout <<  arr[i][j] << " ";
		}
		cout << endl<<'\t';
	}
	cout << endl << "\tMatrix B:\n\t";
	for(int i = 1;i <= num3; i++){
		for(int j = 1;j <= num4; j++){
			cout <<  arr2[i][j] << " ";
		}
		cout << endl<<'\t';
	}
	cout << endl << "\tMeet of Matrix A and B:\n\t";
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num4; j++){
			cout << "(" << arr[i][j] << " v " << arr2[i][j] << ")" << " ";
		}
		cout << endl<<'\t';
	}
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num4; j++){
			if(arr[i][j] == 1 || arr2[i][j] == 1){
				arr3[i][j] = 1;
			}else if(arr[i][j] == 0 && arr2[i][j] == 0){
				arr3[i][j] = 0;
			}
		}
	}
	cout << endl << "\tMatrix C:\n\t";
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num4; j++){
			cout <<  arr3[i][j] << " ";
		}
		cout << endl<<'\t';
	}
			
	}else if(choice2 == 2){
	cout << "\tEnter elements of Matrix A: \n";
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num2; j++){
			cout << "\tEnter R[" << i << "]C[" << j <<"]: ";
			cin >> arr[i][j];
		}
	}
	cout << endl << "\tEnter elements of Matrix B: \n";
	for(int i = 1;i <= num3; i++){
		for(int j = 1;j <= num4; j++){
			cout << "\tEnter R[" << i << "]C[" << j <<"]: ";
			cin >> arr2[i][j];
		}
	}	
	cout << endl << "\tMatrix A:\n\t";
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num2; j++){
			cout <<  arr[i][j] << " ";
		}
		cout << endl<<'\t';
	}
	cout << endl << "\tMatrix B:\n\t";
	for(int i = 1;i <= num3; i++){
		for(int j = 1;j <= num4; j++){
			cout <<  arr2[i][j] << " ";
		}
		cout << endl<<'\t';
	}
	cout << endl << "\tMeet of Matrix A and B:\n\t";
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num4; j++){
			cout << "(" << arr[i][j] << " ^ " << arr2[i][j] << ")" << " ";
		}
		cout << endl<<'\t';
	}
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num4; j++){
			if(arr[i][j] == 1 && arr2[i][j] == 1){
				arr3[i][j] = 1;
			}else if(arr[i][j] == 0 || arr2[i][j] == 0){
				arr3[i][j] = 0;
			}
		}
	}
	cout << endl << "\tMatrix C:\n\t";
	for(int i = 1;i <= num1; i++){
		for(int j = 1;j <= num4; j++){
			cout <<  arr3[i][j] << " ";
		}
		cout << endl<<'\t';
	}		
	}
}else{
	cout << "\tPlease Enter Equal Matrices :) ";
}
}else if(choice == 2){
	int inprow,inpcol;
int i=0,j;
int arr[10][10];
int f=0;

cout<< "Enter number of rows: ";
cin>>inprow;
cout<< "Enter number of columns: ";
cin>>inpcol;
if(inprow == inpcol){
for(i=0;i<inprow;i++)
	for(j=0;j<inpcol;j++){
		cout<<"R["<<i+1<<"]"<<"C["<<j+1<<"]";
			cin>>arr[i][j];
	}
	
	cout<<"the given number of matrix are: \n";
		for(i=0;i<inprow;i++){
			for(j=0;j<inpcol;j++)
	cout<<"  "<<arr[i][j];
	cout<<" \n";
	
}
for(i=0;i<inprow;i++){
	for(j=0;j<inpcol;j++)
		if(i==j){
			if(arr[i][j] == 0)
			f = 1;
		}
		else{
			if(arr[i][j] != 0)
			f = 1;
		}
}
			
if (f == 1)
        cout << "Not identity matrix";
   else
    {
        cout << "identity matrix ";	

}
}else{
	cout << "Please Input Equal Matrix" ;
}

}else{
	cout << "\tInvalid Choice :(";
}	
}else if(choice == 6){
	int choice3;
	cout << "---------------- Representations of Integers ---------------\n";
	cout << "\n\t[1] Binary\n\t[2] Decimal\n\t[3] Octadecimal\n\t[4] Hexadecimal\n\n";
	cout << "Enter Kind of Input Type: ";
	cin >> choice3;
	if(choice3 == 1){
		
	int binary[100], num, i = 0, decimal = 0;
	
	cout << "~~~~~~~~~~ Binary Conversion ~~~~~~~~~~" << endl;
	cout << "Enter Binary Number: ";
	
	cin >> num;
	while (num > 0)
	{	
		binary[i] = num%10;
		num = num/10;
		i++;
	}
	
	cout << endl << "\t";
	for(i = i - 1; i >= 0; i--){
		if(i != 0){
			cout << binary[i] << "*" << "(2^" << i << ") + ";
		} else{
			cout << binary[i] << "*" << "(2^" << i << ")";
		}
		
		decimal += binary[i] * pow(2, i);
	}
	cout << "\n\nDecimal Value = " << decimal;
		
	}else if(choice3 == 2){
	
	int decimal[100], num, i = 0, value = 0, choice;
	char decimal2[100];
	
	cout << "~~~~~~~~~~ Decimal Conversion ~~~~~~~~~~\n\n";
	cout << "\t [1] Binary" << endl;
	cout << "\t [2] Decimal" << endl;
	cout << "\t [3] Octadecimal" << endl;
	cout << "\t [4] Hexadecimal" << endl;
	
	cout << "\n\tEnter Desired Output Type: ";
	cin >> choice;
	cout << "\n\tEnter Decimal Number: ";
	cin >> num;
	if(choice == 1){
		while (num > 0)
		{	
			decimal[i] = num%2;
			num = num/2;
			i++;
		}
		cout << "\n\tBinary Value = ";
		for(i = i - 1; i >= 0; i--){
			cout << decimal[i];
		}
	} else if(choice == 2){
		while (num > 0)
		{	
			decimal[i] = num%10;
			num = num/10;
			i++;
		}
		cout << endl << "\t";
		for(i = i - 1; i >= 0; i--){
			if(i != 0){
				cout << decimal[i] << "*" << "(10^" << i << ") + ";
			} else{
				cout << decimal[i] << "*" << "(10^" << i << ")";
			}
			value += decimal[i] * pow(10, i);
		}
		cout << "\n\n\tDecimal Value = " << value;
	} else if(choice == 3){
		while (num > 0)
		{	
			decimal[i] = num%8;
			num = num/8;
			i++;
		}
		cout << "\n\tOctadecimal Value = ";
		for(i = i - 1; i >= 0; i--){
			cout << decimal[i];
		}
	} else if(choice == 4){
		while (num != 0)
		{	
			value = num % 16;
			if(value == 0){
				decimal2[i] = '0';
			} else if(value == 1){
				decimal2[i] = '1';
			} else if(value == 2){
				decimal2[i] = '2';
			} else if(value == 3){
				decimal2[i] = '3';
			} else if(value == 4){
				decimal2[i] = '4';
			} else if(value == 5){
				decimal2[i] = '5';
			} else if(value == 6){
				decimal2[i] = '6';
			} else if(value == 7){
				decimal2[i] = '7';
			} else if(value == 8){
				decimal2[i] = '8';
			} else if(value == 9){
				decimal2[i] = '9';
			} else if(value == 10){
				decimal2[i] = 'A';
			} else if(value == 11){
				decimal2[i] = 'B';
			} else if(value == 12){
				decimal2[i] = 'C';
			} else if(value == 13){
				decimal2[i] = 'D';
			} else if(value == 14){
				decimal2[i] = 'E';
			} else if(value == 15){
				decimal2[i] = 'F';
			}
			num = num / 16;
			i++;
		}
		cout << "\n\tHexadecimal Value = ";
		for(i = i - 1; i >= 0; i--){
			cout << decimal2[i];
		}
	} else{
		cout << "\n\tInvalid Input" << endl;
	}		
	}else if(choice3 == 3){
	
	int octadecimal[100], num, i = 0, decimal = 0;
	
	cout << "~~~~~~~~~~ Octadecimal Conversion ~~~~~~~~~~" << endl;
	cout << "Enter Octadecimal Number: ";
	
	cin >> num;
	while (num > 0)
	{	
		octadecimal[i] = num%10;
		num = num/10;
		i++;
	}
	
	cout << endl << "\t";
	for(i = i - 1; i >= 0; i--){
		if(i != 0){
			cout << octadecimal[i] << "*" << "(8^" << i << ") + ";
		} else{
			cout << octadecimal[i] << "*" << "(8^" << i << ")";
		}
		decimal += octadecimal[i] * pow(8, i);
	}
	
	cout << "\n\nDecimal Value = " << decimal;
			
	}else if(choice3 == 4){
		
	int hexadecimal[100], i = 0, decimal = 0;
	char num[255];
	
	cout << "~~~~~~~~~~ Hexadecimal Conversion ~~~~~~~~~~" << endl;
	cout << "Enter Hexadecimal Number: ";
	cin >> num;
	
	while (num[i] > '\0'){
	
		if(num[i] == '0'){
			hexadecimal[i] = 0;
		} else if(num[i] == '1'){
			hexadecimal[i] = 1;
		} else if(num[i] == '2'){
			hexadecimal[i] = 2;
		} else if(num[i] == '3'){
			hexadecimal[i] = 3;
		} else if(num[i] == '4'){
			hexadecimal[i] = 4;
		} else if(num[i] == '5'){
			hexadecimal[i] = 5;
		} else if(num[i] == '6'){
			hexadecimal[i] = 6;
		} else if(num[i] == '7'){
			hexadecimal[i] = 7;
		} else if(num[i] == '8'){
			hexadecimal[i] = 8;
		} else if(num[i] == '9'){
			hexadecimal[i] = 9;
		} else if(num[i] == 'A' || num[i] == 'a'){
			hexadecimal[i] = 10;
		} else if(num[i] == 'B' || num[i] == 'b'){
			hexadecimal[i] = 11;
		} else if(num[i] == 'C' || num[i] == 'c'){
			hexadecimal[i] = 12;
		} else if(num[i] == 'D' || num[i] == 'd'){
			hexadecimal[i] = 13;
		} else if(num[i] == 'E' || num[i] == 'e'){
			hexadecimal[i] = 14;
		} else if(num[i] == 'F' || num[i] == 'f'){
			hexadecimal[i] = 15;
		} else{
			cout << "Wrong Input";
			return 0;
		}
		i++;
	}
	
	int q = i-1;
	cout << endl << "\t";
	for(int k = 0; k < i; k++){
		if(k != i-1){
			cout << hexadecimal[k] << "*" << "(16^" << q << ") + ";
		} else{
			cout << hexadecimal[k] << "*" << "(16^" << q << ")";
		}
		decimal += hexadecimal[k] * pow(16, q);
		q--;
	}
	cout << "\n\n\tDecimal Value = " << decimal;	
	}	
}
char swch;
cout << "\n\tTRY AGAIN? (Y/N): ";
cin >> swch;
switch(swch){
	case('y'):
		system("cls");
		goto MENU;
		break;
	case('Y'):
		system("cls");
		goto MENU;
		break;		
	case('n'):
		system("cls");
		exit(1);
		break;
	case('N'):
		system("cls");
		exit(1);
		break;		
	default:
		cout << "\tFORCED EXIT";
		system("cls");
		exit(1);
		break;
}
	return 0;
}
