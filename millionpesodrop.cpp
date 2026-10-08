#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void shuffleCategories(int &cat1, int &cat2)
{
	int temp = cat1;
	cat1 = rand() % 8;
	cat2 = rand() % 8;
	while(cat2 == cat1)
	{
	cat2 = rand() % 8;
	}
}

void shuffleQuestion(int &rQuestion)
{
	rQuestion = rand() % 5;
}

void displayQuestion(string question, string choices[], int money) 
{
	system("cls");
	cout << "\n\t\t\t-------------------------------------------------------------------------------------------------------\n";
	cout << "\t\t\t\tCurrent money: P" << money << endl;
	cout << endl;
	cout << "\t\t\t\tQuestion: " << question << endl;
	cout << endl;
	for (int i = 0; i < 4; ++i)
	{
 		cout << "\t\t\t\t" << (i + 1) << ". " << choices[i] << endl;
 	}	
	cout << endl;
}

void displayQuestionTwo(string question, string choices[], int money) 
{
	system("cls");
 	cout << "\n\t\t\t------------------------------------------------------------------------------------------------------\n";
 	cout << "\t\t\t\tCurrent money: P" << money << endl;
 	cout << endl;
 	cout << "\t\t\t\tQuestion: " << question << endl;
 	cout << endl;
 	for (int i = 0; i < 3; ++i)
	{
 		cout << "\t\t\t\t" << (i + 1) << ". " << choices[i] << endl;
 	}
 	cout << endl;
}

void displayQuestionThree(string question, string choices[], int money) 
{
	system("cls");
 	cout << "\n\t\t\t------------------------------------------------------------------------------------------------------\n";
 	cout << "\t\t\t\tCurrent money: P" << money << endl;
 	cout << endl;
 	cout << "\t\t\t\tQuestion: " << question << endl;
 	cout << endl;
 	for (int i = 0; i < 2; ++i)
	{
 		cout << "\t\t\t\t" << (i + 1) << ". " << choices[i] << endl;
 	}
 	cout << endl;
}

bool askQuestion(int rQuestion, string &question, string options[4], int correctAnswer, int &money)
{
	int totalBet = 0;
	int amounts[4];
 	while (totalBet < money)
	{
	totalBet = 0;
	amounts[0] = {0};
	amounts[1] = {0};
	amounts[2] = {0};
	amounts[3] = {0};
 	displayQuestion(question, options, money);
 	for (int i = 0; i < 4; ++i)
		{
 			if (totalBet < money)
			{
 				cout << "\t\t\t\tEnter the amount of money you want to place for option " << (i + 1) << ": P";
 				int betAmount = 0;
 				cin >> betAmount;
 				if (betAmount <= money && betAmount >= 0)
				{
 					amounts[i] = betAmount;
 					totalBet += betAmount;
 				}
 			}
 		}
 		if (totalBet == money)
 		{
 			break;
		}
 	}
 	cout << "\n\t\t\t\tMoney entered for each option:\n";
 	
 	for (int i = 0; i < 4; ++i)
	{
 		cout << "\t\t\t\tOption " << (i + 1) << ": P" << amounts[i] << endl;
 	}
 	
	cout << endl;
 	
	for (int i = 0; i < 4; ++i)
	{
 		if (i == correctAnswer)
		{
 			cout << "\t\t\t\tYou correctly placed P" << amounts[i] << " on option " << (i + 1) << ". You keep the money.\n";
 			money = amounts[i];
 		}
		else
		{
 		cout << "\t\t\t\tYou dropped P" << amounts[i] << " for option " << (i + 1) << ".\n";
 		}
 	}
 return totalBet > 0;
}

bool askQuestionTwo(int rQuestion, string &question, string options[3], int correctAnswer, int &money)
{
	int amounts[3] = {0};
 	int totalBet = 0;
 	while (totalBet < money)
	{
		amounts[0] = {0};
		amounts[1] = {0};
		amounts[2] = {0};
		displayQuestionTwo(question, options, money);
 		for (int i = 0; i < 3; ++i)
		{
 			if (totalBet < money)
			{
 				cout << "\t\t\t\tEnter the amount of money you want to place for option " << (i + 1) << ": P";
 				int betAmount;
 				cin >> betAmount;
 				if (betAmount <= money && betAmount >= 0)
					{
 					amounts[i] = betAmount;
 					totalBet += betAmount;
 					}
 			}
 		}
 		if (totalBet == money)
 		{
			break;
		}
 	}
 	cout << "\n\t\t\t\tMoney entered for each option:\n";
 	for (int i = 0; i < 3; ++i)
	{
 		cout << "\t\t\t\tOption " << (i + 1) << ": P" << amounts[i] << endl;
 	}
	cout << endl;
 	for (int i = 0; i < 3; ++i)
	{
 		if (i == correctAnswer)
		{
 			cout << "\t\t\t\tYou correctly placed P" << amounts[i] << " on option " << (i + 1) << ". You keep the money.\n";
 			money = amounts[i];
 		}
		else
		{
 		cout << "\t\t\t\tYou dropped P" << amounts[i] << " for option " << (i + 1) << ".\n";
 		}
 	}
 return totalBet > 0;
}

bool askQuestionThree(int rQuestion, string &question, string options[2], int correctAnswer, int &money)
{
	int amounts[2] = {0};
	int totalBet = 0;
 	while (totalBet < money)
	{
	amounts[0] = {0};
	amounts[1] = {0};
 		displayQuestionThree(question, options, money);
 		for (int i = 0; i < 2; ++i)
		{
 			if (totalBet < money)
			{
 				cout << "\t\t\t\tEnter the amount of money you want to place for option " << (i + 1) << ": P";
 				int betAmount;
 				cin >> betAmount;
 				if (betAmount <= money && betAmount >= 0)
				{
 					amounts[i] = betAmount;
 					totalBet += betAmount;
 				}
 			}
 		}
 		if (totalBet == money)
 		{
 			break;
		}
 	}
 	cout << "\n\t\t\t\tMoney entered for each option:\n";
 	for (int i = 0; i < 2; ++i)
	{
 	cout << "\t\t\t\tOption " << (i + 1) << ": P" << amounts[i] << endl;
 	}
 	cout << endl;
 	for (int i = 0; i < 2; ++i)
	{
 		if (i == correctAnswer)
		{
			cout << "\t\t\t\tYou correctly placed P" << amounts[i] << " on option " << (i + 1) << ". You keep the money.\n";
			money = amounts[i];
 		}
		else
		{
 			cout << "\t\t\t\tYou dropped P" << amounts[i] << " for option " << (i + 1) << ".\n";
 		}
 	}
 return totalBet > 0;
}

void minigame(int &money)
{
	int prize = 50000;
 	int randomNumber = rand() % 30 + 1;
 	int userGuess = 0;
 	int attempts = 0;
 	cout << endl;
 	cout << "\t\t\t\t=======================================================================";
 	cout << "\t\t\t\t\tRandom Number Guessing Minigame!\n";
 	cout << "\t\t\t\t\tYou have 5 attempts to guess the correct number between 1-30\n";
 	cout << "\t\t\t\t\tIf you guess correctly you get an extra P50,000 to your money!\n";
 	cout << "\n\t\t\t\t\t Your current money is: " << money << endl;
 	while (attempts != 5)
	{
 		cout << "\t\t\t\t\tEnter your guess: ";
 		cin >> userGuess;
 		attempts++;
 		if (userGuess < randomNumber)
		{
 			cout << "\t\t\t\t\tToo low!" << endl;
 		}
 		else if (userGuess > randomNumber)
		{
 			cout << "\t\t\t\t\tToo high!" << endl;
		}
		else
		{
 			cout << "\t\t\t\t\tCongratulations! You've guessed the right number: " << randomNumber << endl;
 			cout << "\t\t\t\t\tIt took you " << attempts << " attempts." << endl;
 			money += prize;
 			cout << "\t\t\t\t\tYour money is now: " << money;
 			break;
 		}
 		
 		if(attempts >= 5)
 		{
 			cout << endl;
 			cout << "\t\t\t\t\tThe correct number was: " << randomNumber << endl;
 			cout << "\t\t\t\t\tYou won nothing~ Back to the game!\n";
 			break;
 		}
 	}
}

void minigame_two(int &money)
{
	int prize = 100000;
	int userPoint = 0;
 	int AIPoint = 0;
 	cout << "\n\t\t\t\t\tThe Second Minigame: Stat Distribution\n";
 	cout << "\t\t\t\t\tThe aim of the game is, you and the AI will both have a combined stat allocation of 50\n";
 	cout << "\t\t\t\t\tYou will distribute that 50 to 5 different stats and then it will be compared with the computer's own distribution\n";
 	cout << "\t\t\t\t\tIf your stat is higher, you get a point, if the AI's stat is higher, they get a point\n";
 	cout << "\t\t\t\t\tBEGIN!\n";
 	cout << "\n\t\t\t\t\t Your current money: " << money << endl;

 	int userStat = 50;
 	int uStat[5];
 	cout << "\t\t\t\t\tEnter your stats!\n";
 	for(int i = 0; i < 5; i++)
 	{
 		cout << "\t\t\t\t\tEnter stat #" << i+1 << ": ";
 		cin >> uStat[i];
		userStat -= uStat[i];
	}
	
 	int AIStat = 50;
 	int aStat[5];
 	for(int i = 0; i < 5; i++)
	{
		aStat[i] = rand() % (AIStat + 1);
 		AIStat -= aStat[i];
	}
	if(userStat != 0 && AIStat != 0)
	{
		cout << "\t\t\t\t\tYou did not distribute the stats correctly!\n";
		minigame_two(money);
	}
	
	for(int i = 0; i < 5; i++)
	{
		cout << endl;
		cout << "\t\t\t\t\tUser Stat: " << uStat[i] << " vs. " << "AI Stat: " << aStat[i] << endl;
		if(uStat[i] > aStat[i])
		{
			cout << "\n\t\t\t\t\tYou got a point." << endl;
			userPoint++;
		}
		else if(uStat[i] < aStat[i])
		{
			cout << "\n\t\t\t\t\tAI gets the point." << endl;
			AIPoint++;
		}
		else
		{
		cout << "\n\t\t\t\t\tDraw!" << endl;
		continue;
		}
	}
	
	if(userPoint > AIPoint)
	{
		cout << endl;
		cout << "\n\t\t\t\t\tYou won the 100,000 Prize!\n";
		money += prize;
		cout << "\t\t\t\t\tYour money is now: " << money << endl;
		cout << "\t\t\t\t\tNow let's get back to the game!\n";
	}
	else
	{
		cout << endl;
		cout << "\n\t\t\t\t\tToo bad! You did not beat the AI!\n";
		cout << "\t\t\t\t\tBack to the game for you!\n";
	}
}

int main()
{
 srand(static_cast<int>(time(0)));
 
 string categories[8] = {"History", "Geography", "Memes", "Science", "General Knowledge", "Gaming", "Music", "Sports"};
 
 string questions_history[5] = 
 {"Ferdinand Magellan was killed in the Battle of _____",
 "During WW2, Which country only lasted 6 hours against Germany?",
 "How did Alexander the Great untangle the Gordian Knot?",
 "In WW1, What was the reply a surrounded Allied force sent to the Germans when asked to surrender?",
 "How tall was Napoleon Bonaparte?"};
 
 string fOptions_history[5][4] = {{"Marawi", "BGC", "Mactan", "Divisoria"},
 								 {"France", "Netherlands", "Denmark", "Norway"},
 								 {"He cut it", "He solved it carefully after months of trying", "He dropped it in water", "He pulled out the innermost tangle"},
 								 {"You must be crazier than a mango", "NUTS!", "Hell nah", "We don't speak German"},
								 {"5'2\"", "5'0\"", "5'6\"", "5'4\""}};
 string sOptions_history[5][3] = {{"BGC", "Mactan", "Divisoria"},
 								 {"France", "Netherlands", "Denmark"},
								 {"He cut it", "He dropped it in water", "He pulled out the innermost tangle"},
 								 {"You must be crazier than a mango", "NUTS!", "We don't speak German"},
 								 {"5'0\"", "5'6\"", "5'4\""}};
 string lOptions_history[5][2] = {{"Mactan", "Cebu"},
 								 {"Netherlands", "Denmark"},
 								 {"He cut it", "He dropped it in water"},
 								 {"NUTS!", "We don't speak German"},
 								 {"5'6\"", "5'4\""}};

 int hAns[5] = {2, 3, 0, 1, 2};
 int hAns2[5] = {1, 2, 0, 1, 1};
 int hAns3[5] = {0, 1, 0, 0, 0};
 
 string questions_geography[5] = 
 {"How many countries are there in Southeast Asia?",
 "How many oceans are there?",
 "In which country is the Amazon Rainforest located?",
 "Which country has the largest border with France?",
 "Which country is pretty much all ice?"};
 
 string fOptions_geography[5][4] = {
 {"11", "12", "10", "13"},
 {"5", "4", "6", "7"},
 {"Brazil", "Algeria", "Argentina", "Kenya"},
 {"Spain", "Monaco", "Brazil", "Suriname"},
 {"Iceland", "Greenland", "Antarctica", "Finland"}};
 string sOptions_geography[5][3] = {
 {"11", "12", "10"},
 {"5", "4", "6"},
 {"Brazil", "Algeria", "Argentina"},
 {"Monaco", "Brazil", "Suriname"},
 {"Iceland", "Greenland", "Finland"}};
 string lOptions_geography[5][2] = {
 {"11", "12"},
 {"5", "4"},
 {"Brazil", "Peru"},
 {"Suriname", "Brazil"},
 {"Finland", "Greenland"}};
 
 int gAns[5] = {0, 0, 0, 2, 1};
 int gAns2[5] = {0, 0, 0, 1, 1};
 int gAns3[5] = {0, 0, 0, 1, 1};
 
 string questions_memes[5] = 
 {"What is 9 + 10?", 
 "What is the name of the Hawk Tuah Girl?", 
 "Why did MoistCritikal scream \"WOOOOO YEAH BABY! THAT'S WHAT I'VE BEEN WAITING FOR! THAT'S WHAT IT'S ALL ABOUT\"",
 "Who said \"EMOTIONAL DAMAGE\"", 
 "What is the name of the song used in Coffin Dance?"};
 
 string fOptions_memes[5][4] = {{"21", "19", "17", "Lster"},
 {"Abby Victoria", "Hannah Meadows", "Hailey Welch", "Linda Barbara"},
 {"He set the speedrun record for the game 'Mr. Krabs Overdoses on Ketamine and Dies", "A toy unicorn was ready to poop out slime", "He checkmated xQc in 6 moves", "Terrorists have infiltrated a local Burger King"},
 {"Uncle Roger", "Ricegum", "Steven He", "Jackie Chan"},
 {"Astronomia", "Levels", "Unity", "Bangarang"}};
 string sOptions_memes[5][3] = {{"21", "19", "17"},
 {"Abby Victoria", "Hannah Meadows", "Hailey Welch"},
 {"A toy unicorn was ready to poop out slime", "He checkmated xQc in 6 moves", "Terrorists infiltrated a local Burger King"},
 {"Uncle Roger", "Steven He", "Jackie Chan"},
 {"Astronomia", "Levels", "Unity"}};
 string lOptions_memes[5][2] = {{"21", "17"},
 {"Hannah Meadows", "Hailey Welch"},
 {"A toy unicorn was ready to poop out slime", "He checkmated xQc in 6 moves"},
 {"Uncle Roger", "Steven He"},
 {"Astronomia", "Levels"}};
 
 int mAns[5] = {0, 2, 1, 2, 0};
 int mAns2[5] = {0, 2, 0, 1, 0};
 int mAns3[5] = {0, 1, 0, 1, 0};

 string questions_science[5] = 
 {"What is a quark?", 
 "What is the boiling point of milk?", 
 "How many bones are in the human body?",
 "Which was invented first?", 
 "Which of these did Sir Isaac Newton not discover or invent?"};
 
 string fOptions_science[5][4] = {{"Stephen Hawking's Favorite Breakfast", "When a dog queefs and barks at the same time", "A particle with neither postive nor electric charge", "Particles believed to be among the fundamental constitutions of matter"},
 {"100 Degrees", "112 Degrees", "160 Degrees", "127 Degrees"},
 {"272", "206", "116", "249"},
 {"Radio", "Vacuum Cleaner", "Ballpoint Pen", "Refrigerator"},
 {"Laws of Motion", "Theory of Colors/Nature of White Light", "Theory of General Relativity", "Reflecting Telescope"}};
 string sOptions_science[5][3] = {{"When a dog queefs and barks at the same time", "A particle with neither postive nor electric charge", "Particles believed to be among the fundamental constitutions of matter"},
 {"100 Degrees", "112 Degrees", "127 Degrees"},
 {"272", "206", "249"},
 {"Radio", "Vacuum Cleaner", "Ballpoint Pen"},
 {"Theory of Colors/Nature of White Light", "Theory of General Relativity", "Reflecting Telescope"}};
 string lOptions_science[5][2] = {{"A particle with neither postive nor electric charge", "Particles believed to be among the fundamental constitutions of matter"},
 {"100 Degrees", "127 Degrees"},
 {"272", "206",},
 {"Radio", "Ballpoint Pen"},
 {"Theory of General Relativity", "Reflecting Telescope"}};
 
 int sAns[5] = {3, 0, 1, 2, 2};
 int sAns2[5] = {2, 0, 1, 2, 1};
 int sAns3[5] = {1, 0, 1, 1, 0};
 
 string questions_gknowledge[5] = 
 {"Which of these are written by William Shakespeare", 
 "Which movie is at the top of box office?", 
 "Which NBA Team won the 2023-24 Playoffs?", 
 "Which is the longest-running Philippine TV Show", 
 "What is the most played Mobile Game of all Time"};
 
 string fOptions_gknowledge[5][4] = {{"A Midsummer Night's Dream", "The Tell-Tale Heart", "The Seagull", "This Book Loves You"},
 {"Avatar", "Avengers: Endgame", "Titanic", "Star Wars: The Force Awakens"},
 {"Dallas Mavericks", "Boston Celtics", "Denver Nuggets", "Golden State Warriors"},
 {"The World Tonight", "Eat Bulaga!", "Ang Dating Daan", "TV Patrol"},
 {"Call of Duty: Mobile", "Candy Crush Saga", "Genshin Impact", "Clash of Clans"}};
 string sOptions_gknowledge[5][3] = {{"A Midsummer Night's Dream", "The Tell-Tale Heart", "This Book Loves You"},
 {"Avatar", "Avengers: Endgame", "Titanic",},
 {"Dallas Mavericks", "Boston Celtics", "Denver Nuggets"},
 {"The World Tonight", "Eat Bulaga!", "TV Patrol"},
 {"Call of Duty: Mobile", "Candy Crush Saga", "Clash of Clans"}};
 string lOptions_gknowledge[5][2] = {{"A Midsummer Night's Dream", "The Tell-Tale Heart"},
 {"Avatar", "Avengers: Endgame"},
 {"Dallas Mavericks", "Boston Celtics"},
 {"The World Tonight", "TV Patrol"},
 {"Call of Duty: Mobile", "Candy Crush Saga"}};
 
 int kAns[5] = {0, 0, 1, 0, 1};
 int kAns2[5] = {0, 0, 1, 0, 1};
 int kAns3[5] = {0, 0, 1, 0, 1};
 
 string questions_gaming[5] = 
 {"Which of these is not a Gameboy?", 
 "What installation of the Call of Duty Franchise was Modern Warfare?", 
 "When was GTA 6 announced?", 
 "When was Minecraft released?", 
 "Which of these games came first?"};
 
 string fOptions_gaming[5][4] = {{"Advance", "Elite", "Micro", "Color"},
 {"3rd", "4th", "6th", "8th"},
 {"February 4, 2022", "November 16, 2023", "October 10, 2022", "September 11, 2021"},
 {"2006", "2007", "2008", "2009"},
 {"Wii Sports", "Portal", "Garry's Mod", "GTA: San Andreas"}};
 string sOptions_gaming[5][3] = {{"Elite", "Micro", "Color"},
 {"3rd", "4th", "6th"},
 {"February 4, 2022", "October 10, 2022", "September 11, 2021"},
 {"2007", "2008", "2009"},
 {"Wii Sports", "Portal", "GTA: San Andreas"}};
 string lOptions_gaming[5][2] = {{"Elite", "Micro"},
 {"4th", "6th"},
 {"February 4, 2022", "October 10, 2022"},
 {"2008", "2009"},
 {"Wii Sports", "GTA: San Andreas"}};
 
 int gaAns[5] = {1, 0, 0, 3, 3};
 int gaAns2[5] = {0, 1, 0, 2, 2};
 int gaAns3[5] = {0, 0, 0, 1, 1};
 
 string questions_music[5] = 
 {"Which is the most played song of all time on Spotify?", 
 "Which of these is the highest selling Album of all time?", 
 "Who has the most monthly listeners on Spotify?", 
 "Which of these is a Kanye West album?",
 "Who sang the hit song 'Thick of It'?"};
 
 string fOptions_music[5][4] = {{"God's Plan", "Shape of You", "Blinding Lights", "Not Like Us"},
 {"Thriller", "Views", "1989", "Abbey Road"},
 {"The Weeknd", "Taylor Swift", "Drake", "Bruno Mars"},
 {"808s & Heart Break", "Nothing Was The Same", "Relapse", "To Pimp A Butterfly"},
 {"Knowledge, Strength and Integrity", "Drake", "Nicki Minaj", "Joji"}};
 string sOptions_music[5][3] = {{"God's Plan", "Shape of You", "Blinding Lights"},
 {"Thriller", "Views", "Abbey Road"},
 {"The Weeknd", "Drake", "Bruno Mars"},
 {"808s & Heart Break", "Nothing Was The Same", "To Pimp A Butterfly"},
 {"Knowledge, Strength and Integrity", "Drake", "Nicki Minaj"}};
 string lOptions_music[5][2] = {{"Shape of You", "Blinding Lights"},
 {"Thriller", "Abbey Road"},
 {"Drake", "Bruno Mars"},
 {"808s & Heart Break", "Nothing Was The Same"},
 {"Knowledge, Strength and Integrity", "Nicki Minaj"}};
 
 int muAns[5] = {2, 0, 3, 0, 0};
 int muAns2[5] = {2, 0, 2, 0, 0};
 int muAns3[5] = {1, 0, 1, 0, 0};
 
 string questions_sports[5] = 
 {"Which Football Club won the 2024-25 UEFA Champions League?", 
 "How many points did Team USA score in the 2024 Basketball Olympics Final?", 
 "Who was the Turkish Olympian that became popular in the 2024 Olympics", 
 "By number of Fans, which of these Sports is the most popular?", 
 "Who broke the Premier League record for most goals scored (35) in a single season?"};
 
 string fOptions_sports[5][4] = {
 {"Borussia Dortmund", "Manchester City", "Real Madrid", "Bayern Munich"},
 {"106", "98", "131", "87"},
 {"Yusuf Dikec", "Mustafa Demir", "Rachel Gunn", "Arda Guler"},
 {"Basketball", "Table Tennis", "Football", "Cricket"},
 {"Alan Shearer", "Harry Kane", "Antony", "Erling Haaland"}};
 string sOptions_sports[5][3] = {
 {"Borussia Dortmund", "Manchester City", "Real Madrid"},
 {"106", "98", "87"},
 {"Yusuf Dikec", "Mustafa Demir", "Arda Guler"},
 {"Basketball", "Table Tennis", "Football"},
 {"Alan Shearer", "Antony", "Erling Haaland"}};
 string lOptions_sports[5][2] = {
 {"Manchester City", "Real Madrid"},
 {"106", "98"},
 {"Yusuf Dikec", "Mustafa Demir"},
 {"Table Tennis", "Football"},
 {"Antony", "Erling Haaland"}};
 
 int spAns[5] = {2, 1, 0, 2, 3};
 int spAns2[5] = {2, 1, 0, 2, 2};
 int spAns3[5] = {1, 1, 0, 1, 1};
 
 char choice;
 int money = 1000000;
 int currentQuestion = 0;
 int dropMoney;
 int rQuestion;
 bool validAns;
 bool usedHistory[5] = {false};
 bool usedGeography[5] = {false};
 bool usedMemes[5] = {false};
 bool usedScience[5] = {false};
 bool usedGKnowledge[5] = {false};
 bool usedGaming[5] = {false};
 bool usedSports[5] = {false};
 bool usedMusic[5] = {false};
 
 cout << "\n=======================================================================================================================================================\n";
                                                                                                                                                                                                                                                                                                                                    
 cout << endl;
 cout << endl;
 cout << "\t\t\tThis game is based on the British gameshow 'The Million Pound Drop'\n";
 cout << "\n\t\t\t Instructions:\n";
 cout << "\n\t\t\tThe rules of the game are simple:\n";
 cout << "\t\t\tYou have a starting total money of P1,000,000.\n";
 cout << "\t\t\tYou then have to choose between two categories.\n";
 cout << "\t\t\tYou then have to answer a question.\n";
 cout << "\t\t\tIn the First round, there will be 3 questions each with 4 options.\n";
 cout << "\t\t\tIn the Second round, there will be 2 questions each with 3 options.\n";
 cout << "\t\t\tAnd in the Final round, there will be 1 question with 2 options.\n";
 cout << "\t\t\tYou can then bet your money in all the options depending on what you\n";
 cout << "\t\t\tbelieve the answer is. However, you must bet ALL of your money on the options\n";
 cout << "\t\t\tThe money you bet on the correct answer you will keep and take to the next round until\n";
 cout << "\t\t\tyou win. The money you bet on the wrong answers will get dropped and will be subtracted\n";
 cout << "\t\t\tfrom your total current money.\n";
 cout << "\n\t\tStart game? (Y/N): ";
 cin >> choice;
 system("CLS");

 if(choice == 'y' || choice == 'Y')
 {
 cout << "\n\t\t\t  ============First Round============" << endl;
 for(int i = 0; i < 3; i++)
 {
 int cat1, cat2;
 shuffleCategories(cat1, cat2);
 cout << endl;
 cout << "\t\t\t\tPick a category (1 or 2)" << endl;
 cout << "\t\t\t\t1. " << categories[cat1] << endl;
 cout << "\t\t\t\t2. " << categories[cat2] << endl;
 cout << "\t\t\t\tYour chosen category: ";
 int catChoice;
 cin >> catChoice;
 
 if(catChoice == 1)
 {
 if(cat1 == 0)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedHistory[rQuestion]);
 usedHistory[rQuestion] = true;
 validAns = askQuestion(rQuestion, questions_history[rQuestion], fOptions_history[rQuestion], hAns[rQuestion], money);
 }
 else if(cat1 == 1)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedGeography[rQuestion]);
 usedGeography[rQuestion] = true;
 validAns = askQuestion(rQuestion, questions_geography[rQuestion], fOptions_geography[rQuestion], gAns[rQuestion], money);
 }
 else if(cat1 == 2)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedMemes[rQuestion]);
 usedMemes[rQuestion] = true;
 validAns = askQuestion(rQuestion, questions_memes[rQuestion], fOptions_memes[rQuestion], mAns[rQuestion], money);
 }
 else if(cat1 == 3)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedScience[rQuestion]);
 usedScience[rQuestion] = true;
 validAns = askQuestion(rQuestion, questions_science[rQuestion], fOptions_science[rQuestion], sAns[rQuestion], money);
 }
 else if(cat1 == 4)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedGKnowledge[rQuestion]);
 usedGKnowledge[rQuestion] = true;
 validAns = askQuestion(rQuestion, questions_gknowledge[rQuestion], fOptions_gknowledge[rQuestion], kAns[rQuestion],
money);
 }
 else if(cat1 == 5)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedGaming[rQuestion]);
 usedGaming[rQuestion] = true;
 validAns = askQuestion(rQuestion, questions_gaming[rQuestion], fOptions_gaming[rQuestion], gaAns[rQuestion], money);
 }
 else if(cat1 == 6)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedMusic[rQuestion]);
 usedMusic[rQuestion] = true;
 validAns = askQuestion(rQuestion, questions_music[rQuestion], fOptions_music[rQuestion], muAns[rQuestion], money);
 }
 else
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedSports[rQuestion]);
 usedSports[rQuestion] = true;
 validAns = askQuestion(rQuestion, questions_sports[rQuestion], fOptions_sports[rQuestion], spAns[rQuestion], money);
 }
 }
 else
 {
 if(cat2 == 0)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedHistory[rQuestion]);

 usedHistory[rQuestion] = true;
 validAns = askQuestion(rQuestion, questions_history[rQuestion], fOptions_history[rQuestion], hAns[rQuestion], money);
 }
 else if(cat2 == 1)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedGeography[rQuestion]);
 usedGeography[rQuestion] = true;
 validAns = askQuestion(rQuestion, questions_geography[rQuestion], fOptions_geography[rQuestion], gAns[rQuestion], money);
 }
 else if(cat2 == 2)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedMemes[rQuestion]);
 usedMemes[rQuestion] = true;
 validAns = askQuestion(rQuestion, questions_memes[rQuestion], fOptions_memes[rQuestion], mAns[rQuestion], money);
 }
 else if(cat2 == 3)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedScience[rQuestion]);
 usedScience[rQuestion] = true;
 validAns = askQuestion(rQuestion, questions_science[rQuestion], fOptions_science[rQuestion], sAns[rQuestion], money);
 }
 else if(cat2 == 4)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedGKnowledge[rQuestion]);
 usedGKnowledge[rQuestion] = true;
 validAns = askQuestion(rQuestion, questions_gknowledge[rQuestion], fOptions_gknowledge[rQuestion], kAns[rQuestion],
money);
 }
 else if(cat2 == 5)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedGaming[rQuestion]);
 usedGaming[rQuestion] = true;
 validAns = askQuestion(rQuestion, questions_gaming[rQuestion], fOptions_gaming[rQuestion], gaAns[rQuestion], money);
 }
 else if(cat2 == 6)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedMusic[rQuestion]);
 usedMusic[rQuestion] = true;
 validAns = askQuestion(rQuestion, questions_music[rQuestion], fOptions_music[rQuestion], muAns[rQuestion], money);
 }
 else
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedSports[rQuestion]);
 usedSports[rQuestion] = true;
 validAns = askQuestion(rQuestion, questions_sports[rQuestion], fOptions_sports[rQuestion], spAns[rQuestion], money);
 }
 }
 if(money <= 0)
 {
 cout << endl;
 cout << "\n\tGame Over! You lost all your money." << endl;
 return 0;
 }
 }
 cout << "\n\t\t\t\t============================================================================================\n";
 cout << "\t\t\t\t\tAnd that is the end of the first round!\n" << endl;
 cout << "\t\t\t\t\tBefore we proceed to the second round...\n" << endl;
 cout << "\t\t\t\t\tLet us first play a minigame!\n" << endl;
 cout << endl;
 cout << "\t\t\t\t\tPress enter to proceed: ";
 string proceed;
 cin >> proceed;
 if(proceed == " ")
 {
 	minigame(money);
 }
 cout << "\n\t\t\t ============Second Round============" << endl;
 for(int i = 0; i < 2; i++)
 {
 int cat1, cat2;
 shuffleCategories(cat1, cat2);
 cout << endl;
 cout << "\t\t\t\tPick a category (1 or 2)" << endl;
 cout << "\t\t\t\t1. " << categories[cat1] << endl;
 cout << "\t\t\t\t2. " << categories[cat2] << endl;
 cout << "\t\t\t\tYour chosen category: ";
 int catChoice;
 cin >> catChoice;
 if(catChoice == 1)
 {
 if(cat1 == 0)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedHistory[rQuestion]);

 usedHistory[rQuestion] = true;
 validAns = askQuestionTwo(rQuestion, questions_history[rQuestion], sOptions_history[rQuestion], hAns2[rQuestion], money);
 }
 else if(cat1 == 1)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedGeography[rQuestion]);
 usedGeography[rQuestion] = true;
 validAns = askQuestionTwo(rQuestion, questions_geography[rQuestion], sOptions_geography[rQuestion], gAns2[rQuestion],
money);
 }
 else if(cat1 == 2)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedMemes[rQuestion]);
 usedMemes[rQuestion] = true;
 validAns = askQuestionTwo(rQuestion, questions_memes[rQuestion], sOptions_memes[rQuestion], mAns2[rQuestion], money);
 }
 else if(cat1 == 3)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedScience[rQuestion]);
 usedScience[rQuestion] = true;
 validAns = askQuestionTwo(rQuestion, questions_science[rQuestion], sOptions_science[rQuestion], sAns2[rQuestion], money);
 }
 else if(cat1 == 4)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedGKnowledge[rQuestion]);
 usedGKnowledge[rQuestion] = true;
 validAns = askQuestionTwo(rQuestion, questions_gknowledge[rQuestion], sOptions_gknowledge[rQuestion], kAns2[rQuestion],
money);
 }
 else if(cat1 == 5)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedGaming[rQuestion]);
 usedGaming[rQuestion] = true;
 validAns = askQuestionTwo(rQuestion, questions_gaming[rQuestion], sOptions_gaming[rQuestion], gaAns2[rQuestion],
money);
 }
 else if(cat1 == 6)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedMusic[rQuestion]);
 usedMusic[rQuestion] = true;
 validAns = askQuestionTwo(rQuestion, questions_music[rQuestion], sOptions_music[rQuestion], muAns2[rQuestion], money);
 }
 else
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedSports[rQuestion]);
 usedSports[rQuestion] = true;
 validAns = askQuestionTwo(rQuestion, questions_sports[rQuestion], sOptions_sports[rQuestion], spAns2[rQuestion], money);
 }
 }
 else
 {
 if(cat2 == 0)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedHistory[rQuestion]);

 usedHistory[rQuestion] = true;
 validAns = askQuestion(rQuestion, questions_history[rQuestion], sOptions_history[rQuestion], hAns2[rQuestion], money);
 }
 else if(cat2 == 1)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedGeography[rQuestion]);
 usedGeography[rQuestion] = true;
 validAns = askQuestionTwo(rQuestion, questions_geography[rQuestion], sOptions_geography[rQuestion], gAns2[rQuestion],
money);
 }
 else if(cat2 == 2)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedMemes[rQuestion]);
 usedMemes[rQuestion] = true;
 validAns = askQuestionTwo(rQuestion, questions_memes[rQuestion], sOptions_memes[rQuestion], mAns2[rQuestion], money);
 }
 else if(cat2 == 3)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedScience[rQuestion]);
 usedScience[rQuestion] = true;
 validAns = askQuestionTwo(rQuestion, questions_science[rQuestion], sOptions_science[rQuestion], sAns2[rQuestion], money);
 }
 else if(cat2 == 4)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedGKnowledge[rQuestion]);
 usedGKnowledge[rQuestion] = true;
 validAns = askQuestionTwo(rQuestion, questions_gknowledge[rQuestion], sOptions_gknowledge[rQuestion], kAns2[rQuestion],
money);
 }
 else if(cat2 == 5)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedGaming[rQuestion]);
 usedGaming[rQuestion] = true;
 validAns = askQuestionTwo(rQuestion, questions_gaming[rQuestion], sOptions_gaming[rQuestion], gaAns2[rQuestion],
money);
 }
 else if(cat2 == 6)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedMusic[rQuestion]);
 usedMusic[rQuestion] = true;
 validAns = askQuestionTwo(rQuestion, questions_music[rQuestion], sOptions_music[rQuestion], muAns2[rQuestion], money);
 }
 else
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedSports[rQuestion]);
 usedSports[rQuestion] = true;
 validAns = askQuestionTwo(rQuestion, questions_sports[rQuestion], sOptions_sports[rQuestion], spAns2[rQuestion], money);
 }
 }
 if(money <= 0)
 {
 cout << endl;
 cout << "\n\tGame Over! You lost all your money." << endl;
 return 0;
 }
 }
cout << "\n\t\t\t\t============================================================================================\n";
 cout << "\n\t\t\t\t\tCongratulations on making it past the second round!\n";
 cout << "\t\t\t\t\tAnd once again! before we proceed to the final round where you could get to keep P" << money << "...\n";
 cout << "\t\t\t\t\tWe shall do one more minigame to increase your possible winnings!\n";
 cout << endl;
 cout << "\t\t\t\t\tPress enter to proceed: ";
 cin >> proceed;
 if(proceed == " ")
 {
 	minigame_two(money);
 }
 cout << "\n\t\t\t  ============Final Round============" << endl;
 for(int i = 0; i < 1; i++)
 {
 int cat1, cat2;
 shuffleCategories(cat1, cat2);
 cout << "\t\t\t\tFinal round" << endl;
 cout << "\t\t\t\tPick a category (1 or 2)" << endl;
 cout << "\t\t\t\t1. " << categories[cat1] << endl;
 cout << "\t\t\t\t2. " << categories[cat2] << endl;
 cout << "\t\t\t\tYour chosen category: ";
 int catChoice;
 cin >> catChoice;
 if(catChoice == 1)
 {
 if(cat1 == 0)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedHistory[rQuestion]);

 usedHistory[rQuestion] = true;
 validAns = askQuestionThree(rQuestion, questions_history[rQuestion], lOptions_history[rQuestion], hAns3[rQuestion], money);
 }
 else if(cat1 == 1)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedGeography[rQuestion]);
 usedGeography[rQuestion] = true;
 validAns = askQuestionThree(rQuestion, questions_geography[rQuestion], lOptions_geography[rQuestion], gAns3[rQuestion],
money);
 }
 else if(cat1 == 2)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedMemes[rQuestion]);
 usedMemes[rQuestion] = true;
 validAns = askQuestionThree(rQuestion, questions_memes[rQuestion], lOptions_memes[rQuestion], mAns3[rQuestion],
money);
 }
 else if(cat1 == 3)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedScience[rQuestion]);
 usedScience[rQuestion] = true;
 validAns = askQuestionThree(rQuestion, questions_science[rQuestion], lOptions_science[rQuestion], sAns3[rQuestion],
money);
 }
 else if(cat1 == 4)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedGKnowledge[rQuestion]);
 usedGKnowledge[rQuestion] = true;
 validAns = askQuestionThree(rQuestion, questions_gknowledge[rQuestion], lOptions_gknowledge[rQuestion],
kAns3[rQuestion], money);
 }
 else if(cat1 == 5)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedGaming[rQuestion]);
 usedGaming[rQuestion] = true;
 validAns = askQuestionThree(rQuestion, questions_gaming[rQuestion], lOptions_gaming[rQuestion], gaAns3[rQuestion],
money);
 }
 else if(cat1 == 6)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedMusic[rQuestion]);
 usedMusic[rQuestion] = true;
 validAns = askQuestionThree(rQuestion, questions_music[rQuestion], lOptions_music[rQuestion], muAns3[rQuestion], money);
 }
 else
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedSports[rQuestion]);
 usedSports[rQuestion] = true;
 validAns = askQuestionThree(rQuestion, questions_sports[rQuestion], lOptions_sports[rQuestion], spAns3[rQuestion], money);
 }
 }
 else
 {
 if(cat2 == 0)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedHistory[rQuestion]);

 usedHistory[rQuestion] = true;
 validAns = askQuestionThree(rQuestion, questions_history[rQuestion], lOptions_history[rQuestion], hAns3[rQuestion], money);
 }
 else if(cat2 == 1)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedGeography[rQuestion]);
 usedGeography[rQuestion] = true;
 validAns = askQuestionThree(rQuestion, questions_geography[rQuestion], lOptions_geography[rQuestion], gAns3[rQuestion],
money);
 }
 else if(cat2 == 2)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedMemes[rQuestion]);
 usedMemes[rQuestion] = true;
 validAns = askQuestionThree(rQuestion, questions_memes[rQuestion], lOptions_memes[rQuestion], mAns3[rQuestion],
money);
 }
 else if(cat2 == 3)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedScience[rQuestion]);
 usedScience[rQuestion] = true;
 validAns = askQuestionThree(rQuestion, questions_science[rQuestion], lOptions_science[rQuestion], sAns3[rQuestion],
money);
 }
 else if(cat2 == 4)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedGKnowledge[rQuestion]);
 usedGKnowledge[rQuestion] = true;
 validAns = askQuestionThree(rQuestion, questions_gknowledge[rQuestion], lOptions_gknowledge[rQuestion],
kAns3[rQuestion], money);
 }
 else if(cat2 == 5)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedGaming[rQuestion]);
 usedGaming[rQuestion] = true;
 validAns = askQuestionThree(rQuestion, questions_gaming[rQuestion], lOptions_gaming[rQuestion], gaAns3[rQuestion],
money);
 }
 else if(cat2 == 6)
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedMusic[rQuestion]);
 usedMusic[rQuestion] = true;
 validAns = askQuestionThree(rQuestion, questions_music[rQuestion], lOptions_music[rQuestion], muAns3[rQuestion], money);
 }
 else
 {
 do{
 shuffleQuestion(rQuestion);
 }while(usedSports[rQuestion]);
 usedSports[rQuestion] = true;
 validAns = askQuestionThree(rQuestion, questions_sports[rQuestion], lOptions_sports[rQuestion], spAns3[rQuestion], money);
 }
 }
 if(money <= 0)
 {
 cout << endl;
 cout << "\n\t\t\t\t\tGame Over! You lost all your money." << endl;
 return 0;
 }
 }
 
 if(money > 0)
 {
 cout << "\n\t\t\t\tCONGRATULATIONS! You won the Million Peso Drop!" << endl;
 cout << "Your total winnings are: " << money << endl;
 }
 
 }
 else if(choice == 'n' || choice == 'N')
 {
 	cout << endl;
 	cout << "\t\t\t\t\tCome back soon!";
 }
 else
 {
 	cout << endl;
 	cout << "\t\t\t\t\tInvalid input!";
 }

 return 0;
}


