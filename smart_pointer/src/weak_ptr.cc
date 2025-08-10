/**
 * Weak pointer is implemented to address the cyclic reference issue
 * For example, there is a class `Person` that holds a shared_ptr, denoted as a friend, to another `Person` instance,
 * which is analogous to a friend relationship.
 * In this case, both `Person` instances hold shared_ptrs to each other, creating a cyclic reference.
 * When person_A is destroyed, person_B is still holding a shared_ptr to it, preventing its memory from being freed.
 * Even if person_B is destroyed, person_A's memory will not be freed until the last shared_ptr is destroyed.
 *
 *  shared_ptr          shared_ptr
 *  person_A            person_B
 *       |                  |
 *       V                  V
 *  ____________        ____________
 * |            |      |            |
 * | Person A   |      | Person B   |
 * |            |      |            |
 * | shared_ptr | <=== | friend     |
 * | person_A   |      |            |
 * |            |      |            |
 * | friend     | ===> | shared_ptr |
 * |            |      | person_B   |
 * |____________|      |____________|
 */

#include <iostream>
#include <memory>

class PersonSharedPtr {
public:
    PersonSharedPtr(const std::string& name) : name(name) {}
    ~PersonSharedPtr() { std::cout << name << " is destroyed." << std::endl; }

    void setFriend(const std::shared_ptr<PersonSharedPtr>& friendPtr) {
        this->friendPtr = friendPtr;
        std::cout << name << " has a friend: " << friendPtr->name << std::endl;
    }

private:
    std::string name;
    std::shared_ptr<PersonSharedPtr> friendPtr; // Shared pointer to a friend
};

class PersonWeakPtr {
public:
    PersonWeakPtr(const std::string& name) : name(name) {}
    ~PersonWeakPtr() { std::cout << name << " is destroyed." << std::endl; }

    void setFriend(const std::weak_ptr<PersonWeakPtr>& friendPtr) {
        this->friendPtr = friendPtr;
        if (auto sp = friendPtr.lock()) {
            std::cout << name << " has a friend: " << sp->name << std::endl;
        }
    }

private:
    std::string name;
    std::weak_ptr<PersonWeakPtr> friendPtr; // Weak pointer to a friend
};

int main() {
    // The instances of these classes will not be destroyed even if main() ends
    std::cout << "\n--- Demonstrating solution with shared_ptr ---" << std::endl;
    {
        auto personA = std::make_shared<PersonSharedPtr>("Person A");
        auto personB = std::make_shared<PersonSharedPtr>("Person B");

        personA->setFriend(personB);
        personB->setFriend(personA);
    }

    std::cout << "\n--- Demonstrating solution with weak_ptr ---" << std::endl;
    {
        auto personAWeakPtr = std::make_shared<PersonWeakPtr>("Person A");
        auto personBWeakPtr = std::make_shared<PersonWeakPtr>("Person B");

        personAWeakPtr->setFriend(personBWeakPtr);
        personBWeakPtr->setFriend(personAWeakPtr);
    }

    return 0;
}