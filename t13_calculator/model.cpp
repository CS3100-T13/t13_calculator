#include "model.h"
#include "muParser.h"
#include <iostream>
#include <string>
#include <cstdio>


model::model()
{

}

string model::get_equation()
{
    return m_equation;
}

void model::add_digit(const double new_digit)
{
    m_result *= 10;
    m_result += new_digit;
}


void model::parse_string(const MUP_STRING_TYPE a_str)
{
    mu::Parser p;
    p.SetExpr(a_str);
    cout << p.Eval() << endl;
}
