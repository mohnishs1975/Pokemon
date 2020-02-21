#include "Model.h"
#include "Point2D.h"
#include "Model.h"
#include "GameObject.h"
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Input_Handling.h"
#include "Rival.h"
#include "View.h"
#include "Building.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <list>
#include <iterator>

Model::Model() {
    time = 0;
    //Pikachu 1

    //pokemon_ptrs[0] = new Pokemon("Pikachu", 1, 'P', 2.0, Point2D(5, 1));
	Point2D* P = new Point2D(5, 1);
	Pokemon* Pokemonptr = new Pokemon("Pikachu",1,6,3,23,12,'P',2,*P);
    //object_ptrs[0] = pokemon_ptrs[0];
	pokemon_ptrs.push_back(Pokemonptr);
	object_ptrs.push_back(Pokemonptr);
	active_ptrs.push_back(Pokemonptr);

    //Pikachu 2

    //pokemon_ptrs[1] = new Pokemon("Bulbasaur", 2, 'P', 1.0, Point2D(10, 1));
    //object_ptrs[1] = pokemon_ptrs[1];
	Point2D* P1 = new Point2D(10, 1);
	Pokemon* Pokemonptr2 = new Pokemon("Bulbasaur", 2, 3.7, 4, 26, 16, 'P', 1, *P1);
	pokemon_ptrs.push_back(Pokemonptr2);
	object_ptrs.push_back(Pokemonptr2);
	active_ptrs.push_back(Pokemonptr2);

    //PokemonCenter 1

    //center_ptrs[0] = new PokemonCenter(1, 1, 100, Point2D(1, 20));
    //object_ptrs[2] = center_ptrs[0];
	Point2D* P2 = new Point2D(1, 20);
	PokemonCenter* PokemonCenterptr = new PokemonCenter(1, 1, 100, *P2);
	center_ptrs.push_back(PokemonCenterptr);
	object_ptrs.push_back(PokemonCenterptr);
	active_ptrs.push_back(PokemonCenterptr);

    //PokemonCenter 2

    //center_ptrs[1] = new PokemonCenter(2, 2, 200,  Point2D(10, 20));
    //object_ptrs[3] = center_ptrs[1];
	Point2D* P3 = new Point2D(10,20);
    PokemonCenter* PokemonCenterptr2 = new PokemonCenter(2,2,200, *P3);
    center_ptrs.push_back(PokemonCenterptr2);
    object_ptrs.push_back(PokemonCenterptr2);
    active_ptrs.push_back(PokemonCenterptr2);

    //PokemonGym 1

    //gym_ptrs[0] = new PokemonGym(10, 1.0, 2.0, 3, 1, Point2D(0, 0));
    //object_ptrs[4] = gym_ptrs[0];
	PokemonGym* PokemonGymptr = new PokemonGym();
	gym_ptrs.push_back(PokemonGymptr);
	object_ptrs.push_back(PokemonGymptr);
	active_ptrs.push_back(PokemonGymptr);

	//PokemonGym 2

	PokemonGym* PokemonGymptr2 = new PokemonGym();
	gym_ptrs.push_back(PokemonGymptr2);
	object_ptrs.push_back(PokemonGymptr2);
	active_ptrs.push_back(PokemonGymptr2);

    //gym_ptrs[1] = new PokemonGym(20, 5, 7.5, 8, 2, Point2D(5, 5));
    //object_ptrs[5] = gym_ptrs[1];
	Point2D* P4 = new Point2D(5, 5);
	PokemonGym* PokemonGymptr2 = new PokemonGym(20, 5, 7.5, 8, 2, *P4);
	gym_ptrs.push_back(PokemonGymptr2);
	object_ptrs.push_back(PokemonGymptr2);
	active_ptrs.push_back(PokemonGymptr2);

	//Rival

	// rival_ptrs[0] = new Rival("Lugia",1,16,3,7.2,12,1,Point2D(15,12));
	// object_ptrs[6] = rival_ptrs[0];
	Rival* R = new Rival("Lugia", 1, 16, 3, 7.2, 12, 1, Point2D(15, 12));
	Rival* R2 = new Rival("Snorlax", 5, 29, 5, 4, 20, 1, b1);
	Rival* R3 = new Rival("Arceus", 2, 50, 6, 5, 5, 2, b1);

	rival_ptrs.push_back(R);
	object_ptrs.push_back(R);
	active_ptrs.push_back(R);

	rival_ptrs.push_back(R2);
	object_ptrs.push_back(R2);
	active_ptrs.push_back(R2);

	rival_ptrs.push_back(R3);
	object_ptrs.push_back(R3);
	active_ptrs.push_back(R3);




	// battle_ptrs[0] = new BattleArena(3,3,2.5,1,Point2D(15,12));
	// object_ptrs[7] = battle_ptrs[0];
	BattleArena* BArena = new BattleArena(3, 3, 2.5, 1, Point2D(15, 12));
	battle_ptrs.push_back(BArena);
	object_ptrs.push_back(BArena);
	active_ptrs.push_back(BArena);



    cout << "Model default constructed. " << endl;
}

Model::~Model() 
{
	list<GameObject*> ::iterator x;
	for (x = object_ptrs.begin(); x != object_ptrs.end(); ++x) 
	{
		x = object_ptrs.erase(x);
	}
    cout << "Model destructed. " << endl;
}

Pokemon *Model::GetPokemonPtr(int id) 
{
	list<Pokemon*> ::iterator x;
	x = pokemon_ptrs.begin();
    for (int i = 1; i < id; i++) 
	{
		x++;
    }
	return *x;
}


PokemonCenter *Model::GetPokemonCenterPtr(int id) 
{
	list<PokemonCenter*>::iterator x;
	x = center_ptrs.begin();
    for (int i = 1; i < id; i++) 
	{
		x++;
    }
	return *x;
}
    


PokemonGym *Model::GetPokemonGymPtr(int id) 
{
	list<PokemonGym*>::iterator x;
	x = gym_ptrs.begin();
    for (int i = 1; i < id; i++) 
	{
		x++;
    }
    return x;
}

Rival* Model::GetRivalPtr(int id)
{
	list<Rival*> ::iterator x;
	x = rival_ptrs.begin();
	if (rival_ptrs.size() > id)
	{
		advance(x, id);
	}
	return *x;
}

BattleArena* Model::GetBattleArenaPtr(int id)
{
	list<BattleArena*> ::iterator x;
	x = arena_ptrs.begin();
	if (arena_ptrs.size() > id)
	{
		advance(x, id);
	}
	return *x;
}

bool Model::Update() 
{
    int gyms_beaten = 0;
    int pokemon_exhausted = 0;
	int arenas_beaten = 0;
	list<GameObject*>::iterator x;
	this->time++;
    //Calculating number of gyms beaten
	for (x = active_ptrs.begin(); x != active_ptrs.end(); x++) 
	{
		(*x)->Update();
		if ((*x)->ShouldBeVisible() == false) {
			x = active_ptrs.erase(x);
		}
	}

	list<PokemonGym*>::iterator iteratorGym;
	for (iteratorGym = gym_ptrs.begin(); iteratorGym != gym_ptrs.end(); ++iteratorGym) 
	{
		if ((*iteratorGym)->IsBeaten()) 
		{
			gyms_beaten++;
		}
	}

	if (gyms_beaten == gym_ptrs.size()) 
	{
		cout << "GAME OVER: You lose! All Pokemon Gyms beaten." << endl;
		exit(EXIT_FAILURE);
	}

	// Calculating number of pokemon that are tired

	list<Pokemon*>::iterator iteratorPokemon;
	for (iteratorPokemon = pokemon_ptrs.begin(); iteratorPokemon != pokemon_ptrs.end(); ++iteratorPokemon) 
	{
		if ((*iteratorPokemon)->IsExhausted()) 
		{
			pokemon_exhausted++;
		}
	}

	// Calculates Arenas beaten

	list<BattleArena*>::iterator iteratorArena;
	for (iteratorArena = arena_ptrs.begin(); iteratorArena != arena_ptrs.end(); ++iteratorArena)
	{
		if ((*iteratorArena)->IsBeaten())
		{
			arenas_beaten++;
		}
	}

	if (pokemon_exhausted == pokemon_ptrs.size()) 
	{
		cout << "GAME OVER: You lose! All of your Pokemon are tired!" << endl;
		exit(EXIT_FAILURE);
	}
}

void Model::Display(View &view) 
{
	list<GameObject*>::iterator x;
    view.Clear();
	for (x = active_ptrs.begin(); x != active_ptrs.end(); ++x) 
	{
		view.Plot(*x);
	}
    view.Draw();
}

void Model::ShowStatus() 
{
	list<GameObject*>::iterator x;
	x = object_ptrs.begin();

	for (int i = 0; i < object_ptrs.size(); i++)
	{
		(*x)->ShowStatus();
		++x;
	}
}

void Model::NewCommand(char type, int id, double x, double y) 
{
	list<PokemonGym*>::iterator iteratorGym;
	list<PokemonCenter*>::iterator iteratorCenter;
	list<Pokemon*>::iterator iteratorPokemon;
	list<Rival*>::iterator iteratorRival;
	switch (type) 
	{
		case 'g':
		{
			PokemonGym* PokeGym = new PokemonGym(10, 1, 1.0, 2, id, Point2D(x, y));
			for (iteratorGym = gym_ptrs.begin(); iteratorGym != gym_ptrs.end(); ++iteratorGym) 
			{
				if ((*iteratorGym)->GetId() == id) 
				
				{
					cout << "ID number already exists!" << endl;
					return;
				}
			}
			active_ptrs.push_back(PokeGym);
			gym_ptrs.push_back(PokeGym);
			break;
		}

		case 'c':
		{
			for (iteratorCenter = center_ptrs.begin(); iteratorCenter != center_ptrs.end(); ++iteratorCenter)
			{
				if ((*iteratorCenter)->GetId() == id)
				{
					cout << "ID number already exists!" << endl;
					return;
				}
			}
			PokemonCenter* PokeCenter = new PokemonCenter(id, 5, 100, Point2D(x, y));
			active_ptrs.push_back(PokeCenter);
			center_ptrs.push_back(PokeCenter);
			break;
		}

		case 'p':
		{
			for (iteratorPokemon = pokemon_ptrs.begin(); iteratorPokemon != pokemon_ptrs.end(); ++iteratorPokemon)
			{
				if ((*iteratorPokemon)->GetId() == id)
				{
					cout << "ID number already exists!" << endl;
					return;
				}
			}
			Pokemon* Poke = new Pokemon("Machamp", id, 4.5, 5.5, 25, 5, 'P', 2, Point2D(x, y));
			active_ptrs.push_back(Poke);
			pokemon_ptrs.push_back(Poke);
			break;
		}
	
		case 'r':
		{
			for (iteratorRival = rival_ptrs.begin(); iteratorRival != rival_ptrs.end(); ++iteratorRival)
			{
				if ((*iteratorRival)->GetId() == id)
				{
					cout << "ID number already exists!" << endl;
					return;
				}
			}
			Rival* Riv = new Rival("Red", 1.0, 20, 3, 4, 4, id, Point2D(x, y));
			active_ptrs.push_back(Riv);
			rival_ptrs.push_back(Riv);
			break;
		}
		default:
			break;
	}

}

