    cout<<ans<<endl;
    
    for(auto x: piles)
        sum+=x;

    int canWin = ans>sum ? true : false;
    cout<<canWin;