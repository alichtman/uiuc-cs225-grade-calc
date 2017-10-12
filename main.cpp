#include <iostream>
#include <iomanip>
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
  double getFinalExam() const;
  void setFinalExam(double finalExam);
  double getExtraCredit() const;
  void setExtraCredit(double extraCredit);

 private:
  double mpTotal;
  double labTotal;
  double theoryExamTotal;
  double programmingExamTotal;
  double finalExam;
  double extraCredit;
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
  nextInput = NULL;
  cout << endl;

  cout << "Labs are scored out of 100 points, anything earned over that is considered extra credit." << endl;
  cout << "Each week, you can earn 10 points. 60% of these points are based on correctness. 40% are attendance points."
       << endl;
  cout << "There are 14 labs, so 4 of them are 'optional.'" << endl;
  cout << "Enter your total lab score (out of 100 points). Don't enter the extra credit in this section." << endl;
  cin >> nextInput;
  while (nextInput > 100 || nextInput < 0) {
    cout << "Invalid score -- try again." << endl;
    cin >> nextInput;
  }
  pStudent.setLabTotal(nextInput);
  nextInput = NULL;
  cout << endl;

  cout << "Enter your theory exam score out of 280." << endl;
  cin >> nextInput;
  while (nextInput > 280 || nextInput < 0) {
    cout << "Invalid score -- try again." << endl;
    cin >> nextInput;
  }
  pStudent.setTheoryExamTotal(nextInput);
  nextInput = NULL;
  cout << endl;

  cout << "Enter your programming exam score out of 240." << endl;
  cin >> nextInput;
  while (nextInput > 240 || nextInput < 0) {
    cout << "Invalid score -- try again." << endl;
    cin >> nextInput;
  }
  pStudent.setProgrammingExamTotal(nextInput);
  nextInput = NULL;
  cout << endl;

  cout << "Enter your extra credit score, which is capped at 100 points." << endl;
  cout << "This section is composed of MP Early Submission points, Lab extra credit, and POTD points." << endl;
  cout << "MP bonus points are capped at 91 possible." << endl;
  cout << "Lab bonus points are capped at 40 possible." << endl;
  cout << "POTD bonus points are capped at 40 possible." << endl;
  cin >> nextInput;
  while (nextInput > 100 || nextInput < 0) {
    cout << "Invalid score -- try again." << endl;
    cin >> nextInput;
  }
  pStudent.setExtraCredit(nextInput);
  nextInput = NULL;
  cout << endl;
}

/**
 * Prints student grade in nice table
 * @param student
 */
void printGradeInfo(Student student) {

  cout << " --  Grading Information Entered -- " << endl;

  cout << left << setw(20) << "\tMPs " << right << setw(5) << student.getMpTotal() << '\n';
  cout << left << setw(20) << "\tLabs " << right << setw(5) << student.getLabTotal() << '\n';
  cout << left << setw(20) << "\tTheory Quizzes " << right << setw(5) << student.getTheoryExamTotal() << '\n';
  cout << left << setw(20) << "\tCoding Quizzes " << right << setw(5) << student.getProgrammingExamTotal() << '\n';
  cout << left << setw(20) << "\tExtra Credit " << right << setw(5) << student.getExtraCredit() << '\n';
}

int main() {
  graphics::drawLaunchGraphic();

  Student you;
  getGradeInformation(you);

  printGradeInfo(you);

  return 0;
}
