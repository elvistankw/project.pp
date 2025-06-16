#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

/*
 * =================================================================================
 * JR LIBRARY MANAGEMENT SYSTEM
 * =================================================================================
 * 
 * ABOUT
 * This library management system is designed to handle books and magazine
 * management for educational institutions. It includes custom implementations
 * of data structures and algorithms to demonstrate C++ programming concepts.
 * 
 * FEATURES
 * - User and admin management
 * - Book and magazine cataloging
 * - Borrowing and returning functionality
 * - Custom implementations of:
 *   - Bubble Sort algorithm
 *   - Binary Search algorithm
 *   - Linked list data structures
 * 
 * LEARNING GOALS
 * - Demonstrate understanding of core data structures
 * - Implement algorithms without built-in functions
 * - Gain practical experience in real-world applications
 * 
 * PROJECT CREATED BY: JR Library Development Team
 * VERSION: 1.0.0
 * CONTACT: support@jrlibrary.example.com
 * 
 * =================================================================================
 */

#define CYAN "\033[32m" //green color
#define RED "\033[31m"//red color
#define RESET "\033[0m"//reset color
using namespace std;

//5 txt file
//user.txt
//admin.txt /
//books.txt /
//borrowed.txt
//review.txt
//magazine.txt 


// review 
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
    string id;
    string name;
    string password;
    string email;
    string phone_num;
public:
    Person() : id(""), name(""), password(""), email(""), phone_num("") {}
    
    Person(const string& id, const string& name, const string& password,
           const string& email = "", const string& phone_num = "")
        : id(id), name(name), password(password), email(email), phone_num(phone_num) {}
	
    string getID() 
	{
    	return id;
	}
    string getName() 
	{ 
		return name; 
	}
    string getPassword() 
	{ 
		return password; 
	}
    string getEmail() 
	{
    	return email;
	}
	string getPhoneNum()
	{
		return phone_num;
	}
	void setName(string& newName)
	{
		name=newName;
	}
	void setEmail(string& newEmail)
	{
		email=newEmail;
	}
	void setPhoneNum(string& newPhoneNum){
		phone_num=newPhoneNum;
	}
    void setPassword(string& newPass) 
	{ 
		password = newPass; 
	}
	
    virtual void display() {
    	cout << "ID: " << id << endl;
	    cout << "Name: " << name << endl;
	    cout << "Email: " << email << endl;
	    cout << "Phone: " << phone_num << endl;
	};
	
    virtual ~Person(){};
};


//Book 
class BookRecord {
public:
	//book node
    struct BookNode {
        string id;
        string title;
        string author;
        int year;
        bool available;
        BookNode* next;
        
        void setTitle(string& newTitle) 
		{
	        title = newTitle;
	    }
	
	    void setAuthor( string& newAuthor) 
		{
	        author = newAuthor;
	    }
	
	    void setYear(int newYear) 
		{
	        year = newYear;
	    }
	    
	    void setAvailable(bool status) 
		{
	    	available=status;
		}
		
    };
    BookNode* head;

    BookRecord() : head(nullptr){};
    
    

    virtual ~BookRecord()
	{
    	BookNode* current = head;
	    while (current != nullptr) 
		{
	        BookNode* next = current->next;
	        delete current;
	        current = next;
    	}
	};
	
    void insertBook(string id, string title, string author, int year){
    	BookNode* temp = head; //create a temporary pointer from first noe in chain table head
	    while (temp != nullptr) //if  current nodee is not empty, it will continue the while loo
		{
	        if (temp->id == id) //if the book d f a node is same with the new book id
			{
	            cout << "Error: Book ID already exists!\n";
	            return;
	        }
	        temp = temp->next; //else continue t check
	    }
	
		//use new create a new BookNode node
	    BookNode* newNode = new BookNode{id, title, author, year, true, nullptr}; //nullptr=current no next node 
	
	    if (head == nullptr) // if the head of the chain table is null, that mean the new book is first book
		{
	        head = newNode;
	    } 
		else 
		{
	        BookNode* last = head; // use last find the last node
	        while (last->next != nullptr) 
			{
	            last = last->next;
	        }
	        last->next = newNode; //else add new node after last
	    }
	};
	
    void deleteBookById(string id) {
    	BookNode* temp = head;
	    BookNode* prev = nullptr;
	
	    while (temp != nullptr) 
		{
	        if (temp->id == id) 
			{
	            if (prev == nullptr) 
				{
	                head = temp->next; 
	            } 
				else 
				{
	                prev->next = temp->next; 
	            }
	            delete temp;
	            cout << "Book deleted successfully!\n";
	            return;
	        }
	        prev = temp;
	        temp = temp->next;
	    }
	    cout << "Book ID not found!\n";
	};
    
    void setAvailable(string id, bool isAvailable){
    	BookNode* temp = head;
	    while (temp != nullptr) 
		{
	        if (temp->id == id) {
	            temp->available = isAvailable;
	            return;
	        }
	        temp = temp->next;
    	}
    	cout << "Error: Book ID not found!\n";
	}
	
    void displayBooks(){
    	cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                                                                       View All Books\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
    	if (head == nullptr) {
	        cout << "No books available.\n";
	        return;
	    }
	
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	    cout << "ID\t\tTitle\t\t\t\tAuthor\t\t\t\tYear\t\tStatus\n";
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	
	    BookNode* temp = head;
	    while (temp != nullptr) {
	        cout << temp->id << "\t\t"
	             << temp->title << "\t\t\t"
	             << temp->author << "\t\t\t"
	             << temp->year << "\t\t";
	             if (temp->available) 
				 {
				    cout << CYAN << "AVAILABLE" << RESET;
				 } else {
				    cout << RED << "BORROWED" << RESET;
				 }
				cout << endl << endl;

	        temp = temp->next;
	    }
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	};
	
	void displayAvailableBooks() {
	    cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                                                                       View Available Books\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	
	    if (head == nullptr) {
	        cout << "No books available.\n";
	        return;
	    }
	
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	    cout << "ID\t\tTitle\t\t\t\tAuthor\t\t\t\tYear\t\tStatus\n";
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	
	    BookNode* temp = head;
	    bool found = false;
	    while (temp != nullptr) {
	        if (temp->available) {
	            cout << temp->id << "\t\t"
	                 << temp->title << "\t\t\t"
	                 << temp->author << "\t\t\t"
	                 << temp->year << CYAN << "\t\tAVAILABLE" << RESET << endl <<endl;
	            found = true;
	        }
	        temp = temp->next;
	    }
	    if (!found) cout << "No available books found.\n";
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	}
	
	void displayBorrowedBooks() {
	    cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                                                                       View Borrowed Books\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	
	    if (head == nullptr) {
	        cout << "No books available.\n";
	        return;
	    }
	
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	    cout << "ID\t\tTitle\t\t\t\tAuthor\t\t\t\tYear\t\tStatus\n";
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	
	    BookNode* temp = head;
	    bool found = false;
	    while (temp != nullptr) {
	        if (!temp->available) {
	            cout << temp->id << "\t\t"
	                 << temp->title << "\t\t\t"
	                 << temp->author << "\t\t\t"
	                 << temp->year << RED << "\t\tBORROWED" << RESET << endl << endl;
	            found = true;
	        }
	        temp = temp->next;
	    }
	    if (!found) cout << "No borrowed books found.\n";
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	}
	
	void displayMagazine(){
    	cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                                                                       View All Magazine\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
    	if (head == nullptr) {
	        cout << "No books available.\n";
	        return;
	    }
	
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	    cout << "ID\t\tTitle\t\t\t\tAuthor\t\t\t\tYear\t\tStatus\n";
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	
	    BookNode* temp = head;
	    while (temp != nullptr) {
	        cout << temp->id << "\t\t"
	             << temp->title << "\t\t\t"
	             << temp->author << "\t\t\t"
	             << temp->year << "\t\t";
	             if (temp->available) 
				 {
				    cout << CYAN << "AVAILABLE" << RESET;
				 } else {
				    cout << RED << "BORROWED" << RESET;
				 }
				cout << endl << endl;

	        temp = temp->next;
	    }
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	};
	
	void displayAvailableMagazine() {
	    cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                                                                       View Available Magazine\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	
	    if (head == nullptr) {
	        cout << "No books available.\n";
	        return;
	    }
	
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	    cout << "ID\t\tTitle\t\t\t\tAuthor\t\t\t\tYear\t\tStatus\n";
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	
	    BookNode* temp = head;
	    bool found = false;
	    while (temp != nullptr) {
	        if (temp->available) {
	            cout << temp->id << "\t\t"
	                 << temp->title << "\t\t\t"
	                 << temp->author << "\t\t\t"
	                 << temp->year << CYAN << "\t\tAVAILABLE" << RESET << endl <<endl;
	            found = true;
	        }
	        temp = temp->next;
	    }
	    if (!found) cout << "No available books found.\n";
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	}
	
	void displayBorrowedMagazine() {
	    cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                                                                       View Borrowed Magazine\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	
	    if (head == nullptr) {
	        cout << "No books available.\n";
	        return;
	    }
	
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	    cout << "ID\t\tTitle\t\t\t\tAuthor\t\t\t\tYear\t\tStatus\n";
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	
	    BookNode* temp = head;
	    bool found = false;
	    while (temp != nullptr) {
	        if (!temp->available) {
	            cout << temp->id << "\t\t"
	                 << temp->title << "\t\t\t"
	                 << temp->author << "\t\t\t"
	                 << temp->year << RED << "\t\tBORROWED" << RESET << endl << endl;
	            found = true;
	        }
	        temp = temp->next;
	    }
	    if (!found) cout << "No borrowed books found.\n";
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	}
    
    void saveBooksToFile(const string& filename) {
        ofstream outFile(filename, ios::trunc);
        if (!outFile) {
            cerr << "Error opening file for writing!\n";
            return;
        }

        BookNode* temp = head;
        while (temp != nullptr) {
            outFile << temp->id << ","
                   << temp->title << ","
                   << temp->author << ","
                   << temp->year << ","
                   << (temp->available ? "1" : "0") << ",\n"; 
            temp = temp->next;
        }
        outFile.close();
    }
    
    void loadBooksFromFile(const string& filename) {
    	BookNode* current = head;
	    while (current != nullptr) {
	        BookNode* toDelete = current;
	        current = current->next;
	        delete toDelete;
	    }
	    head = nullptr;
	    
	    ifstream inFile(filename);
	    if (!inFile) {
	        cerr << "Error opening file for reading!\n";
	        return;
	    }
	
	    string line;
	    while (getline(inFile, line)) {
	        stringstream ss(line);
	        string id, title, author, yearStr, availableStr;
	
	        getline(ss, id, ',');
	        getline(ss, title, ',');
	        getline(ss, author, ',');
	        getline(ss, yearStr, ',');
	        getline(ss, availableStr,',');
	
	        int year = stoi(yearStr);
	        bool available = (availableStr == "1");
	        
	        BookNode* newNode = new BookNode{id, title, author, year, available, nullptr};
	
	        if (head == nullptr) 
			{
	            head = newNode;
	        } else {
	            BookNode* temp = head;
	            while (temp->next != nullptr) {
	                temp = temp->next;
	            }
	            temp->next = newNode;
	        }
        	setAvailable(id, available);
	    }
	
	    inFile.close();
	}

    
    
};

// ================ Derived Classes =================

class Admin : public Person {
private:
	struct AdminNode {
		Admin* admin; 
	    AdminNode* next;
	    AdminNode(Admin* a) : admin(a), next(nullptr) {}
		};
		
		AdminNode* head;
	
public:
    Admin(){
    	head = nullptr;
	};
	
	Admin(string id, string name, string password, string email = "", string phone_num = "") : Person(id, name, password, email, phone_num) {}
	

	
	bool adminLogin() {
		system("cls");
	    string inputEmail, inputPassword;
	    
	    cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                                                                     Admin Login\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "Enter email: ";
	    getline(cin,inputEmail);
	    cout << "Enter password: ";
	    cin >> inputPassword;
	
	    AdminNode* temp = head;
	    while (temp != nullptr) {
	        if (temp->admin->getEmail() == inputEmail && temp->admin->getPassword() == inputPassword) {
	            cout << "\nLogin successful! Welcome, " << temp->admin->getName() << "!" << endl;
	            cin.ignore();
	            cin.get();
	            return true;
	        }
	        temp = temp->next;
	    }
	
	    cout << "\nLogin failed. Invalid username or password.\n";
	    cin.ignore();
	    cin.get();
	    return false;

	}

    
    bool isDuplicateID(string id) 
	{
	    AdminNode* temp = head;
	    while (temp != nullptr) 
		{
	        if (temp->admin->getID() == id) 
			{
	            return true; 
	        }
	        temp = temp->next;
	    }
	    return false; 
	}
	
	bool isDuplicateEmail(string email) 
	{
	    AdminNode* temp = head;
	    while (temp != nullptr) 
		{
	        if (temp->admin->getEmail() == email) 
			{
	            return true;
	        }
	        temp = temp->next;
	    }
	    return false;
	}


    void addAdmin()
	{
    	string id;
	    string name;
		string password;
		string confirm_password;
		string email;
		string phone_num;
		
		cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                                                                     Add New Admin\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
		do{
			cout << "Enter Admin ID: ";
		    getline(cin,id);
		    if(id.empty()){
		    	cout<< "ID cannot be empty. Please try again.\n";
			}
		} while(id.empty()); 
	    
	    do {
	        cout << "Enter name: ";
	        getline(cin, name);
	        if (name.empty()) {
	        	cout << "Name cannot be empty. Please try again.\n";
			}
	    } while (name.empty());
	    
	    do {
	        cout << "Enter password: ";
	        getline(cin, password);
	        if (password.empty()) {
	            cout << "Password cannot be empty.\n";
	            continue;
	        }
	        cout << "Confirm password: ";
	        getline(cin, confirm_password);
	        if (password != confirm_password) {
	            cout << "Passwords do not match. Please try again.\n";
	        }
	    } while (password.empty() || password != confirm_password);
	    
	    do {
	        cout << "Enter email : ";
	        getline(cin, email);
	            if (email.empty()) cout << "Email cannot be empty. Please try again.\n";
	    } while (email.empty());
	    
	    do {
	        cout << "Enter phone number: ";
	        getline(cin, phone_num);
	            if (phone_num.empty()) cout << "Phone number cannot be empty. Please try again.\n";
	    } while (phone_num.empty());
	    
	    // Check for duplicate ID or email 
	    if (isDuplicateID(id) || isDuplicateEmail(email)) 
		{
	        cout << "Error: ID or admin email already exists. Add unsuccessfully!" << endl;
	        return;
	    }
	
	    
	Admin* newAdmin = new Admin(id, name, password, email, phone_num);

	AdminNode* newNode = new AdminNode(newAdmin);
	
	    if (head == nullptr) 
		{
	        head = newNode;
	    } 
		else 
		{
	        AdminNode* temp = head;
	        	while (temp->next != nullptr)
				{
	        		temp = temp->next;
				}
				temp->next = newNode;
    	}
    	cout << "Add New Admin Successfully!" << endl;

	}
	
	void editAdmin()
	{
	    bool success = true;
		cout << "  ____________\n";
		cout << "  |  _       |\n";
		cout << "  | | |      |\n";
		cout << "  | | |___   |\n";
		cout << "  | |_____|  |\n";
		cout << "  |__________|\n\n";
		cout << "     JR Library\n";
		cout << "JR Library Management System\n";
		cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
		if (head == nullptr) 
		{
	        cout << "No admin records available." << endl;
	        return;
	    }
	    
	    string editID;
	    cout << "Enter Admin ID to edit: ";
	    getline(cin,editID);  
	
	    AdminNode* temp = head;
	    while (temp != nullptr && success) 
		{  
	
		    if (temp->admin->getID() == editID) 
	        {
	            cout << "\n                                                               Current Admin Information\n\n";
	            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	            cout << "ID\t\t\t\t\tName\t\t\t\tEmail\t\t\t\tPhone Number" << endl;
	            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	            cout << temp->admin->getID() << "\t\t\t\t" << temp->admin->getName() << "\t\t\t" << temp->admin->getEmail() << "\t\t\t" << temp->admin->getPhoneNum() << endl;
	            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	
	            int choice;
	            do {
	                cout << "\nWhich information do you want to edit?" << endl;
	                cout << "1. Name" << endl;
	                cout << "2. Password" << endl;
	                cout << "3. Email" << endl;
	                cout << "4. Phone Number" << endl;
	                cout << "5. Exit Edit" << endl;
	                cout << "Enter your choice: ";
	                if (!(cin >> choice)) {
	                    cin.clear();
	                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	                    cout << "Invalid input. Please enter a number." << endl;
	                    continue;
	                }
	                cin.ignore();
	
	                switch (choice) {
	                    case 1: {
	                        string newName;
	                        do {
	                            cout << "Enter new name (current: " << temp->admin->getName() << "): ";
	                            getline(cin, newName);
	                            if (newName.empty()) {
	                            	cout << "Name cannot be empty. Please try again.\n";
								}
	                        } while (newName.empty());
	                        temp->admin->setName(newName);
	                        break;
	                    }
	
	                    case 2: {
	                        string password, confirm_password;
	                        do {
	                            cout << "Enter new password: ";
	                            getline(cin, password);
	                            if (password.empty()) {
	                                cout << "Password cannot be empty.\n";
	                                continue;
	                            }
	                            cout << "Confirm password: ";
	                            getline(cin, confirm_password);
	                            if (password != confirm_password) {
	                                cout << "Passwords do not match. Please try again.\n";
	                            }
	                        } while (password.empty() || password != confirm_password);
	                        temp->admin->setPassword(password);
	                        break;
	                    }
	
	                    case 3: {
	                        string newEmail;
							do {
							    cout << "Enter new email (current: " << temp->admin->getEmail() << "): ";
							    getline(cin, newEmail);
							    if (newEmail.empty()) {
							        cout << "Email cannot be empty. Please try again.\n";
							    } else if (isDuplicateEmail(newEmail)) {
							        cout << "Email already exists. Please try another one.\n";
							    }
							} while (newEmail.empty() || isDuplicateEmail(newEmail));
							
							temp->admin->setEmail(newEmail);
	                        break;
	                    }
	
	                    case 4: {
	                        string phoneInput;
	                        do {
	                            cout << "Enter new phone number (current: " << temp->admin->getPhoneNum() << "): ";
	                            getline(cin, phoneInput);
	                            if (phoneInput.empty()) cout << "Phone number cannot be empty. Please try again.\n";
	                        } while (phoneInput.empty());
	                        temp->admin->setPhoneNum(phoneInput);
	                        break;
	                    }
	
	                    case 5:
	                        cout << "Finished editing admin.\n";
	                        break;
	
	                    default:
	                        cout << "Invalid choice. Try again.\n";
	                }
	
	            } while (choice != 5);
	
	            cout << "Admin updated successfully!" << endl;
	            return;
	        }
	
	        temp = temp->next;
	    }

        cout << "Admin ID not found." << endl;
	    
	    if (!success) {
	        cerr << "Error occurred during admin editing" << endl;
	        cout << "Failed to edit admin. Please try again." << endl;
	    }
	}
	
	void removeAdmin() {
	    if (head == nullptr) 
		{
	        cout << "No admins in the list to remove." << endl;
	        return;
	    }
	    
	    cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                                                                     Delete Admin\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
		
	    string targetID;
	    cout << "Enter Admin ID to remove: ";
	    getline(cin,targetID);
	
	    AdminNode* temp = head;
	    AdminNode* prev = nullptr;
	
	    while (temp != nullptr && temp->admin->getID() != targetID) 
		{
	        prev = temp;
	        temp = temp->next;
	    }
	
	    if (temp == nullptr) 
		{
	        cout << "Admin with ID " << targetID << " not found." << endl;
	        return;
	    }
	
	    if (temp == head) 
		{
	        head = head->next;
	    } 
		else 
		{
	        prev->next = temp->next;
	    }
	
	    delete temp;
	    cout << "Admin with ID " << targetID << " has been removed successfully." << endl;
	}
	
	void saveAdminToFile() 
	{
		ofstream outFile("admin.txt", ios::trunc); 
		if (outFile.is_open()) 
		{
			AdminNode* temp = head;
	        while (temp != nullptr) 
	        {
			    outFile << temp->admin->getID() << "," << temp->admin->getName() << "," << temp->admin->getPassword() << "," << temp->admin->getEmail() << "," << temp->admin->getPhoneNum() << endl;
	            temp = temp->next;
	        }
		    outFile.close();
		    cout << "Admin information is save into the admin.txt..." << endl;
		} else {
		    cout << "Save admin information unsuccessfully, cannot open txt file..." << endl;
		}
	}

	
	void loadAdminsFromFile() {
		AdminNode* current = head;
	    while (current != nullptr) 
		{
	        AdminNode* toDelete = current;
	        current = current->next;
	        delete toDelete;
	    }
	    head = nullptr;
    
	    ifstream inFile("admin.txt");
	    if (!inFile.is_open()) {
	        cout << "Cannot found admin.txt, load unsuccessfully..." << endl;
	        return;
	    }
	
	    string line;
	    while (getline(inFile, line)) 
		{
	        stringstream ss(line);
	        string id, name, password, email, phone;
	        getline(ss, id, ',');
	        getline(ss, name, ',');
	        getline(ss, password, ',');
	        getline(ss, email, ',');
	        getline(ss, phone);
	
			Admin* a = new Admin(id, name, password, email, phone);

			AdminNode* newNode = new AdminNode(a);

	        if (head == nullptr)
			{
	        	head = newNode;
			}
	        else 
			{
	            AdminNode* temp = head;
	            while (temp->next != nullptr)
				{
	            	temp = temp->next;
				}
	            temp->next = newNode;
	        }
	    }
	
	    inFile.close();
	} 
	
	void displayAdmin()
	{
		if (head == nullptr) {
	        cout << "No admin records found." << endl;
	        return;
	    }
	    
	    AdminNode* temp = head;
	    cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                                                                     View Admin\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	    cout << "ID\t\t\t\t\tName\t\t\t\tEmail\t\t\t\tPhone Number" << endl;
	    cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	    
	    while (temp != nullptr) {
	        cout << temp->admin->getID() << "\t\t\t\t";
	        cout << temp->admin->getName()  << "\t\t\t";
	        cout << temp->admin->getEmail()  << "\t\t\t";
	        cout << temp->admin->getPhoneNum() << endl;
	        cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	        temp = temp->next;  
	    }
	}
 
    void addBook(BookRecord& bookRecord){
    	cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                                                                       Add New Book\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
    	string id, title, author;
	    int year;
	
	    cout << "Enter Book ID: ";
	    getline(cin, id);
	    cout << "Enter Title: ";
	    getline(cin, title);
	    cout << "Enter Author: ";
	    getline(cin, author);
	    cout << "Enter Year: ";
	    cin >> year;
	    cin.ignore(); 
	
	    bookRecord.insertBook(id, title, author, year);
	    bookRecord.saveBooksToFile("books.txt");
	    bookRecord.loadBooksFromFile("books.txt");
	    cout << "Book added successfully!\n";
	};
	
	void editBook(BookRecord& bookRecord){
		cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                                                                       Edit Book\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
		string newTitle;
		string newAuthor;
		int newYear;
		 
		if (bookRecord.head == nullptr) 
		{
        cout << "No books to edit.\n";
        return;
	    }
	
	    string id;
	    cout << "Enter Book ID to edit: ";
	    getline(cin, id);
	
	    BookRecord::BookNode* temp = bookRecord.head;
	    while (temp != nullptr) {
	        if (temp->id == id) {
	            cout << "\n                                                         Current Book Information\n\n";
	            cout << "----------------------------------------------------------------------------------------------------------------------------------\n";
	            cout << "ID\t\t\tTitle\t\t\t\tAuthor\t\t\t\tYear\t\t\tAvailable\n";
	            cout << "----------------------------------------------------------------------------------------------------------------------------------\n";
	            cout << temp->id << "\t\t\t" << temp->title << "\t\t\t" << temp->author << "\t\t\t" << temp->year << "\t\t\t" << (temp->available ? "Yes" : "No") << endl;
	            cout << "----------------------------------------------------------------------------------------------------------------------------------\n";
	
	            int choice;
	            do {
	                cout << "\nWhich information do you want to edit?" << endl;
	                cout << "1. Title" << endl;
	                cout << "2. Author" << endl;
	                cout << "3. Year" << endl;
	                cout << "4. Availability" << endl;
	                cout << "5. Exit Edit" << endl;
	                cout << "Enter your choice: ";
	                cin >> choice;
	                cin.ignore(); // Flush newline
	
	                switch (choice) {
	                    case 1: {
	                        string newTitle;
	                        do {
	                            cout << "Enter new title (current: " << temp->title << "): ";
	                            getline(cin, newTitle);
	                            if (newTitle.empty()) 
								{
	                            	cout << "Title cannot be empty. Please try again.\n";
								}
	                        } while (newTitle.empty());
	                        temp->setTitle(newTitle);
	                        break;
	                    }
	
	                    case 2: {
	                        string newAuthor;
	                        do {
	                            cout << "Enter new author (current: " << temp->author << "): ";
	                            getline(cin, newAuthor);
	                            if (newAuthor.empty()) 
								{
	                            	cout << "Author cannot be empty. Please try again.\n";
								}
	                        } while (newAuthor.empty());
	                        temp->setAuthor(newAuthor);
	                        break;
	                    }
	
	                    case 3: {
	                        int newYear;
	                        cout << "Enter new year (current: " << temp->year << "): ";
	                        while (!(cin >> newYear)) {
	                            cout << "Invalid input. Please enter a valid year: ";
	                            cin.clear();
	                            cin.ignore(1000, '\n');
	                        }
	                        cin.ignore();
	                        temp->setYear(newYear);
	                        break;
	                    }
	
	                    case 4: {
	                        int availChoice;
	                        cout << "Set availability (1 = Yes, 0 = No). Current: " << (temp->available ? "Yes" : "No") << ": ";
	                        cin >> availChoice;
	                        cin.ignore();
	                        temp->setAvailable(availChoice == 1);
	                        break;
	                    }
	
	                    case 5:
	                        cout << "Finished editing book.\n";
	                        break;
	
	                    default:
	                        cout << "Invalid choice. Try again.\n";
	                }
	
	            } while (choice != 5);
            
	            cout << "Book updated successfully!\n";
	            bookRecord.saveBooksToFile("books.txt");
	            bookRecord.loadBooksFromFile("books.txt");
	            return;
	        }
	        temp = temp->next;

	    }
	    cout << "Book ID not found!\n";
	};
	
    void deleteBook(BookRecord& bookRecord){
    	cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                                                                       Delete Book\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
    	if (head == nullptr) 
		{
        	cout << "No books to delete.\n";
        	return;
	    }
	
	    string id;
	    cout << "Enter Book ID to delete: ";
	    getline(cin, id);
		bookRecord.deleteBookById(id);
		bookRecord.saveBooksToFile("books.txt");
		bookRecord.loadBooksFromFile("books.txt");
	};
	
	void addMagazine(BookRecord& bookRecord){
    	cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                                                                       Add New Magazine\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
    	string id, title, author;
	    int year;
	
	    cout << "Enter Magazine ID: ";
	    getline(cin, id);
	    cout << "Enter Title: ";
	    getline(cin, title);
	    cout << "Enter Author: ";
	    getline(cin, author);
	    cout << "Enter Year: ";
	    cin >> year;
	    cin.ignore(); 
	
	    bookRecord.insertBook(id, title, author, year);
	    bookRecord.saveBooksToFile("magazine.txt");
	    bookRecord.loadBooksFromFile("magazine.txt");
	    cout << "Book added successfully!\n";
	};
	
	void editMagazine(BookRecord& bookRecord){
		cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                                                                       Edit Magazine\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
		string newTitle;
		string newAuthor;
		int newYear;
		 
		if (bookRecord.head == nullptr) 
		{
        cout << "No Magazines to edit.\n";
        return;
	    }
	
	    string id;
	    cout << "Enter Magazine ID to edit: ";
	    getline(cin, id);
	
	    BookRecord::BookNode* temp = bookRecord.head;
	    while (temp != nullptr) {
	        if (temp->id == id) {
	            cout << "\n                                                         Current Magazine Information\n\n";
	            cout << "----------------------------------------------------------------------------------------------------------------------------------\n";
	            cout << "ID\t\t\tTitle\t\t\t\tAuthor\t\t\tYear\t\t\tAvailable\n";
	            cout << "----------------------------------------------------------------------------------------------------------------------------------\n";
	            cout << temp->id << "\t\t\t" << temp->title << "\t\t\t" << temp->author << "\t\t\t\t" << temp->year << "\t\t\t" << (temp->available ? "Yes" : "No") << endl;
	            cout << "----------------------------------------------------------------------------------------------------------------------------------\n";
	
	            int choice;
	            do {
	                cout << "\nWhich information do you want to edit?" << endl;
	                cout << "1. Title" << endl;
	                cout << "2. Author" << endl;
	                cout << "3. Year" << endl;
	                cout << "4. Availability" << endl;
	                cout << "5. Exit Edit" << endl;
	                cout << "Enter your choice: ";
	                cin >> choice;
	                cin.ignore(); // Flush newline
	
	                switch (choice) {
	                    case 1: {
	                        string newTitle;
	                        do {
	                            cout << "Enter new title (current: " << temp->title << "): ";
	                            getline(cin, newTitle);
	                            if (newTitle.empty()) cout << "Title cannot be empty. Please try again.\n";
	                        } while (newTitle.empty());
	                        temp->setTitle(newTitle);
	                        break;
	                    }
	
	                    case 2: {
	                        string newAuthor;
	                        do {
	                            cout << "Enter new author (current: " << temp->author << "): ";
	                            getline(cin, newAuthor);
	                            if (newAuthor.empty()) cout << "Author cannot be empty. Please try again.\n";
	                        } while (newAuthor.empty());
	                        temp->setAuthor(newAuthor);
	                        break;
	                    }
	
	                    case 3: {
	                        int newYear;
	                        cout << "Enter new year (current: " << temp->year << "): ";
	                        while (!(cin >> newYear)) {
	                            cout << "Invalid input. Please enter a valid year: ";
	                            cin.clear();
	                            cin.ignore(1000, '\n');
	                        }
	                        cin.ignore();
	                        temp->setYear(newYear);
	                        break;
	                    }
	
	                    case 4: {
	                        int availChoice;
	                        cout << "Set availability (1 = Yes, 0 = No). Current: " << (temp->available ? "Yes" : "No") << ": ";
	                        cin >> availChoice;
	                        cin.ignore();
	                        temp->setAvailable(availChoice == 1);
	                        break;
	                    }
	
	                    case 5:
	                        cout << "Finished editing book.\n";
	                        break;
	
	                    default:
	                        cout << "Invalid choice. Try again.\n";
	                }
	
	            } while (choice != 5);
            
	            cout << "Magazine updated successfully!\n";
	            bookRecord.saveBooksToFile("magazine.txt");
	            bookRecord.loadBooksFromFile("magazine.txt");
	            return;
	        }
	        temp = temp->next;

	    }
	    cout << "Magazine ID not found!\n";
	};
	
    void deleteMagazine(BookRecord& bookRecord){
    	cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                                                                       Delete Magazine\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
    	if (head == nullptr) 
		{
        	cout << "No magazine to delete.\n";
        	return;
	    }
	
	    string id;
	    cout << "Enter Magazine ID to delete: ";
	    getline(cin, id);
		bookRecord.deleteBookById(id);
		bookRecord.saveBooksToFile("magazine.txt");
		bookRecord.loadBooksFromFile("magazine.txt");
	};
	
	struct BorrowNode {
	    string userId, bookId, title, author, borrowDate, returnDate;
	    int year;
	    bool returned; // 0 = not returned, 1 = returned
	    BorrowNode* next;
	}; 
	
	void viewBorrowedBooks() {
	    ifstream file("borrowedBook.txt");
	    if (!file) {
	        cout << "Error opening borrowed.txt file!\n";
	        return;
	    }
	
	    BorrowNode* head = nullptr;
	    BorrowNode* tail = nullptr;
	
	    string line;
	    while (getline(file, line)) {
	        if (line.empty()) continue;
	        
	        stringstream ss(line);
	        string userId, bookId, title, author, yearStr, borrowDate, returnDate, returnedStr;
	        getline(ss, userId, ',');
	        getline(ss, bookId, ',');
	        getline(ss, title, ',');
	        getline(ss, author, ',');
	        getline(ss, yearStr, ',');
	        getline(ss, borrowDate, ',');
	        getline(ss, returnDate, ',');
	        getline(ss, returnedStr, ',');
	
	        bool returned = (returnedStr == "1");
	
	        if (!returned) {
	            BorrowNode* newNode = new BorrowNode{
	                userId, bookId, title, author, borrowDate, returnDate,
	                stoi(yearStr), returned, nullptr
	            };
	            if (!head) {
	                head = tail = newNode;
	            } else {
	                tail->next = newNode;
	                tail = newNode;
	            }
	        }
	    }
	
	    file.close();
	
		cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                                                                      View Borrowed Books\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "\nBooks Currently Borrowed (Not Yet Returned):\n";
		cout << "-------------------------------------------------------------------------------------------------------------------------\n";
		cout << left
		     << setw(12) << "User ID"
		     << setw(12) << "Book ID"
		     << setw(30) << "Title"
		     << setw(20) << "Author"
		     << setw(16) << "Borrow Date"
			 << setw(16) << "Return Date"
			 << setw(15) << "Returned"
			 << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------\n";
		
		BorrowNode* current = head;
		while (current) {
		    if (!current->returned) { 
		        cout << left
		             << setw(12) << current->userId
		             << setw(12) << current->bookId
		             << setw(30) << current->title.substr(0, 28)
		             << setw(20) << current->author.substr(0, 18)
		             << setw(20) << current->borrowDate
					 <<setw(15) << current->returnDate
					<<setw(10) << (current->returned ? "Yes" : "No")
		 << endl;
		    }
		    current = current->next;
		}
		cout << "-------------------------------------------------------------------------------------------------------------------------\n";

	    while (head) {
	        BorrowNode* temp = head;
	        head = head->next;
	        delete temp;
	    }
	    
	    cout << "\nPress Enter to return to menu...";
		cin.ignore(); 
		cin.get();    
	}
	
	
	void viewBorrowedHistory() {
	    ifstream file("borrowedBook.txt");
	    if (!file) {
	        cout << "Error opening borrowed.txt file!\n";
	        return;
	    }
	
	    BorrowNode* head = nullptr;
	    BorrowNode* tail = nullptr;
	
	    string line;
	    while (getline(file, line)) {
	        if (line.empty()) continue;
	
	        stringstream ss(line);
	        string userId, bookId, title, author, yearStr, borrowDate, returnDate, returnedStr;
	        getline(ss, userId, ',');
	        getline(ss, bookId, ',');
	        getline(ss, title, ',');
	        getline(ss, author, ',');
	        getline(ss, yearStr, ',');
	        getline(ss, borrowDate, ',');
	        getline(ss, returnDate, ',');
	        getline(ss, returnedStr, ',');
	
	        bool returned = (returnedStr == "1");
	
	        if (returned) {
	            BorrowNode* newNode = new BorrowNode{
	                userId, bookId, title, author, borrowDate, returnDate,
	                stoi(yearStr), returned, nullptr
	            };
	            if (!head) {
	                head = tail = newNode;
	            } else {
	                tail->next = newNode;
	                tail = newNode;
	            }
	        }
	    }
	
	
		cout << "  ____________\n";
		cout << "  |  _       |\n";
		cout << "  | | |      |\n";
		cout << "  | | |___   |\n";
		cout << "  | |_____|  |\n";
		cout << "  |__________|\n\n";
		cout << "     JR Library\n";
		cout << "JR Library Management System\n";
		cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "                                                                       View Borrowed Record (Books)\n\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "\nBooks Borrowed History (All Records):\n";
	    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
	    cout << left
	         << setw(12) << "User ID"
	         << setw(12) << "Book ID"
	         << setw(30) << "Title"
	         << setw(20) << "Author"
	         << setw(20) << "Borrow Date"
	         << setw(15) << "Return Date"
	         << setw(10) << "Returned"
	         << endl;
	    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
	
	    BorrowNode* current = head;
	    while (current) {
	        cout << left
	             << setw(12) << current->userId
	             << setw(12) << current->bookId
	             << setw(30) << current->title.substr(0, 28)
	             << setw(20) << current->author.substr(0, 18)
	             << setw(20) << current->borrowDate
	             << setw(15) << current->returnDate
	             << setw(10) << (current->returned ? "Yes" : "No")
	             << endl;
	        current = current->next;
	    }
	
	    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
		
		    while (head) {
		        BorrowNode* temp = head;
		        head = head->next;
		        delete temp;
		    }
		    
		    char choice;
			cout<< "\n\nDo you need to generate a Borrowed Books Record Report? (Y or N) :";
			cin>>choice;
			
			if(toupper(choice) == 'Y'){
				int yearFilter, monthFilter;
			    cout << "Enter the YEAR to filter by (e.g., 2024): ";
			    cin >> yearFilter;
			    cout << "Enter the MONTH to filter by (1 - 12): ";
			    cin >> monthFilter;
			    cin.ignore();
			    
			    
			    ifstream file("borrowedBook.txt");  
				if (!file) {
				    cout << "Error opening borrowedBook.txt file again!\n";
				    return;
				}

			
			    auto extractYear = [](const string& dateStr) -> int {
			        if (dateStr.length() < 4) return -1;
			        return stoi(dateStr.substr(0, 4));
			    };
			    
			    auto extractMonth = [](const string& dateStr) -> int {
			        if (dateStr.length() < 7) return -1;
			        return stoi(dateStr.substr(5, 2));
			    };
			
			    BorrowNode* head = nullptr;
			    BorrowNode* tail = nullptr;
			
			    string line;
			    while (getline(file, line)) {
			        if (line.empty()) continue;
			
			        stringstream ss(line);
			        string userId, bookId, title, author, yearStr, borrowDate, returnDate, returnedStr;
			        getline(ss, userId, ',');
			        getline(ss, bookId, ',');
			        getline(ss, title, ',');
			        getline(ss, author, ',');
			        getline(ss, yearStr, ',');
			        getline(ss, borrowDate, ',');
			        getline(ss, returnDate, ',');
			        getline(ss, returnedStr, ',');
			
			        bool returned = (returnedStr == "1");
			        int y = extractYear(returnDate);
			        int m = extractMonth(returnDate);
			
			        if (returned && y == yearFilter && m == monthFilter) {
			            BorrowNode* newNode = new BorrowNode{
			                userId, bookId, title, author, borrowDate, returnDate,
			                stoi(yearStr), returned, nullptr
			            };
			            if (!head) {
			                head = tail = newNode;
			            } else {
			                tail->next = newNode;
			                tail = newNode;
			            }
			        }
			    }
			    file.close();
			
			    cout << "\nBorrowed Books Records - " << yearFilter << "/" << (monthFilter < 10 ? "0" : "") << monthFilter << "\n";
			    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
			    cout << left
			         << setw(12) << "User ID"
			         << setw(12) << "Book ID"
			         << setw(30) << "Title"
			         << setw(20) << "Author"
			         << setw(20) << "Borrow Date"
			         << setw(15) << "Return Date"
			         << setw(10) << "Returned"
			         << endl;
			    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
			
			    BorrowNode* current = head;
			    while (current) {
			        cout << left
			             << setw(12) << current->userId
			             << setw(12) << current->bookId
			             << setw(30) << current->title.substr(0, 28)
			             << setw(20) << current->author.substr(0, 18)
			             << setw(20) << current->borrowDate
			             << setw(15) << current->returnDate
			             << setw(10) << "Yes"
			             << endl;
			        current = current->next;
			    }
			    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
			
			        string filename = "borrowedHistoryReport_" + to_string(yearFilter) + "_" + (monthFilter < 10 ? "0" : "") + to_string(monthFilter) + ".txt";
			        ofstream report(filename);
			        if (report) {
			            report << "Borrowed Magazine History - " << yearFilter << "/" << (monthFilter < 10 ? "0" : "") << monthFilter << "\n";
			            report << "-------------------------------------------------------------------------------------------------------------------------\n";
			            report << left
			                   << setw(12) << "User ID"
			                   << setw(12) << "Book ID"
			                   << setw(30) << "Title"
			                   << setw(20) << "Author"
			                   << setw(20) << "Borrow Date"
			                   << setw(15) << "Return Date"
			                   << setw(10) << "Returned"
			                   << endl;
			            report << "-------------------------------------------------------------------------------------------------------------------------\n";
			            current = head;
			            while (current) {
			                report << left
			                       << setw(12) << current->userId
			                       << setw(12) << current->bookId
			                       << setw(30) << current->title.substr(0, 28)
			                       << setw(20) << current->author.substr(0, 18)
			                       << setw(20) << current->borrowDate
			                       << setw(15) << current->returnDate
			                       << setw(10) << "Yes"
			                       << endl;
			                current = current->next;
			            }
			            report << "-------------------------------------------------------------------------------------------------------------------------\n";
			            report.close();
			            cout << " Report saved as '" << filename << "'.\n";
			    }
			
			    while (head) {
			        BorrowNode* temp = head;
			        head = head->next;
			        delete temp;
			    }
			}

		    cout << "\nPress Enter to return to menu...";
			cin.ignore(); 
			cin.get();    
	}
	
	void viewBorrowedMagazine() {
	    ifstream file("borrowedMagazines.txt");
	    if (!file) {
	        cout << "Error opening borrowed.txt file!\n";
	        return;
	    }
	
	    BorrowNode* head = nullptr;
	    BorrowNode* tail = nullptr;
	
	    string line;
	    while (getline(file, line)) {
	        if (line.empty()) continue;
	        
	        stringstream ss(line);
	        string userId, bookId, title, author, yearStr, borrowDate, returnDate, returnedStr;
	        getline(ss, userId, ',');
	        getline(ss, bookId, ',');
	        getline(ss, title, ',');
	        getline(ss, author, ',');
	        getline(ss, yearStr, ',');
	        getline(ss, borrowDate, ',');
	        getline(ss, returnDate, ',');
	        getline(ss, returnedStr, ',');
	
	        bool returned = (returnedStr == "1");
	
	        if (!returned) {
	            BorrowNode* newNode = new BorrowNode{
	                userId, bookId, title, author, borrowDate, returnDate,
	                stoi(yearStr), returned, nullptr
	            };
	            if (!head) {
	                head = tail = newNode;
	            } else {
	                tail->next = newNode;
	                tail = newNode;
	            }
	        }
	    }
	
	    file.close();
	
		cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                                                                       View Borrowed Magazine\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "\nBooks Currently Borrowed (Not Yet Returned):\n";
		cout << "-------------------------------------------------------------------------------------------------------------------------\n";
		cout << left
		     << setw(12) << "User ID"
		     << setw(15) << "Magazine ID"
		     << setw(30) << "Title"
		     << setw(20) << "Author"
		     << setw(16) << "Borrow Date"
			 << setw(16) << "Return Date"
			 << setw(15) << "Returned"
			 << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------\n";
		
		BorrowNode* current = head;
		while (current) {
		    if (!current->returned) { 
		        cout << left
		             << setw(12) << current->userId
		             << setw(15) << current->bookId
		             << setw(30) << current->title.substr(0, 28)
		             << setw(20) << current->author.substr(0, 18)
		             << setw(20) << current->borrowDate
					 <<setw(15) << current->returnDate
					<<setw(10) << (current->returned ? "Yes" : "No")
		 << endl;
		    }
		    current = current->next;
		}
		cout << "-------------------------------------------------------------------------------------------------------------------------\n";

	    while (head) {
	        BorrowNode* temp = head;
	        head = head->next;
	        delete temp;
	    }
	    
	    cout << "\nPress Enter to return to menu...";
		cin.ignore(); 
		cin.get();    
	}
	
	
	void viewBorrowedMagazineHistory() {
	    ifstream file("borrowedMagazines.txt");
	    if (!file) {
	        cout << "Error opening borrowed.txt file!\n";
	        return;
	    }
	
	    BorrowNode* head = nullptr;
	    BorrowNode* tail = nullptr;
	
	    string line;
	    while (getline(file, line)) {
	        if (line.empty()) continue;
	
	        stringstream ss(line);
	        string userId, bookId, title, author, yearStr, borrowDate, returnDate, returnedStr;
	        getline(ss, userId, ',');
	        getline(ss, bookId, ',');
	        getline(ss, title, ',');
	        getline(ss, author, ',');
	        getline(ss, yearStr, ',');
	        getline(ss, borrowDate, ',');
	        getline(ss, returnDate, ',');
	        getline(ss, returnedStr, ',');
	
	        bool returned = (returnedStr == "1");
	
	        if (returned) {
	            BorrowNode* newNode = new BorrowNode{
	                userId, bookId, title, author, borrowDate, returnDate,
	                stoi(yearStr), returned, nullptr
	            };
	            if (!head) {
	                head = tail = newNode;
	            } else {
	                tail->next = newNode;
	                tail = newNode;
	            }
	        }
	    }
	
	    file.close();
	
	cout << "  ____________\n";
	cout << "  |  _       |\n";
	cout << "  | | |      |\n";
	cout << "  | | |___   |\n";
	cout << "  | |_____|  |\n";
	cout << "  |__________|\n\n";
	cout << "     JR Library\n";
	cout << "JR Library Management System\n";
	cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "                                                                       View Borrowed Records (Magazines)\n\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
    cout << "\nMagazines Borrowed History (All Records):\n";
    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
    cout << left
         << setw(12) << "User ID"
         << setw(15) << "Magazine ID"
         << setw(30) << "Title"
         << setw(20) << "Author"
         << setw(20) << "Borrow Date"
         << setw(15) << "Return Date"
         << setw(10) << "Returned"
         << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------\n";

    BorrowNode* current = head;
    while (current) {
        cout << left
             << setw(12) << current->userId
             << setw(15) << current->bookId
             << setw(30) << current->title.substr(0, 28)
             << setw(20) << current->author.substr(0, 18)
             << setw(20) << current->borrowDate
             << setw(15) << current->returnDate
             << setw(10) << (current->returned ? "Yes" : "No")
             << endl;
        current = current->next;
    }

    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
	
	    while (head) {
	        BorrowNode* temp = head;
	        head = head->next;
	        delete temp;
	    }
	    
	    char choice;
			cout<< "\n\nDo you need to generate a Borrowed Books Record Report? (Y or N) :";
			cin>>choice;
			
			if(toupper(choice) == 'Y'){
				int yearFilter, monthFilter;
			    cout << "Enter the YEAR to filter by (e.g., 2024): ";
			    cin >> yearFilter;
			    cout << "Enter the MONTH to filter by (1 - 12): ";
			    cin >> monthFilter;
			    cin.ignore();
			    
			    
			    ifstream file("borrowedMagazines.txt");  
				if (!file) {
				    cout << "Error opening borrowedBook.txt file again!\n";
				    return;
				}

			
			    auto extractYear = [](const string& dateStr) -> int {
			        if (dateStr.length() < 4) return -1;
			        return stoi(dateStr.substr(0, 4));
			    };
			    
			    auto extractMonth = [](const string& dateStr) -> int {
			        if (dateStr.length() < 7) return -1;
			        return stoi(dateStr.substr(5, 2));
			    };
			
			    BorrowNode* head = nullptr;
			    BorrowNode* tail = nullptr;
			
			    string line;
			    while (getline(file, line)) {
			        if (line.empty()) continue;
			
			        stringstream ss(line);
			        string userId, bookId, title, author, yearStr, borrowDate, returnDate, returnedStr;
			        getline(ss, userId, ',');
			        getline(ss, bookId, ',');
			        getline(ss, title, ',');
			        getline(ss, author, ',');
			        getline(ss, yearStr, ',');
			        getline(ss, borrowDate, ',');
			        getline(ss, returnDate, ',');
			        getline(ss, returnedStr, ',');
			
			        bool returned = (returnedStr == "1");
			        int y = extractYear(returnDate);
			        int m = extractMonth(returnDate);
			
			        if (returned && y == yearFilter && m == monthFilter) {
			            BorrowNode* newNode = new BorrowNode{
			                userId, bookId, title, author, borrowDate, returnDate,
			                stoi(yearStr), returned, nullptr
			            };
			            if (!head) {
			                head = tail = newNode;
			            } else {
			                tail->next = newNode;
			                tail = newNode;
			            }
			        }
			    }
			    file.close();
			
			    cout << "\nBorrowed Magazine Records - " << yearFilter << "/" << (monthFilter < 10 ? "0" : "") << monthFilter << "\n";
			    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
			    cout << left
			         << setw(12) << "User ID"
			         << setw(15) << "Magazine ID"
			         << setw(30) << "Title"
			         << setw(20) << "Author"
			         << setw(20) << "Borrow Date"
			         << setw(15) << "Return Date"
			         << setw(10) << "Returned"
			         << endl;
			    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
			
			    BorrowNode* current = head;
			    while (current) {
			        cout << left
			             << setw(12) << current->userId
			             << setw(15) << current->bookId
			             << setw(30) << current->title.substr(0, 28)
			             << setw(20) << current->author.substr(0, 18)
			             << setw(20) << current->borrowDate
			             << setw(15) << current->returnDate
			             << setw(10) << "Yes"
			             << endl;
			        current = current->next;
			    }
			    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
			
			        string filename = "borrowedMagazineHistoryReport_" + to_string(yearFilter) + "_" + (monthFilter < 10 ? "0" : "") + to_string(monthFilter) + ".txt";
			        ofstream report(filename);
			        if (report) {
			            report << "Borrowed Magazine History - " << yearFilter << "/" << (monthFilter < 10 ? "0" : "") << monthFilter << "\n";
			            report << "-------------------------------------------------------------------------------------------------------------------------\n";
			            report << left
			                   << setw(12) << "User ID"
			                   << setw(15) << "Magazine ID"
			                   << setw(30) << "Title"
			                   << setw(20) << "Author"
			                   << setw(20) << "Borrow Date"
			                   << setw(15) << "Return Date"
			                   << setw(10) << "Returned"
			                   << endl;
			            report << "-------------------------------------------------------------------------------------------------------------------------\n";
			            current = head;
			            while (current) {
			                report << left
			                       << setw(12) << current->userId
			                       << setw(15) << current->bookId
			                       << setw(30) << current->title.substr(0, 28)
			                       << setw(20) << current->author.substr(0, 18)
			                       << setw(20) << current->borrowDate
			                       << setw(15) << current->returnDate
			                       << setw(10) << "Yes"
			                       << endl;
			                current = current->next;
			            }
			            report << "-------------------------------------------------------------------------------------------------------------------------\n";
			            report.close();
			            cout << " Report saved as '" << filename << "'.\n";
			    }
			
			    while (head) {
			        BorrowNode* temp = head;
			        head = head->next;
			        delete temp;
			    }
			}
	    
	    cout << "\nPress Enter to return to menu...";
		cin.ignore(); 
		cin.get();    
	}

    void searchCustomers();
    void generateReport();
    
    void display() override 
	{
		cout << "=== Admin Information ===" << endl;
        cout << "Admin ID: " << getID() << endl;
        cout << "Admin Name: " << getName() << endl;
        cout << "Email: " << getEmail() << endl;
        cout << "Phone: " << getPhoneNum() << endl;
	};
    //friend void viewRBorrowedRecord(Admin);
};




class Customer : public Person {
private: 
	string keyword;  // for password reset

    struct CustomerNode {
        Customer* customer;
        CustomerNode* next;
        CustomerNode(Customer* c) : customer(c), next(nullptr) {}
    };

    CustomerNode* head;
    
public:
    Customer() { head = nullptr; }

    Customer(string id, string name, string password, string email, string phone_num, string keyword)
        : Person(id, name, password, email, phone_num), keyword(keyword) {}
    
    // Destructor for Customer class
    ~Customer() {
        CustomerNode* current = head;
        while (current != nullptr) {
            CustomerNode* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        head = nullptr;
    }
    
    string generateUniqueID() {
	    string id;
	    srand(time(0)); 
	    do {
	        id = to_string(rand() % 9000 + 1000); 
	    } while (isDuplicateCustomerID(id));
	    return id;
	}

	bool isDuplicateCustomerID(string id) 
	{
	    CustomerNode* temp = head;
	    while (temp != nullptr) {
	        if (temp->customer->getID() == id) 
			{
				return true;
			}
	        temp = temp->next;
	    }
	    return false;
	}

	bool isDuplicateEmail(string email) {
	    CustomerNode* temp = head;
	    while (temp != nullptr) {
	        if (temp->customer->getEmail() == email) 
			{
				return true;
			}
	        temp = temp->next;
	    }
	    return false;
	}
    
    void registerCustomer() 
	{
        bool success = true;
        string id, name, password, confirm_password, email, phone_num, keyword;
        
        loadCustomersFromFile();
        cout << "  ____________\n";
        cout << "  |  _       |\n";
        cout << "  | | |      |\n";
        cout << "  | | |___   |\n";
        cout << "  | |_____|  |\n";
        cout << "  |__________|\n\n";
        cout << "     JR Library\n";
        cout << "JR Library Management System\n";
        cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        cout << "                                                                     Register Account\n\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        
        id = generateUniqueID();
        if (id.empty()) {
            cerr << "Error: Failed to generate unique ID." << endl;
            success = false;
        }
        
        if (success) {
            do {
                cout << "Enter name: ";
                getline(cin, name);
            } while (name.empty());

            do {
                cout << "Enter password: ";
                getline(cin, password);
                cout << "Confirm password: ";
                getline(cin, confirm_password);
            } while (password != confirm_password || password.empty());

            do {
                cout << "Enter email: ";
                getline(cin, email);
                if (email.empty()) 
				{
					cout << "Email cannot be empty.\n";
				}
                else if (isDuplicateEmail(email)) 
				{
                    cout << "Email already exists. Please use another.\n";
                    email = "";
                }
            } while (email.empty());

            do {
                cout << "Enter phone number: ";
                getline(cin, phone_num);
            } while (phone_num.empty());

            do {
                cout << "Enter keyword (used for resetting password): ";
                getline(cin, keyword);
            } while (keyword.empty());

            if (isDuplicateEmail(email)) 
			{
                cout << "Email already exists. Registration failed.\n";
                success = false;
            }
        }
        
        if (success) {
            Customer* newCust = new (nothrow) Customer(id, name, password, email, phone_num, keyword);
            if (!newCust) 
			{
                cerr << "Error: Memory allocation failed for new customer." << endl;
                success = false;
            } else {
                CustomerNode* newNode = new (nothrow) CustomerNode(newCust);
                if (!newNode) {
                    cerr << "Error: Memory allocation failed for customer node." << endl;
                    delete newCust;
                    success = false;
                } else {
                    if (!head) 
					{
                        head = newNode;
                    } else 
					{
                        CustomerNode* temp = head;
                        while (temp->next) temp = temp->next;
                        temp->next = newNode;
                    }

                    if (!saveCustomersToFile()) 
					{
                        cerr << "Warning: Failed to save customer to file." << endl;
                    }
                    
                    cout << "Customer registered successfully!\n";
                }
            }
        }
        
        if (!success) 
		{
            cout << "Registration failed. Please try again." << endl;
        }
        
        cin.get();
    }

    bool customerLogin() {
        bool success = true;
        
        system("cls");
        cout << "  ____________\n";
        cout << "  |  _       |\n";
        cout << "  | | |      |\n";
        cout << "  | | |___   |\n";
        cout << "  | |_____|  |\n";
        cout << "  |__________|\n\n";
        cout << "     JR Library\n";
        cout << "JR Library Management System\n";
        cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        cout << "                                                                     Login Account\n\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        
        string email, password;
        cout << "Enter email: ";
        getline(cin, email);
        cout << "Enter password: ";
        getline(cin, password);

        if (email.empty() || password.empty()) {
            cout << "Email and password cannot be empty.\n";
            cin.get();
            return false;
        }

        CustomerNode* temp = head;
        while (temp) {
            if (temp->customer->getEmail() == email && temp->customer->getPassword() == password) {
                cout << "Login successful! Welcome, " << temp->customer->getName() << ".\n";
                cin.get();
                return true;
            }
            temp = temp->next;
        }
        
        cout << "Invalid email or password.\n";
        cin.get();
        return false;
    }

    void resetPassword() {
        bool success = true;
        string email, inputKeyword, newPassword;
        
        system("cls");
        loadCustomersFromFile();
        
        cout << "  ____________\n";
        cout << "  |  _       |\n";
        cout << "  | | |      |\n";
        cout << "  | | |___   |\n";
        cout << "  | |_____|  |\n";
        cout << "  |__________|\n\n";
        cout << "     JR Library\n";
        cout << "JR Library Management System\n";
        cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        cout << "                                                                     Reset Password\n\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        
        cout << "Enter your registered email: ";
        getline(cin, email);

        if (email.empty()) 
		{
            cout << "Email cannot be empty.\n";
            cin.get();
            return;
        }
        
        CustomerNode* temp = head;
        bool foundEmail = false;
        
        while (temp) {
            if (temp->customer->getEmail() == email) {
                foundEmail = true;
                cout << "Enter your keyword: ";
                getline(cin, inputKeyword);
                if (temp->customer->keyword == inputKeyword) {
                    cout << "Enter new password: ";
                    getline(cin, newPassword);
                    if (newPassword.empty()) 
					{
                        cout << "Password cannot be empty.\n";
                    } 
					else 
					{
                        temp->customer->setPassword(newPassword);
                        if (saveCustomersToFile()) {
                            cout << "Password reset successful.\n";
                        } else {
                            cerr << "Warning: Failed to save updated password to file." << endl;
                            cout << "Password was reset but there was an error saving to file." << endl;
                        }
                    }
                } else {
                    cout << "Keyword incorrect.\n";
                }
                break;
            }
            temp = temp->next;
        }
        
        if (!foundEmail) {
            cout << "Email not found.\n";
        }
        
        cin.get();
    }

    bool isDuplicateCustomerEmail(string email) {
        CustomerNode* temp = head;
        while (temp) {
            if (temp->customer->getEmail() == email)
            {
            	return true;
			}
                
            temp = temp->next;
        }
        return false;
    }
    
    bool saveCustomersToFile() {
        ofstream outFile("customer.txt");
        if (!outFile.is_open()) {
            cerr << "Error: Unable to open customer.txt for writing" << endl;
            return false;
        }
        
        CustomerNode* temp = head;
        while (temp) {
            outFile << temp->customer->getID() << ","
                    << temp->customer->getName() << ","
                    << temp->customer->getPassword() << ","
                    << temp->customer->getEmail() << ","
                    << temp->customer->getPhoneNum() << ","
                    << temp->customer->keyword << "\n";
            temp = temp->next;
        }
        outFile.close();
        cout << "Customer data saved to customer.txt\n";
        return true;
    }

    void loadCustomersFromFile() {
        CustomerNode* current = head;
        while (current) {
            CustomerNode* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        head = nullptr;

        ifstream inFile("customer.txt");
        if (!inFile) {
            cout << "customer.txt not found. Load failed.\n";
            return;
        }

        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string id, name, password, email, phone, keyword;
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, password, ',');
            getline(ss, email, ',');
            getline(ss, phone, ',');
            getline(ss, keyword);

            Customer* c = new Customer(id, name, password, email, phone, keyword);
            CustomerNode* newNode = new CustomerNode(c);

            if (!head) head = newNode;
            else {
                CustomerNode* temp = head;
                while (temp->next) temp = temp->next;
                temp->next = newNode;
            }
        }

        inFile.close();
    }
    
    friend void viewCustomers(Customer& custSystem);
    
    void searchBook();
    void borrowBook();
    void returnBook();
    void viewBorrowed();
    void display() override{
    	cout << "=== User Information ===" << endl;
        cout << "User ID: " << getID() << endl;
        cout << "Name: " << getName() << endl;
        cout << "Email: " << getEmail() << endl;
        cout << "Phone: " << getPhoneNum() << endl;
	};
    friend void displayUserInfo(Customer); // Friend function
    friend void viewBorrowHistory(const Customer);
};


class Library : public BookRecord {
private:
    // Review data structure implementation
    ReviewNode* reviewHead = nullptr;
    
public:
    Library() : BookRecord() {}
    
    ~Library() {
        // Clean up reviews
        ReviewNode* current = reviewHead;
        while (current != nullptr) {
            ReviewNode* next = current->next;
            delete current;
            current = next;
        }
    }
    
    // Bubble sort implementation for sorting books by title
    void sortBooksByTitle() {
        if (head == nullptr || head->next == nullptr) {
            cout << "No books or only one book in the system. Nothing to sort." << endl;
            return;
        }
        
        bool success = true;
        bool swapped;
        BookNode* ptr1;
        BookNode* lptr = nullptr;
        
        do {
            swapped = false;
            ptr1 = head;
            
            while (ptr1->next != lptr) {
                if (ptr1->title > ptr1->next->title) {
                    // Swap book data
                    string tempId = ptr1->id;
                    string tempTitle = ptr1->title;
                    string tempAuthor = ptr1->author;
                    int tempYear = ptr1->year;
                    bool tempAvailable = ptr1->available;
                    
                    ptr1->id = ptr1->next->id;
                    ptr1->title = ptr1->next->title;
                    ptr1->author = ptr1->next->author;
                    ptr1->year = ptr1->next->year;
                    ptr1->available = ptr1->next->available;
                    
                    ptr1->next->id = tempId;
                    ptr1->next->title = tempTitle;
                    ptr1->next->author = tempAuthor;
                    ptr1->next->year = tempYear;
                    ptr1->next->available = tempAvailable;
                    
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
        
        if (success) {
            cout << "Books sorted by title successfully!" << endl;
        } else {
            cerr << "Error occurred during sorting." << endl;
        }
    }
    
    // General search function that displays the search UI
    void searchBook() {
        cout << "  ____________\n";
        cout << "  |  _       |\n";
        cout << "  | | |      |\n";
        cout << "  | | |___   |\n";
        cout << "  | |_____|  |\n";
        cout << "  |__________|\n\n";
        cout << "     JR Library\n";
        cout << "JR Library Management System\n";
        cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        cout << "                                                                       Search Books\n\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        
        if (head == nullptr) {
            cout << "No books in the system." << endl;
            return;
        }
        
        int searchChoice;
        cout << "Search books by:\n";
        cout << "1. Book ID\n";
        cout << "2. Title\n";
        cout << "3. Author\n";
        cout << "4. Year\n";
        cout << "Enter your choice: ";
        
        if (!(cin >> searchChoice)) {
            cerr << "Error: Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
        
        cin.ignore();
        
        switch (searchChoice) {
            case 1: {
                int id;
                cout << "Enter book ID: ";
                if (!(cin >> id)) {
                    cerr << "Error: Invalid ID input." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    return;
                }
                BookNode* result = binarySearchById(id);
                if (result != nullptr) {
                    cout << "\nBook found!\n";
                    cout << "ID: " << result->id << "\n";
                    cout << "Title: " << result->title << "\n";
                    cout << "Author: " << result->author << "\n";
                    cout << "Year: " << result->year << "\n";
                    cout << "Status: " << (result->available ? "Available" : "Borrowed") << "\n";
                } else {
                    cout << "Book not found with that ID.\n";
                }
                break;
            }
            case 2: {
                string title;
                cout << "Enter book title: ";
                getline(cin, title);
                searchBook(title);
                break;
            }
            case 3: {
                string author;
                cout << "Enter author name: ";
                getline(cin, author);
                searchBookByAuthor(author);
                break;
            }
            case 4: {
                int year;
                cout << "Enter publication year: ";
                if (!(cin >> year)) {
                    cerr << "Error: Invalid year input." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    return;
                }
                searchBook(year);
                break;
            }
            default:
                cout << "Invalid option.\n";
        }
    }
    
    // Search by title
    void searchBook(string title) {
        bool success = true;
        bool found = false;
        BookNode* temp = head;
        
        cout << "\n------------------------------------------------------------------------------------------------------------------\n";
        cout << "Search results for title: " << title << "\n";
        cout << "------------------------------------------------------------------------------------------------------------------\n";
        
        while (temp != nullptr && success) {
            // Check for any potential errors with string operations
            if (title.empty()) {
                cerr << "Error: Empty search string provided" << endl;
                success = false;
                break;
            }
            
            size_t pos = string::npos;
            if (success) {
                // Safely perform the string find operation
                pos = temp->title.find(title);
            }
            
            if (pos != string::npos) {
                cout << "ID: " << temp->id << "\n";
                cout << "Title: " << temp->title << "\n";
                cout << "Author: " << temp->author << "\n";
                cout << "Year: " << temp->year << "\n";
                cout << "Status: " << (temp->available ? "Available" : "Borrowed") << "\n";
                cout << "------------------------------------------------------------------------------------------------------------------\n";
                found = true;
            }
            temp = temp->next;
        }
        
        if (!success) {
            cerr << "Error during title search" << endl;
        } else if (!found) {
            cout << "No books found with title containing: " << title << "\n";
        }
    }
    
    // Search by author
    void searchBookByAuthor(string author) {
        bool success = true;
        bool found = false;
        BookNode* temp = head;
        
        cout << "\n------------------------------------------------------------------------------------------------------------------\n";
        cout << "Search results for author: " << author << "\n";
        cout << "------------------------------------------------------------------------------------------------------------------\n";
        
        while (temp != nullptr && success) {
            // Check for any potential errors with string operations
            if (author.empty()) {
                cerr << "Error: Empty author search string provided" << endl;
                success = false;
                break;
            }
            
            size_t pos = string::npos;
            if (success) {
                // Safely perform the string find operation
                pos = temp->author.find(author);
            }
            
            if (pos != string::npos) {
                cout << "ID: " << temp->id << "\n";
                cout << "Title: " << temp->title << "\n";
                cout << "Author: " << temp->author << "\n";
                cout << "Year: " << temp->year << "\n";
                cout << "Status: " << (temp->available ? "Available" : "Borrowed") << "\n";
                cout << "------------------------------------------------------------------------------------------------------------------\n";
                found = true;
            }
            temp = temp->next;
        }
        
        if (!success) {
            cerr << "Error during author search" << endl;
        } else if (!found) {
            cout << "No books found with author containing: " << author << "\n";
        }
    }
    
    // Search by year
    void searchBook(int year) {
        bool success = true;
        bool found = false;
        BookNode* temp = head;
        
        cout << "\n------------------------------------------------------------------------------------------------------------------\n";
        cout << "Search results for year: " << year << "\n";
        cout << "------------------------------------------------------------------------------------------------------------------\n";
        
        if (year <= 0) {
            cerr << "Error: Invalid year value" << endl;
            success = false;
        }
        
        while (temp != nullptr && success) {
            if (temp->year == year) {
                cout << "ID: " << temp->id << "\n";
                cout << "Title: " << temp->title << "\n";
                cout << "Author: " << temp->author << "\n";
                cout << "Year: " << temp->year << "\n";
                cout << "Status: " << (temp->available ? "Available" : "Borrowed") << "\n";
                cout << "------------------------------------------------------------------------------------------------------------------\n";
                found = true;
            }
            temp = temp->next;
        }
        
        if (!success) {
            cerr << "Error during year search" << endl;
        } else if (!found) {
            cout << "No books found from year: " << year << "\n";
        }
    }
    
    // Binary search implementation for searching by book ID
    BookNode* binarySearchById(int searchId) {
        // Count total books for array size
        int bookCount = 0;
        BookNode* temp = head;
        while (temp != nullptr) {
            bookCount++;
            temp = temp->next;
        }
        
        if (bookCount == 0) {
            return nullptr;
        }
        
        // Create arrays to store book data for binary search
        int* bookIds = nullptr;
        BookNode** bookNodes = nullptr;
        
        bool success = true;
        BookNode* result = nullptr;
        
        // Allocate memory and check for allocation errors
        bookIds = new (nothrow) int[bookCount];
        bookNodes = new (nothrow) BookNode*[bookCount];
        
        if (!bookIds || !bookNodes) {
            cerr << "Error: Memory allocation failed during search" << endl;
            success = false;
        }
        
        if (success) {
                // Fill arrays with data from linked list
        temp = head;
        for (int i = 0; i < bookCount; i++) {
            // Convert string ID to int, handle conversion errors without try-catch
            bool conversionSuccess = true;
            string idStr = temp->id;
            bookIds[i] = 0; // Default value
            
            // Manual string to int conversion with error checking
            for (char c : idStr) {
                if (c >= '0' && c <= '9') {
                    bookIds[i] = bookIds[i] * 10 + (c - '0');
                } else {
                    conversionSuccess = false;
                    break;
                }
            }
            
            // If conversion failed, keep the default value
            if (!conversionSuccess) {
                cerr << "Warning: Non-numeric ID found: " << idStr << ". Using default value 0." << endl;
            }
            
            bookNodes[i] = temp;
            temp = temp->next;
        }
        
        // Sort arrays by ID using bubble sort (prerequisite for binary search)
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = 0; j < bookCount - i - 1; j++) {
                if (bookIds[j] > bookIds[j + 1]) {
                    // Swap IDs
                        int tempId = bookIds[j];
                    bookIds[j] = bookIds[j + 1];
                    bookIds[j + 1] = tempId;
                    
                    // Swap node pointers
                        BookNode* tempNode = bookNodes[j];
                    bookNodes[j] = bookNodes[j + 1];
                    bookNodes[j + 1] = tempNode;
                }
            }
        }
        
        // Perform binary search
        int left = 0;
        int right = bookCount - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
                // Check if book ID is at mid
            if (bookIds[mid] == searchId) {
                    result = bookNodes[mid];
                break;
            }
            
            // If ID is greater, ignore left half
            if (bookIds[mid] < searchId) {
                left = mid + 1;
            }
            // If ID is smaller, ignore right half
            else {
                right = mid - 1;
            }
        }
        }
        
        // Free allocated memory
        if (bookIds) {
			delete[] bookIds;
		}
        if (bookNodes) {
			delete[] bookNodes;
		}
        
        return result;
    }
    
    // Add a review for a book
    void addReview(int bookId, string reviewerName, string comment, int rating) {
        bool success = true;
        
        if (rating < 1 || rating > 5) {
            cout << "Rating must be between 1 and 5." << endl;
            return;
        }
        
        // Check for valid inputs
        if (bookId <= 0 || reviewerName.empty() || comment.empty()) {
            cerr << "Error: Invalid review data provided." << endl;
            success = false;
        }
        
        ReviewNode* newReview = nullptr;
        if (success) {
            // Allocate memory for new review
            newReview = new (nothrow) ReviewNode{bookId, reviewerName, comment, rating, nullptr};
            if (!newReview) {
                cerr << "Error: Memory allocation failed for review" << endl;
                success = false;
            }
        }
        
        if (success) {
            // Add to linked list
            if (reviewHead == nullptr) {
                reviewHead = newReview;
            } else {
                ReviewNode* temp = reviewHead;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newReview;
            }
            
            // Save reviews to file
            ofstream outFile("review.txt", ios::app);
            if (outFile.is_open()) {
                outFile << bookId << "," << reviewerName << "," << comment << "," << rating << endl;
                outFile.close();
                cout << "Review added and saved successfully!" << endl;
            } else {
                cerr << "Error: Unable to open review.txt for writing" << endl;
                success = false;
            }
        }
        
        if (!success) {
            if (newReview) {
                delete newReview; // Clean up if review was allocated but couldn't be saved
            }
            cout << "Failed to add review. Please try again later." << endl;
        }
    }
    
        // Display reviews for a specific book
    void displayReviews(int bookId) {
        bool success = true;
        
        ifstream inFile("review.txt");
        if (!inFile.is_open()) {
            cout << "No reviews found in the system." << endl;
            return;
        }
        
        cout << "\n------------------------------------------------------------------------------------------------------------------\n";
        cout << "Reviews for Book ID: " << bookId << "\n";
        cout << "------------------------------------------------------------------------------------------------------------------\n";
        
        string line;
        bool found = false;
        
        while (getline(inFile, line) && success) {
            stringstream ss(line);
            string idStr, name, comment, ratingStr;
            
            getline(ss, idStr, ',');
            getline(ss, name, ',');
            getline(ss, comment, ',');
            getline(ss, ratingStr);
            
            // Safe string to int conversion for id
            int id = 0;
            bool idValid = true;
            for (char c : idStr) {
                if (c >= '0' && c <= '9') {
                    id = id * 10 + (c - '0');
                } else {
                    idValid = false;
                    break;
                }
            }
            
            if (!idValid) {
                cerr << "Warning: Invalid ID format in review: " << idStr << endl;
                continue;
            }
            
            // Safe string to int conversion for rating
            int rating = 0;
            bool ratingValid = true;
            for (char c : ratingStr) {
                if (c >= '0' && c <= '9') {
                    rating = rating * 10 + (c - '0');
                } else {
                    ratingValid = false;
                    break;
                }
            }
            
            if (!ratingValid || rating < 1 || rating > 5) {
                cerr << "Warning: Invalid rating format in review: " << ratingStr << endl;
                rating = 1; // Default to minimum rating
            }
            
            if (id == bookId) {
                cout << "Reviewer: " << name << "\n";
                cout << "Rating: ";
                for (int i = 0; i < rating; i++) cout << "★";
                for (int i = rating; i < 5; i++) cout << "☆";
                cout << " (" << rating << "/5)\n";
                cout << "Comment: " << comment << "\n";
                cout << "------------------------------------------------------------------------------------------------------------------\n";
                found = true;
            }
        }
        
        inFile.close();
        
        if (!success) {
            cerr << "Error occurred while displaying reviews" << endl;
        } else if (!found) {
            cout << "No reviews found for this book." << endl;
        }
    }
    
    // Friend function implementation
    friend void searchHelper(Library& lib, string keyword) {
        cout << "Using search helper to find books with keyword: " << keyword << endl;
        
        bool success = true;
        bool found = false;
        BookNode* temp = lib.head;
        
        if (keyword.empty()) {
            cerr << "Error: Empty keyword provided" << endl;
            return;
        }
        
        cout << "\n------------------------------------------------------------------------------------------------------------------\n";
        cout << "Search results for keyword: " << keyword << "\n";
        cout << "------------------------------------------------------------------------------------------------------------------\n";
        
        while (temp != nullptr && success) {
            // Check for title match
            bool titleMatch = false;
            if (success && !temp->title.empty()) {
                titleMatch = (temp->title.find(keyword) != string::npos);
            }
            
            // Check for author match
            bool authorMatch = false;
            if (success && !temp->author.empty()) {
                authorMatch = (temp->author.find(keyword) != string::npos);
            }
            
            // Check for year match
            bool yearMatch = false;
            if (success) {
                string yearStr = to_string(temp->year);
                yearMatch = (yearStr.find(keyword) != string::npos);
            }
            
            if (titleMatch || authorMatch || yearMatch) {
                cout << "ID: " << temp->id << "\n";
                cout << "Title: " << temp->title << "\n";
                cout << "Author: " << temp->author << "\n";
                cout << "Year: " << temp->year << "\n";
                cout << "Status: " << (temp->available ? "Available" : "Borrowed") << "\n";
                cout << "------------------------------------------------------------------------------------------------------------------\n";
                found = true;
            }
            
            temp = temp->next;
        }
        
        if (!success) {
            cerr << "Error occurred during search" << endl;
        } else if (!found) {
            cout << "No books found matching the keyword: " << keyword << "\n";
        }
    }

    // Add these functions to the Library class
    // Bubble sort for magazines - manual implementation without STL
    void sortMagazinesByTitle() {
        if (head == nullptr || head->next == nullptr) {
            cout << "No magazines or only one magazine in the system. Nothing to sort." << endl;
            return;
        }
        
        cout << "  ____________\n";
        cout << "  |  _       |\n";
        cout << "  | | |      |\n";
        cout << "  | | |___   |\n";
        cout << "  | |_____|  |\n";
        cout << "  |__________|\n\n";
        cout << "     JR Library\n";
        cout << "JR Library Management System\n";
        cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        cout << "                                                                    Sort Magazines by Title\n\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        loadBooksFromFile("magazine.txt");
        bool success = true;
        bool swapped;
        BookNode* ptr1;
        BookNode* lptr = nullptr;
        
        // Bubble sort implementation
        do {
            swapped = false;
            ptr1 = head;
            
            while (ptr1->next != lptr) {
                if (ptr1->title > ptr1->next->title) {
                    // Swap magazine data
                    string tempId = ptr1->id;
                    string tempTitle = ptr1->title;
                    string tempAuthor = ptr1->author;
                    int tempYear = ptr1->year;
                    bool tempAvailable = ptr1->available;
                    
                    ptr1->id = ptr1->next->id;
                    ptr1->title = ptr1->next->title;
                    ptr1->author = ptr1->next->author;
                    ptr1->year = ptr1->next->year;
                    ptr1->available = ptr1->next->available;
                    
                    ptr1->next->id = tempId;
                    ptr1->next->title = tempTitle;
                    ptr1->next->author = tempAuthor;
                    ptr1->next->year = tempYear;
                    ptr1->next->available = tempAvailable;
                    
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
        
        saveBooksToFile("magazine.txt");
        
        if (success) {
            cout << "Magazines sorted by title successfully!" << endl;
            
            cout << "\n------------------------------------------------------------------------------------------------------------------\n";
            cout << "ID\t\tTitle\t\t\t\tAuthor\t\t\t\tYear\t\tStatus\n";
            cout << "------------------------------------------------------------------------------------------------------------------\n";
            
            BookNode* temp = head;
            while (temp != nullptr) {
                cout << temp->id << "\t\t"
                     << temp->title << "\t\t\t"
                     << temp->author << "\t\t\t"
                     << temp->year << "\t\t";
                     
                if (temp->available) {
                    cout << CYAN << "AVAILABLE" << RESET;
                } else {
                    cout << RED << "BORROWED" << RESET;
                }
                cout << endl << endl;
                
                temp = temp->next;
            }
            cout << "------------------------------------------------------------------------------------------------------------------\n";
        } else {
            cerr << "Error occurred during sorting." << endl;
        }
        
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }

    // Binary search for magazines by ID
    void searchMagazineById() {
        cout << "  ____________\n";
        cout << "  |  _       |\n";
        cout << "  | | |      |\n";
        cout << "  | | |___   |\n";
        cout << "  | |_____|  |\n";
        cout << "  |__________|\n\n";
        cout << "     JR Library\n";
        cout << "JR Library Management System\n";
        cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        cout << "                                                                   Search Magazine by ID\n\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        
        loadBooksFromFile("magazine.txt");
        
        if (head == nullptr) {
            cout << "No magazines in the system." << endl;
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            return;
        }
        
        string searchId;
        cout << "Enter magazine ID to search: ";
        getline(cin, searchId);
        
        int magazineCount = 0;
        BookNode* temp = head;
        while (temp != nullptr) {
            magazineCount++;
            temp = temp->next;
        }
        
        // Create arrays to store magazine data for binary search
        string* magazineIds = new (nothrow) string[magazineCount];
        BookNode** magazineNodes = new (nothrow) BookNode*[magazineCount];
        
        if (!magazineIds || !magazineNodes) {
            cerr << "Error: Memory allocation failed." << endl;
            
            if (magazineIds) {
				delete[] magazineIds;
			}
            if (magazineNodes) {
				delete[] magazineNodes;
			}
            
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            return;
        }
        
        temp = head;
        for (int i = 0; i < magazineCount; i++) {
            magazineIds[i] = temp->id;
            magazineNodes[i] = temp;
            temp = temp->next;
        }
        
        // Sort arrays by ID using bubble sort 
        for (int i = 0; i < magazineCount - 1; i++) {
            for (int j = 0; j < magazineCount - i - 1; j++) {
                if (magazineIds[j] > magazineIds[j + 1]) {
                    // Swap IDs8
                    string tempId = magazineIds[j];
                    magazineIds[j] = magazineIds[j + 1];
                    magazineIds[j + 1] = tempId;
                    
                    // Swap node pointers
                    BookNode* tempNode = magazineNodes[j];
                    magazineNodes[j] = magazineNodes[j + 1];
                    magazineNodes[j + 1] = tempNode;
                }
            }
        }
        
        // Perform binary search 
        int left = 0;
        int right = magazineCount - 1;
        bool found = false;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Check if magazine ID is at mid
            if (magazineIds[mid] == searchId) {
                found = true;
                
                cout << "\n------------------------------------------------------------------------------------------------------------------\n";
                cout << "Magazine found!\n";
                cout << "------------------------------------------------------------------------------------------------------------------\n";
                cout << "ID\t\tTitle\t\t\t\tAuthor\t\t\t\tYear\t\tStatus\n";
                cout << "------------------------------------------------------------------------------------------------------------------\n";
                
                cout << magazineNodes[mid]->id << "\t\t"
                     << magazineNodes[mid]->title << "\t\t\t"
                     << magazineNodes[mid]->author << "\t\t\t"
                     << magazineNodes[mid]->year << "\t\t";
                     
                if (magazineNodes[mid]->available) {
                    cout << CYAN << "AVAILABLE" << RESET;
                } else {
                    cout << RED << "BORROWED" << RESET;
                }
                cout << endl;
                
                cout << "------------------------------------------------------------------------------------------------------------------\n";
                break;
            }
            
            // If ID is greater, ignore left half
            if (magazineIds[mid] < searchId) {
                left = mid + 1;
            }
            // If ID is smaller, ignore right half
            else {
                right = mid - 1;
            }
        }
        
        if (!found) {
            cout << "\nMagazine with ID '" << searchId << "' not found in the system." << endl;
        }
        
        // Free allocated memory
        delete[] magazineIds;
        delete[] magazineNodes;
        
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }

    void bubbleSortMagazines() {
        cout << "  ____________\n";
        cout << "  |  _       |\n";
        cout << "  | | |      |\n";
        cout << "  | | |___   |\n";
        cout << "  | |_____|  |\n";
        cout << "  |__________|\n\n";
        cout << "     JR Library\n";
        cout << "JR Library Management System\n";
        cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        cout << "                                                                    Bubble Sort Magazines\n\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        
        loadBooksFromFile("magazine.txt");
        
        if (head == nullptr || head->next == nullptr) {
            cout << "No magazines or only one magazine in the system. Nothing to sort." << endl;
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            return;
        }
        
        cout << "Sorting helps you organize magazines in alphabetical order by title.\n";
        cout << "This makes finding specific magazines easier for library staff and users.\n\n";
        
        cout << "Magazines before sorting:\n";
        cout << "------------------------------------------------------------------------------------------------------------------\n";
        cout << "ID\t\tTitle\t\t\t\tAuthor\t\t\t\tYear\t\tStatus\n";
        cout << "------------------------------------------------------------------------------------------------------------------\n";
        
        BookNode* temp = head;
        while (temp != nullptr) {
            cout << temp->id << "\t\t"
                 << temp->title << "\t\t\t"
                 << temp->author << "\t\t\t"
                 << temp->year << "\t\t";
                 
            if (temp->available) {
                cout << CYAN << "AVAILABLE" << RESET;
            } else {
                cout << RED << "BORROWED" << RESET;
            }
            cout << endl << endl;
            
            temp = temp->next;
        }
        
        cout << "\nSorting magazines using Bubble Sort algorithm...\n";
        cout << "(Comparing adjacent magazine titles and swapping when needed)\n\n";
        
        bool swapped;
        BookNode* ptr1;
        BookNode* lptr = nullptr;
        
        do {
            swapped = false;
            ptr1 = head;
            
            while (ptr1->next != lptr) {
                if (ptr1->title > ptr1->next->title) {
                    // Swap magazine data
                    string tempId = ptr1->id;
                    string tempTitle = ptr1->title;
                    string tempAuthor = ptr1->author;
                    int tempYear = ptr1->year;
                    bool tempAvailable = ptr1->available;
                    
                    ptr1->id = ptr1->next->id;
                    ptr1->title = ptr1->next->title;
                    ptr1->author = ptr1->next->author;
                    ptr1->year = ptr1->next->year;
                    ptr1->available = ptr1->next->available;
                    
                    ptr1->next->id = tempId;
                    ptr1->next->title = tempTitle;
                    ptr1->next->author = tempAuthor;
                    ptr1->next->year = tempYear;
                    ptr1->next->available = tempAvailable;
                    
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
        
        cout << "Magazines after sorting (by title):\n";
        cout << "------------------------------------------------------------------------------------------------------------------\n";
        cout << "ID\t\tTitle\t\t\t\tAuthor\t\t\t\tYear\t\tStatus\n";
        cout << "------------------------------------------------------------------------------------------------------------------\n";
        
        temp = head;
        while (temp != nullptr) {
            cout << temp->id << "\t\t"
                 << temp->title << "\t\t\t"
                 << temp->author << "\t\t\t"
                 << temp->year << "\t\t";
                 
            if (temp->available) {
                cout << CYAN << "AVAILABLE" << RESET;
            } else {
                cout << RED << "BORROWED" << RESET;
            }
            cout << endl << endl;
            
            temp = temp->next;
        }
        
        cout << "✓ Magazines sorted by title successfully! (Results not saved to file)" << endl;
        cout << "  This view is temporary and will not affect the stored data." << endl;
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
    
    void binarySearchMagazine() {
        cout << "  ____________\n";
        cout << "  |  _       |\n";
        cout << "  | | |      |\n";
        cout << "  | | |___   |\n";
        cout << "  | |_____|  |\n";
        cout << "  |__________|\n\n";
        cout << "     JR Library\n";
        cout << "JR Library Management System\n";
        cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        cout << "                                                                 Binary Search Magazines\n\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        
        loadBooksFromFile("magazine.txt");
        
        if (head == nullptr) {
            cout << "No magazines in the system." << endl;
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            return;
        }
        
        cout << "Binary search is an efficient algorithm that finds items quickly in sorted lists.\n";
        cout << "It works by repeatedly dividing the search area in half until the item is found.\n\n";
        
        string searchId;
        cout << "Enter magazine ID to search: ";
        getline(cin, searchId);
        
        int magazineCount = 0;
        BookNode* temp = head;
        while (temp != nullptr) {
            magazineCount++;
            temp = temp->next;
        }
        
        string* magazineIds = new (nothrow) string[magazineCount];
        BookNode** magazineNodes = new (nothrow) BookNode*[magazineCount];
        
        if (!magazineIds) {
            cerr << "Error: Memory allocation failed." << endl;
            
            if (magazineIds) {
                delete[] magazineIds;
            }
            if (magazineNodes) {
                delete[] magazineNodes;
            }
            
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            return;
        }
        
        temp = head;
        for (int i = 0; i < magazineCount; i++) {
            magazineIds[i] = temp->id;
            magazineNodes[i] = temp;
            temp = temp->next;
        }
        
        cout << "\nPreparing data for binary search...\n";
        cout << "Step 1: First sorting magazines by ID (binary search requires sorted data)\n";
        
        for (int i = 0; i < magazineCount - 1; i++) {
            for (int j = 0; j < magazineCount - i - 1; j++) {
                if (magazineIds[j] > magazineIds[j + 1]) {
                    // Swap IDs
                    string tempId = magazineIds[j];
                    magazineIds[j] = magazineIds[j + 1];
                    magazineIds[j + 1] = tempId;
                    
                    // Swap node pointers
                    BookNode* tempNode = magazineNodes[j];
                    magazineNodes[j] = magazineNodes[j + 1];
                    magazineNodes[j + 1] = tempNode;
                }
            }
        }
        
        cout << "\nStep 2: Sorted magazine IDs for binary search:\n";
        cout << "[ ";
        for (int i = 0; i < magazineCount; i++) {
            cout << magazineIds[i];
            if (i < magazineCount - 1) cout << ", ";
        }
        cout << " ]\n\n";
        
        cout << "Step 3: Performing binary search for ID: " << searchId << "\n";
        cout << "------------------------------------------------------------------------------------------------------------------\n";
        
        int left = 0;
        int right = magazineCount - 1;
        bool found = false;
        int steps = 0;  // Track number of steps
        
        while (left <= right) {
            steps++;
            int mid = left + (right - left) / 2;
            
            cout << "Step " << steps << ": Checking middle position at index " << mid << " (ID: " << magazineIds[mid] << ")\n";
            
            // Check if magazine ID is at mid
            if (magazineIds[mid] == searchId) {
                found = true;
                
                cout << "\n🔍 Found magazine after " << steps << " steps!\n";
                cout << "------------------------------------------------------------------------------------------------------------------\n";
                cout << "ID\t\tTitle\t\t\t\tAuthor\t\t\t\tYear\t\tStatus\n";
                cout << "------------------------------------------------------------------------------------------------------------------\n";
                
                cout << magazineNodes[mid]->id << "\t\t"
                     << magazineNodes[mid]->title << "\t\t\t"
                     << magazineNodes[mid]->author << "\t\t\t"
                     << magazineNodes[mid]->year << "\t\t";
                     
                if (magazineNodes[mid]->available) {
                    cout << CYAN << "AVAILABLE" << RESET;
                } else {
                    cout << RED << "BORROWED" << RESET;
                }
                cout << endl;
                
                cout << "------------------------------------------------------------------------------------------------------------------\n";
                break;
            }
            
            // If ID is greater, ignore left half
            if (magazineIds[mid] < searchId) {
                cout << "ID " << searchId << " is greater than " << magazineIds[mid] << ". Moving to right half.\n";
                left = mid + 1;
            }
            // If ID is smaller, ignore right half
            else {
                cout << "ID " << searchId << " is less than " << magazineIds[mid] << ". Moving to left half.\n";
                right = mid - 1;
            }
        }
        
        if (!found) {
            cout << "\n❌ Magazine with ID '" << searchId << "' not found after " << steps << " steps.\n";
        }
        
        // Free allocated memory
        delete[] magazineIds;
        delete[] magazineNodes;
        
        cout << "\nBinary search completed. No changes saved to file.\n";
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }
};

// =============== Function Prototypes =============

void loginMenu();
void adminMenu(Admin* admin)
{
	BookRecord bookRecords;
	Customer customer;
	Library library;  // Create a Library instance to use the sorting and searching functions
	int choice;
	
	customer.loadCustomersFromFile();
	do
	{
		system("cls");
		cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                                                                       Admin Dashboard\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                              |------------------------------------------------------------------------------------------------------------|" << endl;
	    cout << "                              |                                               MENU                                                         |" << endl;
	    cout << "                              |------------------------------------------------------------------------------------------------------------|" << endl;
	    cout << "                              |                                        1.  Add Admin                                                       |" << endl;
	    cout << "                              |                                        2.  Edit Admin                                                      |" << endl;
	    cout << "                              |                                        3.  Delete Admin                                                    |" << endl;
	    cout << "                              |                                        4.  Display Admin                                                   |" << endl;
	    cout << "                              |                                        5.  Add New Books                                                   |" << endl;
	    cout << "                              |                                        6.  Edit Books                                                      |" << endl;
	    cout << "                              |                                        7.  Delete Books                                                    |" << endl;
	    cout << "                              |                                        8.  View All Book                                                   |" << endl;
	    cout << "                              |                                        9.  View Available Book                                             |" << endl;
	    cout << "                              |                                        10. View Borrowed Book                                              |" << endl;
	    cout << "                              |                                        11. Add Magazine                                                    |" << endl;
	    cout << "                              |                                        12. Edit Magazine                                                   |" << endl;
	    cout << "                              |                                        13. Delete Magazine                                                 |" << endl;
	    cout << "                              |                                        14. View All Magazine                                               |" << endl;
	    cout << "                              |                                        15. View Available Magazine                                         |" << endl;
	    cout << "                              |                                        16. View Borrowed Magazine                                          |" << endl;
	    cout << "                              |                                        17. View All User                                                   |" << endl;
	    cout << "                              |                                        18. View Borrowed Book                                              |" << endl;
	    cout << "                              |                                        19. Books Borrowed Record                                           |" << endl;
	    cout << "                              |                                        20. View Borrowed Magazine                                          |" << endl;
	    cout << "                              |                                        21. Magazine Borrowed Record                                        |" << endl;
	    cout << "                              |                                        22. Sort Books                                                      |" << endl;
	    cout << "                              |                                        23. Search Books                                                    |" << endl;
	    cout << "                              |                                        24. Sort Magazine                                                   |" << endl;
	    cout << "                              |                                        25. Search Magazine                                                 |" << endl;
	    cout << "                              |                                        26. Bubble Sort Magazines (No Save)                 |" << endl;
	    cout << "                              |                                        27. Binary Search Magazines (No Save)               |" << endl;
	    cout << "                              |                                        28. Logout                                          |" << endl;
	    cout << "                              |------------------------------------------------------------------------------------------------------------|" << endl;
		cout<< "Enter Your Choice: ";
		cin>>choice;
		cin.ignore();
	
		switch(choice)
		{
			case 1:
				system("cls");
				admin->addAdmin(); 
				admin->saveAdminToFile();
				admin->loadAdminsFromFile();
				cout<<"Press Enter To Continue...";
				cin.get();
				break;
			case 2:
				system("cls");
				admin->editAdmin();
				admin->saveAdminToFile(); 
				admin->loadAdminsFromFile();
				cout<<"Press Enter To Continue...";
				cin.get();
				break;
			case 3:
				system("cls");
				admin->removeAdmin();
				admin->saveAdminToFile();
				admin->loadAdminsFromFile();
				cout<<"Press Enter To Continue...";
				cin.get();
				break;
			case 4:
				system("cls");
				admin->displayAdmin();
				cout<<"Press Enter To Continue...";
				cin.get();
				break;
			case 5:
				system("cls");
				bookRecords.loadBooksFromFile("books.txt");
				admin->addBook(bookRecords);
				cout<< "Press Enter To Continue...";
				cin.get();
				break;
			case 6:
				system("cls");
				bookRecords.loadBooksFromFile("books.txt");
				admin->editBook(bookRecords);
				cout<< "Press Enter To Continue...";
				cin.get();
				break;
			case 7:
				system("cls");
				bookRecords.loadBooksFromFile("books.txt");
				admin->deleteBook(bookRecords);
				cout<< "Press Enter To Continue...";
				cin.get();
				break;
			case 8: 
				system("cls");
				bookRecords.loadBooksFromFile("books.txt");
				bookRecords.displayBooks();
				cout<< "Press Enter To Continue...";
				cin.get();
				break;
			case 9: 
				system("cls");
				bookRecords.loadBooksFromFile("books.txt");
				bookRecords.displayAvailableBooks();
				cout<< "Press Enter To Continue...";
				cin.get();
				break;
			case 10: 
				system("cls");
				bookRecords.loadBooksFromFile("books.txt");
				bookRecords.displayBorrowedBooks();
				cout<< "Press Enter To Continue...";
				cin.get();
				break;
			case 11:
				system("cls");
				bookRecords.loadBooksFromFile("magazine.txt");
				admin->addMagazine(bookRecords);
				cout<< "Press Enter To Continue...";
				cin.get();
				break;
			case 12:
				system("cls");
				admin->editMagazine(bookRecords);
				cout<< "Press Enter To Continue...";
				cin.get();
				break;
			case 13:
				system("cls");
				bookRecords.loadBooksFromFile("magazine.txt");
				admin->deleteMagazine(bookRecords);
				cout<< "Press Enter To Continue...";
				cin.get();
				break;
			case 14: 
				system("cls");
				bookRecords.loadBooksFromFile("magazine.txt");
				bookRecords.displayMagazine();
				cout<< "Press Enter To Continue...";
				cin.get();
				break;
			case 15: 
				system("cls");
				bookRecords.loadBooksFromFile("magazine.txt");
				bookRecords.displayAvailableMagazine();
				cout<< "Press Enter To Continue...";
				cin.get();
				break;
			case 16: 
				system("cls");
				bookRecords.loadBooksFromFile("magazine.txt");
				bookRecords.displayBorrowedMagazine();
				cout<< "Press Enter To Continue...";
				cin.get();
				break;
			case 17:
				system("cls");
				viewCustomers(customer);
				break;
			case 18:
				system("cls");
				admin->viewBorrowedBooks();
				break;
			case 19:
				system("cls");
				admin->viewBorrowedHistory();
				break;
			case 20:
				system("cls");
				admin->viewBorrowedMagazine();
				break;
			case 21:
				system("cls");
				admin->viewBorrowedMagazineHistory();
				break;
			case 22:
				system("cls");
         			library.sortBooksByTitle();
				cout << "Press Enter to continue...";
				cin.get();
				break;
			case 23:
				system("cls");
				library.searchBook();
				cout << "Press Enter to continue...";
				cin.get();
				break;
			case 24:
				system("cls");
				library.sortMagazinesByTitle();
				cout << "Press Enter to continue...";
				cin.get();
				break;
			case 25:
				system("cls");
				library.searchMagazineById();
				cout << "Press Enter to continue...";
				cin.get();
				break;
			case 26:
				system("cls");
				library.bubbleSortMagazines();
				cout << "Press Enter to continue...";
				cin.get();
				break;
			case 27:
				system("cls");
				library.binarySearchMagazine();
				cout << "Press Enter to continue...";
				cin.get();
				break;
			case 28:
				cout << "Logging out. Goodbye!\n";
				return;
			default:
				cout<< "Invalid Choice...";
				cin.get();
		}
	}while(choice!=28);
}
void customerMenu(Customer&);

void viewCustomers(Customer& custSystem) {
    system("cls");
    cout << "  ____________\n";
    cout << "  |  _       |\n";
    cout << "  | | |      |\n";
    cout << "  | | |___   |\n";
    cout << "  | |_____|  |\n";
    cout << "  |__________|\n\n";
    cout << "     JR Library\n";
    cout << "JR Library Management System\n";
    cout << "\n--------------------------------------------------------------------\n";
    cout << "                          CUSTOMER DIRECTORY\n";
    cout << "--------------------------------------------------------------------\n\n";
    
    Customer::CustomerNode* current = custSystem.head;
    
    if (!current) {
        cout << "No customer records found.\n";
        cout << "Press enter to return to main menu...";
        cin.ignore();
        cin.get();
        return;
    }

    int count = 1;
    while (current) {
        Customer* cust = current->customer;
        
        cout << "CUSTOMER #" << count++ << "\n";
        cout << "ID: " << cust->getID() << "\n";
        cout << "Name: " << cust->getName() << "\n";
        cout << "Email: " << cust->getEmail() << "\n";
        cout << "Phone: " << cust->getPhoneNum() << "\n";
        cout << "----------------------------------------\n\n";
        
        current = current->next;
    }
    
    cout << "Press enter to return to main menu...";
    cin.ignore();
    cin.get();
}

// =============== Main Function ===================

int main() {
	int choice;
	int loginType;
	Admin* admin = new Admin();
	Customer* customer = new Customer();
	
	while(true){
		system("cls");
		cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout<< "\n____________________________________________________________________________________________________________________________________________________________\n\n\n";
        
        cout<<"\n                                                    |======================================================|";
        cout<<"\n                                                    |              JR Library Management System            |";
        cout<<"\n                                                    |======================================================|";
        cout<<"\n                                                    |1.Signup account.                                     |";
        cout<<"\n                                                    |                                                      |";
        cout<<"\n                                                    |2.Login account.                                      |";
        cout<<"\n                                                    |                                                      |";
        cout<<"\n                                                    |3.Reset Password                                      |";
        cout<<"\n                                                    |                                                      |";
        cout<<"\n                                                    |4.Exit.                                               |";
        cout<<"\n                                                    |======================================================|";
    
        cout<<"\n\n                                                    Please Enter Your Option : ";
        cin>>choice;
        cin.ignore(); 
        
        switch(choice){
        	case 1:
        		//signup
        		system("cls");
        		customer->registerCustomer();
        	case 2:
        		system("cls");
				cout << "  ____________\n";
			    cout << "  |  _       |\n";
			    cout << "  | | |      |\n";
			    cout << "  | | |___   |\n";
			    cout << "  | |_____|  |\n";
			    cout << "  |__________|\n\n";
			    cout << "     JR Library\n";
			    cout << "JR Library Management System\n";
			    cout<< "\n____________________________________________________________________________________________________________________________________________________________\n\n\n";
		        
		        cout<<"\n                                                    |======================================================|";
                cout<<"\n                                                    |              JR Library Management System            |";
                cout<<"\n                                                    |======================================================|";
                cout<<"\n                                                    |1.User                                                |";
                cout<<"\n                                                    |                                                      |";
                cout<<"\n                                                    |2.Admin                                               |";
                cout<<"\n                                                    |                                                      |";
                cout<<"\n                                                    |3.Exit.                                               |";
                cout<<"\n                                                    |======================================================|";
		    
		        cout<<"\n\n                                                    Please Enter Your Option : ";
		        cin>>loginType;
		        cin.ignore();
		        
		        //user
		        if(loginType==1){
		        	customer->loadCustomersFromFile();
		        	if(customer->customerLogin())
		        	{ 
					}
				}
				//admin
				else if(loginType==2){
					admin->loadAdminsFromFile();
					if(admin->adminLogin())
					{
						adminMenu(admin);
					}
				}
				break;
			case 3:
				//reset
				customer->resetPassword();
				break;
			case 4:
				cout<< "Thanks For Use JR Library Management System...";
				delete admin;
				delete customer;
				exit(0); 
				break;
		}
	}
    return 0;
}

