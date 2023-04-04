#include "common.h"

static void entity()
{
	Timer timer;

#ifdef _DEBUG
	std::cout << "Debuging...\n";
#endif

	const char data[] = { 0x01, 0x08, 0x00, 0x02, 0x00, 0x00 };
	uint16_t expected = 52033;

	int algorithm = 3;
	uint16_t(*func)(const char*, unsigned int);
	uint16_t res = 0;

	switch (algorithm)
	{
	case 1: func = CRC16_MODBUS_V1; break;
	case 2: func = CRC16_MODBUS_V2; break;
	case 3: func = CRC16_MODBUS_V3; break;
	default: std::cout << "Failed selected algorithm.\n"; return;
	}

	auto start = std::chrono::high_resolution_clock::now();
	for (auto i = 0; i < 10000; i++) res = func(data, length(data));
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> dr = end - start;

	std::cout << "Time taken to execute algorithm " << algorithm << ": " << dr.count() * 1000.0f << " ms" << std::endl;

	std::cout << "Dec: " << res << "\n" << std::hex << "HEX: " << "0x" << res << "\n";
	if (res == expected) { std::cout << "Match! Test complete." << std::endl; }
	else { std::cout << "Checksums don't match." << std::endl; }
}

int main()
{
	entity();
	std::cin.get();
}
   