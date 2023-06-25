// Author: Jarrod Thomisee
// jarrod.thomisee@snhu.edu
// CS-300

#include <algorithm>

#include <iostream>

#include <fstream>

#include <sstream>

#include <string>

#include <vector>

using namespace std;

// Define the Course class
class Course {
public: string courseNumber;
      string courseName;
      vector < string > prerequisites;

      Course(const string& line = "") {
          stringstream ss(line);
          getline(ss, courseNumber, ',');
          getline(ss, courseName, ',');
          string prerequisite;
          while (getline(ss, prerequisite, ',')) {
              prerequisites.push_back(prerequisite);
          }
      }
};

// Define the Node structure for the BST
struct Node {
    Course data;
    Node* left;
    Node* right;

    Node(Course course) : data(course), left(nullptr), right(nullptr) {}
};

// Define the CourseBST class
class CourseBST {
private: Node* root;

       Node* insertNode(Node* root, Course course) {
           if (root == nullptr) {
               root = new Node(course);
           }
           else if (course.courseNumber < root->data.courseNumber) {
               root->left = insertNode(root->left, course);
           }
           else if (course.courseNumber > root->data.courseNumber) {
               root->right = insertNode(root->right, course);
           }
           return root;
       }

       Course searchCourse(Node* root,
           const string& courseNumber) const {
           if (root == nullptr) {
               return Course();
           }

           // Convert both strings to lowercase for case-insensitive comparison
           string rootCourseNumber = root->data.courseNumber;
           transform(rootCourseNumber.begin(), rootCourseNumber.end(), rootCourseNumber.begin(), ::tolower);
           string inputCourseNumber = courseNumber;
           transform(inputCourseNumber.begin(), inputCourseNumber.end(), inputCourseNumber.begin(), ::tolower);

           if (rootCourseNumber == inputCourseNumber) {
               return root->data;
           }
           else if (inputCourseNumber < rootCourseNumber) {
               return searchCourse(root->left, courseNumber);
           }
           else {
               return searchCourse(root->right, courseNumber);
           }
       }

       void printInOrder(Node* root) const {
           if (root != nullptr) {
               printInOrder(root->left);
               cout << root->data.courseNumber << " " << root->data.courseName << endl;
               printInOrder(root->right);
           }
       }

public: CourseBST() : root(nullptr) {}

      void insertCourse(Course course) {
          root = insertNode(root, course);
      }

      void printCourses() const {
          printInOrder(root);
      }

      Course findCourse(const string& courseNumber) const {
          return searchCourse(root, courseNumber);
      }
};

void printCourse(const Course& course) {
    cout << "Course Number: " << course.courseNumber << endl;
    cout << "Course Name: " << course.courseName << endl;
    if (!course.prerequisites.empty()) {
        cout << "Prerequisites: ";
        for (size_t i = 0; i < course.prerequisites.size(); ++i) {
            cout << course.prerequisites[i];
            if (i < course.prerequisites.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

void loadCourseData(const string& filePath, CourseBST& courseBST) {
    ifstream inFile(filePath);
    if (!inFile) {
        cerr << "Unable to open file: " << filePath << endl;
        return; // // Allow user to try again if file could not be opened
    }

    // Read the first three bytes
    char bom[3];
    inFile.read(bom, 3);

    // Check if the BOM sequence matches
    bool hasBOM = (bom[0] == '\xEF' && bom[1] == '\xBB' && bom[2] == '\xBF');

    // Reset the file position to the beginning if a BOM is present
    if (hasBOM) {
        inFile.seekg(3);
    }
    else {
        // No BOM, so continue reading from the current position
        inFile.seekg(0);
    }
    string line;
    while (getline(inFile, line)) {
        Course course(line);
        courseBST.insertCourse(course);
    }
}

int main(int argc, char* argv[]) {
    string csvPath;
    if (argc == 2) {
        csvPath = argv[1];
    }
    else {
        csvPath = "course_data.csv"; // Default file name
    }

    CourseBST courseBST;
    int choice = 0;
    Course course;
    string courseNumber;

    cout << "Welcome to the course planner!" << endl;

    while (choice != 9) {
        cout << endl;
        cout << "Menu:" << endl;
        cout << "  1. Load Data Structure" << endl;
        cout << "  2. Print Course List" << endl;
        cout << "  3. Print Course" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            // Ignore invalid input
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');

            cerr << "Invalid input. Please enter a valid choice." << endl;
            continue;
        }

        cout << endl;

        switch (choice) {
        case 1:
            loadCourseData(csvPath, courseBST);
            break;
        case 2:
            courseBST.printCourses();
            break;
        case 3:
            cout << "Enter course number: ";
            cin >> courseNumber;

            course = courseBST.findCourse(courseNumber);
            if (!course.courseNumber.empty()) {
                printCourse(course);
            }
            else {
                cout << "Course " << courseNumber << " not found." << endl;
            }
            break;
        case 9:
            cout << "Thank you for using the course planner. Goodbye!" << endl;
            break;
        default:
            cerr << "Invalid choice." << endl;
            break;
        }
    }

    return 0;
}