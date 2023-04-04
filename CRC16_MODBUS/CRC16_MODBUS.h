#pragma once

#ifndef	_CRC16_MODBUS_H
#define _CRC16_MODBUS_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */
	uint16_t CRC16_MODBUS_V1(const char* buffer, unsigned int length);
	uint16_t CRC16_MODBUS_V2(const char* buffer, unsigned int length);
	uint16_t CRC16_MODBUS_V3(const char* buffer, unsigned int length);
#ifdef __cplusplus
}
#endif /* __cplusplus  */
#endif