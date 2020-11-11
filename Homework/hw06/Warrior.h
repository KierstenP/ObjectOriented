#include <string>
#include <vector>
namespace WarriorCraft {
    class Noble;
    class Warrior {
        friend Noble;
    public:
        Warrior(const std::string& warriorName, int warrior_strength);
        void reduceStrength(int strengthOne, int strengthTwo);
        bool runaway();
        std::string getName() const;
        int getStrength() const;
    private:
        std::string name;
        int strength;
        Noble* noble = nullptr;
    };
}