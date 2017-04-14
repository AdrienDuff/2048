#ifndef CASE_H
#define CASE_H

#include <iostream>

class Case
{
    public:
        Case(int x);
        virtual ~Case();
        bool estVide() const;
        int get_val();
        void set_val(int y);

    protected:

    private:
        int val;
};

#endif // CASE_H
