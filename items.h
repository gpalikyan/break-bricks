#ifndef ITEMS_H
#define ITEMS_H

typedef struct motion_vector_t
{
	double p, v, a, t0;
} motion_vector_t;

typedef enum item_type_t
{
	PLATFORM, 
	BRICK,
	CANNONBALL
} item_type_t;

class Item
{
	protected:
		motion_vector_t motion_vector_x, motion_vector_y;
		item_type_t item_type;
	public:
		Item(motion_vector_t motion_vector_x, motion_vector_t motion_vector_y, item_type_t item_type);
		item_type_t get_item_type();
		
		double get_x(long int t);
		void set_motion_vector_x(motion_vector_t motion_vector_x);
		motion_vector_t get_motion_vector_x();
		
		double get_y(long int t);
		void set_motion_vector_y(motion_vector_t motion_vector_y);
		motion_vector_t get_motion_vector_y();		
		
};

#endif // ITEMS_H	