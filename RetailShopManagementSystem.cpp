//
// Created by priver on 12/2/24.
//
#include <iostream>
#include <vector>
#include <string>
#include <limits>

// Class representing a Product
class Product {
private:
    std::string name;
    float price;
    int quantity;

public:
    Product(const std::string& prodName, float prodPrice, int prodQuantity)
            : name(prodName), price(prodPrice), quantity(prodQuantity) {}

    void display() const {
        std::cout << "Product Name: " << name << ", Price: $" << price << ", Quantity: " << quantity << std::endl;
    }

    void updatePrice(float newPrice) {
        price = newPrice;
    }

    void updateQuantity(int newQuantity) {
        quantity = newQuantity;
    }

    float getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }

    std::string getName() const {
        return name;
    }
};

// Function to add a product
void addProduct(std::vector<Product>& products) {
    std::string name;
    float price;
    int quantity;

    std::cout << "Enter product name: ";
    std::cin >> name;

    std::cout << "Enter product price: ";
    while (!(std::cin >> price)) {
        std::cout << "Invalid price. Please enter a numeric value: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter product quantity: ";
    while (!(std::cin >> quantity)) {
        std::cout << "Invalid quantity. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    products.push_back(Product(name, price, quantity));
}

// Function to view all products
void viewProducts(const std::vector<Product>& products) {
    for (const auto& product : products) {
        product.display();
    }
}

// Function to update a product's price
void updateProductPrice(std::vector<Product>& products, const std::string& productName) {
    for (auto& product : products) {
        if (product.getName() == productName) {
            float newPrice;
            std::cout << "Enter new price for " << productName << ": ";
            std::cin >> newPrice;
            product.updatePrice(newPrice);
            std::cout << "Price updated for " << productName << std::endl;
            return;
        }
    }
    std::cout << "Product not found." << std::endl;
}

// Function to delete a product
void deleteProduct(std::vector<Product>& products, const std::string& productName) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getName() == productName) {
            products.erase(it);
            std::cout << "Product " << productName << " deleted." << std::endl;
            return;
        }
    }
    std::cout << "Product not found." << std::endl;
}

int main() {
    std::vector<Product> products; // Vector to store products

    addProduct(products); // Add a product
    viewProducts(products); // View all products

    // Modify a product
    std::string productName = "Laptop";
    updateProductPrice(products, productName);
    viewProducts(products); // View all products after update

    // Delete a product
    deleteProduct(products, productName);
    viewProducts(products); // View all products after delete

    return 0;
}
