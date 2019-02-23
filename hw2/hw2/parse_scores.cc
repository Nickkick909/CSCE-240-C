/* Copyright Nicholas Knight 2019
*/

#include "parse_scores.h" //NOLINT



int get_num_grades(int id, const std::string values[], int size) {
    for (int i = 0; i < size; ++i) {
        int value = stoi(values[i]);
        if (value == id) {
            // found matching id!!
            int num_grades = stoi(values[i + 1]);
            // if format is correct i + 1 is number of grades
            if (num_grades + i + 2 > size) {
                return -10;  // incorrect format
            }
            return num_grades;
        }
    }
    return -1;
}


int get_grades(int id, const std::string values[], int size, double grades[]) {
    for (int i = 0; i < size; ++i) {
        int value = stoi(values[i]);
        if (value == id) {
            // found matching id!!
            int num_grades = stoi(values[i + 1]);
            // if format is correct i + 1 is number of grades
            for (int j = 0; j < num_grades; ++j) {
                grades[j] = stod(values[i + j + 2]);
            }
            if (num_grades + i + 2 > size) {
                return -10;  // incorrect format
            }
            return num_grades;
        }
    }
    return -1;
}


double get_grade(int id,
                   int grade_index, const std::string values[], int size) {
    for (int i = 1; i < size; ++i) {
        ++i;
        int num_grades = stoi(values[i]);
        i += num_grades;
        if (i > size) {
            return -10;  // incorrect format
        }
    }
    for (int i = 0; i < size; ++i) {
        int value = stoi(values[i]);
        if (value == id) {
            // found matching id!!
            int num_grades = stoi(values[i + 1]);
            // if format is correct i + 1 is number of grades
            for (int j = 0; j < num_grades; ++j) {
                double grade = stod(values[i + j + 2]);
                if (grade_index == j)
                    return grade;
            }
            return -2;
        }
    }
    return -1;
}


int get_max_grade_id(const std::string values[], int size) {
    int max_id = -1;
    double max_grade = -1;
    const int kSize = 15;
    if (stoi(values[0]) == 0)
        return -1;
    if (stoi(values[2]) == 0)
        return -2;
    for (int i = 1; i < size; ++i) {
        int id = stoi(values[i]);
        if (get_num_grades(id, values, size) == -10)
            return -10;
        double grades[kSize];

        get_grades(id, values, size, grades);
        for (int j = 0; j < get_num_grades(id, values, size); ++j) {
            if (grades[i] > max_grade) {
                max_grade = grades[i];
                max_id = id;
            }
        }
        i +=  get_num_grades(id, values, size) + 1;
    }
    return max_id;
}


double get_max_grade(const std::string values[], int size) {
    double max_grade = -1;
    const int kSize = 15;
    if (stoi(values[0]) == 0)
        return -1;
    if (stoi(values[2]) == 0)
        return -2;
    for (int i = 1; i < size; ++i) {
        int id = stoi(values[i]);
        if (get_num_grades(id, values, size) == -10)
            return -10;
        double grades[kSize];

        get_grades(id, values, size, grades);
        for (int j = 0; j < get_num_grades(id, values, size); ++j) {
            if (grades[j] > max_grade) {
                max_grade = grades[j];
            }
        }
        i +=  get_num_grades(id, values, size) + 1;
    }
    return max_grade;
}


int get_student_ids(const std::string values[], int size, int ids[]) {
    int num_ids = 0;
    for (int i = 1; i < size; ++i) {
        int id = stoi(values[i]);
        if (get_num_grades(id, values, size) == -10)
            return -10;
        ids[num_ids] = id;
        ++num_ids;

        i +=  get_num_grades(id, values, size) + 1;
        // return get_num_grades(id, values, size);
    }
    return num_ids;
}
