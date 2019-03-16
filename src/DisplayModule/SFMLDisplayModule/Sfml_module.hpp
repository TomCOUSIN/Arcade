/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sfml_module
*/

#ifndef SFML_MODULE_HPP_
    #define SFML_MODULE_HPP_
#include "../IDisplayModule.hpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>

namespace displayModule {
    class Sfml_module : public IDisplayModule {
        public:

            //C_TOR
            Sfml_module();
            //D_TOR
            ~Sfml_module() final;
            
            //Sprites
            void refreshWindow() final;
            bool drawAsset(const std::string &assetName, int x, int y) final;
            bool createAsset(const std::string &path, const std::string &assetName) final;
            bool createText(const std::string &text, const std::string &textName) final;
            bool drawText(const std::string &textName, int x, int y) final;
            //Events
            e_event catchEvent() final;

            //Sounds
            void start_sound() final;
            void stop_sound() final;

            sf::RenderWindow _window;
            sf::Event _event;
            sf::Texture _texture;
            sf::Sprite _sprite;
            sf::Font _font;
            sf::Text _text;
        protected:
        private:
        std::unordered_map<std::string, sf::Texture> umap_sfmlsprite_asset;
        std::unordered_map<std::string, std::string> umap_sfmltext_asset;
    };
}

extern "C"
{
    displayModule::Sfml_module *allocator()
    {
        return new displayModule::Sfml_module();
    }

    void deleter(displayModule::Sfml_module *ptr)
    {
        delete  ptr;
    }
}


#endif /* !SFML_MODULE_HPP_ */
