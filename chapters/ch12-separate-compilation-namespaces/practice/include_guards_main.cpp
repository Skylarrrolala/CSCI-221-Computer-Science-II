/*
 * Small Problem 4: Include Guards Practice
 * 
 * Create a header file person.h that defines a Person class. Intentionally 
 * include it twice in main.cpp to see what happens without include guards, 
 * then add guards to fix the problem.
 * 
 * NOTE: This is the main.cpp. You'll also need to create person.h.
 */

#include <iostream>
#include "person.h"
#include "person.h"  // Included twice on purpose!
using namespace std;

int main() {
    // TODO: Your code here
    
    return 0;
}
