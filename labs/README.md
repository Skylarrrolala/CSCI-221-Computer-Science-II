# Lab Guidance - CSCI 221

This directory contains **tutoring guidance** for each lab assignment. These guides will help you understand concepts, plan your approach, and implement solutions **yourself**.

## 🎯 How to Use Lab Guides

### Before Starting a Lab:
1. **Read the lab requirements** carefully (2-3 times!)
2. **Review the relevant topic guide** to refresh concepts
3. **Read the lab guidance** here for strategic help
4. **Plan your approach** using pseudocode
5. **Implement incrementally** - one function at a time
6. **Test thoroughly** - you only get 1 attempt!

### What These Guides Provide:
✅ Concept refreshers and links to topic guides
✅ Step-by-step planning approach
✅ Pseudocode patterns (not complete C++ code!)
✅ Edge cases to consider
✅ Testing strategies
✅ Common pitfalls specific to the lab
✅ Hints when you're stuck

### What These Guides DON'T Provide:
❌ Complete C++ solutions
❌ Copy-paste code
❌ Answers to quiz questions
❌ Shortcuts that bypass learning

## 📅 Lab Schedule

### Lab Chapter 9 - Dynamic Arrays
**Due**: January 22, 2026, 6:00 PM  
**Guide**: [Lab 9 Guidance](lab-09-dynamic-arrays.md)  
**Topics**: Dynamic memory, pointers, arrays  
**Preparation**: Review [Dynamic Memory](../topics/02-dynamic-memory.md)

### Lab Chapter 10 - Odometer Class
**Due**: February 1, 2026, 6:00 PM  
**Guide**: [Lab 10 Guidance](lab-10-odometer-class.md)  
**Topics**: Classes, member functions, constructors  
**Preparation**: Review [Classes](../topics/01-classes.md)

### Lab Chapter 11 - Movie Rating Class
**Due**: February 12, 2026, 6:00 PM  
**Guide**: [Lab 11 Guidance](lab-11-movie-rating.md)  
**Topics**: Classes, arrays, loops  
**Preparation**: Review [Classes](../topics/01-classes.md)

### Lab Chapter 13 - Linked List Reversal
**Due**: March 8, 2026, 5:00 PM  
**Guide**: [Lab 13 Guidance](lab-13-linked-list-reversal.md)  
**Topics**: Linked lists, pointers, stacks  
**Preparation**: Review [Linked Lists](../topics/04-linked-lists.md) and [Stacks](../topics/05-stacks.md)

### Lab Chapter 15 - Inheritance & Polymorphism
**Due**: March 19, 2026, 5:00 PM  
**Guide**: [Lab 15 Guidance](lab-15-inheritance-game.md)  
**Topics**: Inheritance, polymorphism, OOP  
**Preparation**: Review textbook Chapter 15

### Lab Chapter 16 - Exception Handling
**Due**: April 2, 2026, 5:00 PM  
**Guide**: [Lab 16 Guidance](lab-16-exception-handling.md)  
**Topics**: Exception handling, input validation  
**Preparation**: Review textbook Chapter 16

## 🎓 Quiz Preparation

While I won't provide quiz answers, here's how to prepare:

### For Each Quiz:
1. **Review relevant topic guides** in this repository
2. **Understand concepts deeply**, don't just memorize
3. **Practice with code** - implement examples yourself
4. **Test your understanding** with the practice problems
5. **Take practice quiz** if available in Blackboard

### Quiz Tips:
- You have **2 attempts** - use them wisely
- **Read questions carefully** - they can be tricky
- **Unlimited time** - don't rush, think through each question
- **Last attempt counts** - make your second attempt your best

### Quiz Topics Likely Covered:
- Quiz 1-2: Chapters 9-10 (Dynamic memory, Classes)
- Quiz 3-4: Chapters 11-12 (Arrays, File I/O)
- Quiz 5-6: Chapters 13-14 (Linked lists, Recursion)
- Quiz 7-8: Chapters 15-16 (Inheritance, Exceptions)
- Quiz 9: Chapter 17-18 (Templates, Data structures)

## ⚠️ Important Reminders

### For Labs (1 Attempt Only!):
1. **Plan thoroughly** before coding
2. **Test locally first** with various inputs
3. **Check requirements** against your implementation
4. **Compile with no warnings** using `-Wall -Wextra`
5. **Run test cases** covering all edge cases
6. **Review your code** for common errors
7. **Only submit when confident** - you can't redo it!

### Best Practices:
```bash
# Compile with warnings
g++ -Wall -Wextra -std=c++11 your_program.cpp -o program

# Test with various inputs
./program < test_input1.txt
./program < test_input2.txt

# Check for memory leaks (if using dynamic memory)
valgrind --leak-check=full ./program
```

## 🆘 When You're Stuck

### Step 1: Review Concepts
- Go back to the relevant topic guide
- Understand the theory before coding

### Step 2: Check Lab Guidance
- Read the planning section
- Study the pseudocode patterns
- Review edge cases

### Step 3: Break It Down
- Solve a simpler version first
- Implement one function at a time
- Test each piece before moving on

### Step 4: Debug Systematically
- Print intermediate values
- Use a debugger
- Check pointer values before dereferencing

### Step 5: Ask for Help (Smart Way)
✅ "I'm working on the addEntry function. I understand I need to create a new array and copy elements, but I'm not sure how to handle the pointer reassignment. Here's my pseudocode... What am I missing?"

❌ "My code doesn't work. Can you fix it?"

## 📚 Additional Resources

- **Topic Guides**: [../topics/](../topics/)
- **Practice Problems**: [../practice/](../practice/)
- **Resources**: [../resources/](../resources/)
- **Quick Start**: [../QUICKSTART.md](../QUICKSTART.md)

---

**Remember**: These labs are your opportunity to prove you understand the concepts. Take them seriously, plan carefully, and test thoroughly. You've got this! 🚀
