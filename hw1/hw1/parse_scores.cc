// Copyright 2019 Nicholas Knight
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  /* The following input
   *
   *   2 1234 3 98.7 87.92 77.32 2345 3 93.1 90.23 81.21
   *
   * would result in the following output.
   */
  /* 
  cout << "    { \"id\" : 1234, \"grades\" : [ 98.7, 87.92, 77.32 ] }," << endl;
  cout << "    { \"id\" : 2345, \"grades\" : [ 93.1, 90.23, 81.21 ] }" << endl;
  */
  cout << "{" << endl;
  cout << "  \"students\" : [" << endl;
  int num_students;
  cin >> num_students;
  double max_grade = 0;
  int max_id = 0;
  for (int i = 0; i< num_students; ++i) {
    int id;
    cin >> id;
    int num_grades;
    cin >> num_grades;
    // cout << id << endl;
    cout << "    { \"id\" : " << id <<", \"grades\" : [ ";
    const int kNumGrades = num_grades;
    double grades[kNumGrades];
    for (int i = 0; i < num_grades; ++i) {
      cin >> grades[i];
      cout << grades[i];
      if (i< num_grades-1)
        cout << ", ";
      if (grades[i] > max_grade) {
        max_grade = grades[i];
        max_id = id;
      }
    }
    if (i != num_students -1)
      cout << " ] }," << endl;
    else
      cout << " ] }" << endl;
  }
  cout << "  ]," << endl;
  cout << "  \"max_id\" : " << max_id << "," << endl;
  cout << "  \"max_score\" : " << max_grade << endl;
  cout << "}" << endl;
  return 0;
}
