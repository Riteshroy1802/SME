#include "../../header/Powerup/Controller/TrippleLaserController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Powerup
{
    namespace Controller
    {
        using namespace Global;

        TrippleLaserController::TrippleLaserController(PowerupType type) : PowerupController(type) {}

        TrippleLaserController::~TrippleLaserController() {}

        void TrippleLaserController::applyPowerup()
        {
            ServiceLocator::getInstance()->getPlayerService()->enableTrippleLaser();
        }
    }
}