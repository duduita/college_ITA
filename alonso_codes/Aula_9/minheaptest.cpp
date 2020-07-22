#include <iostream>
#include <vector>
#include <algorithm>

class City
{
public:
    City() : x(0), y(0), id(0){};
    City(int x_, float y_, float id_) : x(x_), y(y_), id(id_){};

    int disti(City &c)
    {
        return (int)round(dist(c));
    }

    float dist(City &c)
    {
        return (sqrt((x - c.x) * (x - c.x) + (y - c.y) * (y - c.y)));
    }

    float getx() const { return x; }
    float gety() const { return y; }
    int getId() const { return id; }

    void copy(City &c)
    {
        x = c.getx();
        y = c.gety();
        id = c.getId();
    }

struct doc_rank_greater_than {
    bool operator()(doc const& a, doc const& b) const {
        return a.rank > b.rank;
    }
};

private:
    float x;
    float y;
    int id;
};

int main() {
    std::vector<City> docvec;
    docvec.push_back( City(1, 2, 5) );
    std::make_heap(docvecbegin(),docvec.end(),doc_rank_greater_than());
    std::cout << docvec.front().rank << '\n';
}
