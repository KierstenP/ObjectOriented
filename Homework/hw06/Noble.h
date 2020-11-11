#include <string>
#include <vector>
namespace WarriorCraft {
    class Warrior;
    class Noble {
        friend Warrior;
        friend std::ostream& operator<<(std::ostream& os, const Noble& rhs);
    public:
        Noble(const std::string& nobleName);
        bool hire(Warrior& warrior);
        bool battle(Noble& otherNoble);
        void reduceStrength(int strengthOne, int strengthTwo);
        bool fire(Warrior& warriorName);
        std::string getName() const;
    private:
        std::string name;
        std::vector<Warrior*> warriors;
        bool dead = false;
    };
}