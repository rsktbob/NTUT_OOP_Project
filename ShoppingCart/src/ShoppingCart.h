#ifndef SHOPPINGCART
#define SHOPPINGCART

#include "Product.h"

class ShoppingCart
{
private:
    int _item_list_size;
    Product *_item_list;

public:
    ShoppingCart()
    {
        _item_list_size = 0;
        _item_list = NULL;
    }
    ShoppingCart(int item_list_size, Product *item_list)
    {
        for (int i = 0; i < item_list_size - 1; i++)
        {
            for (int j = i + 1; j < item_list_size; j++)
            {
                if (item_list[i] == item_list[j])
                {
                    throw string("error name");
                }
            }
        }
        _item_list_size = item_list_size;
        _item_list = new Product[_item_list_size];
        for (int i = 0; i < _item_list_size; i++)
        {
            _item_list[i] = item_list[i];
        }
    }
    ShoppingCart &operator=(const ShoppingCart &other)
    {
        if (this != &other)
        {
            _item_list_size = other._item_list_size;
            delete[] _item_list;
            _item_list = new Product[_item_list_size];
            for (int i = 0; i < _item_list_size; i++)
            {
                _item_list[i] = other._item_list[i];
            }
        }
        return *this;
    }
    ShoppingCart operator+(const ShoppingCart &other)
    {
        int check = 0;
        ShoppingCart newcart;
        for (int i = 0; i < _item_list_size; i++)
        {
            newcart.appendItem(_item_list[i]);
        }
        for (int i = 0; i < other._item_list_size; i++)
        {
            for (int j = 0; j < _item_list_size; j++)
            {
                if (newcart._item_list[j] == other._item_list[i])
                {
                    check = 1;
                    break;
                }
            }
            if (check == 0)
            {
                newcart.appendItem(other._item_list[i]);
            }
            check = 0;
        }
        return newcart;
    }
    ShoppingCart operator-(const ShoppingCart &other)
    {
        int check = 0;
        ShoppingCart newcart;
        for (int i = 0; i < _item_list_size; i++)
        {
            for (int j = 0; j < other._item_list_size; j++)
            {
                if (_item_list[i] == other._item_list[j])
                {
                    check = 1;
                    break;
                }
            }
            if (check == 0)
            {
                newcart.appendItem(_item_list[i]);
            }
            check = 0;
        }
        return newcart;
    }
    ~ShoppingCart()
    {
        delete[] _item_list;
    }
    int getItemCount() const
    {
        return _item_list_size;
    }
    Product getItemByIndex(int index)
    {
        if (index >= _item_list_size)
        {
            throw string("out of range");
        }
        return _item_list[index];
    }
    void setItemByIndex(int index, Product product)
    {
        if (index >= _item_list_size)
        {
            throw string("out of range");
        }
        for (int i = 0; i < _item_list_size; i++)
        {
            if (_item_list[i] == product && i != index)
            {
                throw string("error product");
            }
        }`
        _item_list[index] = product;
    }
    void appendItem(Product product)
    {
        for (int i = 0; i < _item_list_size; i++)
        {
            if (_item_list[i] == product)
            {
                throw string("error product");
            }
        }
        _item_list_size++;
        Product *new_item_list = new Product[_item_list_size];
        for (int i = 0; i < _item_list_size - 1; i++)
        {
            new_item_list[i] = _item_list[i];
        }
        delete[] _item_list;
        _item_list = new_item_list;
        _item_list[_item_list_size - 1] = product;
    }
    int getTotalCost() const
    {
        int sum = 0;
        for (int i = 0; i < _item_list_size; i++)
        {
            sum += _item_list[i].getPrice();
        }
        return sum;
    }
};

#endif