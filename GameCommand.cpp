#include "GameCommand.h"
#include <string.h>

char UserInputCommand(Model& model, View& view)  {
  string input;    // Take input
  cout << "Enter the game command: ";
  getline(cin, input);
  
  char inputChar[input.length()];
  for (int i =0; i < sizeof(inputChar); i++)  {
    inputChar[i] = input[i];
  }

  char gameCommand = inputChar[0];
  switch(gameCommand)  {
    case 'm':  {
      int ID = int(inputChar[2] - '0');
      double x = static_cast<double>(inputChar[4] - '0');
      double y = static_cast<double>(inputChar[6] - '0');
      DoMoveCommand(model, ID, Point2D(x, y));
      break;
    }
    case 'c':  {
      int ID1 = int(inputChar[2] - '0');
      int ID2 = int(inputChar[4] - '0');
      DoMoveToCenterCommand(model, ID1, ID2);
      break;
    }
    case 'g':  {
      int ID1 = int(inputChar[2] - '0');
      int ID2 = int(inputChar[4] - '0');
      DoMoveToGymCommand(model, ID1, ID2);
      break;
    }
    case 's':  {
      int ID = int(inputChar[2] - '0');
      DoStopCommand(model, ID);
      break;
    }
    case 'p':  {
      int ID = int(inputChar[2] - '0');
      int potion_amount = int(inputChar[4] - '0');
      DoMoveToGymCommand(model, ID, potion_amount);
      break;
    }
    case 'b':  {
      int ID = int(inputChar[2] - '0');
      int battle_amount = int(inputChar[4] - '0');
      DoMoveToGymCommand(model, ID, battle_amount);
      break;
    }
    case 'a': {
      DoAdvanceCommand(model, view);
      break;
    }
    case 'r':  { 
      DoRunCommand(model, view);
      break;
    }
    case 'n':  {
      char type = inputChar[2];
      int ID = int(inputChar[4] - '0');
      double x = double(inputChar[6] - '0');
      double y = double(inputChar[8] - '0');
      model.NewCommand(type, ID, x, y); 
      break;
    }
    case 'q':
      exit(0);
    default:
      cout << "Invalid input!!" << endl;  
  }  
  return gameCommand;
}

void DoMoveCommand(Model& model, int trainer_id, Point2D p1)  {
    Trainer* TrainerA = model.GetTrainerPtr(trainer_id);
    if (TrainerA == nullptr)  {
        throw Invalid_Input("Please enter the ID of an existing trainer");
        //cout <<"Error: Please enter a valid command" << endl;
    }  else  {
        TrainerA -> StartMoving(p1);
        cout << "Moving " << TrainerA -> GetName() << " to " << p1 << endl;
    }
}

void DoMoveToCenterCommand(Model& model, int trainer_id, int center_id)  {
    Trainer* TrainerA = model.GetTrainerPtr(trainer_id);
    PokemonCenter* CenterA = model.GetPokemonCenterPtr(center_id);
    if (TrainerA == nullptr || CenterA == nullptr)  {
        throw Invalid_Input("Please enter the IDs of existing objects");
        //cout << "Error: Please enter a valid command" << endl;
    }  else  {
        TrainerA -> StartMovingToCenter(CenterA);
        cout << "Moving " << TrainerA -> GetName() << " to Pokemon Center " << CenterA -> GetId() << endl;
    }
}

void DoMoveToGymCommand(Model& model, int trainer_id, int gym_id)  {
    Trainer* TrainerA = model.GetTrainerPtr(trainer_id);
    PokemonGym* GymA = model.GetPokemonGymPtr(gym_id);
    if (TrainerA == nullptr || GymA == nullptr)  {
        throw Invalid_Input("Please enter the IDs of existing objects");
        //cout << "Error: Please enter a valid command" << endl;
    }  else  {
        TrainerA -> StartMovingToGym(GymA);
        cout << "Moving " << TrainerA -> GetName() << " to Gym " << GymA -> GetId() << endl;
    }
}

void DoStopCommand(Model& model, int trainer_id)  {
    Trainer* TrainerA = model.GetTrainerPtr(trainer_id);
    if (TrainerA == 0)  {
        throw Invalid_Input("Please enter the ID of an existing Trainer");
        //cout << "Error: Please enter a valid command" << endl;
    }  else  {
        TrainerA -> Stop();
        cout << "Stopping " << TrainerA -> GetName() << endl;
    }
}

void DoBattleCommand(Model& model, int trainer_id, unsigned int battles)  {
    Trainer* TrainerA = model.GetTrainerPtr(trainer_id);
    if (TrainerA == 0)  {
        throw Invalid_Input("Please enter the ID of a existing Trainer");
        //cout << "Error: Please enter a valid command" << endl;
    }  else  {
        TrainerA -> StartBattling(battles);
        cout << TrainerA -> GetName() << " is battling" << endl;
    }
}

void DoRecoverInCenterCommand(Model& model, int trainer_id, unsigned int potions_needed)  {
    Trainer* TrainerA = model.GetTrainerPtr(trainer_id);
    if (TrainerA == 0)  {
        throw Invalid_Input("Please enter the ID of a existing Trainer");
        //cout << "Error: Please enter a valid command" << endl;
    }  else  {
        TrainerA -> StartRecoveringHealth(potions_needed);
        cout << "Recovering " << TrainerA -> GetName() << "'s pokemon's health" << endl;
    }
}

void DoAdvanceCommand(Model& model, View& view)  {
    cout << "Advancing one tick." << endl;
    model.Update();
    model.ShowStatus();
    view.Clear();
    model.Display(view);
    view.Draw();
}

void DoRunCommand(Model& model, View& view)  {
    for (int i = 0; i < 5; i++)  {
        if (model.Update())  {
            break;
        }
    }
    cout << "Advancing one event" << endl;
    model.ShowStatus();
    view.Clear();
    model.Display(view);
    view.Draw();
}

