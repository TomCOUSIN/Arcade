/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#ifndef OOP_ARCADE_2018_ASSET_HPP
#define OOP_ARCADE_2018_ASSET_HPP

namespace displayModule
{
    class Asset
    {
        public:
            explicit Asset() = default;
            ~Asset() = default;
            void setPosition(int x, int y);
            void setAsset(void *asset);
            void *getAsset() const;
            int getXPosition() const;
            int getYPosition() const;

        private:
            void *_asset;
            int _x;
            int _y;
    };
};

#endif //OOP_ARCADE_2018_ASSET_HPP
