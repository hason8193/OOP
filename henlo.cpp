#include <iostream>
#include <vector>
using namespace std;

class Gatekeeper {
public:
    virtual ~Gatekeeper() {}
    virtual bool passGate(int& princeMoney, int& princeIntelligence, int& princeStrength) = 0;
};

class Merchant : public Gatekeeper {
private:
    int unitPrice;
    int quantity;
public:
    Merchant(int unitPrice, int quantity) {
        this->unitPrice = unitPrice;
        this->quantity = quantity;
    }

    bool passGate(int& princeMoney, int& princeIntelligence, int& princeStrength)  {
        int requiredMoney = unitPrice * quantity;
        if (requiredMoney <= princeMoney) {
            princeMoney -= requiredMoney;
            return true;
        }
        return false;
    }
};

class Philosopher : public Gatekeeper {
private:
    int intelligenceIndex;
public:
    Philosopher(int index) : intelligenceIndex(index) {}

    bool passGate(int& princeMoney, int& princeIntelligence, int& princeStrength)  {
        return princeIntelligence >= intelligenceIndex;
    }
};

class Warrior : public Gatekeeper {
private:
    int strengthIndex;
public:
    Warrior(int index) : strengthIndex(index) {}

    bool passGate(int& princeMoney, int& princeIntelligence, int& princeStrength)  {
        if (princeStrength >= strengthIndex) {
            princeStrength -= strengthIndex;
            return true;
        }
        return false;
    }
};

class Gate {
private:
    int gateType;
    Gatekeeper* gatekeeper;
public:
    Gate(int type, Gatekeeper* keeper) : gateType(type), gatekeeper(keeper) {}

    bool passGate(int& princeMoney, int& princeIntelligence, int& princeStrength)  {
        return gatekeeper->passGate(princeMoney, princeIntelligence, princeStrength);
    }

    ~Gate() {
        delete gatekeeper;
    }
};

int main() {
    int numGates;
    cin >> numGates;

    vector<Gate*> gates;
    for (int i = 0; i < numGates; ++i) {
        int gateType;
        cin >> gateType;

        Gatekeeper* keeper = nullptr;
        if (gateType == 1) {
            int unitPrice;
            int quantity;
            cin >> unitPrice >> quantity;
            keeper = new Merchant(unitPrice,quantity);
        } else if (gateType == 2) {
            int intelligenceIndex;
            cin >> intelligenceIndex;
            keeper = new Philosopher(intelligenceIndex);
        } else if (gateType == 3) {
            int strengthIndex;
            cin >> strengthIndex;
            keeper = new Warrior(strengthIndex);
        }

        if (keeper != nullptr) {
            gates.push_back(new Gate(gateType, keeper));
        }
    }

    int princeMoney, princeIntelligence, princeStrength;
    cin >> princeMoney >> princeIntelligence >> princeStrength;

    bool passAllGates = true;
    for ( Gate* gate : gates) {
        if (!gate->passGate(princeMoney, princeIntelligence, princeStrength)) {
            passAllGates = false;
            break;
        }
    }

    if (passAllGates) {
        cout << princeMoney << " " << princeIntelligence << " " << princeStrength << endl;
    } else {
        cout << "-1" << endl;
    }

    // Clean up allocated memory
    for (Gate* gate : gates) {
        delete gate;
    }

    return 0;
}
