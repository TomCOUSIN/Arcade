/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#ifndef OOP_ARCADE_2018_DLLOADER_HPP
#define OOP_ARCADE_2018_DLLOADER_HPP

/**
 * @file DLLoader.hpp
 */

#include <dlfcn.h>
#include "IDisplayModule.hpp"
#include "DLLoaderException.hpp"
#include <iostream>
#include <memory>

namespace dlloader
{
    /**
     * Templated class for DLLoader
     */
    template <class T>
    class DLLoader
    {
        public:
            /*! Constructor */
            DLLoader() = default;
            /*! Destructor */
            ~DLLoader() = default;
            bool loadLibrary(const std::string &path);
            bool closeLibrary();
            std::shared_ptr<T> getInstance();

        private:
            void *_handle;
    };
}

/**
 * Load the library passed as parameter
 * @param const std::string &path
 * @return void
 */
template <class T>
bool dlloader::DLLoader<T>::loadLibrary(const std::string &path)
{
    try {
        _handle = dlopen(path.data(), (RTLD_NOW | RTLD_LAZY));
        if (!_handle)
            throw DLLoaderException(dlerror());
        return true;
    }
    catch (const DLLoaderException &exception) {
        std::cerr << exception.getComponent() << ": " << exception.what() << std::endl;
        return false;
    }
}

/**
 * Close the linked library
 * @param void
 * @return void
 */
template <class T>
bool dlloader::DLLoader<T>::closeLibrary()
{
    try {
        if (dlclose(_handle) != 0)
            throw DLLoaderException(dlerror());
        return true;
    }
    catch (const DLLoaderException &exception) {
        std::cerr << exception.getComponent() << ": " << exception.what() << std::endl;
        return false;
    }
}

/**
 * Get instance from linked library
 * @param void
 * @return std::shared_ptr<T>
 */
template <class T>
std::shared_ptr<T> dlloader::DLLoader<T>::getInstance()
{
    using allocClass = std::shared_ptr<T>(*)();

    try {
        auto allocator = reinterpret_cast<allocClass>(dlsym(_handle,"allocator"));

        if (!allocator) {
            closeLibrary();
            throw DLLoaderException(dlerror());
        }
        return allocator();
    }
    catch (const DLLoaderException &exception) {
        std::cerr << exception.getComponent() << ": " << exception.what() << std::endl;
        return nullptr;
    }
}

#endif //OOP_ARCADE_2018_DLLOADER_HPP
