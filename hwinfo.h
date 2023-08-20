#ifndef _HWINFO_H
#define _HWINFO_H

// Reads version from mechacon
u8 hwinfo_get_mechacon_version(u32 *mechaconId);

// Reads system temperature from mechacon
// @param decTemp Raw temperature form mechacon will be written here.
//                Value should be in deg. celsius, last 7 bits are used for .99 decimal part
// @returns TRUE if the command succeded 
u8 hwinfo_get_temperature(u16 *decTemp);

#endif // _HWINFO_H
