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
#include "../../core/serial.h"
#include "../../module/printcounter.h"
#include "../../libs/duration_t.h"
#include "../../lcd/ultralcd.h"

/** \addtogroup G-Codes
 * @{
 */

/**
 *### M31: Get the time since the start of SD Print (or last M109) <a href="https://reprap.org/wiki/G-code#M31:_Output_time_since_last_M109_or_SD_card_start_to_serial">M31: Output time since last M109 or SD card start to serial</a>
 *
 *#### Usage
 *
 *    M31
 *
 */
void GcodeSuite::M31() {
  char buffer[22];
  duration_t(print_job_timer.duration()).toString(buffer);

  ui.set_status(buffer);

  SERIAL_ECHO_START();
  SERIAL_ECHOLNPAIR("Print time: ", buffer);
}

/** @}*/
