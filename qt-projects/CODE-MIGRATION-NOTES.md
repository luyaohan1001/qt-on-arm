# Sometimes the projects are created on x86-64 QT Creator 4.12.2 (Based on QT 5.14.2) and codes can be reused on raspberry pi 4B, QT Creator 4.12.1 (also based on QT 5.15.2). However, the compilation environment is different on the two platforms.

# The configure button might be greyed about, we need to set the compiler right:
  Tool > Options > Kits > Manual > Desktop > Compiler

      C: GCC (C, arm 64bit in /usr/bin)
      C++: GCC (C++, arm 64bit in /usr/bin)
