#include "items.h"

Item::Item(motion_vector_t motion_vector_x, motion_vector_t motion_vector_y, item_type_t item_type)
{
	this->motion_vector_x = motion_vector_x;
	this->motion_vector_y = motion_vector_y;
	this->item_type       = item_type;
}

item_type_t Item::get_item_type()
{
	return this->item_type;
}

double Item::get_x(long int t)
{
	double p = this->motion_vector_x.p;
	double v = this->motion_vector_x.v;
	double a = this->motion_vector_x.a;
	double t0 = this->motion_vector_x.t0;	
	
	return p + v * (t - t0) + (a*(t-t0)*(t-t0))/2;
}

void Item::set_motion_vector_x(motion_vector_t motion_vector_x)
{
	this->motion_vector_x = motion_vector_x;
}
motion_vector_t Item::get_motion_vector_x()
{
	return this->motion_vector_x;
}	

double Item::get_y(long int t)
{
	double p = this->motion_vector_y.p;
	double v = this->motion_vector_y.v;
	double a = this->motion_vector_y.a;
	double t0 = this->motion_vector_y.t0;	
	
	return p + v * (t - t0) + a*(t-t0)*(t-t0)/2;
}

void Item::set_motion_vector_y(motion_vector_t motion_vector_y)
{
	this->motion_vector_y = motion_vector_y;
}
motion_vector_t Item::get_motion_vector_y()
{
	return this->motion_vector_y;
}	