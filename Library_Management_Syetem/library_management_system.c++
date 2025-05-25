#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
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
protected:
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
public:
    BookRecord();
    virtual ~BookRecord();
    void insertBook(int, string, string, int);
    void deleteBookById(int);
    void displayBooks();
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
	
	void displayAdmin()
	{
		
	}

	
    void addBook();
	void editBook();
    void deleteBook();
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
    void borrowBook();
    void returnBook();
    void viewBorrowed();
    //void display() const override;
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
void customerMenu(Customer&);
void loadSampleBooks(Library&);
void mainMenu();

// =============== Main Function ===================

int main() {
    return 0;
} 