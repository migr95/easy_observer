# easy_observer

Header files for an easy Obsever/Subject pattern.

# Usage
```
#include "Observer.hpp"
#include "Subject.hpp"

int main(int argc, char * argv[])
{
    Subject obj1;
    Subject obj2;

    Observer obs(obj1);
    obs.DetachFromSubject();
    obs.reAttach();
    obs.attachToSubject(obj2, false);
    obs.attachToSubject(obj2, true);

    return 0;
}
```

