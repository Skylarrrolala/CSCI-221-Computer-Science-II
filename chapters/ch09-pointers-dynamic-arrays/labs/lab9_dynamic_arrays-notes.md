# Lab 9: Dynamic Arrays - Notes

## Goal

This lab is all about building your own mini-version of what `vector` does behind the scenes. You'll create a dynamic array of strings that can grow when you add items and shrink when you delete them. The key skill here is managing memory manually with `new` and `delete[]`, and learning to reassign pointers when the array changes size.

## Plan

Here's the order to tackle this lab:

1. **Set up main()** - Declare a size variable (start at 5) and create a dynamic array of 5 strings using `new string[5]`.

2. **Initialize with starting data** - Put 5 names into your array (can be anything: "Alice", "Bob", etc.).

3. **Print helper** - Write a simple loop to print all names in the array so you can see what's happening.

4. **Implement addEntry()** - Create a new array that's one bigger, copy everything over, add the new name at the end, delete the old array, return the new one.

5. **Test adding** - In main(), call `addEntry()` a few times and print after each add. Don't forget to reassign: `names = addEntry(names, size, "Charlie");`

6. **Implement deleteEntry()** - Search for the name, if found create a smaller array and copy everything except that name, if not found just return the original array.

7. **Test deleting** - Try removing a name that exists, then try removing one that doesn't exist. Print after each attempt.

8. **Clean up** - Before `return 0;`, remember to `delete[] names;` to avoid memory leaks.

## Tricky Parts

Watch out for these common issues:

- **Memory leaks** - Every time you use `new[]`, you must eventually use `delete[]` on that same pointer. If you create a new array and forget to delete the old one, you leak memory.

- **Forgetting to reassign** - The functions return a new pointer, so you MUST write `names = addEntry(names, size, "Bob");` not just `addEntry(names, size, "Bob");`. Otherwise you're still pointing at deleted memory!

- **Size not updated** - The size is passed by reference (`int& size`), so incrementing or decrementing it inside the function changes the original variable in main.

- **Off-by-one errors** - When copying to a new array, make sure your loop goes from `0` to `size-1` (or use `i < size`). When adding, the new entry goes at index `size` (before you increment).

- **Not handling "not found"** - In `deleteEntry()`, if you don't find the name, just return the original array without changing anything. Don't try to delete from an array that doesn't have it.

## Test Ideas

Try these scenarios to make sure your code works:

- Start with 5 names, add 2 new names → should have 7 total
- Delete a name from the middle → check that the order of remaining names is correct
- Delete a name from the beginning or end → make sure no crashes
- Try to delete a name that doesn't exist → size should stay the same, array unchanged
- Add several names in a row → verify size keeps growing correctly
- Delete all but one name, then add more → test that it handles size 1 properly
- Print after every operation to visually confirm the array contents

Good luck! Remember: the whole point is learning to manage memory yourself. Take it one step at a time.
