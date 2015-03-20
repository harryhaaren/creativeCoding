Custom Classes
==============

This example introduces creating custom classes, and why it is useful to do so.
Note that the class is both declared *and* implemented in the `mymesh.h` file.
In order to use it, `#include "mymesh.h"` is in the start of the `ofApp.h` file,
so that the class is included.

Why Create a Class
------------------
The data (eg `ofVec3f position`) and what you probably intend to do with the
data (eg `ofTranslate()`) can be wrapped up into a function.

A class can represent a complex object - but using it remains easy, as the author
of the class can add functions for commonly desired actions. 

Draw()
------
In this example a `draw()` function is provided. The draw function makes it much
easier to draw this object than before: because it actually does the `ofTranslate`
`ofRotate` for us. It *hides* the fact that it does them - this is called "encapsulation".

(Theory behind this practice: C++ is an  Object Oriented language, and a class
represents an Object. In "encapsulating" the detail of how the object draws itself,
it has become simpler for other people to use the class.)

Randomize()
-----------
Similarly to the `draw()` function, `randomize()` performs multiple different
actions. It hides the details of what exactly is happening, and provides an easy
way to make a mesh randomize itself.

Again encapsulation is making it easier to use a class, by giving the user of the
class a single function to call which achieves a goal.

Conclusion
----------
In a project where complex objects are being represented in a scene, a class should
be written. The class should have a function for each commonly desired action.

Setting sane defaults in the constructor, and allowing easy use of the class by
providing `draw()`, `randomize()` and any other common action is good programming.
