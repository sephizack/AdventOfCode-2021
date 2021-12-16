#include "../../common.hpp"

using namespace std;

int main() {
    // Fast ios
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int aHori=0;
    int aDepth=0;
    string action;
    int n;
    while (true)
    {
        if (!(cin>>action)) break;
        if (!(cin>>n)) break;
        if (action == "forward")
        {
            aHori+=n;
        }
        if (action == "down")
        {
            aDepth+=n;
        }
        if (action == "up")
        {
            aDepth-=n;
        }
    }

    dbg(aDepth*aHori);
    return 0;
}

