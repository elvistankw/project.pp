#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//5 txt file
//user.txt
//admin.txt
//books.txt
//borrowed.txt
//review.txt
//report.txt

 
struct ReviewNode {
    int bookId;          
    string reviewerName; 
    string comment;      
    int rating;          
    ReviewNode* next;    
};

// ================= Base Classes =================

class Person {
private:
    int id;
    string name;
    string password;
    string email;
    int phone_num;
public:
    Person();
    Person(int, string, string);
    string getName() const { return name; }
    string getPassword() const { return password; }
    void setPassword(const string& newPass) { password = newPass; }
    virtual void display() const;
    virtual ~Person();
};

class BookRecord {
protected:
	//book node
    struct BookNode {
        int id;
        string title;
        string author;
        int year;
        bool available;
        BookNode* next;
    };
    BookNode* head;
public:
    BookRecord();
    virtual ~BookRecord();
    void insertBook(int, string, string, int);
    void deleteBookById(int);
    void displayBooks();
};

// ================ Derived Classes =================

class Admin : public Person {
public:
    Admin();
    Admin(int, string, string);
    void addBook();
	void editBook();
    void deleteBook();
    void sortBooks();
    void searchBook();
    void generateReport();
    void display() const override;
    friend void viewReport(Admin);
};

class Customer : public Person {
public:
    Customer();
    Customer(int, string, string);
    void searchBook();
    void borrowBook();
    void returnBook();
    void viewBorrowed();//借着的书
    void display() const override;//display全部书
    friend void displayUserInfo(Customer); // Friend function
    friend void viewBorrowHistory(const Customer);
};

class Library : public BookRecord {
public:
    Library();
    void sortBooksByTitle();               // Selection sort
	void searchBook(); 
	void searchBook(string title); 
	void searchBookByAuthor(string author); 
	void searchBook(int year); 

    BookNode* binarySearchById(int);       // Binary search
    void addReview(int bookId, string reviewerName, string comment, int rating);
    void displayReviews(int bookId);
    friend void searchHelper(Library&, string);  // Friend function
};

class UserManage {
public:
    Person* login(const string& name, const string& password);
    bool signupCustomer(const string& name, const string& password);
    bool resetPassword(const string& name, const string& newPassword);
private:
    int generateNewId(); 
};


// =============== Function Prototypes =============

void loginMenu();
void adminMenu(Admin&);
void customerMenu(Customer&);
void loadSampleBooks(Library&);
void mainMenu();

// =============== Main Function ===================

int main() {
    Library library;
    loadSampleBooks(library); 
    mainMenu();
    return 0;
} 