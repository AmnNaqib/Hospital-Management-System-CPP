#include <cstdlib>   //include library
#include <fstream>   //include library
#include <iomanip>   //include library
#include <iostream>  //include library
#include <limits>    //include library
#include <string>    //include library

using namespace std;
void calc(int, int, int, int, double, double & , double & , double & ,
  double & ); // function prototype
void invalid();
int main() {
  string ic, name, filename, line;
  int age, sex, status, room, type, days, choice, c, ans;
  double fee = 0, price, totalb, totald, discount;
  bool valid;
  char response;
  fstream file;
  string sexo[2] = {
    "Male",
    "Female"
  };
  string statuso[2] = {
    "Yes",
    "No"
  };
  string roomo[3] = {
    "Aurora",
    "Calma",
    "Lindo"
  };
  string typeo[3] = {
    "Medical Check Up",
    "Operation",
    "Emergency"
  };
  cout << "\t\t\t\t\t\t\t     _____" << endl <<
    "\t\t\t\t\t\t\t    \"" <<
    " ____|" << endl <<
    "\t\t\t\t\t\t\t   | |  __ " << endl <<
    "\t\t\t\t\t\t\t   | | |_ |" << endl <<
    "\t\t\t\t\t\t\t   | |__| |" << endl <<
    "\t\t\t\t\t\t\t    \"" <<
    "_____|" << endl <<
    "\t\t\t\t\t\t\t  GLENEAGLES" << endl;

  cout << "\n\n\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n";
  do{
  cout
    <<
    "\t\t\t\t "
  "_________________________________________________________________ \n";
  cout << "\t\t\t\t|                                           	               "
  "   |\n";
  cout << "\t\t\t\t|             1  >> Add New Patient Record                  "
  "      |\n";
  cout << "\t\t\t\t|             2  >> Add Diagnosis Information               "
  "      |\n";
  cout << "\t\t\t\t|             3  >> Full History of the Patient             "
  "      |\n";
  cout << "\t\t\t\t|             4  >> Exit the Program                        "
  "      |\n";
  cout << "\t\t\t\t|___________________________________________________________"
  "______|\n\n";
    cout << "\t\t\t\tEnter your choice: ";
    cin >> choice;
    system("cls");
    if ((choice > 4) || (choice < 1))
    /*check condition, if false,
               error message will be prompted*/
    {
      // something went wrong, we reset the buffer's state to good
      cin.clear();
      // and empty it
      cin.ignore(numeric_limits < streamsize > ::max(), '\n');
      // error message
      invalid();
    }
  } while (choice > 4 || choice < 1); // loop when invalid input entered
  cin.ignore();
  cout << endl;
  if (choice == 1) // if true, the statements will be executed
  {
    do {
      c = 0; // set c to 0
      cout << "\t\t\t\tEnter Patient's IC No. for file name (w/o -): ";
      getline(cin,filename);
      for (int i = 0; i < filename.size(); i++) // validating the input
      {
        if (filename.find(' ') != string::npos)
        {
          // invalidate filename
          c = 1; //when invalid, set c to 1
          break; //exit the loop
        }
        if (!isdigit(filename[i])) {
          c = 1; // when invalid, set c to 1
          break; // exit the loop
        }
      }
      if (c == 1) // when c is 1, error message will be prompted
      {
        // error message
        invalid();
      }
    } while (c == 1); // loop when invalid input entered
    file.open(filename.c_str(), ios::in); // open the input file
    if (!file.fail()) // if it doesn't fail, the file exists
    {
      cout << "\n\t\t\t\tA file by the name " << filename << " exists.\n" <<
        "\t\t\t\tDo you want to continue and overwrite it\n" <<
        "\t\t\t\twith the new data (y or n)\n "
      "\t\t\t\t[note that choice 2 is to add diagnosis]: ";
      cin >> response;
      cin.ignore();
      cout << endl;
      if (tolower(response) == 'n') {
        cout << "The existing file will not be overwritten." << endl;
        exit(1); // terminate program execution
      }
    }
    file.close(); // close the file
    file.open(filename.c_str(), ios::out); // open the output file
    if (file.fail()) // check the file
    {
      cout << "\nThe file is not successfully opened" << endl;
      exit(1); // terminate program execution
    }
    do {
      cout << "\t\t\t\tPatient Name: ";
      getline(cin, name); // get the entire line, including spaces
      valid = true; // set valid to true
      // validating the input
      for (size_t i {}; i < name.length() && valid; ++i) {
        if (!(isalpha(static_cast < unsigned char > (name[i])) ||
            isspace(static_cast < unsigned char > (name[i]))))
          valid = false; // set valid to false
      }
      if (!valid) // if invalid, error message will be prompted
      {
        cin.clear();
        // error message
        invalid();
      }
    } while (!valid); // loop when invalid input entered
    while (true) {
      cout << "\t\t\t\tAge: ";
      cin >> age;
      if (cin.fail()) // validating the input, if invalid, error message will
      // be prompted
      {
        cin.clear(); // reset the state bits back to goodbit so we can use
        // ignore()
        cin.ignore(numeric_limits < streamsize > ::max(),
          '\n'); // clear out the bad input from the stream
        // error message
        invalid();
        continue; // try again
      }
      cin.ignore(numeric_limits < streamsize > ::max(),
        '\n'); // clear out any additional input from the stream
      if (cin.gcount() >
        1) // if we cleared out more than one additional character
      {
        // error message
        invalid();
        continue; // try again
      }
      if (age <= 0)
      /* make sure age is positive, if invalid,
           error message will be propted*/
      {
        // error message
        invalid();
        continue; // try again
      }
      break; // exit the loop
    }
    cout << "\n\n\t\t\t\t[1]-Male\n\t\t\t\t[2]-Female\n";
    do{
      cout << "\t\t\t\tSex: ";
      cin >> sex;
      if ((sex < 1) || (sex > 2))
      /*check condition, if invalid,
           error message will be prompted*/
      {
        // something went wrong, we reset the buffer's state to good
        cin.clear();
        // and empty it
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        // error message
        invalid();
      }
    } while ((sex < 1) || (sex > 2)); // loop when invalid input entered
    cout << "\n\t\t\t\t[1]-Yes\n\t\t\t\t[2]-No\n";
    do{
      cout << "\t\t\t\tMember status: ";
      cin >> status;
      if (status == 2) // if true, fee will be set to 10
      {
        cout << "\n\t\t\t\t[1]-Yes\n\t\t\t\t[2]-No\n";
        do{
          cout << "\t\t\t\tDo you want to be a member?: ";
          cin >> ans;
          if (ans == 1) {
            status = 1;
            fee = 10;
          }
          if ((ans < 1) || (ans > 2))
          /*validating the input, if invalid,
                   error message will be promopted*/
          {
            // something went wrong, we reset the buffer's state to good
            cin.clear();
            // and empty it
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            // error message
            invalid();
          }
        } while ((ans < 1) || (ans > 2));
      }
      if ((status < 1) || (status > 2))
      /*validating the input, if invalid,
           error message will be promopted*/
      {
        // something went wrong, we reset the buffer's state to good
        cin.clear();
        // and empty it
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        // error message
        invalid();
      }
    } while ((status < 1) || (status > 2)); // loop when invalid input entered
    system("cls");
    cout << "\n\t\t\t\t[1]-Aurora\n\t\t\t\t[2]-Calma\n\t\t\t\t[3]-Lindo\n";
    do {
      cout << "\t\t\t\tRoom Type: ";
      cin >> room;
      if ((room < 1) || (room > 3)) // validating the input
      {
        // something went wrong, we reset the buffer's state to good
        cin.clear();
        // and empty it
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        invalid();
      }
    } while ((room < 1) || (room > 3)); // loop when invalid input entered
    cout << "\n\t\t\t\t[1]-Medical Check "
    "Up\n\t\t\t\t[2]-Operation\n\t\t\t\t[3]-Emergency\n";
    do {
      cout << "\t\t\t\tPatient Type: ";
      cin >> type;
      if ((type < 1) || (type > 3))
      /*validating the input, if invalid,
           error message will be prompted*/
      {
        // something went wrong, we reset the buffer's state to good
        cin.clear();
        // and empty it
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        // error message
        invalid();
      }
    } while ((type < 1) || (type > 3)); // loop when invalid input entered
    while (true) {
      cout << "\n\t\t\t\tDays: ";
      cin >> days;
      system("cls");
      if (cin.fail())
      /* validating the input, if invalid,
           error message will be prompted*/
      {
        cin.clear(); // reset the state bits back to goodbit so we can use
        // ignore()
        cin.ignore(numeric_limits < streamsize > ::max(),
          '\n'); // clear out the bad input from the stream
        // error message
        invalid();
        continue; // try again
      }
      cin.ignore(numeric_limits < streamsize > ::max(),
        '\n'); // clear out any additional input from the stream
      if (cin.gcount() >
        1)
      /* if we cleared out more than one additional character,
                    if invalid, the error message will be prompted*/
      {
        // error message
        invalid();
        continue; // try again
      }
      if (days <= 0) // make sure age is positive, if invalid, the error
      // message will be prompted
      {
        // error message
        invalid();
        continue; // try again
      }
      break; // exit the loop
    }
    calc(days, room, type, status, fee, price, totalb, discount,
      totald); // function call
    // display receipt
    cout << "\n\n\t\tPatient Name: " << left << setw(60) << name <<
      "Sex: " << sexo[sex - 1] << endl <<
      "------------------------------------------------------------------"
    "-------------------------------------------------" <<
    endl
      <<
      "\t\tIC No.      : " << left << setw(60) << filename <<
      "Age: " << age << " Y" << endl <<
      "------------------------------------------------------------------"
    "-------------------------------------------------" <<
    endl
      <<
      "\t\tMember Status: " << statuso[status - 1] << endl <<
      "\t\tRoom Type    : " << roomo[room - 1] << endl <<
      "\t\tPatient Type : " << typeo[type - 1] << endl <<
      "\t\tDays         : " << days << endl <<
      endl <<
      "------------------------------------------------------------------"
    "-------------------------------------------------" <<
    endl
      <<
      "\t\t\t\t\t\tAdditional Fee: RM " << fixed << setprecision(2) << fee <<
      endl <<
      "\t\t\t\t\t\tRoom Price    : RM " << fixed << setprecision(2) <<
      price << endl <<
      "\t\t\t\t\t\tTotal Price   : RM " << totalb << endl <<
      "\t\t\t\t\t\tDiscount      : RM " << discount << endl <<
      "\t\t\t\t\t\tTotal         : RM " << totald << endl <<
      endl;
    // save the receipt
    file << "\t\tPatient Name: " << left << setw(60) << name <<
      "Sex: " << sexo[sex - 1] << endl <<
      "------------------------------------------------------------------"
    "-------------------------------------------------" <<
    endl
      <<
      "\t\tIC No.      : " << left << setw(60) << filename <<
      "Age: " << age << " Y" << endl <<
      "------------------------------------------------------------------"
    "-------------------------------------------------" <<
    endl
      <<
      "\t\tMember Status: " << statuso[status - 1] << endl <<
      "\t\tRoom Type    : " << roomo[room - 1] << endl <<
      "\t\tPatient Type : " << typeo[type - 1] << endl <<
      "\t\tDays         : " << days << endl <<
      endl <<
      "------------------------------------------------------------------"
    "-------------------------------------------------" <<
    endl
      <<
      "\t\t\t\t\t\tAdditional Fee: RM " << fixed << setprecision(2) << fee <<
      endl <<
      "\t\t\t\t\t\tRoom Price    : RM " << fixed << setprecision(2) <<
      price << endl <<
      "\t\t\t\t\t\tTotal Price   : RM " << totalb << endl <<
      "\t\t\t\t\t\tDiscount      : RM " << discount << endl <<
      "\t\t\t\t\t\tTotal         : RM " << totald << endl <<
      endl;
    file.close(); // close the file
    cout << "The data has been saved succesfully";
  } else if (choice == 2) // if true, the statements will be executed
  {
    do {
      c = 0; // set c to 0
      cout << "\t\t\t\tEnter Patient's IC No. to retreive data (w/o -): ";
      getline(cin,filename);
      for (int i = 0; i < filename.size(); i++) // validating the input
      {
        if (filename.find(' ') != string::npos)
        {
          // invalidate filename
          c = 1; //when invalid, set c to 1
          break; //exit the loop
        }
        if (!isdigit(filename[i])) {
          c = 1; // set c to 1
          break; // exit the loop
        }
      }
      if (c == 1) // if c is 1, error message will be prompted
      {
        // error message
        invalid();
      }
    } while (c == 1); // loop when invalid input entered
    file.open(filename.c_str(), ios::in); // open input file
    if (file.fail()) // check the file
    {
      cout << "Data does not exist" << endl;
      cout << "Choose choice 1 to insert new patient" << endl;
      exit(1); // terminate program execution
    }
    while (true) {
      cout << "\t\t\t\tAge: ";
      cin >> age;
      if (cin.fail())
      /*validating the input, if invalid,
           error message will be prompted*/
      {
        cin.clear(); // reset the state bits back to goodbit so we can use
        // ignore()
        cin.ignore(numeric_limits < streamsize > ::max(),
          '\n'); // clear out the bad input from the stream
        // error message
        invalid();
        continue; // try again
      }
      cin.ignore(numeric_limits < streamsize > ::max(),
        '\n'); // clear out any additional input from the stream
      if (cin.gcount() >
        1) // if we cleared out more than one additional character
      {
        // error message
        invalid();
        continue; // try again
      }
      if (age <= 0) // make sure age is positive, if invalid, error message
      // will be prompted
      {
        // error message
        invalid();
        continue; // try again
      }
      break; // exit the loop
    }
    cout << "\n\t\t\t\t[1]-Yes\n\t\t\t\t[2]-No\n";
    do{
      cout << "\t\t\t\tMember status: ";
      cin >> status;
      if (status == 2) // if true, fee will be set to 10
      {
        cout << "\n\t\t\t\t[1]-Yes\n\t\t\t\t[2]-No\n";
        do{
          cout << "\t\t\t\tDo you want to be a member?: ";
          cin >> ans;
          if (ans == 1) {
            status = 1;
            fee = 10;
          }
          if ((ans < 1) || (ans > 2))
          /*validating the input, if invalid,
                   error message will be promopted*/
          {
            // something went wrong, we reset the buffer's state to good
            cin.clear();
            // and empty it
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            // error message
            invalid();
          }
        } while ((ans < 1) || (ans > 2));
      }
      if ((status < 1) || (status > 2))
      /*validating the input, if invalid,
           error message will be promopted*/
      {
        // something went wrong, we reset the buffer's state to good
        cin.clear();
        // and empty it
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        // error message
        invalid();
      }
    } while ((status < 1) || (status > 2)); // loop when invalid input entered
    system("cls");
    cout << "\n\t\t\t\t[1]-Aurora\n\t\t\t\t[2]-Calma\n\t\t\t\t[3]-Lindo\n";
    do {
      cout << "\t\t\t\tRoom Type: ";
      cin >> room;
      if ((room < 1) || (room > 3))
      /* validating the input, if invalid,
           error message will be prompted*/
      {
        // something went wrong, we reset the buffer's state to good
        cin.clear();
        // and empty it
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        // error message
        invalid();
      }
    } while ((room < 1) || (room > 3)); // loop when invalid input entered
    cout << "\n\t\t\t\t[1]-Medical Check "
    "Up\n\t\t\t\t[2]-Operation\n\t\t\t\t[3]-Emergency\n";
    do {
      cout << "\t\t\t\tPatient Type: ";
      cin >> type;
      if ((type < 1) || (type > 3))
      /*validating the input, if invalid,
           error message will be prompted*/
      {
        // something went wrong, we reset the buffer's state to good
        cin.clear();
        // and empty it
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        // error message
        invalid();
      }
    } while ((type < 1) || (type > 3)); // loop when invalid input entered
    while (true) {
      cout << "\n\t\t\t\tDays: ";
      cin >> days;
      system("cls");
      if (cin.fail())
      /* validating the input, if invalid,
           error message will be prompted*/
      {
        cin.clear(); // reset the state bits back to goodbit so we can use
        // ignore()
        cin.ignore(numeric_limits < streamsize > ::max(),
          '\n'); // clear out the bad input from the stream
        // error message
        invalid();
        continue; // try again
      }
      cin.ignore(numeric_limits < streamsize > ::max(),
        '\n'); // clear out any additional input from the stream
      if (cin.gcount() >
        1) // if we cleared out more than one additional character
      {
        // error message
        invalid();
        continue; // try again
      }
      if (days <= 0) // make sure age is positive, if invalid, error message
      // will be prompted
      {
        // error message
        invalid();
        continue; // try again
      }
      break; // exit the loop
    }
    cout << endl << endl;
    calc(days, room, type, status, fee, price, totalb, discount,
      totald); // function call
    for (int i = 1; i <= 2; i++) // read file
    {
      getline(file, line);
      cout << line << endl;
    }
    file.close(); // close the file
    file.open(filename.c_str(), ios::out | ios::app); // open the output fail
    if (file.fail()) // check the file
    {
      cout << "Data does not exist" << endl;
      cout << "Choose choice 1 to insert new patient" << endl;
      exit(1); // terminate program execution
    }
    // display receipt
    cout << "\t\tIC No.      : " << left << setw(60) << filename <<
      "Age: " << age << " Y" << endl <<
      "------------------------------------------------------------------"
    "-------------------------------------------------" <<
    endl
      <<
      "\t\tMember Status: " << statuso[status - 1] << endl <<
      "\t\tRoom Type    : " << roomo[room - 1] << endl <<
      "\t\tPatient Type : " << typeo[type - 1] << endl <<
      "\t\tDays         : " << days << endl <<
      endl <<
      "------------------------------------------------------------------"
    "-------------------------------------------------" <<
    endl
      <<
      "\t\t\t\t\t\tAdditional Fee: RM " << fixed << setprecision(2) << fee <<
      endl <<
      "\t\t\t\t\t\tRoom Price    : RM " << fixed << setprecision(2) <<
      price << endl <<
      "\t\t\t\t\t\tTotal Price   : RM " << totalb << endl <<
      "\t\t\t\t\t\tDiscount      : RM " << discount << endl <<
      "\t\t\t\t\t\tTotal         : RM " << totald << endl <<
      endl;
    // save the receipt
    file << "\t\tIC No.:       " << left << setw(60) << filename <<
      "Age: " << age << " Y" << endl <<
      "------------------------------------------------------------------"
    "-------------------------------------------------" <<
    endl
      <<
      "\t\tMember Status: " << statuso[status - 1] << endl <<
      "\t\tRoom Type    : " << roomo[room - 1] << endl <<
      "\t\tPatient Type : " << typeo[type - 1] << endl <<
      "\t\tDays         : " << days << endl <<
      endl <<
      "------------------------------------------------------------------"
    "-------------------------------------------------" <<
    endl
      <<
      "\t\t\t\t\t\tAdditional Fee: RM " << fixed << setprecision(2) << fee <<
      endl <<
      "\t\t\t\t\t\tRoom Price    : RM " << fixed << setprecision(2) <<
      price << endl <<
      "\t\t\t\t\t\tTotal Price   : RM " << totalb << endl <<
      "\t\t\t\t\t\tDiscount      : RM " << discount << endl <<
      "\t\t\t\t\t\tTotal         : RM " << totald << endl <<
      endl;
    file.close(); // close the file
    cout << "The data has been saved succesfully";
  } else if (choice == 3) // if true, the statements will be executed
  {
    do {
      c = 0; // set c to 0
      cout << "\t\t\t\tEnter Patient's IC No. to retrive data (w/o -): ";
      getline(cin,filename);
      system("cls");
      for (int i = 0; i < filename.size(); i++)
      /*validating the input, if
                   invalid, error message will be prompted */
      {
        if (filename.find(' ') != string::npos)
        {
          // invalidate filename
          c = 1; //when invalid, set c to 1
          break; //exit the loop
        }
        if (!isdigit(filename[i])) {
          c = 1; // set c to 1
          break; // exit the loop
        }
      }
      if (c == 1) // when c is 1, error message will be prompted
      {
        // error message
        invalid();
      }
    } while (c == 1); // loop when invalid input entered
    file.open(filename.c_str(), ios::in); // open input fail
    if (file.fail()) // check file
    {
      cout << "Data does not exist" << endl;
      cout << "Choose choice 1 to insert new patient" << endl;
      exit(1); // terminate program execution
    }
    cout << "\n\t\t\t\t\t\tThis Is The Patient's History\n\n";
    while (getline(file, line)) // read the file
    {
      cout << line << endl;
    }
    file.close(); // close the file
  } else if (choice == 4) // when choice is 4, run the task
  {
    exit(1); // exit the program
  }
  return 0;
}
// this function will calculated room price, total price as well as the discount
void calc(int days, int room, int type, int status, double fee, double & price,
  double & totalb, double & discount,
  double & totald) // function definition
{
  switch (room) {
  case 1:
    if (type == 1)
      price = 300; // set price to 300
    else if (type == 2)
      price = 400; // set price to 400
    else if (type == 3)
      price = 500; // set price to 500
    break;
  case 2:
    if (type == 1)
      price = 250; // set price to 250
    else if (type == 2)
      price = 300; // set price to 300
    else if (type == 3)
      price = 350; // set price to 350
    break;
  case 3:
    if (type == 1)
      price = 200; // set price to 200
    else if (type == 2)
      price = 210; // set price to 210
    else if (type == 3)
      price = 230; // set price to 230
    break;
  }

  totalb = price * days; // multiply price with days

  switch (status) {
  case 1:
    if (room == 1) {
      if (days > 3)
        discount = 0.6 * totalb;
      else
        discount = 0; // set discount to 0
    } else if (room == 2) {
      if (days > 3)
        discount = 0.45 * totalb;
      else
        discount = 0; // set discount to 0
    } else if (room == 3) {
      if (days > 3)
        discount = 0.3 * totalb;
      else
        discount = 0; // set discount to 0
    }
    break;
  case 2:
    if (room == 1) {
      if (days > 3)
        discount = 0.4 * totalb;
      else
        discount = 0; // set discount to 0
    } else if (room == 2) {
      if (days > 3)
        discount = 0.3 * totalb;
      else
        discount = 0; // set discount to 0
    } else if (room == 3) {
      if (days > 3)
        discount = 0.2 * totalb;
      else
        discount = 0; // set discount to 0
    }
    break;
  }
  totald = totalb - discount +
    fee; // substract totalb with discount and add with fee
}
void invalid() {
  cout << "\t\t\t\t*******************************\n\n";
  cout << "\t\t\t\t        INVALID INPUT        " << endl;
  cout << "\n\t\t\t\t*******************************";
  cout << "\n\t\t\t\tPlease re-enter\n";
}
