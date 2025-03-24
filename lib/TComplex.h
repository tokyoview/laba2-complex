#pragma once
#include <iostream>

template<class T>
class TComplex
{
protected:
	double re;
	double im;
public:
	TComplex(T re_ = 0, T im_ = 0);
	TComplex(const TComplex& p);
	~TComplex();

	T GetRe();
	T GetIm();
	void SetRe(T re_);
	void SetIm(T im_);

	TComplex operator+ (const TComplex <T>& p);
	TComplex operator- (const TComplex <T>& p);
	TComplex operator* (const TComplex <T>& p);
	TComplex operator/ (const TComplex <T>& p);

	TComplex& operator+= (const TComplex <T>& p);
	TComplex& operator-= (const TComplex <T>& p);
	TComplex& operator*= (const TComplex <T>& p);
	TComplex& operator/= (const TComplex <T>& p);

	TComplex& operator= (const TComplex <T>& p);

	bool operator== (const TComplex <T>& p);
	bool operator!= (const TComplex <T>& p);

	template<class Osel>
	friend std::ostream& operator <<(std::ostream& o, TComplex<Osel>& p);

	template<class Osel>
	friend std::istream& operator >>(std::istream& i, TComplex<Osel>& p);
};

template<class T>
inline TComplex<T>::TComplex(T re_, T im_)
{
	this->re = re_;
	this->im = im_;
}

template<class T>
inline TComplex<T>::TComplex(const TComplex& p)
{
	this->re = p.re;
	this->im = p.im;
}

template<class T>
inline TComplex<T>::~TComplex()
{}

template<class T>
inline T TComplex<T>::GetRe()
{
	return re;
}

template<class T>
inline T TComplex<T>::GetIm()
{
	return im;
}

template<class T>
inline void TComplex<T>::SetRe(T re_)
{
	this->re = re_;
}

template<class T>
inline void TComplex<T>::SetIm(T im_)
{
	this->im = im_;
}

template<class T>
inline TComplex<T> TComplex<T>::operator+(const TComplex <T>& p)
{
	return TComplex(re + p.re, im + p.im);
}

template<class T>
inline TComplex<T> TComplex<T>::operator-(const TComplex <T>& p)
{
	return TComplex(re - p.re, im - p.im);
}

template<class T>
inline TComplex<T> TComplex<T>::operator*(const TComplex <T>& p)
{
	return TComplex((re * p.re) - (im * p.im), (re * p.im) + (im * p.re));
}

template<class T>
inline TComplex<T> TComplex<T>::operator/(const TComplex <T>& p)
{
	return TComplex(((re * p.re) + (im * p.im)) / ((p.re * p.re) + (p.im * p.im)),
	((im * p.re) - (re * p.im)) / ((p.re * p.re) + (p.im * p.im)));
}

template<class T>
inline TComplex<T>& TComplex<T>::operator+=(const TComplex <T>& p)
{
	this->re += p.re;
	this->im += p.im;
	return *this;
}

template<class T>
inline TComplex<T>& TComplex<T>::operator-=(const TComplex <T>& p)
{
	this->re -= p.re;
	this->im -= p.im;
	return *this;
}

template<class T>
inline TComplex<T>& TComplex<T>::operator*=(const TComplex <T>& p)
{
	this->re = (re * p.re) - (im * p.im); 
	this->im = (re * p.im) + (im * p.re);
	return *this;
}

template<class T>
inline TComplex<T>& TComplex<T>::operator/=(const TComplex <T>& p)
{
	this->re = ((re * p.re) + (im * p.im)) / ((p.re * p.re) + (p.im * p.im)); 
	this->im = ((im * p.re) - (re * p.im)) / ((p.re * p.re) + (p.im * p.im));
	return *this;
}

template<class T>
inline TComplex<T>& TComplex<T>::operator=(const TComplex <T>& p)
{
	this->re = p.re; 
	this->im = p.im;
	return *this;
}

template<class T>
inline bool TComplex<T>::operator==(const TComplex <T>& p)
{
	return (re == p.re) && (im == p.im);
}

template<class T>
inline bool TComplex<T>::operator!=(const TComplex <T>& p)
{
	return (re != p.re) && (im != p.im);
}

template<class T>
inline std::ostream& operator<<(std::ostream& o, TComplex<T>& p)
{
	o << "Here is your complex number:\n";
	if (p.im > 0)
		o << p.re << " + " << p.im << "i";
	else
	o << p.re << " - " << p.im << "i";
	return o;
}

template<class T>
inline std::istream& operator>>(std::istream& i, TComplex<T>& p)
{
	std::cout << "Enter complex number:\nRe: ";
	i >> p.re;
	std::cout << "Im: ";
	i >> p.im;
	std::cout << "Success!\n";
	return i;
}