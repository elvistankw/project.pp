#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#define CYAN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
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
    string id;
    string name;
    string password;
    string email;
    string phone_num;
public:
    Person(){
		id = "";
	    name = "";
	    password = "";
	    email = "";
	    phone_num = "";
	};
    
    Person(string id, string n, string p, string e, string pn)
	{
    	this->id=id;
    	name=n;
    	password=p;
    	email=e;
    	phone_num=pn;
	};
	
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
    void setPassword(const string& newPass) 
	{ 
		password = newPass; 
	}
    void setEmail(const string& e) 
	{ 
		email = e; 
	}
	void setName(const string& n) 
	{ 
		name = n; 
	}
	void setPhoneNum(string num) 
	{ 
		phone_num = num; 
	}
	
    //virtual void display() const;
    //virtual ~Person();
};

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
    	BookNode* temp = head;
	    while (temp != nullptr) 
		{
	        if (temp->id == id) 
			{
	            cout << "Error: Book ID already exists!\n";
	            return;
	        }
	        temp = temp->next;
	    }
	
	    BookNode* newNode = new BookNode{id, title, author, year, true, nullptr};
	
	    if (head == nullptr) 
		{
	        head = newNode;
	    } 
		else 
		{
	        BookNode* last = head;
	        while (last->next != nullptr) 
			{
	            last = last->next;
	        }
	        last->next = newNode;
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
};

// ================ Derived Classes =================

class Admin : public Person {
private:
	struct AdminNode {
	    string id;
	    string name;
	    string password;
	    string email;
	    string phone_num;
	    AdminNode* next;
	    
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
	    void setPassword(const string& newPass) 
		{ 
			password = newPass; 
		}
	    void setEmail(const string& e) 
		{ 
			email = e; 
		}
		void setName(const string& n) 
		{ 
			name = n; 
		}
		void setPhoneNum(string num) 
		{ 
			phone_num = num; 
		}
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
	        if (temp->email == inputEmail && temp->password == inputPassword) {
	            cout << "\nLogin successful! Welcome, " << temp->name << "!" << endl;
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
	        if (temp->id == id) 
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
	        if (temp->email == email) 
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
	
	    AdminNode* newNode = new AdminNode{id, name, password, email, phone_num, nullptr};
	
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
	    while (temp != nullptr) 
		{  
	
		    if (temp->id == editID) 
	        {
	            cout << "\n                                                               Current Admin Information\n\n";
	            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	            cout << "ID\t\t\t\t\tName\t\t\t\tEmail\t\t\t\tPhone Number" << endl;
	            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	            cout << temp->id << "\t\t\t\t" << temp->name << "\t\t\t" << temp->email << "\t\t\t" << temp->phone_num << endl;
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
	                cin >> choice;
	                cin.ignore();
	
	                switch (choice) {
	                    case 1: {
	                        string newName;
	                        do {
	                            cout << "Enter new name (current: " << temp->name << "): ";
	                            getline(cin, newName);
	                            if (newName.empty()) {
	                            	cout << "Name cannot be empty. Please try again.\n";
								}
	                        } while (newName.empty());
	                        temp->setName(newName);
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
	                        temp->setPassword(password);
	                        break;
	                    }
	
	                    case 3: {
	                        string newEmail;
	                        do {
	                            cout << "Enter new email (current: " << temp->email << "): ";
	                            getline(cin, newEmail);
	                            if (newEmail.empty()) cout << "Email cannot be empty. Please try again.\n";
	                        } while (newEmail.empty());
	                        temp->setEmail(newEmail);
	                        break;
	                    }
	
	                    case 4: {
	                        string phoneInput;
	                        do {
	                            cout << "Enter new phone number (current: " << temp->phone_num << "): ";
	                            getline(cin, phoneInput);
	                            if (phoneInput.empty()) cout << "Phone number cannot be empty. Please try again.\n";
	                        } while (phoneInput.empty());
	                        temp->setPhoneNum(phoneInput);
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
	
	    while (temp != nullptr && temp->id != targetID) 
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
			    outFile << temp->id << "," << temp->name << "," << temp->password << "," << temp->email << "," << temp->phone_num << endl;
	            temp = temp->next;
	        }
		    outFile.close();
		    cout << "Admin information is save into the admin.txt..." << endl;
		} else {
		    cout << "Save admin information unsuccessfully, cannot open txt file..." << endl;
		}
	}

	void loadAdminsFromFile() {
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
	
	        AdminNode* newNode = new AdminNode{id, name, password, email, phone, nullptr};
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
	            cout << "ID\t\t\tTitle\t\t\t\tAuthor\t\t\tYear\t\t\tAvailable\n";
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
    void sortBooks();
    void searchBook();
    void viewCustomers();
    void generateReport();
    //void display() const override;
    //friend void viewReport(Admin);
};

class Customer : public Person {
public:
    Customer();
    Customer(int, string, string);
    void searchBook();

    void borrowBook(){
        BookRecord bookRecord;
        bookRecord.loadBooksFromFile("books.txt");
        
        string bookId;
        cout << CYAN << "\nEnter book ID to borrow: " << RESET;
        getline(cin, bookId);

        BookRecord::BookNode* book = nullptr;
        BookRecord::BookNode* temp = bookRecord.head;
        while(temp) {
            if(temp->id == bookId) {
                book = temp;
                break;
            }
            temp = temp->next;
        }

        if(!book) {
            cout << RED << "Book not found!" << RESET << endl;
            return;
        }

        if(!book->available) {
            cout << RED << "Book is already borrowed!" << RESET << endl;
            return;
        }

        time_t now = time(0);
        tm* ltm = localtime(&now);
        char borrowDate[11], returnDate[11];
        strftime(borrowDate, 11, "%Y-%m-%d", ltm);
        
        ltm->tm_mday += 7;
        mktime(ltm);
        strftime(returnDate, 11, "%Y-%m-%d", ltm);

        BorrowBook* newBorrow = new BorrowBook{
            this->getID(),
            book->id,
            book->title,
            book->author,
            book->year,
            borrowDate,
            returnDate,
            nullptr
        };

        if(head == nullptr) {
            head = newBorrow;
        } else {
            newBorrow->next = head;
            head = newBorrow;
        }

        book->available = false;
        
        bookRecord.saveBooksToFile("books.txt");
        
        ofstream borrowFile("borrowed.txt", ios::app);
        borrowFile << newBorrow->uid << ","
                  << newBorrow->id << ","
                  << newBorrow->title << ","
                  << newBorrow->author << ","
                  << newBorrow->year << ","
                  << newBorrow->borrowDate << ","
                  << newBorrow->returnDate << "\n";
        borrowFile.close();

        cout << CYAN << "\nBook borrowed successfully!\n"
             << "Title: " << book->title << "\n"
             << "Return Date: " << returnDate << RESET << endl;
    }

    void returnBook();

    void viewBorrowed();
    //void display() const override;
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
void adminMenu(Admin& admin)
{
	int choice;
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
	    cout << "                              |                                        4.  Diaplay Admin                                                   |" << endl;
	    cout << "                              |                                        5.  View All Books                                                  |" << endl;
	    cout << "                              |                                        6.  View Available Books                                            |" << endl;
	    cout << "                              |                                        7.  View Borrowed Books                                             |" << endl;
	    cout << "                              |                                        8.  Add New Book                                                    |" << endl;
	    cout << "                              |                                        9.  Edit Book                                                       |" << endl;
	    cout << "                              |                                        10. Delete Book                                                     |" << endl;
	    cout << "                              |                                        11. Sort Books                                                      |" << endl;
	    cout << "                              |                                        12. Search Books                                                    |" << endl;
	    cout << "                              |                                        13. View All Customers                                              |" << endl;
	    cout << "                              |                                        14. Sort Customers                                                  |" << endl;
	    cout << "                              |                                        15. Search Customers                                                |" << endl;
	    cout << "                              |                                        16. View Report                                                     |" << endl;
	    cout << "                              |                                        17. Exit                                                            |" << endl;
	    cout << "                              |------------------------------------------------------------------------------------------------------------|" << endl;
		cout<< "Enter Your Choice: ";
		cin>>choice;
		cin.ignore();
	
		switch(choice)
		{
			case 1:
				system("cls");
				admin.addAdmin(); 
				admin.saveAdminToFile();
				cout<<"Press Enter To Continue...";
				cin.get();
				break;
			case 2:
				system("cls");
				admin.editAdmin();
				admin.saveAdminToFile(); 
				cout<<"Press Enter To Continue...";
				cin.get();
				break;
			case 3:
				system("cls");
				admin.removeAdmin();
				admin.saveAdminToFile();
				cout<<"Press Enter To Continue...";
				cin.get();
				break;
			case 4:
				system("cls");
				admin.displayAdmin();
				cout<<"Press Enter To Continue...";
				cin.get();
				break;
			case 5:
				//search book;
			case 6:
				//view customer
			case 7:
				//view report
			case 8: 
				//view borrowed book
			default:
				cout<< "Invalid Choice...";
		}
	}while(choice!=17);
}

void customerMenu(Customer& customer){
	int choice;
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
	    cout << "                                                                        User Dashboard\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                              |------------------------------------------------------------------------------------------------------------|" << endl;
	    cout << "                              |                                               MENU                                                         |" << endl;
	    cout << "                              |------------------------------------------------------------------------------------------------------------|" << endl;
	    cout << "                              |                                        1.  Borrow Book                                                     |" << endl;
	    cout << "                              |                                        2.  Return Book                                                     |" << endl;
	    cout << "                              |                                        3.  View Borrewed Book                                              |" << endl;
	    cout << "                              |                                        4.  User Information                                                |" << endl;
	    cout << "                              |                                        5.  Exit                                                            |" << endl;
	    cout << "                              |------------------------------------------------------------------------------------------------------------|" << endl;
		cout<< "Enter Your Choice: ";
		cin>>choice;
		cin.ignore();
	
		switch(choice)
		{
			case 1:
				system("cls");
				customer.borrowBook(); 
				cout<<"Press Enter To Continue...";
				cin.get();
				break;
			/*case 2:
				system("cls");
				customer.returnBook(); 
				cout<<"Press Enter To Continue...";
				cin.get();
				break;
			case 3:
				system("cls");
				customer.viewBorrowed(); 
				cout<<"Press Enter To Continue...";
				cin.get();
				break;
			case 4:
				system("cls");
				customer.display(); 
				cout<<"Press Enter To Continue...";
				cin.get();
				break;*/
			default:
				cout<< "Invalid Choice...";
		}
	}while(choice!=5);
	
}

void loadSampleBooks(Library&);
void mainMenu();

// =============== Main Function ===================

int main() {
	int choice;
	int loginType;
	Admin admin;
	Customer customer;
	
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
                cout<<"\n                                                    |                Honda Service Centre                  |";
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

					customerMenu(customer);
		        	
				}
				//admin
				else if(loginType==2){
					admin.loadAdminsFromFile();
					if(admin.adminLogin())
					{
						adminMenu(admin);
					}
					
					
				}
		}
	}
    return 0;
} 