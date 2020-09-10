#pragma once
#include <memory>
#include <string>
#include <vector>


#include "Component_Collision.h"

namespace game
{
    ///-------------------------------------------------------------------------
    ///-------------------------------------------------------------------------





     ///------------------------------------------------------------------------
    ///
    /// <summary>
    /// Обработчик столкновения с физ объектом
    /// при столкновении покажем эффект
    /// </summary>
    ///
    ///
    ///-------------------------------------------------------------------------
    class AComponentCLLEffect
        :
        public AComponentCollision
    {
        using super = AComponentCollision;

    public:

        AComponentCLLEffect(const std::string &effectName);
        ~AComponentCLLEffect() override;

        void changeComponents() override; //компаненты поменялись, чтото добавилось, чтото удалилось


    public:

        bool collision(const std::vector<FPoint> &contacts, const PComponentBody &body)override;//обработка контакта взаимодействия

    private:

        std::string mEffectName;

        PComponentBody mLastContact;

    };
    ///-------------------------------------------------------------------------


 

}
