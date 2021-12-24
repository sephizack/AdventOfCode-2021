#include "../../common.hpp"

using namespace std;

int main() {
    // Fast ios
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
    string bits;
    vector<vector<bool>> matrice;
    while (true)
    {
        if (!(cin>>bits)) break;
        vector<bool> line;
        for (char c : bits) {
            line.push_back(c=='1');
        }
        matrice.push_back(line);
    }

    vector<uint> counters;
    counters.resize(matrice[0].size());
    for (auto& line : matrice)
    {
        //dbg(line);
        for (uint i=0 ; i<line.size() ; ++i)
        {
            counters[i] += (line[i] ? 1 : 0);
        }
    }
    dbg(counters);

    vector<bool> gamma;
    vector<bool> epsilon;
    for (uint i=0 ; i<counters.size() ; ++i)
    {
        bool isgamma = counters[i] > matrice.size()/2;
        gamma.push_back(isgamma);
        epsilon.push_back(!isgamma);
    }
    dbg(gamma);
    dbg(epsilon);

    uint gammadecimal = 0;
    uint epsilondecimal = 0;
    for (uint i=0 ; i<gamma.size() ; ++i)
    {
        gammadecimal = gammadecimal << 1;
        gammadecimal += gamma[i] ? 1 : 0;
        epsilondecimal = epsilondecimal << 1;
        epsilondecimal += epsilon[i] ? 1 : 0;
    }

    dbg(gammadecimal);
    dbg(epsilondecimal);
    dbg(gammadecimal*epsilondecimal);
    return 0;
}

