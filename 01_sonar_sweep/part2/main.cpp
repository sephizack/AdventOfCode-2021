#include "../../common.hpp"

using namespace std;

int main() {
    // Fast ios
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    uint aMeasure;
    uint idx=0
    vector<uint> aMesures;
    aMesures.resize(3000,0);
    while (cin>>aMeasure)
    {
        aMesures[idx] += aMeasure;
        aMesures[idx+1] += aMeasure;
        aMesures[idx+2] += aMeasure;
        ++idx;
    }
    aMesures.resize(idx-1);

    vector<uint> aWindowedMesures;
    for (int i=0 ; i<aMesures.size()-2 ; ++i)
    {
        aWindowedMesures.push_back(aMesures[i] + aMesures[i+1] + aMesures[i+2]);
    }    

    uint aRes=0;
    uint aPrev = -1;
    for(auto aWin : aMesures){
        if (aWin > aPrev)
        {
            ++aRes;
        }
        aPrev = aWin;
    }

    dbg(aRes);
    return 0;
}

