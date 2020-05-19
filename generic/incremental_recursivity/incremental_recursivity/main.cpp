#include <iostream>
using std::cout;
using std::endl;

#define DECLARE_PRIORITY(_name_)\
    static const int m ## _name_ = 1 << _name_

class Test
{
    enum priority
    {
        ePriorA = 0,
        ePriorE,
        ePriorB,
        ePriorC,
        ePriorD,
        ePriorF,
        ePriorG
    };

public:
    Test()
    {
    }

    void ShowPriority()
    {
        cout << "mePriorA: " << mePriorA << endl;
        cout << "mePriorB: " << mePriorB << endl;
        cout << "mePriorC: " << mePriorC << endl;
        cout << "mePriorD: " << mePriorD << endl;
        cout << "mePriorE: " << mePriorE << endl;
        cout << "mePriorF: " << mePriorF << endl;
        cout << "mePriorG: " << mePriorG << endl;
    }

private:
    DECLARE_PRIORITY(ePriorA);
    DECLARE_PRIORITY(ePriorB);
    DECLARE_PRIORITY(ePriorC);
    DECLARE_PRIORITY(ePriorD);
    DECLARE_PRIORITY(ePriorE);
    DECLARE_PRIORITY(ePriorF);
    DECLARE_PRIORITY(ePriorG);
};

int main()
{
    Test incPriors;

    incPriors.ShowPriority();
    return 0;
}