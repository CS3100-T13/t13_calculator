#ifndef MODEL_H
#define MODEL_H
#include <string>
#include <vector>
#include "notificationcenter.h"
#include "muParser.h"

using namespace std;

const NotificationID EQUATION_UPDATED = "NOTIFICATION_UPDATED";

enum MathFunction {
    UNDEFINED = 0,
    PLUS = 1,
    MINUS = 2,
    MULTIPLY = 3,
    DIVIDE = 4
};

enum SpecialKey {
    //use isdigit(int c), built in function for c++ somehow//
    EQUALS = 0,
    ALL_CLEAR = 1,
    OPEN_PAREN = 2,
    CLOSE_PAREN = 3,
    DECIMAL = 4,
    SIGN_SWITCH = 5
};

class model
{
public:
    model();
    ~model();
    string get_equation();
    void add_digit(const double new_digit);
    void mathFunctionEntered( const MathFunction f );
    void specialKeyEntered( const SpecialKey s );
    static string parse_string(const MUP_STRING_TYPE a_str);

private:
    string m_equation;
    void update_equation();
    double m_result;
    NotificationCenter *nc;
    vector<MathFunction> funcs;
    //string funcs;
    vector<SpecialKey> specials;
    //string specials;

};

#endif // MODEL_H
