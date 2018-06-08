//============================================================================
// Name        : Grading.cpp
// Author      : reginald
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <dirent.h>
using namespace std;

#include "Grading.h"
void draw_welcome();
void CIN1();
int Nof();
void Print_array_menu(int, string a[]);
void check_input( string, int& found);
bool no_input(string x);
bool no_input2(string x);
void FIRST_TYM_USAGE();

int main()
{
	// class constants th
	int Stu_num;
	int Grad_comp;
	string Class;
	string caution;

	/// file for entries
	ofstream out_file;
	out_file.open("DETAILS.txt");
	out_file << "";
	out_file.close();


	double **All_Grading_comp;


	string user_reply;
	int user_reply_no;
	cout <<"\a";
	FIRST_TYM_USAGE();

	while(user_reply != "3")
	{
		draw_welcome();
	    CIN1();
	    cin >> user_reply;
	    cout << endl << endl;


		if (user_reply == "1")
		{
			int i;
			const int NUM_FILES = Nof();
			//cout << " \t the number of files = " << NUM_FILES << endl;
			//y = NUM_FILES;

			//cout << " \t string for stored classes have been created " << endl;


			if(NUM_FILES == -1)
			{
				cout << "\t IT SEEMS YOU HAVE NOT YET STORED ANY CLASS DATA OR THE PROGRAM WAS NOT ABLE TO ACCESS YOUR STORED DATA" << endl << endl;
			}
			else
			{
				string STORED_CLASSES [NUM_FILES];
				ifstream in_file;   in_file.open("SYSTEM_FILES\\STORED_CLAS.txt");
				for(i=0; i< NUM_FILES; i++)
				{
					getline(in_file, STORED_CLASSES[i] );
				}
				in_file.close();

				do
				{
					Print_array_menu(NUM_FILES, STORED_CLASSES);
					cout << "[ PLEASE ENTER THE NUMBER ASSOCIATED THE CLASS DATA ] :" << endl;
					CIN1();
					cin >> user_reply;
					cout << endl;

				    if(user_reply == "0")
					{

					}
				    else if( no_input(user_reply) )
					{
						stringstream CONVERT(user_reply);
						CONVERT >> user_reply_no;

						if(user_reply_no > NUM_FILES)
						{
							cout << "NO SUCH FILE EXIST ENTER AGAIN" <<endl;
						}

						else
						{
							//convertion of stored name to c string
							string out_file = "SYSTEM_FILES\\" + STORED_CLASSES[user_reply_no - 1] + "\\" + STORED_CLASSES[user_reply_no - 1] + ".txt";
							char file_name[80];
							strcpy(file_name, out_file.c_str());

							//opening file
							ifstream in_file;
							in_file.open(file_name);

							in_file >> Stu_num;
							in_file >> Grad_comp;

							//////////////////////////
							char symbol;
							do
							{
								in_file.get(symbol);
							}while(symbol != '\n');
							//////////////////////////

							getline(in_file, Class);
							in_file.close();

							const int C_Stu_num = Stu_num;
							const int C_Grad_comp = Grad_comp;

							// arrays
							string Names[C_Stu_num];
							string Grad_comps[C_Grad_comp];
							double Wieght[C_Grad_comp];
							string GRADE [C_Stu_num];
							double TOTAL[C_Stu_num];

							All_Grading_comp = new double*[C_Stu_num];

							for(i=0; i < C_Stu_num ; i++ )
							{
								All_Grading_comp[i] = new double[C_Grad_comp];
							}
							cout << endl << endl;
							BMCC MAT( Class, C_Stu_num, C_Grad_comp, Names, Grad_comps, Wieght, All_Grading_comp, GRADE, TOTAL );

							MAT.second_menu();

						}
					}
					else{}

				}while(user_reply != "0" );

			}



		}
		else if(user_reply == "2")
		{
			char symbol;
			do
			{
			      cin.get( symbol);

			}while(symbol != '\n');

			int FOUND =0 ;
			int i;
			int k=1;
			cout << " YOU WILL BE ASK DETAILS OF THE CLASS YOU WISH TO ADD ( PLEASE PRESS ENTER AFTER EVERY INPUT)" << endl;
			cout << " PLEASE ENTER THE NAME OF YOUR CLASS :" << endl;
					 	CIN1();
			getline(cin, Class);
			cout << endl;
			check_input( Class, FOUND);

			if (FOUND == 0 )
			{
				string Stu_num_check;
				cout << " PLEASE ENTER THE NUMBER OF STUDENTS :"<< endl ;
				CIN1();
				cin >> Stu_num_check ;
				cout << endl;

				if(no_input(Stu_num_check))
				{
					stringstream CONVERT(Stu_num_check);
					CONVERT >> Stu_num;
					const int C_Stu_num = Stu_num;
					string Names[C_Stu_num];

					cout << " HOW MANY GRADING COMPONENTS WILL YOU USE :" << endl ;
					CIN1();       string Grad_comp_check;

					cin >> Grad_comp_check;
					cout << endl;
					if(no_input(Grad_comp_check ) )
					{
						stringstream CONVERT(Grad_comp_check);
						CONVERT >> Grad_comp;

						string weight_check;

						/////////////////////////////////////
						char symbol;
						do
						{
							  cin.get( symbol);

						}while(symbol != '\n');
						/////////////////////////////////////

							const int C_Grad_comp = Grad_comp;
							string Grad_comps[C_Grad_comp];
							double Wieght[C_Grad_comp];
							for(i=0; i < C_Grad_comp; i++)
							{
								cout << " PLEASE ENTER THE NAME OF GRADING COMPONENT " << k <<" :" << endl;
									CIN1();
								getline(cin, Grad_comps[i]);
								cout << endl;
								/*///////////////////////
								char symbol;
								do
								{
									cin.get( symbol);

								}while(symbol != '\n');
								*/////////////////////////
								do
								{
									cout << " WHAT PERCENTAGE DOES " << Grad_comps[i] << " MAKE UP THE FINAL GRADE (ENTER DECIMALS) :" << endl;
									CIN1();
									cin >> weight_check;
									cout << endl;
								}while( !no_input2(weight_check) );

								stringstream CONVERT(weight_check);
								CONVERT >>Wieght[i];
								k++;

								char symbol;
								do
								{
									cin.get( symbol);

								}while(symbol != '\n');


						}
						cout << endl << endl << endl;

						//double All_Grading_comp[C_Stu_num][10];
						string GRADE [C_Stu_num];
						double TOTAL[C_Stu_num];

						All_Grading_comp = new double*[C_Stu_num];

						for(i=0; i < C_Stu_num ; i++ )
						{
							All_Grading_comp[i] = new double[C_Grad_comp];
						}




						//BMCC( int ST_number, int Grade_compo, string Names[], string Grd_Com[], double W[], double All_Grd[][C_Grad_comp] );

						BMCC MAT( Class, C_Stu_num, C_Grad_comp, Names, Grad_comps, Wieght, All_Grading_comp, GRADE, TOTAL );
						MAT.first_menu();
					}
					else{ cout << " ONLY INTEGERS ARE ALLOWED " << endl<< endl; }
				}
				else{ cout << " ONLY INTEGERS ARE ALLOWED " << endl<< endl; }
			}
			else if ( FOUND == 1)
			{
				cout << " THE CLASS NAME YOU ENTERED ALREADY EXIST" << endl << endl;
			}
		}
		else
		{
			cout << " INCORRECT INPUT TRY AGAIN \a" << endl << endl;

		}
	}

	return 0;
}

void draw_welcome()
{
	cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	cout <<	" %% PRESS 1 FOR TO MANAGE PREVIOUSLY STORED CLASS DATA  %%" << endl;
	cout << " %% PRESS 2 TO  ADD A NEW CLASS                         %%" << endl;
	cout << " %%                                                     %%"<<endl;
	cout << " %% PRESS 3 TO QUIT                                     %%" << endl;
	cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
}
void CIN1()
{
	cout << " ==> ";
}
int Nof()
{
	string f;
	int counter = 0;
	ifstream in_file;
	in_file.open("SYSTEM_FILES\\STORED_CLAS.txt");
	if (in_file.fail() )
	{
		//cout << " \t OPERATION NOT SUCCESSFUL" << endl;
		return -1;
	}
	else
	{
		while ( ! in_file.eof())
		{
			/*
			char symbol;
			do
			{
				in_file.get(symbol);
				cout << symbol << endl;
			}while(symbol == '\n' || symbol == ' ' );

			cout << " reach" << endl;
			*/
			getline(in_file, f );
			if(! in_file.eof())
			{
				counter++;
			}
		}
		in_file.close();
		return counter;
	}
}
void Print_array_menu(int f, string a[])
{
	//cout <<"\t maximum files"<< f << endl;

	int i,j, y=1, length;
	cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<< endl;
	for(i=0; i < f; i++)
	{
		cout <<" %% " << y << "." << a[i];
		length = a[i].length();
		for(j=0; j < 40 - length; j++ )
		{
			cout << " ";
		}
		cout << "%%" << endl;
		y++;
	}
	cout << " %%                                           %%"<<endl;
	cout << " %% PRESS 0(ZERO) TO GO BACK TO THE MAIN MENU %%"<< endl;
	cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<< endl;
}

void check_input( string x, int& found)
{
	ifstream in_file;
	int i;
	in_file.open("SYSTEM_FILES\\STORED_CLAS.txt");
	string next, next1, x1;
	found = 0;

	if(in_file.fail())
	{
		found = 0;
	}
	else
	{
		//int i=0;

		while(!in_file.eof())
		{   x1 = "";
			next1 = "";
			getline(in_file, next);

			for(i=0; i < next.length(); i++)
			{
			/*	cout << "\t length of file " << next.length() << endl;
				cout << "\t" << next[i] << endl;;
				cout << "\t is " << next[i] << " a whitespace character " << endl; */
				if( isalnum(next[i]) )
				{
					if( isalpha(next[i]) )
					{
						next[i] = tolower(next[i]);
					}
				//	cout << " \t NO " << next[i] << " isnt a whitespace character" << endl;
					next1 = next1 + next[i];
				}
				else{/* cout << " IT IS A WHITESPACE" << endl; */}

			}

		/*	cout <<"\t next1 is " << next1 << endl;
			cout << " INPUT NAME " << endl; */

			for(i =0; i < x.length(); i++)
			{
			/*	cout << "\t length of file" << x.length() << endl;
				cout <<"\t" << x[i] << endl;
				cout << "\t is " << x[i] << " a whitespace character " << endl;			*/
				if( isalnum(x[i]) )
				{
					if( isalpha(x[i]) )
					{
						x[i] = tolower(x[i]);
					}
				//	cout << " \t NO " << x[i] << " isnt a whitespace character" << endl;
					x1 = x1 + x[i];
				}
				else{/* cout << " IT IS A WHITESPACE" << endl; */ }
			}
		/*	cout << "\t x1 is " << x1 << endl;

			cout << "\t COMPARING " <<  x1 << " AND " << next1 << next1 << endl;		*/
			if(x1 == next1 )
			{
			//	cout << " THEY ARE THE SAME WORDS" << endl;
				found = 1;
			}
			else{/* cout << " THEY ARE NOT THE SAME WORDS" << endl;*/ }
		}
	}
	in_file.close();
}

bool no_input(string x)
{
	const int size = x.length() + 1 ;
	char f[size];
	int y;

	strcpy(f, x.c_str());

	bool r = atoi(f);
	//cout << "\t" << r << endl;


	if(r)
	{
		y = atoi(f);
		if( y < 0)
		{

			cout << endl;
			cout << " NEGATIVE NUMBERS ARE NOT ACCEPTED " << endl;
			return 0;
		}
		else
		{
			return r;
		}
	}
	else
	{
		cout << endl;
		cout << " INCORRECT INPUT TRY AGAIN 11 " << endl;
		return r;
	}

}

bool no_input2(string x)
{
	const int size = x.length() + 1 ;
	char f[size];
	double y;

	strcpy(f, x.c_str());

	bool r = atof(f);

	if(r)
	{
		y = atof(f);
		if(y < 0)
		{
			cout << endl;
			cout << " NEGATIVE NUMBERS ARE NOT ACCEPTED " << endl;
			return 0;
		}
		else
		{
			return r;
		}
	}
	else
	{
		cout << endl;
		cout << " INCORRECT INPUT TRY AGAIN " << endl;
		return r;
	}
}

void FIRST_TYM_USAGE()
{
	ifstream in_file;
	in_file.open("installation\\ins.txt");
	if(in_file.fail())
	{
		cout << " PLEASE WAIT WHILE WE INSTALL NEEDED FILES .................." << endl << endl;
		mkdir("SYSTEM_FILES");
		mkdir("installation");
		mkdir("CLASSES");

		ofstream out_file;
		out_file.open("installation\\ins.txt");
		out_file << " installation complete" << endl;
		out_file.close();
	}
	else
	{
		in_file.close();
	}


}

