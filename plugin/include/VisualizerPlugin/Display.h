#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>
#include "Shape.h"

class Display {
public:
  static Display& getInstance()
  {
    if (nullptr == instance) instance = new Display;
    return *instance;
  }

  Display(const Display&) = delete; 
  Display& operator=(const Display&) = delete;
  static void destruct() {
    delete instance;
    instance = nullptr;
  }
  
  int getResolution() {return resolution;}
  std::vector<Shape*> getShapes() {return shapes;}
  int getNumShapes() {return shapes.size();}

  float getMaxRadius()
  {
    float maxRadius = 0;
    for (auto shape : shapes)
    {
      if (shape->getMaxRadius() > maxRadius)
      {
        maxRadius = shape->getMaxRadius();
      }
    }
    return maxRadius;
  }

  void setResolution(int newResolution) {resolution = newResolution;}
  void addShape(Shape* shape) {shapes.push_back(shape);}

  void clearShapes() {shapes.clear();}
private:
  Display() = default; 
  ~Display() = default; 
  static Display* instance; 
  int resolution;
  std::vector<Shape*> shapes;
};

#endif