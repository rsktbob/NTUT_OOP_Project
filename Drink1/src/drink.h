#include <string>

class Drink{
public:
    /* The constructor of the Drink. */
    Drink(std::string name = "", double sweetness_level = -1){
        if (name.length() < 4 && name != ""){
            throw std::string("length not enough");
        }
        if((sweetness_level < 0 || sweetness_level > 1) && sweetness_level != -1){
            throw std::string("over range");
        }
        _name = name;
        _sweetness_level = sweetness_level;
        _dim = 0;
        _arr_dim = 1;
        _topping = new std::string[1];
    }
    /* The destructor of the Drink. */
    ~Drink(){
        delete[] _topping;
    }
    /* Return the name of drink. */
    std::string getName(){
        if (_name == ""){
            throw std::string("no name");
        }
        return _name;
    }
    /* Return the level of sweetness. */
    double getSweetnessLevel(){
        if (_sweetness_level == -1){
            throw std::string("no sweetness level");
        }
        return _sweetness_level;
    }
    /* Add a topping to the drink. */
    void addTopping(std::string topping){
        if (_arr_dim  <= _dim){
            if (_arr_dim == 0) {
                _arr_dim += 1;
            }
            else {
                _arr_dim *= 2;
            }
            std::string *_newTopping = new std::string[_arr_dim];
            for (int i = 0; i < _dim; i++){
                _newTopping[i] = _topping[i];
            }
            if (_topping != NULL) {
                delete[] _topping;
            }
            _topping = _newTopping;
        }
        _topping[_dim] = topping;
        _dim += 1;
    }
    /* Get the topping of drink by index, the index is determine by the order of topping added and start from 0. */
    std::string getToppingByIndex(int index){
        if (index >= _dim){
            throw std::string("out of range");
        }
        return _topping[index];
    }
    /* Get the count of topping in drink. */
    int getToppingCount(){
        return _dim;
    }
private:
    std::string _name;
    double _sweetness_level;
    int _dim;
    int _arr_dim;
    std::string *_topping;
    /* Put some attribute on here if necessary. */
};

