#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

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
	    cout << "Added successfully!\n";
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
	    try {
	        ofstream outFile(filename, ios::trunc);
	        if (!outFile.is_open()) {
	            cerr << "Unable to open file for writing: " << filename << endl;
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
	    } catch (const ofstream::failure& e) {
	        cerr << "File write failure: " << e.what() << endl;
	    } catch (const bad_alloc& e) {
	        cerr << "Memory allocation failed: " << e.what() << endl;
	    }
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
	
	    ifstream inFile(filename);
	    if (!inFile.is_open()) {
	        cerr << "Cannot open " << filename << endl;
	        return;
	    }
	
	    string line;
	    while (getline(inFile, line)) {
	        stringstream ss(line);
	        string id, title, author, yearStr, availableStr;
	
	        if (!getline(ss, id, ',') ||
	            !getline(ss, title, ',') ||
	            !getline(ss, author, ',') ||
	            !getline(ss, yearStr, ',') ||
	            !getline(ss, availableStr, ',')) {
	            cerr << "Format conversion erro and skip this line : " << line << endl;
	            continue;
	        }
	
	        int year;
	        bool available;
	
	        try {
	            year = stoi(yearStr);  
	            available = (availableStr == "1");
	        } catch (...) { 
	            cerr << "Data conversion erro and skip this line : " << line << endl;
	            continue;
	        }
	        BookNode* newNode = new BookNode{id, title, author, year, available, nullptr};
	
	        if (head == nullptr) {
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
	void saveAdminToFile() {
	    try {
	        // Open file for writing (overwrite mode)
	        ofstream outFile("admin.txt", ios::trunc);
	
	        if (!outFile.is_open()) {
	            cout << "Save admin information unsuccessfully, cannot open admin.txt file..." << endl;
	            return;
	        }
	
	        AdminNode* temp = head; // start from head
	        while (temp != NULL) {
	            try {
	                // Safely access admin data
	                outFile << temp->admin->getID() << ","
	                        << temp->admin->getName() << ","
	                        << temp->admin->getPassword() << ","
	                        << temp->admin->getEmail() << ","
	                        << temp->admin->getPhoneNum() << endl;
	
	                temp = temp->next; // move to next node
	
	            } catch (const exception& e) {
	                cerr << "Error writing admin data: " << e.what() << endl;
	                temp = temp->next; // skip this node and continue
	            }
	        }
	
	        outFile.close();
	
	    } catch (const ofstream::failure& e) {
	        cerr << "File output error occurred: " << e.what() << endl;
	    } catch (const bad_alloc& e) {
	        cerr << "Memory allocation failed while saving admin data: " << e.what() << endl;
	    } catch (...) {
	        cerr << "Unknown error occurred while saving admin data." << endl;
	    }
	}


	//load admin
	void loadAdminsFromFile() {
	    // Clear the current admin list
	    AdminNode* current = head;
	    while (current != NULL) {
	        AdminNode* toDelete = current;
	        current = current->next;
	        delete toDelete; // free memory
	    }
	    head = NULL; // reset head
	
	    // Try opening the file
	    ifstream inFile("admin.txt");
	    if (!inFile.is_open()) {
	        cout << "Cannot find admin.txt, load unsuccessfully..." << endl;
	        return;
	    }
	
	    string line;
	    while (getline(inFile, line)) {
	        try {
	            stringstream ss(line);
	            string id, name, password, email, phone;
	
	            // Check if all fields exist in the line
	            if (!getline(ss, id, ',') || !getline(ss, name, ',') || !getline(ss, password, ',') || !getline(ss, email, ',') || !getline(ss, phone)) {
	                cout << "Error: format error, skipped the " << line << endl;
	                continue; 
	            }
	
	            // Try creating Admin object
	            Admin* a = new Admin(id, name, password, email, phone);
	
	            // Create new AdminNode
	            AdminNode* newNode = new AdminNode(a);
	
	            // Insert into the linked list
	            if (head == NULL) {
	                head = newNode; // first admin in list
	            } else {
	                AdminNode* temp = head;
	                while (temp->next != NULL) {
	                    temp = temp->next; // go to the end
	                }
	                temp->next = newNode; // link the new node
	            }
	
	        } catch (const bad_alloc& e) {
	            cerr << "Memory allocation failed while loading admin: " << e.what() << endl;
	            break; // stop reading further
	        } catch (...) {
	            cerr << "Unknown error occurred while loading line: " << line << endl;
	            continue; // skip this line and continue
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
	            cout << temp->id << "\t\t\t" << temp->title << "\t\t\t" << temp->author << "\t\t" << temp->year << "\t\t\t" << (temp->available ? "Yes" : "No") << endl;
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
	    cout << "                                                                      View Borrowed Books By User\n\n";
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
	    cout << "                                                                       View Borrowed Magazine By User\n\n";
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
	    ifstream file("borrowedMagazines.txt"); //open magazines.txt file 
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
    Customer* currentUser = NULL;  // Added for tracking current user

    struct CustomerNode {
        Customer* customer;
        CustomerNode* next;
        CustomerNode(Customer* c) : customer(c), next(NULL) {}
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
    
    BorrowBook* head1 = NULL;
    
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
    
    BorrowMagazine* head2 = NULL;
    

    
public:
    Customer() : currentUser(NULL), head(NULL), head1(NULL), head2(NULL) {}

    Customer(string id, string name, string password, string email, string phone_num, string keyword)
        : Person(id, name, password, email, phone_num), keyword(keyword) {}
    
    // Destructor for Customer class
    ~Customer() {
        CustomerNode* current = head;
        while (current != NULL) {
            CustomerNode* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        head = NULL;
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
	    while (temp != NULL) {
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
	    while (temp != NULL) {
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
            do{
            cout << "Enter name: ";
            getline(cin, name);
        } while (name.empty());

            do{
            cout << "Enter password: ";
            getline(cin, password);
            cout << "Confirm password: ";
            getline(cin, confirm_password);
        } while(password != confirm_password || password.empty());

            do{
            cout << "Enter email: ";
        getline(cin, email);
                if(email.empty()) 
				{
					cout << "Email cannot be empty.\n";
				}
                else if(isDuplicateEmail(email)) 
				{
            cout << "Email already exists. Please use another.\n";
            email = "";
        }
        } while(email.empty());

            do{
            cout << "Enter phone number: ";
            getline(cin, phone_num);
        } while(phone_num.empty());

            do{
            cout << "Enter keyword (used for resetting password): ";
            getline(cin, keyword);
        } while(keyword.empty());

        if (isDuplicateEmail(email)) 
		{
            cout << "Email already exists. Registration failed.\n";
                success = false;
            }
        }
        
        if (success){
            Customer* newCust = new (nothrow) Customer(id, name, password, email, phone_num, keyword);
            if (!newCust) 
			{
                cerr << "Error: Memory allocation failed for new customer." << endl;
                success = false;
            } else {
                CustomerNode* newNode = new (nothrow) CustomerNode(newCust);
                if (!newNode){
                    cerr << "Error: Memory allocation failed for customer node." << endl;
                    delete newCust;
                    success = false;
                } else {
        if(!head) 
		{
			head = newNode;
                    } else 
		{
            CustomerNode* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }

                    if(!saveCustomersToFile()) 
					{
                        cerr << "Warning: Failed to save customer to file." << endl;
                    }
                    
        cout << "Customer registered successfully!\n";
                }
            }
        }
        
        if(!success) 
		{
            cout << "Registration failed. Please try again." << endl;
        }
        
        cin.get();
    }

    bool customerLogin() {
	    string email, password;
	
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
	
	    try {
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
	            try {
	                if (temp->customer &&
	                    temp->customer->getEmail() == email &&
	                    temp->customer->getPassword() == password) {
	
	                    cout << "Login successful! Welcome, " << temp->customer->getName() << ".\n";
	                    currentUser = temp->customer;  // Set the current user
	                    cin.get();
	                    return true;
	                }
	                temp = temp->next;
	            } catch (...) {
	                cerr << "Something went wrong while checking login credentials.\n";
	                temp = temp->next; // skip this node if exception occurs
	            }
	        }
	
	        cout << "Invalid email or password.\n";
	        cin.get();
	        return false;
	
	    } catch (...) {
	        cerr << "Unexpected error during login.\n";
	        cin.get();
	        return false;
	    }
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

        CustomerNode* temp =head;
        bool foundEmail = false;
        
        while(temp){
            if (temp->customer->getEmail() == email){
                foundEmail = true;
                cout << "Enter your keyword: ";
                getline(cin, inputKeyword);
                if (temp->customer->keyword == inputKeyword){
                    cout << "Enter new password: ";
                    getline(cin, newPassword);
                    if(newPassword.empty()) 
					{
                        cout << "Password cannot be empty.\n";
                    } 
					else 
					{
                    temp->customer->setPassword(newPassword);
                        if(saveCustomersToFile())
						{
                    cout << "Password reset successful.\n";
                        }else{
                            cerr << "Warning: Failed to save updated password to file." << endl;
                            cout << "Password was reset but there was an error saving to file." << endl;
                        }
                    }
                }else{
                    cout << "Keyword incorrect.\n";
                }
                break;
            }
            temp = temp->next;
        }

        if (!foundEmail)
		{
        cout << "Email not found.\n";
        }
        
        cin.get();
    }

    bool isDuplicateCustomerEmail(string email) {
        CustomerNode* temp = head;
        while (temp)
		{
            if (temp->customer->getEmail() == email)
            {
                return true;
			}
                
            temp = temp->next;
        }
        return false;
    }
    
    bool saveCustomersToFile()
	{
        ofstream cFile("customer.txt");
        if (!cFile.is_open())
		{
            cerr << "Error: Unable to open customer.txt for writing" << endl;
            return false;
        }
        
        CustomerNode* temp = head;
        while (temp)
		{
            cFile << temp->customer->getID() << ","<< temp->customer->getName() << ","<< temp->customer->getPassword() << ","<< temp->customer->getEmail() << ","<< temp->customer->getPhoneNum() << ","<< temp->customer->keyword << "\n";
            temp = temp->next;
        }
        cFile.close();
        cout << "Customer data saved to customer.txt\n";
        return true;
    }

    void loadCustomersFromFile()
	{
		
		string line, id, name, password, email, phone, keyword;
		
        CustomerNode* current = head;
        while(current)
		{
            CustomerNode* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        head = NULL;

        ifstream cFile("customer.txt");
        if (!cFile){
            cout << "customer.txt not found. Load failed.\n";
            return;
        }

        while(getline(cFile, line))
		{
            stringstream ss(line);
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, password, ',');
            getline(ss, email, ',');
            getline(ss, phone, ',');
            getline(ss, keyword);

            Customer* c = new Customer(id, name, password, email, phone, keyword);
            CustomerNode* newNode = new CustomerNode(c);

            if (!head) head = newNode;
            else{
                CustomerNode* temp = head;
                while (temp->next) temp = temp->next;
                temp->next = newNode;
            }
        }

        cFile.close();
    }
    
    friend void viewCustomers(Customer& custSystem);
    
    //view borrowed book
	void viewBorrowedBooks() {
		
		string userId = currentUser->getID(), line, uid, id, title, author, yearStr, borrowDate, returnDate, returnedStr;;
		
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
	
	    if (currentUser == NULL) {
	        cout << "Please log in first.\n";
	        cin.get();
	        return;
	    }
	    
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
	
	    BorrowedBook* head = NULL;
	    BorrowedBook* tail = NULL;
	    bool found = false;
	
	    // Read borrowed books file
	    ifstream borbfile("borrowedBook.txt");
	    if (borbfile.is_open()) {
	        while (getline(borbfile, line)) {
	            if (line.empty()){
	            	continue;
				}
	
	            stringstream ss(line);
	
	            getline(ss, uid, ',');
	            getline(ss, id, ',');
	            getline(ss, title, ',');
	            getline(ss, author, ',');
	            getline(ss, yearStr, ',');
	            getline(ss, borrowDate, ',');
	            getline(ss, returnDate, ',');
	            getline(ss, returnedStr, ',');
	
	            // Create new borrowed book record
	            BorrowedBook* newBook = new BorrowedBook{uid, id, title, author, stoi(yearStr), borrowDate, returnDate, (returnedStr == "1"), NULL};
	
	            // Add to linked list
	            if
				(!head) {
	                head = tail = newBook;
	            }else{
	                tail->next = newBook;
	                tail = newBook;
	            }
	        }
	        borbfile.close();
	    }else{
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
	    while (current)
		{
	        if (current->uid == userId && !current->returned){
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
	
	    if (!found)
		{
	        cout << "No borrowed books found.\n";
	    }
	
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	
	    // Clean up memory
	    while(head)
		{
	        BorrowedBook* temp = head;
	        head = head->next;
	        delete temp;
	    }
	
	    cout << "\nPress Enter to continue...";
	    cin.get();
	}


//view borrowed magazine
	void viewBorrowedMagazines() {
		
		string userId = currentUser->getID(), line, uid, id, title, author, yearStr, borrowDate, returnDate, returnedStr;
		
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
	
	    if (currentUser == NULL)
		{
	        cout << "Please log in first.\n";
	        cin.get();
	        return;
	}
	    
	    // Structure to hold borrowed book records (similar to returnBook())
	    struct BorrowedBook
		{
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
	
	    BorrowedBook* head = NULL;
	    BorrowedBook* tail = NULL;
	    bool found = false;
	
	    // Read borrowed books file
	    ifstream bormfile("borrowedMagazines.txt");
	    if (bormfile.is_open())
		{
	        string line;
	        while (getline(bormfile, line))
			{
	            if (line.empty()){
	            	
	            	continue;
				}
	
	            stringstream ss(line);
	            getline(ss, uid, ',');
	            getline(ss, id, ',');
	            getline(ss, title, ',');
	            getline(ss, author, ',');
	            getline(ss, yearStr, ',');
	            getline(ss, borrowDate, ',');
	            getline(ss, returnDate, ',');
	            getline(ss, returnedStr, ',');
	
	            // Create new borrowed book record
	            BorrowedBook* newBook = new BorrowedBook{uid, id, title, author, stoi(yearStr), borrowDate, returnDate, (returnedStr == "1"), NULL};
	
	            // Add to linked list
	            if (!head)
				{
	                head = tail = newBook;
	            }else{
	                tail->next = newBook;
	                tail = newBook;
	            }
	        }
	        bormfile.close();
	    }else{
	        cout << "No borrowed magazines found.\n";
	        cin.get();
	        return;
	    }
	
	    // Display borrowed books
	    cout << "\nBorrowed Magazines:\n";
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	    cout << "ID\t\tTitle\t\t\t\tAuthor\t\t\tBorrow Date\t\tReturn Date\n";
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	
	    BorrowedBook* current = head;
	    while (current)
		{
	        if (current->uid == userId && !current->returned)
			{
	            found =true;
	            cout << left << setw(10) << current->id << "\t"<< left << setw(25) << (current->title) << "\t"<< left << setw(20) << (current->author) << "\t"<< current->borrowDate << "\t\t"<< current->returnDate << endl;
	        }
	        current = current->next;
	    }
	
	    if(!found)
		{
	        cout << "No borrowed magazine found.\n";
	    }
	
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	
	    // Clean up memory
	    while (head)
		{
	        BorrowedBook* temp = head;
	        head = head->next;
	        delete temp;
	    }
	
	    cout << "\nPress Enter to continue...";
	    cin.get();
	}

    //function for borrow book
    void borrowBook() {
    	
    	string bookId, line, bookTitle, bookAuthor, bookYear, id, title, author, year, available;;
    	
    	CustomerNode* temp = head;
    	
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
        cout << "Enter Book ID to borrow: ";
        getline(cin, bookId);

        // Read books from file
        ifstream bFile("books.txt");
        if (!bFile){
            cerr << "Error opening books file!\n";
            return;
        }

        // Temporary linked list for books
        struct BookNode
		{
            string id;
            string title;
            string author;
            string year;
            string available;
            BookNode* next;
        };
        
        BookNode* bookH = NULL;
        BookNode* bookT = NULL;
        bool bookFound = false;
        bool bookAvailable = false;

        // Read books and build linked list
        while (getline(bFile, line))
		{
            if (line.empty()){
            	
            	continue;
			}
            
            stringstream ss(line);
            getline(ss, id, ',');
            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, year, ',');
            getline(ss, available, ',');

            // Create new book node
            BookNode* newBook = new BookNode{id, title, author, year, available, NULL};
            
            // Add to list
            if (!bookH) 
			{
                bookH = bookT = newBook;
            }
			else
			{
                bookT->next = newBook;
                bookT = newBook;
            }
            
            // Check if this is the requested book
            if (id == bookId)
			{
                bookFound = true;
                if (available == "1")
				{
                    bookAvailable = true;
                    bookTitle = title;
                    bookAuthor = author;
                    bookYear = year;
                }
            }
        }
        bFile.close();

        if (!bookFound)
		{
            cout << "Book ID not found!\n";
            
            // Clean up book list
            while (bookH){
                BookNode* temp = bookH;
                bookH = bookH->next;
                delete temp;
            }
            return;
        }

        if (!bookAvailable)
		{
            cout << "Book is not available for borrowing!\n";
            
            // Clean up book list
            while (bookH)
			{
                BookNode* temp = bookH;
                bookH = bookH->next;
                delete temp;
            }
            return;
        }

        // Update book availability in memory for the found book
        BookNode* currentBook = bookH;
        while (currentBook)
		{
            if (currentBook->id == bookId)
			{
                currentBook->available = "0";
                break;
            }
            currentBook = currentBook->next;
        }

        // Update books.txt file
        ofstream bbFile("books.txt");
        currentBook = bookH;
        
        while (currentBook){
            bbFile << currentBook->id << ","<< currentBook->title << ","<< currentBook->author << ","<< currentBook->year << ","<< currentBook->available << ",\n";
            currentBook = currentBook->next;
        }
        bbFile.close();

        // Get current date using ctime
        time_t now = time(0);
        tm* ltm = localtime(&now);
        char borrowDate[11];
        strftime(borrowDate, sizeof(borrowDate), "%Y-%m-%d", ltm);

        // Create borrow record
        string returnDate = "-";
        bool returned = false;

        // Add to borrow list
        BorrowBook* newBorrow = new BorrowBook
		{
            currentUser->getID(), 
            bookId, 
            bookTitle, 
            bookAuthor, 
            stoi(bookYear), 
            borrowDate, 
            returnDate, 
            returned, 
            NULL
        };

        if(!head1)
		{
            head1 = newBorrow;
        }else{
            BorrowBook* temp = head1;
            while (temp->next)
			{
                temp = temp->next;
            }
            temp->next = newBorrow;
        }

        // Save to borrowed.txt
        ofstream borbFile("borrowedBook.txt", ios::app);
        borbFile << currentUser->getID() << ","<< bookId << ","<< bookTitle << ","<< bookAuthor << ","<< bookYear << ","<< borrowDate << ","<< returnDate << ","<< "0\n"; // 0 = not returned
        borbFile.close();

        cout << "\nBook borrowed successfully!\n";
        cout << "Due date: " << borrowDate << " + 14 days\n";

        // Clean up book list
        while (bookH)
		{
            BookNode* temp = bookH;
            bookH = bookH->next;
            delete temp;
        }
    }
    
    //function to borrow magazine
    void borrowMagazine() {
    	
    	string magazineId, line, magazineTitle, magazineAuthor, magazineYear, id, title, author, year, available;
    	
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
	    cout << "                                                                       Borrow Magazine\n\n";
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
    	
	    if (!currentUser)
		{
	        cout << "Error: No user logged in!\n";
	        return;
	    }
	
	    // Get magazine ID from user
	    cout << "Enter Magazine ID to borrow: ";
	    getline(cin, magazineId);
	
	    // Read magazines from file
	    ifstream mFile("magazine.txt");
	    if(!mFile){
	        cerr << "Error opening magazines file!\n";
	        return;
	    }
	
	    // Temporary linked list for magazines
	    struct MagazineNode
		{
	        string id;
	        string title;
	        string author;
	        string year;
	        string available;
	        MagazineNode* next;
	    };
	    
	    MagazineNode* magH = NULL;
	    MagazineNode* magT = NULL;
	    bool magazineFound = false;
	    bool magazineAvailable =false;
	
	    // Read magazines and build linked list
	    while (getline(mFile, line))
		{
	        if (line.empty()){
	        	continue;
			}
	        
	        stringstream ss(line);
	        getline(ss, id,',');
	        getline(ss, title, ',');
	        getline(ss, author, ',');
	        getline(ss, year, ',');
	        getline(ss, available, ',');
	
	        // Create new magazine node
	        MagazineNode* newMagazine = new MagazineNode{id, title, author, year, available, NULL};
	        
	        // Add to list
	        if (!magH)
			{
	            magH = magT = newMagazine;
	        }else{
	            magT->next = newMagazine;
	            magT = newMagazine;
	        }
	        
	        // Check if this is the requested magazine
	        if (id == magazineId)
			{
	            magazineFound = true;
	            if (available == "1") {
	                magazineAvailable = true;
	                magazineTitle = title;
	                magazineAuthor = author;
	                magazineYear = year;
	            }
	        }
	    }
	    mFile.close();
	
	    if(!magazineFound)
		{
	        cout << "Magazine ID not found!\n";
	        
	        // Clean up book list
	        while (magH){
	            MagazineNode* temp = magH;
	            magH = magH->next;
	            delete temp;
	        }
	        return;
	    }
	
	        if(!magazineAvailable)
			{
	            cout << "Magazine is not available for borrowing!\n";
	            
	            // Clean up book list
	            while (magH){
	                MagazineNode* temp = magH;
	                magH = magH->next;
	                delete temp;
	            }
	            return;
	        }
	
	    // Update magazine availability in memory
	    MagazineNode* currentMagazine = magH;
	    while (currentMagazine)
		{
	        if (currentMagazine->id == magazineId)
			{
	            currentMagazine->available = "0";
	            break;
	        }
	        currentMagazine = currentMagazine->next;
	    }
	
	    // Update magazine.txt file
	    ofstream mmFile("magazine.txt");
	    currentMagazine = magH;
	    while (currentMagazine)
		{
	        mmFile << currentMagazine->id << ","<< currentMagazine->title << ","<< currentMagazine->author << ","<< currentMagazine->year << ","<< currentMagazine->available << ",\n";
	        currentMagazine = currentMagazine->next;
	    }
	    mmFile.close();
	
	    // Get current date
	    time_t now = time(0);
	    tm* ltm = localtime(&now);
	    char borrowDate[11];
	    strftime(borrowDate, sizeof(borrowDate), "%Y-%m-%d", ltm);
	
	    // Create borrow record
	    BorrowMagazine* newBorrow = new BorrowMagazine
		{
	        currentUser->getID(), 
	        magazineId, 
	        magazineTitle, 
	        magazineAuthor, 
	        stoi(magazineYear), 
	        borrowDate, 
	        "-", 
	        false, 
	        NULL
	    };
	
	    // Add to borrow list
	    if(!head2)
		{
	    	head2 = newBorrow;
	    }else{
	        BorrowMagazine* temp = head2;
	        while (temp->next)
			{
	            temp = temp->next;
	        }
	        temp->next = newBorrow;
	    }
	
	    // Save to borrowed_magazines.txt
	    ofstream bormmFile("borrowedMagazines.txt", ios::app);
	    bormmFile << currentUser->getID() << ","<< magazineId << ","<< magazineTitle << ","<< magazineAuthor << ","<< magazineYear << ","<< borrowDate << ","<< "-" << ","<< "0\n";
	    bormmFile.close();
	
	    cout<< "\nMagazine borrowed successfully!\n";
	    cout << "Due date: " << borrowDate << " + 14 days\n";
	
	    // Clean up
	    while (magH)
		{
	        MagazineNode* temp = magH;
	    	magH = magH->next;
	        delete temp;
	    }
	}

	//function to return book
    void returnBook() {
    	
    	string bookId, line, uid, id, title, author, yearStr, borrowDate, returnDate, returnedStr, year, available;;
    	
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
	    if (!currentUser){
	        cout << "Error: No user logged in!\n";
	        cin.get();
	        return;
	    }
	
	    // Get book ID to return
	    cout << "Enter Book ID to return: ";
	    getline(cin, bookId);
	
	    // Load borrowed books from file
	    ifstream borbFile("borrowedBook.txt");
	    if (!borbFile)
		{
	        cout << "No borrowed books found!\n";
	        cin.get();
	        return;
	    }
	
	    // Temporary structure to hold borrowed books
	    struct TempBorrow 
		{
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
	
	    TempBorrow* tempH = NULL;
	    TempBorrow* tempT = NULL;
	    bool bookFound = false;
	
	    // Read all borrowed books
	    while (getline(borbFile, line))
		{
	        if (line.empty()){
			continue;
			}
	
	        stringstream ss(line);
	        
	        getline(ss, uid, ',');
	        getline(ss, id, ',');
	        getline(ss, title, ',');
	        getline(ss, author, ',');
	        getline(ss, yearStr, ',');
	        getline(ss, borrowDate, ',');
	        getline(ss, returnDate, ',');
	        getline(ss, returnedStr);
	
	        int year = stoi(yearStr);
	        bool returned = (returnedStr == "1");
	
	        // Create new temp node
	        TempBorrow* newBorrow =new TempBorrow{uid, id, title, author, year, borrowDate, returnDate, returned, NULL};
	
	        // Add to temp list
	        if (!tempH)
			{
	            tempH = tempT = newBorrow;
	        }else{
	            tempT->next = newBorrow;
	            tempT = newBorrow;
	        }
	    }
	    borbFile.close();
	
	    // Update the borrowed book record
	    TempBorrow* current = tempH;
	    while (current)
		{
	        if(current->uid == currentUser->getID() && current->id == bookId && !current->returned){
	            bookFound = true;
	            
	            // Get current date
	            time_t now = time(0);
	            tm* ltm = localtime(&now);
	            char returnDate[11];
	            strftime(returnDate, sizeof(returnDate), "%Y-%m-%d", ltm);
	            
	            // Update record
	            current->returnDate = returnDate;
	            current->returned = true;
	            break;
	        }
	        current = current->next;
	    }
	
	    if (!bookFound){
	        cout << "Book not found in your borrowed items or already returned.\n";
	        
	        // Clean up temp list
	        while(tempH)
			{
	            TempBorrow* temp= tempH;
	            tempH = tempH->next;
	            delete temp;
	        }
	        cin.get();
	        return;
	    }
	
	    // Update books.txt to mark book as available
	    ifstream bFile("books.txt");
	    if (!bFile)
		{
	        cerr << "Error opening books file!\n";
	        cin.get();
	        return;
	    }
	
	    struct BookNode
		{
	        string id;
	        string title;
	        string author;
	        string year;
	        string available;
	        BookNode* next;
	    };
	
	    BookNode* bookH = NULL;
	    BookNode* bookT = NULL;
	
	    // Read all books
	    while (getline(bFile, line))
		{
	        if (line.empty()){
	        	
	        	continue;
			}
	
	        stringstream ss(line);
	        getline(ss, id, ',');
	        getline(ss, title, ',');
	        getline(ss, author, ',');
	        getline(ss, year, ',');
	        getline(ss, available, ',');
	
	        BookNode* newBook = new BookNode{id, title, author, year, available, NULL};
	
	        if (!bookH)
			{
	            bookH = bookT = newBook;
	        }else{
	            bookT->next = newBook;
	            bookT = newBook;
	        }
	    }
	    bFile.close();
	
	    // Update book availability
	    BookNode* currentBook = bookH;
	    while(currentBook)
		{
	        if (currentBook->id == bookId)
			{
	            currentBook->available = "1";
	            break;
	        }
	        currentBook = currentBook->next;
	    }
	
	    // Save updated books.txt
	    ofstream bbFile("books.txt");
	    currentBook = bookH;
	    while (currentBook)
		{
	        bbFile << currentBook->id << ","<< currentBook->title << ","<< currentBook->author << ","<< currentBook->year << ","<< currentBook->available << ",\n";
	        currentBook =currentBook->next;
	    }
	    bbFile.close();
	
	    // Save updated borrowed books
	    ofstream borbbFile("borrowedBook.txt");
	    current = tempH;
	    while (current)
		{
	        borbbFile << current->uid << ","<< current->id << ","<< current->title << ","<< current->author << ","<< current->year << ","<< current->borrowDate << ","<< current->returnDate << ","<< (current->returned ? "1" : "0") << "\n";
	        current = current->next;
	    }
	    borbbFile.close();
	
	    // Update in-memory borrowed books list
	    BorrowBook* currentBorrow = head1;
	    while (currentBorrow)
		{
	        if (currentBorrow->uid == currentUser->getID() && currentBorrow->id == bookId)
			{
	        	char returnDate[11];
	            time_t now = time(0);
	            tm* ltm = localtime(&now);
	            
	            strftime(returnDate, sizeof(returnDate), "%Y-%m-%d", ltm);
	            
	            currentBorrow->returnDate = returnDate;
	            currentBorrow->available = true;
	            break;
	        }
	        currentBorrow = currentBorrow->next;
	    }
	
	    // Clean up temp lists
	    while(tempH)
		{
	        TempBorrow* temp = tempH;
	        tempH = tempH->next;
	        delete temp;
	    }
	    while (bookH)
		{
	        BookNode* temp = bookH;
	        bookH = bookH->next;
	        delete temp;
	    }
	
	    cout << "\nBook returned successfully!\n";
	    cin.get();
	}
	
	//return magazine function
	void returnMagazine() {
		
		string magazineId, line, uid, id, title, author, yearStr, borrowDate, returnDate, returnedStr, year, available;
		
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
	
	    if (!currentUser)
		{
	        cout << "Error: No user logged in!\n";
	        cin.get();
	        return;
	    }
	
	    cout << "Enter Magazine ID to return: ";
	    getline(cin, magazineId);
	
	    // Load borrowed magazines from file
	    ifstream bormFile("borrowedMagazines.txt");
	    if(!bormFile)
		{
	        cout << "No borrowed magazines found!\n";
	        cin.get();
	        return;
	    }
	
	    // Temporary structure to hold borrowed magazines
	    struct TempBorrow
		{
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
	
	    TempBorrow* tempH = NULL;
	    TempBorrow* tempT = NULL;
	    bool magazineFound = false;
	
	    // Read all borrowed magazines
	    while (getline(bormFile, line))
		{
	        if (line.empty()){
	        	continue;
			}
	
	        stringstream ss(line);
	        
	        getline(ss, uid, ',');
	        getline(ss, id, ',');
	        getline(ss, title, ',');
	        getline(ss, author, ',');
	        getline(ss, yearStr, ',');
	        getline(ss, borrowDate, ',');
	        getline(ss, returnDate, ',');
	        getline(ss, returnedStr, ',');
	
	        int year = stoi(yearStr);
	        bool returned = (returnedStr == "1");
	
	        // Create new temp node
	        TempBorrow* newBorrow = new TempBorrow{uid, id, title, author, year, borrowDate, returnDate, returned, NULL};
	
	        // Add to temp list
	        if (!tempH)
			{
	            tempH = tempT = newBorrow;
	        }else{
	            tempT->next = newBorrow;
	            tempT = newBorrow;
	        }
	    }
	    bormFile.close();
	
	    // Update the borrowed magazine record
	    TempBorrow* current = tempH;
	    while (current)
		{
	        if(current->uid == currentUser->getID() && current->id == magazineId && !current->returned)
			{
	            magazineFound = true;
	            
	            // Get current date
	            time_t now = time(0);
	            tm* ltm = localtime(&now);
				char returnDate[11];
	            strftime(returnDate, sizeof(returnDate), "%Y-%m-%d", ltm);
	            
	            // Update record
	            current->returnDate = returnDate;
	            current->returned = true;
	            break;
	        }
	        current = current->next;
	    }
	
	    if (!magazineFound)
		{
	        cout << "Magazine not found in your borrowed items or already returned.\n";
	        
	        // Clean up temp list
	        while (tempH)
			{
	            TempBorrow* temp =tempH;
	            tempH = tempH->next;
	            delete temp;
	        }
	        cin.get();
	        return;
	    }
	
	    // Update magazine.txt to mark magazine as available
	    ifstream mFile("magazine.txt");
	    if (!mFile){
	        cerr << "Error opening magazines file!\n";
	        cin.get();
	        return;
	    }
	
	    struct MagazineNode
		{
	        string id;
	        string title;
	        string author;
	        string year;
	        string available;
	        MagazineNode* next;
	    };
	
	    MagazineNode* magH = NULL;
	    MagazineNode* magT = NULL;
	
	    // Read all magazines
	    while (getline(mFile, line))
		{
	        if (line.empty()){
	        	
	        	continue;
			}
	
	        stringstream ss(line);
	        getline(ss, id, ',');
	        getline(ss, title, ',');
	        getline(ss, author, ',');
	        getline(ss, year, ',');
	        getline(ss, available, ',');
	
	        MagazineNode* newMagazine = new MagazineNode{id, title, author, year, available, NULL};
	
	        if(!magH)
			{
	            magH = magT = newMagazine;
	        }else{
	            magT->next = newMagazine;
	            magT = newMagazine;
	        }
	    }
	    mFile.close();
	
	    // Update magazine availability
	    MagazineNode* currentMagazine = magH;
	    while (currentMagazine)
		{
	        if (currentMagazine->id == magazineId)
			{
	            currentMagazine->available = "1";
	            break;
	        }
	        currentMagazine =currentMagazine->next;
	    }
	
	    // Save updated magazines.txt
	    ofstream mmFile("magazine.txt");
	    currentMagazine = magH;
	    while (currentMagazine){
	        mmFile << currentMagazine->id << ","<< currentMagazine->title << ","<< currentMagazine->author << ","<< currentMagazine->year << ","<< currentMagazine->available << ",\n";
	        currentMagazine = currentMagazine->next;
	    }
	    mmFile.close();
	
	    // Save updated borrowed magazines
	    ofstream bormmFile("borrowedMagazines.txt");
	    current = tempH;
	    while (current)
		{
	        bormmFile << current->uid << ","<< current->id << ","<< current->title << ","<< current->author << ","<< current->year << ","<< current->borrowDate << ","<< current->returnDate << ","<< (current->returned ? "1" : "0") << "\n";
	        current = current->next;
	    }
	    bormmFile.close();
	    
	    // Update in-memory borrowed magazines list
	    BorrowMagazine* currentBorrow = head2;
	    while (currentBorrow)
		{
	        if (currentBorrow->uid == currentUser->getID() && currentBorrow->id == magazineId)
			{
	            time_t now = time(0);
	            tm* ltm = localtime(&now);
	            char returnDate[11];
	            strftime(returnDate, sizeof(returnDate), "%Y-%m-%d", ltm);
	            
	            currentBorrow->returnDate = returnDate;
	            currentBorrow->available = true;
	            break;
	        }
	        currentBorrow = currentBorrow->next;
	    }
	
	    // Clean up temp lists
	    while (tempH)
		{
	        TempBorrow* temp = tempH;
	        tempH = tempH->next;
	        delete temp;
	    }
	    while (magH)
		{
	        MagazineNode* temp = magH;
	        magH = magH->next;
	        delete temp;
	    }
	
	    cout << "\nMagazine returned successfully!\n";
	    cin.get();
	}
	
	//view borrowed history function
	void viewBorrowHistory()
	{
		
		string currentID = currentUser->getID(), line, uid, id, title, author, yearStr, borrowDate, returnDate, returnedStr;
		int totalCount = 0, count = 1;;
		char choice;
		
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
	    if (!currentUser){
	        cout << "Error: No user logged in!\n";
	        cin.get();
	        return;
	    }
	
	    // Display books history
	    cout << "Book Borrowing History:\n\n";
	    cout << setw(5) << "No." << setw(15) << "Book ID" << setw(30) << "Title" << setw(25) << "Author" << setw(15) << "Borrow Date" << setw(15) << "Return Date" << "\n";
	    cout << string(110, '-') << "\n";
	
	    // Read book history
	    ifstream borbFile("borrowedBook.txt");
	    bool bookFound = false;
	
	    while (getline(borbFile,line))
		{
	        if (line.empty())
			{
	        	continue;
			}
	
	        stringstream ss(line);
	        getline(ss, uid, ',');
	        getline(ss, id, ',');
	        getline(ss, title, ',');
	        getline(ss, author, ',');
	        getline(ss, yearStr, ',');
	        getline(ss, borrowDate, ',');
	        getline(ss, returnDate, ',');
	        getline(ss, returnedStr, ',');
	
	        if(uid == currentID && returnedStr == "1")
			{
	            bookFound = true;
	            totalCount++;
	            cout << setw(5) << count++ << setw(15) << id << setw(30) << (title.length() > 28 ? title.substr(0, 25) + "..." : title)<< setw(25) << (author.length() > 23 ? author.substr(0, 20) + "..." : author)<< setw(15) << borrowDate<< setw(15) << returnDate << "\n";
	        }
	    }
	    borbFile.close();
	
	    if (!bookFound)
		{
	        cout << "No book borrowing history found.\n";
	    }
	    // Display magazines history
	    count = 1;  // Reset count for magazines
	    cout << "\n\nMagazine Borrowing History:\n\n";
	    cout << setw(5) << "No." << setw(15) << "Magazine ID" << setw(30) << "Title" << setw(25) << "Author" << setw(15) << "Borrow Date" << setw(15) << "Return Date" << "\n";
	    cout << string(100, '-') << "\n";
	
	    // Read magazine history
	    ifstream bormFile("borrowedMagazines.txt");
	    bool magazineFound = false;
	
	    while (getline(bormFile, line))
		{
	        if (line.empty()){
	        	continue;
			}
	
	        stringstream ss(line);
	        getline(ss, uid, ',');
	        getline(ss, id, ',');
	        getline(ss, title, ',');
	        getline(ss, author, ',');
	        getline(ss, yearStr, ',');
	        getline(ss, borrowDate, ',');
	        getline(ss, returnDate, ',');
	        getline(ss, returnedStr, ',');
	
	        if (uid == currentID && returnedStr == "1")
			{
	            magazineFound = true;
	            totalCount++;
	            cout << setw(5) << count++ << setw(15) << id << setw(30) << (title.length() > 28 ? title.substr(0, 25) + "..." : title)<< setw(25) << (author.length() > 23 ? author.substr(0, 20) + "..." : author)<< setw(15) << borrowDate<< setw(15) << returnDate << "\n";
	        }
	    }
	    bormFile.close();
	
	    if (!magazineFound){
	        cout << "No magazine borrowing history found.\n";
	    }
	
	    cout << "\nTotal borrowing history items: " << totalCount << "\n";
	    
		cout << "\nDo you want to generate a borrowing report file? (Y/N): ";
		cin >> choice;
		
		if (choice == 'Y' || choice == 'y')
		{
		    ofstream output("Borrow_History_Report.txt");
		    output << "JR Library - Borrow History Report\n";
		    output << "User ID: " << currentID << "\n\n";
		
		    // Book History
		    output << "Book Borrowing History:\n";
		    output << setw(5) << "No." << setw(15) << "Book ID" << setw(30) << "Title"<< setw(25) << "Author" << setw(15) << "Borrow Date" << setw(15) << "Return Date" << "\n";
		    output << string(100, '-') << "\n";
		
		    // Reset file read for books
		    ifstream borbbFile("borrowedBook.txt");
		    int bookCount = 1;
		    while (getline(borbbFile, line))
			{
		        if (line.empty()){
		        	
		        	continue;
				}
		
		        stringstream ss(line);
		        getline(ss, uid, ',');
		        getline(ss, id, ',');
		        getline(ss, title, ',');
		        getline(ss, author, ',');
		        getline(ss, yearStr, ',');
		        getline(ss, borrowDate, ',');
		        getline(ss, returnDate, ',');
		        getline(ss, returnedStr, ',');
		
		        if(uid == currentID && returnedStr == "1")
				{
		            output << setw(5) << bookCount++<< setw(15) << id<< setw(30) << title<< setw(25) << author<< setw(15) << borrowDate << setw(15) << returnDate << "\n";
		        }
		    }
		    borbbFile.close();
		
		    if (bookCount ==1){
		    	
		        output << "No book borrowing history found.\n";
		    }
		
		    // Magazine History
		    output << "\nMagazine Borrowing History:\n";
		    output << setw(5) << "No." << setw(15) << "Magazine ID" << setw(30) << "Title"<< setw(25) << "Author" << setw(15) << "Borrow Date" << setw(15) << "Return Date" << "\n";
		    output << string(100, '-') << "\n";
		
		    // Reset file read for magazines
		    ifstream bormmFile("borrowedMagazines.txt");
		    int magCount = 1;
		    while (getline(bormmFile, line))
			{
		        if (line.empty()){
		        	
		        	continue;
				}
		
		        stringstream ss(line);
		        getline(ss, uid, ',');
		        getline(ss, id, ',');
		        getline(ss, title, ',');
		        getline(ss, author, ',');
		        getline(ss, yearStr, ',');
		        getline(ss, borrowDate, ',');
		        getline(ss, returnDate, ',');
		        getline(ss, returnedStr, ',');
		
		        if(uid == currentID && returnedStr == "1")
				{
		            output << setw(5) << magCount++<< setw(15) << id<< setw(30) << title<< setw(25) << author<< setw(15) << borrowDate<< setw(15) << returnDate << "\n";
		        }
		    }
		    bormmFile.close();
		
		    if (magCount == 1)
			{
		        output << "No magazine borrowing history found.\n";
		    }
		
		    // Total count
		    output << "\nTotal borrowing history items: " << totalCount << "\n";
		    output.close();
		    cout << "Report generated: Borrow_History_Report.txt\n"; 
		    cin.get();
		}else{
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
    
    // Validate sort choice before entering the sorting loop
    if (sortChoice < 1 || sortChoice > 4) {
        cout << "Invalid sort option." << endl;
        cout << "Press Enter to continue...";
        cin.get();
        return;
    }
    
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
    
    // Validate sort choice before entering the sorting loop
    if (sortChoice < 1 || sortChoice > 4) {
        cout << "Invalid sort option." << endl;
        cout << "Press Enter to continue...";
        cin.get();
        return;
    }
    
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
                    // Default case removed - validation happens before the loop
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
	    cout << "                              |                                        18. View Borrowed Book by user                                      |" << endl;
	    cout << "                              |                                        19. Books Borrowed Record                                           |" << endl;
	    cout << "                              |                                        20. View Borrowed Magazine by user                                  |" << endl;
	    cout << "                              |                                        21. Magazine Borrowed Record                                        |" << endl;
	    cout << "                              |                                        22. Sort Books                                                      |" << endl;
	    cout << "                              |                                        23. Search Books                                                    |" << endl;
	    cout << "                              |                                        24. Sort Magazine                                                   |" << endl;
	    cout << "                              |                                        25. Search Magazine                                                 |" << endl;
	    cout << "                              |                                        26. Logout                                                          |" << endl;
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
				cin.ignore();  // Clear any leftover characters
				cin.get();
				break;
			case 2:
				system("cls");
				admin.editAdmin();
				admin.saveAdminToFile(); 
				admin.loadAdminsFromFile();
				cout<<"Press Enter To Continue...";
				cin.ignore();  // Clear any leftover characters
				cin.get();
				break;
			case 3:
				system("cls");
				admin.removeAdmin();
				admin.saveAdminToFile();
				admin.loadAdminsFromFile();
				cout<<"Press Enter To Continue...";
				cin.ignore();  // Clear any leftover characters
				cin.get();
				break;
			case 4:
				system("cls");
				admin.displayAdmin();
				cout<<"Press Enter To Continue...";
				cin.ignore();  // Clear any leftover characters
				cin.get();
				break;
			case 5:
				system("cls");
				bookRecords.loadBooksFromFile("books.txt");
				admin.addBook(bookRecords);
				cout<< "Press Enter To Continue...";
				cin.ignore();  // Clear any leftover characters
				cin.get();
				break;
			case 6:
				system("cls");
				bookRecords.loadBooksFromFile("books.txt");
				admin.editBook(bookRecords);
				cout<< "Press Enter To Continue...";
				cin.ignore();  // Clear any leftover characters
				cin.get();
				break;
			case 7:
				system("cls");
				bookRecords.loadBooksFromFile("books.txt");
				admin.deleteBook(bookRecords);
				cout<< "Press Enter To Continue...";
				cin.ignore();  // Clear any leftover characters
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
				bookRecords.loadBooksFromFile("magazine.txt");
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
				cin.get();
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
                		system("cls");
                		customer.borrowBook();
                		cout << "Press Enter To Continue...";
						cin.get();
                		break;
                	case 2:
                		customer.returnBook();
                		cout << "Press Enter To Continue...";
						cin.get();
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
                		system("cls");
                		customer.borrowMagazine();
                		cout << "Press Enter To Continue...";
						cin.get();
                		break;
                	case 2:
                		customer.returnMagazine();
                		cout << "Press Enter To Continue...";
						cin.get();
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
            	cout << "Press Enter To Continue...";
            	cin.get();
            	break;
            case 11:
                cout << "Logging out. Goodbye!\n";
                cin.get();
                return;
            default:
                cout << "Invalid Choice...";
                cin.ignore();  // Clear any leftover characters
                cin.get();
        }
    } while(choice != 11);
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
