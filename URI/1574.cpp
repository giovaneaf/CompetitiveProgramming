#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int t, n, i, p, same, act[101] = {0};
    string line;

    getline(cin, line);
    t = stoi(line);

    for(; t > 0; t--){
        getline(cin, line);
        n = stoi(line);
        p = 0;
        for(i = 1; i <= n; i++) {
            getline(cin, line);
            if(line == "LEFT")
                act[i] = -1;
            else if(line == "RIGHT")
                act[i] = 1;
            else {
                same = stoi(line.substr(8));
                act[i] = act[same];
            }

            p += act[i];
        }

        cout << p << endl;
    }

        
    return 0;
    
}