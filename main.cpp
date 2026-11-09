#include "studentPtr.h"
#include <memory>


int main(){
    using namespace kimyewon2649007;

    studentPtr sp1{student{"kim",1234556,100}}; sp1.print();
    studentPtr sp2{sp1}; sp2.print();
    studentPtr sp3{std::move(sp2)}; sp2.print(); sp3.print();
    sp2 = std::move(sp3);
    sp3 = sp2;

    studentPtr* dp{new studentPtr};
    delete dp;

    std::unique_ptr<studentPtr> up1;
    auto up2{std::make_unique<studentPtr>(student{"name",1234567,100})};

    up1 = std::move(up2); up1->print();

    auto shp1{std::make_shared<studentPtr>(student{"kim",2345678,90})};
    std::cout << shp1.use_count()<<std::endl;

    std::shared_ptr<studentPtr> shp2{shp1};
    std::cout<<shp1.use_count()<<" "<< shp2.use_count()<< std::endl;

    std::weak_ptr<studentPtr> wp1{shp1};

    std::cout<<shp1.use_count()<<" "<< shp2.use_count()<< std::endl;
    
    shp1.reset();
    std::cout<<shp1.use_count()<<" "<< shp2.use_count()<< std::endl;
    
    
    if (!wp1.expired()) shp1 = wp1.lock();//메모리가 있다면
    std::cout<<shp1.use_count()<<" "<< shp2.use_count()<< std::endl;

    return 0;
}