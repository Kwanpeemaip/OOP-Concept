#include <iostream>
using namespace std;

class Animal {
public:
    Animal() {
        cout << "create animal" << endl;
    }

    virtual void sound() {
        cout << "animal makes a sound" << endl;
    }

    virtual ~Animal() {
        cout << "delete animal" << endl;
    }
};

class Dog : public Animal {
public:
    Dog() {
        cout << "dog" << endl;
    }

    void sound() override {
        cout << "dog barks" << endl;
    }

    ~Dog() {
        cout << "delete dog" << endl;
    }
};

class Cat : public Animal {
public:
    Cat() {
        cout << "cat" << endl;
    }

    void sound() override {
        cout << "cat meows" << endl;
    }

    ~Cat() {
        cout << "delete cat" << endl;
    }
};

int main() {
    Animal* a = new Animal();
    a->sound();
    delete a;

    Dog* d = new Dog();
    d->sound();
    delete d;

    Cat* c = new Cat();
    c->sound();
    delete c;

    return 0;
}
