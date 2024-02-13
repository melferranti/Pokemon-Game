#include "Point2D.h"
#include "GameObject.h"

using namespace std;

GameObject :: GameObject(char in_code)
:display_code(in_code), id_num(1), state(0)  {  
  cout << "GameObject constructed" << endl;
}

GameObject :: GameObject(Point2D in_loc, int in_id, char in_code)
:display_code(in_code), id_num(in_id), location(in_loc), state(0)  {  
  cout << "GameObject constructed" << endl;
}

GameObject :: ~GameObject() { cout << "GameObject destructed" << endl;  }

// Added
void GameObject :: setState(char in_state)  {
  state = in_state;
}

// Added
void GameObject :: setDisplayCode(char in_code)  {
  display_code = in_code;
}

Point2D GameObject :: GetLocation() const  {
  return location;
}

int GameObject :: GetId() const  {
  return id_num;
}

int GameObject :: GetState() const  {
  return state;
}

void GameObject :: ShowStatus()  {
  cout << display_code << id_num << " at " << location << endl;
}

void GameObject :: DrawSelf(char* ptr)  {    
  *ptr = display_code;
  *(ptr + 1) = '0' + id_num;
}