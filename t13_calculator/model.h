#ifndef MODEL_H
#define MODEL_H
#include <string>
#include "muParser.h"

using namespace std;

class model
{
public:
    model();
    string get_equation();
    void add_digit(const double new_digit);
    void parse_string(const MUP_STRING_TYPE a_str);

private:
    string m_equation;
    void update_equation();
    double m_result;

};

#endif // MODEL_H
