//hex.c
int hex(int N) {
    char N_str[100];
    sprintf(N_str, "%d", N);
    int length = 0;
    while (N_str[length] != '\0') {
        length++;
    }

    int dec_N = 0;
    for (int i = 0; i < length; i++) {
        dec_N = dec_N*16 + (N_str[i]-'0');
    }

    int s = bin(dec_N);
    return s;
}
//hex to dec to bin
//worse solution