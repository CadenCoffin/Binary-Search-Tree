/***************************************************************
Author:         Dr. Spiegel - Modified by Patrick Stelmach and Caden Coffin
Filename:       Term.h   
Purpose:        A Term holds one term of a polynomial. A term 
		can be created, evaluated, compared, and printed
***************************************************************/
#ifndef TERM_H
#define TERM_H

#include <iostream>

using namespace std;

/*! 
    \class Term
    \brief A Term holds one term of a polynomial.
   
    The term can be created, evaluated, compared, and printed. Created by Dr. Spiegel.
*/
class Term
{
public:
	///Constructor
	Term(double=0, int=0); 	//default value of 0x^0

	///Gets - returns the coefficient
	/*!
	*   \fn  getCoefficient
	*   \brief   retrieves the coefficient
	*   \param n/a
	*                                                                   
	*   \return double- the coefficient at the index
	*********************************************************************/
	double getCoefficient() const;
	///Gets - returns the exponent
	/*!
	*   \fn  getExponent
	*   \brief   retrieves the exponent
	*   \param n/a
	*                                                                   
	*   \return int- the exponent at the index
	*********************************************************************/
	int getExponent() const;

	///Sets the coefficient
	/*!
	*   \fn  setCoefficient
	*   \brief   sets the coefficient
	*   \param n/a
	*                                                                   
	*   \return double- the coefficient at the index
	*********************************************************************/
	double setCoefficient(double coeff) ;
	
	///Sets the exponent
	/*!
	*   \fn  setExponent
	*   \brief   sets the exponent
	*   \param n/a
	*                                                                   
	*   \return int- the exponent at the index
	*********************************************************************/
	int setExponent(int expn);

	///evaluation of term
	/*!
	*   \fn  operator()
	*   \brief   Evaluates the term by the input number 
	*   \param double x- the number to evaluate to 
	*                                                                   
	*   \return the sum of the evaluated term
	*********************************************************************/
	double operator()(double x) const; 	
	
	//other
	/// updates the exponent 
	/*!
	*   \fn  operator!=
	*   \brief  Compares an int against the exponent
	*   \param int value- the number to compare the exponent by
	*                                                                   
	*   \return true- if doesn't match // false- if match
	*********************************************************************/
	bool operator=(int value); //Note signature ==(Term&,int)
	/// does exponent match the parameter? 
	/*!
	*   \fn  operator==
	*   \brief  Compares an int against the exponent
	*   \param int value- the number to compare the exponent by
	*                                                                   
	*   \return true- if match // false- if doesn't match
	*********************************************************************/
	bool operator==(int value); //Note signature ==(Term&,int)
	/// does exponent match that of the param?  
	/*!
	*   \fn  operator==
	*   \brief  Compares a Term against the exponent
	*   \param int value- the number to compare the exponent by
	*                                                                   
	*   \return true- if match // false- if doesn't match
	*********************************************************************/
	bool operator==(const Term &right); //Signature: ==(Term,Term)
	/// adds the term coefficents and updates this coefficient
	/*!
	*   \fn  operator+=
	*   \brief  adds input term coefficient to coefficient
	*   \param int value- the number to compare the exponent by
	*                                                                   
	*   \return true- if match // false- if doesn't match
	*********************************************************************/
	bool operator+=(const Term &right); //Signature: +=(Term,Term)
	/// does exponent match that of the param?  
	/*!
	*   \fn  operator!=
	*   \brief  Compares an int against the exponent
	*   \param int value- the number to compare the exponent by
	*                                                                   
	*   \return true- if doesn't match // false- if match
	*********************************************************************/
	bool operator!=(int value); //Note signature !=(Term&,int)
	/// does exponent match that of the param?  
	/*!
	*   \fn  operator!=
	*   \brief  Compares a Term against the exponent
	*   \param int value- the number to compare the exponent by
	*                                                                   
	*   \return true- if doesn't match // false- if match
	*********************************************************************/
	bool operator!=(const Term &right); //Signature: !=(Term,Term)
	/// is this term's exponent less than right? 
	/*!
	*   \fn  operator<
	*   \brief  Compares two Terms based on exponent
	*   \param int value- the value to make the comparision to
	*                                                                   
	*   \return according to the comparison
	*********************************************************************/
	bool operator<(const Term &right) const;//Signature <(Term&,Term&)
	/// is this term's exponent less than right? 
	/*!
	*   \fn  operator<
	*   \brief  Compares Term's exponent to an int
	*   \param int value- the value to make the comparision to
	*                                                                   
	*   \return according to the comparison
	*********************************************************************/
	bool operator<(int right);//Signature: <(Term&,int)

private:
	double coefficient; //holds the coefficient value
	int exponent; //holds the exponent value

};
	/// Stream insert a term
	/*!
	*   \fn  operator<<
	*   \brief  For output
	*   \param ofstream &ouput- 
	*	\param const Term &t- the term object to be outputted
	*                                                                   
	*   \return output
	*********************************************************************/
	ostream &operator<<(ostream &output,const Term &term); 
#endif
