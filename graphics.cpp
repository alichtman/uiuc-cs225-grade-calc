#include "graphics.h"
#include <fstream>
#include <iostream>

using namespace std;

/**
 * CREDIT TO THEMASSIVECHIPMUNK -> http://www.cplusplus.com/forum/general/58945/
 */

string getFileContents(std::ifstream &File) {
  string Lines = "";        //All lines
  if (File)                      //Check if everything is good
  {
    while (File.good()) {
      std::string TempLine;                  //Temp line
      std::getline(File, TempLine);        //Get temp line
      TempLine += "\n";                      //Add newline character

      Lines += TempLine;                     //Add newline
    }
    return Lines;
  } else                           //Return error
  {
    return "ERROR File does not exist.";
  }
}

/**
 * Prints splash screen and creator info
 */
void graphics::drawLaunchGraphic() {
  drawGraphicFromFile("splash.txt");
  drawCreatorCredits();
}

/**
 * Prints ASCII art from text file
 * @param fileName
 */
void graphics::drawGraphicFromFile(std::string fileName) {
  ifstream reader(fileName);             //Open file
  string Art = getFileContents(reader);       //Get file
  cout << Art << std::endl;               //Print it to the screen
  reader.close(); //close file
}

/**
 * Prints out the creator info
 */
void graphics::drawCreatorCredits() {
  drawGraphicFromFile("creator.txt");
}


