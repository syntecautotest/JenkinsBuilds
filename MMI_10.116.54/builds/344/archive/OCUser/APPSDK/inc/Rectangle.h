// Rectangle.h: interface for the CRectangle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RECTANGLE_H__5F7616B1_2589_404F_B719_AE2CE2F41E44__INCLUDED_)
#define AFX_RECTANGLE_H__5F7616B1_2589_404F_B719_AE2CE2F41E44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRectangle  
{
public:
	class CDouble
	{
	public:
		CDouble();
		// constructs and initializes it to empty rectangle at
		// (0.0,0.0)

		virtual ~CDouble();
		// destructor

		void add( double x, double y );
		// adjust rectange to contains the added point

		void set( CDouble &r );
		// initialize this object by specified object

		double getCenterX( void );
		// get rectangle center x coordinate

		double getCenterY( void );
		// get rectangle center y coordinate

		void setBounds( double x, double y, double width, double height );
		// Sets the bounding rectangle of this rectangle to the specified
		// values for x, y, width, and height.

		void setLocation( double x, double y );
		// Moves the rectangle to the specified location.

		void setSize( double width, double height );
		// Sets the size of this rectangle to the specified width and height.

		// public data member
		double		m_x;
		double		m_y;
		double		m_width;
		double		m_height;
	};

public:
	CRectangle();
	// constructs and initializes it to empty rectangle at (0,0)

	CRectangle( CRectangle &r );
	// constructs and initializes it from the specified rectangle

	virtual ~CRectangle();
	// destructor

	void setBounds( CRectangle &r );
	// Sets the bounding rectangle of this rectangle to match the
	// specified rectangle.

	void setBounds( LONG x, LONG y, LONG width, LONG height );
	// Sets the bounding rectangle of this rectangle to the specified
	// values for x, y, width, and height.

	void setLocation( LONG x, LONG y );
	// Moves the rectangle to the specified location.

	void setSize( LONG width, LONG height );
	// Sets the size of this rectangle to the specified width and height.

	BOOL isEmpty( void );
	// Determines whether this rectangle is empty. A rectangle is empty
	// if its width or its height is less than or equal to zero.
	// true if this rectangle is empty; false otherwise.

	void translate( LONG dx, LONG dy );
	// Translates the rectangle the indicated distance, to the right
	// along the x coordinate axis, and downward along the y
	// coordinate axis.

	BOOL contains( LONG x, LONG y );
	// Checks whether this rectangle contains the point at the specified
	// location (x, y).
	// true if the point (x, y) is inside this rectangle; false otherwise.

	BOOL contains( CRectangle &r );
	// Checks whether this rectangle contains the other rectangle.
	// true if the another rectangle, r is inside this rectangle;
	// false otherwise.

	void grow( LONG h, LONG v );
	// Grows the rectangle both horizontally and vertically. 
	//
	// This method modifies the rectangle so that it is h units
	// larger on both the left and right side, and v units larger
	// at both the top and bottom. 
	//
	// The new rectangle has (x - h, y - v) as its top-left corner,
	// a width of width + 2h, and a height of height + 2v. 
	//
	// If negative values are supplied for h and v, the size of the
	// rectangle decreases accordingly. The grow method does not
	// check whether the resulting values of width and height
	// are non-negative.

	// public data member
	LONG		m_x;
	LONG		m_y;
	LONG		m_width;
	LONG		m_height;
};

#endif // !defined(AFX_RECTANGLE_H__5F7616B1_2589_404F_B719_AE2CE2F41E44__INCLUDED_)
