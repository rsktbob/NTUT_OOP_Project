#ifndef DRINK
#define DRINK

#include <string>
#include <vector>
#include "topping.h"

class Drink{
public:
	/* The constructor of the Drink. */
	Drink() = default;
	Drink(std::string name, double sweetness_level, int price)
	{
		if (name.size() < 4 || sweetness_level < 0 || sweetness_level > 1 || price < 0)
		{
			throw std::string("Invalid");
		}
		_name = name;
		_sweetness_level = sweetness_level;
		_price = price;
	}
	/* The destructor of the Drink. */
	~Drink() = default;
	/* Return the name of drink. */
	std::string getName() const 
	{
        if (_name == "")
        {
            throw std::string("name error");
        }
		return _name;
	}
	/* Return the level of sweetness. */
	double getSweetnessLevel() const 
	{
        if (_sweetness_level == -1)
        {
            throw std::string("sweetnesslevel error");
        }
		return _sweetness_level;
	}
	/* Return the price of drink. */
	int getPrice() const 
	{
		if (_price == -1)
		{
			throw std::string("invalid price");
		}
		return _price;
	}
	/* Add a topping to the drink. */
	void addTopping(Topping topping)
	{
        if (_name == "" || _sweetness_level == -1 || _price == -1)
        {
            throw std::string("define drink error");
        }
		_sweetness_level += topping.getSweetnessLevel();
		_price += topping.getPrice();
		_topping.push_back(topping);
	}
	/* Get the topping of drink by index, the index is determine by the order of topping added and start from 0. */
	Topping getToppingByIndex(int index) const 
	{
        if (index >= _topping.size())
        {
            throw std::string("out of range");
        }
		return _topping[index];
	}
	/* Get the count of topping in drink. */
	int getToppingCount() const
	{
		return _topping.size();
	}
	/* Operator overloading */
	Drink &operator=(const Drink& other) = default;
private:
	/* Put some attribute on here if necessary. */
	std::string _name = "";
	double _sweetness_level = -1;
	int _price = -1;
	std::vector<Topping> _topping;
};

#endif
