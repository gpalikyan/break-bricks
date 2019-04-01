#ifndef ITEMS_H
#define ITEMS_H

typedef struct motion_vector_t
{
	unsigned short p, v, a;
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
};

#endif // ITEMS_H	