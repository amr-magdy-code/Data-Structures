#include <iostream>
#include <string>
using namespace std;

// ======================= TEAM STRUCT =======================
class Team {
public:
    int id;
    string name;
    string president;
    Team* next;
};

// ======================= PLAYER STRUCT =======================
class Player {
public:
    int id;
    string name;
    string teamName;
    string position;
    int age;
    double salary;
    Player* next;
};

// ====== HEAD POINTERS ======
Team* teamHead = NULL;
Player* playerHead = NULL;

// ======================= TEAM FUNCTIONS =======================

// Add new team
void addTeam() {
    Team* newTeam = new Team();

    cout << "Enter Team ID: ";
    cin >> newTeam->id;
    cin.ignore();

    cout << "Enter Team Name: ";
    getline(cin, newTeam->name);

    cout << "Enter Team President: ";
    getline(cin, newTeam->president);

    newTeam->next = NULL;

    if (teamHead == NULL) {
        teamHead = newTeam;
    }
    else {
        Team* temp = teamHead;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newTeam;
    }

    cout << "\nTeam added successfully!\n";
}

// Display teams
void displayTeams() {
    if (teamHead == NULL) {
        cout << "No teams available.\n";
        return;
    }

    Team* temp = teamHead;
    while (temp != NULL) {
        cout << "\n--- Team Info ---\n";
        cout << "ID: " << temp->id << endl;
        cout << "Name: " << temp->name << endl;
        cout << "President: " << temp->president << endl;
        temp = temp->next;
    }
}

// Search team by ID
Team* searchTeam(int id) {
    Team* temp = teamHead;
    while (temp != NULL) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// Update team info
void updateTeam() {
    int id;
    cout << "Enter Team ID to update: ";
    cin >> id;

    Team* team = searchTeam(id);

    if (team == NULL) {
        cout << "Team not found.\n";
        return;
    }

    cin.ignore();
    cout << "Enter new name: ";
    getline(cin, team->name);

    cout << "Enter new president: ";
    getline(cin, team->president);

    cout << "\nTeam updated successfully!\n";
}

// ======================= PLAYER FUNCTIONS =======================

// Add new player
void addPlayer() {
    Player* newPlayer = new Player();

    cout << "Enter Player ID: ";
    cin >> newPlayer->id;
    cin.ignore();

    cout << "Enter Player Name: ";
    getline(cin, newPlayer->name);

    cout << "Enter Team Name: ";
    getline(cin, newPlayer->teamName);

    cout << "Enter Position: ";
    getline(cin, newPlayer->position);

    cout << "Enter Age: ";
    cin >> newPlayer->age;

    cout << "Enter Salary: ";
    cin >> newPlayer->salary;

    newPlayer->next = NULL;

    if (playerHead == NULL) {
        playerHead = newPlayer;
    }
    else {
        Player* temp = playerHead;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newPlayer;
    }

    cout << "\nPlayer added successfully!\n";
}

// Remove player by ID
void removePlayer() {
    if (playerHead == NULL) {
        cout << "No players to remove.\n";
        return;
    }

    int pid;
    cout << "Enter Player ID to remove: ";
    cin >> pid;

    Player* temp = playerHead;
    Player* prev = NULL;

    if (temp != NULL && temp->id == pid) {
        playerHead = temp->next;
        delete temp;
        cout << "Player removed.\n";
        return;
    }

    while (temp != NULL && temp->id != pid) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Player not found.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;

    cout << "Player removed.\n";
}

// Display all players
void displayPlayers() {
    if (playerHead == NULL) {
        cout << "No players available.\n";
        return;
    }

    Player* temp = playerHead;
    while (temp != NULL) {
        cout << "\n--- Player Info ---\n";
        cout << "ID: " << temp->id << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Team: " << temp->teamName << endl;
        cout << "Position: " << temp->position << endl;
        cout << "Age: " << temp->age << endl;
        cout << "Salary: " << temp->salary << endl;
        temp = temp->next;
    }
}

// Search player by name
void searchPlayerByName() {
    cin.ignore();
    string name;
    cout << "Enter Player Name: ";
    getline(cin, name);

    Player* temp = playerHead;
    while (temp != NULL) {
        if (temp->name == name) {
            cout << "\nPlayer Found:\n";
            cout << "ID: " << temp->id << endl;
            cout << "Team: " << temp->teamName << endl;
            cout << "Position: " << temp->position << endl;
            cout << "Age: " << temp->age << endl;
            cout << "Salary: " << temp->salary << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Player not found.\n";
}

// ======================= NEW FEATURE 1 =======================
// Display players of a team ordered by salary
void displayPlayersOfTeamSortedBySalary() {
    cin.ignore();
    string team;
    cout << "Enter Team Name: ";
    getline(cin, team);

    int count = 0;
    Player* temp = playerHead;
    while (temp != NULL) {
        if (temp->teamName == team)
            count++;
        temp = temp->next;
    }

    if (count == 0) {
        cout << "No players found for this team.\n";
        return;
    }

    Player** arr = new Player * [count];
    temp = playerHead;
    int i = 0;

    while (temp != NULL) {
        if (temp->teamName == team)
            arr[i++] = temp;
        temp = temp->next;
    }

    for (int a = 0; a < count - 1; a++) {
        for (int b = a + 1; b < count; b++) {
            if (arr[a]->salary < arr[b]->salary) {
                Player* t = arr[a];
                arr[a] = arr[b];
                arr[b] = t;
            }
        }
    }

    cout << "\nPlayers of " << team << " (Sorted by Salary):\n";
    for (int j = 0; j < count; j++) {
        cout << arr[j]->name << " | Salary: " << arr[j]->salary << endl;
    }

    delete[] arr;
}

// ======================= NEW FEATURE 2 =======================
// Display teams ordered by average age
void displayTeamsOrderedByAverageAge() {
    if (teamHead == NULL) {
        cout << "No teams available.\n";
        return;
    }

    int T = 0;
    Team* t = teamHead;
    while (t != NULL) {
        T++;
        t = t->next;
    }

    struct TeamAge {
        Team* team;
        double avgAge;
    };

    TeamAge* arr = new TeamAge[T];
    t = teamHead;
    int idx = 0;

    while (t != NULL) {
        int totalAge = 0, count = 0;

        Player* p = playerHead;
        while (p != NULL) {
            if (p->teamName == t->name) {
                totalAge += p->age;
                count++;
            }
            p = p->next;
        }

        arr[idx].team = t;
        arr[idx].avgAge = (count == 0 ? 0 : (double)totalAge / count);
        idx++;

        t = t->next;
    }

    for (int i = 0; i < T - 1; i++) {
        for (int j = i + 1; j < T; j++) {
            if (arr[i].avgAge < arr[j].avgAge) {
                TeamAge temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "\nTeams ordered by Average Age:\n";
    for (int i = 0; i < T; i++) {
        cout << arr[i].team->name << " | Average Age: " << arr[i].avgAge << endl;
    }

    delete[] arr;
}

// ======================= NEW FEATURE 3 =======================
// Remove team + remove all its players
void removeTeam() {
    if (teamHead == NULL) {
        cout << "No teams to remove.\n";
        return;
    }

    int id;
    cout << "Enter Team ID to remove: ";
    cin >> id;

    Team* temp = teamHead;
    Team* prev = NULL;

    if (temp != NULL && temp->id == id) {
        string teamName = temp->name;

        Player* p = playerHead;
        Player* prevP = NULL;

        while (p != NULL) {
            if (p->teamName == teamName) {
                if (p == playerHead) {
                    playerHead = p->next;
                    delete p;
                    p = playerHead;
                }
                else {
                    prevP->next = p->next;
                    delete p;
                    p = prevP->next;
                }
            }
            else {
                prevP = p;
                p = p->next;
            }
        }

        teamHead = temp->next;
        delete temp;

        cout << "Team and its players removed.\n";
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Team not found.\n";
        return;
    }

    string teamName = temp->name;

    Player* p = playerHead;
    Player* prevP = NULL;

    while (p != NULL) {
        if (p->teamName == teamName) {
            if (p == playerHead) {
                playerHead = p->next;
                delete p;
                p = playerHead;
            }
            else {
                prevP->next = p->next;
                delete p;
                p = prevP->next;
            }
        }
        else {
            prevP = p;
            p = p->next;
        }
    }

    prev->next = temp->next;
    delete temp;

    cout << "Team and its players removed.\n";
}

// ======================= MENU =======================
void menu() {
    int choice;

    while (true) {
        cout << "\n\n===== Egyptian League Management System =====\n";
        cout << "1. Add Team\n";
        cout << "2. Display Teams\n";
        cout << "3. Search Team by ID\n";
        cout << "4. Add Player\n";
        cout << "5. Remove Player\n";
        cout << "6. Display Players\n";
        cout << "7. Search Player by Name\n";
        cout << "8. Update Team Info\n";
        cout << "9. Display Players of a Team (Sorted by Salary)\n";
        cout << "10. Display Teams (Ordered by Average Age)\n";
        cout << "11. Remove Team\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1: addTeam(); break;
        case 2: displayTeams(); break;
        case 3:
            int id;
            cout << "Enter Team ID: ";
            cin >> id;
            if (searchTeam(id)) cout << "Team Found!\n";
            else cout << "Team Not Found.\n";
            break;
        case 4: addPlayer(); break;
        case 5: removePlayer(); break;
        case 6: displayPlayers(); break;
        case 7: searchPlayerByName(); break;
        case 8: updateTeam(); break;
        case 9: displayPlayersOfTeamSortedBySalary(); break;
        case 10: displayTeamsOrderedByAverageAge(); break;
        case 11: removeTeam(); break;
        case 0: return;
        default: cout << "Invalid choice!\n";
        }
    }
}

// ======================= MAIN =======================
int main() {
    menu();
    return 0;
}
