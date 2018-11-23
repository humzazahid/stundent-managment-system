#include <iostream>
#include <windows.h>                  // For gotoxy() and Sleep function
#include <conio.h>
//#include <algorithm>
#include <ctype.h>                  // For isalpha() function
//#include<minmax.h>
using namespace std;
using namespace std;
static int height = 0;


class records
{
private:
	struct student
	{
		int roll;
		char name[30];
		char fname[30];   //father name
		float cgpa;

		student *left;
		student *right;
	};

public:
	student *root;      //intailing  pionting at null
	records();
	void insert();
	void display(int);
	void show1(student *&);
	void show4(student *&);
	void search();
	void deleteRecords();
	int remove(int rn, student *&, int &found);
	void del(student *&nodeptr);
	void totalNodes();
	int findHeight(student *&);
	void findDepthOfNode();
	void studentMenu();
};

records r;

records::records()
{
	root = NULL;           //construtor intailizing the root with NULL
}

void records::insert()
{
	system("cls");

label:                           //act as a point to restart  the function using goto        
	student *newnode, *nodeptr;
	char ch;

	cout << "\n\n**********************RECORDS INSERTION***********************";
	do
	{
		system("cls");
		newnode = new student;

		cout << "\n\n Enter Roll Number of Student: ";
		while (1)        //we are using 1 as a check
		{
			cin >> newnode->roll;
			if (cin.fail() || newnode->roll < 1)
			{
				cin.clear();
				//cin.ignore(numeric_limits<streamsize> ::max(), '\n');
				cout << "\nInvalid Input...\nPlease Enter a Roll No. greater than or equal to 1: ";
			}
			else
				break;
		}

		student *temp = new student;     //checking roll number is already present 
		temp = root;
		while (temp != NULL)
		{
			if (newnode->roll == temp->roll)
			{
				cout << "\n\n This Roll No. has already been used";
				cout << "\n\n\t Please Enter a unique Roll NO. \n\n";
				system("pause");
				goto label;				//using to restart the same process
				break;
			}
			else if (newnode->roll > temp->roll)
			{
				temp = temp->right;
			}
			else if (newnode->roll < temp->roll)
			{
				temp = temp->left;
			}
		}

	label1:                                         //on to this if alphabet is not entered
		cout << "\n\n Enter Name of Student: ";
		cin.ignore();
		cin.getline(newnode->name, 30);

		int check1 = 0;
		for (int i = 0; i < strlen(newnode->name); i++) {
			if (isalpha(newnode->name[i]) == 0) {
				if (newnode->name[i] == ' ')
				{
					check1 = 0;
				}
				else
				{
					cout << "\n\nInvalid Input...\nPlease Enter alphabets only:";
					check1 = 1;
					break;
				}
			}
		}
		if (check1 == 1)
		{
			goto label1;
		}

	label2:
		cout << "\n\n Enter Father Name of Student: ";
		cin.getline(newnode->fname, 30);

		int check2 = 0;
		for (int j = 0; j < strlen(newnode->fname); j++) {
			if (isalpha(newnode->fname[j]) == 0) {
				if (newnode->fname[j] == ' ')
				{
					check2 = 0;
				}
				else
				{
					cout << "\n\nInvalid Input...\nPlease Enter alphabets only:";
					check2 = 1;
					break;
				}
			}
		}
		if (check2 == 1)
		{
			goto label2;
		}

		cout << "\n\n Enter CGPA of Student (out of 4.0): ";

		while (1)
		{
			cin >> newnode->cgpa;
			if (cin.fail() || (newnode->cgpa < 0.0) || (newnode->cgpa > 4.0))
			{
				cin.clear();
//				cin.ignore(numeric_limits<streamsize> ::max(), '\n');
				cout << "\nInvalid Input...\nPlease Enter CGPA ranging from 0.0 to 4.0: ";
			}
			else
				break;
		}

		newnode->left = NULL;
		newnode->right = NULL;

		if (root == NULL)
		{
			root = newnode;
			height++;
		}

		else
		{
			nodeptr = root;
			while (nodeptr != NULL)
			{
				if (newnode->roll < nodeptr->roll)
				{
					if (nodeptr->left != NULL)
					{
						nodeptr = nodeptr->left;
					}
					else
					{
						nodeptr->left = newnode;
						height++;
						break;
					}
				}

				else if (newnode->roll > nodeptr->roll)
				{
					if (nodeptr->right != NULL)
					{
						nodeptr = nodeptr->right;
					}
					else
					{
						nodeptr->right = newnode;
						height++;
						break;
					}
				}
			}
		}
		cout << "\n\n\t Do you want to enter more Records ? \n\n";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}

void records::show1(student *&temp)   //used to display all the data at the right side of tree
{
	if (temp != NULL)
	{
		show1(temp->left);
		cout << "\n\n\n\n Roll-No: " << temp->roll;
		cout << "\n\n Name: " << temp->name;
		cout << "\n\n Father's Name: " << temp->fname;
		cout << "\n\n CGPA: " << temp->cgpa;
		show1(temp->right);
	}
}

void records::show4(student *&temp)       //used to display all the data at the right side of tree
{
	if (temp != NULL)
	{
		show4(temp->right);
		cout << "\n\n\n\n Roll-No: " << temp->roll;
		cout << "\n\n Name: " << temp->name;
		cout << "\n\n Father's Name: " << temp->fname;
		cout << "\n\n CGPA: " << temp->cgpa;
		show4(temp->left);
	}
}

void records::display(int choice)
{
	system("cls");
	if (root == NULL)
	{
		cout << "\n\n\tPlease Enter some Record First...\n\n";
		return;
	}
	cout << "\n\n _________________________RECORDS DISPLAY_________________________";
	if (choice == 1)
	{
		records::show1(root);			//right side of tree data to show
	}
	else if (choice == 2)
	{
		records::show4(root);			//left side  of tree  to show
	}

}

void records::search()
{
	system("cls");
	if (root == NULL)
	{
		cout << "\n\n\tPlease Enter Some Record First...\n\n";
		return;
	}
	int rn, check = 0;
	student *temp;
	cout << "\n\n _________________________RECORDS SEARCH_________________________";
	cout << "\n\n Please Enter Roll No. of Student to Search: ";
	while (1)
	{
		cin >> rn;
		if (cin.fail() || rn < 1)
		{
			cin.clear();
//			cin.ignore(numeric_limits<streamsize> ::max(), '\n');
			cout << "\nInvalid Input...\nPlease Enter a Roll No. greater than or equal to 1: ";
		}
		else
			break;
	}

	temp = root;
	while (temp != NULL)
	{
		if (temp->roll == rn)
		{
			cout << "\n\n\n\n Roll-No: " << temp->roll;
			cout << "\n\n Name: " << temp->name;
			cout << "\n\n Father's Name: " << temp->fname;
			cout << "\n\n CGPA: " << temp->cgpa;
			check = 1;
			break;
		}

		else if (rn < temp->roll)
		{
			temp = temp->left;
		}

		else if (rn > temp->roll)
		{
			temp = temp->right;
		}
	}
	if (check == 0)
	{
		cout << "\n\n\t Record of Student with Roll NO. " << rn << " not Found...!\n\n";
		return;
	}
}

int records::remove(int rn, student *&nodeptr, int &found)
{
	if (nodeptr == NULL)
	{
		return found;
	}

	else if (rn < nodeptr->roll)
	{
		records::remove(rn, nodeptr->left, found);
	}

	else if (rn > nodeptr->roll)
	{
		records::remove(rn, nodeptr->right, found);
	}
	else if (rn == nodeptr->roll)
	{
		found = 1;
		records::del(nodeptr);
	}

	return found;
}

void records::del(student *&nodeptr)
{
	student *temp;
	// if no Child
	if (nodeptr->left == NULL && nodeptr->right == NULL)
	{
		delete nodeptr;
		nodeptr = NULL;
	}
	// if only Left Child		
	else if (nodeptr->right == NULL)
	{
		temp = nodeptr;
		nodeptr = nodeptr->left;
		delete temp;
		height--;
		cout << "\n\n RECORD DELETED SUCCESSFULLY...\n";
	}
	// if only Right Child
	else if (nodeptr->left == NULL)
	{
		temp = nodeptr;
		nodeptr = nodeptr->right;
		delete temp;
		height--;
		cout << "\n\n RECORD DELETED SUCCESSFULLY...\n";
	}
	else if (nodeptr->right != NULL && nodeptr->left != NULL)
	{
		temp = nodeptr->right;

		while (temp->left != NULL)   // Traversing to find Min
		{
			temp = temp->left;
		}
		temp->left = nodeptr->left;

		temp = nodeptr;
		nodeptr = nodeptr->right;
		delete temp;

		height--;
		cout << "\n\n RECORD DELETED SUCCESSFULLY...\n";
	}
	return;
}


void records::deleteRecords()
{
	system("cls");
	int rn, f = 0, found = 0;

	if (r.root == NULL)
	{
		cout << "Please Enter some Record First....";
		return;
	}

	cout << "\n\n _________________________RECORDS DELETION_________________________";
	cout << "\n\n\tPlease Enter Roll No. of student to Delete: ";

	while (1)
	{
		cin >> rn;
		if (cin.fail() || rn < 1)
		{
			cin.clear();
			//cin.ignore(numeric_limits<streamsize> ::max(), '\n');
			cout << "\nInvalid Input...\nPlease Enter a Roll No. greater than or equal to 1: ";
		}
		else
			break;
	}

	f = r.remove(rn, r.root, found);

	if (f == 0)
	{
		cout << "\n\n\t Record of Student with Roll NO. " << rn << " not Found...!\n\n";
		return;
	}

}

void records::totalNodes()
{
	system("cls");
	if (height == 0)
	{
		cout << "\n\n\t Please Insert Some Records First...";
		return;
	}
	else
	{
		cout << "\n\n Total Number of Students are: " << height;
	}
}

void records::findDepthOfNode()
{
	system("cls");
	int rn;
	int count = 0;
	int check = 0;
	student *temp;

	if (height == 0)
	{
		cout << "Please Enter some Record First....";
		return;
	}
	else
	{
		cout << "\n _________________________DEPTH OF NODE_________________________";
		cout << "\n\n Enter Roll No. of Student to Find the Depth of Node: ";

		while (1)
		{
			cin >> rn;
			if (cin.fail() || rn < 1)
			{
				cin.clear();
				//cin.ignore(numeric_limits<streamsize> ::max(), '\n');
				cout << "\nInvalid Input...\nPlease Enter a Roll No. greater than or equal to 1: ";
			}
			else
				break;
		}

		temp = root;
		while (temp != NULL)
		{
			if (temp->roll == rn)   //comparing with root node 
			{
				cout << "\n\n Depth of Node you Entered starting From Zero is: " << count;
				check = 1;
				break;
			}
			else if (rn < temp->roll)
			{
				temp = temp->left;
				count++;
			}
			else if (rn > temp->roll)
			{
				temp = temp->right;
				count++;
			}
		}
		if (check == 0)
		{
			cout << "\n\nThe Student with Roll No. " << rn << " was not FOUND...\n\n";
		}
	}
}

void records::studentMenu()
{
	system("cls");

	int choice;
	while (true)
	{
		system("cls");
		cout << "\n\n  _________________________STUDENT RECORD DATABASE_________________________";
		cout << "\n\n 1: Enter Record ";
		cout << "\n\n 2: Display Records in Ascending Order";
		cout << "\n\n 3: Display Records in Descending Order";
		cout << "\n\n 4: Search Record ";
		cout << "\n\n 5: Delete Record ";
		cout << "\n\n 6: Check Total No. of Students";
		cout << "\n\n 7: Depth of Specific Node ";
		cout << "\n\n 8: Exit ";
		cout << "\n\n Enter your Choice: ";

	label1:
		choice = _getch();

		if (choice >= '1' && choice <= '9')
		{
			goto label2;
		}
		goto label1;

	label2:
		cout << choice - 48; //for getting ascii value

		system("cls");
		switch (choice)
		{
		case '1':
			r.insert();
			cout << "\n\n\t";
			system("pause");
			break;
		case '2':
			r.display(1);
			cout << "\n\n\t";
			system("pause");
			break;
		case '3':
			r.display(2);
			cout << "\n\n\t";
			system("pause");
			break;
		case '4':
			r.search();
			cout << "\n\n\t";
			system("pause");
			break;
		case '5':
			r.deleteRecords();
			cout << "\n\n\t";
			system("pause");
			break;
		case '6':
			r.totalNodes();
			cout << "\n\n\t";
			system("pause");
			break;
		case '7':
			r.findDepthOfNode();
			cout << "\n\n\t";
			system("pause");
			break;
		case '8':
			exit(0);
			break;
		default:
			cout << "\n\n Please Enter a valid Choice: \n\n";
			system("pause");
			break;
		}
	}
}
