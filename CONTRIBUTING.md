# UAHEV Contributing Guidelines

General rule of thumb: Avoid doing/saying anything that could be mistaken as a Torvalds/Jobs/Gates rant

## Formatting and Neat-Freak things

Use the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html). Don't be pedantic, but try to be neat

To keep files formatted correctly, use the following guidelines:

`.h` template:
```Cpp
//
//  <filename>
//  MicroController
//
//  Created by <Your Name> on <MM>/<DD>/<YY>.
//  Copyright (c) 2018 - <YYYY> UAH Electric Vehicle Club
//  Licensed under Apache License v2.0
//
//  Put 2 to 3 sentences about what the class defined here
//  does. Note that the comments don't go too far (> 3)
//  past the "Copyright ..." line

// Ex: MICROCONTROLLER_DIRECTORYONE_DIRECTORYTWO_FILENAME_H_
#ifndef MICROCONTROLLER_PATH_WITH_UNDERSCORES_
#define MICROCONTROLLER_PATH_WITH_UNDERSCORES_

class <ClassName> {
  /* Change the World (TM) here... */
};

#endif // MICROCONTROLLER_PATH_WITH_UNDERSCORES_
```
