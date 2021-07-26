/*	Bookstore Inventory program. */

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
const long MaxRecSize = 150;

struct BookType {
	long CopiesInStock;
	string Title;
	string Author;
};
//--------------------------------------------------------------------------------
istream & getline(istream &InFile, long &N){
	InFile >> N;
	InFile.ignore(100,'\n');
	return(InFile);
}
//--------------------------------------------------------------------------------
long NumRecords(fstream &F){
	F.seekp(0, ios::end);
	if (F.tellp()==0)
		return(0);
	else
		return(1+F.tellp()/MaxRecSize);
}
//--------------------------------------------------------------------------------
bool ReadBook(fstream &F, const long RecNum, BookType &Book)
/*	Reads record RecNum into Book
	Pre: F is open for reading
	Post: Book contains record RecNum.
	false returned if the read fails, otherwise true returned */
{
	if ((RecNum < NumRecords(F)) && (F.seekg(RecNum*MaxRecSize))) {
		getline(F, Book.CopiesInStock);
		getline(F, Book.Title);
		getline(F, Book.Author);
		return(true);
	}
	else
		return(false);
}
//--------------------------------------------------------------------------------
bool WriteBook(fstream &F, const long RecNum, const BookType &Book)
/*	Writes Book to F at position RecNum
	Pre: F is open for reading
	Post: Book written to F at RecNum record.
	false returned if read fails, true returned otherwise */
{
	if ((RecNum <= NumRecords(F)) && (F.seekp(RecNum*MaxRecSize))) {
		F.seekp(RecNum*MaxRecSize);
		F << Book.CopiesInStock << endl << Book.Title << endl << Book.Author << endl;
		return(true);
	}
	else
		return(false);
}
//--------------------------------------------------------------------------------
void ShowBook(const long N, const BookType &Book)
/*	Displays a book's data in a formatted line
	Post: N, Book displayed on a formatted line */
{
	cout.width(2); cout << N << ". ";
	cout.setf(ios::left);
	cout.width(20); cout << Book.Title << " ";
	cout.width(20); cout << Book.Author << " ";
	cout.setf(ios::right);
	cout.width(5); cout << Book.CopiesInStock << endl;
}
//--------------------------------------------------------------------------------
void ChangeBook(fstream &BookFile)
/*	Displays a book and allows user to change its stock.
	Pre: BookFile is open for read/write
	Post: Book selected by user has been displayed and
	stock may have been changed.                                    */
{
	long BookNum;
	BookType Book;
	while (true) {
		cout << "Enter number of book to change: ";
		getline(cin, BookNum);
		if (ReadBook(BookFile, BookNum, Book))
			break;
		cout << "Bad book number" << endl;
	}
	ShowBook(BookNum, Book);
	char Choice;
	cout << "Add one to copies, Subtract one, Cancel: ";
	cin >> Choice; cout << endl;
	switch (Choice) {
		case 'A':
		case 'a':	Book.CopiesInStock++;
							WriteBook(BookFile, BookNum, Book);
							break;
		case 'S':
		case 's':	Book.CopiesInStock--;
							WriteBook(BookFile, BookNum, Book);
							break;
		case 'C':
		case 'c':	cout << "Change canceled" << endl;
							break;
	}
}
//--------------------------------------------------------------------------------
void AddBook(fstream &BookFile)
/*	Adds a book record to BookFile
	Pre: BookFile is open for read/write
	Post: Book data entered by user appended to BookFile. */
{
	BookType Book;
    cin.ignore();
	cout << "Enter title: ";
	getline(cin,Book.Title);
	cout << "Enter author: ";
	getline(cin,Book.Author);
	cout << "Enter number of copies: ";
	getline(cin,Book.CopiesInStock);
	WriteBook(BookFile, NumRecords(BookFile), Book);
}
//--------------------------------------------------------------------------------
void ListBooks(fstream &BookFile)
/*	Displays a formatted table of book data.
	Pre: BookFile is open for reading
	Post: List of books displayed                     */
{
	long i;
	for (i=0; i < NumRecords(BookFile); i++) {
		BookType Book;
		ReadBook(BookFile, i, Book);
		ShowBook(i, Book);
	}
}
//--------------------------------------------------------------------------------
int main()
{
	fstream BookFile("BookData.txt", ios::in | ios::out);
	bool Quit = false;
	char Choice;
	do {
		cout << "Add title, Check/Change, List, Quit: ";
		cin >> Choice;
		cout << endl;
		switch (Choice) {
			case 'A':
			case 'a': AddBook(BookFile); break;
			case 'C':
			case 'c': ChangeBook(BookFile); break;
			case 'L':
			case 'l': ListBooks(BookFile); break;
			case 'q':
			case 'Q': Quit = true; break;
			default: cout << "Bad command" << endl;
		}
	} while (!Quit);
	return(0);
}