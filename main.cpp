#include <iostream>
#include <iomanip>
#include <complex>
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
  cout << "MPs are worth 130 points in total. MP1 is worth 10 points, and all other MPs are worth 20." << endl;
  cout << "How many points did you earn?" << endl;
  cin >> nextInput;
  while (nextInput > 130 || nextInput < 0) {
    cout << "Invalid score -- try again." << endl;
    cin >> nextInput;
  }
  pStudent.setMpTotal(nextInput);
  cout << endl;

  cout << "Labs are scored out of 100 total points, anything earned over that is considered extra credit." << endl;
  cout << "There are 14 labs, worth 10 points each, so 40 points of EC can be earned." << endl;
  cout << "Enter your lab score without the extra credit. (We'll deal with EC later...)" << endl;
  cin >> nextInput;
  while (nextInput > 100 || nextInput < 0) {
    cout << "Invalid score -- try again." << endl;
    cin >> nextInput;
  }
  pStudent.setLabTotal(nextInput);
  cout << endl;

  cout << "Enter your theory exam score out of 280." << endl;
  cin >> nextInput;
  while (nextInput > 280 || nextInput < 0) {
    cout << "Invalid score -- try again." << endl;
    cin >> nextInput;
  }
  pStudent.setTheoryExamTotal(nextInput);
  cout << endl;

  cout << "Enter your programming exam score out of 240." << endl;
  cin >> nextInput;
  while (nextInput > 240 || nextInput < 0) {
    cout << "Invalid score -- try again." << endl;
    cin >> nextInput;
  }
  pStudent.setProgrammingExamTotal(nextInput);
  cout << endl;

  cout << "Enter your extra credit score, which is capped at 100 points." << endl;
  cout << "This section is composed of MP Early Submission points, Lab extra credit, and POTD points." << endl;

  double mpBonusPoints;
  cout << "How many MP early submission bonus points do you have?" << endl;
  cin >> mpBonusPoints;
  while (mpBonusPoints < 0 || mpBonusPoints > 91) {
    cout << "MP bonus points are capped at 91. Enter a number between 0 and 91." << endl;
    cin >> mpBonusPoints;
  }

  double labBonusPoints;
  cout << "How much lab extra credit do you have? Any lab points earned over 100 overflow into this category." << endl;
  cin >> labBonusPoints;
  while (labBonusPoints < 0 || labBonusPoints > 40) {
    cout << "Lab bonus points are capped at 40. Enter a number between 0 and 40." << endl;
    cin >> labBonusPoints;
  }

  double potdBonusPoints;
  cout << "How many POTDs have you completed? POTD points are capped at 40." << endl;
  cin >> potdBonusPoints;
  while (potdBonusPoints < 0 || potdBonusPoints > 40) {
    cout << "POTD points are capped at 40. Enter a number between 0 and 40." << endl;
    cin >> potdBonusPoints;
  }

  double totalEc = mpBonusPoints + labBonusPoints + potdBonusPoints;

  pStudent.setExtraCredit(totalEc);
  cout << endl;
}

/**
 * Function to set num of decimal places for x
 */
double formatPctage(const double &x, const int &numDecimals) {
  int y = x;
  double z= x-y;
  double m=pow(10,numDecimals);
  double q=z*m;
  double r=round(q);
  return static_cast<double>(y)+(1.0/m)*r;
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

  double ECScore = student.getExtraCredit();


  cout << " -- Grading Information Entered -- \n" << endl;
  cout << left << setw(20) << "  MPs " << right << setw(5) << mpScore << right << setw(5) << "(" << formatPctage(mpPct, 2) << "%)" << endl;
  cout << left << setw(20) << "  Labs " << right << setw(5) << labScore << right  << setw(5) <<  "(" << formatPctage(labPct, 2) << "%)" << endl;
  cout << left << setw(20) << "  Theory Quizzes " << right << setw(5) << theoryScore << right << setw(5) << "(" << formatPctage(theoryPct, 2) << "%)" << endl;
  cout << left << setw(20) << "  Coding Quizzes " << right << setw(5) << programmingScore << right << setw(5) << "(" << formatPctage(programmingPct, 2) << "%)" << endl;
  cout << left << setw(20) << "  Extra Credit " << right << setw(6) << ECScore << "   (-----)" << endl;
  cout << right << setw(20) << "     Current Total : \t" << student.calculateTotalPoints() << "\n" << endl;
}

/**
 * Gets final grade cutoff
 * @return desired final grade
 */
int getFinalGradeDesired(Student &student) {
  cout << " ---- Grading Cutoffs ---- " << endl;
  cout << left << "  0.  A-" << right << setw(10) << "900" << endl;
  cout << left << "  1.  B-" << right << setw(10) << "800" << endl;
  cout << left << "  2.  C-" << right << setw(10) << "700" << endl;
  cout << left << "  3.  D-" << right << setw(10) << "600" << endl;
  cout << left << "  4.  F" << right << setw(11) << "500" << endl;

  int input;
  cout << "Please enter your minimum desired final letter grade." << endl;
  cout << "Indicate the number on the left." << endl;
  cin >> input;

  while (input > 4 || input < 0) {
    cout << "Invalid line number. Try again." << endl;
    cin >> input;
  }

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
      cout << "Dude what" << endl;
      return - 1;
    default:cout << "Something has gone wrong." << endl;
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

  for (int i = 0; i < 1100; i ++) {
    if (pointsSoFar + i >= desiredGradeCutoff) {
      return i;
    }
  }
  cout << "This line of code should never execute?" << endl;
  return - 1;
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

  cout << "In order to earn a final grade of " << studentGrades.getGradeDesired() << "," << endl;
  cout << "you need a raw final exam score of " << finalExamScoreNeeded << " out of 250." << endl;

  if (finalExamScoreNeeded < 250) {
    cout << "This is do-able! Good luck!" << endl;
  } else {
    cout
        << "Unfortunately this does not appear to be do-able. \nFor your sake, I hope there's a serious logic error in this code..."
        << endl;
  }
  return 0;
}
