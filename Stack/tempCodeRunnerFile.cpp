
    sort(begin(posSpeed), end(posSpeed), myComp);

    for(auto i : posSpeed) {
        cout << i.first << '\n';
    }
    stack<int> s;