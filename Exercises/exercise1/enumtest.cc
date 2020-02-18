#include "eyes.h"
#include "traffic_light.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    traffic_light tl1 {red};
    print(tl1);
    traffic_light tl2 {green};
    print(tl2);

    eye_colour e1{green};
    print(e1);
    eye_colour e2{blue};
    print(e2);

    tl1 = static_cast<traffic_light>(4);
    print(tl1);

    return 0;
}
