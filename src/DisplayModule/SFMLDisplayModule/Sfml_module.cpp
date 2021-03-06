/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sfml_module
*/

/**
 * @file SFMLDisplayModule.cpp
 */


#include <memory>
#include "Sfml_module.hpp"

/**
 * Constructor : open the sfml window
 */
displayModule::Sfml_module::Sfml_module() : _window(sf::VideoMode(1920, 1080), "Arcade")
{
}

/**
 * Destructor : close the sfml window
 */
displayModule::Sfml_module::~Sfml_module()
{
    this->_window.close();
}

/**
 * refreshWindow : refresh the sfml window
 */
void displayModule::Sfml_module::refreshWindow()
{
    this->_window.display();
    this->_window.clear();
}

/**
 * catchEvent: function which catch the event of the keypad and return a enum e_event for the keypad
 * @return the pattern of the correct enum for the keypad event
 */
displayModule::e_event displayModule::Sfml_module::catchEvent()
{
    while (this->_window.pollEvent(this->_event)) {
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
            if (this->_event.key.code == sf::Keyboard::Q)
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
            if (this->_event.key.code == sf::Keyboard::Return)
                return ENTER;
            if (this->_event.key.code == sf::Keyboard::Escape)
                return ESCAPE;
        }
        if (this->_event.type == sf::Event::Closed) {
            _window.close();
            return ESCAPE;
        }
    }
    return NOTHING;
}

/**
 * createAsset : function which create the asset in the unordered_map
 * @param path : path to the asset : toto/1d/map.txt
 * @param assetName : name of the asset
 * @return true
 */
bool displayModule::Sfml_module::createAsset(const std::string &path, const std::string &assetName)
{
    std::string true_name = path + "/2d/" + assetName + ".png";
    this->_texture.loadFromFile(true_name);
    if (umap_sfmlsprite_asset.find(assetName) != umap_sfmlsprite_asset.end())
        umap_sfmlsprite_asset[assetName] = _texture;
    else
        umap_sfmlsprite_asset.insert(std::pair<std::string, sf::Texture>(assetName, this->_texture));
    return true;
}

/**
 * drawAsset : function which draw the asset in the sfml window
 * @param assetName : name of the asset
 * @param x : horizontal coordinates of the asset in the sfml window
 * @param y : vertical coordinates of the asset in the sfml window
 * @return false if it's can't draw the asset
 * @return true if it's can draw the asset
 */
bool displayModule::Sfml_module::drawAsset(const std::string &assetName, int x, int y)
{
    if (umap_sfmlsprite_asset.find(assetName) == umap_sfmlsprite_asset.end())
        return false;
    sf::Sprite sprite;
    sprite.setTexture(umap_sfmlsprite_asset.find(assetName)->second);
    sprite.setPosition(x * 32, y * 32);
    this->_window.draw(sprite);
    return true;
}

/**
 * createText : function which create a text in an unordered_map
 * @param text : text to draw!!
 * @param assetName : key to find the text in the unordered_map
 * @return true because no error
 */
bool displayModule::Sfml_module::createText(const std::string &text, const std::string &textName)
{
    if (umap_sfmltext_asset.find(textName) != umap_sfmltext_asset.end())
        umap_sfmltext_asset[textName] = text;
    else
        umap_sfmltext_asset.insert(std::pair<std::string, std::string>(textName, text));
    return true;
}

/**
 * drawText : function which draw the text in the sfml window
 * @param textName : key of the text name
 * @param x : horizontal coordinates of the text in the sfml window
 * @param y : vertical coordinates of the text in the sfml window
 * @return false if it's can't draw the text
 * @return true because no error
 */
bool displayModule::Sfml_module::drawText(const std::string &textName, int x, int y)
{
    if (umap_sfmltext_asset.find(textName) == umap_sfmltext_asset.end())
        return false;
    sf::Text text;
    sf::Font font;
    font.loadFromFile("./.fonts/default.ttf");
    text.setFont(font);
    text.setString(umap_sfmltext_asset.find(textName)->second);
    text.setPosition(x * 16, y * 16);
    this->_window.draw(text);
    return true;
}

/**
 * clearScreen : clear the sfml window
 */
void displayModule::Sfml_module::clearScreen()
{
    this->_window.clear();
}

/**
 * startSound : start the sound
 */
void displayModule::Sfml_module::startSound(const std::string &soundKey)
{ (void)soundKey; }

/**
 * stopSound : stop the sound
 */
void displayModule::Sfml_module::stopSound(const std::string &soundKey)
{ (void)soundKey; }

/**
 * createSound : create the sound
 */
void displayModule::Sfml_module::createSound(const std::string &path,
    const std::string &soundKey)
{ (void)path; (void)soundKey; }

extern "C"
{
    std::shared_ptr<displayModule::Sfml_module> allocator()
    {
        return std::make_shared<displayModule::Sfml_module>();
    }
}