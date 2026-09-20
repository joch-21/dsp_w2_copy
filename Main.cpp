#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Item.h"

int main() {
    cout << "========================================\n";
    cout << "   TESTING BASE & DERIVED ENTITIES      \n";
    cout << "========================================\n\n";

    // 1. Test Default Constructor
    cout << "--- 1. Testing Default Constructor (Player) ---\n";
    Player defaultPlayer;
    cout << "ID: " << defaultPlayer.GetID() << "\n";
    cout << "Position: (" << defaultPlayer.GetPosition().x << ", "
        << defaultPlayer.GetPosition().y << ")\n";
    cout << "HP: " << defaultPlayer.GetCurrentHP() << "/" << defaultPlayer.GetMaxHP() << "\n";
    cout << "Lives: " << defaultPlayer.GetLives() << "\n\n";

    // 2. Test Overloaded Constructor & Accessors (Getters/Setters)
    cout << "--- 2. Testing Overloaded Constructor & Accessors ---\n";
    Position heroPos = { 10, 15 };
    Player hero("Knight_Artorias", heroPos, 150, 120, 25, 5, 0);

    cout << "Original Name: " << hero.GetID() << "\n";
    hero.SetID("Ashen_One"); // Test Setter
    cout << "Updated Name (Setter): " << hero.GetID() << "\n";

    hero.SetPosition({ 12, 18 });
    cout << "New Pos: (" << hero.GetPosition().x << ", " << hero.GetPosition().y << ")\n";
    hero.GainXP(250);
    cout << "\n";

    // 3. Test Enemy Derived Class
    cout << "--- 3. Testing Enemy Class ---\n";
    Enemy boss("Dungeon_Dragon", { 50, 50 }, 500, 500, 45, 12, "Aggressive");
    cout << "Boss ID: " << boss.GetID() << " | Attack: " << boss.GetAttack() << "\n";
    cout << "Aggro Range: " << boss.GetAggroRange() << "\n";
    boss.Patrol();
    cout << "\n";

    // 4. Test Item Derived Class
    cout << "--- 4. Testing Item Class ---\n";
    Item potion("Super_Elixir", { 3, 7 }, 2, "Full_Restore");
    cout << "Item: " << potion.GetID() << " | Effect: " << potion.GetEffect() << "\n";
    potion.Use();
    potion.Use();
    potion.Use(); // Testing durability exhaustion

    cout << "\nAll Entity tests completed successfully.\n";
    

    //Part C
    cout << "Part C : \n\n";

    // 1. Create a base entity instance
    Entity drone("0001", { 0, 0 }, 100, 100, 15);

    // a) Test PrintStatus()
    cout << "--- [A] Testing PrintStatus() ---\n";
    cout << drone.PrintStatus() << "\n\n";

    // b) Test Insertion Operator (<<)
    cout << "--- [B] Testing Insertion Operator (<<) ---\n";
    cout << drone << "\n\n";

    // c) Test Extraction Operator (>>)
    cout << "--- [C] Testing Extraction Operator (>>) ---\n";
    cout << "Enter new details for drone (Format: ID X Y MaxHP CurrentHP Attack):\n";
    cout << "Example: DroneBeta 4 7 150 120 30\n> ";
    cin >> drone;

    // Verify values were updated via operator<<
    cout << "\nUpdated Entity Output:\n";
    cout << drone << "\n\n";


    //Part D 
    cout << "Program Start\n\n";

    // Create test unit
    Entity pudge("Pudge", { 5, 5 }, 200, 200, 45);
    cout << "Initial Status:\n" << pudge << "\n\n";

    // 1. Test "Damaged <Value>"
    cout << "Enter command (e.g., Damaged 50): ";
    cin >> pudge;
    pudge.Tick();
    cout << "After Tick -> " << pudge << "\n\n";

    // 2. Test "Heal <Value>"
    cout << "Enter command (e.g., Heal 20): ";
    cin >> pudge;
    pudge.Tick();
    cout << "After Tick -> " << pudge << "\n\n";

    // 3. Test "Move <dx> <dy>"
    cout << "Enter command (e.g., Move 3 -2): ";
    cin >> pudge;
    pudge.Tick();
    cout << "After Tick -> " << pudge << "\n\n";

    // 4. Test "Attack"
    cout << "Enter command (e.g., Attack): ";
    cin >> pudge;
    int damageDealt = pudge.Tick(); 
    cout << pudge.GetID() << " attacks for " << damageDealt << " damage!\n";
    cout << "Current Status -> " << pudge << "\n\n";


    return 0;
}