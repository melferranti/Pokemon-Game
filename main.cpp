#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Trainer.h"
#include "Model.h"
#include "GameCommand.h"

using namespace std;

int main() {
  srand(time(NULL));
  
  char gameCommand;
  Model model;
  View view;
  view.Draw();
  do  {
    gameCommand = UserInputCommand(model, view);
    model.Update();
    model.ShowStatus();
    view.Draw();
  } while (gameCommand != 'q');

  return 0;
}