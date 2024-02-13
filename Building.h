#ifndef BUILDING_H
#define BUILDING_H

#include "Point2D.h"
#include "GameObject.h"

class Building  : public GameObject  {
  private:
    unsigned int trainer_count = 0;
  public:
    Building();
    Building(char in_code, int in_id, Point2D in_loc);
    virtual ~Building();
    void AddOneTrainer();
    void RemoveOneTrainer();
    virtual void ShowStatus();
    bool ShouldBeVisible();
  protected:
    Building(char in_code);  
};

#endif