class Animal {
    public Animal() {
        System.out.println("create animal");
    }

    public void sound() {
        System.out.println("animal makes a sound");
    }

    protected void finalize() {
        System.out.println("delete animal");
    }
}

class Dog extends Animal {
    public Dog() {
        System.out.println("dog");
    }

    @Override
    public void sound() {
        System.out.println("dog barks");
    }

    protected void finalize() {
        System.out.println("delete dog");
    }
}

class Cat extends Animal {
    public Cat() {
        System.out.println("cat");
    }

    @Override
    public void sound() {
        System.out.println("cat meows");
    }

    protected void finalize() {
        System.out.println("delete cat");
    }
}

public class Main {
    public static void main(String[] args) {
        Animal a = new Animal();
        a.sound();

        Dog d = new Dog();
        d.sound();

        Cat c = new Cat();
        c.sound();
    }
}
