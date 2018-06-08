/*
 * Grading.h
 *
 *  Created on: Jul 6, 2016
 *      Author: regit
 */

class BMCC
{
	public:


		BMCC(string, int, int , string names[], string Grd_Com[], double W[], double**ALL_GRD, string LG[], double TOT[]);

		void first_menu();
		void second_menu();


	private:



		//file streams
		char file_name[80];
		char file_name2[80];
		char file_name3[80];


		//input manipulator
		string garbage[3];

		//CLASS NAME;
		string Class_Name;

		//constants
		//int i;
		int number_stu;
		int grade_compo; // number of grading components


		// array pointers
		string *stu_names;
		string *Grd_compo_names;
		double *weight;
		double **All_grd;
		string *Letter_grade;
		double *Total;

		void Underline(string, string, ostream& f);
		void Underline(double, char, ostream& f);
		void Underline(int, char, ostream& f);
		// printing
		void Print_array(int a[], string L, int x, ostream& f);
		void Print_array(double a[], string L, int x, ostream& f);
		void Print_array(string a[], string L, int x, ostream& f);

		void Saving( char a[], string x, int& y );
		void Class_sheet(ostream& f);
		void CIN();
		int Nof(char a[]);

		void INI();

		bool INPUT_CHECK( string);
		bool INPUT_CHECK2( string x );
		void PREP( );

		void Genrate_Report( char a[], string x );
		void Genrate_Report();
		void MANAGING();
		int longest_name();
		int longest_grd_comp_name();
		void data_sheet();
		void total();
		void GRADING1(ostream& f, const int num_grade, const int max1_counter, string **display, string GRADE[], int counter[]  );

		// grading it returns the grade
		string  GRADING( string grd[], double grd1[][2], double m, int numgrd );





};

BMCC::BMCC(string Clas_nam, int ST_number, int Grade_compo, string names[], string Grd_Com[], double W[], double**ALL_GRD, string LG[], double TOT[])
{
	 int i ;
	cout <<" %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% " << endl;
	cout <<" %% 	PROGRAM IS INITIALIZING...                %% " << endl;
	cout <<" %%                               	          %% " << endl;

	Class_Name = Clas_nam;

	//constants
	number_stu = ST_number;
	grade_compo = Grade_compo;

	// array pointers
	stu_names = names;
	Grd_compo_names = Grd_Com;
	weight = W;
	All_grd = ALL_GRD;
	Letter_grade = LG;
	Total = TOT;



		cout <<" %% YOUR CLASS PARAMETERS HAVE BEEN SUCCESSFULLY  %%" << endl;
		cout <<" %%      SET FOR " << Class_Name;
		int length = Class_Name.length();
		for(i=0; i < (33 - length ); i++)
		{
			cout << " ";
		}
		cout <<"%%" << endl;
		cout <<" %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
		cout <<endl << endl;

}


void
BMCC:: Class_sheet( ostream& f )
{
	f.setf(ios::fixed); f.setf(ios::showpoint); f.precision(2);
	int g, n, NL; // longest names
	string NL1;
	n = longest_name();
	g = longest_grd_comp_name();

	stringstream CONVERT;
	CONVERT << number_stu;
	NL1 = CONVERT.str();

	NL = NL1.length();


	// longest line
	int y , longest;
	longest = 4 + n + 4 + grade_compo*(g+6+4) + 5 + 4 + 5 ;


	string text;
	string weighted;
		//cout << "\t"<< g << "\t" << n<< endl;
	f.setf(ios:: left);
// OUTPUTING OF HEADERS
	int i, k, s = 1;
	f << "                                                            CLASS " << Class_Name << endl;
	f << "==================================================================================================================================================" << endl;
	f << setw(NL+2) << "N#" << setw(n+4) << "NAMES" ;


	for(i=0; i < grade_compo; i++)
	{
		stringstream CONVERT;
		CONVERT << weight[i] * 100;
		weighted = CONVERT.str();
		text = Grd_compo_names[i] + "(" + weighted + "%)";
		f << setw(g+6+4) << text;
	}

	f << setw(5+4)<< "TOTAL" <<  "GRADE" << endl;

// UNDERLINING OF HEADERS
	f << setw(NL+2) <<"==" << setw(n+4) << "=====";

	for(i=0; i < grade_compo; i++ )
	{
		stringstream CONVERT;
		CONVERT << weight[i] * 100;
		weighted = CONVERT.str();
		text = Grd_compo_names[i] + "(" + weighted + "%)";
		f << setw(g+6+4);  Underline(text, "=", f);
	}
	f << setw(5+4) << "=====" << "=====" << endl;


// WRITING OF STUDENT NAMES, GRADE COMPONENTS,TOTALS AND LETTER GRADE
	for(i=0; i < number_stu; i++ )
	{
		f << setw(NL+2) << s << setw(n+4) << stu_names[i];

	    for(k=0; k < grade_compo; k++ )
	    {

	    	f << setw(g+6+4) << All_grd[i][k] ;
	    }

	    f << setw(5+4) << Total[i]  << Letter_grade[i] << endl;
		s++;

		for (y=0; y < longest; y ++)
		{
			f <<"_";
		}
		f << endl;

	}

	cout << endl << endl;
}

void
BMCC::Underline(string x, string Under_char, ostream& f)
{
	int i;
	string printl;
	int lenght = x.length();
	for (i=0; i < lenght; i++)
	{
		printl = printl + Under_char;
	}
	f << printl;
}

void
BMCC:: Underline(int x, char Under_char, ostream& f )
{
	int i;
	if (0 <= x || x < 10 )
	{
			f << Under_char;
	}
	else if (10 <= x || x < 100)
	{
		for (i=0; i < 2; i++)
		{
			f << Under_char;
		}
	}
}

void
BMCC:: Underline(double x, char Under_char, ostream& f )
{
	int i;
	if (0 <= x || x < 10 )
	{
			f << Under_char;
	}
	else if (10 <= x || x < 100)
	{
		for (i=0; i < 2; i++)
		{
			f << Under_char;
		}
	}
}

void
BMCC::Print_array(int a[], string L, int x, ostream& f )
{
	int i;
	if(L == "t")
	{
		for(i=0; i< x; i++)
		{
			f << "\t" << a[i];
		}
	}
	else if (L == "n")
	{
		for(i=0; i < x; i++)
		{
			f << "\t" << a[i];
		}
	}
}

void
BMCC::Print_array(double a[], string L, int x, ostream& f)
{
	int i;
	if(L == "t")
	{
		for(i=0; i< x; i++)
		{
			f << "\t" << a[i];
		}
	}
	else if (L == "n")
	{
		for(i=0; i < x; i++)
		{
			f << a[i] << endl;
		}
	}
}

void
BMCC::Print_array(string a[], string L, int x, ostream& f)
{
	int i;
	if(L == "t")
	{
		for(i=0; i< x; i++)
		{
			f << a[i] << "\t";
		}
	}
	else if (L == "n")
	{
		for(i=0; i < x; i++)
		{
			f << a[i] << endl;
		}
	}
}

void
BMCC::first_menu ()
{
	//initialization
	INI();


	int i, f=1;
	int success = 0; //( 1 means fail , 2 means successful)
	string user_reply;

	//////////////////////////////////// creating folder

	string FOLDER = "SYSTEM_FILES\\"+Class_Name;
	strcpy(file_name, FOLDER.c_str());
	mkdir(file_name);



	////////////////////////////////////
	string Out_fil = FOLDER + "\\" + Class_Name + ".txt";
	do
	{
		cout <<" %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
		cout <<" %% PRESS 1 TO ENTER STUDENTS DETAILS MANUALLY                %%" << endl;
		cout <<" %% PRESS 2 TO READ STUDENTS DETAILS FROM A FILE (RECOMMENDED)%%" << endl;
		cout <<" %% PRESS 6 TO QUIT                                           %%" << endl;
		cout <<" %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
		CIN();
		cin >> user_reply;

		if( user_reply =="1")
		{
			do{
				f=1;  success = 0;
				for(i=0; i< number_stu; i++)
				{
					cout << " PLEASE ENTER STUDENT " << f << " DETAILS" <<endl;
					cout << " NAME (SEPERATE FIRST AND LAST NAME WITH (_) THIS) : ";

					char symbol;
					do
					{
						cin.get( symbol);

					}while(symbol != '\n');

					getline(cin,stu_names[i] ) ;

				/*	for(k=0; k < grade_compo; k++ )
					{
						cout << " " << Grd_compo_names[k] << " : ";  cin >> All_grd[i][k];
					}
				 */
					f++;
				}
				cout << "Please cross check the list"<< endl;
				cout << endl;
				Class_sheet(cout);
				cout << "*********************************************************************************************************************************************************" << endl;
				cout << endl;
				cout << " DO YOU WISH TO SAVE (PRESS 3) , MAKE CHANGES(PRESS 4) OR TYPE THE WHOLE DETAILS OVER AGAIN ( PRESS 5) " << endl;
			    CIN();
				cin >>  user_reply;

				if (user_reply == "3")
				{

					do
					{
						success = 0;
						Saving( file_name2, Out_fil, success );
						if (success == 1)
						{
							cout << " Please Press 1 to try again || Press 2 to quit : " ;
							cin >> user_reply;
							if(user_reply == "2")
							{
								break;
							}
							else if(user_reply == "1" ){}
							else{ cout << endl; cout << " INCORECT INPUT. PLEASE ENTER  AGAIN \a" << endl << endl;       user_reply = "1";               }
						}

					}while(success == 1 && user_reply == "1" );
				}

				else if(user_reply == "4")
				{
					string num;
					int num_no;


					cout << " PLEASE ENTER THE STUDENTS NUMBER : " ;
					cin >> num;
					if(INPUT_CHECK(num ))
					{
						stringstream CONVERT(num);
						CONVERT >> num_no;
						if(num_no <= number_stu && num_no >= 0)
						{
							cout << " PLEASE ENTER THE NEW NAME : ";
							cin >> 	stu_names[num_no-1];
							cout << "STUDENT " << num << " NAME HAS BEEN CHANGED TO " << stu_names[num_no-1] << endl;

							// after changes
							do
							{
								success = 0;
								Saving( file_name2, Out_fil, success );
								if (success == 1)
								{
									cout << " Please Press 1 to try again || Press 2 to quit : " ;
									cin >> user_reply;
									if(user_reply == "2")
									{
										break;
									}
									else if(user_reply == "1" ){}
									else{ cout << endl;   cout << " INCORECT INPUT. PLEASE ENTER  AGAIN \a" << endl;       user_reply = "1";               }

								}

							}while(success == 1 && user_reply == "1" );

						}
						else{ cout << endl;   cout << " INCORECT INPUT. PLEASE ENTER  AGAIN \a" << endl; }
					}
					else{ cout << endl;   cout << " INCORECT INPUT. PLEASE ENTER  AGAIN \a" << endl; }


				}
				else if (user_reply == "5")
				{

				}

			}while(user_reply == "5" );

			if(success == 2)
			{
							//SAVES NUMBER OF CLASSES STORED
							ofstream stored_classes;
							stored_classes.open("SYSTEM_FILES\\STORED_CLAS.txt", ios::app);
							stored_classes << Class_Name << endl;
							stored_classes.close();

							cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% "<< endl;
							cout << "%%  PLEASE PRESS 1 TO GENERATE A DATA SHEET          %% "<< endl;
							cout << "%%  PLEASE PRESS 2 TO IGNORE                         %% "<< endl;
							cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% "<< endl;
							CIN();
							cin >> user_reply;

							if (user_reply == "1")
							{
								string FOLDER = "CLASSES\\"+Class_Name;
								strcpy(file_name, FOLDER.c_str());
								mkdir(file_name);
								string f = FOLDER + "\\Datasheet_" + Class_Name + ".txt";

								Genrate_Report( file_name2, f );
								cout << endl << endl;
								cout << " YOUR DATA SHEET HAS BEEN GENERATED AS " << f << endl;
								cout << endl;
							}
							else{}

							cout << "THE OPERATION WAS SUCCESSFUL" << endl;
							cout << endl << endl;
			}



		}
		else if (user_reply == "2")
		{
			int input_ret=0; // 2 means input was readable,  1 means input was not readable
			cout << " PLEASE  OPEN THE FILE CALLED DETAILS. AFTER OPENING THIS FILE PLEASE ENTER THE NAMES OF THE STUDENTS \a" << endl;
			cout << " PLEASE YOUR ENTRIES SHOULD BE IN THIS FORMAT  " << endl;
			//cout << " .............. GRADING COMPONENTS NAMES............... " << endl;
			cout << " FIRST STUDENT'S NAME ................................. " << endl;
			cout << "    . "<< endl;
			cout << "    . "<< endl;
			cout << "    . "<< endl;
			cout << " LAST STUDENT'S NAME................................... " << endl;
			cout << endl;
			cout << "!!!!!!!!!!!! PLEASE SAVE  THE FILE AFTER YOU ENTER THE NAMES !!!!!!!!!!!!!"<< endl;
			cout << "***************************** CLOSE THE FILE AFTER SAVING IT ****************************** " << endl << endl;
			cout << " PRESS 2 AFTER SAVING YOUR ENTRIES IN DETAILS.TXT FILE TO CONTINUE || PRESS 3 TO CANCEL" << endl;
			CIN();

			cin >> user_reply;

			if(user_reply == "2" )
			{
				ifstream in_file;
				in_file.open("DETAILS.txt");

				if(in_file.fail())
				{
					input_ret = 1;
					cout << "    THE FILE WAS NOT OPENED SUCCESFULLY"<< endl;
					cout << "    TRY AGAIN" << endl;
				}
				else
				{
					input_ret = 2;
					cout << "     THE FILE WAS OPENED SUCCESFULLY"<< endl;
					cout << "     READING FROM FILES...." << endl;

					for(i=0; i < number_stu; i++)
					{
						//in_file >> stu_names[i];
						getline(in_file, stu_names[i] );
					}
					cout << "     READING COMPLETE:" << endl;
				}
				in_file.close();

				if(input_ret == 2)
				{	cout << "Please cross check the list"<< endl;
					cout << endl;
					Class_sheet(cout);

					cout << " DO YOU WISH TO SAVE (PRESS 3) OR MAKE CHANGES(PRESS 4) "<< endl;
					CIN();
					cin >> user_reply;
				}
				if(input_ret == 1)
				{
					cout <<" THERE WAS A PROBLEM TRY AGAIN " << endl << endl;
					success = 1;
				}

				if(user_reply == "3")
				{
					do
					{
						success = 0;
						Saving( file_name, Out_fil, success );
						if (success == 1)
						{
							cout << " Please Press 1 to try again || Press 2 to quit : " ;
							cin >> user_reply;
							if(user_reply == "2")
							{
								break;
							}
							else if(user_reply == "1" ){}
							else{ cout << endl;   cout << " INCORECT INPUT. PLEASE ENTER  AGAIN \a" << endl;       user_reply = "1";               }
						}

					}while(success == 1 && user_reply == "1" );

					if(success == 2)
					{
						ofstream out_file;
						out_file.open("DETAILS.txt");
						out_file << " " ;
						out_file.close();

						cout << "THE OPERATION WAS SUCCESSFUL" << endl;
						cout << endl << endl;

						//SAVES NUMBER OF CLASSES STORED
						ofstream stored_classes;
						stored_classes.open("SYSTEM_FILES\\STORED_CLAS.txt", ios::app);
						stored_classes << Class_Name << endl;
						stored_classes.close();

						cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% "<< endl;
						cout << "%%  PLEASE PRESS 1 TO GENERATE A DATA SHEET          %% "<< endl;
						cout << "%%  PLEASE PRESS 2 TO IGNORE                         %% "<< endl;
						cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% "<< endl;
						CIN();
						cin >> user_reply;

						if (user_reply == "1")
						{
							string FOLDER = "CLASSES\\"+Class_Name;
							strcpy(file_name, FOLDER.c_str());
							mkdir(file_name);
							string f = FOLDER + "\\Datasheet_" + Class_Name + ".txt";


							Genrate_Report( file_name2, f );
							cout << endl << endl;
							cout << " YOUR DATA SHEET HAS BEEN GENERATED AS Datasheet_" << Class_Name << ".txt IN YOUR CLASSES FOLDER" << endl;
							cout << endl;
						}
						else if (user_reply == "2" ){}
						else {cout << endl;   cout << " INCORECT INPUT. PLEASE ENTER  AGAIN \a" << endl;   }
					}



				}

				else if(user_reply == "4")
				{
				cout << " PLEASE QUIT THE PROGRAM AND CHANGE WHAT YOU WANT TO CHANGE IN THE FILE DETAILS.TXT (LOCATED IN THE GRADING PROGRAM FOLDER)" << endl;
				cout << " WHEN YOU ARE DONE WITH THE EDITING PLEASE TRY AGAIN" << endl;
				}
				else{ cout << endl;   cout << " INCORECT INPUT. PLEASE ENTER  AGAIN \a" << endl; }

			}

			else if (user_reply =="3" )
			{

			}
			else{ cout << endl;   cout << " INCORECT INPUT. PLEASE ENTER  AGAIN \a" << endl;  }


		}
		else if (user_reply == "6")
		{   char answer;
			cout << " ARE YOU SURE YOU WANT TO EXIT (Y/N)" << endl;
			CIN();
			cin >> answer;
			if (answer == 'Y' || answer == 'y')
			{
			cout << " THANK YOU FOR AND GOOD BYE" << endl;
			break;
			}
			else if(answer == 'N' || answer == 'n')
			{
				user_reply = "0";
			}
			else
			{
				cout << endl;   cout << " INCORECT INPUT. PLEASE ENTER  AGAIN \a" << endl;   user_reply = "0";
			}
		}
		else
		{
			cout << " INCORECT INPUT. PLEASE ENTER  AGAIN \a" << endl;
		}

		if(success == 1)
		{
			user_reply = "0";
		}
		if(success == 2 )
		{
			user_reply = "6";
		}


	}while ( user_reply != "6");
}

void
BMCC::second_menu()
{

	int i, k;
	string user_reply;
	string user_reply_mm; // user reply for the main menu


	int user_reply_no;

	//convertion of stored name to c string
	string FOLDER = "SYSTEM_FILES\\"+Class_Name;
	string out_file = FOLDER + "\\" + Class_Name + ".txt";
	strcpy(file_name, out_file.c_str());

	//opening file
	ifstream in_file;
	in_file.open(file_name);

	if(in_file.fail())
	{
		cout << " FAILED TO OPEN" << endl;
	}
	else
	{
		//garbage collection
		//in_file >> garbage[0] >> garbage[1] >> garbage[2];
		getline(in_file,garbage[0] );
		getline(in_file,garbage[1] );
		getline(in_file,garbage[2] );

	/*	// clearing newline character
		char symbol;
		do
		{
			in_file.get(symbol);
		}while(symbol != '\n');
		////////////////////////////////////////////
	*/
		for (i=0; i <grade_compo; i++ )
		{
			getline(in_file, Grd_compo_names[i]);
			//in_file >> Grd_compo_names[i];
		}

		for(i=0; i <grade_compo; i++)
		{
			in_file >> weight[i];
		}

		// clearing new line character
		char symbol;
		do
		{
			in_file.get(symbol);
		}while(symbol != '\n');
		//////////////////////////////

		for (i=0; i < number_stu; i++)
		{


			getline(in_file,stu_names[i]);

		}
		for(i=0; i< number_stu; i++)
		{
			for (k=0; k < grade_compo; k++)
			{
				in_file >> All_grd[i][k];
			}
			in_file >> Total[i] >> Letter_grade[i] ;
		}

		in_file.close();
		do
		{

			cout << Class_Name << endl;
			cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<< endl;
			cout << " %% PRESS 1 TO UPDATE YOUR CLASS RECORDS      %%"<< endl;
			cout << " %% PRESS 2 FOR GRADING CRITERIA AND OPTIONS  %%"<< endl;
			cout << " %% PRESS 3 TO DRAW A GRAPH FOR THIS CLASS    %%"<< endl;
			cout << " %% PRESS 4 FOR MENU ON CLASS ATTENDENCE      %%"<< endl;
			cout << " %% PRESS 5 FOR A DATASHEET OF THE CLASS      %%"<< endl;
			cout << " %%                                           %%"<< endl;
			cout << " %% PRESS 0 TO GO BACK TO THE PREVIOUS MENU   %%"<< endl;
			cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<< endl;
			CIN();
			cin >> user_reply_mm;

			cout << endl << endl;
			if(user_reply_mm == "1")
			{

				do
				{

						int i,j, y=2, length;
						cout << " " << Class_Name << endl;
						cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<< endl;
						cout << " %% 1.STUDENT NAMES                           %%"<< endl;
						for(i=0; i <grade_compo ; i++)
						{
							cout <<" %% " << y << "." << Grd_compo_names[i];
							length = Grd_compo_names[i].length();
							for(j=0; j < 40 - length; j++ )
							{
								cout << " ";
							}
							cout << "%%" << endl;
							y++;
						}
						cout << " %%                                           %%"<< endl;
						cout << " %% PRESS 0(ZERO) TO GO BACK TO PREVIOUS MENU %%"<< endl;
						cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<< endl;
						//cout << "\t\t counter for grade components" << y << endl;

						CIN();
						cin >> user_reply;

						stringstream CONVERT(user_reply);
						CONVERT >> user_reply_no;

						cout << endl << endl;
						if (user_reply == "1")
						{
							do
							{
								cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
								cout << " %% PRESS 1 TO UPDATE A SPECIFIC STUDENT'S NAME%%" << endl;
								cout << " %% PRESS 2 TO UPDATE MANY STUDENT NAMES       %%" << endl;
								cout << " %%                                            %%" << endl;
								cout << " %% PRESS 0 TO GO TO PREVIOUS MENU             %%" << endl;
								cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
								CIN();
								cin >> user_reply;

								cout << endl;

								if (user_reply == "1")
								{
									cout << " PLEASE ENTER THE NUMBER OF THE STUDENT WHOSE NAME YOU WANT TO CHANGE" << endl;
									CIN();
									cin >> user_reply;
									stringstream CONVERT(user_reply);
									CONVERT >> user_reply_no;
									if(INPUT_CHECK( user_reply ) && user_reply_no <= number_stu && user_reply_no >=0 )
									{
										cout << " PLEASE ENTER THE NEW NAME FOR STUDENT " << user_reply << endl;
										CIN();
										cin >> stu_names[user_reply_no - 1];
										cout << " STUDENT " << user_reply << " NAME HAS BEEN CHANGED TO " << stu_names[user_reply_no - 1] << endl;

										int a;
										Saving(file_name , out_file, a );
										ofstream Delete;
										Delete.open("DETAILS.txt");
										Delete << " ";
										Delete.close();
										cout << "!!!!!!!!!SAVED SUCCESSFULLY!!!!!!!!!!!!!!" << endl;
										cout << endl;
										data_sheet();
										cout << endl;

									}
									if(user_reply_no > number_stu && user_reply_no <=0 )
									{
										cout << " !!!!!! NO SUCH STUDENT EXIST !!!!!!!! \a" << endl << endl;
									}
									else{}
								}
								else if(user_reply == "2")
								{
									cout << " TO UPDATE MANY STUDENT NAMES PLEASE OPEN THE FILE DETAILS.TXT  AND THEN ENTER THE STUDENT NUMBER AND THE NEW NAME IN THIS FORMAT" << endl;
									cout << " !!!!!!! THE DETAILS.TXT FILE IS LOCATED IN THE SAME FOLDER THIS PROGRAM IS IN. !!!!!!!!!!!!!!! "<< endl;
									cout << " STUDENT N#       NEW NAME   " << endl;
									cout << " PLEASE SAVE AFTER THE FILE AFTER ENTERING THE NUMBERS AND NAMES " << endl;
									cout << " !!!!!!!!!!!!!PLEASE CLOSE THE FILE AFTER SAVING!!!!!!!!!!!!!!!!!!!!!" << endl;
									cout << " PRESS 2 AFTER SAVING YOUR ENTRIES IN DETAILS.TXT FILE || PRESS 3 TO CANCEL" << endl;
									CIN();
									cin >>  user_reply;
									cout << endl;
									if(user_reply == "2")
									{
										ifstream in_file;
										in_file.open("DETAILS.txt");
										int next;
										while(in_file >> next)
										{
											 in_file >> stu_names[next-1];

										}
										in_file.close();

										cout << "PLEASE CROSSCHECK YOUR CHANGES *****************"<< endl << endl;

										Genrate_Report();

										cout << " PRESS 2 TO SAVE || PRESS 3 TO CANCEL " << endl;
										CIN();
										cin >> user_reply;
										cout << endl;
										if(user_reply == "2")
										{
											int a;

											Saving(file_name , out_file, a );
											ofstream Delete;
											Delete.open("DETAILS.txt");
											Delete << " ";
											Delete.close();
											cout << "!!!!!!!!!SAVED SUCCESSFULLY!!!!!!!!!!!!!!" << endl;
											cout << endl;
											data_sheet();
											cout << endl;



										}
										else if (user_reply == "3" )
										{
											// cancel
										}
										else
										{
											cout << " INCORRECT INPUT TRY AGAIN " << endl;
											cout << endl;
										}

									}
									else if(user_reply == "3")
									{
										// cancel
									}
									else
									{
										cout << " INCORRECT INPUT TRY AGAIN " << endl << endl;
									}

								}
								else if (user_reply == "0")
								{
									// go back to previous menu

								}
								else
								{
									cout << " INCORRECT INPUT TRY AGAIN " << endl << endl;
								}
							}while (user_reply != "0");

						}
						else if(user_reply == "0")
						{
							// go back
						}
						else if (user_reply_no >= y || user_reply_no < 0)
						{
							cout << " INCORRECT INPUT TRY AGAIN " << endl << endl;
						}
						else if(INPUT_CHECK(user_reply))
						{
							string user_reply1;
							int user_reply1_no;
							do
							{

								cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<< endl;
								cout << " %% PRESS 1 TO UPDATE A SPECIFIC STUDENT'S " << Grd_compo_names[user_reply_no-2];
								length = Grd_compo_names[user_reply_no-2].length();
								for(j=0; j < 20 - length; j++ )
								{
									cout << " ";
								}
								cout << "%%" << endl;
								cout << " %% PRESS 2 TO UPDATE MANY STUDENT'S " << Grd_compo_names[user_reply_no-2];
								for(j=0; j < 26 - length; j++ )
								{
									cout << " ";
								}
								cout << "%%" << endl;

								cout << " %%                                                            %%" << endl;
								cout << " %% PRESS 0 TO GO TO PREVIOUS MENU                             %%" << endl;
								cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
								CIN();
								cin >> user_reply1;

								stringstream CONVERT(user_reply1);

								CONVERT >> user_reply1_no;

								cout << endl << endl;
								if (user_reply1 == "1")
								{
									cout << endl;
									cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
									cout << " PRESS 1 TO ADD NEW " <<Grd_compo_names[user_reply_no-2] << " TO THE PREVIOUS " <<endl;
									cout << " PRESS 2 TO REPLACE THE WHOLE OF " << Grd_compo_names[user_reply_no-2] << " WITH A NEW  ENTRY" << endl;
									cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
									CIN();
									cin >> user_reply1;
									cout << endl;
									if(user_reply1 == "1" )
									{
										double update;
										cout << " PLEASE ENTER THE NUMBER OF THE STUDENT WHOSE " << Grd_compo_names[user_reply_no-2] << " YOU WANT TO ADD" << endl;
										CIN();
										cin >> user_reply1;

										if(INPUT_CHECK(user_reply1)  )
										{

											stringstream CONVERT(user_reply1);

											CONVERT >> user_reply1_no;

											if ( user_reply1_no <= number_stu &&  user_reply1_no >= 1)
											{
												cout << " PLEASE ENTER THE NEW " << Grd_compo_names[user_reply_no-2] << " FOR THE STUDENT " << endl;
												CIN();
												cin >> update;
												All_grd[user_reply1_no-1][user_reply_no-2] =  All_grd[user_reply1_no-1][user_reply_no-2] + update;
												cout << " STUDENT " << user_reply1 <<" [" << stu_names[user_reply1_no-1] << "] "<< Grd_compo_names[user_reply_no-2] << "  HAS BEEN CHANGED TO " << All_grd[user_reply1_no-1][user_reply_no-2] << endl;

												// totaling recent entries
												total();

												// saving
												int a;

												Saving(file_name , out_file, a );
												data_sheet();
											}
											else{ cout << " NO SUCH STUDENT EXISTS \a" << endl << endl;}
										}
										else
										{
											cout << endl<< endl;// incorect goes back
										}

									}
									else if (user_reply1 == "2" )
									{
										cout << " PLEASE ENTER THE NUMBER OF THE STUDENT WHOSE " << Grd_compo_names[user_reply_no-2] << " YOU WANT TO CHANGE" << endl;
										CIN();
										cin >> user_reply1;

										if(INPUT_CHECK(user_reply1))
										{
											stringstream CONVERT(user_reply1);

											CONVERT >> user_reply1_no;
											if ( user_reply1_no <= number_stu &&  user_reply1_no >= 1)
											{
												cout << " PLEASE ENTER THE NEW " << Grd_compo_names[user_reply_no-2] << " FOR THE STUDENT " << endl;
												CIN();
												cin >> All_grd[user_reply1_no-1][user_reply_no-2];
												cout << " STUDENT " << user_reply1 <<" [" << stu_names[user_reply1_no-1] << "] "<< Grd_compo_names[user_reply_no-2] << "  HAS BEEN CHANGED TO " << All_grd[user_reply1_no-1][user_reply_no-2] << endl;

												// totaling recent entries
												total();

												// saving
												int a;
												//string out_file = Class_Name + ".txt";
												Saving(file_name , out_file, a );
												data_sheet();
											}
											else{ cout << " NO SUCH STUDENT EXISTS \a" << endl<< endl; }
										}
									}
									else
									{
										cout << " INCORRECT INPUT TRY AGAIN " << endl << endl;
									}

								}
								else if ( user_reply1 == "2")
								{
									string user_reply2;
									cout << endl;
									cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
									cout << " PRESS 1 TO ADD NEW " <<Grd_compo_names[user_reply_no-2] << " TO THE PREVIOUS " <<endl;
									cout << " PRESS 2 TO REPLACE THE WHOLE OF " << Grd_compo_names[user_reply_no-2] << " WITH A NEW  ENTRY" << endl;
									cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
									CIN();
									cin >> user_reply2;

									cout << endl << endl;

									PREP( );

									cout << " TO UPDATE MANY STUDENT "<< Grd_compo_names[user_reply_no-2] <<" PLEASE OPEN THE FILE DETAILS.TXT AND THEN ENTER THE STUDENT'S NUMBER AND THE NEW "<< Grd_compo_names[user_reply_no-2]<< endl;
									cout << " !!!!!!! THE DETAILS.TXT FILE IS LOCATED IN THE SAME FOLDER THIS PROGRAM IS IN. !!!!!!!!!!!!!!! "<< endl;
									cout << " YOUR ENTRIES SHOULD BE IN THIS FORMAT " << endl;
									cout << " STUDENT N#      " << Grd_compo_names[user_reply_no-2] << endl;
									cout << " PLEASE SAVE THE FILE AFTER ENTERING THE STUDENT NUMBERS AND THEIR NEW " << Grd_compo_names[user_reply_no-2] << endl;
									cout << " !!!!!!!!!!!!! PLEASE CLOSE THE FILE AFTER SAVING !!!!!!!!!!!!!!!!!!!!!\a" << endl;
									cout << " PRESS 2 AFTER SAVING YOUR ENTRIES IN DETAILS.TXT FILE || PRESS 3 TO CANCEL" << endl;
									CIN();
									cin >>  user_reply1;

									cout << endl;

									if( user_reply1 == "2" && ( user_reply2 == "1"   || user_reply2 == "2"  ) )
									{
										char garbage;
										string update1;
										char symbol, symbol1;
										ifstream in_file;
										in_file.open("DETAILS.txt");
										int next;

										if(user_reply2 == "1" )
										{	double update;


											while(in_file >> next)
											{
												in_file >> symbol1; //reading '['
												do
												{
													in_file >> symbol1;

												}while (symbol1 != ']');


												for (i=0; i<3 ; i++)
												{
													in_file >> garbage;
												}

												do
												{
													in_file.get(symbol);

												}while(symbol == ' ');


												if (symbol != '\n' )
												{
													in_file.putback(symbol);
													in_file >> update1;

													if(INPUT_CHECK2(update1))
													{
														stringstream CONVERT(update1);
														CONVERT >> update;

														All_grd[next-1][user_reply_no-2] =  All_grd[next-1][user_reply_no-2] + update;
													}
													else
													{
														cout << "\a YOU ENTERED AN INVALID INPUT FOR STUDENT " << next << endl << endl;
													}

												}
												else if(symbol == '\n')
												{}
												else{}
											}
											in_file.close();
										}
										else if(user_reply2 == "2")
										{

											while(in_file >> next)
											{
												in_file >> symbol1; //reading '['
												do
												{
													in_file >> symbol1;
												}while (symbol1 != ']');

												for (i=0; i<3 ; i++)
												{
													in_file >> garbage;
												}

												do
												{
													in_file.get(symbol);

												}while(symbol == ' ');


												if (symbol != '\n')
												{
													in_file.putback(symbol);
													in_file >> update1;

													if( INPUT_CHECK2(update1) )
													{
														stringstream CONVERT(update1);
														CONVERT >> All_grd[next-1][user_reply_no-2];

													}
													else
													{
														cout << "\a YOU ENTERED AN INVALID INPUT FOR STUDENT " << next << endl << endl;
													}

												}
												else if (symbol == '\n' )
												{

												}
												else{}
											}
											in_file.close();
										}
										cout << "******************** PLEASE CROSSCHECK YOUR CHANGES *****************"<< endl << endl;

										// totaling for recent entries
										total();

										Genrate_Report();

										cout << " PRESS 2 TO SAVE || PRESS 3 TO CANCEL " << endl;
										CIN();
										cin >> user_reply1;

										cout << endl;

										if (user_reply1 == "2"  )
										{
											int a;
											//string out_file = Class_Name + ".txt";
											Saving(file_name , out_file, a );
											ofstream Delete;
											Delete.open("DETAILS.txt");
											Delete << " ";
											Delete.close();
											cout << "!!!!!!!!!SAVED SUCCESSFULLY!!!!!!!!!!!!!!" << endl;
											cout << endl;
											data_sheet();
											cout << endl;
										}
										else if (user_reply1 == "3")
										{
											// go back
										}
										else
										{
											cout << " INCORRECT INPUT TRY AGAIN " << endl << endl;
										}
									}
									else if ( user_reply1 == "3" )
									{
										// go back
									}
									else
									{
										cout << " INCORRECT INPUT TRY AGAIN " << endl << endl;
									}
								}
								else if (user_reply1 == "0")
								{
									user_reply =1; // previous menu
									cout  << endl << endl;
								}
								else
								{
									cout << " INCORECT INPUT. TRY AGAIN"<< endl << endl;  // go back
								}

							}while (user_reply1 != "0" );
						}
						else{}
				}while (user_reply != "0" );

			}
			else if (user_reply_mm == "2")
			{
				do
				{
					cout << " !!!!!!!!!!!!!!!!  PLEASE BEFORE USING THIS GRADING OPTION YOU ARE RECOMMENDED TO HAVE ENTERED ALL GRADING COMPONENTS OF THE CLASS !!!!!!!!!!!!!!!!!!!" << endl;
					cout << " !!!!!!!!!!!!!!!!!!!!!!!!!!!!!  IF YOU HAVE NOT DONE THE ABOVE PLEASE GO BACK  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<< endl << endl;
					cout << Class_Name << endl;
					cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
					cout << " %% PRESS 1 TO SET  GRADING CRITERIA OR THRESHOLD                                           %%" << endl;
					cout << " %% PRESS 2 TO GRADE THIS CLASS (RECOMMENDED AFTER ALL GRADING COMPONENTS HAVE BEEN FILLED) %%" << endl;
					cout << " %%                                                                                         %%" << endl;
					cout << " %% PRESS 0 TO GO BACK TO THE PREVIOUS MENU                                                 %%" << endl;
					cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
					CIN();
					cin >> user_reply;
					cout << endl<< endl;

					if (user_reply == "1" )
					{

						cout << " OPEN THE FILE DETAIL.TXT AND ENTER THE GRADE SIGN  AND ITS UPPER AND LOWER LIMIT MARKS \a " << endl;
						cout << " !!!!!!! THE DETAILS.TXT FILE IS LOCATED IN THE SAME FOLDER THIS PROGRAM IS IN. !!!!!!!!!!!!!!! "<< endl;
						cout << " YOUR ENTRY SHOULD BE IN THIS FORMAT " << endl << endl;
						cout << " GRADE       HIGHEST SCORE      LOWEST SCORE" << endl << endl;
						cout << "!!!!!!!!!!!!!!!!!!!!!!!!! AFTER ENTERING THE YOUR GRADE ENTRIES PLEASE SAVE THE FILE AND CLOSE THE FILE AFTER SAVING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
						cout << " PRESS 2 AFTER SAVING YOUR ENTRIES IN DETAILS.TXT FILE TO CONTINUE || PRESS 3 TO CANCEL" << endl;
						CIN();
						cin >> user_reply;
						cout << endl;
						if (user_reply == "2")
						{
							string file = "DETAILS.txt" ;
							strcpy(file_name, file.c_str());
							const int num_grade = Nof(file_name);
							int num_grade1 = num_grade;
								//cout << "\t " << num_grade << endl;
							string GRADE[num_grade];
							double GRADES2[num_grade][2];

							ifstream in_file;
							in_file.open("DETAILS.txt");
							for(i=0; i < num_grade1; i++)
							{
								in_file >>	GRADE[i];
								for(k =0; k < 2; k++)
								{
									in_file >> GRADES2[i][k];
								}
							}
							in_file.close();


							cout << " **************************** PLEASE CROSSCHECK ***********************************" << endl << endl;
							cout.setf(ios:: left);
							cout << "\t"  << setw(12) << " GRADE " << "MARKS" << endl;
							cout << "\t" << setw(12) << "=======" << "=====" << endl;

							for (i =0; i <num_grade1; i++ )
							{
								cout <<"\t" << setw(12) << GRADE[i] << GRADES2[i][0] <<"--> " << GRADES2[i][1] << endl << endl;


							}

							cout << " IF YOUR ARE SATISFIED WITH THE ABOVE ENTRIES PRESS 2 TO SAVE IT || PRESS 3 TO CANCEL " << endl;
							CIN();
							cin >> user_reply;
							if(user_reply == "2")
							{
								string file = FOLDER + "\\" + "GRADE_" +  Class_Name + ".txt";
								strcpy(file_name, file.c_str());
								ofstream out_file;
								out_file.open(file_name);
								for (i=0; i < num_grade1; i++)
								{
									//           letter                 high score              lower score
									out_file << GRADE[i] << "   " << GRADES2[i][0]<< "   " << GRADES2[i][1] << endl;

								}

								out_file.close();
								// clearing details file after saving
								ofstream Delete;
								Delete.open("DETAILS.txt");
								Delete << " ";
								Delete.close();

							}
							else if ( user_reply == "3")
							{
								// goback
								cout << endl << endl;
							}
							else
							{
								cout << " INCORECT INPUT. TRY AGAIN \a"<< endl << endl;
							}

						}
						else if (user_reply == "3")
						{
							// goback
						}
						else
						{
							cout << " INCORECT INPUT. TRY AGAIN \a"<< endl<< endl;
						}
					}
					else if (user_reply == "2")
					{
						string file = FOLDER +"\\" + "GRADE_" +  Class_Name + ".txt";
						strcpy(file_name, file.c_str());
						int num_grade1;

						ifstream in_file;
						in_file.open(file_name);
						if(in_file.fail())
						{
							cout << " !!!!!!!!! THERE WAS A PROBLEM IT SEEM YOU HAVE NOT SET GRADING PARAMETERS FOR THIS CLASS YET !!!!!!!! \a" << endl;
							cout << " ********* PLEASE SET THE PARAMETERS BEFORE PROCEDING TO GRADE THIS CLASS *******************" << endl << endl;
						}
						else
						{
							double max_total_no;
							string max_total;
							double marks;
							num_grade1 = Nof(file_name);
							const int num_grade = num_grade1;
							ifstream in_file;
							in_file.open(file_name);
							string GRADE[num_grade];
							double GRADES2[num_grade][2];

							for(i =0; i < num_grade; i++ )
							{
								in_file >> GRADE[i];
								for(k=0; k < 2;k++ )
								{
									in_file >> GRADES2[i][k];
								}
							}
							in_file.close();

							cout << " WHAT IS THE MAXIMUM TOTAL POINTS FOR THE CLASS" << endl;
							CIN();
							cin >> max_total;
							cout << " you" << endl;

							//cout << endl << endl;

							if( INPUT_CHECK2( max_total ))
							{	// grading all student based on totals
												//cout << " you" << endl;
								stringstream CONVERT(max_total);
								CONVERT >> max_total_no;
												//cout << " you" << endl;
								for(i=0; i < number_stu; i++)
								{
												//cout << " you" << endl;
									marks = ( Total[i] / max_total_no ) * 100;
									Letter_grade[i] =  GRADING( GRADE, GRADES2, marks, num_grade );
								}

								Genrate_Report();
								data_sheet();

								cout << endl;
								cout << " *****************  THE DATA SHEET HAS BEEN UPDATED FOR " << Class_Name << " ****************** " << endl;

								int a;
								string out_file = FOLDER + "\\" + Class_Name + ".txt";
								Saving(file_name , out_file, a );
							}
							else{}

						}
					}
					else if (user_reply == "0")
					{
								// going back to previous menu
					}
					else
					{
						cout << " INCORECT INPUT. TRY AGAIN \a"<< endl << endl;
					}



				}while (user_reply != "0");
			}
			else if (user_reply_mm == "3")
			{
				string file = FOLDER + "\\" + "GRADE_" +  Class_Name + ".txt";
				strcpy(file_name, file.c_str());
				int num_grade1;

				ifstream in_file;
				in_file.open(file_name);
				if(in_file.fail())
				{
					cout << " !!!!!!!!! THERE WAS A PROBLEM IT SEEM YOU HAVE NOT SET GRADING PARAMETERS FOR THIS CLASS YET !!!!!!!! \a" << endl;
					cout << " ********* PLEASE SET THE PARAMETERS BEFORE PROCEDING TO GRADE THIS CLASS *******************" << endl;
				}
				else
				{
					int j;
					num_grade1 = Nof(file_name);
					const int num_grade = num_grade1;
					ifstream in_file;
					in_file.open(file_name);
					string GRADE[num_grade];

					// intitializing counter
					int counter[num_grade];
					for (i =0; i < num_grade; i++)
					{
						counter[i] = 0;
					}

					double GRADES2[num_grade][2];

					for(i =0; i < num_grade; i++ )
					{
						in_file >> GRADE[i];
						for(k=0; k < 2;k++ )
						{
							in_file >> GRADES2[i][k];
						}
					}
					in_file.close();

					//cout << " NUMBER OF GRADES ARE " << num_grade << endl;
					// geting number of grades
					 int found = 0;
					for ( i=0; i < number_stu; i++)
					{
						//cout << " NEW STUDENT" << endl;

						for(j=0; j < num_grade && found == 0 ; j++ )
						{
							//cout << "\t IS " << GRADE[j] << " EQUAL TO " << Letter_grade[i] << endl;;
							if( GRADE[j] == Letter_grade[i] )
							{
								found = 1;
								counter[j]++;
								//cout << "\t " << GRADE[j] << " IS EQUAL TO " <<Letter_grade[i] << " which has occured " << counter[j] << " times" << endl;
							}
							else
							{
								//cout << "\t NO " << GRADE[j] << " IS NOT EQUAL TO  " << Letter_grade[i] << endl;
							}
						}

						found = 0;
					}

					// finding maximum counter
					int max_counter = counter[0];
					int pos1;
					for ( i =0; i< num_grade; i++)
					{

						if(max_counter < counter[i])
						{
							max_counter = counter[i];
							pos1 = i;
						}
						else{}
					}

					const int max1_counter =  max_counter;

					//cout << " \t The highest grade is " <<  GRADE[pos1] << " it occured " << max_counter<< endl;

					//string display[max1_counter][num_grade];
					string ** display;

					display = new string *[max1_counter];

					for(i=0; i < max1_counter; i++)
					{
						display[i] = new string[num_grade];
					}

					// entering x for graph
					for( j=0; j< num_grade; j++)
					{
						for( i =0; i < max1_counter; i++ )
						{
							if(i >= (max_counter - counter[j]))
							{
								display[i][j] = "X";
							}
							else
							{
								display[i][j] = " ";
							}

						}
					}

					GRADING1(cout, num_grade, max1_counter, display, GRADE, counter   );
					cout << endl<< endl;

					cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
					cout << " %% PLEASE PRESS 1 TO GENERATE A HARD COPY OF THIS GRAPH %%" << endl;
					cout << " %% PLEASE PRESS 0 TO IGNORE THIS OPTION                 %%" << endl;
					cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
					CIN();
					cin >> user_reply;

					if (user_reply == "1" )
					{
						string FOLDER1 = "CLASSES\\" + Class_Name;
						string file = FOLDER1 +"\\" +"GRAPHICAL_" +  Class_Name + ".txt";
						strcpy(file_name, file.c_str());
						ofstream out_file ;
						out_file.open(file_name);

						GRADING1(out_file, num_grade, max1_counter, display,GRADE, counter );
						out_file.close();
						cout << endl<< endl;
					}
					else if (user_reply ==  "0" )
					{
						cout << endl<< endl;
						// do nothing
					}
					else
					{
						cout << "\a INCORECT INPUT. TRY AGAIN"<< endl;
						cout << endl;
					}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					/*
					cout.setf(ios:: left);

					// displaying graph

					cout << endl;
					cout << "                        GRAPH OF GRADES FOR " << Class_Name << endl;
					cout << "********************************************************************************************************" << endl << endl;

					for (i=0; i < num_grade; i++)
					{
						cout << "__" << "__";
					}
					cout << "_" << endl;

					for(i=0; i < max1_counter; i++)
					{

						for(j=0; j< num_grade; j++)
						{
							cout << "| "; cout << setw(2) << display[i][j];
						}
						cout <<"|"<< endl;
					}

					//cout<< "********************************************************************************************************" << endl;
					for(j=0; j< num_grade; j++)
					{
						cout <<"|-"<<"--";
					}
					cout <<"|" << endl;
					for(i=0; i < num_grade; i++ )
					{
						cout <<"| "<< setw(2) << GRADE[i] ;
					}
					cout <<"|" << endl;

					for(j=0; j< num_grade; j++)
					{
						cout <<"^^"<<"^^";
					}
					cout <<"^" << endl;
					*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				}


			}
			else if (user_reply_mm == "4")
			{
				cout << " FOR THIS FEATURE PLEASE DONATE OR ASK THE PROGRAMMER TO KINDLY ADD IT " << endl << endl;
			}
			else if(user_reply_mm == "5")
			{
				do
				{
					cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
					cout << " %% PRESS 1 TO GENERATE REPORT ON THE SCREEN       %%" << endl;
					cout << " %% PRESS 2 TO GENERATE REPORT AS A DATASHEET FILE %%"	<< endl;
					cout << " %%                                                %%" << endl;
					cout << " %% PRESS 0 TO GO BACK TO PREVIOUS MENU            %%" << endl;
					cout << " %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
					CIN();
					cin >> user_reply;

					if (user_reply == "1" )
					{
						cout << endl << endl << endl;
						Genrate_Report();

					}
					else if(user_reply == "2" )
					{
						data_sheet();
					}
					else if ( user_reply == "0")
					{
						cout << endl << endl;
						user_reply = "0";   // go back
					}
				}while ( user_reply != "0");
			}
			else if(user_reply_mm == "0")
			{

			}
			else
			{
				cout << " INCORECT INPUT. TRY AGAIN"<< endl;
				user_reply = 1;
				cout << endl << endl;
			}
		}while(user_reply_mm !=  "0");

	}





}

void
BMCC::Saving( char a[], string x, int& y )
{

	int i,k;
	 strcpy(a, x.c_str());

	ofstream out_file;
	out_file.open(a);

	if( out_file.fail())
	{
		cout << " SAVING FAILED : Try Again " << endl;
		y = 1 ;

	}
	else
	{
		out_file << number_stu << endl;
		out_file << grade_compo << endl;
		out_file << Class_Name << endl;
		for (i=0; i <grade_compo; i++ )
		{
			out_file << Grd_compo_names[i] << endl;
		}
		//out_file << endl;

		for(i=0; i <grade_compo; i++)
		{
			out_file << weight[i]<< "\t";
		}
		out_file << endl;

		for (i=0; i < number_stu; i++)
		{
			out_file << stu_names[i] ;
			out_file << endl;
		}

		for( i=0; i < number_stu; i++)
		{
			for (k=0; k < grade_compo; k++)
			{
				out_file << "\t" << All_grd[i][k];
			}

			cout.setf(ios::fixed); cout.setf(ios::showpoint); cout.precision(2);

			out_file << "\t" << Total[i] <<"\t"<< Letter_grade[i] << endl;
		}

		out_file.close();
		y = 2;
		cout << " SAVING WAS SUCCESSFULL" << endl;

		cout << " THE CLASS FILE FOR " << Class_Name << " WAS SAVED AS " << endl;
	}


}


void
BMCC::Genrate_Report( char a[], string x )
{
	strcpy(a, x.c_str());

	ofstream out_file;
	out_file.open(a);

	Class_sheet(out_file);
	out_file.close();

}

void
BMCC::Genrate_Report()
{
	Class_sheet(cout);
}

void
BMCC::CIN()
{
	cout << " ==> ";
}

//INTITIALIZATION FUNCTION
void
BMCC::INI()
{
	int i, k;
	for(i=0; i < number_stu; i++ )
	{
		Letter_grade[i] = "--";
		Total[i] = 0;
		for(k=0; k < grade_compo; k++)
		{

			All_grd[i][k] = 0;
		}
	}
}

int
BMCC:: longest_name()
{
	int i, MAX;
	MAX = stu_names[0].length();
	for(i=0; i < number_stu; i++ )
	{
		if(MAX < stu_names[i].length() )
		{
			MAX = stu_names[i].length();
		}
		else
		{}
	}

	return MAX;
}

int
BMCC :: longest_grd_comp_name()
{
	int i, MAX;
	MAX = Grd_compo_names[0].length();
	for(i=0; i < grade_compo; i++ )
	{
		if(MAX < Grd_compo_names[i].length() )
		{
			MAX = Grd_compo_names[i].length();
		}
		else
		{}
	}

	return MAX;
}

void
BMCC::data_sheet()
{
	string f = "CLASSES\\" + Class_Name + "\\" +"Datasheet_" + Class_Name + ".txt";
	Genrate_Report( file_name2, f );
	cout << endl << endl;
	cout << " YOUR DATA SHEET HAS BEEN GENERATED AS " << f << endl;
	cout << endl;
}

int
BMCC:: Nof(char a[] )
{

	//strcpy(file_name, x.c_str());
	string f;
	int t;
	int counter = 0;
	ifstream in_file;
	in_file.open(a);
	if (in_file.fail() )
	{
		return -1;
	}
	else
	{
		while (in_file >> f)
		{
			in_file >> t >> t;
			counter++;
		}
		in_file.close();
		return counter;
	}
}

//total
void
BMCC::total()
{
	int i;
	int k;
	cout.setf(ios::fixed); cout.setf(ios::showpoint); cout.precision(2);
	for(i=0; i < number_stu; i++)
	{
		Total[i] = 0;

		//cout << " \t  student" << i << " TOTAL IS BEING CALCULATED " << endl;
		for(k=0; k < grade_compo; k++)
		{

			//cout << " \t  "
			Total[i]  =   Total[i]  + ( All_grd[i][k] * weight[k]);
			//Total[5]  =   Total[5]  + ( All_grd[i][k] * weight[i]);
		}
	}

}

string
BMCC:: GRADING( string grd[], double grd1[][2], double m, int numgrd )
{
	int i, pos, found = 0;
	for (i=0; i < numgrd; i++ )
	{
		if(  (grd1[i][0] >= m) && ( m >= grd1[i][1] ) )
		{
			found = 1;
			pos = i;
		}

	}
	if(found == 0)
	{
		for(i=0; i < numgrd ; i++)
		{
			if ( (grd1[i][0] >= m ) && ( m >= (grd1[i][1] - 0.99 ) ) )
			{
				pos = i;
			}
		}
	}

	return grd[pos];
}

void
BMCC :: GRADING1(ostream& f, const int num_grade, const int max1_counter, string **display, string GRADE[], int counter[]   )
{
	int j, i ;
	f.setf(ios:: left);

	// displaying graph

	f << endl;
	f << "      GRAPH OF GRADES FOR " << Class_Name << endl;
	f << "************************************************************************" << endl << endl;

	for (i=0; i < num_grade; i++)
	{
		f << "__" << "__";
	}
	f << "_" << endl;

	for(i=0; i < max1_counter; i++)
	{

		for(j=0; j< num_grade; j++)
		{
			f << "| "; f << setw(2) << display[i][j];
		}
		f <<"|"<< endl;
	}

	//f<< "********************************************************************************************************" << endl;
	for(j=0; j< num_grade; j++)
	{
		f <<"|-"<<"--";
	}
	f <<"|" << endl;
	for(i=0; i < num_grade; i++ )
	{
		f <<"| "<< setw(2) << GRADE[i] ;
	}
	f <<"|" << endl;

	for(j=0; j< num_grade; j++)
	{
		f <<"^^"<<"^^";
	}
	f <<"^" << endl;
	f << endl;

	f << "\t__" << "_________________________________"<< endl;
	f << "\t|"  << setw(10) << " GRADE "<< setw(5)<<" " << setw(18) <<" N# of STUDENTS" << "|" << endl;
	f << "\t|"  << setw(10) << "==========" << "=========" << "==============|" << endl;

	for ( i=0; i< num_grade; i++)
	{
		f << "\t| " << setw(9) << GRADE[i] << setw(9) << "==>"<< setw(14)  << counter[i] << "|" << endl;
		f << "\t|_" << "________________________________|"<< endl;

	}

}

bool
BMCC :: INPUT_CHECK( string x )
{
	const int size = x.length() + 1 ;
	char f[size];

	strcpy(f, x.c_str());

	bool r = atoi(f);

	if(r)
	{

		return r;
	}
	else
	{
		cout << endl;
		cout << " INCORRECT INPUT TRY AGAIN " << endl;
		return r;
	}

}

bool
BMCC :: INPUT_CHECK2( string x )
{
	const int size = x.length() + 1 ;
	char f[size];

	strcpy(f, x.c_str());

	bool r = atof(f);

	if(r)
	{

		return r;
	}
	else
	{
		cout << endl;
		cout << " INCORRECT INPUT TRY AGAIN " << endl;
		return r;
	}

}

void
BMCC ::PREP( )
{
	int i, y=1;
	ofstream out_file;
	int n = longest_name();
	out_file.open("DETAILS.txt");

	stringstream CONVERT;
	CONVERT << number_stu;
	string no_stu = CONVERT.str();

	int size = no_stu.length();
	out_file.setf(ios:: left);
	for (i=0; i < number_stu; i++)
	{
		string name_bracket =  "[" + stu_names[i] + "]";
		out_file << setw(size+3) << y << setw(n+3)<< name_bracket << setw(4) << "==> " << endl;
		y++;
	}
	out_file.close();

}







