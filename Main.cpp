#include "Lock.h"
#include "TKPierce.h"

int Lock::sv;

TKPIERCE_BREAKDOWN(key_v, Lock, v, int);
TKPIERCE_BREAKDOWN_STATIC(key_sv, Lock, sv, int);
TKPIERCE_BREAKDOWN_FUNC(key_f, Lock, f, void, int, int);
TKPIERCE_BREAKDOWN_FUNC_STATIC(key_sf, Lock, sf, void, int, int);

#include <iostream>

int main()
{
    Lock a, b;

    SEIZE(a, key_v) = 100;
    SEIZE(b, key_v) = 110;

    std::cout << "a: " << SEIZE(a, key_v) << ", " << "b: " << SEIZE(b, key_v) << '\n';

    SEIZE_STATIC(key_sv) = 111;

    std::cout << "si: " << SEIZE_STATIC(key_sv) << '\n';

    SEIZE(a, key_f)(100, 100);
    SEIZE(b, key_f)(110, 110);

    std::cout << "a: " << SEIZE(a, key_v) << ", " << "b: " << SEIZE(b, key_v) << '\n';

    SEIZE_STATIC(key_sf)(111, 111);

    std::cout << "si: " << SEIZE_STATIC(key_sv) << '\n';
}
