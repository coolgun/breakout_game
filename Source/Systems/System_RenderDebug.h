#pragma once
#include <memory>

#include "ecs/aaSystem.h"
#include "Components/Graphics/Component_Debug.h"


namespace game
{
    ///-------------------------------------------------------------------------
    ///-------------------------------------------------------------------------






     ///------------------------------------------------------------------------
    ///
    ///
    ///
    /// Система отрисовки компонентов
    /// для отладки
    ///
    ///
    ///-------------------------------------------------------------------------
    class ASystemRenderDebug
        :
        public ecs::ASystem<AComponentDebug>
    {
    public:


        ASystemRenderDebug();
        ~ASystemRenderDebug() override;



        ///-------------------------------------------------------------------------

    public:


        void draw(dm::ARender &render);
        void enabled(); //включить отладочную отрисовку
        void disabled(); //выключить отладочную отрисовку



        ///-------------------------------------------------------------------------

    private:

        bool mEnabled = { false }; //включение режима отрисовки


    };
    ///-------------------------------------------------------------------------




}