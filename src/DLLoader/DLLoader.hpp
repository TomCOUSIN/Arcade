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
            void loadLibrary(const std::string &path);
            void closeLibrary();
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
void dlloader::DLLoader<T>::loadLibrary(const std::string &path)
{
    _handle = dlopen(path.data(), (RTLD_NOW | RTLD_LAZY));
    if (!_handle)
        throw DLLoaderException(dlerror());
}

/**
 * Close the linked library
 * @param void
 * @return void
 */
template <class T>
void dlloader::DLLoader<T>::closeLibrary()
{
    if (dlclose(_handle) != 0)
        throw DLLoaderException(dlerror());
}

/**
 * Get instance from linked library
 * @param void
 * @return std::shared_ptr<T>
 */
template <class T>
std::shared_ptr<T> dlloader::DLLoader<T>::getInstance()
{
    using allocClass = T *(*)();
    using deleteClass = void (*)(T *);

    auto allocator = reinterpret_cast<allocClass>(dlsym(_handle, "allocator"));
    auto destructor = reinterpret_cast<deleteClass >(dlsym(_handle, "deleter"));

    if (allocator == nullptr || destructor == nullptr) {
        closeLibrary();
        throw DLLoaderException(dlerror());
    }
    return std::shared_ptr<T>(allocator(), [destructor](T *p){ destructor(p);});
}

#endif //OOP_ARCADE_2018_DLLOADER_HPP
