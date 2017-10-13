#include <iostream>
#include <iomanip>
#include <complex>
#include <sstream>
#include "graphics.h"

using namespace std;

class Student {
 public:
  Student();
  Student(double mpTotal,
          double labTotal,
          double theoryExamTotal,
          double programmingExamTotal,
          double extraCredit);
  double getMpTotal() const;
  void setMpTotal(double mpTotal);
  double getLabTotal() const;
  void setLabTotal(double labTotal);
  double getTheoryExamTotal() const;
  void setTheoryExamTotal(double theoryExamTotal);
  double getProgrammingExamTotal() const;
  void setProgrammingExamTotal(double programmingExamTotal);
  double getExtraCredit() const;
  void setExtraCredit(double extraCredit);

  double calculateTotalPoints();

 private:
  double mpTotal;
  double labTotal;
  double theoryExamTotal;
  double programmingExamTotal;
  double extraCredit;
  string gradeDesired;
 public:
  const string &getGradeDesired() const;
  void setGradeDesired(const string &gradeDesired);

};

Student::Student(double mpTotal,
                 double labTotal,
                 double theoryExamTotal,
                 double programmingExamTotal,
                 double extraCredit)
    : mpTotal(mpTotal),
      labTotal(labTotal),
      theoryExamTotal(theoryExamTotal),
      programmingExamTotal(programmingExamTotal),
      extraCredit(extraCredit) {
}

Student::Student() {
  mpTotal = 0;
  labTotal = 0;
  theoryExamTotal = 0;
  programmingExamTotal = 0;
  extraCredit = 0;
}

double Student::getMpTotal() const {
  return mpTotal;
}

void Student::setMpTotal(double mpTotal) {
  Student::mpTotal = mpTotal;
}

double Student::getLabTotal() const {
  return labTotal;
}

void Student::setLabTotal(double labTotal) {
  Student::labTotal = labTotal;
}

double Student::getTheoryExamTotal() const {
  return theoryExamTotal;
}

void Student::setTheoryExamTotal(double theoryExamTotal) {
  Student::theoryExamTotal = theoryExamTotal;
}

double Student::getProgrammingExamTotal() const {
  return programmingExamTotal;
}

void Student::setProgrammingExamTotal(double programmingExamTotal) {
  Student::programmingExamTotal = programmingExamTotal;
}

double Student::getExtraCredit() const {
  return extraCredit;
}

void Student::setExtraCredit(double extraCredit) {
  Student::extraCredit = extraCredit;
}

const string &Student::getGradeDesired() const {
  return gradeDesired;
}

void Student::setGradeDesired(const string &gradeDesired) {
  Student::gradeDesired = gradeDesired;
}

/**
 * Calculates total points earned by a student, excluding final exam.
 * @return double total points
 */
double Student::calculateTotalPoints() {
  return this->getExtraCredit() + this->getProgrammingExamTotal() + this->getTheoryExamTotal() + this->getLabTotal()
      + this->getMpTotal();
}

/**
 * Fields input for grade information from student.
 *
 * @param pStudent
 */
void getGradeInformation(Student &pStudent) {

  /**
    * Grading: ------------------------
    * ----- MPs : 130 pts total   -   10 pts for MP1, 20 pts for everything else
    * ----- Labs: 100 pts total, anything after is extra credit. 60% correctness, 40% attendance. 10pts each, 14 weeks
    * ----- Theory Exams: 280 pts total, 7x 40pts each
    * ----- Programming Exams: 240 pts, 6x 40pts each
    * ----- Final Exam: 250 pts
    * ----- Extra Credit: Capped at 100 pts, MP bonus total poss = 91, POTD total poss = 40
   */

  double nextInput;
  cout
      << "\033[1;32mThere are 130 points in the MP category. \nMP1 is worth 10 points. All other MPs are worth 20.\nHow many points did you earn?\033[0m\n";
  cin >> nextInput;
  while (nextInput > 130 || nextInput < 0) {
    cout << "\033[1;31mInvalid score -- enter a score between 0 and 130.\033[0m\n";
    cin >> nextInput;
  }
  pStudent.setMpTotal(nextInput);
  cout << endl;

  cout
      << "\033[1;32mThere are 100 points in the Lab category.\nThere are 14 labs, each worth 10 points.\nAny points over 100 earned will be counted as extra credit.\nEnter your lab score, not counting extra credit.\033[0m\n";
  cin >> nextInput;
  while (nextInput > 100 || nextInput < 0) {
    cout << "\033[1;31mInvalid score -- enter a score between 0 and 100.\033[0m\n";
    cin >> nextInput;
  }
  pStudent.setLabTotal(nextInput);
  cout << endl;

  cout << "\033[1;32mEnter your theory exam score out of 280.\033[0m\n";
  cin >> nextInput;
  while (nextInput > 280 || nextInput < 0) {
    cout << "\033[1;31mInvalid score -- enter a score between 0 and 280.\033[0m\n";
    cin >> nextInput;
  }
  pStudent.setTheoryExamTotal(nextInput);
  cout << endl;

  cout << "\033[1;32mEnter your programming exam score out of 240.\033[0m\n";
  cin >> nextInput;
  while (nextInput > 240 || nextInput < 0) {
    cout << "\033[1;31mInvalid score -- enter a score between 0 and 240.\033[0m\n";
    cin >> nextInput;
  }
  pStudent.setProgrammingExamTotal(nextInput);
  cout << endl;

  double mpBonusPoints;
  cout
      << "\033[1;32mYour extra credit score is composed of MP Early Submission points, Lab extra credit, and POTD points.\nIt's capped at 100 points.\nHow many MP early submission bonus points do you have?\033[0m\n";
  cin >> mpBonusPoints;
  while (mpBonusPoints < 0 || mpBonusPoints > 91) {
    cout << "\033[1;31mMP bonus points are capped at 91. Enter a number between 0 and 91.\033[0m\n";
    cin >> mpBonusPoints;
  }
  cout << endl;

  double labBonusPoints;
  cout
      << "\033[1;32mHow much lab extra credit do you have?\nAny lab points earned over 100 overflow into this category.\033[0m\n";
  cin >> labBonusPoints;
  while (labBonusPoints < 0 || labBonusPoints > 40) {
    cout << "\033[1;31mLab bonus points are capped at 40. Enter a number between 0 and 40.\033[0m\n";
    cin >> labBonusPoints;
  }
  cout << endl;

  double potdBonusPoints;
  cout
      << "\033[1;32mHow many POTDs have you completed?\nThe greatest number of points you can earn in this category is 40.\033[0m\n";
  cin >> potdBonusPoints;
  while (potdBonusPoints < 0 || potdBonusPoints > 40) {
    cout << "\033[1;31mPOTD points are capped at 40. Enter a number between 0 and 40.\033[0m\n";
    cin >> potdBonusPoints;
  }
  cout << endl;

  double totalEc = mpBonusPoints + labBonusPoints + potdBonusPoints;

  if (totalEc > 100) {
    totalEc = 100;
  }

  pStudent.setExtraCredit(totalEc);
  cout << endl;
}

/**
 * Function to set num of decimal places for x
 * CREDIT : https://stackoverflow.com/questions/1343890/rounding-number-to-2-decimal-places-in-c
 */
string formatPctage(const double &x, const int &numDecimals) {
  int y = x;
  double z = x - y;
  double m = pow(10, numDecimals);
  double q = z * m;
  double r = round(q);

  std::ostringstream strs;
  strs << static_cast<double>(y) + (1.0 / m) * r;
  std::string str = strs.str();
  return str;
}

/**
 * Prints student grade in nice table format
 * @param student
 */
void printGradeInfo(Student student) {

  double mpScore = student.getMpTotal();
  double mpPct = 100 * mpScore / 130;

  double labScore = student.getLabTotal();
  double labPct = 100 * labScore / 100;

  double theoryScore = student.getTheoryExamTotal();
  double theoryPct = 100 * theoryScore / 280;

  double programmingScore = student.getProgrammingExamTotal();
  double programmingPct = 100 * programmingScore / 240;

  cout << "\033[1;32m -- Grading Information Entered -- \033[0m\n";
  cout << left << setw(20) << "  MPs " << right << setw(5) << mpScore << right << setw(5) << "("
       << formatPctage(mpPct, 2) << "%)" << endl;
  cout << left << setw(20) << "  Labs " << right << setw(5) << labScore << right << setw(5) << "("
       << formatPctage(labPct, 2) << "%)" << endl;
  cout << left << setw(20) << "  Theory Quizzes " << right << setw(5) << theoryScore << right << setw(5) << "("
       << formatPctage(theoryPct, 2) << "%)" << endl;
  cout << left << setw(20) << "  Coding Quizzes " << right << setw(5) << programmingScore << right << setw(5) << "("
       << formatPctage(programmingPct, 2) << "%)" << endl;
  cout << left << setw(20) << "  Extra Credit " << right << setw(5) << student.getExtraCredit() << "    (----)" << endl;
  cout << right << setw(20) << "\033[1;33m  Current Total :      " << student.calculateTotalPoints() << "/1000"
       << "\033[0m\n\n";
}

/*
 * Gets final grade cutoff
 * @return desired final grade
 */
int getFinalGradeDesired(Student &student) {
  cout << "\033[1;32m ---- Grading Cutoffs ---- \033[0m\n";
  cout << left << "  0.  A-" << right << setw(10) << "900\n";
  cout << left << "  1.  B-" << right << setw(10) << "800\n";
  cout << left << "  2.  C-" << right << setw(10) << "700\n";
  cout << left << "  3.  D-" << right << setw(10) << "600\n";
  cout << left << "  4.  F" << right << setw(12) << "500\n\n";

  int input;
  cout << "\033[1;32mPlease enter your minimum desired final letter grade.\033[0m\n";
  cout << "\033[1;32mIndicate your choice by entering the respective index.\033[0m\n";
  cin >> input;

  while (input > 4 || input < 0) {
    cout << "\033[1;31mInvalid line number. Try again.\033[0m\n";
    cin >> input;
  }

  cout << endl;

  //Returns cutoff for grade level selected
  switch (input) {
    case 0:student.setGradeDesired("A-");
      return 900;
    case 1:student.setGradeDesired("B-");
      return 800;
    case 2:student.setGradeDesired("C-");
      return 700;
    case 3:student.setGradeDesired("D-");
      return 600;
    case 4:student.setGradeDesired("F");
      return 500;
    default:cout << "\033[1;31mThis line of code should never execute?\033[0m\n";
      return - 1;
  }
}

/**
 * Calculates the final exam grade needed to attain the desired grade.
 * If return from this function is greater than 250, it's not possible
 * @param student
 * @param needed
 * @return score needed on final out of 250 pts
 */
double calculateFinalExamGradeNeeded(Student student, int desiredGradeCutoff) {
  double pointsSoFar = student.calculateTotalPoints();

  if (pointsSoFar + 250 >= desiredGradeCutoff) {
    return desiredGradeCutoff-pointsSoFar;
  }
  else return -1;
}

int main() {
  //Draw splash screen
  graphics::drawLaunchGraphic();

  //Gather info
  Student studentGrades;
  getGradeInformation(studentGrades);
  printGradeInfo(studentGrades);
  int lowestGradeNeeded = getFinalGradeDesired(studentGrades);

  double finalExamScoreNeeded = calculateFinalExamGradeNeeded(studentGrades, lowestGradeNeeded);

  cout << "\033[1;37mTo earn a final grade of " << studentGrades.getGradeDesired() << ", a final exam score of " <<
       formatPctage(100 * finalExamScoreNeeded / 250, 3) << "% is needed.\033[0m\n";

  if (finalExamScoreNeeded < 250) {
    cout << "\033[1;32mThis is do-able! Good luck!\033[0m" << endl;
  } else {
    cout
        << "\033[1;31mUnfortunately this does not appear to be do-able. \nFor your sake, I hope there's a serious logic error in this code...\033[0m\n";
  }

  return 0;
}
