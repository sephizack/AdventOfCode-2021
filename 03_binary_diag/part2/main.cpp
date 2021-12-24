#include "../../common.hpp"

using namespace std;

vector<vector<bool>*> filter(vector<vector<bool>*>& input, uint curbit, bool isoxy){
    vector<vector<bool>*> zero;
    vector<vector<bool>*> un;
    for(auto* line : input){
        ((*line)[curbit] ? un : zero).push_back(line);
    }
    if (isoxy) {
        return un.size() >= zero.size() ? un : zero;
    }
    else {
        return un.size() < zero.size() ? un : zero;
    }
}

int main() {
    // Fast ios
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string bits;
    vector<vector<bool>*> matriceOxy;
    while (true)
    {
        if (!(cin>>bits)) break;
        vector<bool>* line = new vector<bool>; // Heavy leak
        for (char c : bits) {
            line->push_back(c=='1');
        }
        matriceOxy.push_back(line);
    }
    vector<vector<bool>*> matriceCo2 = matriceOxy;

    uint curbit = 0;
    while(matriceOxy.size()>1)
    {
        matriceOxy = filter(matriceOxy, curbit++, true);
    }
    curbit = 0;
    while(matriceCo2.size()>1)
    {
        matriceCo2 = filter(matriceCo2, curbit++, false);
    }

    uint oxydecimal = 0;
    uint co2decimal = 0;
    for (uint i=0 ; i<matriceOxy[0]->size() ; ++i)
    {
        oxydecimal = oxydecimal << 1;
        oxydecimal += (*matriceOxy[0])[i] ? 1 : 0;
        co2decimal = co2decimal << 1;
        co2decimal += (*matriceCo2[0])[i] ? 1 : 0;
    }

    dbg(oxydecimal);
    dbg(co2decimal);
    dbg(oxydecimal*co2decimal);
    return 0;
}

