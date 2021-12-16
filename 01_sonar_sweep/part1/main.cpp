#include "../../common.hpp"

using namespace std;

int main() {
    // Fast ios
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    uint aRes=0;
    uint aMeasure=-1;
    uint aNewMeasure=-1;
    while (cin>>aNewMeasure)
    {
        if (aNewMeasure > aMeasure) {
            ++aRes;
        }
        aMeasure = aNewMeasure;
    }

    dbg(aRes);
    return 0;
}

