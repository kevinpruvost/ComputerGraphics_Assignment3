# Assignment 3 of Fundamentals of Computer Graphics: Star Rotation

<p align="center">
  <img src="https://github.com/kevinpruvost/OpenImages/blob/miscellaneous/images/1200px-Tsinghua_University_Logo.svg.png" width=250/><br/><br/>
</p>

# Introduction

For this assignment, the main theme was `Stars Rotation`.

The objectives here were:

1. Multiple stars rotate around a center.
2. The colors of stars are different.
3. Stars rotate and spread out in spiral path.
4. Choose a spiral type in Archimedes spiral, Fermat spiral and logarithmic spiral.

# Compilation

This project and all of my CG projects will be compiled with CMake, if you open the project directly with Visual Studio, you should be able to directly compile it.
Though, as CMake permits it, you will be easily able to compile on other platforms.

# Demonstration

## Content

For my Assignment, I got all these points covered:

- Starts rotate around a center
- Colors of stars are different
- Stars rotate/spread around in spiral path
- All spiral formulas are covered (Archimedes, Fermat & Logarithmic)
- Bonus:
    - Camera Movement + Rotation (can be enabled/disabled)
    - Display Mode (Vertices, Wireframe, Faces)
    - Enable/Disable GUI
    - Particle Systems parameters can be edited
    - The 3 spiral types can be tested

## How to use it

[![Demo](embed.png)](https://youtu.be/Q7Rqe0mQsaM)

You can launch the `Assignment3.exe`directly, if you already have Visual C++ Redistribuable.

The program was compiled in Release mode.

As it is displayed in the program, here are the controls by order of priority for the assignment:

## Controls

- Change Font: F
- Enable/Disable GUI: T
- Object View Mode Switch: C
- Wireframe Color Change: P
- Camera/Cursor Lock: L
- Camera Movement:
    - Forward: W (or Z on AZERTY layout)
    - Backward: S
    - Left: A (or Q on AZERTY layout)
    - Right: D
    - Up: Space
    - Down: Left CTRL

## Additional Interactions

- You can change every parameters related to the particle systems lile:
    - Particle Speed
    - Polar Speed
    - Alpha & Beta of the formulas
    - Frequency of emitted particles (particles/second)
    - Life Span of each particle (in seconds)
    - Maximum count of Particles
    - Change the Spiral Formula
- You can change the Display Mode on the `Display Mode`menu.
- You can change the FPS cap/limit
- You can change the Time multiplier (multiplies deltaTime)

# Code Architecture

The Complete Documentation is available in the project, in the Code Architecture part will only be explained a small description of what classes do.

## Documentation

There is a documentation available [here](https://kevinpruvost.github.io/ComputerGraphics_Assignment3/) or in `docs/index.html` if you want to have a better view on the classes I made.
