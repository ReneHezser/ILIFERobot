#ifndef __pinTime_H__
#define __pinTime_H__

#include <Arduino.h>
#include <Structs.h>

void initPinTimer(pinTime &pin, int pin_number, size_t readings);
void calcPinTime(pinTime &pin, unsigned int timeout);
int calculateAverageValue(pinTime &pin);

#endif