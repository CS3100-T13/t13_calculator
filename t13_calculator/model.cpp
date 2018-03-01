#include "model.h"
#include "muParser.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

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
    //funcs.append( f );

    update_equation();

    nc->post( EQUATION_UPDATED );
}

void model::specialKeyEntered( const SpecialKey s ){
    specials.push_back( s );
    //specials.append( s );

    update_equation();

    nc->post( EQUATION_UPDATED );
}


string model::parse_string(const MUP_STRING_TYPE a_str) {
    using namespace mu;
    Parser p;
    p.SetExpr(a_str);
    try {
        double value = p.Eval();
        if (isinf(value)) {
            return "Overflow";
        }
        return to_string(value);
    }
    catch(char const* c)
    {
        string s(c);
        return c;
    }
    catch(Parser::exception_type &e) { //for bad input errors
        return "Invalid input";
    }
}
