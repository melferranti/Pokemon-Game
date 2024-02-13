#ifndef WILDPOKEMON_H
#define WILDPOKEMON_H
#include "Point2D.h"
#include "Trainer.h"

class WildPokemon : public GameObject  {
  protected:
  double attack = 5.0;
  double health = 2.0;
  bool variant = false;
  bool in_combat = false;
  string name;
  Trainer* current_trainer;

  public:
  WildPokemon(string, double, double, bool, int, Point2D);
  ~WildPokemon();
  void follow(Trainer* t);
  bool get_variant();
  double get_attack();
  double get_health();
  bool get_in_combat();
  bool Update();
  void ShowStatus();
  bool IsAlive();
  bool ShouldBeVisible();
};

  enum WildPokemonStates  {
    IN_ENVIRONMENT = 0,
    DEAD = 1,
    IN_TRAINER = 2,
  };
  

#endif 