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

bool TestGetNumGrades();
bool TestGetNumGradesNoMatch();
bool TestGetNumGradesCorrupt();

bool TestGetGrades() {
  bool passed = true;
  int expected_return[] = {3, 4};
  int actual_return;
  double expected_grades[][4] = {
      { 98.7, 87.92, 77.32, 0.0 },
      { 93.1, 90.23, 81.21, 89.33 }
  };
  double actual_grades[4];
  int ids[] = { 1234, 2345 };
  int num_grades[] = {3, 4};

  for (int i = 0; i < 2; ++i) {
    actual_return = get_grades(ids[i], kValues, kSize, actual_grades);
    if (expected_return[i] != actual_return) {
      cout << "\tExpected Return: " << expected_return[i] << ", Actual Return: "
          << actual_return << endl;
      passed = false;
    }
    for (int j = 0; j < num_grades[i]; ++j) {
      if (expected_grades[i][j] != actual_grades[j]) {
        cout << "\tExpected[" << j << "]: " << expected_grades[i][j]
            << ", Actual [" << j << "]: " << actual_grades[j] << endl;
        passed = false;
      }
    }
  }

  return passed;
}


int main(int argc, char* argv[]) {
  int passed = 0;
  // test get_num_grades
  cout << "Testing get_num_grades" << endl;
  if (TestGetNumGrades())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }
  cout << "Testing get_num_grades with no match" << endl;
  if (TestGetNumGradesNoMatch())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }
  cout << "Testing get_num_grades with corrupt format" << endl;
  if (TestGetNumGradesCorrupt())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }

  // test get_grades
  cout << "Testing get_grades" << endl;
  if (TestGetGrades())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }


  //test get_grade
  assert(get_grade(1234, 0, kValues, kSize) == 98.7);
  assert(get_grade(1234, 2, kValues, kSize) == 77.32);
  assert(get_grade(2345, 0, kValues, kSize) == 93.1);
  assert(get_grade(2345, 3, kValues, kSize) == 89.33);

  // test get_max_ values
  
   cout << get_max_grade_id(kValues, kSize -1 ) << endl;//<< get_max_grade_id(kValues, kSize);
  cout << endl;
  assert(get_max_grade_id(kValues, kSize) == 1234);
  assert(get_max_grade(kValues, kSize) == 98.7);

  // test get_student_ids
  int ids[5];
  assert(get_student_ids(kValues, kSize, ids) == 2);

  assert(ids[0] == 1234);
  assert(ids[1] == 2345);

  return passed;
}

bool TestGetNumGrades() {
  bool passed = true;
  int expected, actual;

  expected = 3;
  actual = get_num_grades(1234, kValues, kSize);
  if (expected != actual) {
    cout << "\tExpected: " << expected << ", Actual: " << actual << endl;
    passed = false;
  }

  expected = 4;
  actual = get_num_grades(2345, kValues, kSize);
  if (expected != actual) {
    cout << "\tExpected: " << expected << ", Actual: " << actual << endl;
    passed = false;
  }

  return passed;
}


bool TestGetNumGradesNoMatch() {
  bool passed = true;
  int expected, actual;

  expected = -1;
  actual = get_num_grades(3456, kValues, kSize);
  if (expected != actual) {
    cout << "\tExpected: " << expected << ", Actual: " << actual << endl;
    passed = false;
  }

  return passed;
}


bool TestGetNumGradesCorrupt() {
  bool passed = true;
  int expected, actual;

  expected = -10;
  actual = get_num_grades(2345, kValues, kSize - 1);
  if (expected != actual) {
    cout << "\tExpected: " << expected << ", Actual: " << actual << endl;
    passed = false;
  }

  return passed;
}