#include <iostream>
#include <vector>

// Switch class
class Switch {
public:
    Switch(int id) : id_(id) {}
    void add_link(Switch* switch_ptr) { links_.push_back(switch_ptr); }
    int id() const { return id_; }
    const std::vector<Switch*>& links() const { return links_; }

private:
    int id_;
    std::vector<Switch*> links_;
};

int main() {
    // Create switches
    std::vector<Switch*> spine_switches;
    std::vector<Switch*> leaf_switches;
    for (int i = 1; i <= 2; ++i) {
        spine_switches.push_back(new Switch(i));
    }
    for (int i = 3; i <= 6; ++i) {
        leaf_switches.push_back(new Switch(i));
    }

    // Connect switches
    for (auto spine_switch : spine_switches) {
        for (auto leaf_switch : leaf_switches) {
            spine_switch->add_link(leaf_switch);
            leaf_switch->add_link(spine_switch);
        }
    }

    // Print connections
    for (auto spine_switch : spine_switches) {
        std::cout << "Spine switch " << spine_switch->id() << " is connected to leaf switches: ";
        for (auto leaf_switch : spine_switch->links()) {
            std::cout << leaf_switch->id() << " ";
        }
        std::cout << std::endl;
    }
    for (auto leaf_switch : leaf_switches) {
        std::cout << "Leaf switch " << leaf_switch->id() << " is connected to spine switches: ";
        for (auto spine_switch : leaf_switch->links()) {
            std::cout << spine_switch->id() << " ";
        }
        std::cout << std::endl;
    }

    // Clean up
    for (auto switch_ptr : spine_switches) {
        delete switch_ptr;
    }
    for (auto switch_ptr : leaf_switches) {
        delete switch_ptr;
    }

    return 0;
}
