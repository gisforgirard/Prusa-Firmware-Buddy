#pragma once

#include <enum_array.hpp>

enum class Unit : uint8_t {
    none,
    percent,
    celsius,
    hour,
    second,
    hertz,
    millimeter,
    micrometer,
    milliamper,
    _cnt,
};

static constexpr EnumArray<Unit, const char *, Unit::_cnt> units_str {
    { Unit::none, "" },
    { Unit::percent, "%" },
    { Unit::celsius, "\xC2\xB0\x43" },
    { Unit::hour, "h" },
    { Unit::second, "s" },
    { Unit::hertz, "Hz" },
    { Unit::millimeter, "mm" },
    { Unit::micrometer, "um" },
    { Unit::milliamper, "mA" },
};
