// RPG Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime> // For randomization
#include "Character.h" 
#include "Ogun.h"
#include "Orunmila.h"
#include "Osun.h"
#include "Sango.h"
#include <stdexcept>


using namespace std;

class ReturnToMainMenuException : public exception {
public:
    const char* what() const noexcept override {
        return "Return to Main Menu";
    }
};

Character* createCharacter(int characterType, const string& name) {
    switch (characterType) {
    case 1:
        return new Ogun(name);
    case 2:
        return new Sango(name);
    case 3:
        return new Orunmila(name);
    case 4:
        return new Osun(name);
    default:
        cerr << "Invalid character type. Defaulting to Ogun.\n";
        return new Ogun(name); // Default to Ogun if an invalid type is provided
    }
}


string getCharacterName(int characterType) {
    switch (characterType) {
    case 1:
        return "Ogun";
    case 2:
        return "Sango";
    case 3:
        return "Orunmila";
    case 4:
        return "Osun";
    default:
        cerr << "Invalid character type. Defaulting to Ogun.\n";
        return "Ogun"; // Default to Ogun if an invalid type is provided
    }
}


// Function to display the menu and get user input
int displayMenu() {
    int choice;
    std::cout << R"(
                                                                                   
                            /      \  /      \         /  |                                                       
                           /$$$$$$  |/$$$$$$  |______  $$/   _______   ______   _______                           
                            $$ |__$$ |$$ |_ $$//      \ /  | /       | /      \ /       \                          
                            $$    $$ |$$   |  /$$$$$$  |$$ |/$$$$$$$/  $$$$$$  |$$$$$$$  |                         
                            $$$$$$$$ |$$$$/   $$ |  $$/ $$ |$$ |       /    $$ |$$ |  $$ |                         
                            $$ |  $$ |$$ |    $$ |      $$ |$$ \_____ /$$$$$$$ |$$ |  $$ |                         
                            $$ |  $$ |$$ |    $$ |      $$ |$$       |$$    $$ |$$ |  $$ |                         
                            $$/   $$/ $$/     $$/       $$/  $$$$$$$/  $$$$$$$/ $$/   $$/                          
                                                                                       
                                                                                       
                                                                                       
                __       __              __      __                  __                               
               /  \     /  |            /  |    /  |                /  |                              
               $$  \   /$$ | __    __  _$$ |_   $$ |____    ______  $$ |  ______    ______   __    __ 
               $$$  \ /$$$ |/  |  /  |/ $$   |  $$      \  /      \ $$ | /      \  /      \ /  |  /  |
               $$$$  /$$$$ |$$ |  $$ |$$$$$$/   $$$$$$$  |/$$$$$$  |$$ |/$$$$$$  |/$$$$$$  |$$ |  $$ |
               $$ $$ $$/$$ |$$ |  $$ |  $$ | __ $$ |  $$ |$$ |  $$ |$$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |
               $$ |$$$/ $$ |$$ \__$$ |  $$ |/  |$$ |  $$ |$$ \__$$ |$$ |$$ \__$$ |$$ \__$$ |$$ \__$$ |
               $$ | $/  $$ |$$    $$ |  $$  $$/ $$ |  $$ |$$    $$/ $$ |$$    $$/ $$    $$ |$$    $$ |
               $$/      $$/  $$$$$$$ |   $$$$/  $$/   $$/  $$$$$$/  $$/  $$$$$$/   $$$$$$$ | $$$$$$$ |
                            /  \__$$ |                                            /  \__$$ |/  \__$$ |
                             $$    $$/                                             $$    $$/ $$    $$/ 
                              $$$$$$/                                               $$$$$$/   $$$$$$/  


                                 __       __                                                                           
                                /  \     /  |                                                                          
                                $$  \   /$$ | __    __   ______    ______   _______                                    
                                $$$  \ /$$$ |/  |  /  | /      \  /      \ /       \                                   
                                $$$$  /$$$$ |$$ |  $$ |/$$$$$$  |/$$$$$$  |$$$$$$$  |                                  
                                $$ $$ $$/$$ |$$ |  $$ |$$ |  $$ |$$    $$ |$$ |  $$ |                                  
                                $$ |$$$/ $$ |$$ \__$$ |$$ \__$$ |$$$$$$$$/ $$ |  $$ |                                  
                                $$ | $/  $$ |$$    $$/ $$    $$ |$$       |$$ |  $$ |                                  
                                $$/      $$/  $$$$$$/   $$$$$$$ | $$$$$$$/ $$/   $$/                                   
                                                       /  \__$$ |                                                      
                                                       $$    $$/                                                       
                                                        $$$$$$/                                                        
    
)";

   cout << endl;
   cout << endl;
   cout << setw(65) << "Menu:\n";
   cout << setw(73) << "1. Start a new game\n";
   cout << setw(74) << "2. Continue a saved game\n";
   cout << setw(65) << "3. Exit\n";
   cout << endl;
   cout << setw(75) << "Enter your choice (1-3): ";
   cin >> choice;
    return choice;
}


void OgunperformTurn(Character& currentPlayer, Character& opponent){

    cout << "\n" << currentPlayer.getName() << "'s turn!\n";
    cout << "1. Shield Bash\n";
    cout << "2. Taunt\n";
    cout << "3. Defence Overload\n";
    cout << "4. Iron Slash\n";
    cout << "5. Use Mana to Heal\n";
    cout << "6. Rest\n";
    cout << "7. Back to menu\n";
    cout << "8. Save game\n";

    int choice;
    cout << "Enter your choice (1-8): ";
    cin >> choice;
    string fileName;

    Ogun* ogunPlayer = dynamic_cast<Ogun*>(&currentPlayer);
    if (ogunPlayer) {
        // currentPlayer is indeed an instance of Ogun
        string fileName;
        switch (choice) {
        case 1:
            ogunPlayer->ShieldBash(opponent);
            break;
        case 2:
            ogunPlayer->Taunt(opponent);
            break;
        case 3:
            ogunPlayer->DefenceOverload();
            break;
        case 4:
            ogunPlayer->IronSlash(opponent);
            break;
        case 5:
            ogunPlayer->useManaToHeal();
            break;
        case 6:
            ogunPlayer->rest();
            break;
        case 7:
            cout << "Returning to main menu\n";
            throw ReturnToMainMenuException();
        case 8:
            cout << "Enter Name of file:\n";
            cin >> fileName;
            ogunPlayer->SaveToFile(fileName);
            break;
        default:
            cout << "Invalid choice!\n";
        }
    }
    else {
        cout << "Invalid player type for this action!\n";
    }

}



void SangoperformTurn(Character& currentPlayer, Character& opponent) {
    cout << "\n" << currentPlayer.getName() << "'s turn!\n";
    cout << "1. Lightning Kick\n";
    cout << "2. Lightning Punch\n";
    cout << "3. Berserk\n";
    cout << "4. Lightning Arnament\n";
    cout << "5. Use Mana to Heal\n";
    cout << "6. Rest\n";
    cout << "7. Return to main menu\n";
    cout << "8. Save game.\n";

    int choice;
    cout << "Enter your choice (1-8): ";
    cin >> choice;

    Sango* sangoPlayer = dynamic_cast<Sango*>(&currentPlayer);
    if (sangoPlayer) {
        // currentPlayer is indeed an instance of Sango
        string fileName;
        switch (choice) {
        case 1:
            sangoPlayer->LightningKick(opponent);
            break;
        case 2:
            sangoPlayer->LightningPunch(opponent);
            break;
        case 3:
            sangoPlayer->Berserk(opponent);
            break;
        case 4:
            sangoPlayer->LightningArmament(opponent);
            break;
        case 5:
            sangoPlayer->useManaToHeal();
            break;
        case 6:
            sangoPlayer->rest();
            break;
        case 7:
            cout << "Returning to main menu\n";
            throw ReturnToMainMenuException();
        case 8:
            cout << "Enter Name of file:\n";
            cin >> fileName;
            sangoPlayer->SaveToFile(fileName);
            break;
        default:
            cout << "Invalid choice!\n";
        }
    }
    else {
        cout << "Invalid player type for this action!\n";
    }

}



void OsunperformTurn(Character& currentPlayer, Character& opponent) {
    cout << "\n" << currentPlayer.getName() << "'s turn!\n";
    cout << "1. WaterBall\n";
    cout << "2. Hell Raise\n";
    cout << "3. Divination\n";
    cout << "4. Water Burial\n";
    cout << "5. Use Mana to Heal\n";
    cout << "6. Rest\n";
    cout << "7. Return to main menu\n";
    cout << "8. Save game.\n";

    int choice;
    cout << "Enter your choice (1-8): ";
    cin >> choice;

    Osun* osunPlayer = dynamic_cast<Osun*>(&currentPlayer);
    if (osunPlayer) {
        // currentPlayer is indeed an instance of Osun
        string fileName;
        switch (choice) {
        case 1:
            osunPlayer->WaterBall(opponent);
            break;
        case 2:
            osunPlayer->HellRaise(opponent);
            break;
        case 3:
            osunPlayer->Divination();
            break;
        case 4:
            osunPlayer->WaterBurial(opponent);
            break;
        case 5:
            osunPlayer->useManaToHeal();
            break;
        case 6:
            osunPlayer->rest();
            break;
        case 7:
            cout << "Returning to main menu\n";
            throw ReturnToMainMenuException();
        case 8:
            cout << "Enter Name of file:\n";
            cin >> fileName;
            osunPlayer->SaveToFile(fileName);
            break;
        default:
            cout << "Invalid choice!\n";
        }
    }
    else {
        cout << "Invalid player type for this action!\n";
    }

}



void OrunmilaperformTurn(Character& currentPlayer, Character& opponent) {
    cout << "\n" << currentPlayer.getName() << "'s turn!\n";
    cout << "1. FireBall\n";
    cout << "2. Sky Fall\n";
    cout << "3. Divination\n";
    cout << "4. Earth Burial\n";
    cout << "5. Use Mana to Heal\n";
    cout << "6. Rest\n";
    cout << "7. Return to main menu\n";
    cout << "8. Save game.\n";

    int choice;
    cout << "Enter your choice (1-8): ";
    cin >> choice;

    Orunmila* orunmilaPlayer = dynamic_cast<Orunmila*>(&currentPlayer);
    if (orunmilaPlayer) {
        // currentPlayer is indeed an instance of Osun
        string fileName;
        switch (choice) {
        case 1:
            orunmilaPlayer->FireBall(opponent);
            break;
        case 2:
            orunmilaPlayer->skyFall(opponent);
            break;
        case 3:
            orunmilaPlayer->Divination();
            break;
        case 4:
            orunmilaPlayer->EarthBurial(opponent);
            break;
        case 5:
            orunmilaPlayer->useManaToHeal();
            break;
        case 6:
            orunmilaPlayer->rest();
            break;
        case 7:
            cout << "Returning to main menu\n";
            throw ReturnToMainMenuException();
        case 8:
            cout << "Enter Name of file:\n";
            cin >> fileName;
            orunmilaPlayer->SaveToFile(fileName);
            break;
        default:
            cout << "Invalid choice!\n";
        }
    }
    else {
        cout << "Invalid player type for this action!\n";
    }

}


// Function to simulate the game
void playGame(Character& player1, Character& player2) {
    // Game initialization logic (e.g., random starting attributes)
    // ...
    

    int num1;
    int num2;

    cout << "\n1. Ogun(shield user)\n2. Sango(warrior)\n3. Orunmila(wizard)\n4. Osun(wizard)\n";
    cout << "Select your character type (1-4)(pick the same # as your first choice): ";
    cin >> num1;
    
    cout << "\n1. Ogun(shield user)\n2. Sango(warrior)\n3. Orunmila(wizard)\n4. Osun(wizard)\n";
    cout << "Select your character type (1-4)(pick the same # as your first choice): ";
    cin >> num2;

    string p1 = getCharacterName(num1);
    string p2 = getCharacterName(num2);

    // Main game loop
    while (player1.getHealth() > 0 && player2.getHealth() > 0) {
        
        // Allow the first player to take their turn
        if (p1 == "Ogun") {
            try {
                OgunperformTurn(player1, player2);
            }
            catch (const ReturnToMainMenuException&) {
                cout << "\nReturned to the main menu.\n";
                return;
            }
        }

        else if (p1 == "Sango") {
            try {
                SangoperformTurn(player1, player2);
            }
            catch (const ReturnToMainMenuException&) {
                cout << "\nReturned to the main menu.\n";
                return;
            }
        }

        else if (p1 == "Osun") {
            try {
                OsunperformTurn(player1, player2);
            }
            catch (const ReturnToMainMenuException&) {
                cout << "\nReturned to the main menu.\n";
                return;
            }
        }

        else if (p1 == "Orunmila") {
            try {
                OrunmilaperformTurn(player1, player2);
            }
            catch (const ReturnToMainMenuException&) {
                cout << "\nReturned to the main menu.\n";
                return;
            }
        }

        cout << endl;

        // Check if the game should continue after the first player's turn
        if (player2.getHealth() <= 0) {
            cout << "Player 1" << " wins!" << endl;
            break;
        }

        // Allow the second player to take their turn
        if (p2 == "Ogun") {
            try {
                OgunperformTurn(player2, player1);
            }
            catch (const ReturnToMainMenuException&) {
                cout << "\nReturned to the main menu.\n";
                return;
            }
        }

        else if (p2 == "Sango") {
            try {
                SangoperformTurn(player2, player1);
            }
            catch (const ReturnToMainMenuException&) {
                cout << "\nReturned to the main menu.\n";
                return;
            }
        }

        else if (p2 == "Osun") {
            try {
                OsunperformTurn(player2, player1);
            }
            catch (const ReturnToMainMenuException&) {
                cout << "\nReturned to the main menu.\n";
                return;
            }
        }

        else if (p2 == "Orunmila") {
            try {
                OrunmilaperformTurn(player2, player1);
            }
            catch (const ReturnToMainMenuException&) {
                cout << "\nReturned to the main menu.\n";
                return;
            }
        }

        cout << endl;

        // Check if the game should continue after the second player's turn
        if (player1.getHealth() <= 0) {
            cout << "\nPlayer 2" << " wins!" << endl;
            break;
        }
    }

}


int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for randomization

    // Main menu loop
    while (true) {
        int menuChoice = displayMenu();

        switch (menuChoice) {
        case 1: // Start a new game
        {
            string name1, name2;
            int type1, type2;

            cout << "\nPlayer 1, enter your name: \n";
            cin >> name1;
            cout << "\n1. Ogun(shield user)\n2. Sango(warrior)\n3. Orunmila(wizard)\n4. Osun(wizard)\n";
            cout << "Select your character type (1-4): ";
            cin >> type1;

            cout << "\nPlayer 2, enter your name: ";
            cin >> name2;
            cout << "\n1. Ogun(shield user)\n2. Sango(warrior)\n3. Orunmila(wizard)\n4. Osun(wizard)\n";
            cout << "Select your character type (1-4): ";
            cin >> type2;

            // Create characters based on user input
            Character* player1 = createCharacter(type1, name1);
            Character* player2 = createCharacter(type2, name2);

            // Play the game
            playGame(*player1, *player2);


            // Free allocated memory
            delete player1;
            delete player2;
        }
        break;

        case 2: // Continue a saved game
        {
            string fileName;
            string filename;

            cout << "Enter the name of your saved game Player 1: ";
            cin >> fileName;

            cout << "Enter the name of your saved game Player 2: ";
            cin >> filename;

            // Load the characters and game state from the file
            // For simplicity, assume there's a function loadGameFromFile
            Character* player1 = Character::LoadFromFile(fileName);
            Character* player2 = Character::LoadFromFile(filename);

            // Play the game
            if (player1 && player2) {  // Check if loading was successful
                // Play the game
                cout << "\nWelcome back " << player1->getName() << endl;
                cout << "Welcome back " << player2->getName() << endl;
                playGame(*player1, *player2);

                delete player1;
                delete player2;
            }
            else {
                std::cerr << "Error loading characters from files.\n";
            }
        }
        break;

        case 3: // Exit
            cout << "Exiting the game. Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 3.\n";
        }
    }

    return 0;
}


