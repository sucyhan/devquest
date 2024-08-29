#include <iostream>
#include <map>
#include <algorithm> // for std::max
using namespace std;

struct Player
{
    int frontendPoints = 0;
    int backendPoints = 0;
    int devopsPoints = 0;
    int dataPoints = 0;
    string developerType;
    int firstChoice;
    int secondChoice;
};

enum Path
{
    FLEXBOX_FOREST = 1,
    ENDPOINT_MOUNTAINS,
    CAVERN_DOCKERSTONE,
    SCHEMA_SANCTUM
};

enum FrontendFirstChoice
{
    GRID = 1,
    MANUAL,
    LARGEST_ONLY
};

enum BackendFirstChoice
{
    INDEXES = 1,
    NOSQL,
    SEARCH
};

enum DevOpsFirstChoice
{
    JENKINS = 1,
    MANUAL_DEPLOY,
    GITHUB_ACTIONS
};

enum DataFirstChoice
{
    PANDAS = 1,
    MANUAL_CORRECT,
    CUSTOM_SCRIPT
};

void introduction()
{
    cout << "Welcome to the DevQuest, a world where code is magic, and developers are heroes." << endl;
    cout << "Your adventure begins now. Face unique challenges and discover your true developer identity." << endl;
    cout << "Let the adventure begin!" << endl;
}

void displayChoices(const string &prompt, const map<int, string> &choices)
{
    cout << prompt << endl;
    for (const auto &choice : choices)
    {
        cout << choice.first << ". " << choice.second << endl;
    }
}

void firstChoice(Player &player)
{
    map<int, string> paths = {
        {FLEXBOX_FOREST, "Flexbox Forest"},
        {ENDPOINT_MOUNTAINS, "Endpoint Mountains"},
        {CAVERN_DOCKERSTONE, "Cavern of Dockerstone"},
        {SCHEMA_SANCTUM, "Schema Sanctum"}};

    displayChoices("You arrive in a town with four paths. Which path will you choose?", paths);

    int choice;
    cin >> choice;

    switch (choice)
    {
    case FLEXBOX_FOREST:
        player.frontendPoints += 10;
        break;
    case ENDPOINT_MOUNTAINS:
        player.backendPoints += 10;
        break;
    case CAVERN_DOCKERSTONE:
        player.devopsPoints += 10;
        break;
    case SCHEMA_SANCTUM:
        player.dataPoints += 10;
        break;
    default:
        cout << "You hesitate and stand still. The path you were on fades away, and you are lost in the Digital Realm..." << endl;
        break;
    }
    player.firstChoice = choice;
}

void frontendFirstChallenge(Player &player)
{
    map<int, string> choices = {
        {GRID, "Use a responsive grid system like Flexbox or CSS Grid"},
        {MANUAL, "Create different layouts for each type of creature manually"},
        {LARGEST_ONLY, "Focus only on the largest creatures and let others adapt as best they can"}};

    cout << "You step into the Flexbox Forest, where trees and vines shift with the breeze. The guardian challenges you to design the layout for an upcoming festival that must fit all the creatures of the realm, from tiny sprites to mighty dragons." << endl;
    cout << "How will you ensure that the festival grounds adapt perfectly to every size and shape?" << endl;
    displayChoices("", choices);

    int choice;
    cin >> choice;

    switch (choice)
    {
    case GRID:
        player.frontendPoints += 10;
        break;
    case MANUAL:
        player.frontendPoints += 5;
        player.backendPoints += 2;
        break;
    case LARGEST_ONLY:
        player.frontendPoints += 2;
        player.backendPoints += 3;
        break;
    default:
        cout << "The guardian is waiting for your answer. What do you do?" << endl;
        break;
    }
    player.secondChoice = choice;
}

void backendFirstChallenge(Player &player)
{
    map<int, string> choices = {
        {INDEXES, "Create indexes on frequently searched columns"},
        {NOSQL, "Migrate to a NoSQL database"},
        {SEARCH, "Perform a full-text search in the database manually"}};

    cout << "Deep within the mountains lies the Library of Logic, where the most powerful algorithms and databases are kept. A stern wizard, the keeper of the library, challenges you to optimize a slow-running spell (database query)." << endl;
    cout << "The library’s knowledge grows endlessly, and the retrieval of wisdom (data) is becoming slower. How will you ensure that the knowledge is accessed swiftly by all who seek it?" << endl;
    displayChoices("", choices);

    int choice;
    cin >> choice;

    switch (choice)
    {
    case INDEXES:
        player.backendPoints += 10;
        break;
    case NOSQL:
        player.backendPoints += 8;
        player.dataPoints += 2;
        break;
    case SEARCH:
        player.backendPoints += 6;
        player.dataPoints += 4;
        break;
    default:
        cout << "The keeper of the library awaits your decision. What will you choose?" << endl;
        break;
    }
    player.secondChoice = choice;
}

void devopsFirstChallenge(Player &player)
{
    map<int, string> choices = {
        {JENKINS, "Set up a Jenkins pipeline for continuous integration and delivery"},
        {MANUAL_DEPLOY, "Deploy manually to maintain control"},
        {GITHUB_ACTIONS, "Use GitHub Actions for a more integrated approach"}};

    cout << "You enter the Cavern of Dockerstone, where the DevOps dragons test the stability of their infrastructure. The lead dragon challenges you to set up a robust deployment pipeline for a new application." << endl;
    cout << "How will you ensure continuous integration and deployment in this ever-changing environment?" << endl;
    displayChoices("", choices);

    int choice;
    cin >> choice;

    switch (choice)
    {
    case JENKINS:
        player.devopsPoints += 10;
        break;
    case MANUAL_DEPLOY:
        player.devopsPoints += 2;
        player.backendPoints += 4;
        break;
    case GITHUB_ACTIONS:
        player.devopsPoints += 8;
        player.backendPoints += 2;
        break;
    default:
        cout << "The dragons are waiting for your choice. What will you do?" << endl;
        break;
    }
    player.secondChoice = choice;
}

void dataFirstChallenge(Player &player)
{
    map<int, string> choices = {
        {PANDAS, "Use Python’s pandas library to clean and preprocess the data"},
        {MANUAL_CORRECT, "Manually correct the data in a spreadsheet"},
        {CUSTOM_SCRIPT, "Write a custom script to automate the cleaning process"}};

    cout << "In the Schema Sanctum, you find a vast array of data scrolls. The Data Sorcerer challenges you to clean and prepare this data for a grand analysis." << endl;
    cout << "How will you approach the task of cleaning and preprocessing the data?" << endl;
    displayChoices("", choices);

    int choice;
    cin >> choice;

    switch (choice)
    {
    case PANDAS:
        player.dataPoints += 10;
        break;
    case MANUAL_CORRECT:
        player.dataPoints += 4;
        player.backendPoints += 2;
        break;
    case CUSTOM_SCRIPT:
        player.dataPoints += 8;
        player.backendPoints += 2;
        break;
    default:
        cout << "The Data Sorcerer awaits your decision. Choose wisely!" << endl;
        break;
    }
    player.secondChoice = choice;
}

void calculateDeveloperType(Player &player)
{
    if (player.frontendPoints > max({player.backendPoints, player.devopsPoints, player.dataPoints}))
        player.developerType = "Frontend Sorcerer";
    else if (player.backendPoints > max({player.frontendPoints, player.devopsPoints, player.dataPoints}))
        player.developerType = "Backend Wizard";
    else if (player.devopsPoints > max({player.frontendPoints, player.backendPoints, player.dataPoints}))
        player.developerType = "DevOps Guru";
    else if (player.dataPoints > max({player.frontendPoints, player.backendPoints, player.devopsPoints}))
        player.developerType = "Data Sorcerer";
    else
        player.developerType = "Full Stack Developer";
}

void revealDeveloperType(Player &player)
{
    cout << "Congratulations! You are a " << player.developerType << "!" << endl;

    map<string, string> descriptions = {
        {"Frontend Sorcerer", "You wield the power of the web, shaping the user experience with your spells."},
        {"Backend Wizard", "You are the guardian of the server, protecting the realm from bugs and glitches."},
        {"DevOps Guru", "You are the master of deployment, ensuring the realm runs smoothly and efficiently."},
        {"Data Sorcerer", "You seek the truth in the data, uncovering hidden insights and knowledge."},
        {"Full Stack Developer", "You are a master of all trades, wielding the power of both frontend and backend magic."}};

    cout << descriptions[player.developerType] << endl;
}

int main()
{
    Player player;
    introduction();
    cout << endl;
    firstChoice(player);
    cout << endl;

    switch (player.firstChoice)
    {
    case FLEXBOX_FOREST:
        frontendFirstChallenge(player);
        break;
    case ENDPOINT_MOUNTAINS:
        backendFirstChallenge(player);
        break;
    case CAVERN_DOCKERSTONE:
        devopsFirstChallenge(player);
        break;
    case SCHEMA_SANCTUM:
        dataFirstChallenge(player);
        break;
    default:
        cout << "You stand at a crossroads, unsure of where to go. The path to discovery remains unclear." << endl;
        break;
    }

    calculateDeveloperType(player);
    revealDeveloperType(player);

    return 0;
}
