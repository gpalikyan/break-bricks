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