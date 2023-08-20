#include "launchelf.h"

u8 hwinfo_get_mechacon_version(u32 *mechaconId)
{
	u8 in_buffer = 0;
	u8 out_buffer[16] = { 0 };
	if (sceCdApplySCmd(0x03, &in_buffer, sizeof(in_buffer), out_buffer)) {
		*mechaconId = *(uint32_t *)out_buffer;
		return TRUE;
	}

	return FALSE;
}

u8 hwinfo_get_temperature(u16 *decTemp)
{
	u8 in_buffer = 0xEF;
	u8 out_buffer[16] = { 0 };
	if (!sceCdApplySCmd(0x03, &in_buffer, sizeof(in_buffer), out_buffer)) {
		return FALSE;
	}
	if (out_buffer[0] != 0) {
		return FALSE;
	}

	*decTemp = (out_buffer[1] << 8) | out_buffer[2];
	return TRUE;
}
