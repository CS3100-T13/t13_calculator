#ifndef MODEL_H
#define MODEL_H
#include <string>
using namespace std;

class model
{
public:
    model();
    string get_equation();
    void add_digit(const double new_digit);

private:
    string m_equation;
    update_equation();
    double m_result;

};

#endif // MODEL_H
