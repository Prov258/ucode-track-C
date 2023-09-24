int mx_sqrt(int x) {
    if(x < 0) {
        return 0;
    }

    int sqrt = 0;

    for(int i = 1; i <= (x / 2); i++) {
        if(i * i == x) {
            sqrt = i;
            break;
        }
    }

    return sqrt;
}


