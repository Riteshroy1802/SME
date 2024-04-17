#pragma once
#include "../../header/Powerup/PowerupController.h"

namespace Powerup
{
    namespace Controller
    {
        class RapidFireController : public PowerupController
        {
        protected:
            void applyPowerup() override;

        public:
            RapidFireController(PowerupType type);
            virtual ~RapidFireController();
        };
    }
}