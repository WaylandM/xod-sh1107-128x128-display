
#ifndef X_SH1107_H
#define X_SH1107_H

#include <Wire.h>
#include <XRender.h>


#define SH1107_DISPLAY_OFF 0xAE
#define SH1107_SET_DISPLAY_CLOCK 0xD5
#define SH1107_SET_MULTIPLEX_RATIO 0xA8
#define SH1107_SET_DISPLAY_OFFSET 0xD3
#define SH1107_SET_START_LINE 0x40
#define SH1107_CHARGE_DCDC_PUMP 0x8D
#define SH1107_ADDR_MODE 0x20
#define SH1107_SET_REMAP_L_TO_R 0xA1 
#define SH1107_SET_REMAP_T_TO_D 0xC8 
#define SH1107_SET_COM_PINS 0xDA
#define SH1107_SET_CONTRAST 0x81
#define SH1107_SET_PRECHARGE_PERIOD 0xD9
#define SH1107_SET_VCOM_DESELECT 0xDB
#define SH1107_RAM_ON 0xA4
#define SH1107_INVERT_OFF 0xA6
#define SH1107_DISPLAY_ON 0xAF
#define SH1107_ADDR_PAGE 0x22
#define SH1107_ADDR_COLUMN 0x21

#define SH1107_DISPLAY_WIDTH 128
#define SH1107_DISPLAY_HEIGHT 128

class SH1107 : public XRenderer {
public:
    SH1107(TwoWire* wire, uint8_t i2cAddress, uint8_t* buffer);

    int16_t getScreenWidth() const {
        return _width;
    }
    int16_t getScreenHeight() const {
        return _height;
    }

    void begin();
    void sendBuffer();
    void clearScreen();

    void renderScanlinePart(int16_t scanline, int16_t xmin, int16_t xmax, const uint16_t* lineBuffer) override;

private:
    TwoWire* _wire = nullptr;
    uint8_t _i2cAddress = 0x00;
    uint8_t* _buffer;
    int16_t _width = 0;
    int16_t _height = 0;

    void sendCommand(uint8_t command);
};

#endif // X_SH1107_H
