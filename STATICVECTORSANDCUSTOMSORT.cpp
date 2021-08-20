#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

#include <functional>

using namespace std;

class Product
{

private:
    string name;

    string type;

    int price;

    static int currentTotal;

    static int productCount;

    static vector<Product *> products;

public:
    Product(string n, string t, int p = 1000) : name(n), type(t), price(p)
    {

        Product::addPriceToTotal(p);

        Product::productCount += 1;

        Product::products.push_back(this);
    }

    static void addPriceToTotal(int x)
    {

        Product::currentTotal += x;
    }

    static void removePriceFromTotal(int x)
    {

        Product::currentTotal -= x;
    }

    static int getTotal()
    {

        return Product::currentTotal;
    }

    static int getProductCount()
    {

        return Product::productCount;
    }

    static int getAvg()
    {

        return Product::currentTotal / Product::productCount;
    }

    static void showProducts()
    {

        function<bool(Product *, Product *)> lambda = [](Product *x, Product *y)
        { return (x->price) < (y->price); };

        sort(Product::products.begin(), Product::products.end(), lambda);

        cout << "Name\ttype\tprice\n";

        for (Product *element : Product::products)
        {

            cout << element->name << "\t" << element->type << "\t" << element->price << "\n";
        }
    }
};

int Product::currentTotal = 0;

int Product::productCount = 0;

vector<Product *> Product::products;

int main()
{

    Product *p1 = new Product("dvd", "hw", 150);

    Product *p2 = new Product("dvd", "hw", 2000);

    Product *p3 = new Product("dvd", "hw", 3500);

    Product *p4 = new Product("dvd", "hw", 2200);

    Product *p5 = new Product("dvd", "hw", 3600);

    Product *p6 = new Product("dvd", "hw", 2500);

    Product *p7 = new Product("dvd", "hw");

    Product *p8 = new Product("dvd", "hw");

    cout << Product::getTotal() << "\n";

    cout << Product::getProductCount() << "\n";

    cout << Product::getAvg() << "\n";

    Product::showProducts();

    return 0;
}