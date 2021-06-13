#include <iostream>
#include "../include/stublib.h"

// function to stub out
float lerp(float start, float end, float percent) {
    STUB(start, end, percent);
}

int main() {
    // get stub values for lerp with these values
    std::cout << "ANS: " << lerp(0, 1, 0.5) << '\n';
    std::cout << "ANS: " << lerp(10, 20, 0) << '\n';
    
    // note that this stub value was already used
	// by consequence, this call won't be queried
    std::cout << "ANS: " << lerp(0, 1, 0.5) << '\n';
}