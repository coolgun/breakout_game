// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Device.h"
#include <map>

float dm::deviceWidth()
{
    return 1024;
}


float dm::deviceHeight()
{
    return 768;
}



//����������� ��������
sf::Texture& loadImage(const std::string &name)
{
    static std::map<std::string, sf::Texture> textures;
    const auto item = textures.find(name);
    if (item != textures.end())
    {
        return item->second;
    }
    sf::Texture img;
    if (!img.loadFromFile("data/textures/" + name + ".png"))
    {
        throw "�� �������� ����";
    }
    img.setSmooth(true);
    return textures.emplace(name, std::move(img)).first->second;
}



//���������� ������
sf::Sprite dm::loadSprite(const std::string &name)
{
    sf::Sprite sprite;
    sprite.setTexture(loadImage(name));
    return sprite;
}