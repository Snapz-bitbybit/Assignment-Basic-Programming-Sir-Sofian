// Code made by Kadro
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Define the structure for users
struct User
{
    int id;
    string name;
    string personalityType;
    int score;
};

User users[100]; // Array to store users
int userCount = 0; // Counter for user entries
const string FILE_NAME = "users.txt"; // File to store user data

// Function prototypes
void readUsers();
void writeUsers();
void deleteUser();
void addUser();
void displayUsers();
int validateScore(const string &question, const string &scale);
void getUserFeedback(); // Prototype for the feedback function

// Function to read user data from a file
void readUsers()
{
    ifstream file(FILE_NAME);
    if (!file.is_open())
    {
        cout << "Error: Unable to open file for reading.\n";
        return;
    }
    userCount = 0;
    while (file >> users[userCount].id)
    {
        file.ignore();
        getline(file, users[userCount].name);
        getline(file, users[userCount].personalityType);
        file >> users[userCount].score;
        userCount++;
    }
    file.close();
}

// Function to write user data to a file
void writeUsers()
{
    ofstream file(FILE_NAME);
    if (!file.is_open())
    {
        cout << "Error: Unable to open file for writing.\n";
        return;
    }
    for (int i = 0; i < userCount; i++)
    {
        file << users[i].id << endl;
        file << users[i].name << endl;
        file << users[i].personalityType << endl;
        file << users[i].score << endl;
    }
    file.close();
}

// Function to delete a user
void deleteUser()
{
    int id;
    cout << "Enter User ID to delete (or type -1 to cancel): ";
    cin >> id;

    // Allow the user to cancel the operation
    if (id == -1)
    {
        cout << "Operation canceled. Returning to the menu.\n";
        return;
    }

    bool found = false; // Flag to indicate if the user was found
    for (int i = 0; i < userCount; i++)
    {
        if (users[i].id == id)
        {
            found = true;
            // Shift the remaining users to remove the deleted user
            for (int j = i; j < userCount - 1; j++)
            {
                users[j] = users[j + 1];
            }
            userCount--; // Decrease the user count
            writeUsers(); // Save the updated data to the file
            cout << "User deleted successfully!\n";
            return;
        }
    }
    // Display an error if the user ID is not found
    cout << "Error: User ID not found.\n";
}

// Function to validate the user's score for a question
int validateScore(const string &question, const string &scale)
{
    int response;
    cout << question << "\n" << scale << "\nResponse (or type -1 to cancel): ";
    cin >> response;

    // Allow the user to cancel the operation
    if (response == -1)
    {
        cout << "Operation canceled.\n";
        return -1;
    }

    // Validate the response to ensure it is between 1 and 5
    while (response < 1 || response > 5)
    {
        cout << "Invalid response. Please enter a number between 1 and 5: ";
        cin >> response;
    }
    return response; // Return the valid response
}

// Function to add a new user
void addUser()
{
    if (userCount >= 100)
    {
        cout << "Error: User limit reached.\n";
        return;
    }

    User newUser;
    cout << "Enter User ID (or type -1 to cancel): ";
    cin >> newUser.id;

    // Allow the user to cancel the operation
    if (newUser.id == -1)
    {
        cout << "Operation canceled. Returning to the menu.\n";
        return;
    }

    // Check if the ID already exists
    for (int i = 0; i < userCount; i++)
    {
        if (users[i].id == newUser.id)
        {
            cout << "Error: User ID already exists.\n";
            return;
        }
    }

    cin.ignore(); // Ignore leftover newline
    cout << "Enter User Name (or type 'exit' to cancel): ";
    getline(cin, newUser.name);

    // Allow the user to cancel the operation
    if (newUser.name == "exit")
    {
        cout << "Operation canceled. Returning to the menu.\n";
        return;
    }

    int totalScore = 0;
    string scale = "\n 1: Rarely\n 2: Occasionally\n 3: Sometimes\n 4: Often\n 5: Always\n";

    // Ask questions and calculate the total score
    totalScore += validateScore("1. Do you enjoy socializing?", scale);
    totalScore += validateScore("2. Are you comfortable planning ahead?", scale);
    totalScore += validateScore("3. Do you like solving problems?", scale);
    totalScore += validateScore("4. Do you feel energized by group activities?", scale);
    totalScore += validateScore("5. Are you quick to adapt to new environments?", scale);

    // Determine personality type based on the score
    if (totalScore <= 10)
    {
        newUser.personalityType = "Introvert";
    }
    else if (totalScore <= 20)
    {
        newUser.personalityType = "Ambivert";
    }
    else
    {
        newUser.personalityType = "Extrovert";
    }

    newUser.score = totalScore;
    users[userCount++] = newUser; // Add the user to the array
    writeUsers(); // Save user data to the file
    cout << "User added successfully!\n";
}

// Function to display all users
void displayUsers()
{
    if (userCount == 0)
    {
        cout << "No users found.\n";
        return;
    }

    // Sort users by ID in ascending order using a simple bubble sort
    for (int i = 0; i < userCount - 1; i++)
    {
        for (int j = 0; j < userCount - i - 1; j++)
        {
            if (users[j].id > users[j + 1].id)
            {
                // Swap the two users
                User temp = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp;
            }
        }
    }

    // Display the list of users in a formatted table
    cout << setw(10) << "ID" << setw(20) << "Name" << setw(15) << "Personality" << setw(10) << "Score" << endl;
    for (int i = 0; i < userCount; i++)
    {
        cout << setw(10) << users[i].id
             << setw(20) << users[i].name
             << setw(15) << users[i].personalityType
             << setw(10) << users[i].score << endl;
    }
}

// Function to collect user feedback
void getUserFeedback()
{
    cout << "\n***********************************\n";
    cout << "*   Welcome to the Feedback Section!   *\n";
    cout << "* Your input helps us improve our program. *\n";
    cout << "*   Please answer the following questions   *\n";
    cout << "***********************************\n";

    cout << "\nWe value your feedback! Please rate the following:\n";
    string scale = "\n 1: Poor\n 2: Fair\n 3: Good\n 4: Very Good\n 5: Excellent\n";
    int feedbackScores[5];

    string questions[5] = {
        "1. How satisfied are you with the program's functionality?",
        "2. How easy was it to use the system?",
        "3. How clear were the instructions and prompts?",
        "4. How likely are you to recommend this program to others? (Rate from 0 to 10)",
        "5. How satisfied are you with the overall experience?"
    };

    for (int i = 0; i < 5; i++)
    {
        if (i == 3) // Special handling for Question 4
        {
            int response;
            do
            {
                cout << questions[i] << "\nYour response: ";
                cin >> response;
                if (response < 0 || response > 10)
                {
                    cout << "Invalid input. Please enter a number between 0 and 10.\n";
                }
            } while (response < 0 || response > 10);
            feedbackScores[i] = response;
        }
        else
        {
            do
            {
                cout << questions[i] << scale << "\nYour response: ";
                cin >> feedbackScores[i];
                if (feedbackScores[i] < 1 || feedbackScores[i] > 5)
                {
                    cout << "Invalid input. Please enter a number between 1 and 5.\n";
                }
            } while (feedbackScores[i] < 1 || feedbackScores[i] > 5);
        }
    }

    // Display a thank-you message
    cout << "\nThank you for your feedback! It helps us improve.\n";

    // Optional: Save feedback to a file
    ofstream feedbackFile("feedback.txt", ios::app);
    if (feedbackFile.is_open())
    {
        feedbackFile << "Feedback Scores:\n";
        for (int i = 0; i < 5; i++)
        {
            feedbackFile << questions[i] << " - " << feedbackScores[i] << endl;
        }
        feedbackFile << "-----------------------------------\n";
        feedbackFile.close();
    }
    else
    {
        cout << "Error: Unable to save feedback to file.\n";
    }
}

// Main function
int main()
{
    system("color 3"); // Set the text color in the console

    // Display welcoming message
    cout << "***********************************\n";
    cout << "* Welcome to the Personality Test System *\n";
    cout << "* Manage and analyze user personalities  *\n";
    cout << "*          Made by Group G1              *\n";
    cout << "***********************************\n";

    readUsers(); // Load existing user data
    int choice;

    do
    {
        cout << "\n1. Add User\n2. Delete User\n3. Display Users\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addUser(); // Add a new user
            break;
        case 2:
            deleteUser(); // Delete a user
            break;
        case 3:
            displayUsers(); // Display all users
            break;
        case 4:
            cout << "Exiting program.\n"; // Exit the program
            getUserFeedback(); // Collect user feedback before exiting
            break;
        default:
            cout << "Invalid choice. Try again.\n"; // Handle invalid input
        }
    } while (choice != 4); // Continue until the user chooses to exit

    // Exit message
    cout << "Thank you for using the Personality Test System. Goodbye!\n";

    return 0;
}
