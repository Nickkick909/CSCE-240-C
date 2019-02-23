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
int ids[] = {1234, 2345};

bool TestGetStudentId();
bool TestGetStudentIdCorruptFormat();


int main(int argc, char* argv[]) {
  int passed = 0;
  

  // test get_student_ids
  cout << "Testing get_student_ids" << endl;
  if (TestGetStudentId())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }

  cout << "Testing get_student_ids with corrupt format" << endl;
  if (TestGetStudentIdCorruptFormat())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }

  return passed;
}


bool TestGetStudentId() {
  int expected = 2;
  int actual = get_student_ids(kValues, kSize, ids);
  if (expected != actual) {
    cout << "\tExpected: " << expected << ", Actual: "
        << actual << endl;
    return false;
  }

  return true;
}

bool TestGetStudentIdCorruptFormat() {
  int expected_id = -10;
  int actual_id = get_student_ids(kValues, kSize-1, ids);
  if (expected_id != actual_id) {
    cout << "\tExpected: " << expected_id << ", Actual: "
        << actual_id << endl;
    return false;
  }

  return true;
}
