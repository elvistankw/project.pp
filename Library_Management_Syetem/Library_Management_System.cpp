#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

// Forward declarations for sorting functio

#define CYAN "\033[32m" //green color
#define RED "\033[31m"//red color
#define RESET "\033[0m"//reset color

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
	
    string getID() const
	{
    	return id;
	}
    string getName() const
	{ 
		return name; 
	}
    string getPassword() const
	{ 
		return password; 
	}
    string getEmail() const
	{
    	return email;
	}
	string getPhoneNum() const
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
	
    virtual ~Person(){};
};

//Book 
class BookRecord {
//friend class
friend class Library; 
public:
	//structure book node
    struct BookNode {
        string id;
        string title;
        string author;
        int year;
        bool available;
        BookNode* next;
        
        void setTitle(string& newTitle) 
		{
			//update title
	        title = newTitle;
	    }
	
	    void setAuthor( string& newAuthor) 
		{
			//update author
	        author = newAuthor;
	    }
	
	    void setYear(int newYear) 
		{
			//update year
	        year = newYear;
	    }
	    
	    void setAvailable(bool status) 
		{
			//update status
	    	available=status;
		}
		
    };
	// Head pointer for linked list
    BookNode* head;
	// Constructor initializes empty list
    BookRecord() : head(nullptr){};
    // Destructor to clean up memory
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
	// Insert new book into the linked list
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
	// Delete book by ID from linked list
    void deleteBookById(string id) {
		// Current node pointer
    	BookNode* temp = head;
		 // Previous node pointer
	    BookNode* prev = nullptr;
	    while (temp != nullptr) 
		{
			// Found matching ID
	        if (temp->id == id) 
			{
				// If deleting head node
	            if (prev == nullptr) 
				{
					// Update head pointer
	                head = temp->next; 
	            } 
				else
				{
					// Bypass current node
	                prev->next = temp->next; 
	            }
	            delete temp;
	            cout << "Book deleted successfully!\n";
	            return;
	        }
			// Update previous pointer
	        prev = temp;
			//move the next node
	        temp = temp->next;
	    }
	    cout << "Book ID not found!\n";
	};
    // Update availability status of a book
    void setAvailable(string id, bool isAvailable){
    	BookNode* temp = head;
	    while (temp != nullptr) 
		{
			// Found matching ID
	        if (temp->id == id) {
				//update available
	            temp->available = isAvailable;
	            return;
	        }
	        temp = temp->next;
    	}
    	cout << "Error: Book ID not found!\n";
	}
	//Virtual function to display books
    virtual void displayBooks(){
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
	//Virtual function to display available books
	virtual void displayAvailableBooks() {
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
	//Virtual function to display borrowed books
	virtual void displayBorrowedBooks() {
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
	//Virtual function to display magazine
	virtual void displayMagazine(){
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
	//Virtual function to display available magazine
	virtual void displayAvailableMagazine() {
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
	//Virtual function to display borrowed magazine
	virtual void displayBorrowedMagazine() {
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
	//Virtual function to save file
    virtual void saveBooksToFile(const string& filename) {
		// Open output file 
        ofstream outFile(filename, ios::trunc);
        if (!outFile) {
            cerr << "Error opening file for writing!\n";
            return;
        }
		// Start traversal from head of linked list
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
    //Virtual function to load file
    virtual void loadBooksFromFile(const string& filename) {
    	BookNode* current = head;
	    while (current != nullptr) {
	        BookNode* toDelete = current;
	        current = current->next;
	        delete toDelete;
	    }
	    head = nullptr;
	    // Open input file for reading
	    ifstream inFile(filename);
	    if (!inFile) {
	        cerr << "Error opening file for reading!\n";
	        return;
	    }
	    string line;
	    while (getline(inFile, line)) {
	        stringstream ss(line);
	        string id, title, author, yearStr, availableStr;
			// Parse comma-separated values
	        getline(ss, id, ',');
	        getline(ss, title, ',');
	        getline(ss, author, ',');
	        getline(ss, yearStr, ',');
	        getline(ss, availableStr,',');
	        int year = stoi(yearStr);
	        bool available = (availableStr == "1");
	        // Create new book node
	        BookNode* newNode = new BookNode{id, title, author, year, available, nullptr};
			// Insert node at end of linked list
	        if (head == nullptr) 
			{
	            head = newNode;
	        } else {
	            BookNode* temp = head;
	            while (temp->next != nullptr) {
					// Traverse to end of list
	                temp = temp->next;
	            }
				// Append new node
	            temp->next = newNode;
	        }
			// Update book availability status
        	setAvailable(id, available);
	    }
	    inFile.close();
	}
    virtual BookNode* findBookById(string id) {
        BookNode* temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
				// Return node if ID matches
                return temp;
            }
			// Check next node
            temp = temp->next;
        }
		// Return null if not found
        return nullptr;
    }
    // Placeholder for sorting functionality
    virtual void sortBooks() {
        // Base implementation does nothing
        cout << "Base class sort not implemented" << endl;
    }
    // Placeholder for binary search
    virtual BookNode* binarySearch(const string& searchValue) {
        // Base implementation returns nullptr
        return nullptr;
    } 
    // In the BookRecord class declaration (around line 70)
    friend void searchHelper(BookRecord& records, const string& query, bool searchTitle, bool searchAuthor, bool searchId);
};

// ================ Derived Classes =================

// ================ Derived Classes =================
//Admin class inheritance Person
class Admin : public Person {
private:
	
	//struct for admin linked list node
	struct AdminNode {
		Admin* admin; //pointer to admin object
	    AdminNode* next; //pointer to next node
	    AdminNode(Admin* a) : admin(a), next(nullptr) {} //constructor
		};
		
		AdminNode* head; //head for admin linked list
	
public:
	//default constructor
    Admin()
	{
    	head = NULL; // initialize head
	};
	
	//parameterized constructor
	Admin(string id, string name, string password, string email = "", string phone_num = "") : Person(id, name, password, email, phone_num) {}
	

	//admin login function
	bool adminLogin() {
		system("cls");
	    string inputEmail,inputPassword;
	    AdminNode* temp =head; //start from head
	    
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
	    //get user input
	    cout << "Enter email: ";
	    getline(cin,inputEmail);
	    cout << "Enter password: ";
	    cin >> inputPassword;
		
		// check credentials against stored admins
	    while (temp != NULL) {
	        if (temp->admin->getEmail() == inputEmail && temp->admin->getPassword() == inputPassword) {
	            cout << "\nLogin successful! Welcome, " << temp->admin->getName() << "!" << endl;
	            cin.ignore();
	            cin.get();
	            return true; //login successful
	        }
	        temp = temp->next; // move to next admin
	    }
	
	    cout << "\nLogin failed. Invalid username or password.\n";
	    cin.ignore();
	    cin.get();
	    return false; //login unsucessful

	}

    // check for duplicate admin ID
    bool isDuplicateID(string id) 
	{
	    AdminNode* temp = head; //temporary pointer to traverse the linked list
	    while (temp != NULL) 
		{
	        if (temp->admin->getID() == id) 
			{
	            return true; //id already exits
	        }
	        temp = temp->next; //move to next node
	    }
	    return false; // id is unique
	}
	
	// check for duplicate admin ID
	bool isDuplicateEmail(string email) 
	{
	    AdminNode* temp = head; //temporary pointer
	    while (temp != NULL) 
		{
	        if (temp->admin->getEmail() == email) 
			{
	            return true; //email already exits
	        }
	        temp = temp->next; //move to next node
	    }
	    return false; //email is unique
	}

	// Add new admin to system
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
	    //user input
	    //Admin ID
		while(id.empty()){
			cout << "Enter Admin ID: ";
		    getline(cin,id);
		    if(id.empty()){
		    	cout<< "ID cannot be empty. Please try again.\n";
			}
		}  
	    //Admin Name
	    while (name.empty()) {
	        cout << "Enter name: ";
	        getline(cin, name);
	        if (name.empty()) {
	        	cout << "Name cannot be empty. Please try again.\n";
			}
	    } 
	    //Get and comfirm password
	    do {
	        cout << "Enter password: ";
	        getline(cin, password);
	        if (password.empty()) {
	            cout << "Password cannot be empty.\n";
	            continue;
	        }
	        cout << "Confirm password: "; //comfirm password
	        getline(cin, confirm_password);
	        if (password != confirm_password) {
	            cout << "Passwords do not match. Please try again.\n";
	        }
	    } while (password.empty() || password != confirm_password);
	    //get email input
	    while (email.empty()) {
	        cout << "Enter email : ";
	        getline(cin, email);
	            if (email.empty()) cout << "Email cannot be empty. Please try again.\n";
	    } 
	    //get phone number inut
	    while (phone_num.empty()) {
	        cout << "Enter phone number: ";
	        getline(cin, phone_num);
	            if (phone_num.empty()) cout << "Phone number cannot be empty. Please try again.\n";
	    } 
	    
	    // Check for duplicate ID or email 
	    if (isDuplicateID(id) || isDuplicateEmail(email)) 
		{
	        cout << "Error: ID or admin email already exists. Add unsuccessfully!" << endl;
	        return;
	    }
	
	    //create new admin and add to linked list
		Admin* newAdmin = new Admin(id, name, password, email, phone_num);
	AdminNode* newNode = new AdminNode(newAdmin);
		
		//if list is empty
	    if (head == NULL) {
	        head = newNode; //set head to new node
	    } 
		else{
	        AdminNode* temp = head;
	        	while (temp->next != nullptr){
	        		temp = temp->next;
				}
				temp->next = newNode; //add new node at the end of the list
    	}
    	cout << "Yeah! Add New Admin Successfully..." << endl;
	}
	
	//edit admin function
	void editAdmin()
	{
	    bool success = true;
	    string editID;
	    string newName;
		string password, confirm_password;
		string newEmail;
		string phoneInput;
					
		cout << "  ____________\n";
		cout << "  |  _       |\n";
		cout << "  | | |      |\n";
		cout << "  | | |___   |\n";
		cout << "  | |_____|  |\n";
		cout << "  |__________|\n\n";
		cout << "     JR Library\n";
		cout << "JR Library Management System\n";
		cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
		// check if there are any admins to edit
		if (head ==NULL) 
		{
	        cout << "No admin records is available to edit, please check the admin.txt file.\n";
	        return;
	    }
	    
	    // Check if there are any admins to edit
	    // get admin id to edit
	    cout << "Enter Admin ID to edit: ";
	    getline(cin,editID);  
	
	    AdminNode* temp = head;
	    while (temp !=NULL && success) 
		{  
		    if (temp->admin->getID() ==editID) 
	        {
	            cout << "\n                                                               Current Admin Information\n\n";
	            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	            cout << "ID\t\t\t\t\tName\t\t\t\tEmail\t\t\t\tPhone Number" << endl;
	            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	            cout << temp->admin->getID() << "\t\t\t\t" << temp->admin->getName() << "\t\t\t" << temp->admin->getEmail() << "\t\t\t" << temp->admin->getPhoneNum() << endl;
	            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				// Display edit options
	            int choice;
	            do {
	                cout << "\nWhich type of information do you want to edit?" << endl;
	                cout << "1. Name" << endl;
	                cout << "2. Password" << endl;
	                cout << "3. Email" << endl;
	                cout << "4. Phone Number" << endl;
	                cout << "5. Exit Edit" << endl;
	                cout << "Enter your choice: ";
	                if (!(cin >> choice)){
	                    cin.clear();
	                    cin.ignore();
	                    cout << "Invalid input. Please enter a number." << endl;
	                    continue;
	                }
	                cin.ignore();
	                // Handle user's choice
	                switch (choice) {
	                    case 1: {// Edit name
	                        while (newName.empty()){
	                            cout << "Enter new name (current: " << temp->admin->getName() << "): ";
	                            getline(cin, newName);
	                            if (newName.empty()) {
	                            	cout << "Name cannot be empty. Please try again.\n";
								}
	                        } 
	                        temp->admin->setName(newName);
	                        break;
	                    }
	                    case 2: {// Edit password
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
	                    case 3: {// Edit email
							while (newEmail.empty() || isDuplicateEmail(newEmail)) {
							    cout << "Enter new email (current: " << temp->admin->getEmail() << "): ";
							    getline(cin, newEmail);
							    if (newEmail.empty()) 
								{
							        cout << "Email cannot be empty. Please try again.\n";
							    } else if (isDuplicateEmail(newEmail)) {
							        cout << "Email already exists. Please try another one.\n";
							    }
							} 
							
							temp->admin->setEmail(newEmail);
	                        break;
	                    }
	                    case 4: { // Edit phone number
	                        while (phoneInput.empty()) {
	                            cout << "Enter new phone number (current: " << temp->admin->getPhoneNum() << "): ";
	                            getline(cin, phoneInput);
	                            if (phoneInput.empty()) cout << "Phone number cannot be empty. Please try again.\n";
	                        } 
	                        temp->admin->setPhoneNum(phoneInput);
	                        break;
	                    }
	                    case 5: // Exit edit
	                        cout << "Finished editing admin.\n";
	                        break;
	
	                    default:
	                        cout << "Invalid choice. Try again.\n";
	                }
	
	            } while (choice != 5);
	
	            cout << "Admin updated successfully!" << endl;
	            return;
	        }
	
	        temp = temp->next; // move to the next node
	    }

    cout << "Ouh! Admin ID not found..." << endl;
	    
	    if (!success) 
		{
	        cout << "Failed to edit admin. Please try again." << endl;
	    }
	}
	
	//remove admin function
	void removeAdmin() {
		//if list is empty 
	    if (head == NULL) 
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
		
		// Get admin ID to remove
	    string targetID;
	    cout << "Enter Admin ID to remove: ";
	    getline(cin,targetID);
		//initialize pointer
	    AdminNode* temp = head; // pointer cutrent node
	    AdminNode* prev =NULL; //pointer previous node
		
		// Find the admin to remove
	    while (temp != NULL && temp->admin->getID() != targetID) 
		{
	        prev = temp; //current nod as previous
	        temp = temp->next; //move to next node
	    }
	
	    if (temp ==NULL) 
		{
	        cout << "Admin with ID " << targetID << " not found." << endl;
	        return;
	    }
		// if the removed admin is head
	    if (temp == head) 
		{
	        head = head->next; // head to next node
	    } 
		else 
		{
	        prev->next = temp->next; // bypass the node to be deleted
	    }
	
	    delete temp; // delete target node
	    cout << "Admin with ID " << targetID << " has been removed successfully." << endl;
	}
	//save admin
	void saveAdminToFile() 
	{
		//open file for writting
		ofstream outFile("admin.txt", ios::trunc); 
		if (outFile.is_open()) 
		{
			AdminNode* temp = head; //start from head
	        while (temp !=NULL) 
	        {
			    outFile << temp->admin->getID() << "," << temp->admin->getName() << "," << temp->admin->getPassword() << "," << temp->admin->getEmail() << "," << temp->admin->getPhoneNum() << endl;
	            temp = temp->next; // move to next node
	        }
		    outFile.close();
		} else {
		    cout << "Save admin information unsuccessfully, cannot open txt file..." << endl;
		}
	}

	//load admin
	void loadAdminsFromFile() {
		//clear the current admin list
		AdminNode* current = head;
	    while (current !=NULL) 
		{
	        AdminNode* toDelete = current;
	        current = current->next;
	        delete toDelete; //free memory
	    }
	    head =NULL; //reset head
    	
    	//open file for read
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
			
			//create a new admin object
			Admin* a = new Admin(id, name, password, email, phone);
			
			//create a new node to insert into the list
			AdminNode* newNode = new AdminNode(a);
			//insert the new node at the end of linked list
	        if (head == NULL)
			{
	        	head = newNode; // first admin in list
			}
	        else 
			{
	            AdminNode* temp = head;
	            while (temp->next != NULL)
				{
	            	temp = temp->next; // go to the end
				}
	            temp->next = newNode; //link the new node
	        }
	    }
	    inFile.close();
	} 
	//dispaly admin function
	void displayAdmin()
	{
		//check if admin list is empty
		if (head ==NULL) {
	        cout << "No admin records found in admin.txt." << endl;
	        return;
	    }
	    //start from the head
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
	    //print data
	    while (temp !=NULL) {
	        cout << temp->admin->getID() << "\t\t\t\t"; 
			cout << temp->admin->getName()  << "\t\t\t";
	        cout << temp->admin->getEmail()  << "\t\t\t";
	        cout << temp->admin->getPhoneNum() << endl;
	        cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	        temp = temp->next;  
	    }
	}
	//add book function
    void addBook(BookRecord& bookRecord){
    	string id, title, author;
	    int year;
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
    	// get new book input
	    cout << "Enter Book ID: ";
	    getline(cin, id);
	    cout << "Enter Title: ";
	    getline(cin, title);
	    cout << "Enter Author: ";
	    getline(cin, author);
	    cout << "Enter Year: ";
	    cin >> year;
	    cin.ignore(); 
		
	    bookRecord.insertBook(id, title, author, year); //insert book into the BookRecord
	    bookRecord.saveBooksToFile("books.txt");  // write into file
	    bookRecord.loadBooksFromFile("books.txt"); // load the lastest data from file
	    cout << "Book added successfully!\n";
	};
	//edit book function
	void editBook(BookRecord& bookRecord){
		string newTitle;
		string newAuthor;
		int newYear;
		string id;
		
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
		//check if the book list is empty
		if (bookRecord.head == NULL) 
		{
        cout << "No books to edit.\n";
        return;
	    }
		// user input book id to edit
	    cout << "Enter Book ID to edit: ";
	    getline(cin, id);
	
	    BookRecord::BookNode* temp = bookRecord.head;
	    while (temp !=NULL) {
	        if (temp->id == id) { //search fior book node with matching ID
	            cout << "\n                                                         Current Book Information\n\n";
	            cout << "----------------------------------------------------------------------------------------------------------------------------------\n";
	            cout << "ID\t\t\tTitle\t\t\t\tAuthor\t\t\t\tYear\t\t\tAvailable\n";
	            cout << "----------------------------------------------------------------------------------------------------------------------------------\n";
	            cout << temp->id << "\t\t\t" << temp->title << "\t\t\t" << temp->author << "\t\t\t" << temp->year << "\t\t\t" << (temp->available ? "Yes" : "No") << endl;
	            cout << "----------------------------------------------------------------------------------------------------------------------------------\n";
				// display edit menu
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
					//perform the selected edit
	                switch (choice) {
	                    case 1: {
	                    	string newTitle;
	                        while (newTitle.empty()) {
	                            cout << "Enter new title (current: " << temp->title << "): ";
	                            getline(cin, newTitle);
	                            if (newTitle.empty()) 
								{
	                            	cout << "Title cannot be empty. Please try again.\n";
								}
	                        } 
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
	                            	cout << "Author cannot be empty. Please try again...\n";
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
	                            cin.ignore();
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
	                        cout << "Finished editing book. Thank You...\n";
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
	// delete book function
    void deleteBook(BookRecord& bookRecord){
    	string id;
    	
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
    	if (head ==NULL) {
        	cout << "No books to delete, please check books.txt.\n";
        	return;
	    }
		//get id need to delete
	    cout << "Enter Book ID to delete: ";
	    getline(cin, id);
		bookRecord.deleteBookById(id); // Call the delete function to remove the book by ID
		bookRecord.saveBooksToFile("books.txt"); // Save the updated book list to file
		bookRecord.loadBooksFromFile("books.txt"); // Reload the list to reflect latest changes in memory
	};
	//add magazine function
	void addMagazine(BookRecord& bookRecord){
		string id, title, author;
	    int year;
	    
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
    	// Prompt user for magazine details
	    cout << "Enter Magazine ID: ";
	    getline(cin, id);
	    cout << "Enter Title: ";
	    getline(cin, title);
	    cout << "Enter Author: ";
	    getline(cin, author);
	    cout << "Enter Year: ";
	    cin >> year;
	    cin.ignore(); 
	
	    bookRecord.insertBook(id, title, author, year); // Insert magazine as a book into the book record
	    bookRecord.saveBooksToFile("magazine.txt"); // Save updated list to "magazine.txt"
	    bookRecord.loadBooksFromFile("magazine.txt"); // Reload the list from "magazine.txt" to reflect changes in memory
	    cout << "Book added successfully!\n";
	};
	//edit magazine function
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
		 
		if (bookRecord.head ==NULL) {
        cout << "No Magazines to edit.\n";
        return;
	    }
		
		//ask magazine id to edit
	    string id;
	    cout << "Enter Magazine ID to edit: ";
	    getline(cin, id);
		// travels the list to find maching id
	    BookRecord::BookNode* temp = bookRecord.head;
	    while (temp !=NULL) {
	        if (temp->id == id) {
	            cout << "\n                                                         Current Magazine Information\n\n";
	            cout << "----------------------------------------------------------------------------------------------------------------------------------\n";
	            cout << "ID\t\t\tTitle\t\t\t\tAuthor\t\t\tYear\t\t\tAvailable\n";
	            cout << "----------------------------------------------------------------------------------------------------------------------------------\n";
	            cout << temp->id << "\t\t\t" << temp->title << "\t\t\t" << temp->author << "\t\t\t\t" << temp->year << "\t\t\t" << (temp->available ? "Yes" : "No") << endl;
	            cout << "----------------------------------------------------------------------------------------------------------------------------------\n";
				// Menu to edit fields
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
	                        while (newTitle.empty()) {
	                            cout << "Enter new title (current: " << temp->title << "): ";
	                            getline(cin, newTitle);
	                            if (newTitle.empty()) cout << "Title cannot be empty. Please try again.\n";
	                        } 
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
	            // Menu to edit fields
	            cout << "Magazine updated successfully!\n";
	            bookRecord.saveBooksToFile("magazine.txt");
	            bookRecord.loadBooksFromFile("magazine.txt");
	            return;
	        }
	        temp = temp->next; //move to the next node
	    }
	    cout << "Magazine ID not found!\n";
	};
	//delete magazine function
    void deleteMagazine(BookRecord& bookRecord){
    	string id;
    	
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
    	if (head == NULL) {
        	cout << "No magazine to delete.\n";
        	return;
	    }
	 	// get the if of the magazine to delete
	    cout << "Enter Magazine ID to delete: ";
	    getline(cin, id);
		bookRecord.deleteBookById(id); // Delete magazine using existing delete function
		bookRecord.saveBooksToFile("magazine.txt"); // Save changes to the magazine file
		bookRecord.loadBooksFromFile("magazine.txt"); // Reload the file to reflect changes
	}; 
	// Struct for borrowed book node
	struct BorrowNode {
	    string userId, bookId, title, author, borrowDate, returnDate;
	    int year;
	    bool returned; // 0 = not returned, 1 = returned
	    BorrowNode* next;
	}; 
	// View currently borrowed books
	void viewBorrowedBooks() {
	    ifstream file("borrowedBook.txt");
	    if (!file) {
	        cout << "Error opening borrowed.txt file!\n";
	        return;
	    }
		// Linked list to store currently borrowed books
	    BorrowNode* head = nullptr;
	    BorrowNode* tail = nullptr;
	
	    string line;
	    while (getline(file, line)) {
	        if (line.empty()) {
	        	continue;
			}
	        
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
	
	        bool returned =(returnedStr == "1");
			// Only store if the book has not been returned yet
	        if (!returned) {
	            BorrowNode* newNode =new BorrowNode{
	                userId, bookId, title, author, borrowDate, returnDate,
	                stoi(yearStr), returned, nullptr
	            };
	            // Add to linked list
	            if (!head) {
	                head = tail =newNode;
	            } 
				else 
				{
	                tail->next = newNode;
	                tail =newNode;
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
		     << setw(12) << "User ID" << setw(12) << "Book ID" << setw(30) << "Title" << setw(20) << "Author" << setw(16) << "Borrow Date" << setw(16) << "Return Date" << setw(15) << "Returned"
			 << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------\n";
		// display list
		BorrowNode* current =head;
		while (current){
		    if (!current->returned) { 
		        cout <<left
		             <<setw(12) << current->userId
		             <<setw(12) << current->bookId
		             <<setw(30) << current->title
		             <<setw(20) << current->author
		             <<setw(20) << current->borrowDate
					 <<setw(15) << current->returnDate
					<<setw(10) << (current->returned ? "Yes" : "No")
		 << endl;
		    }
		    current = current->next;
		}
		cout <<"-------------------------------------------------------------------------------------------------------------------------\n";
		// free linked list memory
	    while (head){
	        BorrowNode* temp =head;
	        head = head->next;
	        delete temp;
	    }
	    
	    cout << "\nPress Enter to Continue...";
		cin.ignore(); 
		cin.get();    
	}
	
	// view borrowed history
	void viewBorrowedHistory() {
	    ifstream file("borrowedBook.txt");
	    if (!file) {
	        cout << "Error opening borrowed.txt file!\n";
	        return;
	    }
		// load return record into linked list
	    BorrowNode* head =NULL;
	    BorrowNode* tail =NULL;
	
	    string line;
	    while (getline(file, line)) {
	        if (line.empty()){
	        	continue;
			} 
			
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
	            } else 
				{
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
	         << setw(12) << "User ID" << setw(12) << "Book ID" << setw(30) << "Title" << setw(20) << "Author" << setw(20) << "Borrow Date" << setw(15) << "Return Date" << setw(10) << "Returned"
	         << endl;
	    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
	
	    BorrowNode* current = head;
	    while (current){
	        cout <<left
	             <<setw(12) << current->userId
	             <<setw(12) << current->bookId
	             <<setw(30) << current->title
	             <<setw(20) << current->author
	             <<setw(20) << current->borrowDate
	             <<setw(15) << current->returnDate
	             <<setw(10) << (current->returned ? "Yes" : "No")
	             <<endl;
	        current =current->next;
	    }
	
	    cout << "-------------------------------------------------------------------------------------------------------------------------" <<endl;
		
		    while (head) 
			{
		        BorrowNode* temp = head;
		        head = head->next;
		        delete temp;
		    }
		    //ask user need monthly report or not
		    char choice;
			cout<< "\n\nDo you need to generate a Borrowed Books Record Report? (Y or N) :";
			cin>>choice;
			
			if(toupper(choice) == 'Y'){
				int yearFilter, monthFilter;
			    cout << "Enter the YEAR to filter by (example: 2024): ";
			    cin >> yearFilter;
			    cout << "Enter the MONTH to filter by (1 - 12): ";
			    cin >> monthFilter;
			    cin.ignore();
			    
			    ifstream file("borrowedBook.txt");  
				if (!file) 
				{
				    cout << "Error opening borrowedBook.txt file!\n";
				    return;
				}

				// helper functions to extract year/month from returnDate
			    auto extractYear = [](const string& dateStr) -> int 
				{
			        if (dateStr.length() < 4) {
			        	return -1;
					}
			        return stoi(dateStr.substr(0, 4));
			    };
			    
			    auto extractMonth = [](const string& dateStr) -> int 
				{
			        if (dateStr.length() < 7){
			        	return -1;
					} 
			        return stoi(dateStr.substr(5, 2));
			    };
				//reload file
			    BorrowNode* head =NULL;
			    BorrowNode* tail = NULL;
			
			    string line;
			    while (getline(file, line)) {
			        if (line.empty()) 
					{
			        	continue;
					}
			
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
			            BorrowNode* newNode = new BorrowNode{ userId, bookId, title, author, borrowDate, returnDate, stoi(yearStr), returned, nullptr };
			            if (!head) {
			                head =tail =newNode;
			            } 
						else 
						{
			                tail->next =newNode;
			                tail = newNode;
			            }
			        }
			    }
			    file.close();
				//diaplay report
			    cout << "\nBorrowed Books Records - " << yearFilter << "/" << (monthFilter < 10 ? "0" : "") << monthFilter << endl;
			    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
			    cout <<left <<setw(12) << "User ID" << setw(12) << "Book ID" << setw(30) << "Title" << setw(20) << "Author" << setw(20) << "Borrow Date"<< setw(15) << "Return Date" << setw(10) << "Returned"
			         <<endl;
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
					//save to file
			        string filename = "borrowedHistoryReport.txt";
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
				// free memory of main history list
			    while (head) 
				{
			        BorrowNode* temp = head;
			        head = head->next;
			        delete temp;
			    }
			}

		    cout << "\nPress Enter to return to menu...";
			cin.ignore(); 
			cin.get();    
	}
	//view borrowed  magazine 
	void viewBorrowedMagazine() {
	    ifstream file("borrowedMagazines.txt"); // read file
	    if (!file) {
	        cout << "Error opening borrowed.txt file!\n";
	        return;
	    }
		// initialize pointers for the linked list of borrowed magazine records
	    BorrowNode* head =NULL;
	    BorrowNode* tail =NULL;
	
	    string line;
	    while (getline(file, line)) {
	        if (line.empty()) 
			{
	        	continue;
			}
	        
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
			// skip empty lines
	        bool returned = (returnedStr == "1"); 
			// only include magazines that have not been returned
	        if (!returned){
	        	// create a new BorrowNode with parsed data
	            BorrowNode* newNode = new BorrowNode{ userId,bookId, title, author,borrowDate, returnDate, stoi(yearStr),returned, nullptr
	            };
	            // add the node to the linked list
	            if (!head)
				{
	                head = tail =newNode; // first node
	            } 
				else {
	                tail->next = newNode; // append to list
	                tail =newNode; // move tail pointer
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
		cout << left << setw(12) << "User ID" << setw(15) << "Magazine ID" << setw(30) << "Title" << setw(20) << "Author" << setw(16) << "Borrow Date" << setw(16) << "Return Date" << setw(15) << "Returned" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------\n";
		//display each node in the list
		BorrowNode* current = head;
		while (current) 
		{
		    if (!current->returned) { 
		        cout << left
		             <<setw(12) << current->userId
		             <<setw(15) << current->bookId
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
		// move tail pointer
	    while (head) {
	        BorrowNode* temp =head;
	        head = head->next;
	        delete temp;
	    }
	    
	    cout << "\nPress Enter To Continue...";
		cin.ignore(); 
		cin.get();    
	}
	
	//view borrowed magazine history function
	void viewBorrowedMagazineHistory() {
	    ifstream file("borrowedMagazines.txt"); addAdmin(); //open magazines.txt file 
	    if (!file) {
	        cout << "Error opening borrowed.txt file!\n";
	        return;
	    }
		// Initialize linked list pointers
	    BorrowNode* head =NULL;
	    BorrowNode* tail =NULL;
		//read data from file
	    string line;
	    while (getline(file, line)) {
	        if (line.empty()) {
	        	continue;
			}
	
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
			// Convert returned status to boolean
	        bool returned = (returnedStr == "1");
			
	        if (returned) {
	        	// Create new node for the borrowed magazine
	            BorrowNode* newNode = new BorrowNode{
	                userId, bookId, title, author, borrowDate, returnDate,
	                stoi(yearStr), returned, nullptr
	            };
	            
	            //add to linked list
	            if (!head) 
				{
	                head = tail = newNode;
	            } 
				else {
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
         << setw(12) << "User ID" << setw(15) << "Magazine ID" << setw(30) << "Title" << setw(20) << "Author" << setw(20) << "Borrow Date" << setw(15) << "Return Date" << setw(10) << "Returned"
         << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
	//travels linked list and display data
    BorrowNode* current = head;
    while (current){
        cout << left
             <<setw(12) << current->userId
             <<setw(15) << current->bookId
             <<setw(30) << current->title.substr(0, 28)
             << setw(20) << current->author.substr(0, 18)
             << setw(20) << current->borrowDate
             << setw(15) << current->returnDate
             << setw(10) << (current->returned ? "Yes" : "No")
             << endl;
        current =current->next;
    }

    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
		//clean linked list memory
	    while (head) {
	        BorrowNode* temp =head;
	        head = head->next;
	        delete temp;
	    }
	    //ask user generate report or not
	    char choice;
			cout<< "\n\nDo you need to generate a Borrowed Books Record Report? (Y or N) :";
			cin>>choice;
			
			if(toupper(choice) =='Y'){
				//get filter year and month
				int yearFilter, monthFilter;
			    cout << "Enter the YEAR to filter by (example: 2024): ";
			    cin >> yearFilter;
			    cout << "Enter the MONTH to filter by (1 - 12): ";
			    cin >> monthFilter;
			    cin.ignore();
			    
			    //reopen file to filtering
			    ifstream file("borrowedMagazines.txt");  
				if (!file) {
				    cout << "Error opening borrowedBook.txt file again!\n";
				    return;
				}

				// Lambda function to extract month from date string
			    auto extractYear = [](const string& dateStr) -> int 
				{
			        if (dateStr.length() < 4) 
					{
			        	return -1;
					}
			        return stoi(dateStr.substr(0, 4));
			    };
			    
			    auto extractMonth = [](const string& dateStr) -> int 
				{
			        if (dateStr.length() < 7) 
					{
			        	return -1;
					}
			        return stoi(dateStr.substr(5, 2));
			    };
				//initialize new linked list for filtered result
			    BorrowNode* head =NULL;
			    BorrowNode* tail =NULL;
			
			    string line;
			    while (getline(file, line)) {
			        if (line.empty()){
			        	continue;
					} 
			
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
			
			        if (returned && y == yearFilter && m == monthFilter) 
					{
			            BorrowNode* newNode = new BorrowNode{ userId, bookId, title, author, borrowDate, returnDate, stoi(yearStr), returned, nullptr };
			            if (!head) 
						{
			                head = tail = newNode; //first node
			            } 
						else {
			                tail->next = newNode; //append to end
			                tail = newNode;
			            }
			        }
			    }
			    file.close();
				//diaplay filter result
			    cout << "\nBorrowed Magazine Records - " << yearFilter << "/" << (monthFilter < 10 ? "0" : "") << monthFilter << "\n";
			    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
			    cout << left
			         << setw(12) << "User ID" << setw(15) << "Magazine ID" << setw(30) << "Title" << setw(20) << "Author" << setw(20) << "Borrow Date" << setw(15) << "Return Date" << setw(10) << "Returned" << endl;
			    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
			
			    BorrowNode* current = head;
			    while (current) {
			        cout <<left
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
					//generate report file
			        string filename = "borrowedMagazineHistoryReport.txt";
			        ofstream report(filename);
			        if (report) {
			            report << "Borrowed Magazine History - " << yearFilter << "/" << (monthFilter < 10 ? "0" : "") << monthFilter << "\n";
			            report << "-------------------------------------------------------------------------------------------------------------------------\n";
			            report << left << setw(12) << "User ID" << setw(15) << "Magazine ID" << setw(30) << "Title" << setw(20) << "Author" << setw(20) << "Borrow Date" << setw(15) << "Return Date" << setw(10) << "Returned"
			                   << endl;
			            report << "-------------------------------------------------------------------------------------------------------------------------\n";
			            // write each record to the report file
			            current = head;
			            while (current) {
			                report <<left
			                       <<setw(12) << current->userId
			                       <<setw(15) << current->bookId
			                       << setw(30) << current->title.substr(0, 28)
			                       << setw(20) << current->author.substr(0, 18)
			                       << setw(20) << current->borrowDate
			                       << setw(15) << current->returnDate
			                       << setw(10) << "Yes"
			                       << endl;
			                current = current->next;
			            }
			            report <<"-------------------------------------------------------------------------------------------------------------------------\n";
			            report.close();
			            cout << "Report saved as '" << filename << "'.\n";
			    }
				// Clean up filtered linked list
			    while (head) 
				{
			        BorrowNode* temp =head;
			        head =head->next;
			        delete temp;
			    }
			}
	    
	    cout << "\nPress Enter to Continue...";
		cin.ignore(); 
		cin.get();    
	}

    // Implementation outside the class
    void searchHelper(BookRecord& records, const string& query, bool searchTitle, bool searchAuthor, bool searchId) {
    // Check if database is empty
    if (records.head == nullptr) {
        cout << "No records found in the database.\n";
        return;
    }
    // Display search header
        cout << "  ____________\n";
	    cout << "  |  _       |\n";
	    cout << "  | | |      |\n";
	    cout << "  | | |___   |\n";
	    cout << "  | |_____|  |\n";
	    cout << "  |__________|\n\n";
	    cout << "     JR Library\n";
	    cout << "JR Library Management System\n";
	    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                                                               Search Results\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        cout << string(80, '=') << "\n";
        cout << left << setw(8) << "ID" 
         << setw(25) << "Title" 
         << setw(20) << "Author" 
         << setw(8) << "Year" 
         << setw(12) << "Status" << "\n";
    cout << string(80, '-') << "\n";
    // Initialize variables
    bool found = false;
    BookRecord::BookNode* current = records.head;
    // Traverse the linked list
    while (current != nullptr) {
        bool isMatch = false;
        // Check matching criteria
        if (searchId && current->id.find(query) != string::npos) {
            isMatch = true;
        }
        if (searchTitle && current->title.find(query) != string::npos) {
            isMatch = true;
        }
        if (searchAuthor && current->author.find(query) != string::npos) {
            isMatch = true;
        }
        // Display matching record
        if (isMatch) {
            string displayTitle = current->title.length() > 22 ? 
                                current->title.substr(0, 22) + "..." : current->title;
            string displayAuthor = current->author.length() > 17 ? 
                                 current->author.substr(0, 17) + "..." : current->author;
            string status = current->available ? "Available" : "Borrowed";
            
            cout << left << setw(8) << current->id
                 << setw(25) << displayTitle
                 << setw(20) << displayAuthor
                 << setw(8) << current->year
                 << setw(12) << status << "\n";
            
            found = true;
        }
        // Move to next node
        current = current->next;
    }
    // Display footer
    cout << string(80, '=') << "\n";
    if (!found) {
        cout << "No matching records found for your search criteria.\n";
    } else {
        cout << "Search completed successfully.\n";
    }
    cout << "\n";
    }
};




class Customer : public Person {

friend class Admin;

private: 
	string keyword;  // for password reset
    Customer* currentUser = nullptr;  // Added for tracking current user

    struct CustomerNode {
        Customer* customer;
        CustomerNode* next;
        CustomerNode(Customer* c) : customer(c), next(nullptr) {}
    };
    
    CustomerNode* head;
    
    // Structures for borrowed items
    struct BorrowBook {
        string uid;
        string id;
        string title;
        string author;
        int year;
        string borrowDate;
        string returnDate;
        bool available;
        BorrowBook* next;
    };
    
    BorrowBook* head1 = nullptr;
    
    struct BorrowMagazine {
        string uid;
        string id;
        string title;
        string author;
        int year;
        string borrowDate;
        string returnDate;
        bool available;
        BorrowMagazine* next;
    };
    
    BorrowMagazine* head2 = nullptr;
    

    
public:
    Customer() : currentUser(nullptr), head(nullptr), head1(nullptr), head2(nullptr) {}

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
                currentUser = temp->customer;  // Set the current user
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
    
    //view borrowed book
	void viewBorrowedBooks() {
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
	    cout << "                                                               Your Borrowed Books\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	
	    if (currentUser == nullptr) {
	        cout << "Please log in first.\n";
	        cin.get();
	        return;
	    }
	
	    string userId = currentUser->getID();
	    
	    // Structure to hold borrowed book records (similar to returnBook())
	    struct BorrowedBook {
	        string uid;
	        string id;
	        string title;
	        string author;
	        int year;
	        string borrowDate;
	        string returnDate;
	        bool returned;
	        BorrowedBook* next;
	    };
	
	    BorrowedBook* head = nullptr;
	    BorrowedBook* tail = nullptr;
	    bool found = false;
	
	    // Read borrowed books file
	    ifstream file("borrowedBook.txt");
	    if (file.is_open()) {
	        string line;
	        while (getline(file, line)) {
	            if (line.empty()) continue;
	
	            stringstream ss(line);
	            string uid, id, title, author, yearStr, borrowDate, returnDate, returnedStr;
	
	            getline(ss, uid, ',');
	            getline(ss, id, ',');
	            getline(ss, title, ',');
	            getline(ss, author, ',');
	            getline(ss, yearStr, ',');
	            getline(ss, borrowDate, ',');
	            getline(ss, returnDate, ',');
	            getline(ss, returnedStr, ',');
	
	            // Create new borrowed book record
	            BorrowedBook* newBook = new BorrowedBook{
	                uid, id, title, author, stoi(yearStr), 
	                borrowDate, returnDate, (returnedStr == "1"), nullptr
	            };
	
	            // Add to linked list
	            if (!head) {
	                head = tail = newBook;
	            } else {
	                tail->next = newBook;
	                tail = newBook;
	            }
	        }
	        file.close();
	    } else {
	        cout << "No borrowed books found.\n";
	        cin.get();
	        return;
	    }
	
	    // Display borrowed books
	    cout << "\nBorrowed Books:\n";
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	    cout << "ID\t\tTitle\t\t\t\tAuthor\t\t\tBorrow Date\t\tReturn Date\n";
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	
	    BorrowedBook* current = head;
	    while (current) {
	        if (current->uid == userId && !current->returned) {
	            found = true;
	            cout << left << setw(10) << current->id << "\t"
	                 << left << setw(25) << 
	                    (current->title) << "\t"
	                 << left << setw(20) << 
	                    (current->author) << "\t"
	                 << current->borrowDate << "\t\t"
	                 << current->returnDate << endl;
	        }
	        current = current->next;
	    }
	
	    if (!found) {
	        cout << "No borrowed books found.\n";
	    }
	
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	
	    // Clean up memory
	    while (head) {
	        BorrowedBook* temp = head;
	        head = head->next;
	        delete temp;
	    }
	
	    cout << "\nPress Enter to continue...";
	    cin.get();
	}


//view borrowed magazine
	void viewBorrowedMagazines() {
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
	    cout << "                                                               Your Borrowed Magazines\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	
	    if (currentUser == nullptr) {
	        cout << "Please log in first.\n";
	        cin.get();
	        return;
	    }
	
	    string userId = currentUser->getID();
	    
	    // Structure to hold borrowed book records (similar to returnBook())
	    struct BorrowedBook {
	        string uid;
	        string id;
	        string title;
	        string author;
	        int year;
	        string borrowDate;
	        string returnDate;
	        bool returned;
	        BorrowedBook* next;
	    };
	
	    BorrowedBook* head = nullptr;
	    BorrowedBook* tail = nullptr;
	    bool found = false;
	
	    // Read borrowed books file
	    ifstream file("borrowedMagazines.txt");
	    if (file.is_open()) {
	        string line;
	        while (getline(file, line)) {
	            if (line.empty()) continue;
	
	            stringstream ss(line);
	            string uid, id, title, author, yearStr, borrowDate, returnDate, returnedStr;
	
	            getline(ss, uid, ',');
	            getline(ss, id, ',');
	            getline(ss, title, ',');
	            getline(ss, author, ',');
	            getline(ss, yearStr, ',');
	            getline(ss, borrowDate, ',');
	            getline(ss, returnDate, ',');
	            getline(ss, returnedStr, ',');
	
	            // Create new borrowed book record
	            BorrowedBook* newBook = new BorrowedBook{
	                uid, id, title, author, stoi(yearStr), 
	                borrowDate, returnDate, (returnedStr == "1"), nullptr
	            };
	
	            // Add to linked list
	            if (!head) {
	                head = tail = newBook;
	            } else {
	                tail->next = newBook;
	                tail = newBook;
	            }
	        }
	        file.close();
	    } else {
	        cout << "No borrowed books found.\n";
	        cin.get();
	        return;
	    }
	
	    // Display borrowed books
	    cout << "\nBorrowed Books:\n";
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	    cout << "ID\t\tTitle\t\t\t\tAuthor\t\t\tBorrow Date\t\tReturn Date\n";
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	
	    BorrowedBook* current = head;
	    while (current) {
	        if (current->uid == userId && !current->returned) {
	            found = true;
	            cout << left << setw(10) << current->id << "\t"
	                 << left << setw(25) << 
	                    (current->title) << "\t"
	                 << left << setw(20) << 
	                    (current->author) << "\t"
	                 << current->borrowDate << "\t\t"
	                 << current->returnDate << endl;
	        }
	        current = current->next;
	    }
	
	    if (!found) {
	        cout << "No borrowed books found.\n";
	    }
	
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	
	    // Clean up memory
	    while (head) {
	        BorrowedBook* temp = head;
	        head = head->next;
	        delete temp;
	    }
	
	    cout << "\nPress Enter to continue...";
	    cin.get();
	}

    
    void borrowBook() {
    	system("cls");
    	CustomerNode* temp = head;
        string userId = "";
        while (temp != nullptr) {
            if (temp->customer == currentUser) {
                userId = temp->customer->getID();
                break;
            }
            temp = temp->next;
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
        cout << "                                                                       Borrow Book\n\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";

        // Get book ID from user
        string bookId;
        cout << "Enter Book ID to borrow: ";
        getline(cin, bookId);

        // Read books from file
        ifstream bookFile("books.txt");
        if (!bookFile) {
            cerr << "Error opening books file!\n";
            return;
        }

        // Temporary linked list for books
        struct BookNode {
            string id;
            string title;
            string author;
            string year;
            string available;
            BookNode* next;
        };
        
        BookNode* bookHead = nullptr;
        BookNode* bookTail = nullptr;
        string line;
        bool bookFound = false;
        bool bookAvailable = false;
        string bookTitle, bookAuthor, bookYear;

        // Read books and build linked list
        while (getline(bookFile, line)) {
            if (line.empty()) continue;
            
            stringstream ss(line);
            string id, title, author, year, available;
            getline(ss, id, ',');
            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, year, ',');
            getline(ss, available, ',');

            // Create new book node
            BookNode* newBook = new BookNode{id, title, author, year, available, nullptr};
            
            // Add to list
            if (!bookHead) {
                bookHead = bookTail = newBook;
            } else {
                bookTail->next = newBook;
                bookTail = newBook;
            }
            
            // Check if this is the requested book
            if (id == bookId) {
                bookFound = true;
                if (available == "1") {
                    bookAvailable = true;
                    bookTitle = title;
                    bookAuthor = author;
                    bookYear = year;
                }
            }
        }
        bookFile.close();

        if (!bookFound) {
            cout << "Book with ID " << bookId << " not found.\n";
            
            // Clean up linked list
            while (bookHead) {
                BookNode* temp = bookHead;
                bookHead = bookHead->next;
                delete temp;
            }
            
            cin.get();
            return;
        }

        if (!bookAvailable) {
            cout << "Book is already borrowed by someone else.\n";
            
            // Clean up linked list
            while (bookHead) {
                BookNode* temp = bookHead;
                bookHead = bookHead->next;
                delete temp;
            }
            
            cin.get();
            return;
        }

        // Calculate borrowing dates
        time_t now = time(nullptr);
        tm* ltm = localtime(&now);
        
        // Format: YYYY-MM-DD
        string borrowDate = 
            to_string(1900 + ltm->tm_year) + "-" +
            (ltm->tm_mon + 1 < 10 ? "0" : "") + to_string(ltm->tm_mon + 1) + "-" +
            (ltm->tm_mday < 10 ? "0" : "") + to_string(ltm->tm_mday);
    
        string returnDate = "-";

        // Update book status to borrowed in the books.txt file
        ofstream outFile("books.txt");
        if (!outFile) {
            cerr << "Error opening books file for writing!\n";
            
            // Clean up linked list
            while (bookHead) {
                BookNode* temp = bookHead;
                bookHead = bookHead->next;
                delete temp;
            }
            
            return;
        }
        
        BookNode* current = bookHead;
        while (current) {
            string availStatus = (current->id == bookId) ? "0" : current->available;
            outFile << current->id << "," 
                   << current->title << "," 
                   << current->author << "," 
                   << current->year << "," 
                   << availStatus << ",\n";
            current = current->next;
        }
        outFile.close();
        
        // Add borrowing record to borrowedBook.txt
        ofstream borrowFile("borrowedBook.txt", ios::app);
        if (!borrowFile) {
            cerr << "Error opening borrowed books file!\n";
            
            // Clean up linked list
            while (bookHead) {
                BookNode* temp = bookHead;
                bookHead = bookHead->next;
                delete temp;
            }
            
            return;
        }
        
        borrowFile << userId << "," 
                   << bookId << ","
                   << bookTitle << ","
                   << bookAuthor << ","
                   << bookYear << ","
                   << borrowDate << ","
                   << returnDate << ","
                  << "0,\n";  // 0 means not returned yet
        borrowFile.close();

        // Clean up linked list
        while (bookHead) {
            BookNode* temp = bookHead;
            bookHead = bookHead->next;
            delete temp;
        }
        
        cout << "\nBook borrowed successfully!\n";
        cout << "Borrow Date: " << borrowDate << "\n";
        cin.ignore();
        cin.get();
    }
    
    void borrowMagazine() {
    	system("cls");
	    CustomerNode* temp = head;
	    string userId = "";
	    while (temp != nullptr) {
	        if (temp->customer == currentUser) {
	            userId = temp->customer->getID();
	            break;
	        }
	        temp = temp->next;
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
	    cout << "                                                                       Borrow Magazine\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	
	    
	    string magazineId;
	    cout << "Enter Magazine ID to borrow: ";
	    getline(cin, magazineId);
	
	    
	    ifstream magazineFile("magazine.txt");
	    if (!magazineFile) {
	        cerr << "Error opening magazine file!\n";
	        return;
	    }
	
	    
	    struct MagazineNode {
	        string id;
	        string title;
	        string author;
	        string year;
	        string available;
	        MagazineNode* next;
	    };
	
	    
	    MagazineNode* magazineHead = nullptr;
	    MagazineNode* magazineTail = nullptr;
	
	    string line;
	    bool magazineFound = false;
	    bool magazineAvailable = false;
	    string magazineTitle, magazineAuthor, magazineYear;
	
	    while (getline(magazineFile, line)) {
	        if (line.empty()) continue;
	        
	        stringstream ss(line);
	        string id, title, author, year, available;
	        getline(ss, id, ',');
	        getline(ss, title, ',');
	        getline(ss, author, ',');
	        getline(ss, year, ',');
	        getline(ss, available, ',');
	
	        MagazineNode* newMagazine = new MagazineNode{id, title, author, year, available, nullptr};
	        
	        if (!magazineHead) {
	            magazineHead = magazineTail = newMagazine;
	        } else {
	            magazineTail->next = newMagazine;
	            magazineTail = newMagazine;
	        }
	        
	        if (id == magazineId) {
	            magazineFound = true;
	            if (available == "1") {
	                magazineAvailable = true;
	                magazineTitle = title;
	                magazineAuthor = author;
	                magazineYear = year;
	            }
	        }
	    }
	    magazineFile.close();
	
	    if (!magazineFound) {
	        cout << "Magazine with ID " << magazineId << " not found.\n";
	        while (magazineHead) {
	            MagazineNode* temp = magazineHead;
	            magazineHead = magazineHead->next;
	            delete temp;
	        }
	        cin.get();
	        return;
	    }
	
	        if (!magazineAvailable) {
	        cout << "Magazine is already borrowed.\n";
	            while (magazineHead) {
	                MagazineNode* temp = magazineHead;
	                magazineHead = magazineHead->next;
	                delete temp;
	            }
	        cin.get();
	            return;
	        }
	
	    
	    time_t now = time(nullptr);
	    tm* ltm = localtime(&now);
	    string borrowDate = 
	        to_string(1900 + ltm->tm_year) + "-" +
	        (ltm->tm_mon + 1 < 10 ? "0" : "") + to_string(ltm->tm_mon + 1) + "-" +
	        (ltm->tm_mday < 10 ? "0" : "") + to_string(ltm->tm_mday);
	    string returnDate = "-";
	
	    
	    ofstream outMagFile("magazine.txt");
	    if (!outMagFile) {
	        cerr << "Error opening magazine file for writing!\n";
	        while (magazineHead) {
	            MagazineNode* temp = magazineHead;
	            magazineHead = magazineHead->next;
	            delete temp;
	        }
	        return;
	    }
	
	    MagazineNode* current = magazineHead;
	    while (current) {
	        string availStatus = (current->id == magazineId) ? "0" : current->available;
	        outMagFile << current->id << ","
	                   << current->title << ","
	                   << current->author << ","
	                   << current->year << ","
	                   << availStatus << ",\n";
	        current = current->next;
	    }
	    outMagFile.close();
	
	    
	    ofstream borrowFile("borrowedMagazines.txt", ios::app);
	    if (!borrowFile) {
	        cerr << "Error opening borrowed magazines file!\n";
	        while (magazineHead) {
	            MagazineNode* temp = magazineHead;
	            magazineHead = magazineHead->next;
	            delete temp;
	        }
	        return;
	    }
	
	    borrowFile << userId << ","
	               << magazineId << ","
	               << magazineTitle << ","
	               << magazineAuthor << ","
	               << magazineYear << ","
	               << borrowDate << ","
	               << returnDate << ","
	               << "0,\n"; 
	    borrowFile.close();
	
	    while (magazineHead) {
	        MagazineNode* temp = magazineHead;
	    	magazineHead = magazineHead->next;
	        delete temp;
	    }
	
	    cout << "\nMagazine borrowed successfully!\n";
	    cout << "Borrow Date: " << borrowDate << "\n";
	    cin.ignore();
	    cin.get();
}
    
    	
    void returnBook() {
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
	    cout << "                                                                       Return Book\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	
	    // Check if user is logged in
    if (currentUser == nullptr) {
        cout << "Please log in first.\n";
	        cin.get();
	        return;
	    }
	
    string userId = currentUser->getID();
    
    // Display borrowed books
    cout << "\nYour Borrowed Books:\n";
    cout << "------------------------------------------------------------------------------------------------------------------\n";
    cout << "ID\t\tTitle\t\t\t\tAuthor\t\t\tBorrow Date\t\tReturn Date\n";
    cout << "------------------------------------------------------------------------------------------------------------------\n";

    // Read borrowed books file
    ifstream borrowedFile("borrowedBook.txt");
    if (!borrowedFile) {
        cout << "You have no borrowed books.\n";
	        cin.get();
	        return;
	    }
	
    // Temporary structure to hold borrowed records
	    struct TempBorrow {
	        string uid;
	        string id;
	        string title;
	        string author;
	        int year;
	        string borrowDate;
	        string returnDate;
	        bool returned;
	        TempBorrow* next;
	    };
	
    TempBorrow* borrowHead = nullptr;
    TempBorrow* borrowTail = nullptr;
    bool hasBorrowedBooks = false;

    string line;
    while (getline(borrowedFile, line)) {
	        stringstream ss(line);
	        string uid, id, title, author, yearStr, borrowDate, returnDate, returnedStr;
	        
        // Parse the line
	        getline(ss, uid, ',');
	        getline(ss, id, ',');
	        getline(ss, title, ',');
	        getline(ss, author, ',');
	        getline(ss, yearStr, ',');
	        getline(ss, borrowDate, ',');
	        getline(ss, returnDate, ',');
        getline(ss, returnedStr, ',');

        // Create new borrow record
        TempBorrow* newBorrow = new TempBorrow{
            uid, id, title, author, stoi(yearStr), borrowDate, returnDate, 
            (returnedStr == "1"), nullptr
        };
        
        // Add to list
        if (!borrowHead) {
            borrowHead = borrowTail = newBorrow;
	        } else {
            borrowTail->next = newBorrow;
            borrowTail = newBorrow;
        }
        
        // Display only current user's unreturned books
        if (uid == userId && returnedStr == "0") {
            hasBorrowedBooks = true;
            cout << id << "\t\t" 
                 << title << "\t\t\t" 
                 << author << "\t\t\t" 
                 << borrowDate << "\t" 
                 << returnDate << endl << endl;
        }
    }
    borrowedFile.close();

    if (!hasBorrowedBooks) {
        cout << "You have no borrowed books to return.\n";
        
        // Clean up the linked list
        while (borrowHead) {
            TempBorrow* temp = borrowHead;
            borrowHead = borrowHead->next;
            delete temp;
        }
        
        cin.get();
        return;
    }

    // Get book ID to return
    string idToReturn;
    cout << "\nEnter Book ID to return: ";
    getline(cin, idToReturn);

    // Check if the user has borrowed this book
    bool hasBookBorrowed = false;
    TempBorrow* current = borrowHead;
    while (current) {
        if (current->uid == userId && current->id == idToReturn && !current->returned) {
            hasBookBorrowed = true;
	            break;
	        }
	        current = current->next;
	    }
	
    if (!hasBookBorrowed) {
        cout << "You haven't borrowed this book or it's already returned.\n";
        
        // Clean up the linked list
        while (borrowHead) {
            TempBorrow* temp = borrowHead;
            borrowHead = borrowHead->next;
	            delete temp;
	    }
	
	        cin.get();
	        return;
	    }
	
    // Update the book's availability in books.txt
	    struct BookNode {
	        string id;
	        string title;
	        string author;
	        string year;
	        string available;
	        BookNode* next;
	    };
	
	    BookNode* bookHead = nullptr;
	    BookNode* bookTail = nullptr;
	
    ifstream bookFile("books.txt");
    if (bookFile) {
	    while (getline(bookFile, line)) {
	        stringstream ss(line);
	        string id, title, author, year, available;
            
	        getline(ss, id, ',');
	        getline(ss, title, ',');
	        getline(ss, author, ',');
	        getline(ss, year, ',');
	        getline(ss, available, ',');
	
	        BookNode* newBook = new BookNode{id, title, author, year, available, nullptr};
	
	        if (!bookHead) {
	            bookHead = bookTail = newBook;
	        } else {
	            bookTail->next = newBook;
	            bookTail = newBook;
	        }
	    }
	    bookFile.close();
	
        // Update the book status
        BookNode* bookNode = bookHead;
        bool bookFound = false;
        while (bookNode) {
            if (bookNode->id == idToReturn) {
                bookNode->available = "1"; // Mark as available
                bookFound = true;
	            break;
	        }
            bookNode = bookNode->next;
        }
        
        if (!bookFound) {
            cout << "Warning: Book ID not found in books.txt. Status not updated.\n";
        }
        
        // Write back to the file
        ofstream outBookFile("books.txt");
        if (outBookFile) {
            bookNode = bookHead;
            while (bookNode) {
                outBookFile << bookNode->id << ","
                           << bookNode->title << ","
                           << bookNode->author << ","
                           << bookNode->year << ","
                           << bookNode->available << ",\n";
                bookNode = bookNode->next;
            }
            outBookFile.close();
        } else {
            cout << "Error: Could not open books.txt for writing.\n";
        }
        
        // Clean up the book linked list
        while (bookHead) {
            BookNode* temp = bookHead;
            bookHead = bookHead->next;
            delete temp;
        }
    } else {
        cout << "Error: Could not open books.txt for reading.\n";
    }

    // Update the borrowed file to mark the book as returned
    current = borrowHead;
	    while (current) {
        if (current->uid == userId && current->id == idToReturn && !current->returned) {
            current->returned = true;
            
            time_t now = time(nullptr);
            tm* ltm = localtime(&now);
            current->returnDate =
                to_string(1900 + ltm->tm_year) + "-" +
                (ltm->tm_mon + 1 < 10 ? "0" : "") + to_string(ltm->tm_mon + 1) + "-" +
                (ltm->tm_mday < 10 ? "0" : "") + to_string(ltm->tm_mday);
        
            break;
        }
        current = current->next;
    }

    // Write back to borrowed file
    ofstream outBorrowFile("borrowedBook.txt");
    if (outBorrowFile) {
        current = borrowHead;
        
        while (current) {
            outBorrowFile << current->uid << ","
	                 << current->id << ","
	                 << current->title << ","
	                 << current->author << ","
	                 << current->year << ","
	                 << current->borrowDate << ","
	                 << current->returnDate << ","
                         << (current->returned ? "1" : "0") << ",\n";
	        current = current->next;
	    }
        outBorrowFile.close();
        cout << "\nBook returned successfully!\n";
    } else {
        cout << "\nError updating borrowed books record!\n";
    }

    // Clean up the borrow linked list
    while (borrowHead) {
        TempBorrow* temp = borrowHead;
        borrowHead = borrowHead->next;
	        delete temp;
	    }
	
    cout << "\nPress Enter to continue...";
	    cin.get();
	}

	void returnMagazine() {
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
	    cout << "                                                                       Return Magazine\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	
    // Check if user is logged in
    if (currentUser == nullptr) {
        cout << "Please log in first.\n";
        cin.get();
        return;
    }

    string userId = currentUser->getID();
    
    // Display borrowed magazines
    cout << "\nYour Borrowed Magazines:\n";
    cout << "------------------------------------------------------------------------------------------------------------------\n";
    cout << "ID\t\tTitle\t\t\t\tAuthor\t\t\tBorrow Date\t\tReturn Date\n";
    cout << "------------------------------------------------------------------------------------------------------------------\n";

    // Read borrowed magazines file
    ifstream borrowedFile("borrowedMagazines.txt");
    if (!borrowedFile) {
        cout << "You have no borrowed magazines.\n";
        cin.get();
	        return;
	    }
	
    // Temporary structure to hold borrowed records
    struct TempBorrow {
	        string uid;
	        string id;
	        string title;
	        string author;
        int year;
	        string borrowDate;
	        string returnDate;
        bool returned;
        TempBorrow* next;
    };

    TempBorrow* borrowHead = nullptr;
    TempBorrow* borrowTail = nullptr;
    bool hasBorrowedMagazines = false;

	    string line;
    while (getline(borrowedFile, line)) {
	        stringstream ss(line);
        string uid, id, title, author, yearStr, borrowDate, returnDate, returnedStr;
	
        // Parse the line
	        getline(ss, uid, ',');
	        getline(ss, id, ',');
	        getline(ss, title, ',');
	        getline(ss, author, ',');
        getline(ss, yearStr, ',');
	        getline(ss, borrowDate, ',');
	        getline(ss, returnDate, ',');
        getline(ss, returnedStr, ',');

        // Create new borrow record
        TempBorrow* newBorrow = new TempBorrow{
            uid, id, title, author, stoi(yearStr), borrowDate, returnDate, 
            (returnedStr == "1"), nullptr
        };
        
        // Add to list
        if (!borrowHead) {
            borrowHead = borrowTail = newBorrow;
	        } else {
            borrowTail->next = newBorrow;
            borrowTail = newBorrow;
        }
        
        // Display only current user's unreturned magazines
        if (uid == userId && returnedStr == "0") {
            hasBorrowedMagazines = true;
            cout << id << "\t\t" 
                 << title << "\t\t\t" 
                 << author << "\t\t" 
                 << borrowDate << "\t" 
                 << returnDate << endl << endl;
        }
    }
    borrowedFile.close();

    if (!hasBorrowedMagazines) {
        cout << "You have no borrowed magazines to return.\n";
        
        // Clean up the linked list
        while (borrowHead) {
            TempBorrow* temp = borrowHead;
            borrowHead = borrowHead->next;
	            delete temp;
	        }
        
        cin.get();
	        return;
	    }
	
    // Get magazine ID to return
    string idToReturn;
    cout << "\nEnter Magazine ID to return: ";
    getline(cin, idToReturn);

    // Check if the user has borrowed this magazine
    bool hasMagazineBorrowed = false;
    TempBorrow* current = borrowHead;
    while (current) {
        if (current->uid == userId && current->id == idToReturn && !current->returned) {
            hasMagazineBorrowed = true;
            break;
        }
        current = current->next;
    }

    if (!hasMagazineBorrowed) {
        cout << "You haven't borrowed this magazine or it's already returned.\n";
        
        // Clean up the linked list
        while (borrowHead) {
            TempBorrow* temp = borrowHead;
            borrowHead = borrowHead->next;
            delete temp;
        }
        
        cin.get();
	        return;
	    }
	
    // Update the magazine's availability in magazine.txt
    struct MagazineNode {
	        string id;
	        string title;
	        string author;
	        string year;
	        string available;
        MagazineNode* next;
    };

    MagazineNode* magazineHead = nullptr;
    MagazineNode* magazineTail = nullptr;
    
    ifstream magazineFile("magazine.txt");
    if (magazineFile) {
        while (getline(magazineFile, line)) {
	        stringstream ss(line);
	        string id, title, author, year, available;
            
	        getline(ss, id, ',');
	        getline(ss, title, ',');
	        getline(ss, author, ',');
	        getline(ss, year, ',');
	        getline(ss, available, ',');
	
            MagazineNode* newMagazine = new MagazineNode{id, title, author, year, available, nullptr};
	
            if (!magazineHead) {
                magazineHead = magazineTail = newMagazine;
	        } else {
                magazineTail->next = newMagazine;
                magazineTail = newMagazine;
            }
        }
        magazineFile.close();
        
        // Update the magazine status
        MagazineNode* magazineNode = magazineHead;
        bool magazineFound = false;
        while (magazineNode) {
            if (magazineNode->id == idToReturn) {
                magazineNode->available = "1"; // Mark as available
                magazineFound = true;
                break;
            }
            magazineNode = magazineNode->next;
        }
        
        if (!magazineFound) {
            cout << "Warning: Magazine ID not found in magazine.txt. Status not updated.\n";
        }
        
        // Write back to the file
        ofstream outMagazineFile("magazine.txt");
        if (outMagazineFile) {
            magazineNode = magazineHead;
            while (magazineNode) {
                outMagazineFile << magazineNode->id << ","
                               << magazineNode->title << ","
                               << magazineNode->author << ","
                               << magazineNode->year << ","
                               << magazineNode->available << ",\n";
                magazineNode = magazineNode->next;
            }
            outMagazineFile.close();
        } else {
            cout << "Error: Could not open magazine.txt for writing.\n";
        }
        
        // Clean up the magazine linked list
        while (magazineHead) {
            MagazineNode* temp = magazineHead;
            magazineHead = magazineHead->next;
            delete temp;
        }
    } else {
        cout << "Error: Could not open magazine.txt for reading.\n";
    }

    // Update the borrowed file to mark the magazine as returned
    current = borrowHead;
	    while (current) {
        if (current->uid == userId && current->id == idToReturn && !current->returned) {
            current->returned = true;
            
            time_t now = time(nullptr);
            tm* ltm = localtime(&now);
            current->returnDate =
                to_string(1900 + ltm->tm_year) + "-" +
                (ltm->tm_mon + 1 < 10 ? "0" : "") + to_string(ltm->tm_mon + 1) + "-" +
                (ltm->tm_mday < 10 ? "0" : "") + to_string(ltm->tm_mday);
        
            break;
        }
        current = current->next;
    }

    // Write back to borrowed file
    ofstream outBorrowFile("borrowedMagazines.txt");
    if (outBorrowFile) {
        current = borrowHead;
        
        while (current) {
            outBorrowFile << current->uid << ","
	               << current->id << ","
	               << current->title << ","
	               << current->author << ","
	               << current->year << ","
	               << current->borrowDate << ","
	               << current->returnDate << ","
                         << (current->returned ? "1" : "0") << ",\n";
	        current = current->next;
	    }
        outBorrowFile.close();
        cout << "\nMagazine returned successfully!\n";
    } else {
        cout << "\nError updating borrowed magazines record!\n";
    }

    // Clean up the borrow linked list
    while (borrowHead) {
        TempBorrow* temp = borrowHead;
        borrowHead = borrowHead->next;
        delete temp;
    }
    
    cout << "\nPress Enter to continue...";
    cin.get();
}

	void viewBorrowHistory() {
		
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
	    cout << "                                                                       My Borrowing History\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	
	    // Check if user is logged in
	    if (!currentUser) {
	        cout << "Error: No user logged in!\n";
	        cin.get();
	        return;
	    }
	
	    string currentID = currentUser->getID();
	    int totalCount = 0;
	    int count = 1;
	
	    // Display books history
	    cout << "Book Borrowing History:\n\n";
	    cout << setw(5) << "No." << setw(15) << "Book ID" << setw(30) << "Title" 
	         << setw(25) << "Author" << setw(15) << "Borrow Date" << setw(15) << "Return Date" << "\n";
	    cout << string(100, '-') << "\n";
	
	    // Read book history
	    ifstream bookFile("borrowedBook.txt");
	    string line;
	    bool bookFound = false;
	
	    while (getline(bookFile, line)) {
	        if (line.empty()) continue;
	
	        stringstream ss(line);
	        string uid, id, title, author, yearStr, borrowDate, returnDate, returnedStr;
	        
	        getline(ss, uid, ',');
	        getline(ss, id, ',');
	        getline(ss, title, ',');
	        getline(ss, author, ',');
	        getline(ss, yearStr, ',');
	        getline(ss, borrowDate, ',');
	        getline(ss, returnDate, ',');
	        getline(ss, returnedStr, ',');
	
	        if (uid == currentID && returnedStr == "1") {
	            bookFound = true;
	            totalCount++;
	            cout << setw(5) << count++ 
	                 << setw(15) << id 
	                 << setw(30) << (title.length() > 28 ? title.substr(0, 25) + "..." : title)
	                 << setw(25) << (author.length() > 23 ? author.substr(0, 20) + "..." : author)
	                 << setw(15) << borrowDate
	                 << setw(15) << returnDate << "\n";
	        }
	    }
	    bookFile.close();
	
	    if (!bookFound) {
	        cout << "No book borrowing history found.\n";
	    }
	
	    // Display magazines history
	    count = 1;  // Reset count for magazines
	    cout << "\n\nMagazine Borrowing History:\n\n";
	    cout << setw(5) << "No." << setw(15) << "Magazine ID" << setw(30) << "Title" 
	         << setw(25) << "Author" << setw(15) << "Borrow Date" << setw(15) << "Return Date" << "\n";
	    cout << string(100, '-') << "\n";
	
	    // Read magazine history
	    ifstream magazineFile("borrowedMagazines.txt");
	    bool magazineFound = false;
	
	    while (getline(magazineFile, line)) {
	        if (line.empty()) continue;
	
	        stringstream ss(line);
	        string uid, id, title, author, yearStr, borrowDate, returnDate, returnedStr;
	        
	        getline(ss, uid, ',');
	        getline(ss, id, ',');
	        getline(ss, title, ',');
	        getline(ss, author, ',');
	        getline(ss, yearStr, ',');
	        getline(ss, borrowDate, ',');
	        getline(ss, returnDate, ',');
	        getline(ss, returnedStr, ',');
	
	        if (uid == currentID && returnedStr == "1") {
	            magazineFound = true;
	            totalCount++;
	            cout << setw(5) << count++ 
	                 << setw(15) << id 
	                 << setw(30) << (title.length() > 28 ? title.substr(0, 25) + "..." : title)
	                 << setw(25) << (author.length() > 23 ? author.substr(0, 20) + "..." : author)
	                 << setw(15) << borrowDate
	                 << setw(15) << returnDate << "\n";
	        }
	    }
	    magazineFile.close();
	
	    if (!magazineFound) {
	        cout << "No magazine borrowing history found.\n";
	    }
	
	    cout << "\nTotal borrowing history items: " << totalCount << "\n";
	    
	    char choice;
cout << "\nDo you want to generate a borrowing report file? (Y/N): ";
cin >> choice;

if (choice == 'Y' || choice == 'y') {
    ofstream report("Borrow_History_Report.txt");
    report << "JR Library - Borrow History Report\n";
    report << "User ID: " << currentID << "\n\n";

    // Book History
    report << "Book Borrowing History:\n";
    report << setw(5) << "No." << setw(15) << "Book ID" << setw(30) << "Title"
           << setw(25) << "Author" << setw(15) << "Borrow Date" << setw(15) << "Return Date" << "\n";
    report << string(100, '-') << "\n";

    // Reset file read for books
    ifstream bookFileAgain("borrowedBook.txt");
    int bookCount = 1;
    while (getline(bookFileAgain, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string uid, id, title, author, yearStr, borrowDate, returnDate, returnedStr;

        getline(ss, uid, ',');
        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, yearStr, ',');
        getline(ss, borrowDate, ',');
        getline(ss, returnDate, ',');
        getline(ss, returnedStr, ',');

        if (uid == currentID && returnedStr == "1") {
            report << setw(5) << bookCount++
                   << setw(15) << id
                   << setw(30) << title
                   << setw(25) << author
                   << setw(15) << borrowDate
                   << setw(15) << returnDate << "\n";
        }
    }
    bookFileAgain.close();

    if (bookCount == 1) {
        report << "No book borrowing history found.\n";
    }

    // Magazine History
    report << "\nMagazine Borrowing History:\n";
    report << setw(5) << "No." << setw(15) << "Magazine ID" << setw(30) << "Title"
           << setw(25) << "Author" << setw(15) << "Borrow Date" << setw(15) << "Return Date" << "\n";
    report << string(100, '-') << "\n";

    // Reset file read for magazines
    ifstream magazineFileAgain("borrowedMagazines.txt");
    int magCount = 1;
    while (getline(magazineFileAgain, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string uid, id, title, author, yearStr, borrowDate, returnDate, returnedStr;

        getline(ss, uid, ',');
        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, yearStr, ',');
        getline(ss, borrowDate, ',');
        getline(ss, returnDate, ',');
        getline(ss, returnedStr, ',');

        if (uid == currentID && returnedStr == "1") {
            report << setw(5) << magCount++
                   << setw(15) << id
                   << setw(30) << title
                   << setw(25) << author
                   << setw(15) << borrowDate
                   << setw(15) << returnDate << "\n";
        }
    }
    magazineFileAgain.close();

    if (magCount == 1) {
        report << "No magazine borrowing history found.\n";
    }

    // Total count
    report << "\nTotal borrowing history items: " << totalCount << "\n";
    report.close();
    cout << "Report generated: Borrow_History_Report.txt\n"; 
    cin.get();
} else {
    cout << "Report not generated.\n";
    cin.get();
}

	}
};

//inheritance BookRecord
class Library : public BookRecord {
public:
    //Constructor
    Library() : BookRecord() {}
    //Destructor
    ~Library() override {
    }
    
    // Override virtual method for displayingBooks
    void displayBooks() override {
        BookRecord::displayBooks();
    }
    // Override virtual method for displayAvailableBooks
    void displayAvailableBooks() override {
        BookRecord::displayAvailableBooks();
    }
    // Override virtual method for displayBorrowedBooks
    void displayBorrowedBooks() override {
        BookRecord::displayBorrowedBooks();
    }
    // Override virtual method for displayMagazine
    void displayMagazine() override {
        BookRecord::displayMagazine();
    }
    // Override virtual method for displayAvailableMagazine
    void displayAvailableMagazine() override {
        BookRecord::displayAvailableMagazine();
    }
    // Override virtual method for displayBorrowedMagazine
    void displayBorrowedMagazine() override {
        BookRecord::displayBorrowedMagazine();
    }
    // Override virtual method for saveBooksToFile
    void saveBooksToFile(const string& filename) override {
        BookRecord::saveBooksToFile(filename);
    }
    // Override virtual method for loadBooksFromFile
    void loadBooksFromFile(const string& filename) override {
        BookRecord::loadBooksFromFile(filename);
    }
    
    //search book function
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
        //Load Books
		loadBooksFromFile("books.txt");

        if (head == nullptr) {
            cout << "No books in the system." << endl;
            cout << "Press Enter to continue...";
            cin.get();
            return;
        }
        //choose the options
        int searchChoice;
        cout << "Search books by:\n";
        cout << "1. Book ID\n";
        cout << "2. Title\n";
        cout << "3. Author\n";
        cout << "4. Year\n";
        cout << "Enter your choice: ";
        //Validate the input
        if (!(cin >> searchChoice)) {
            cerr << "Error: Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Press Enter to continue...";
            cin.get();
            return;
        }
        cin.ignore();
        //Process choice
        switch (searchChoice) {
			// Search by Book ID
            case 1: {
                string id;
                cout << "Enter book ID: ";
                getline(cin, id);
                searchBookById(id);
                break;
            }
			// Search by Book title
            case 2: {
                string title;
                cout << "Enter book title: ";
                getline(cin, title);
                searchBookByTitle(title);
                break;
            }
			// Search by Book Author
            case 3: {
                string author;
                cout << "Enter author name: ";
                getline(cin, author);
                searchBookByAuthor(author);
                break;
            }
			// Search by Book year
            case 4: {
                int year;
                cout << "Enter publication year: ";
                if (!(cin >> year)) {
                    cerr << "Error: Invalid year input." << endl;
                    cin.clear();
                    cin.ignore();
                    cout << "Press Enter to continue...";
                    cin.get();
                    return;
                }
                cin.ignore();
                searchBookByYear(year);
                break;
            }
            default:
                cout << "Invalid option.\n";
        }
        cout << "\nPress Enter to continue...";
        cin.get();
    }
    
    // Search by ID 
    void searchBookById(string searchId) {
        int n = 0;
        BookNode* temp = head;
        // Count total books
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }
        //Check Books
        if (n == 0) {
            cout << "No books in the file." << endl;
            return;
        }
        
        // Create arrays for sorting and searching
        string arr[100];  // Book IDs
        BookNode* nodes[100];  // Corresponding book nodes
        int i, j;
        // Fill arrays with book data
        temp = head;
        for (i = 0; i < n; ++i) {
            arr[i] = temp->id;
            nodes[i] = temp;
            temp = temp->next;
        }
        // Bubble sort by ID
        string tempStr;
        BookNode* tempNode;
        for (i = 1; i < n; ++i) {
            for (j = 0; j < (n - i); ++j) {
                if (arr[j] > arr[j + 1]) {
                    // Swap IDs
                    tempStr = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tempStr;
                    
                    // Swap corresponding nodes
                    tempNode = nodes[j];
                    nodes[j] = nodes[j + 1];
                    nodes[j + 1] = tempNode;
                }
            }
        }
        cout << "\n------------------------------------------------------------------------------------------------------------------\n";
        cout << "Search results for Book ID: " << searchId << "\n";
        cout << "------------------------------------------------------------------------------------------------------------------\n";
        // Binary search implementation
        int first = 0;
        int last = n - 1;
        int middle = (first + last) / 2;
        bool found = false;
         // Continue searching
        while (first <= last) {
            if (arr[middle] < searchId) {
                first = middle + 1;
            } else if (arr[middle] == searchId) {
                cout << "ID: " << nodes[middle]->id << "\n";
                cout << "Title: " << nodes[middle]->title << "\n";
                cout << "Author: " << nodes[middle]->author << "\n";
                cout << "Year: " << nodes[middle]->year << "\n";
                cout << "Status: " << (nodes[middle]->available ? "Available" : "Borrowed") << "\n";
                cout << "------------------------------------------------------------------------------------------------------------------\n";
                found = true;
                break;
            } else {
                last = middle - 1;
            }
            middle = (first + last) / 2;
        }
        //Check items
        if (!found) {
            cout << "Not found! "<< endl;
        }
    }
    
    // Search by title - Rewritten according to your pattern
    void searchBookByTitle(string searchTitle) {
        int n = 0;
        BookNode* temp = head;
        // Count total books
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }
        //Check book
        if (n == 0) {
            cout << "No books in the file." << endl;
            return;
        }
        // Create arrays for sorting and searching
        string arr[100];  // Book titles
        BookNode* nodes[100];  // Corresponding book nodes
        int i, j;
        
        // Fill arrays with book data
        temp = head;
        for (i = 0; i < n; ++i) {
            arr[i] = temp->title;
            nodes[i] = temp;
            temp = temp->next;
        }
        // Bubble sort by title
        string tempStr;
        BookNode* tempNode;
        for (i = 1; i < n; ++i) {
            for (j = 0; j < (n - i); ++j) {
                if (arr[j] > arr[j + 1]) {
                    // Swap titles
                    tempStr = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tempStr;
                    // Swap corresponding nodes
                    tempNode = nodes[j];
                    nodes[j] = nodes[j + 1];
                    nodes[j + 1] = tempNode;
                }
            }
        }
        cout << "\n------------------------------------------------------------------------------------------------------------------\n";
        cout << "Search results for title: " << searchTitle << "\n";
        cout << "------------------------------------------------------------------------------------------------------------------\n";
        // Binary search implementation
        int first = 0;
        int last = n - 1;
        int middle = (first + last) / 2;
        bool found = false;
         // Continue searching
        while (first <= last) {
            if (arr[middle] < searchTitle) {
                first = middle + 1;
            } else if (arr[middle] == searchTitle) {
                cout << "ID: " << nodes[middle]->id << "\n";
                cout << "Title: " << nodes[middle]->title << "\n";
                cout << "Author: " << nodes[middle]->author << "\n";
                cout << "Year: " << nodes[middle]->year << "\n";
                cout << "Status: " << (nodes[middle]->available ? "Available" : "Borrowed") << "\n";
                cout << "------------------------------------------------------------------------------------------------------------------\n";
                found = true;
                break;
            } else {
                last = middle - 1;
            }
            middle = (first + last) / 2;
        }
        //Check items
        if (!found) {
            cout << "Not found! "  << endl;
        }
    }
    
    // Search by author
    void searchBookByAuthor(string searchAuthor) {
        int n = 0;
        BookNode* temp = head;
        // Count total books
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }
        //Check book
        if (n == 0) {
            cout << "No books in the file." << endl;
            return;
        }
        //Create arrays for sorting and searching
        string arr[100];  // Book authors
        BookNode* nodes[100];  // Corresponding book nodes
        int i, j;
        // Fill arrays with book data
        temp = head;
        for (i = 0; i < n; ++i) {
            arr[i] = temp->author;
            nodes[i] = temp;
            temp = temp->next;
        }
        // Bubble sort by author
        string tempStr;
        BookNode* tempNode;
        for (i = 1; i < n; ++i) {
            for (j = 0; j < (n - i); ++j) {
                if (arr[j] > arr[j + 1]) {
                    // Swap authors
                    tempStr = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tempStr;
                    
                    // Swap corresponding nodes
                    tempNode = nodes[j];
                    nodes[j] = nodes[j + 1];
                    nodes[j + 1] = tempNode;
                }
            }
        }
        cout << "\n------------------------------------------------------------------------------------------------------------------\n";
        cout << "Search results for author: " << searchAuthor << "\n";
        cout << "------------------------------------------------------------------------------------------------------------------\n";
        // Binary search implementation
        int first = 0;
        int last = n - 1;
        int middle = (first + last) / 2;
        bool found = false;
         // Continue searching
        while (first <= last) {
            if (arr[middle] < searchAuthor) {
                first = middle + 1;
            } else if (arr[middle] == searchAuthor) {
                cout << "ID: " << nodes[middle]->id << "\n";
                cout << "Title: " << nodes[middle]->title << "\n";
                cout << "Author: " << nodes[middle]->author << "\n";
                cout << "Year: " << nodes[middle]->year << "\n";
                cout << "Status: " << (nodes[middle]->available ? "Available" : "Borrowed") << "\n";
                cout << "------------------------------------------------------------------------------------------------------------------\n";
                found = true;
                break;
            } else {
                last = middle - 1;
            }
            middle = (first + last) / 2;
        }
        //Check items
        if (!found) {
            cout << "Not found! "<< endl;
        }
    }
    
    // Search by year
    void searchBookByYear(int searchYear) {
        int n = 0;
        BookNode* temp = head;
        // Count total books
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }
        //Check book
        if (n == 0) {
            cout << "No books in the system." << endl;
            return;
        } 
        // Create arrays for sorting and searching
        int arr[100];  // Book years
        BookNode* nodes[100];  // Corresponding book nodes
        int i, j;
        // Fill arrays with book data
        temp = head;
        for (i = 0; i < n; ++i) {
            arr[i] = temp->year;
            nodes[i] = temp;
            temp = temp->next;
        }
        // Bubble sort by year
        int tempInt;
        BookNode* tempNode;
        for (i = 1; i < n; ++i) {
            for (j = 0; j < (n - i); ++j) {
                if (arr[j] > arr[j + 1]) {
                    // Swap years
                    tempInt = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tempInt;
                    // Swap corresponding nodes
                    tempNode = nodes[j];
                    nodes[j] = nodes[j + 1];
                    nodes[j + 1] = tempNode;
                }
            }
        }
        cout << "\n------------------------------------------------------------------------------------------------------------------\n";
        cout << "Search results for year: " << searchYear << "\n";
        cout << "------------------------------------------------------------------------------------------------------------------\n";
        // Binary search implementation 
        int first = 0;
        int last = n - 1;
        int middle = (first + last) / 2;
        bool found = false;
        // Continue searching
        while (first <= last) {
            if (arr[middle] < searchYear) {
                first = middle + 1;
            } else if (arr[middle] == searchYear) {
                cout << "ID: " << nodes[middle]->id << "\n";
                cout << "Title: " << nodes[middle]->title << "\n";
                cout << "Author: " << nodes[middle]->author << "\n";
                cout << "Year: " << nodes[middle]->year << "\n";
                cout << "Status: " << (nodes[middle]->available ? "Available" : "Borrowed") << "\n";
                cout << "------------------------------------------------------------------------------------------------------------------\n";
                found = true;
                break;
            } else {
                last = middle - 1;
            }
            middle = (first + last) / 2;
        }
        //Check items
        if (!found) {
            cout << "Not found! "  << endl;
        }
    }
    
    
    // Magazine search function
    void searchMagazine() {
        cout << "  ____________\n";
        cout << "  |  _       |\n";
        cout << "  | | |      |\n";
        cout << "  | | |___   |\n";
        cout << "  | |_____|  |\n";
        cout << "  |__________|\n\n";
        cout << "     JR Library\n";
        cout << "JR Library Management System\n";
        cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        cout << "                                                                   Search Magazine\n\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        //load magazine.txt
        loadBooksFromFile("magazine.txt");
        //Check magazine
        if (head == nullptr) {
            cout << "No magazines in the system." << endl;
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            return;
        }
        //Choose options
        int searchChoice;
        cout << "Search magazines by:\n";
        cout << "1. Magazine ID\n";
        cout << "2. Title\n";
        cout << "3. Author\n";
        cout << "4. Year\n";
        cout << "Enter your choice: ";
        // Validate the input
        if (!(cin >> searchChoice)) {
            cerr << "Error: Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Press Enter to continue...";
            cin.get();
            return;
        }
        cin.ignore();
        //Process choice
        switch (searchChoice) {
			// Search by magazine ID
            case 1: {
                string id;
                cout << "Enter magazine ID: ";
                getline(cin, id);
                searchMagazineById(id);
                break;
            }
			// Search by magazine title
            case 2: {
                string title;
                cout << "Enter magazine title: ";
                getline(cin, title);
                searchMagazineByTitle(title);
                break;
            }
			// Search by magazine author
            case 3: {
                string author;
                cout << "Enter author name: ";
                getline(cin, author);
                searchMagazineByAuthor(author);
                break;
            }
			// Search by magazine year
            case 4: {
                int year;
                cout << "Enter publication year: ";
                if (!(cin >> year)) {
                    cerr << "Error: Invalid year input." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Press Enter to continue...";
                    cin.get();
                    return;
                }
                cin.ignore();
                searchMagazineByYear(year);
                break;
            }
            default:
                cout << "Invalid option.\n";
        }
        cout << "Press Enter to continue...";
        cin.get();
    }

    // Search magazine by ID 
    void searchMagazineById(string searchId) {
        int n = 0;
        BookNode* temp = head;
        // Count total magazines
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }
        //Check magazine
        if (n == 0) {
            cout << "No magazines in the system." << endl;
            return;
        }
        // Create arrays for sorting and searching
        string arr[100];  // Magazine IDs
        BookNode* nodes[100];  // Corresponding magazine nodes
        int i, j;
        // Fill arrays with magazine data
        temp = head;
        for (i = 0; i < n; ++i) {
            arr[i] = temp->id;
            nodes[i] = temp;
            temp = temp->next;
        }
        // Bubble sort by ID
        string tempStr;
        BookNode* tempNode;
        for (i = 1; i < n; ++i) {
            for (j = 0; j < (n - i); ++j) {
                if (arr[j] > arr[j + 1]) {
                    // Swap IDs
                    tempStr = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tempStr;
                    // Swap corresponding nodes
                    tempNode = nodes[j];
                    nodes[j] = nodes[j + 1];
                    nodes[j + 1] = tempNode;
                }
            }
        }
        cout << "\n------------------------------------------------------------------------------------------------------------------\n";
        cout << "Search results for Magazine ID: " << searchId << "\n";
        cout << "------------------------------------------------------------------------------------------------------------------\n";
        // Binary search implementation
        int first = 0;
        int last = n - 1;
        int middle = (first + last) / 2;
        bool found = false;
        //Continue searching
        while (first <= last) {
            if (arr[middle] < searchId) {
                first = middle + 1;
            } else if (arr[middle] == searchId) {
                cout << "ID: " << nodes[middle]->id << "\n";
                cout << "Title: " << nodes[middle]->title << "\n";
                cout << "Author: " << nodes[middle]->author << "\n";
                cout << "Year: " << nodes[middle]->year << "\n";
                cout << "Status: " << (nodes[middle]->available ? "Available" : "Borrowed") << "\n";
                cout << "------------------------------------------------------------------------------------------------------------------\n";
                found = true;
                break;
            } else {
                last = middle - 1;
            }
            middle = (first + last) / 2;
        }
        //Check items
        if (!found) {
            cout << "Not found! "  << endl;
        }
    }
    
    // Search magazine by title 
    void searchMagazineByTitle(string searchTitle) {
        int n = 0;
        BookNode* temp = head;
        // Count total magazines
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }
        //Check magazine
        if (n == 0) {
            cout << "No magazines in the system." << endl;
            return;
        }
        // Create arrays for sorting and searching
        string arr[100];  // Magazine titles
        BookNode* nodes[100];  // Corresponding magazine nodes
        int i, j;
        // Fill arrays with magazine data
        temp = head;
        for (i = 0; i < n; ++i) {
            arr[i] = temp->title;
            nodes[i] = temp;
            temp = temp->next;
        }
        // Bubble sort by title 
        string tempStr;
        BookNode* tempNode;
        for (i = 1; i < n; ++i) {
            for (j = 0; j < (n - i); ++j) {
                if (arr[j] > arr[j + 1]) {
                    // Swap titles
                    tempStr = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tempStr;
                    // Swap corresponding nodes
                    tempNode = nodes[j];
                    nodes[j] = nodes[j + 1];
                    nodes[j + 1] = tempNode;
                }
            }
        }
        cout << "\n------------------------------------------------------------------------------------------------------------------\n";
        cout << "Search results for title: " << searchTitle << "\n";
        cout << "------------------------------------------------------------------------------------------------------------------\n";
        // Binary search implementation
        int first = 0;
        int last = n - 1;
        int middle = (first + last) / 2;
        bool found = false;
        //Continue Searching
        while (first <= last) {
            if (arr[middle] < searchTitle) {
                first = middle + 1;
            } else if (arr[middle] == searchTitle) {
                cout << "ID: " << nodes[middle]->id << "\n";
                cout << "Title: " << nodes[middle]->title << "\n";
                cout << "Author: " << nodes[middle]->author << "\n";
                cout << "Year: " << nodes[middle]->year << "\n";
                cout << "Status: " << (nodes[middle]->available ? "Available" : "Borrowed") << "\n";
                cout << "------------------------------------------------------------------------------------------------------------------\n";
                found = true;
                break;
            } else {
                last = middle - 1;
            }
            middle = (first + last) / 2;
        }
        //Check items
        if (!found) {
            cout << "Not found! "<< endl;
        }
    }
    
    // Search magazine by author 
    void searchMagazineByAuthor(string searchAuthor) {
        int n = 0;
        BookNode* temp = head;
        // Count total magazines
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }
        if (n == 0) {
            cout << "No magazines in the system." << endl;
            return;
        }
        // Create arrays for sorting and searching
        string arr[100];  // Magazine authors
        BookNode* nodes[100];  // Corresponding magazine nodes
        int i, j;
        // Fill arrays with magazine data
        temp = head;
        for (i = 0; i < n; ++i) {
            arr[i] = temp->author;
            nodes[i] = temp;
            temp = temp->next;
        }
        // Bubble sort by author 
        string tempStr;
        BookNode* tempNode;
        for (i = 1; i < n; ++i) {
            for (j = 0; j < (n - i); ++j) {
                if (arr[j] > arr[j + 1]) {
                    // Swap authors
                    tempStr = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tempStr;
                    // Swap corresponding nodes
                    tempNode = nodes[j];
                    nodes[j] = nodes[j + 1];
                    nodes[j + 1] = tempNode;
                }
            }
        }
        cout << "\n------------------------------------------------------------------------------------------------------------------\n";
        cout << "Search results for author: " << searchAuthor << "\n";
        cout << "------------------------------------------------------------------------------------------------------------------\n";
        // Binary search implementation
        int first = 0;
        int last = n - 1;
        int middle = (first + last) / 2;
        bool found = false;
        //Continue searching
        while (first <= last) {
            if (arr[middle] < searchAuthor) {
                first = middle + 1;
            } else if (arr[middle] == searchAuthor) {
                cout << "ID: " << nodes[middle]->id << "\n";
                cout << "Title: " << nodes[middle]->title << "\n";
                cout << "Author: " << nodes[middle]->author << "\n";
                cout << "Year: " << nodes[middle]->year << "\n";
                cout << "Status: " << (nodes[middle]->available ? "Available" : "Borrowed") << "\n";
                cout << "------------------------------------------------------------------------------------------------------------------\n";
                found = true;
                break;
            } else {
                last = middle - 1;
            }
            middle = (first + last) / 2;
        }
        
        if (!found) {
            cout << "Not found! " << searchAuthor << " is not present in the list." << endl;
        }
    }
    
    // Search magazine by year
void searchMagazineByYear(int searchYear) {
    int n = 0;
    BookNode* temp = head;
    // Count total magazines
    while (temp != nullptr) {
        n++;
        temp = temp->next;
    }
    if (n == 0) {
        cout << "No magazines in the system." << endl;
        return;
    }
    // Create arrays for sorting and searching
    int arr[100];  // Magazine years
    BookNode* nodes[100];  // Corresponding magazine nodes
    int i, j;
    // Fill arrays with magazine data
    temp = head;
    for (i = 0; i < n; ++i) {
        arr[i] = temp->year;
        nodes[i] = temp;
        temp = temp->next;
    }
    // Bubble sort by year
    int tempInt;
    BookNode* tempNode;
    for (i = 1; i < n; ++i) {
        for (j = 0; j < (n - i); ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap years
                tempInt = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tempInt;
                // Swap corresponding nodes
                tempNode = nodes[j];
                nodes[j] = nodes[j + 1];
                nodes[j + 1] = tempNode;
            }
        }
    }
    cout << "\n------------------------------------------------------------------------------------------------------------------\n";
    cout << "Search results for year: " << searchYear << "\n";
    cout << "------------------------------------------------------------------------------------------------------------------\n";
    // Binary search implementation
    int first = 0;
    int last = n - 1;
    int middle = (first + last) / 2;
    bool found = false;
    //Continue searching
    while (first <= last) {
        if (arr[middle] < searchYear) {
            first = middle + 1;
        } else if (arr[middle] == searchYear) {
            cout << "ID: " << nodes[middle]->id << "\n";
            cout << "Title: " << nodes[middle]->title << "\n";
            cout << "Author: " << nodes[middle]->author << "\n";
            cout << "Year: " << nodes[middle]->year << "\n";
            cout << "Status: " << (nodes[middle]->available ? "Available" : "Borrowed") << "\n";
            cout << "------------------------------------------------------------------------------------------------------------------\n";
            found = true;
            break;
        } else {
            last = middle - 1;
        }
        middle = (first + last) / 2;
    }
    //Check items
    if (!found) {
        cout << "Not found! " << endl;
    }
}

//Function sorting books
void sortBooks() {
    // Load books
    loadBooksFromFile("books.txt");
    //Check books
    if (head == nullptr || head->next == nullptr) {
        cout << "No books or only one book in the file. Nothing to sort." << endl;
		cout << "Press Enter to continue...";
        cin.get();
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
    cout << "                                                                    Sort Books\n\n";
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
    //Choose choice
    int sortChoice;
    cout << "Sort books by:\n";
    cout << "1. Title\n";
    cout << "2. Author\n";
    cout << "3. Year\n";
    cout << "4. ID\n";
    cout << "Enter your choice: ";
    //validation the input
    if (!(cin >> sortChoice)) {
        cerr << "Error: Invalid input. Please enter a number." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    cin.ignore();
    // Count the number of books
    int n = 0;
    BookNode* temp = head;
    while (temp != nullptr) {
        n++;
        temp = temp->next;
    }
    // Bubble sort implementation
    for (int i = 1; i < n; ++i) {
        BookNode* current = head;
        for (int j = 0; j < (n - i); ++j) {
            if (current->next != nullptr) {
                bool shouldSwap = false;
                switch (sortChoice) {
                    case 1: // Sort by title
                        shouldSwap = current->title > current->next->title;
                        break;
                    case 2: // Sort by author
                        shouldSwap = current->author > current->next->author;
                        break;
                    case 3: // Sort by year
                        shouldSwap = current->year > current->next->year;
                        break;
                    case 4: // Sort by ID
                        shouldSwap = current->id > current->next->id;
                        break;
                    default:
                        cout << "Invalid sort option. Sorting by title as default." << endl;
                        shouldSwap = current->title > current->next->title;
                        break;
                }
                if (shouldSwap) {
                    // Swap book data
					//1. Backup current node data
                    string tempId = current->id;
                    string tempTitle = current->title;
                    string tempAuthor = current->author;
                    int tempYear = current->year;
                    bool tempAvailable = current->available;
                    //2. Copy next node's data to current node
                    current->id = current->next->id;
                    current->title = current->next->title;
                    current->author = current->next->author;
                    current->year = current->next->year;
                    current->available = current->next->available;
                    //3. Restore backup data to next node
                    current->next->id = tempId;
                    current->next->title = tempTitle;
                    current->next->author = tempAuthor;
                    current->next->year = tempYear;
                    current->next->available = tempAvailable;
                }
				// Move to next node
                current = current->next;
            }
        }
    }
    //take the sorttype
    string sortType;
    switch (sortChoice) {
        case 1: sortType = "title"; break;
        case 2: sortType = "author"; break;
        case 3: sortType = "year"; break;
        case 4: sortType = "ID"; break;
        default: sortType = "title"; break;
    }
    cout << "Books sorted by " << sortType << " successfully!" << endl;
    // Display sorted books
    cout << "\n------------------------------------------------------------------------------------------------------------------\n";
    cout << "ID\t\tTitle\t\t\t\tAuthor\t\t\t\tYear\t\tStatus\n";
    cout << "------------------------------------------------------------------------------------------------------------------\n";
    // Start traversing from the head of the linked list
    temp = head;
    while (temp != nullptr) {
        cout << temp->id << "\t\t"
             << temp->title << "\t\t\t"
             << temp->author << "\t\t\t"
             << temp->year << "\t\t";
        //check status
        if (temp->available) {
            cout << CYAN << "AVAILABLE" << RESET;
        } else {
            cout << RED << "BORROWED" << RESET;
        }
        cout << endl << endl;
        
        temp = temp->next;
    }
    cout << "------------------------------------------------------------------------------------------------------------------\n";
    cout << "Press Enter to continue...";
    cin.get();
} 

//sortMagazines function
void sortMagazines() {
    cout << "  ____________\n";
    cout << "  |  _       |\n";
    cout << "  | | |      |\n";
    cout << "  | | |___   |\n";
    cout << "  | |_____|  |\n";
    cout << "  |__________|\n\n";
    cout << "     JR Library\n";
    cout << "JR Library Management System\n";
    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
    cout << "                                                                    Sort Magazines\n\n";
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
    //load magazine.txt
    loadBooksFromFile("magazine.txt");
    if (head == nullptr|| head->next == nullptr) {
        cout << "No magazine or only one magazine in the file. Nothing to sort." << endl;
        cout << "Press Enter to continue...";
        cin.get();
        return;
    }
    //Choose choice
	int sortChoice;
    cout << "Sort magazines by:\n";
    cout << "1. Title\n";
    cout << "2. Author\n";
    cout << "3. Year\n";
    cout << "4. ID\n";
    cout << "Enter your choice: ";
    //validation the input
	if (!(cin >> sortChoice)) {
        cerr << "Error: Invalid input. Please enter a number." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    cin.ignore();
    // Count the number of books
   int n = 0;
    BookNode* temp = head;
    while (temp != nullptr) {
        n++;
        temp = temp->next;
    }
    // Bubble sort implementation
    for (int i = 1; i < n; ++i) {
        BookNode* current = head;
        for (int j = 0; j < (n - i); ++j) {
            if (current->next != nullptr) {
                bool shouldSwap = false;
                switch (sortChoice) {
                    case 1: // Sort by title
                        shouldSwap = current->title > current->next->title;
                        break;
                    case 2: // Sort by author
                        shouldSwap = current->author > current->next->author;
                        break;
                    case 3: // Sort by year
                        shouldSwap = current->year > current->next->year;
                        break;
                    case 4: // Sort by ID
                        shouldSwap = current->id > current->next->id;
                        break;
                    default:
                        cout << "Invalid sort option. Sorting by title as default." << endl;
                        shouldSwap = current->title > current->next->title;
                        break;
                }
                if (shouldSwap) {
                    // Swap book data
					// 1. Backup current node data
                    string tempId = current->id;
                    string tempTitle = current->title;
                    string tempAuthor = current->author;
                    int tempYear = current->year;
                    bool tempAvailable = current->available;
                    // 2. Copy next node's data to current node
                    current->id = current->next->id;
                    current->title = current->next->title;
                    current->author = current->next->author;
                    current->year = current->next->year;
                    current->available = current->next->available;
                    // 3. Restore backup data to next node
                    current->next->id = tempId;
                    current->next->title = tempTitle;
                    current->next->author = tempAuthor;
                    current->next->year = tempYear;
                    current->next->available = tempAvailable;
                }
				// Move to next node
                current = current->next;
            }
        }
    }
    //take the sorttype
    string sortType;
    switch (sortChoice) {
        case 1: sortType = "title"; break;
        case 2: sortType = "author"; break;
        case 3: sortType = "year"; break;
        case 4: sortType = "ID"; break;
        default: sortType = "title"; break;
    }
    cout << "magazine sorted by " << sortType << " successfully!" << endl;
    // Display sorted magazines
    cout << "\n------------------------------------------------------------------------------------------------------------------\n";
    cout << "ID\t\tTitle\t\t\t\tAuthor\t\t\t\tYear\t\tStatus\n";
    cout << "------------------------------------------------------------------------------------------------------------------\n";
	// Start traversing from the head of the linked list
    temp = head;
    while (temp != nullptr) {
        cout << temp->id << "\t\t"
             << temp->title << "\t\t\t"
             << temp->author << "\t\t\t"
             << temp->year << "\t\t";
        //check status
        if (temp->available) {
            cout << CYAN << "AVAILABLE" << RESET;
        } else {
            cout << RED << "BORROWED" << RESET;
        }
        cout << endl << endl;
        
        temp = temp->next;
    }
    cout << "------------------------------------------------------------------------------------------------------------------\n";
    cout << "Press Enter to continue...";
    cin.get();
}


}; 

void adminMenu(Admin& admin)
{
	BookRecord bookRecords;
	Customer customer;
	Library library; 
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
	    cout << "                              |                                        26. Logout                                	                   |" << endl;
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
				admin.loadAdminsFromFile();
				cout<<"Press Enter To Continue...";
				cin.ignore(10000, '\n');  // Clear any leftover characters
				cin.get();
				break;
			case 2:
				system("cls");
				admin.editAdmin();
				admin.saveAdminToFile(); 
				admin.loadAdminsFromFile();
				cout<<"Press Enter To Continue...";
				cin.ignore(10000, '\n');  // Clear any leftover characters
				cin.get();
				break;
			case 3:
				system("cls");
				admin.removeAdmin();
				admin.saveAdminToFile();
				admin.loadAdminsFromFile();
				cout<<"Press Enter To Continue...";
				cin.ignore(10000, '\n');  // Clear any leftover characters
				cin.get();
				break;
			case 4:
				system("cls");
				admin.displayAdmin();
				cout<<"Press Enter To Continue...";
				cin.ignore(10000, '\n');  // Clear any leftover characters
				cin.get();
				break;
			case 5:
				system("cls");
				bookRecords.loadBooksFromFile("books.txt");
				admin.addBook(bookRecords);
				cout<< "Press Enter To Continue...";
				cin.ignore(10000, '\n');  // Clear any leftover characters
				cin.get();
				break;
			case 6:
				system("cls");
				bookRecords.loadBooksFromFile("books.txt");
				admin.editBook(bookRecords);
				cout<< "Press Enter To Continue...";
				cin.ignore(10000, '\n');  // Clear any leftover characters
				cin.get();
				break;
			case 7:
				system("cls");
				bookRecords.loadBooksFromFile("books.txt");
				admin.deleteBook(bookRecords);
				cout<< "Press Enter To Continue...";
				cin.ignore(10000, '\n');  // Clear any leftover characters
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
				admin.addMagazine(bookRecords);
				cout<< "Press Enter To Continue...";
				cin.get();
				break;
			case 12:
				system("cls");
				admin.editMagazine(bookRecords);
				cout<< "Press Enter To Continue...";
				cin.get();
				break;
			case 13:
				system("cls");
				bookRecords.loadBooksFromFile("magazine.txt");
				admin.deleteMagazine(bookRecords);
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
				admin.viewBorrowedBooks();
				break;
			case 19:
				system("cls");
				admin.viewBorrowedHistory();
				break;
			case 20:
				system("cls");
				admin.viewBorrowedMagazine();
				break;
			case 21:
				system("cls");
				admin.viewBorrowedMagazineHistory();
				break;
			case 22:
				system("cls");
				bookRecords.loadBooksFromFile("books.txt");
         		library.sortBooks();
				break;
			case 23:
				system("cls");
				library.searchBook();
				break;
			case 24:
				system("cls");
				bookRecords.loadBooksFromFile("magazine.txt");
				library.sortMagazines();
				break;
			case 25:
				system("cls");
				library.searchMagazine();
				break;
			case 26:
				cout << "Logging out. Goodbye!\n";
				return;
			default:
				cout<< "Invalid Choice...";
				cin.get();
		}
	}while(choice!=26);
}

void customerMenu(Customer& customer) {
    BookRecord bookRecords;
    Library library;
	int choice;
    
    bookRecords.loadBooksFromFile("books.txt");
    
    do {
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
        cout << "                                                                    Customer Dashboard\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	    cout << "                              |------------------------------------------------------------------------------------------------------------|" << endl;
	    cout << "                              |                                               MENU                                                         |" << endl;
	    cout << "                              |------------------------------------------------------------------------------------------------------------|" << endl;
        cout << "                              |                                        1. View All Books                                                   |" << endl;
        cout << "                              |                                        2. View Available Books                                             |" << endl;
        cout << "                              |                                        3. Search Books                                                     |" << endl;
        cout << "                              |                                        4. View All Magazines                                               |" << endl;
        cout << "                              |                                        5. View Available Magazines                                         |" << endl;
        cout << "                              |                                        6. Search Magazines                                                 |" << endl;
        cout << "                              |                                        7. Borrow and Return Book                                           |" << endl;
        cout << "                              |                                        8. Borrow amd Return Magazine                                       |" << endl;
        cout << "                              |                                        9. View Your Borrowed Items                                         |" << endl;
        cout << "                              |                                        10. View Borrowed History                                           |" << endl;
        cout << "                              |                                        11. Logout                                                          |" << endl;
	    cout << "                              |------------------------------------------------------------------------------------------------------------|" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
		cin.ignore();
	
        switch(choice) {
			case 1:
				system("cls");
                bookRecords.loadBooksFromFile("books.txt");
                bookRecords.displayBooks();
                cout << "Press Enter To Continue...";
				cin.get();
				break;
			case 2:
				system("cls");
                bookRecords.loadBooksFromFile("books.txt");
                bookRecords.displayAvailableBooks();
                cout << "Press Enter To Continue...";
				cin.get();
				break;
			case 3:
				system("cls");
                library.loadBooksFromFile("books.txt");
                library.searchBook();
                cout << "Press Enter To Continue...";
				cin.get();
				break;
			case 4:
				system("cls");
                bookRecords.loadBooksFromFile("magazine.txt");
                bookRecords.displayMagazine();
                cout << "Press Enter To Continue...";
				cin.get();
				break;
			case 5:
				system("cls");
                bookRecords.loadBooksFromFile("magazine.txt");
                bookRecords.displayAvailableMagazine();
                cout << "Press Enter To Continue...";
				cin.get();
				break;
			case 6:
				system("cls");
                library.loadBooksFromFile("magazine.txt");
                library.searchMagazine();
				break;
			case 7:
				system("cls");
                int choice;
				cout << "  ____________\n";
				cout << "  |  _       |\n";
				cout << "  | | |      |\n";
				cout << "  | | |___   |\n";
				cout << "  | |_____|  |\n";
				cout << "  |__________|\n\n";
				cout << "     JR Library\n";
				cout << "JR Library Management System\n";
				cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
				cout << "                                                                    Borrow and Return Book\n\n";
				cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                cout<< "1. Borrow Book\n";
                cout<< "2. Return Book\n";
                cout<< "Enter Your Choice:";
                cin>> choice;
                cin.ignore();
                
                switch(choice){
                	case 1:
                		customer.borrowBook();
                		break;
                	case 2:
                		customer.returnBook();
                		break;
                	default:
                		cout<< "Invalide Choice...";
				cin.get();
				}
				break;
			case 8:
				system("cls");
                int option;
				cout << "  ____________\n";
				cout << "  |  _       |\n";
				cout << "  | | |      |\n";
				cout << "  | | |___   |\n";
				cout << "  | |_____|  |\n";
				cout << "  |__________|\n\n";
				cout << "     JR Library\n";
				cout << "JR Library Management System\n";
				cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
				cout << "                                                                    Borrow and Return Magazine\n\n";
				cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                cout<< "1. Borrow Magazine\n";
                cout<< "2. Return Magazine\n";
                cout<< "Enter Your Choice:";
                cin>> option;
                cin.ignore();
                
                switch(option){
                	case 1:
                		customer.borrowMagazine();
                		break;
                	case 2:
                		customer.returnMagazine();
                		break;
                	default:
                		cout<< "Invalide Choice...";
				cin.get();
				}
                break;
            case 9:
                system("cls");
                int c;
				cout << "  ____________\n";
				cout << "  |  _       |\n";
				cout << "  | | |      |\n";
				cout << "  | | |___   |\n";
				cout << "  | |_____|  |\n";
				cout << "  |__________|\n\n";
				cout << "     JR Library\n";
				cout << "JR Library Management System\n";
				cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
				cout << "                                                                    View Current Borrowed items\n\n";
				cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                cout<< "1. Borrowed Book\n";
                cout<< "2. Borrowed Magazine\n";
                cout<< "Enter Your Choice:";
                cin>> c;
                cin.ignore();
                
                switch(c){
                	case 1:
                		customer.viewBorrowedBooks();
                		break;
                	case 2:
                		customer.viewBorrowedMagazines(); 
				break;
			default:
                		cout<< "Invalide Choice...";
                		cin.get();
				}
                
                break;
            case 10:
            	customer.viewBorrowHistory();
            	cin.get();
            	break;
            case 11:
                cout << "Logging out. Goodbye!\n";
                return;
            default:
                cout << "Invalid Choice...";
                cin.ignore(10000, '\n');  // Clear any leftover characters
                cin.get();
        }
    } while(choice != 10);
}

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
		        		customerMenu(*customer);
					}
				}
				//admin
				else if(loginType==2){
					admin->loadAdminsFromFile();
					if(admin->adminLogin())
					{
						adminMenu(*admin);
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
