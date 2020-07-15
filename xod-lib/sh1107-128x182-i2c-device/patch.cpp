// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/WaylandM/xod-sh1107-128x128-display"

// clang-format off
{{#global}}
#include <SH1107.h>
{{/global}}
// clang-format on

struct State {
    uint8_t mem[sizeof(SH1107)];
    uint8_t buffer[SH1107_DISPLAY_WIDTH * SH1107_DISPLAY_HEIGHT / 8];
};

using Type = SH1107*;

// clang-format off
{{ GENERATED_CODE }}
// clang-format on

void evaluate(Context ctx) {
    if (!isSettingUp())
        return;

    auto state = getState(ctx);

    auto i2c = getValue<input_I2C>(ctx);
    uint8_t addr = getValue<input_ADDR>(ctx);

    if (addr > 127) {
        raiseError(ctx);
        return;
    }

    Type dev = new (state->mem) SH1107(i2c, addr, state->buffer);

    dev->begin();
    dev->clearScreen();

    emitValue<output_DEV>(ctx, dev);
}
