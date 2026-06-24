#include <iostream>
#include <memory>

class Entity {
    public:
    Entity() {
        std::cout << "Entity created" << std::endl;
    }
    ~Entity() 
    { std::cout << "Entity destroyed" << std::endl; }
};

int main() {
    std::cout << "Smart Pointers Example" << std::endl;
    // Using unique_ptr
    {
        std::unique_ptr<Entity> entityPtr = std::make_unique<Entity>();
        std::shared_ptr<Entity> sharedEntityPtr = std::make_shared<Entity>();
        std::cout << "Unique Pointer and Shared Pointer created" << std::endl;
        // Print shared pinter reference count
        {
            std::shared_ptr<Entity> anotherSharedPtr = sharedEntityPtr;
            std::cout << "Another Shared Pointer created, reference count: " << anotherSharedPtr.use_count() << std::endl;
        } 
        std::cout << "Shared Pointer Reference Count: " << sharedEntityPtr.use_count() << std::endl;

    }

    return 0;   
}