#include "Point2D.h"
#include "View.h"
#include "Model.h"
#include "GameCommand.h"
#include "Input_Handling.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <fstream>

using namespace std;

//Function prototypes
bool IsNumber(string s);
bool IsWhiteSpace(string s);

const string POKEMON_BANNER = "                                  ,'\\\n"
                              "    _.----.        ____         ,'  _\\   ___    ___     ____\n"
                              "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.\n"
                              "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |\n"
                              " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |\n"
                              "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |\n"
                              "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |\n"
                              "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |\n"
                              "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |\n"
                              "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |\n"
                              "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |\n"
                              "                                `'                            '-._|";
// TODO: Add help menu
int main(int argc, char** argv) 
{
    // Welcome Message
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2019" << endl;
    cout << "Programming Assignment 3" << endl;
    cout << POKEMON_BANNER << endl;
    
    Model game_model;
    View game_view;

    bool game_is_running = true;
	char command = 0;
	char type = 0;
	double x;
	double y;
	int id;
	int id2;
	unsigned int stamina_amount;
	unsigned int unit_amount;
    bool read_from_file = false;
    game_model.ShowStatus();
    game_model.Display(game_view);
    ifstream input_file;
   
	while (command != 'q')
	{
		cout << "Enter Command: ";

		cin >> command;

		try {
			switch (command)
			{
			case 'm':
			{
				if (!(cin >> id))
				{
					throw Invalid_Input("Expected an integer for Pokemon ID");
				}

				if (!(cin >> x))
				{
					throw Invalid_Input("Expected a double for x coordinate");
				}

				if (!(cin >> y))
				{
					throw Invalid_Input("Expected a double for y coordinate");
				}

				DoMoveCommand(model, id, Point2D(x, y));
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}

			case 'g':
			{
				if (!(cin >> id))
				{
					throw Invalid_Input("Expected an integer for Pokemon ID");
				}
				if (!(cin >> id2))
				{
					throw Invalid_Input("Expected an integer for Gym ID");
				}
				DoMoveToGymCommand(model, id, id2);
				game_model.Display(game_view);
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}

			case 'c':
			{
				if (!(cin >> id))
				{
					throw Invalid_Input("Expected an integer for Pokemon ID");
				}
				if (!(cin >> id2))
				{
					throw Invalid_Input("Expected an integer for Gym ID");
				}
				DoMoveToCenterCommand(model, id, id2);
				game_model.Display(game_view);
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}

			case 's':
			{
				if (!(cin >> id))
				{
					throw Invalid_Input("Expected an integer for Pokemon ID");
				}
				DoStopCommand(model, id);
				game_model.Display(game_view);
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}

			case 'r':
			{
				if (!(cin >> id))
				{
					throw Invalid_Input("Expected an integer for Pokemon ID");
				}
				if (!(cin >> stamina_amount))
				{
					throw Invalid_Input("Expected an unsigned integer for stamina amount");
				}
				DoRecoverInCenterCommand(model, id, stamina_amount);
				game_model.Display(game_view);
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}

			case 't':
			{
				if (!(cin >> id))
				{
					throw Invalid_Input("Expected an integer for Pokemon ID");
				}
				if (!(cin >> unit_amount))
				{
					throw Invalid_Input("Expected an unsigned integer for Training Unit Amount");
				}
				DoTrainInGymCommand(model, id, unit_amount);
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}

			case 'v':
			{
				DoGoCommand(model, view);
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}

			case 'x':
			{
				DoRunCommand(model, view);
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}

			case 'q':
			{
				break;
			}

			case 'b':
			{
				if (!(cin >> id))
				{
					throw Invalid_Input("Expected an integer for Pokemon ID");
				}
				if (!(cin >> id2))
				{
					throw Invalid_Input("Expected an integer for Rival ID");
				}
				DoBattleInArenaCommand(model, id, id2);
				game_model.Display(game_view);
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}

			case 'a':
			{
				if (!(cin >> id))
				{
					throw Invalid_Input("Expected an integer for Pokemon ID");
				}
				if (!(cin >> id2))
				{
					throw Invalid_Input("Expected an integer for Battle Arena ID");
				}

				DoMoveToArenaCommand(model, id, id2);
				game_model.Display(game_view);
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}

			case 'n':
			{
				if (!(cin >> type))
				{
					throw Invalid_Input("Expected a char for display code");
				}
				if (!(cin >> id1))
				{
					throw Invalid_Input("Expected an int for the ID #");
				}
				if (!(cin >> x))
				{
					throw Invalid_Input("Expected a double for x coordinate");
				}

				if (!(cin >> y))
				{
					throw Invalid_Input("Expected a double for y coordinate");
				}

				if (x > 20 || x < 0 || y < 0 || y > 20)
				{
					throw Invalid_Input("Make sure object is within the plotting boundary range");
				}

				model.NewCommand(type, id, x, y);
				game_model.Display(game_view);
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}

			default:
			{
				throw Invalid_Input("Please enter a valid command code");
				break;
			}
			}
		}



		catch (Invalid_Input & except)
		{
			cout << "Invalid input - " << except.msg_ptr << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}

	}


	return 0;
}




bool IsNumber(string s){
    for(int i = 0; i < s.length(); i++) {
        if(!(s[i] >= '0' && s[i] <= '9')) {
            return false;
        }
    }
    return true;
}

bool IsWhiteSpace(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ' && s[i] != '\t') {
            return false;
        }
    }
    return true;
}

