#include <iostream>

// Declaring functions
int *createBookIsbn(int size);
std::string *createBookTitles(int size);
int *createBookPrices(int size);
void insertElement(int *isbn, std::string *title, int *price, int bookIsbn, std::string bookTitle, int bookPrice, int index, int size);
void deleteElement(int *isbn, std::string *title, int *price, int bookIsbn, int size);
void printArray(int *bookIsbn, std::string *bookTitles, int *bookPrices, int size);

int main() {

	// Declaring and initializing varibles
	int size = 10, index = 0, bookIsbn = 0, bookPrice = 0;
	std::string bookTitle;
	std::string runAgain = "yes";
	
	int *isbn = createBookIsbn(size);
	std::string *title = createBookTitles(size);
	int *price = createBookPrices(size);
	
	do {
		std::cout << "\n========== Input to Insert A Book ==========" << std::endl;
		
		std::cout << "\nEnter index you want to insert element at: ";
		std::cin >> index;

		std::cout << "Enter Book Isbn: ";
		std::cin >> bookIsbn;
		
		std::cout << "Enter Book Title: ";
		std::cin.ignore();
		getline(std::cin, bookTitle);

		std::cout << "Enter Book Price: ";
		std::cin >> bookPrice;

		insertElement(isbn, title, price, bookIsbn, bookTitle, bookPrice, index, size);

		std::cout << "\nWish to insert element again? (yes/no): ";
		std::cin >> runAgain;

		system("cls");
	}
	while(runAgain != "no");

	do {
		std::cout << "\n========== Input to Delete A Book ==========" << std::endl;
		
		std::cout << "\nEnter Book Isbn Number to delete book detail from shelf: ";
		std::cin >> bookIsbn;

		deleteElement(isbn, title, price, bookIsbn, size);

		std::cout << "\nWish to delete again? (yes/no): ";
		std::cin >> runAgain;

		system("cls");
	}
	while(runAgain != "no");

	return 0;
}

int *createBookIsbn(int size) {
	
	int *bookIsbn = new int[size];
	
	for(int i = 0; i < size; i++) {
		bookIsbn[i] = 0;
	}
	
	return bookIsbn;
}

std::string *createBookTitles(int size) {
	
	std::string *bookTitles = new std::string[size];
	
	for(int i = 0; i < size; i++) {
		bookTitles[i] = "";
	}
	return bookTitles;
}

int *createBookPrices(int size) {

	int *bookPrices = new int[size];

	for(int i = 0; i < size; i++) {
		bookPrices[i] = 0;
	}

	return bookPrices;
}

void insertElement(int *isbn, std::string *title, int *price, int bookIsbn, std::string bookTitle, int bookPrice, int index, int size) {

	for(int i = size - 1; i > index; --i) {
		
		isbn[i] = isbn[i - 1];
		title[i] = title[i - 1];
		price[i] = price[i - 1];
	}

	isbn[index] = bookIsbn;
	title[index] = bookTitle;
	price[index] = bookPrice;

	std::cout << "\n========== After Insertion ==========" << std::endl;
	printArray(isbn, title, price, size);
}

void deleteElement(int *isbn, std::string *title, int *price, int bookIsbn, int size) {
	
	for(int i = 0; i < size - 1; i++) {
		
		if(isbn[i] == bookIsbn) {
			
			isbn[i] = isbn[i + 1];
			title[i] = title[i + 1];
			price[i] = price[i + 1];
		}
	}

	std::cout << "\n========== After Deletion ==========" << std::endl;
	printArray(isbn, title, price, size);
}

void printArray(int *bookIsbn, std::string *bookTitles, int *bookPrices, int size) {
	
	for(int i = 0; i < size; i++) {
		std::cout << "Shelf[" << i << "]: " << bookIsbn[i] << ", " << bookTitles[i] << ", " << bookPrices[i] << std::endl; 
	}
}
