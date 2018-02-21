#include "model.h"

model::model()
{
  nc = new NotificationCenter();
}


void model::update_equation() {

}

model::~model()
{
    delete nc;
}

string model::get_equation()
{
    return m_equation;
}

void model::add_digit(const double new_digit)
{
    m_result *= 10;
    m_result += new_digit;

    update_equation();

    nc->post( EQUATION_UPDATED );
}


void model::mathFunctionEntered( const MathFunction f ) {
    funcs.push_back( f );

    update_equation();

    nc->post( EQUATION_UPDATED );
}

void model::specialKeyEntered( const SpecialKey s ){
    specials.push_back( s );

    update_equation();

    nc->post( EQUATION_UPDATED );
}
