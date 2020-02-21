#ifndef MODEL_H
#define MODEL_H
#include "GameObject.h"
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "View.h"
#include "BattleArena.h"
#include <list>
#include <iterator>

class Model 
{
    
public:
	int time;
	list <GameObject*> object_ptrs;
	list <GameObject*> active_ptrs;
	list <Pokemon*> pokemon_ptrs;
	list <PokemonCenter*> center_ptr;
	list <PokemonGym*> gym_ptrs;
	list <BattleArena*> arena_ptrs;
	list <Rival*> rival_ptrs;
    
public:
    Model();
    ~Model();
    Pokemon* GetPokemonPtr(int id);
    PokemonCenter* GetPokemonCenterPtr(int id);
    PokemonGym* GetPokemonGymPtr(int id);
    bool Update();
    void Display(View &view);
    void ShowStatus();
	void NewCommand(char type, int id, double x, double y);
};


#endif
