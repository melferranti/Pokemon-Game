#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonGym.h"

using namespace std;

PokemonGym :: PokemonGym() 
:Building('G'), max_number_of_battles(10), num_battle_remaining(max_number_of_battles), health_cost_per_battle(1), PokeDollar_cost_per_battle(1.0), experience_per_battle(2) {
  GameObject :: setState(PokemonGymStates(NOT_DEFEATED));
  cout << "PokemonGym default constructed" << endl;
}

PokemonGym :: PokemonGym(unsigned int max_battle, unsigned int health_loss, double PokeDollar_cost, unsigned int exp_per_battle, int in_id, Point2D in_loc)
:Building('G', in_id, in_loc), max_number_of_battles(max_battle), num_battle_remaining(max_number_of_battles), health_cost_per_battle(health_loss), experience_per_battle(exp_per_battle), PokeDollar_cost_per_battle(PokeDollar_cost)  {
  GameObject :: setState(PokemonGymStates(NOT_DEFEATED));
  cout << "PokemonGym constructed" << endl;
}

PokemonGym :: ~PokemonGym()  {  cout << "PokemonGym destructed" << endl;  };

double PokemonGym :: GetPokeDollarCost(unsigned int battle_qty)  {
  return (battle_qty * PokeDollar_cost_per_battle);
}

unsigned int PokemonGym :: GetHealthCost(unsigned int battle_qty)  {
  return (battle_qty * health_cost_per_battle);
}

unsigned int PokemonGym :: GetNumBattlesRemaining()  {
  return this -> num_battle_remaining;
}

bool PokemonGym :: IsAbleToBattle(unsigned int battle_qty, double budget, unsigned int health)  {
  if (PokemonGym::GetPokeDollarCost(battle_qty) <= budget && PokemonGym::GetHealthCost(battle_qty) <= health)
    return true;
  return false;
}

unsigned int PokemonGym :: TrainPokemon(unsigned int battle_units)  {
  if (this -> num_battle_remaining <= battle_units)  {
    this -> num_battle_remaining -= battle_units;
    return (battle_units * experience_per_battle);
  }
  unsigned int tempBattleRemain = this -> num_battle_remaining;
  this -> num_battle_remaining = 0;
  return (tempBattleRemain * experience_per_battle);
}

unsigned int PokemonGym :: GetExperiencePerBattle()  {
  return experience_per_battle;
}

bool PokemonGym :: Update()  {
  if (this -> num_battle_remaining == 0)  {
    GameObject :: setState(PokemonGymStates(DEFEATED));
    GameObject :: setDisplayCode('g');
    cout << display_code << id_num << " has been beaten." << endl;
    return true;
  }
  return false;
}

bool PokemonGym :: passed()  {
  if (this -> num_battle_remaining == 0)  {
    return true;
  }
  return false;
}

void PokemonGym :: ShowStatus()  {
  cout << "PokemonGym Status: " << endl;
  Building :: ShowStatus();
  cout << "Max number of battles: " << max_number_of_battles << endl;
  cout << "Health cost per battle: " << health_cost_per_battle << endl;
  cout << "PokeDollar per battle: " << PokeDollar_cost_per_battle << endl;
  cout << "Experience per battle: " << experience_per_battle << endl;
  cout << num_battle_remaining << " battle(s) are remaining for this PokemonGym" << endl;
}