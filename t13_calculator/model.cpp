#include "model.h"
#include "muParser.h"
#include "muParserError.h"
#include <iostream>
#include <string>
#include <cstdio>

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


void model::parse_string(const MUP_STRING_TYPE a_str)
{

    using namespace mu;
    Parser p;
    p.SetExpr(a_str);
    try{
    cout << p.Eval() << endl;
    }

    catch(Parser::exception_type &e)
    {
        std::cout << (e.GetToken()).c_str() << std::endl;
        std::cout << (e.GetMsg()).c_str() << std::endl;


    }

}
