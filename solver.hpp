#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <complex>
using namespace std;

namespace solver{

    class RealVariable;

    class ComplexVariable;
    
    double solve(RealVariable);//Function has to clear the variables of the reference
    
    complex<double> solve(ComplexVariable);

class RealVariable {
       
        protected:
        
        double _a;//Coefficient of x^2
        double _b;//Coefficient of x
        double _c;//Free number

        
        public:

        RealVariable() : _a(0.0), _b(1.0), _c(0.0){}//Default C'tor
        
        RealVariable(double a, double b, double c):_a(a),_b(b),_c(c){};

        //void handle_imag(complex<double> &result, double a, double b, double discriminant);
       
        //double solve(RealVariable r);

        double solve_formula();

        double getA(){return _a;}
        double getB(){return _b;}
        double getC(){return _c;}

        //We want make it friend in order to enable something like 7 * RealVariable
        friend RealVariable operator+(const RealVariable &, const RealVariable &);

        friend RealVariable operator+(const RealVariable &, const double);

        friend RealVariable operator+(const double, const RealVariable &);

        friend RealVariable operator-(const RealVariable &, const RealVariable &);

        friend RealVariable operator-(const RealVariable &, const double);

        friend RealVariable operator*(const double, const RealVariable &);

        friend RealVariable operator/(const RealVariable &, const double);

        friend RealVariable operator^(RealVariable const &, const double);

        friend RealVariable operator==(const RealVariable &, const RealVariable &);

        friend RealVariable operator==(const RealVariable &, const double);
    };

    class ComplexVariable  {

    protected:  
        double _a;//Coefficient of x^2
        double _b;//Coefficient of x
        double _c;//Free number
        complex<double> _im;
  
    public:

        ComplexVariable() : _a(0.0), _b(1.0), _c(0.0), _im(0.0){}//Default C'tor
        
        ComplexVariable(double a, double b, double c, complex<double> im):_a(a),_b(b),_c(c),_im(im){};

        //void handle_imag(complex<double> &result, double a, double b, double discriminant) override;
        //complex<double> solve(ComplexVariable);
        
        complex<double> solve_formula();


        friend ComplexVariable operator+(const ComplexVariable &, const ComplexVariable &);

        friend ComplexVariable operator+(const ComplexVariable &, const double);

        friend ComplexVariable operator+(const double, const ComplexVariable &);

        friend ComplexVariable operator+(const ComplexVariable &, complex<double>);

        friend ComplexVariable operator-(const ComplexVariable &, const ComplexVariable &);

        friend ComplexVariable operator-(const ComplexVariable &, const double);

        friend ComplexVariable operator*(const double, ComplexVariable const &);

        friend ComplexVariable operator/(ComplexVariable const &, const double);

        friend ComplexVariable operator^(ComplexVariable const &, const double);

        friend ComplexVariable operator==(const ComplexVariable &, const double);

        friend ComplexVariable operator==(const ComplexVariable &, const ComplexVariable &);
    };

}

#endif