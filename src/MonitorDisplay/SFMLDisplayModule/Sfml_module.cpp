/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sfml_module
*/

#include "Sfml_module.hpp"

displayModule::Sfml_module::Sfml_module() : _window(sf::VideoMode(800, 600), "SFML window")
{
}

displayModule::Sfml_module::~Sfml_module()
{
    this->_window.close();
}

void displayModule::Sfml_module::refreshWindow()
{
    this->_window.display();
    this->_window.clear();
 }
displayModule::e_event displayModule::Sfml_module::catchEvent()
{
    this->_window.pollEvent(this->_event);
    if (this->_event.type == sf::Event::KeyPressed) {

        if (this->_event.key.code == sf::Keyboard::Up)
            return ARROW_UP;
        if (this->_event.key.code == sf::Keyboard::Down)
            return ARROW_DOWN;
        if (this->_event.key.code == sf::Keyboard::Right)
            return ARROW_RIGHT;
        if (this->_event.key.code == sf::Keyboard::Left)
            return ARROW_LEFT;
        if (this->_event.key.code == sf::Keyboard::A)
            return KEY_A;
        if (this->_event.key.code == sf::Keyboard::B)
            return KEY_B;
        if (this->_event.key.code == sf::Keyboard::C)
            return KEY_C;
        if (this->_event.key.code == sf::Keyboard::D)
            return KEY_D;
        if (this->_event.key.code == sf::Keyboard::E)
            return KEY_E;
        if (this->_event.key.code == sf::Keyboard::F)
            return KEY_F;
        if (this->_event.key.code == sf::Keyboard::G)
            return KEY_G;
        if (this->_event.key.code == sf::Keyboard::H)
            return KEY_H;
        if (this->_event.key.code == sf::Keyboard::I)
            return KEY_I;
        if (this->_event.key.code == sf::Keyboard::J)
            return KEY_J;
        if (this->_event.key.code == sf::Keyboard::K)
            return KEY_K;
        if (this->_event.key.code == sf::Keyboard::L)
            return KEY_L;
        if (this->_event.key.code == sf::Keyboard::M)
            return KEY_M;
        if (this->_event.key.code == sf::Keyboard::N)
            return KEY_N;
        if (this->_event.key.code == sf::Keyboard::O)
            return KEY_O;
        if (this->_event.key.code == sf::Keyboard::P)
            return KEY_P;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            return KEY_Q;
        if (this->_event.key.code == sf::Keyboard::R)
            return KEY_R;
        if (this->_event.key.code == sf::Keyboard::S)
            return KEY_S;
        if (this->_event.key.code == sf::Keyboard::T)
            return KEY_T;
        if (this->_event.key.code == sf::Keyboard::U)
            return KEY_U;
        if (this->_event.key.code == sf::Keyboard::V)
            return KEY_V;
        if (this->_event.key.code == sf::Keyboard::W)
            return KEY_W;
        if (this->_event.key.code == sf::Keyboard::X)
            return KEY_X;
        if (this->_event.key.code == sf::Keyboard::Y)
            return KEY_Y;
        if (this->_event.key.code == sf::Keyboard::Z)
            return KEY_Z;
        if (this->_event.key.code == sf::Keyboard::Space)
            return SPACE;
        if (this->_event.key.code == sf::Keyboard::BackSpace)
            return ENTER;
        if (this->_event.key.code == sf::Keyboard::Escape)
            return ESCAPE;
    }
    if (this->_event.type == sf::Event::Closed) {
        return ESCAPE;
    }
    return NOTHING;                
}

void displayModule::Sfml_module::start_sound()
{
}

void displayModule::Sfml_module::stop_sound()
{
}

bool displayModule::Sfml_module::createAsset(const std::string &path, const std::string &assetName)
{
    std::string true_name = path + "/2d/" + assetName;
    this->_texture.loadFromFile(true_name);
    umap_sfmlsprite_asset.insert(std::pair<std::string, sf::Texture>(assetName, this->_texture));
    return true;
}

bool displayModule::Sfml_module::drawAsset(const std::string &assetName, int x, int y)
{
    this->_sprite.setTexture(umap_sfmlsprite_asset.find(assetName)->second);
    this->_sprite.setPosition(x, y); 
    this->_window.draw(this->_sprite);
    return true;
}

bool displayModule::Sfml_module::createText(const std::string &text, const std::string &textName)
{
    umap_sfmltext_asset.insert(std::pair<std::string, std::string>(textName, text));
    return true;
}

bool displayModule::Sfml_module::drawText(const std::string &textName, int x, int y)
{
    this->_font.loadFromFile("./Games/asset/arial.ttf");
    this->_text.setFont(this->_font);
    this->_text.setString(umap_sfmltext_asset.find(textName)->second);
    this->_text.setPosition(x, y);
    this->_window.draw(this->_text);
    return true;
}