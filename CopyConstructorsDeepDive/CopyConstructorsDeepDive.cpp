/*
* A Copy constructor needs to be defined in the public domain.
* It has NO return type. It takes an argument of
* the instance of the class  passed by reference
*/

#include<iostream>
class Book {
private:
	std::string title{};
	std::string author{};
	int publishers{};
	int* myPtr{};

public:
	Book(std::string title, std::string author, int publishers) {
		this->title = title;
		this->author = author;
		this->publishers = publishers;
		myPtr = new int[publishers];
		std::cout << author + " Constructor Created!" << std::endl;
	}

	// This is the copy constructor 
	Book(const Book& Original) {
		title = Original.title;
		author = Original.author;
		publishers = Original.publishers;
		myPtr = Original.myPtr;

		myPtr = new int[publishers]; // Making sure the copy constructor
		for (int i = 0; i < publishers; i++)  // Creates its own Heap memory 
			myPtr[i] = Original.myPtr[i]; // To avoid program crash when it tries to delete an already deleted 
	}                                     // Heap memory 

	~Book() {
		std::cout << author + " Destructor Called!" << std::endl;
		std::cout << "Deleting Heap Memory of: " << myPtr << std::endl;
		delete[] myPtr;
		myPtr = nullptr;
	}

	void showInfo() {
		std::cout << title + " by " + author << std::endl;
	}

	void set(std::string title, std::string author) {
		this->title = title;
		this->author = author;
	}
};

int main() {
	Book book1("IoT mastery", "Dogan Ibrahim", 5);
	Book book2("MCUs Deep Dive", "Abel Ashenafi", 5);
	Book book3(book2);
	Book book4 = book1;

	std::cout << "Let's fuck things up!" << std::endl;
	book1.showInfo();
	book2.showInfo();
	book3.showInfo();
	book4.showInfo();

	return 0;
}