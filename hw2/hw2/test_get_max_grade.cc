#include "parse_scores.h"

#include <cassert>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

std::string kValues[] = {
  "2",
  "1234", "3", "98.7", "87.92", "77.32", 
  "2345", "4", "93.1", "90.23", "81.21", "89.33" };
int kSize = 12;


bool TestGetMaxGrade();
bool TestGetMaxGradeNoMatch();  // true when returns -1 for no matching id
bool TestGetMaxGradeNoIndex();  // true when returns -2 for missing index
bool TestGetMaxGradeFormatCorrupt();  // true when returns -10 for corrupt format


int main(int argc, char* argv[]) {
  int passed = 0;
  // test get_max_grades
  cout << "Testing get_max_grade" << endl;
  if (TestGetMaxGrade())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }
  
  cout << "Testing get_max_grade with no student" << endl;
  if (TestGetMaxGradeNoMatch())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }
  
  cout << "Testing get_max_grade with no grade" << endl;
  if (TestGetMaxGradeNoIndex())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }
  
  cout << "Testing get_max_grade with format corrupt" << endl;
  if (TestGetMaxGradeFormatCorrupt())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }

  return passed;
}


bool TestGetMaxGrade() {  // true when correct grade selected for given id
  int ids[] = { 1234, 2345, 1234, 2345 };
  double expected_grade = 98.7;
  bool passed = true;
  double actual_grade = get_max_grade(kValues, kSize);
  
    if (expected_grade != actual_grade) {
      cout << "\tExpected Grade: " << expected_grade
          << "Actual Grade : " << actual_grade << endl;
      passed = false;
    }

  return passed;
}


bool TestGetMaxGradeNoMatch() {  // true when returns -1 for no matching id
  double expected = -1;
  std::string kNoStudent[] = {
  "0",
  "1234", "3", "98.7", "87.92", "77.32", 
  "2345", "4", "93.1", "90.23", "81.21", "89.33" };

  double actual = get_max_grade(kNoStudent, kSize);
  if (expected != actual) {
    cout << "\tExpected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}


bool TestGetMaxGradeNoIndex() {
  double expected = -2;
  std::string kNoStudent[] = {
  "2",
  "1234", "0", "", "", "", 
  "2345", "4", "93.1", "90.23", "81.21", "89.33" };
  double actual = get_max_grade(kNoStudent, kSize);
  if (expected != actual) {
    cout << "\tExpected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}


bool TestGetMaxGradeFormatCorrupt() {
  double expected = -10;
  double actual = get_max_grade(kValues, kSize-5);
  if (expected != actual) {
    cout << "\tExpected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}
