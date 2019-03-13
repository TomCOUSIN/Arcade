/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#ifndef OOP_ARCADE_2018_DLLOADER_HPP
#define OOP_ARCADE_2018_DLLOADER_HPP

#include <dlfcn.h>
#include "IDisplayModule.hpp"
#include "DLLoaderException.hpp"
#include <iostream>
#include <memory>

namespace dlloader
{
    template <class T>
    class DLLoader
    {
        public:
            DLLoader() = default;
            ~DLLoader() = default;
            void loadLibrary(const std::string &path);
            void closeLibrary();
            std::shared_ptr<T> getInstance();

        private:
            void *_handle;
    };
}

template <class T>
void dlloader::DLLoader<T>::loadLibrary(const std::string &path)
{
    _handle = dlopen(path.data(), (RTLD_NOW | RTLD_LAZY));
    if (!_handle)
        throw DLLoaderException(dlerror());
}

template <class T>
void dlloader::DLLoader<T>::closeLibrary()
{
    if (dlclose(_handle) != 0)
        throw DLLoaderException(dlerror());
}

template <class T>
std::shared_ptr<T> dlloader::DLLoader<T>::getInstance()
{
    using allocClass = T *(*)();
    using deleteClass = void (*)(T *);

    auto allocator = reinterpret_cast<allocClass>(dlsym(_handle, "allocator"));
    auto destructor = reinterpret_cast<deleteClass >(dlsym(_handle, "destructor"));

    if (allocator == nullptr || destructor == nullptr) {
        closeLibrary();
        throw DLLoaderException(dlerror());
    }
    return std::shared_ptr<T>(allocator(), [destructor](T *p){ destructor(p);});
}

#endif //OOP_ARCADE_2018_DLLOADER_HPP
