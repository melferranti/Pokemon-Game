#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Point2D.h"
#include "Vector2D.h"

class GameObject  {
  protected:
    Point2D location;
    int id_num;
    char display_code;
    char state;
    void setState(char in_state); // Added
    void setDisplayCode(char in_code); // Added
  public:
    GameObject();
    GameObject(char in_code);
    GameObject(Point2D in_loc, int in_id, char in_code);
    virtual ~GameObject();
    Point2D GetLocation() const;
    int GetId() const;
    int GetState() const;
    virtual void ShowStatus() = 0;
    virtual bool Update()  = 0;
    virtual bool ShouldBeVisible() = 0;
    void DrawSelf(char* ptr);
};

#endif