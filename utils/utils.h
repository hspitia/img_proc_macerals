#ifndef UTILS_H
#define UTILS_H

#include <cmath>

inline double round(double number)
{
    return number < 0.0 ? ceil(number - 0.5) : floor(number + 0.5);
}

inline double round(float number)
{
    return number < 0.0 ? ceil(number - 0.5) : floor(number + 0.5);
}

inline double levelRound(double number, int maxLevel=255)
{
    double out = number < 0.0 ? ceil(number - 0.5) : floor(number + 0.5);
		if (out > maxLevel) return maxLevel;
    return out;
}

inline double levelRound(float number, int maxLevel=255)
{
		float out = number < 0.0 ? ceil(number - 0.5) : floor(number + 0.5);
		if (out > maxLevel) return maxLevel;
    return out;
}

#endif        //  #ifndef UTILS_H

