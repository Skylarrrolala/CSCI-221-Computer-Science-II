# Chapter 15: Inheritance - Practice Problems

## Small Problems

**1. Vehicle Hierarchy**  
Create a base class Vehicle with make and year. Derive a Car class that adds numberOfDoors. Create objects of both types and demonstrate that Car inherits Vehicle's members.

**2. Basic Virtual Function**  
Make a Shape base class with a virtual getType() function that returns "Generic Shape". Create Circle and Square derived classes that override it to return their specific types.

**3. Employee Polymorphism**  
Design an Employee base class with name and ID. Create SalariedEmployee and HourlyEmployee derived classes. Use a base class pointer to point to different employee types and call their methods.

**4. Protected Members**  
Create a BankAccount base class with protected balance. Derive SavingsAccount and CheckingAccount that can access and modify balance through their own methods.

**5. Constructor Chaining**  
Make a Person base class with name. Derive Student that adds GPA. Show that the Student constructor must call the Person constructor. Create a few students and verify both Person and Student data are initialized.

## Medium Problems

**1. Animal Sounds**  
Create an Animal base class with a virtual makeSound() function. Derive Dog, Cat, and Cow classes with their specific sounds. Create an array of Animal pointers pointing to different derived objects, then loop through calling makeSound() on each.

**2. Shape Area Calculator**  
Build a Shape base class with a pure virtual getArea() function. Derive Rectangle, Triangle, and Circle classes that implement getArea() differently. Create an array of Shape pointers, calculate total area of all shapes, and find the largest one.

**3. Game Character System**  
Design a Character base class with health and attack power. Derive Warrior, Mage, and Archer classes with different special abilities (virtual functions). Implement a virtual takeDamage() that works differently for each class (Warrior absorbs more, Mage has shields, etc.). Create a simple battle simulation.
