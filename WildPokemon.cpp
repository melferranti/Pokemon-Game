#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "Model.h"

WildPokemon :: WildPokemon(string in_name, double in_attack, double in_health, bool in_variant, int in_id, Point2D in_loc)
:GameObject(in_loc, in_id, 'W')  {
  name = in_name;
  attack = in_attack;
  health = in_health;  
  variant = in_variant; 
  state = IN_ENVIRONMENT;
  cout << "WildPokemon constructed" << endl;
}

WildPokemon :: ~WildPokemon()  {  cout << "WildPokemon destructed" << endl;  }

void WildPokemon :: follow(Trainer* t)  {
  current_trainer = t;
  in_combat = true;
  location = t -> GetLocation();
  t -> SetNumFollowed(t -> GetNumFollowed() + 1);
  cout << "\tIn Combat with Trainer: " << current_trainer -> GetName();
}

bool WildPokemon :: get_variant()  {
  return variant; 
}

double WildPokemon :: get_attack()  {
  return attack;
}

double WildPokemon :: get_health()  {
  return health;
}

bool WildPokemon :: get_in_combat()  {
  return in_combat;
}

bool WildPokemon :: Update()  {
  if (health <= 0)  {
    state = DEAD;
    return true;
  }
  if (!(current_trainer == NULL))  {
    state = IN_TRAINER;
    return true;
  }
  state = IN_ENVIRONMENT;
  return false;
}

void WildPokemon :: ShowStatus()  {
  cout << "WildPokemon status: " << endl;
  GameObject :: ShowStatus();
  switch(state)  {
    case IN_ENVIRONMENT: 
      cout << " is in the environment" << endl;
      break;
    case DEAD: 
      cout << " is dead" << endl;
      break;
    case IN_TRAINER:
      cout << " is following Trainer " << current_trainer -> GetName() << endl;
      break;
  }
  cout << "\tHealth: " << health << endl;
  cout << "\tAttack: " << attack << endl;
  cout << "\tVariant: " << variant << endl;
}

bool WildPokemon :: IsAlive()  {
  if (health > 0)
    return true;
  return false;
}

bool WildPokemon :: ShouldBeVisible()  {
  if (health > 0)
    return true;
  return false;
}