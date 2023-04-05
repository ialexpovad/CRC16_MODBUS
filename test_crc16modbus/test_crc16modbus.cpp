
#include "test.h"
#include "../CRC16_MODBUS/CRC16_MODBUS.h"


TEST(CRC16Test, BasicTest)
{
    const char data[] = { 0x01, 0x08, 0x00, 0x02, 0x00, 0x00 };
    uint16_t expected = 52033;

    EXPECT_EQ(CRC16_MODBUS_V3(data, length(data)), expected);

}