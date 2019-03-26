cmake_minimum_required(VERSION 3.13)
project(OOP_arcade_2018)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/CoreProgram)
include_directories(src/CoreProgram/DLLoader)
include_directories(src/CoreProgram/launcher)
include_directories(src/DisplayModule)
include_directories(src/DisplayModule/DisplayModuleNcurses)
include_directories(src/DisplayModule/SDL2DisplayModule)
include_directories(src/DisplayModule/SDLDisplayModule)
include_directories(src/DisplayModule/SFMLDisplayModule)
include_directories(src/GameModule)
include_directories(src/GameModule/GameModuleNibbler)

add_executable(OOP_arcade_2018
        src/CoreProgram/DLLoader/DLLoader.hpp
        src/CoreProgram/DLLoader/DLLoaderException.cpp
        src/CoreProgram/DLLoader/DLLoaderException.hpp
        src/CoreProgram/launcher/launcher.cpp
        src/CoreProgram/launcher/launcher.hpp
        src/CoreProgram/launcher/launcherException.cpp
        src/CoreProgram/launcher/launcherException.hpp
        src/CoreProgram/coreProgram.cpp
        src/CoreProgram/coreProgram.hpp
        src/CoreProgram/coreProgramException.cpp
        src/CoreProgram/coreProgramException.hpp
        src/DisplayModule/DisplayModuleNcurses/DisplayModuleNcurses.cpp
        src/DisplayModule/DisplayModuleNcurses/DisplayModuleNcurses.hpp
        src/DisplayModule/DisplayModuleNcurses/DisplayModuleNcursesException.cpp
        src/DisplayModule/DisplayModuleNcurses/DisplayModuleNcursesException.hpp
        src/DisplayModule/SDL2DisplayModule/SDL2DisplayModule.hpp
        src/DisplayModule/SDL2DisplayModule/SDL2DisplayModule.cpp
        src/DisplayModule/SDLDisplayModule/SDLDisplayModule.cpp
        src/DisplayModule/SDLDisplayModule/SDL2DisplayModule.hpp
        src/DisplayModule/SFMLDisplayModule/Sfml_module.cpp
        src/DisplayModule/SFMLDisplayModule/Sfml_module.hpp
        src/DisplayModule/IDisplayModule.hpp
        src/GameModule/GameModuleNibbler/GameModuleNibbler.cpp
        src/GameModule/GameModuleNibbler/GameModuleNibbler.hpp
        src/GameModule/GameModuleNibbler/GameModuleNibblerException.cpp
        src/GameModule/GameModuleNibbler/GameModuleNibblerException.hpp
        src/GameModule/IGameModule.hpp
        src/main.cpp)
