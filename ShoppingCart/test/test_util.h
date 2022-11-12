#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "../src/Product.h"

std::string generate_random_name(){
    std::string name = "";
    for(int i = 0; i < 10; i++){
        name += rand() % 2 == 0 ? 'A' + (rand() % 26) : 'a' + (rand() % 26);
    }
    return name;
}

std::vector<std::string> generate_random_name_array(const int size){
    std::vector<std::string> vec;
    for(int i = 0; i < size; i++){
        vec.push_back(generate_random_name());
    }
    return vec;
}

std::vector<int> generate_random_price_array(const int size){
    std::vector<int> vec;
    for(int i = 0; i < size; i++){
        vec.push_back((rand() % 99 + 1) * 5);
    }
    return vec;
}

Product* generate_products_pointer_array(std::vector<std::string> name, std::vector<int> price){
    Product* products = new Product[name.size()];
    for(int i = 0; i < name.size(); i++){
        products[i] = Product(name[i], price[i]);
    }
    return products;
}

Product* mix_product_pointer_array(Product* product1, Product* product2, int product_size){
    Product* result = new Product[product_size];
    for(int i = 0; i < product_size; i++){
        i % 2 == 0 ? result[i] = product1[i] : result[i] = product2[i];
    }
    return result;
}

Product* fetch_specific_indexes_of_product_pointer_array(Product* product, std::vector<int> position){
    Product* result = new Product[position.size()];
    for(int i = 0; i < position.size(); i++){
        result[i] = product[position[i]];
    }
    return result;
}

int calculate_total_cost_of_product(std::vector<int> vec){
    int total = 0;
    for(int i = 0; i < vec.size(); i++){
        total += vec[i];
    }
    return total;
}

int calculate_total_cost_of_odd_index_product(std::vector<int> vec){
    int total = 0;
    for(int i = 1; i < vec.size(); i+=2){
        total += vec[i];
    }
    return total;
}

int calculate_total_cost_of_even_index_product(std::vector<int> vec){
    int total = 0;
    for(int i = 0; i < vec.size(); i+=2){
        total += vec[i];
    }
    return total;
}
