#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"

using namespace std;

PokemonCenter :: PokemonCenter() 
:Building('C'), potion_capacity(100), num_potions_remaining(potion_capacity), pokedollar_cost_per_potion(5) {
  GameObject :: setState(PokemonCenterStates(POTIONS_AVAILABLE));
  cout << "PokemonCenter default constructed" << endl;
}

PokemonCenter :: PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc)
:Building('C', in_id, in_loc), pokedollar_cost_per_potion(potion_cost), potion_capacity(potion_cap), num_potions_remaining(potion_capacity)  {
  GameObject :: setState(PokemonCenterStates(POTIONS_AVAILABLE));
  cout << "PokemonCenter constructed" << endl;
}

PokemonCenter :: ~PokemonCenter()  {  cout << "PokemonCenter destructed" << endl;  };

bool PokemonCenter :: HasPotions()  {
  if (num_potions_remaining > 0)
    return true;
  return false;
}

unsigned int PokemonCenter :: GetNumPotionRemaining() const   {
  return num_potions_remaining;
}

bool PokemonCenter :: CanAffordPotion(unsigned int potion, double budget)  {
  if (budget >= (potion * pokedollar_cost_per_potion))
    return true;
  return false;
}

double PokemonCenter :: GetPokeDollarCost(unsigned int potion)  {
  return (potion * pokedollar_cost_per_potion);
}

unsigned int PokemonCenter :: DistributePotion(unsigned int potion_needed)  {
  if (num_potions_remaining >= potion_needed)  {
    num_potions_remaining -= potion_needed;
    return potion_needed;
  }
  unsigned int tempPotionRemain = num_potions_remaining;
  num_potions_remaining = 0;
  return tempPotionRemain;
}

bool PokemonCenter :: Update()  {
  if (num_potions_remaining == 0)  {
    GameObject :: setState(PokemonCenterStates(NO_POTIONS_AVAILABLE));
    GameObject :: setDisplayCode('c');
    cout << "PokemonCenter " << id_num << " has ran out of potions." << endl;
    return true;
  }
  return false;
}

void PokemonCenter :: ShowStatus()  {
  cout << "PokemonCenter Status: " << endl;
  Building :: ShowStatus();
  cout << "PokeDollars per potion: " << pokedollar_cost_per_potion << endl;
  cout << "has " << num_potions_remaining << " potion(s) remaining." << endl;
}