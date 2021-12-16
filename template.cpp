#include "../../common.hpp"

int main() {
    // Fast ios
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> aVect = {1,2,3,4};
    dbg(aVect);

    pair<int, string> aPair = {1,"coucou"};
    dbg(aPair);

    return 0;
}

