#include "PlaylistView.h"
#include <iostream>

void PlaylistView::display(vector<string> plists) {
    system("clear");
    cout << View::alignMiddle(" SELECT PLAYLIST ", '=', WIDTH) << endl;
    cout << endl;
    int num = plists.size();
    cout << "You have " << num << " playlists. Please select one:" << endl << endl;
    for(int i = 0; i < num; i++) {
        if((line % num) == i) {
            View::highlightLine(to_string(i+1)+ ". " + plists[i]);
        } else cout << i + 1 << ". " << plists[i] << endl;
    }
    View::alignLength();
    View::displayBottom();
}