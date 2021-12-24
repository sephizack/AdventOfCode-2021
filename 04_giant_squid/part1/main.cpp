#include "../../common.hpp"

using namespace std;

void parseNumbers(string& s, vector<int>& ioOut, char sep) {
    int cur=0;
    for (char c : s) {
        if (c == sep) {
            ioOut.push_back(cur);
            cur = 0;
        }
        else {
            cur = (cur * 10) + (c - '0');
        }
    }
    ioOut.push_back(cur);
}

struct gridcase {
    bool ischecked;
    int* curlinecount;
    int* curcolcount;
};

int main() {
    // Fast ios
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string aLine;
    cin>>aLine;
    vector<int> aTiredNumbers;
    parseNumbers(aLine, aTiredNumbers, ',');
    dbg(aTiredNumbers);

    const int GRID_SIZE = 5;
    vector<map<int, struct gridcase>> grids;

    bool parse = true;
    while (parse){
        grids.push_back({});
        auto& curgrid = grids.back();
        vector<int*> colscounts;
        for (int i=0;i<GRID_SIZE;++i) {
            int* curline = new int();

            *curline = 0;
            for (int j=0;j<GRID_SIZE;++j) {
                if (!(cin>>aLine)) {
                    parse = false;
                    break;
                }
                int anb = std::stoi(aLine);
                if (i == 0) {
                    int* curcol = new int();
                    *curcol = 0;
                    colscounts.push_back(curcol);
                }
                curgrid[anb] = {
                    false,
                    curline,
                    colscounts[j]
                };
            }
            if (!parse) break;
        }
    }
    grids.pop_back();

    for (int tirednb : aTiredNumbers) {
        for (auto& grid : grids)
        {
            auto foundnb = grid.find(tirednb);
            if (foundnb == grid.end()) continue;
            foundnb->second.ischecked = true;
            if (++(*foundnb->second.curlinecount) == GRID_SIZE || ++(*foundnb->second.curcolcount) == GRID_SIZE)
            {
                // this grid wins
                int unmarkedsum = 0;
                for (auto& gridcase : grid){
                    if (!gridcase.second.ischecked){
                        unmarkedsum += gridcase.first;
                    }
                }
                dbg(unmarkedsum);
                dbg(tirednb);
                int result = unmarkedsum * tirednb;
                dbg(result);
                return 0;
            }
        }
    }
    
    return 0;
}

