# stublib

`stublib` is a simple header-only library that provides access to a stub function which can be used to specify desired outputs of a function at runtime. This can be useful for multiple use cases:

* before a function is fully implemented, being able to run the full program using the stubbed method
* given multiple candidate functions with different outputs, being able to test the values produced by each one in the full program without recompiling
* in things like game balancing, being able to try out various different values without needing to edit stats or functions directly in order to test changes

## Usage

```cpp
#include "include/stublib.h"

// function to stub out
float lerp(float start, float end, float percent) {
    STUB(start, end, percent);
}
```

With the above code, whenever `lerp` is called the program will either query for what the value should be (if those parameters were not already encountered during program runtime) or will use the return value that matches the supplied arguments.

The query will appear as `STUB float lerp(float, float, float)[start=0, end=1, percent=0.5]:` prompting for input.