#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>

enum GameState
{
    // enum to store the game states
    MainMenu,
    FightMenu,
    MoveMenu,
    Exit
};
void outputMenu(GameState state)
{
    // outputs the basic menus depending on the state
    std::cout << "___________________________" << std::endl;
    std::cout << "|   Menu                  |" << std::endl;
    switch (state)
    {
    case MainMenu:
    {
        std::cout << "___________________________" << std::endl;
        std::cout << "|   1. Explore            |" << std::endl;
        std::cout << "|   2. Exit               |" << std::endl;
        std::cout << "|_________________________|" << std::endl;
        break;
    }
    case FightMenu:
    {
        std::cout << "___________________________" << std::endl;
        std::cout << "|   1. Fight!             |" << std::endl;
        std::cout << "|   2. Throw a smoke bomb |" << std::endl;
        std::cout << "|   3. Try to negotiate   |" << std::endl;
        std::cout << "|   4. Flee!              |" << std::endl;
        std::cout << "|_________________________|" << std::endl;
        break;
    }
    case MoveMenu:
    {
        std::cout << "___________________________" << std::endl;
        std::cout << "|   1. North - To forest  |" << std::endl;
        std::cout << "|   2. East - To mines    |" << std::endl;
        std::cout << "|   3. South - To desert  |" << std::endl;
        std::cout << "|   4. West - To city     |" << std::endl;
        std::cout << "|_________________________|" << std::endl;
        break;
    }
    case Exit:
    {
        std::cout << "Thank you for playing!" << std::endl;
        exit(0);
        break;
    }
    }
}

struct Location
{
    // struct containing the different locations and a description
    std::string Forest = "A luscious forest is ahead of you, you enter not knowing what you will find. Many creatures have taken over the forest as their home, you see giant ants carrying leafs, beautiful coloured winged butterflies soaring through the gaps in the trees, and the sun feels cozy.";
    std::string Mines = "A deserted thousand year old mine is on your path, you thread carefully not wanting to be crushed by the decaying enormous wood supports. You hear a scraping sound almost like a pickaxe is being dragged across the rock deep in the tunnels, you gulp, musterring up courage and proceed to enter.";
    std::string Desert = "A vast, scorching desert stretches out before you, with waves of heat rising from the golden sands. The air is dry, and each step sinks slightly into the ground. In the distance, you spot a lone cactus and the faint outline of ancient ruins, whispering tales of forgotten civilizations ";
    std::string City = "A sprawling, abandoned city lies ahead, its towering structures crumbling but still magnificent. Ivy climbs the stone walls, and faint echoes of distant footsteps suggest you're not alone. You take refuge in a what looks like supermarket, gathering your thoughts and looking for supplies and a place to stay for the night.";
};
struct PlayerAttacks
{
    // struct containing the different player attacks and a description
    std::string Slash = "You swing your sword in a wide arc, aiming to cut your enemy down.";
    std::string Fireball = "You summon a fireball and hurl it at your opponent, engulfing them in flames.";
    std::string PoisonDagger = "You strike with a poisoned dagger, hoping to weaken the enemy over time.";
    std::string ShieldBash = "You raise your shield and bash it into the enemy, knocking them off balance.";
};
struct EnemyAttacks
{
    // struct containing the different enemy attacks and a description
    std::string ClawStrike = "The enemy slashes at you with sharp claws, dealing damage!";
    std::string FireBreath = "The enemy breathes a fiery stream towards you, burning you!";
    std::string PoisonSpit = "The enemy spits poisonous venom at you, slowly weakening you!";
    std::string Stomp = "The enemy stomps the ground with great force, knocking you off balance!";
};
struct Enemies
{
    // forest enemies
    struct ForestEnemies
    {
        // struct containing the different forest enemies attacks and a description
        std::string ForestCrab = "A giant crab with sharp claws scuttles towards you, its exoskeleton glistening in the sunlight. Its beady eyes fixate on you as it clicks its claws, preparing to attack.";
        std::string ForestGoblin = "A sneaky goblin, hunched and twisted, with pointy ears and a mischievous grin, emerges from the shadows. It’s armed with a rusty dagger, looking for trouble.";
        std::string ForestWolf = "A large, snarling wolf with sharp teeth and glowing eyes emerges from the dense forest. It circles you, waiting for the right moment to strike.";

        EnemyAttacks ForestCrabAttacks = { "ClawStrike", "PoisonSpit" };
        EnemyAttacks ForestGoblinAttacks = { "ClawStrike", "Stomp" };
        EnemyAttacks ForestWolfAttacks = { "Stomp", "ClawStrike" };
    } forest;

    // mines enemies
    struct MineEnemies
    {
        // struct containing the different mines enemies attacks and a description
        std::string MineZombie = "A slow-moving zombie, covered in dirt and grime, stumbles out of the shadows. Its eyes are vacant, and its hands reach for you, hungry for flesh.";
        std::string MineGoblin = "A goblin with a twisted, mischievous grin lurks behind a large pile of rocks, holding a jagged pickaxe, ready to strike from the shadows.";
        std::string MineTroll = "A hulking troll with glowing red eyes emerges from the deep darkness of the mine. It lumbers toward you, swinging a heavy, spiked club in your direction.";

        EnemyAttacks MineZombieAttacks = { "ClawStrike", "FireBreath" };
        EnemyAttacks MineGoblinAttacks = { "ClawStrike", "Stomp" };
        EnemyAttacks MineTrollAttacks = { "Stomp", "PoisonSpit" };
    } mine;

    // desert enemies
    struct DesertEnemies
    {
        // struct containing the different desert enemies attacks and a description
        std::string DesertScorpion = "A massive scorpion with a venomous stinger skitters across the hot sand, its eyes locking onto you as it clicks its pincers in anticipation.";
        std::string DesertBandit = "A sun-worn bandit in a tattered cloak steps out from behind a rock, his dagger gleaming under the hot sun. His eyes are full of malice and greed.";
        std::string DesertVampire = "A pale, bloodthirsty vampire with glowing red eyes appears from behind a sand dune. Its fangs glisten as it eyes you hungrily, ready to strike.";

        EnemyAttacks DesertScorpionAttacks = { "PoisonSpit", "ClawStrike" };
        EnemyAttacks DesertBanditAttacks = { "ClawStrike", "Stomp" };
        EnemyAttacks DesertVampireAttacks = { "FireBreath", "PoisonSpit" };
    } desert;

    // city enemies
    struct CityEnemies
    {
        // struct containing the different city enemies attacks and a description
        std::string CityZombie = "A decaying zombie, its clothes torn and face rotting, shuffles through the streets of the city. Its arms stretch forward, searching for its next victim.";
        std::string CityHarpy = "A harpy, with the body of a woman and the wings and talons of a bird, screeches loudly as it swoops down from a crumbling rooftop, ready to tear into you with its deadly claws.";
        std::string CityBandit = "A rugged bandit, wearing a torn cloak and holding a crooked dagger, emerges from an abandoned building, ready to steal anything of value.";

        EnemyAttacks CityZombieAttacks = { "ClawStrike", "PoisonSpit" };
        EnemyAttacks CityHarpyAttacks = { "ClawStrike", "FireBreath" };
        EnemyAttacks CityBanditAttacks = { "Stomp", "PoisonSpit" };
    } city;
};

std::string randomEnemyEncounter(std::string location)
{
    // initialise enemies of type Enemies
    Enemies enemies;
    // check location to output correct enemy types
    if (location == "Forest")
    {
        // chance variable to spice up encouter
        int encounterChance = rand() % 100;
        if (encounterChance < 50) // 50% chance of encountering an enemy
        {
            int enemyChoice = rand() % 3;
            // output description of randoml enemy
            if (enemyChoice == 0)
            {
                std::cout << enemies.forest.ForestCrab << std::endl;
                return "ForestCrab";
            }
            else if (enemyChoice == 1)
            {
                std::cout << enemies.forest.ForestGoblin << std::endl;
                return "ForestGoblin";
            }
            else
            {
                std::cout << enemies.forest.ForestWolf << std::endl;
                return "ForestWolf";
            }
        }
    }
    else if (location == "Mines")
    {
        int encounterChance = rand() % 100;
        if (encounterChance < 50) // 50% chance of encountering an enemy
        {
            int enemyChoice = rand() % 3;
            if (enemyChoice == 0)
            {
                std::cout << enemies.mine.MineZombie << std::endl;
                return "MineZombie";
            }

            else if (enemyChoice == 1)
            {
                std::cout << enemies.mine.MineGoblin << std::endl;
                return "MineGoblin";
            }


            else
            {
                std::cout << enemies.mine.MineTroll << std::endl;
                return "MineTroll";
            }

        }
    }
    else if (location == "Desert")
    {
        int encounterChance = rand() % 100;
        if (encounterChance < 50) // 50% chance of encountering an enemy
        {
            int enemyChoice = rand() % 3;
            if (enemyChoice == 0)
            {
                std::cout << enemies.desert.DesertScorpion << std::endl;
                return "DesertScorpion";
            }

            else if (enemyChoice == 1)
            {
                std::cout << enemies.desert.DesertBandit << std::endl;
                return "DesertBandit";
            }

            else
            {
                std::cout << enemies.desert.DesertVampire << std::endl;
                return "DesertVampire";

            }

        }
    }
    else if (location == "City")
    {
        int encounterChance = rand() % 100;
        if (encounterChance < 50) // 50% chance of encountering an enemy
        {
            int enemyChoice = rand() % 3;
            if (enemyChoice == 0)
            {
                std::cout << enemies.city.CityZombie << std::endl;
                return "CityZombie";
            }

            else if (enemyChoice == 1)
            {
                std::cout << enemies.city.CityHarpy << std::endl;
                return "CityHarpy";
            }

            else
            {
                std::cout << enemies.city.CityBandit << std::endl;
                return "CityBandit";
            }

        }
    }
    return "";
}
void enemyFight(std::string enemyType)
{
    EnemyAttacks enemyAttacks;
    int randomChoice;

    // Now, it's the enemy's turn to attack
    std::cout << "The enemy attacks!" << std::endl;

    if (enemyType == "ForestCrab")
    {
        randomChoice = rand() % 2; // 2 attacks available for ForestCrab
        if (randomChoice == 0)
            std::cout << enemyAttacks.ClawStrike << std::endl;
        else
            std::cout << enemyAttacks.PoisonSpit << std::endl;
    }
    else if (enemyType == "ForestGoblin")
    {
        randomChoice = rand() % 2; // 2 attacks available for ForestGoblin
        if (randomChoice == 0)
            std::cout << enemyAttacks.ClawStrike << std::endl;
        else
            std::cout << enemyAttacks.Stomp << std::endl;
    }
    else if (enemyType == "ForestWolf")
    {
        randomChoice = rand() % 2; // 2 attacks available for ForestWolf
        if (randomChoice == 0)
            std::cout << enemyAttacks.Stomp << std::endl;
        else
            std::cout << enemyAttacks.ClawStrike << std::endl;
    }
    
}

void playerFight(std::string enemyType)
{

    //gGive the player a chance to choose an attack
    std::cout << "1. Slash\n2. Fireball\n3. Poison Dagger\n4. Shield Bash\n";
    int playerAttackChoice;
    std::cin >> playerAttackChoice;

    // handle player attack
    switch (playerAttackChoice)
    {
    case 1:
        std::cout << "You chose Slash!" << std::endl;
        break;
    case 2:
        std::cout << "You chose Fireball!" << std::endl;
        break;
    case 3:
        std::cout << "You chose Poison Dagger!" << std::endl;
        break;
    case 4:
        std::cout << "You chose Shield Bash!" << std::endl;
        break;
    default:
        std::cout << "Invalid choice!" << std::endl;
    }
}


void gameLoop()
{
    GameState state = MainMenu;
    int choice = 0;
    Location location;
    srand(static_cast<unsigned int>(time(0)));
    std::string enemyType = ""; // Stores the enemy type encountered in each location

    while (state != Exit)
    {
        // Display the current menu at the start of each loop iteration
        outputMenu(state);
        std::cout << "Choose an option: ";
        std::cin >> choice;

        // Check if input is valid
        if (std::cin.fail()) {
            std::cin.clear(); // clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input, please enter a number.\n";
            continue;
        }

        if (state == MainMenu)
        {
            if (choice == 1)
            {
                std::cout << "You chose to explore!" << std::endl;
                state = MoveMenu;
            }
            else if (choice == 2)
            {
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                state = Exit;
            }
            else
            {
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
        else if (state == MoveMenu)
        {
            switch (choice)
            {
            case 1:
                std::cout << "You chose to move North!" << std::endl;
                std::cout << location.Forest << std::endl;
                enemyType = randomEnemyEncounter("Forest");
                break;
            case 2:
                std::cout << "You chose to move East!" << std::endl;
                std::cout << location.Mines << std::endl;
                enemyType = randomEnemyEncounter("Mines");
                break;
            case 3:
                std::cout << "You chose to move South!" << std::endl;
                std::cout << location.Desert << std::endl;
                enemyType = randomEnemyEncounter("Desert");
                break;
            case 4:
                std::cout << "You chose to move West!" << std::endl;
                std::cout << location.City << std::endl;
                enemyType = randomEnemyEncounter("City");
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                continue; // Re-prompt for valid MoveMenu input
            }

            // If an enemy is encountered, switch to FightMenu
            if (!enemyType.empty())
            {
                state = FightMenu;
            }
            else
            {
                // Stay in MoveMenu if no enemy is encountered
                continue;
            }
        }
        else if (state == FightMenu)
        {
            std::cout << "Choose an action: ";
            std::cin >> choice;

            // Check for valid input again
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input, please enter a number.\n";
                continue;
            }

            int successChance = rand() % 100 + 1; // Random chance (1-100)

            if (choice == 1) // Fight!
            {
                playerFight(enemyType);
                enemyFight(enemyType);
            }
            else if (choice == 2) // Throw a smoke bomb
            {
                std::cout << "You throw a smoke bomb!" << std::endl;
                if (successChance <= 50)
                {
                    std::cout << "The smoke bomb confuses the enemy, and you successfully flee!" << std::endl;
                    state = MoveMenu;
                    enemyType.clear(); // Clear enemyType to avoid immediate re-entry into FightMenu
                }
                else
                {
                    std::cout << "The smoke bomb failed! The enemy is not confused!" << std::endl;
                    playerFight(enemyType);
                    enemyFight(enemyType);
                }
            }
            else if (choice == 3) // Try to negotiate
            {
                std::cout << "You attempt to negotiate with the " << enemyType << "." << std::endl;
                if (successChance <= 30)
                {
                    std::cout << "The negotiation was successful, and the enemy lets you go!" << std::endl;
                    state = MoveMenu;
                    enemyType.clear();
                }
                else
                {
                    std::cout << "Negotiation failed! The enemy is not convinced!" << std::endl;
                    playerFight(enemyType);
                    enemyFight(enemyType);
                }
            }
            else if (choice == 4) // Flee!
            {
                std::cout << "You attempt to flee!" << std::endl;
                if (successChance <= 40)
                {
                    std::cout << "You successfully flee from the " << enemyType << "!" << std::endl;
                    state = MoveMenu;
                    enemyType.clear();
                }
                else
                {
                    std::cout << "You failed to flee! The enemy blocks your escape!" << std::endl;
                    playerFight(enemyType);
                    enemyFight(enemyType);
                }
            }
            else
            {
                std::cout << "Invalid choice. Please try again." << std::endl;
                continue; // re-prompt for valid fight action input
            }

            // after handling all FightMenu actions, reset to MoveMenu
            if (state == FightMenu) {
                state = MoveMenu;
                enemyType.clear(); // clear enemy type after fight ends
            }
        }
    }
}



int main()
{
    // call gameLoop to start the game
    gameLoop();
    return 0;
}
