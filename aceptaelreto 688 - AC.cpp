#include <iostream>
using namespace std;

int main()
{
    int max_dif_consecutive, max_dif_total, n;
    while (cin >> max_dif_consecutive) {
        cin >> max_dif_total >> n;
        bool is_ok = true;
        int current_heigh, previous_heigh, min_dif = 0, max_dif = 0, last_dif = 0, current_dif;
        cin >> previous_heigh;
        while (n--) {
            cin >> current_heigh;
            if (!is_ok) continue;

            current_dif = current_heigh - previous_heigh;
            if (!last_dif) { last_dif = min_dif = max_dif = current_dif; }
            //Check consecutive difference
            if (last_dif - current_dif > max_dif_consecutive || 
                current_dif - last_dif > max_dif_consecutive) is_ok = false;
            //Store total difference
            if (current_dif < min_dif) min_dif = current_dif;
            if (current_dif > max_dif) max_dif = current_dif;
            
            previous_heigh = current_heigh;
            last_dif = current_dif;
        }

        if (max_dif > min_dif + max_dif_total) is_ok = false;

        if (is_ok) cout << "Ok" << endl;
        else cout << "Tropiezo" << endl;
    }

    return 0;
}
