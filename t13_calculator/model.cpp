#include "model.h"
#include "muParser.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <QDebug>

model::model()
{
  nc = new NotificationCenter();
}


void model::update_equation()
{
  parse_string(equation);
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
    m_result.append(str(new_digit));
    if(SIGN_SWITCH)
    {
      if(m_result[1] == '+')
      {
        m_result[1] = '-';
      }
      else
      {
        m_result[1] = '+';
      }
    }


    update_equation();

    nc->post( EQUATION_UPDATED );
}


void model::mathFunctionEntered( const MathFunction f ) {
    //funcs.push_back( f );
    //equation.append( f );
    switch(f)
    {
      case PLUS:
        equation.append ('+');
        QDebug("Plus added to equation.");
        break;
      case MINUS:
        equation.append ('-');
        QDebug("Minus added to equation.");
        break;
      case MULTIPLY:
        equation.append ('*');
        QDebug("Multiply added to equation.");
        break;
      case DIVIDE:
        equation.append ('/');
        QDebug("Divide added to equation.");
        break;
    }
    update_equation();

    nc->post( EQUATION_UPDATED );
}

void model::specialKeyEntered( const SpecialKey s ){
    //specials.push_back( s );
    //equation.append( s );
    switch(s)
    {
      case EQUALS:
        equation.append('=');
        QDebug("Equals added to equation.");
        break;
      case OPEN_PAREN:
        equation.append('(');
        QDebug("Open Parentheses added to equation.");
        break;
      case CLOSE_PAREN:
        equation.append(')');
        QDebug("Close Parantheses added to equation.");
        break;
      case DECIMAL:
        equation.append('.');
        QDebug("Decimal point added to equation.");
        break;
    }

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
