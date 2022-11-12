#include <ctime>
#include <gtest/gtest.h>
#include <random>
#include <string>
#include <vector>

#include "test_util.h"
#include "../src/ShoppingCart.h"

TEST(Sample, test_product_contains_name_and_price_should_return_correct_name_and_price){
    Product product("item1", 500);

    ASSERT_EQ(product.getName(), "item1");
    ASSERT_EQ(product.getPrice(), 500);
}

TEST(Sample, test_product_contains_name_length_less_than_4_should_throw_exception){
    ASSERT_THROW(Product("a", 500), std::string);
}

TEST(Sample, test_product_contains_negative_price_should_throw_exception){
    ASSERT_THROW(Product("abcd", -500), std::string);
}

TEST(Sample, test_product_self_point_should_return_correct_name_and_price){
    Product product("abcd", 500);
    product = product;
    
    ASSERT_EQ(product.getName(), "abcd");
    ASSERT_EQ(product.getPrice(), 500);
}

TEST(Sample, test_cart_contains_item_should_return_correct_item_count_and_total_cost){
    Product* products = generate_products_pointer_array({"item1", "item2", "item3"}, {5, 10, 15});
    ShoppingCart shopping_cart = ShoppingCart(3, products);

    ASSERT_EQ(shopping_cart.getItemCount(), 3);
    ASSERT_EQ(shopping_cart.getTotalCost(), 30);

    delete[] products;
}

TEST(Sample, test_cart_contains_item_should_return_correct_name_and_price_on_specific_index){
    Product* products = generate_products_pointer_array({"item1", "item2", "item3"}, {5, 10, 15});
    ShoppingCart shopping_cart = ShoppingCart(3, products);

    ASSERT_EQ(shopping_cart.getItemByIndex(0).getName(), "item1");
    ASSERT_EQ(shopping_cart.getItemByIndex(1).getName(), "item2");
    ASSERT_EQ(shopping_cart.getItemByIndex(2).getName(), "item3");
    ASSERT_EQ(shopping_cart.getItemByIndex(0).getPrice(),  5);
    ASSERT_EQ(shopping_cart.getItemByIndex(1).getPrice(), 10);
    ASSERT_EQ(shopping_cart.getItemByIndex(2).getPrice(), 15);

    delete[] products;
}

TEST(Sample, test_cart_with_some_item_modified_should_return_correct_name_and_price_on_specific_index){
    Product* products = generate_products_pointer_array({"item1", "item2", "item3"}, {5, 10, 15});
    ShoppingCart shopping_cart = ShoppingCart(3, products);

    shopping_cart.setItemByIndex(1, Product("item9", 5));

    ASSERT_EQ(shopping_cart.getItemByIndex(0).getName(), "item1");
    ASSERT_EQ(shopping_cart.getItemByIndex(1).getName(), "item9");
    ASSERT_EQ(shopping_cart.getItemByIndex(2).getName(), "item3");
    ASSERT_EQ(shopping_cart.getItemByIndex(0).getPrice(),  5);
    ASSERT_EQ(shopping_cart.getItemByIndex(1).getPrice(),  5);
    ASSERT_EQ(shopping_cart.getItemByIndex(2).getPrice(), 15);

    delete[] products;
}


TEST(Sample, test_cart_add_some_product_should_return_correct_item_count_and_total_cost){
    ShoppingCart shopping_cart;

    shopping_cart.appendItem(Product("item1", 5));
    shopping_cart.appendItem(Product("item2", 50));
    shopping_cart.appendItem(Product("item3", 500));
    
    ASSERT_EQ(shopping_cart.getItemCount(), 3);
    ASSERT_EQ(shopping_cart.getTotalCost(), 555);
}

TEST(Sample, test_cart_add_some_product_should_throw_exception){
    ShoppingCart shopping_cart;

    shopping_cart.appendItem(Product("item1", 5));
    shopping_cart.appendItem(Product("item2", 50));
    shopping_cart.appendItem(Product("item3", 500));
    
    ASSERT_THROW(shopping_cart.appendItem(Product("item3", 500)), std::string);
}

TEST(Sample, test_cart_get_index_out_of_range_should_throw_exception){
    ShoppingCart shopping_cart;

    shopping_cart.appendItem(Product("item1", 5));
    shopping_cart.appendItem(Product("item2", 50));
    shopping_cart.appendItem(Product("item3", 500));
    
    ASSERT_THROW(shopping_cart.getItemByIndex(4), std::string);
}

TEST(Sample, test_cart_set_index_out_of_range_should_throw_exception){
    ShoppingCart shopping_cart;

    shopping_cart.appendItem(Product("item1", 5));
    shopping_cart.appendItem(Product("item2", 50));
    shopping_cart.appendItem(Product("item3", 500));
    
    ASSERT_THROW(shopping_cart.setItemByIndex(4, Product("item4", 5000)), std::string);
}

TEST(Sample, test_cart_set_index_with_duplicated_stuff_should_throw_exception){
    ShoppingCart shopping_cart;

    shopping_cart.appendItem(Product("item1", 5));
    shopping_cart.appendItem(Product("item2", 50));
    shopping_cart.appendItem(Product("item3", 500));
    
    ASSERT_THROW(shopping_cart.setItemByIndex(1, Product("item3", 500)), std::string);
}

TEST(Sample, test_cart_put_duplicate_item_list_into_copy_constructor_should_throw_exception){
    Product* products = generate_products_pointer_array({"item1", "item1", "item3"}, {5, 5, 15});
    ASSERT_THROW(ShoppingCart(3, products), std::string);

    delete[] products;
}

TEST(Sample, test_two_carts_contains_the_same_products_difference_should_be_empty){
    ShoppingCart shopping_cart;
    ShoppingCart shopping_cart2;
    ShoppingCart difference_cart;

    shopping_cart.appendItem(Product("item1", 5));
    shopping_cart.appendItem(Product("item2", 50));
    shopping_cart.appendItem(Product("item3", 500));
    shopping_cart2.appendItem(Product("item1", 5));
    shopping_cart2.appendItem(Product("item2", 50));
    shopping_cart2.appendItem(Product("item3", 500));
    difference_cart = shopping_cart - shopping_cart2;
    
    ASSERT_EQ(difference_cart.getItemCount(), 0);
    ASSERT_EQ(difference_cart.getTotalCost(), 0);
}

TEST(Sample, test_two_carts_contains_products_difference_should_delete_some_stuff){
    ShoppingCart shopping_cart;
    ShoppingCart shopping_cart2;
    ShoppingCart difference_cart;

    shopping_cart.appendItem(Product("item1", 5));
    shopping_cart.appendItem(Product("item2", 50));
    shopping_cart.appendItem(Product("item3", 500));
    shopping_cart2.appendItem(Product("item3", 500));
    difference_cart = shopping_cart - shopping_cart2;
    
    ASSERT_EQ(difference_cart.getItemCount(), 2);
    ASSERT_EQ(difference_cart.getTotalCost(), 55);
}

TEST(Sample, test_two_carts_contains_the_same_products_union_should_be_the_same){
    ShoppingCart shopping_cart;
    ShoppingCart shopping_cart2;
    ShoppingCart difference_cart;

    shopping_cart.appendItem(Product("item1", 5));
    shopping_cart.appendItem(Product("item2", 50));
    shopping_cart.appendItem(Product("item3", 500));
    shopping_cart2.appendItem(Product("item1", 5));
    shopping_cart2.appendItem(Product("item2", 50));
    shopping_cart2.appendItem(Product("item3", 500));
    difference_cart = shopping_cart + shopping_cart2;
    
    ASSERT_EQ(difference_cart.getItemCount(), 3);
    ASSERT_EQ(difference_cart.getTotalCost(), 555);
}

TEST(Sample, test_two_carts_contains_products_union_should_append_the_missing_stuff_on_first_cart){
    ShoppingCart shopping_cart;
    ShoppingCart shopping_cart2;
    ShoppingCart difference_cart;

    shopping_cart.appendItem(Product("item1", 5));
    shopping_cart.appendItem(Product("item2", 50));
    shopping_cart.appendItem(Product("item3", 500));
    shopping_cart2.appendItem(Product("item1", 5));
    shopping_cart2.appendItem(Product("item3", 500));
    shopping_cart2.appendItem(Product("item5", 5000));
    shopping_cart2.appendItem(Product("item7", 50000));
    difference_cart = shopping_cart + shopping_cart2;
    
    ASSERT_EQ(difference_cart.getItemCount(), 5);
    ASSERT_EQ(difference_cart.getTotalCost(), 55555);
}

TEST(Sample, test_two_carts_the_second_cart_assign_to_first_cart_the_item_should_be_the_same){
    ShoppingCart shopping_cart;
    ShoppingCart shopping_cart2;
    
    shopping_cart.appendItem(Product("item1", 5));
    shopping_cart.appendItem(Product("item2", 50));
    shopping_cart.appendItem(Product("item3", 500));
    shopping_cart2.appendItem(Product("item1", 5));
    shopping_cart2.appendItem(Product("item3", 500));
    shopping_cart2.appendItem(Product("item5", 5000));
    shopping_cart = shopping_cart2;

    ASSERT_EQ(shopping_cart.getItemByIndex(0).getName(), "item1");
    ASSERT_EQ(shopping_cart.getItemByIndex(1).getName(), "item3");
    ASSERT_EQ(shopping_cart.getItemByIndex(2).getName(), "item5");
    ASSERT_EQ(shopping_cart.getItemByIndex(0).getPrice(), 5);
    ASSERT_EQ(shopping_cart.getItemByIndex(1).getPrice(), 500);
    ASSERT_EQ(shopping_cart.getItemByIndex(2).getPrice(), 5000);
    ASSERT_EQ(shopping_cart.getTotalCost(), 5505);
}

TEST(Sample, test_two_the_same_cart_assign_should_be_the_same){
    ShoppingCart shopping_cart;
    ShoppingCart shopping_cart2;

    shopping_cart2 = shopping_cart;
    shopping_cart = shopping_cart2;

    ASSERT_EQ(shopping_cart.getItemCount(), 0);
}

TEST(Sample, test_self_assign_copy_constructor_object_should_be_the_same){
    int size = 5;
    std::vector<std::string> random_name_vector = generate_random_name_array(size);
    std::vector<int> random_price_vector = generate_random_price_array(size);
    Product* products = generate_products_pointer_array(random_name_vector, random_price_vector);
    ShoppingCart shopping_cart(size, products);

    shopping_cart = shopping_cart;

    ASSERT_EQ(shopping_cart.getItemCount(), 5);
    ASSERT_EQ(shopping_cart.getTotalCost(), calculate_total_cost_of_product(random_price_vector));

    delete[] products;
}

TEST(Sample, test_self_assign_default_constructor_object_should_be_the_same){
    ShoppingCart shopping_cart;

    shopping_cart = shopping_cart;

    ASSERT_EQ(shopping_cart.getItemCount(), 0);
    ASSERT_EQ(shopping_cart.getTotalCost(), 0);
}

/* For those brave student use pointer to store the product. */
TEST(Sample, test_huge_item_add_to_shopping_cart_by_copy_constructor){
    int size = 500;
    std::vector<std::string> random_name_vector = generate_random_name_array(size);
    std::vector<int> random_price_vector = generate_random_price_array(size);
    Product* products = generate_products_pointer_array(random_name_vector, random_price_vector);
    ShoppingCart shopping_cart = ShoppingCart(size, products);

    ASSERT_EQ(shopping_cart.getItemCount(), size);
    ASSERT_EQ(shopping_cart.getTotalCost(), calculate_total_cost_of_product(random_price_vector));

    delete[] products;
}

/* For those brave student use pointer to store the product. */
TEST(Sample, test_huge_item_add_to_shopping_cart_by_append_item){
    int size = 500;
    std::vector<std::string> random_name_vector = generate_random_name_array(size);
    std::vector<int> random_price_vector = generate_random_price_array(size);
    Product* products = generate_products_pointer_array(random_name_vector, random_price_vector);
    ShoppingCart shopping_cart;

    for(int i = 0; i < 500; i++){
        shopping_cart.appendItem(products[i]);
    }

    ASSERT_EQ(shopping_cart.getItemCount(), size);
    ASSERT_EQ(shopping_cart.getTotalCost(), calculate_total_cost_of_product(random_price_vector));
    
    delete[] products;
}

