# OOP-Concept
### II. อธิบายส่วนประกอบของโค้ดเปรียบเทียบกับ Concept ของ OOP

#### 1. **Class**
- **Class** คือพิมพ์เขียว (blueprint) สำหรับการสร้างวัตถุ (object) โดยการรวบรวมคุณสมบัติและพฤติกรรมเข้าไว้ในที่เดียว เช่น ในโค้ดข้อ I:

    **ตัวอย่าง:**
    ```java
    class Animal {
        public void sound() {
            System.out.println("animal makes a sound");
        }
    }
    ```

    **อธิบาย:** 
    - Class `Animal` คือการนิยามคุณสมบัติและพฤติกรรมพื้นฐานของสิ่งมีชีวิต โดยมี method `sound` ที่ใช้แสดงเสียงของสัตว์ 

#### 2. **Object, Instance**
- **Object** คือการสร้างตัวอย่าง (instance) ของ class เพื่อใช้งานจริงในการรันโปรแกรม แต่ละ object มีคุณสมบัติของ class ที่มันถูกสร้างขึ้นมา

    **ตัวอย่าง:**
    ```java
    Animal a = new Animal();
    Dog d = new Dog();
    ```

    **อธิบาย:** 
    - `a` คือ object ของ class `Animal` และ `d` คือ object ของ class `Dog` โดย `a` กับ `d` เป็น instance ของ class ที่ถูกนิยามไว้

#### 3. **Subclass, Derived Class**
- **Subclass** (หรือ **Derived Class**) คือ class ที่ถูกสร้างขึ้นจาก class อื่นผ่านการสืบทอด (inheritance) โดย subclass จะสืบทอดคุณสมบัติและพฤติกรรมจาก class แม่ และสามารถปรับเปลี่ยนหรือขยายการทำงานได้

    **ตัวอย่าง:**
    ```java
    class Dog extends Animal {
        @Override
        public void sound() {
            System.out.println("dog barks");
        }
    }
    ```

    **อธิบาย:** 
    - `Dog` เป็น subclass ของ `Animal` ซึ่งสืบทอดคุณสมบัติจาก `Animal` แต่ได้ปรับเปลี่ยนการทำงานของ method `sound` ให้แสดงเสียงว่า "dog barks"

#### 4. **Message**
- **Message** ใน OOP หมายถึงการสื่อสารระหว่าง object โดยการเรียกใช้ method ของ object ตัวหนึ่ง

    **ตัวอย่าง:**
    ```java
    d.sound();
    ```

    **อธิบาย:**
    - คำสั่ง `d.sound()` เป็นการส่ง message ไปยัง object `d` เพื่อให้เรียกใช้ method `sound` ของ class `Dog` ซึ่งพิมพ์ว่า "dog barks"

#### 5. **Inheritance**
- **Inheritance** คือกลไกที่ทำให้ subclass สามารถสืบทอดคุณสมบัติและพฤติกรรมจาก superclass ได้ ซึ่งช่วยลดการซ้ำซ้อนของโค้ด

    **ตัวอย่าง:**
    ```java
    class Dog extends Animal {
    }
    ```

    **อธิบาย:** 
    - `Dog` สืบทอด method `sound` จาก `Animal` และสามารถ override เพื่อเปลี่ยนแปลงการทำงานของ method ได้

#### 6. **Polymorphism**
- **Polymorphism** คือความสามารถของ method ที่มีหลายรูปแบบ ขึ้นอยู่กับ object ที่ถูกเรียกใช้งาน ในที่นี้ subclass สามารถมีการทำงานที่แตกต่างจาก superclass ได้

    **ตัวอย่าง:**
    ```java
    Animal a = new Dog();
    a.sound();
    ```

    **อธิบาย:** 
    - ถึงแม้ว่า `a` จะถูกประกาศเป็น `Animal` แต่เนื่องจาก `a` ถูกสร้างจาก class `Dog` เมื่อเรียก `a.sound()` จะได้ผลลัพธ์เป็น "dog barks" ซึ่งเป็นการทำงานแบบ polymorphism


### III. **Abstract Class** คืออะไร

- **Abstract Class** คือ class ที่ไม่สามารถสร้าง object โดยตรงได้ มีไว้เพื่อเป็นแบบแผนสำหรับการสร้าง subclass ที่ต้องการให้ subclass นำไปสืบทอดแล้วทำงานในแบบของตัวเอง มักจะมี method ที่เป็น abstract method ซึ่งไม่มีเนื้อหาในตัวมันเอง และบังคับให้ subclass ต้อง override เพื่อระบุรายละเอียดของ method นั้น

**หลักการสร้าง abstract class ใน Java:**
```java
abstract class Animal {
    public abstract void sound(); // Abstract method
}
```

- ในตัวอย่างข้อ I ไม่มี class ใดที่เป็น **abstract class** เนื่องจากทุก class สามารถสร้าง object ได้และ method `sound()` ใน class `Animal` มีการระบุรายละเอียดแล้ว อย่างไรก็ตาม เราสามารถเปลี่ยน `Animal` ให้เป็น abstract class ได้ถ้าต้องการบังคับให้ subclass ต้อง override method `sound`:

**การปรับเปลี่ยน class `Animal` เป็น abstract class:**
```java
abstract class Animal {
    public Animal() {
        System.out.println("create animal");
    }

    public abstract void sound(); // Abstract method, no implementation

    protected void finalize() {
        System.out.println("delete animal");
    }
}
```

- **อธิบาย:** 
  - `Animal` กลายเป็น abstract class เพราะมี method `sound()` ที่เป็น abstract method โดยไม่มีการระบุวิธีการทำงานใน class `Animal` ทำให้ class ที่สืบทอดจาก `Animal` จำเป็นต้อง override method `sound()`