#include <stdio.h>

int main() {
    double a, b, c, d, e, f, g, h;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f, &g, &h);

    int opt = 0;

    //A(a,b)B(c,d)C(e,f)D(g,h)
    
    //ABD
    
    double ABx, ABy, ADx, ADy;
    ABx = c - a;
    ABy = d - b;
    ADx = g - a;
    ADy = h - b;
    
    double AOx, AOy;
    AOx = 0 - a;
    AOy = 0 - b;
    
    //O in ABD
    
    //n(ABx,ABy)+m(ADx,ADy)=(AOx,AOy)
    //n*ABx + m*ADx = AOx...1
    //n*ABy + m*ADy = AOy...2
    
    double ABDdel, ABDdelx, ABDdely;
    
    ABDdel  = ABx*ADy - ADx*ABy;//delta   = ABx*ADy - ADx*ABy
    ABDdelx = AOx*ADy - ADx*AOy;//delta x = AOx*ADy - ADx*AOy
    ABDdely = ABx*AOy - AOx*ABy;//delta y = ABx*AOy - AOx*ABy
    
    double ABDn, ABDm;
    if (ABDdel != 0) {
        ABDn = ABDdelx / ABDdel;
        ABDm = ABDdely / ABDdel;
    
        if (ABDn >= 0 && ABDm >= 0 && ABDn + ABDm <= 1) {
            opt = 1;
        }
    }
    
    
    
    //DBC
    
    double DBx, DBy, DCx, DCy;
    DBx = c - g;
    DBy = d - h;
    DCx = e - g;
    DCy = f - h;
    
    double DOx, DOy;
    DOx = 0 - g;
    DOy = 0 - h;
    
    //O in DBC
    
    //n(DBx,DBy)+m(DCx,DCy)=(DOx,DOy)
    //n*DBx + m*DCx = DOx...1
    //n*DBy + m*DCy = DOy...2
    
    double DBCdel, DBCdelx, DBCdely;
    
    DBCdel  = DBx*DCy - DCx*DBy;//delta   = DBx*DCy - DCx*DBy
    DBCdelx = DOx*DCy - DCx*DOy;//delta x = DOx*DCy - DCx*DOy
    DBCdely = DBx*DOy - DOx*DBy;//delta y = DBx*DOy - DOx*DBy
    
    double DBCn, DBCm;
    if (DBCdel != 0) {
        DBCn = DBCdelx / DBCdel;
        DBCm = DBCdely / DBCdel;
    
        if (DBCn >= 0 && DBCm >= 0 && DBCn + DBCm <= 1) {
            opt = 1;
        }
    }
    
    
    printf("%d\n", opt);
    
    return 0;
}