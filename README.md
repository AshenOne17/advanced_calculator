# Advanced Calculator Omega

This program has **4 different modes**:
- Arithmetic calculations (+, -, *, /).
- Trigonometry calculations (sin(), cos(), tg(), ctg())
- Exponential calculations (power(), root())
- Logarithmic calculations (log(), ln())

The program includes error handling for invalid inputs and provides a user-friendly interface for conducting calculations. The code is written in C++ and utilizes object-oriented programming techniques, making it easy to expand and maintain in the future. Using templates as well. Minimal markdown for making the interface user-friendly. Looking forward into the future to add possibility of complex calculations, extra error handling, calculation on different unit measures, etc.

## Program building
In case you cloned the project to make a commit or to build it, and you are using **Microsoft Visual Studio ©**, there is a chance that VS will not recognize default `include` directories. To include them, go through these steps:

1. Open project file `advanced_calculator.sln`.
2. Enable `Solution Explorer` by pressing combination of `Ctrl+Alt+L`, or by going through `View->Solution Explorer`.
3. Click RMB on `advanced_calculation` solution file in the opened Solution Explorer window.
4. Scroll down and click on `Properties`.
5. Go through `Configuration Properties->VC++ Directories->General` and click on `Include Directories` to get a dropdown arrow, click on it and on 'Edit'.
6. Click the folder image (`New Line (Ctrl-Insert)`) and on three dots afterwards to locate the header directories.
7. Choose the `Header Files` from the root project folder.

After these steps, the project should build in both `Debug` and `Releaase` configurations, as well as both on `x86` and `x64` platforms.

In case everything works, **don't change** the default solution properties.
