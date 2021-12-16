#include "../../common.hpp"

using namespace std;

int main() {
    // Fast ios
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    uint aMeasure;
    vector<uint> aMesures;
    while (cin>>aMeasure)
    {
        aMesures.push_back(aMeasure);
    }
    
    vector<uint> aWindowedMesures;
    for (int i=0 ; i<aMesures.size()-2 ; ++i)
    {
        aWindowedMesures.push_back(aMesures[i] + aMesures[i+1] + aMesures[i+2]);
        if (i<5) dbg(aWindowedMesures.back());
    }    

    uint aRes=0;
    uint aPrev = -1;
    for(auto aWin : aWindowedMesures){
        if (aWin > aPrev)
        {
            ++aRes;
        }
        aPrev = aWin;
    }

    dbg(aRes);
    return 0;
}

