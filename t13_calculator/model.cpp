#include "model.h"

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
