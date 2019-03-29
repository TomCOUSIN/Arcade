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
#include <SFML/Audio.hpp>

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
            void clearScreen() final;
            //Events
            e_event catchEvent() final;

            //Sounds
            void createSound(const std::string &path, const std::string &soundKey) final;
            void startSound(const std::string &soundKey) final;
            void stopSound(const std::string &soundKey) final;

            sf::RenderWindow _window;
            sf::Event _event;
            sf::Texture _texture;
        protected:
        private:
        std::unordered_map<std::string, sf::Texture> umap_sfmlsprite_asset;
        std::unordered_map<std::string, std::string> umap_sfmltext_asset;
    };
}

#endif /* !SFML_MODULE_HPP_ */
