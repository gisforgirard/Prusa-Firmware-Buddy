/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "../gcode.h"
#include "../../module/temperature.h"

/** \addtogroup G-Codes
 * @{
 */

/**
 *### M105: Read hot end and bed temperature <a href="https://reprap.org/wiki/G-code#M105:_Get_Extruder_Temperature">M105: Get Extruder Temperature</a>
 *
 * Request a temperature report to be sent to the host as soon as possible.
 *
 *#### Usage
 *
 *    M105 [ T | R ]
 *
 *#### Parameters
 *
 * - `T` - Tool
 * - `R` - Include the Redundant temperature sensor (not active)
 */
void GcodeSuite::M105() {

  const int8_t target_extruder = get_target_extruder_from_command();
  if (target_extruder < 0) return;

  SERIAL_ECHOPGM(MSG_OK);

  #if HAS_TEMP_SENSOR

    thermalManager.print_heater_states(target_extruder
      #if ENABLED(TEMP_SENSOR_1_AS_REDUNDANT)
        , parser.boolval('R')
      #endif
    );

    SERIAL_EOL();

  #else

    SERIAL_ECHOLNPGM(" T:0"); // Some hosts send M105 to test the serial connection

  #endif
}

/** @}*/
