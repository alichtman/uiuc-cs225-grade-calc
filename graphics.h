//
// Created by Aaron Lichtman on 10/12/17.
//

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>

class graphics {
 public:
  static void drawLaunchGraphic();
  static void drawGraphicFromFile(std::string fileName);
  static void drawCreatorCredits();
};

#endif //GRAPHICS_H
