// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Component_Timer.h"
///-------------------------------------------------------------------------




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
AComponentTimer::AComponentTimer(const float time, const functor &signal)
    :
        mTime(time),
        mSignal(signal)
{

}
///-------------------------------------------------------------------------








 ///------------------------------------------------------------------------
///
/// <summary>
/// destructor
/// </summary>
///
///-------------------------------------------------------------------------
AComponentTimer::~AComponentTimer()
{

}
///-------------------------------------------------------------------------







 ///------------------------------------------------------------------------
///
/// <summary>
/// 
/// </summary>
///
///-------------------------------------------------------------------------
void AComponentTimer::update(const float timeSpan)
{
    mCurrent += timeSpan;
    if (mCurrent > mTime)
    {
        mCurrent = 0;
        if (mSignal)
        {
            mSignal(this);
        }
    }
}
///-------------------------------------------------------------------------


