#pragma once

#include <device/board.h>
#include <option/has_loadcell.h>
#include <option/has_modularbed.h>

// this struct collects data from metrics and gives access to the
// sensor info screen
struct SensorData {
private:
    friend SensorData &sensor_data();

    SensorData() = default;
    SensorData(SensorData &other) = delete;
    SensorData(SensorData &&other) = delete;

public:
    float MCUTemp;
    float boardTemp;
    float hbrFan;
    float inputVoltage;
#if BOARD_IS_XLBUDDY()
    float sandwich5VVoltage;
    float sandwich5VCurrent;
    float buddy5VCurrent;
    float dwarfBoardTemperature;
    float dwarfMCUTemperature;
#elif BOARD_IS_XBUDDY()
    float heaterVoltage;
    float heaterCurrent;
    float inputCurrent;
    float mmuCurrent;
#else
#endif
#if PRINTER_IS_PRUSA_COREONE()
    uint32_t door_sensor;
#endif
#if HAS_LOADCELL()
    float loadCell;
#endif
#if HAS_MODULARBED()
    float mbedMCUTemperature;
#endif
};

SensorData &sensor_data();
