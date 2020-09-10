// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Component_ShapeCircle.h"
#include "Component_Body.h"
#include "MathUtils.h"




///-------------------------------------------------------------------------
using namespace game;
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
///
/// Constructor
///
///
///-------------------------------------------------------------------------
AComponentShapeCircle::AComponentShapeCircle(const float radius)
    :
    mRadius(radius)
{

}
///-------------------------------------------------------------------------








 ///------------------------------------------------------------------------
///
/// <summary>
/// инциализация
/// </summary>
///
///-------------------------------------------------------------------------
void AComponentShapeCircle::initialize()
{
    computeMass( 1.0f );
}
///-------------------------------------------------------------------------






 ///------------------------------------------------------------------------
///
/// <summary>
/// подсчитать массу объекта 
/// </summary>
///
///-------------------------------------------------------------------------
void AComponentShapeCircle::computeMass(const float density)
{
    const float mass = math::PI * mRadius * mRadius * density;
    const float inertia = mass * mRadius * mRadius;

    if (const auto body = findComponent<AComponentBody>())
    {
        body->setMass(mass, inertia);
    }
}
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
/// <summary>
/// ориентация объекта
/// </summary>
///
///-------------------------------------------------------------------------
void AComponentShapeCircle::setAngleRadian(const float radians)
{

}
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
/// <summary>
/// радиус круга
/// </summary>
///
///-------------------------------------------------------------------------
float AComponentShapeCircle::radius()const
{
    return mRadius;
}
///-------------------------------------------------------------------------




 ///------------------------------------------------------------------------
///
/// <summary>
/// ограничиваюшая рамка элемента
/// </summary>
///
///-------------------------------------------------------------------------
FPoint AComponentShapeCircle::boundingSize() const
{
    return { mRadius * 2.0f, mRadius * 2.0f };
}
///-------------------------------------------------------------------------







 ///------------------------------------------------------------------------
///
/// <summary>
/// Самая последния точка вдоль направления внутри многоугольника
/// </summary>
///
///-------------------------------------------------------------------------
FPoint AComponentShapeCircle::getSupport(const FPoint &dir) const
{
    auto d = dir;
    d.normalize();
    d = d * mRadius;
    return d;
}
///-------------------------------------------------------------------------
