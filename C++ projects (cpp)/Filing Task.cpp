#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

void listFiles(const string& path) {
    if (system(("dir \"" + path + "\" /A").c_str()) != 0) {
        cout << "Error: Path does not exist." << endl;
    }
}

bool createDirectory(const string& path) {
    if (system(("mkdir \"" + path + "\"").c_str()) != 0) {
        cout << "Error creating directory." << endl;
        return false;
    }
    cout << "Directory created successfully!" << endl;
    return true;
}

bool copyFile(const string& source, const string& destination) {
    ifstream src(source.c_str());
    ofstream dst(destination.c_str());

    if (!src || !dst) {
        cout << "Error opening files for copy." << endl;
        return false;
    }

    dst << src.rdbuf();

    cout << "File copied successfully!" << endl;
    return true;
}

bool moveFile(const string& source, const string& destination) {
    if (!copyFile(source, destination)) {
        return false;
    }

    if (remove(source.c_str()) != 0) {
        cout << "Error: Failed to delete source file after copy." << endl;
        return false;
    }

    cout << "File moved successfully!" << endl;
    return true;
}

int main() {
    string currentPath = ".";
    string command, argument;

    while (true) {
        cout << currentPath << " > ";
        getline(cin, command);

        if (command.empty()) {
            continue;
        }

        istringstream iss(command);
        iss >> command >> argument;

        if (command == "ls") {
            listFiles(currentPath);
        } else if (command == "cd") {
            if (argument.empty()) {
                cout << "Usage: cd <directory name>" << endl;
            } else {
                currentPath = argument;
            }
        } else if (command == "mkdir") {
            if (argument.empty()) {
                cout << "Usage: mkdir <directory name>" << endl;
            } else {
                createDirectory(argument);
            }
        } else if (command == "cp") {
            string source, destination;
            iss >> source >> destination;
            if (source.empty() || destination.empty()) {
                cout << "Usage: cp <source file> <destination file>" << endl;
            } else {
                copyFile(source, destination);
            }
        } else if (command == "mv") {
            string source, destination;
            iss >> source >> destination;
            if (source.empty() || destination.empty()) {
                cout << "Usage: mv <source file> <destination file>" << endl;
            } else {
                moveFile(source, destination);
            }
        } else if (command == "exit") {
            break;
        } else {
            cout << "Command not recognized." << endl;
        }
    }

    return 0;
}

