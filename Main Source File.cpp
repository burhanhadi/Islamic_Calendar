#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<iomanip>
#include<windows.h>
#include<conio.h>
using namespace std;
struct Admin_Database
{
	string username[5] = { "hadi", "haseeb", "hashim", "maysam", "ali" };
	string password[5] = { "Charon", "haseeb123", "hashim123", "maysam123", "ali123" };
}admin_db;
void invalidinput()
{
	cin.clear();
	cin.ignore(10000, '\n');
}
void calendarheader()
{
	cout << setw(85) << setfill('-') << "-" << endl;
	cout << "|" << right << setw(84) << setfill(' ') << "|" << endl;
	cout << "|" << right << setw(49) << setfill(' ') << " Hijri Calendar " << setw(35) << setfill(' ') << "|" << endl;
	cout << "|" << right << setw(84) << setfill(' ') << "|" << endl;
	cout << setw(85) << setfill('-') << "-" << endl;
}
void mainmenu()
{
	calendarheader();
	cout << "|" << right << setw(45) << setfill(' ') << "Main Menu" << setw(38) << setfill(' ') << " " << "|" << endl;
	cout << setw(85) << setfill('-') << "-" << endl;
	cout << "|" << right << setw(84) << setfill(' ') << "|" << endl;
	cout << "|" << right << setw(84) << setfill(' ') << "|" << endl;
	cout << "|" << right << setw(84) << setfill(' ') << "|" << endl;
	cout << "|" << right << setw(84) << setfill(' ') << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "              1. Administrator Login" << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "              2. User Login" << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "              3. Register as new user" << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "              4. Exit" << "|";
	cout << endl << endl << endl << endl << endl << "    	        Enter your choice: ";
}
int login(int choice, string& username, char ch)
{
	int i = 0, no_of_try = 0;
	string ext{ ".txt" }, password, line;
entry:
	calendarheader();
	if (choice == 1)
	{
		cout << "|" << right << setw(51) << setfill(' ') << "Administrator Login" << setw(32) << setfill(' ') << " " << "|" << endl;
	}
	else
	{
		cout << "|" << right << setw(46) << setfill(' ') << "User Login" << setw(37) << setfill(' ') << " " << "|" << endl;
	}
	cout << setw(85) << setfill('-') << "-" << endl << endl << endl << endl << endl << endl;
	if (no_of_try == 3)
	{
		if (choice == 1)
		{
			cout << endl << endl << endl << endl << endl << "\t\t\tMaximum number of tries reached" << endl << "\t\t\tPlease contact Chief Administrative Officer";
		}
		else
		{
			cout << endl << "\t\t\tMaximum number of tries reached" << endl << "\t\t\tPlease reset your password";
		}
		Sleep(4000);
		system("cls");
		return 1;
	}
	no_of_try++;
	cout << right << setw(38) << setfill(' ') << "Username: ";
	cin >> username;
	if (choice == 1)
	{
		for (int i = 0; i <= 5; i++)
		{
			if (username == admin_db.username[i])
			{
				goto password;
			}
		}
	}
	else if (choice == 2)
	{
		fstream user(username + ext, ios::in);
		while (getline(user, line))
		{
			size_t pos = line.find(username);
			if (pos != string::npos)
			{
				user.close();
				goto password;
			}
		}
		user.close();
	}
	cout << endl << endl << endl << endl << endl << "\t\t\t   User not found" << "\n\t\t\t   Do you want to retry (Y / N): ";
	cin >> ch;
	while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n')
	{
		invalidinput();
		cout << "\t\t\t   Invalid choice entered, retry: ";
		cin >> ch;
	}
	if (ch == 'Y' || ch == 'y')
	{
		system("cls");
		goto entry;
	}
	else
	{
		system("cls");
		return 1;
	}
password:
	cout << right << setw(38) << setfill(' ') << "Password: ";
	while ((ch = _getch()) != '\r')
	{
		if (ch == '\b')
		{
			if (password.size() > 0)
			{
				password.erase(password.size() - 1, 1);
				cout << "\b \b";
			}
		}
		else
		{
			password.push_back(ch);
			cout.put('*');
		}
	}
	if (choice == 1)
	{
		for (int i = 0; i <= 5; i++)
		{
			if (password == admin_db.password[i])
			{
				cout << endl << endl << endl << endl << "\t\t\t\tLogin Successfull";
				Sleep(4000);
				system("cls");
				return 0;
			}
		}
	}
	else if (choice == 2)
	{
		fstream user(username + ext, ios::in);
		while (getline(user, line))
		{
			size_t pos = line.find(password);
			if (pos != string::npos)
			{
				cout << endl << endl << endl << endl << "\t\t\t\tLogin Successfull";
				user.close();
				Sleep(4000);
				system("cls");
				return 0;
			}
		}
		user.close();
	}
	cout << endl << endl << endl << endl << "\t\t\t    Wrong Password" << "\n\t\t\t    Do you want to retry(Y/N): ";
	cin >> ch;
	while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n')
	{
		invalidinput();
		cout << "\t\t\t   Invalid choice entered, retry: ";
		cin >> ch;
	}
	if (ch == 'Y' || ch == 'y')
	{
		system("cls");
		goto entry;
	}
	else
	{
		return 1;
	}
}
int newregister()
{
	int day, month, year;
	char ch;
	string ext {".txt"}, username, password, name, confirm_password;
retry:
	calendarheader();
	cout << "|" << right << setw(53) << setfill(' ') << "New User Registration" << setw(30) << setfill(' ') << " " << "|" << endl;
	cout << setw(85) << setfill('-') << "-" << endl << endl << endl << endl << endl << endl;
	cout << right << setw(40) << setfill(' ') << "New Username: ";
	cin >> username;
	cout << right << setw(40) << setfill(' ') << "New Password: ";
	while ((ch = _getch()) != '\r')
	{
		if (ch == '\b')
		{
			if (password.size() > 0)
			{
				password.erase(password.size() - 1, 1);
				cout << "\b \b";
			}
		}
		else
		{
			password.push_back(ch);
			cout.put('*');
		}
	}
	cout << endl << right << setw(48) << setfill(' ') << "Confirm New Password: ";
	while ((ch = _getch()) != '\r')
	{
		if (ch == '\b')
		{
			if (confirm_password.size() > 0)
			{
				confirm_password.erase(confirm_password.size() - 1, 1);
				cout << "\b \b";
			}
		}
		else
		{
			confirm_password.push_back(ch);
			cout.put('*');
		}
	}
	if (password != confirm_password)
	{
		cout << endl << endl << endl << endl << right << setw(51) << setfill(' ') << "Passwords donot match, retry";
		Sleep(4000);
		system("cls");
		goto retry;
	}
	cout << endl << right << setw(47) << setfill(' ') << "Enter you full name: ";
	cin.ignore();
	getline(cin, name);
	cout << right << setw(54) << setfill(' ') << "Date of Birth (DD/MM/YYYY): ";
	cin >> day;
	if (cin.get() != '/')
	{
		cout << "expected /\n";
		return 1;
	}
	cin >> month;
	if (cin.get() != '/')
	{
		cout << "expected /\n";
		return 1;
	}
	cin >> year;
	fstream user(username + ext, ios::out);
	user << "Username: " << username << '\n';
	user << "Password: " << password << '\n';
	user << "Full Name: " << name << '\n';
	user << "Birthday: " << '\n' << "Day: " << day << '\n' << "Month: " << month << '\n' << "Year: " << year;
	user.close();
	cout << endl << endl << endl << right << setw(51) << setfill(' ') << "Registration Successfull";
	Sleep(4000);
	system("cls");
	return 0;
}
void years()
{
	cout << "|" << right << setw(51) << setfill(' ') << "From 1438 to 1442" << setw(32) << setfill(' ') << " " << "|" << endl;
	cout << setw(85) << setfill('-') << "-" << endl;
	cout << "|" << right << setw(22) << setfill(' ') << "Choose the year: " << right << setw(62) << setfill(' ') << "|" << endl;
	cout << "|" << setw(84) << setfill(' ') << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "       1. 1438 AH" << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "       2. 1439 AH" << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "       3. 1440 AH" << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "       4. 1441 AH" << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "       5. 1442 AH" << "|" << endl;
	cout << "|" << right << setw(84) << setfill(' ') << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "       Or press 0 to logout" << "|" << endl;
	cout << endl << endl << endl << "    	        Enter your choice: ";
}
void months()
{
	calendarheader();
	cout << "|" << right << setw(51) << setfill(' ') << "From 1438 to 1442" << setw(32) << setfill(' ') << " " << "|" << endl;
	cout << setw(85) << setfill('-') << "-" << endl;
	cout << "|" << right << setw(23) << setfill(' ') << "Choose the month: " << right << setw(61) << setfill(' ') << "|" << endl;
	cout << "|" << setw(84) << setfill(' ') << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "       1. Muharram" << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "       2. Safar" << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "       3. Rabi' al-awwal" << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "       4. Rabi' al-thani" << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "       5. Jumada al-awwal" << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "       6. Jumada al-thani" << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "       7. Rajab" << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "       8. Sha'ban" << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "       9. Ramadan" << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "       10. Shawwal" << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "       11. Dhu al-Qi'dah" << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "       12. Dhu al-Hijjah" << "|" << endl;
	cout << "|" << right << setw(84) << setfill(' ') << "|" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "       Or press 0 to return to year menu" << "|" << endl;
	cout << endl << endl << endl << "    	        Enter your choice: ";
}
void bar(int year_choose, int month_choose)
{
	calendarheader();
	switch (month_choose)
	{
	case 1:
	{
		cout << "|" << left << setw(43) << setfill(' ') << " Muharram";
		break;
	}
	case 2:
	{
		cout << "|" << left << setw(43) << setfill(' ') << " Safar";
		break;
	}
	case 3:
	{
		cout << "|" << left << setw(43) << setfill(' ') << " Rabi' al-awwal";
		break;
	}
	case 4:
	{
		cout << "|" << left << setw(43) << setfill(' ') << " Rabi' al-thani";
		break;
	}
	case 5:
	{
		cout << "|" << left << setw(43) << setfill(' ') << " Jumada al-awwal";
		break;
	}
	case 6:
	{
		cout << "|" << left << setw(43) << setfill(' ') << " Jumada al-thani";
		break;
	}
	case 7:
	{
		cout << "|" << left << setw(43) << setfill(' ') << " Rajab";
		break;
	}
	case 8:
	{
		cout << "|" << left << setw(43) << setfill(' ') << " Sha'ban";
		break;
	}
	case 9:
	{
		cout << "|" << left << setw(43) << setfill(' ') << " Ramadan";
		break;
	}
	case 10:
	{
		cout << "|" << left << setw(43) << setfill(' ') << " Shawwal";
		break;
	}
	case 11:
	{
		cout << "|" << left << setw(43) << setfill(' ') << " Dhu al-Qi'dah";
		break;
	}
	case 12:
	{
		cout << "|" << left << setw(43) << setfill(' ') << " Dhu al-Hijjah";
		break;
	}
	}
	switch (year_choose)
	{
	case 1:
	{
		cout << right << setw(40) << setfill(' ') << " 1438 AH " << "|" << endl;
		break;
	}
	case 2:
	{
		cout << right << setw(40) << setfill(' ') << " 1439 AH " << "|" << endl;
		break;
	}
	case 3:
	{
		cout << right << setw(40) << setfill(' ') << " 1440 AH " << "|" << endl;
		break;
	}
	case 4:
	{
		cout << right << setw(40) << setfill(' ') << " 1441 AH " << "|" << endl;
		break;
	}
	case 5:
	{
		cout << right << setw(40) << setfill(' ') << " 1442 AH " << "|" << endl;
		break;
	}
	}
	cout << setw(85) << setfill('-') << "-" << endl;
	cout << "|" << setw(7) << setfill(' ') << "Sun" << setw(4) << setfill(' ') << " ";
	cout << "|" << setw(7) << setfill(' ') << "Mon" << setw(4) << setfill(' ') << " ";
	cout << "|" << setw(7) << setfill(' ') << "Tue" << setw(4) << setfill(' ') << " ";
	cout << "|" << setw(7) << setfill(' ') << "Wed" << setw(4) << setfill(' ') << " ";
	cout << "|" << setw(7) << setfill(' ') << "Thu" << setw(4) << setfill(' ') << " ";
	cout << "|" << setw(7) << setfill(' ') << "Fri" << setw(4) << setfill(' ') << " ";
	cout << "|" << setw(7) << setfill(' ') << "Sat" << setw(4) << setfill(' ') << " ";
	cout << "|" << endl;
}
void calendarbody(int, int, int, string&);
int main()
{
	int choice, start_day = 0, end_day = 0, year_choose = 0, month_choose = 0, maneuver = 0;
	char ch = '\0';
	string username, password, name, b_day, b_month;
forward:
	mainmenu();
retry:
	cin >> choice;
	while (choice < 1 || choice > 4)
	{
		invalidinput();
		cout << "    	        Invalid choice, retry: ";
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		system("cls");
		choice = login(choice, username, ch);
		if (choice == 1)
		{
			goto forward;
		}
		break;
	}
	case 2:
	{
		system("cls");
		choice = login(choice, username, ch);
		if (choice == 1)
		{
			goto forward;
		}
		break;
	}
	case 3:
	{
		system("cls");
		newregister();
		goto forward;
		break;
	}
	case 4:
	{
		exit(0);
		break;
	}
	}
next0:
	system("cls");
	calendarheader();
	years();
	cin >> year_choose;
	if (year_choose < 0 || year_choose > 5)
	{
		invalidinput();
		cout << "    	        Invalid choice, retry: ";
		cin >> ch;
	}
	if (year_choose == 0)
	{
		system("cls");
		goto forward;
	}
next1:
	system("cls");
	months();
	cin >> month_choose;
	if (month_choose < 0 || month_choose > 12)
	{
		invalidinput();
		cout << "    	        Invalid choice, retry: ";
		cin >> month_choose;
	}
	if (month_choose == 0)
	{
		system("cls");
		goto next0;
	}
next2:
	system("cls");
	bar(year_choose, month_choose);
	switch (year_choose)
	{
	case 1:
	{
		if (month_choose == 1)
		{
			start_day = 1, end_day = 30;
		}
		else if (month_choose == 2)
		{
			start_day = 1, end_day = 30;
		}
		else if (month_choose == 3)
		{
			start_day = -2, end_day = 30;
		}
		else if (month_choose == 4)
		{
			start_day = -4, end_day = 30;
		}
		else if (month_choose == 5)
		{
			start_day = 1, end_day = 30;
		}
		else if (month_choose == 6)
		{
			start_day = -1, end_day = 29;
		}
		else if (month_choose == 7)
		{
			start_day = -2, end_day = 29;
		}
		else if (month_choose == 8)
		{
			start_day = -3, end_day = 30;
		}
		else if (month_choose == 9)
		{
			start_day = -5, end_day = 29;
		}
		else if (month_choose == 10)
		{
			start_day = 1, end_day = 29;
		}
		else if (month_choose == 11)
		{
			start_day = 0, end_day = 30;
		}
		else if (month_choose == 12)
		{
			start_day = -2, end_day = 29;
		}
		calendarbody(month_choose, start_day, end_day, username);
		break;
	}
	case 2:
	{
		if (month_choose == 1)
		{
			start_day = -3, end_day = 30;
		}
		else if (month_choose == 2)
		{
			start_day = -5, end_day = 29;
		}
		else if (month_choose == 3)
		{
			start_day = 1, end_day = 30;
		}
		else if (month_choose == 4)
		{
			start_day = -1, end_day = 30;
		}
		else if (month_choose == 5)
		{
			start_day = -3, end_day = 30;
		}
		else if (month_choose == 6)
		{
			start_day = -5, end_day = 29;
		}
		else if (month_choose == 7)
		{
			start_day = 1, end_day = 30;
		}
		else if (month_choose == 8)
		{
			start_day = -1, end_day = 29;
		}
		else if (month_choose == 9)
		{
			start_day = -2, end_day = 30;
		}
		else if (month_choose == 10)
		{
			start_day = -4, end_day = 29;
		}
		else if (month_choose == 11)
		{
			start_day = -5, end_day = 29;
		}
		else if (month_choose == 12)
		{
			start_day = 1, end_day = 30;
		}
		calendarbody(month_choose, start_day, end_day, username);
		break;
	}
	case 3:
	{
		if (month_choose == 1)
		{
			start_day = -1, end_day = 29;
		}
		else if (month_choose == 2)
		{
			start_day = -2, end_day = 30;
		}
		else if (month_choose == 3)
		{
			start_day = -4, end_day = 29;
		}
		else if (month_choose == 4)
		{
			start_day = -5, end_day = 30;
		}
		else if (month_choose == 5)
		{
			start_day = 0, end_day = 30;
		}
		else if (month_choose == 6)
		{
			start_day = -2, end_day = 30;
		}
		else if (month_choose == 7)
		{
			start_day = -4, end_day = 29;
		}
		else if (month_choose == 8)
		{
			start_day = -5, end_day = 30;
		}
		else if (month_choose == 9)
		{
			start_day = 0, end_day = 29;
		}
		else if (month_choose == 10)
		{
			start_day = -1, end_day = 30;
		}
		else if (month_choose == 11)
		{
			start_day = -3, end_day = 29;
		}
		else if (month_choose == 12)
		{
			start_day = -4, end_day = 29;
		}
		calendarbody(month_choose, start_day, end_day, username);
		break;
	}
	case 4:
	{
		if (month_choose == 1)
		{
			start_day = -5, end_day = 30;
		}
		else if (month_choose == 2)
		{
			start_day = 0, end_day = 29;
		}
		else if (month_choose == 3)
		{
			start_day = -1, end_day = 30;
		}
		else if (month_choose == 4)
		{
			start_day = -3, end_day = 29;
		}
		else if (month_choose == 5)
		{
			start_day = -4, end_day = 30;
		}
		else if (month_choose == 6)
		{
			start_day = 1, end_day = 30;
		}
		else if (month_choose == 7)
		{
			start_day = -1, end_day = 29;
		}
		else if (month_choose == 8)
		{
			start_day = -2, end_day = 30;
		}
		else if (month_choose == 9)
		{
			start_day = -4, end_day = 30;
		}
		else if (month_choose == 10)
		{
			start_day = 1, end_day = 29;
		}
		else if (month_choose == 11)
		{
			start_day = 0, end_day = 30;
		}
		else if (month_choose == 12)
		{
			start_day = -2, end_day = 29;
		}
		calendarbody(month_choose, start_day, end_day, username);
		break;
	}
	case 5:
	{
		if (month_choose == 1)
		{
			start_day = -3, end_day = 29;
		}
		else if (month_choose == 2)
		{
			start_day = -4, end_day = 30;
		}
		else if (month_choose == 3)
		{
			start_day = 1, end_day = 29;
		}
		else if (month_choose == 4)
		{
			start_day = 0, end_day = 30;
		}
		else if (month_choose == 5)
		{
			start_day = -2, end_day = 29;
		}
		else if (month_choose == 6)
		{
			start_day = -3, end_day = 30;
		}
		else if (month_choose == 7)
		{
			start_day = -5, end_day = 29;
		}
		else if (month_choose == 8)
		{
			start_day = 1, end_day = 30;
		}
		else if (month_choose == 9)
		{
			start_day = -1, end_day = 30;
		}
		else if (month_choose == 10)
		{
			start_day = -3, end_day = 29;
		}
		else if (month_choose == 11)
		{
			start_day = -4, end_day = 30;
		}
		else if (month_choose == 12)
		{
			start_day = 1, end_day = 29;
		}
		calendarbody(month_choose, start_day, end_day, username);
		break;
	}
	}
	ch = _getch();
	maneuver = ch - '0';
	while (maneuver < 0 || maneuver > 2)
	{
		cout << endl << right << setw(53) << setfill(' ') << "Invalid choice, retry";
		ch = _getch();
		maneuver = ch - '0';
	}
	if (maneuver == 0)
	{
		goto next1;
	}
	else if (month_choose == 1 && maneuver == 2)
	{
		month_choose = 2;
	}
	else if (month_choose == 2 && maneuver == 1)
	{
		month_choose = 1;
	}
	else if (month_choose == 2 && maneuver == 2)
	{
		month_choose = 3;
	}
	else if (month_choose == 3 && maneuver == 1)
	{
		month_choose = 2;
	}
	else if (month_choose == 3 && maneuver == 2)
	{
		month_choose = 4;
	}
	else if (month_choose == 4 && maneuver == 1)
	{
		month_choose = 3;
	}
	else if (month_choose == 4 && maneuver == 2)
	{
		month_choose = 5;
	}
	else if (month_choose == 5 && maneuver == 1)
	{
		month_choose = 4;
	}
	else if (month_choose == 5 && maneuver == 2)
	{
		month_choose = 6;
	}
	else if (month_choose == 6 && maneuver == 1)
	{
		month_choose = 5;
	}
	else if (month_choose == 6 && maneuver == 2)
	{
		month_choose = 7;
	}
	else if (month_choose == 7 && maneuver == 1)
	{
		month_choose = 6;
	}
	else if (month_choose == 7 && maneuver == 2)
	{
		month_choose = 8;
	}
	else if (month_choose == 8 && maneuver == 1)
	{
		month_choose = 7;
	}
	else if (month_choose == 8 && maneuver == 2)
	{
		month_choose = 9;
	}
	else if (month_choose == 9 && maneuver == 1)
	{
		month_choose = 8;
	}
	else if (month_choose == 9 && maneuver == 2)
	{
		month_choose = 10;
	}
	else if (month_choose == 10 && maneuver == 1)
	{
		month_choose = 9;
	}
	else if (month_choose == 10 && maneuver == 2)
	{
		month_choose = 11;
	}
	else if (month_choose == 11 && maneuver == 1)
	{
		month_choose = 10;
	}
	else if (month_choose == 11 && maneuver == 2)
	{
		month_choose = 12;
	}
	else if (month_choose == 12 && maneuver == 1)
	{
		month_choose = 11;
	}
	goto next2;
	return 0;
}
void calendarbody(int month_choose, int start_day, int end_day, string& username)
{
	int b_day, b_month, i, row, col;
	string ext{ ".txt" }, s{ "'s Birthday" }, line, user_full_name, user_b_day, user_b_month;
	ifstream data;
	data.open(username + ext);
	while (getline(data, line))
	{
		size_t pos = line.find("Full Name: ");
		if (pos != string::npos)
		{
			user_full_name = line;
		}
	}
	data.close();
	data.open(username + ext);
	while (getline(data, line))
	{
		size_t pos = line.find("Day: ");
		if (pos != string::npos)
		{
			user_b_day = line;
		}
	}
	data.close();
	data.open(username + ext);
	while (getline(data, line))
	{
		size_t pos = line.find("Month: ");
		if (pos != string::npos)
		{
			user_b_month = line;
		}
	}
	user_full_name.erase(0, 11);
	user_b_day.erase(0, 5);
	user_b_month.erase(0, 7);
	istringstream(user_b_day) >> b_day;
	istringstream(user_b_month) >> b_month;
	data.close();
	for (row = 0; row < 24; row++)
	{
		if (row == 0 || row == 4 || row == 8 || row == 12 || row == 16 || row == 20 || row == 24)
		{
			cout << setw(85) << setfill('-') << "-" << endl;
		}
		else if (row == 3 || row == 7 || row == 11 || row == 15 || row == 19 || row == 23)
		{
			for (col = 0; col < 7; col++)
			{
				cout << "|" << setw(10) << setfill(' ');
				if (start_day > 0 && start_day <= end_day)
				{
					cout << start_day;
				}
				else
				{
					cout << " ";
				}
				cout << " ";
				start_day++;
				if (start_day == 31)
				{
					break;
				}
			}
			cout << "|";
			if (row == 19)
			{
				for (int k = 0; k < 6 - col; k++)
				{
					cout << setw(11) << setfill(' ') << " " << "|";
				}
			}
			if (row < 23)
			{
				cout << endl;
			}
			if (row == 23)
			{
				for (int k = 0; k < 6 - col; k++)
				{
					cout << setw(11) << setfill(' ') << " " << "|";
				}
				cout << endl;
			}
		}
		else
		{
			for (i = 0; i < 7; i++)
			{
				cout << "|" << setw(11) << setfill(' ') << " ";
			}
			cout << "|" << endl;
		}
	}
	cout << setw(85) << setfill('-') << "-" << endl << endl;
	cout << setw(85) << setfill('-') << "-" << endl;
	cout << "|" << left << setw(83) << setfill(' ') << "   Events:" << "|" << endl;
	if (month_choose == 1)
	{
		cout << "|" << left << setw(83) << setfill(' ') << "      1st - Hijri New Year" << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << "      10th - Yawm Al-'Ashura'" << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << " " << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << " " << "|" << endl;
	}
	else if (month_choose == 3)
	{
		cout << "|" << left << setw(83) << setfill(' ') << "      9th - Prophet's birth and call to Prophethood" << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << "      12th - Prophet's arrival at Madinah and his death" << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << " " << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << " " << "|" << endl;
	}
	else if (month_choose == 7)
	{
		cout << "|" << left << setw(83) << setfill(' ') << "      27th - Al-Isra wal Mi'rajd" << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << " " << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << " " << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << " " << "|" << endl;
	}
	else if (month_choose == 8)
	{
		cout << "|" << left << setw(83) << setfill(' ') << "     1st - 15th(Voluntary Fasting)" << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << "     15th - Night of Forgiveness" << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << " " << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << " " << "|" << endl;
	}
	else if (month_choose == 9)
	{
		cout << "|" << left << setw(57) << setfill(' ') << "     1st - First day of obligatory fasting" << "17th - Battle of Badr     " << "|" << endl;
		cout << "|" << left << setw(58) << setfill(' ') << "     20th - Conquest of Makkah" << "20th - 30th(I'tikaf)     " << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << "     27th - Commencement of Revelation of the Qur'an" << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << "     21st, 23rd, 25th, 27th, 29th - Search for Laylatul Qadr" << "|" << endl;
	}
	else if (month_choose == 10)
	{
		cout << "|" << left << setw(83) << setfill(' ') << "     1st - 'Eid Al-Fitr'" << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << "     6 days fasting" << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << " " << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << " " << "|" << endl;
	}
	else if (month_choose == 12)
	{
		cout << "|" << left << setw(54) << setfill(' ') << "     1st - 10th(Blessed days for worship)" << "8th - 13th(Days of Hajj)     " << "|" << endl;
		cout << "|" << left << setw(58) << setfill(' ') << "     9th - Yawm Al-'Arafat'" << "10th - 'Eid Al-Adha'     " << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << "     11th - 13th (Ayyam Al-Tashriq)" << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << " " << "|" << endl;
	}
	else
	{
		cout << "|" << left << setw(83) << setfill(' ') << " " << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << " " << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << " " << "|" << endl;
		cout << "|" << left << setw(83) << setfill(' ') << " " << "|" << endl;
	}
	cout << "|" << left << setw(83) << setfill(' ') << "   Personal Events:" << "|" << endl;
	if (month_choose == b_month)
	{
		cout << "|     " << b_day;
		if (b_day == 1)
		{
			cout << "st";
		}
		else if (b_day == 2)
		{
			cout << "nd";
		}
		else if (b_day == 3)
		{
			cout << "rd";
		}
		else
		{
			cout << "th";
		}
		cout << " - " << left << setw(71) << setfill(' ') << user_full_name + s << "|" << endl;
	}
	else
	{
		cout << "|" << left << setw(83) << setfill(' ') << " " << "|" << endl;
	}
	cout << setw(85) << setfill('-') << "-" << endl;
	cout << endl << right << setw(75) << setfill(' ') << "Press 0 to go to year menu, 1 to previous month or 2 to next month";
}