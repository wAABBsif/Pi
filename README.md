π
====
**A quick experiment I wrote to calculate π from scratch.**

Purpose
--------
- This was written to quickly practice writing a small C application, along with trigonometry.

Usage
--------
Start the application with no argument and enter resolution, or use the intended resolution as an argument.

How It Works
--------
Half of the circumference of a circle is equal to its radius multiplied by π. Every point on the circumference will have the same distance from the center, that being the radius. By using the Pythagorean theorem, you can calculate a valid vertical displacement of a point from its horizontal displacement. By creating many points along half of the circumference and summing up their distances, you can calculate how long it is. Given a radius of 1, this would mean that the total distance is approximately π.
