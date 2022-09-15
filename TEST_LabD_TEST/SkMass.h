#ifndef SKMASS_H
#define SKMASS_H
class SkMass{
private:
    double m[5];
public:
    double* GetM(){return m;}
    void Change(int n, double sk);
    double Sum(int sk1, int sk2);
    double Avg();
    void Print();
    void Ini();
    SkMass();
    ~SkMass();
};
#endif
