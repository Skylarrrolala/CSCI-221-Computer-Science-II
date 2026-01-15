/*
 * Medium Problem 3: Namespace Collision Resolution
 * 
 * Create two different libraries in separate namespaces (e.g., GraphicsLib 
 * and MathLib). Both have a function called draw() but they do different 
 * things. In main, use both libraries and resolve the name collision using 
 * namespace aliasing and explicit scope resolution.
 * 
 * Split this into: graphicslib.h, graphicslib.cpp, mathlib.h, mathlib.cpp, 
 * and main.cpp. This file is the main.cpp starter.
 */

#include <iostream>
#include "graphicslib.h"
#include "mathlib.h"
using namespace std;

int main() {
    // TODO: Your code here
    // Hint: Use namespace aliases like "namespace GL = GraphicsLib;"
    
    return 0;
}
