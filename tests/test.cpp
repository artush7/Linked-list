#include <gtest/gtest.h>
#include "linked_list.h"

TEST(list,head)
{
    linked_list<int> lst;
    lst.insert_head(5);

    EXPECT_EQ(lst.get(0),5);
}

 TEST(list,head_1)
 {
     linked_list<double> lst;
     lst.insert_head(6.7);
     lst.insert_head(5.7);

     EXPECT_EQ(lst.get(1),6.7);
     EXPECT_EQ(lst.get(0),5.7);
 }

TEST(list,insert)
{
    linked_list<int> lst;
    lst.insert(0, 10);
    lst.insert(1, 20);
    lst.insert(1, 15);


    EXPECT_EQ(lst.get(0), 10);
    EXPECT_EQ(lst.get(1), 15);
    EXPECT_EQ(lst.get(2), 20);

}

TEST(list,insert_tail)
{
    linked_list<double> lst;
    lst.insert_tail(1.5);
    lst.insert_tail(2.5);

    EXPECT_EQ(lst.get(0),1.5);
    EXPECT_EQ(lst.get(1),2.5);
}

TEST(list,get)
{
    linked_list<double> lst;
    lst.insert_tail(1.5);
    lst.insert(0, 10);
    lst.insert_head(6.7);
    EXPECT_EQ(lst.get(0),6.7);
    EXPECT_EQ(lst.get(1),10);
}

TEST(list, remove)
{
    linked_list<int> list;
    list.insert_head(20);
    list.insert_head(10);

    list.remove(0); 

    EXPECT_EQ(list.get(0), 20);
}

TEST(list,copy_constructor)
{
    linked_list<int> lst;
    lst.insert_head(5);
    lst.insert_head(4);


    linked_list<int> lst1(lst);


    EXPECT_EQ(lst1.get(0),4);
    EXPECT_EQ(lst1.get(1),5);


    lst.insert(0,999);
    EXPECT_EQ(lst1.get(0), 4); 
    
}

TEST(list,copy_operator)
{
    linked_list<int> original;
    original.insert_head(5);


    linked_list<int> copy;


    copy.insert_head(11);
    copy.insert_head(10);


    original = copy;

    EXPECT_EQ(original.get(0), 10); 

}

TEST(list,move_constructor)
{
    linked_list<int> original;
    original.insert_head(11);
    original.insert_head(10);

    linked_list<int> move(std::move(original));

    EXPECT_EQ(move.get(0), 10); 

}

TEST(list,move_operator)
{
    linked_list<int> original;

    original.insert_head(11);
    original.insert_head(10);

    linked_list<int> move;

    move.insert_head(9);

    move = std::move(original);

    EXPECT_EQ(move.get(0), 10); 
}

TEST(list,lambda)
{
    linked_list<int> original;

    original.insert_head(12);
    original.insert_head(11);
    original.insert_head(10);

    original.ForEach([](int& x){x = x * x;});

    EXPECT_EQ(original.get(0), 100);
    EXPECT_EQ(original.get(1),121);
    EXPECT_EQ(original.get(2),144);


}

TEST(list,lambda_2)
{
    linked_list<int> original;

    original.insert_head(12);
    original.insert_head(11);
    original.insert_head(10);

    original.ForEach([](int& x){x = x - 1;});


    EXPECT_EQ(original.get(0),9);
    EXPECT_EQ(original.get(1),10);
    EXPECT_EQ(original.get(2),11);


}

TEST(list,exception_insert)
{
    linked_list<int> original;
    original.insert_head(10);

    EXPECT_THROW({original.insert(2,10);},std::out_of_range);
}

TEST(list,exception_insert_1)
{
    linked_list<int> original;

    EXPECT_THROW({original.insert(1,10);},std::out_of_range);
}

TEST(list,exception_get)
{
    linked_list<int> original;
    original.insert_head(10);

    EXPECT_THROW({original.get(2);},std::out_of_range);
}

TEST(list,exception_get_1)
{
    linked_list<int> original;

    EXPECT_THROW({original.get(0);},std::out_of_range);
}

TEST(list,exception_remove)
{
    linked_list<int> original;

    EXPECT_THROW({original.remove(0);},std::out_of_range);
}

TEST(list,exception_remove_1)
{
    linked_list<int> original;
    original.insert_head(10);

    EXPECT_THROW({original.remove(1);},std::out_of_range);
}


TEST(list,exception_remove_2)
{
    linked_list<int> original;
    original.insert_head(10);

    EXPECT_THROW({original.remove(2);},std::out_of_range);
}

TEST(list,iterator)
{
    linked_list<int> original;

    original.insert_head(12);
    original.insert_head(11);
    original.insert_head(10); 

    auto it = original.begin();
    EXPECT_EQ(*it,10);
}

TEST(list,iterator_1)
{
    linked_list<int> original;

    original.insert_head(12);
    original.insert_head(11);
    original.insert_head(10); 

    auto it = original.begin();
    it++;
    EXPECT_EQ(*it,11);
}

TEST(list,iterator_2)
{
    linked_list<int> original;

    original.insert_head(12);
    original.insert_head(11);
    original.insert_head(10); 

    auto it = original.begin();

    it++;
    it++;
    it++;

    EXPECT_EQ(it,original.end());
}

TEST(list,iterator_3)
{
    linked_list<int> original;

    original.insert_head(12);
    original.insert_head(11);
    original.insert_head(10); 

    auto it = original.begin();

    EXPECT_EQ(*it,10);
    it++;
    EXPECT_EQ(*it,11);
    it++;
    EXPECT_EQ(*it,12);
    it++;

    EXPECT_EQ(it,original.end());
}

TEST(list,iterato_find)
{
    linked_list<int> lst;

    lst.insert_head(12);
    lst.insert_head(11);
    lst.insert_head(10); 

    auto it = std::find(lst.begin(),lst.end(),11);
    EXPECT_EQ(*it,11);

    auto it1 = std::find(lst.begin(),lst.end(),20);
    EXPECT_EQ(it1,lst.end());
}

TEST(list,iterato_distance)
{
    linked_list<int> lst;

    lst.insert_head(12);
    lst.insert_head(11);
    lst.insert_head(10);

    auto d = std::distance(lst.begin(),lst.end());
    EXPECT_EQ(d,3);
}

TEST(list,iterato_copy)
{
    linked_list<int> lst;

    lst.insert_head(12);
    lst.insert_head(11);
    lst.insert_head(10);

    auto out_it = std::ostream_iterator<int>(std::cout," ");
    std::copy(lst.begin(),lst.end(),out_it);
    std::cout << std::endl;
}



TEST(list,throw_2)
{
    linked_list<int> lst;
    auto it = lst.end();

    EXPECT_THROW({*it;},std::logic_error);

}

TEST(list,throw_3)
{
    linked_list<int> lst;
    auto it = lst.end();

    EXPECT_THROW({it++;},std::logic_error);

}

TEST(list,throw_4)
{
    linked_list<int> lst;
    auto it = lst.end();

    EXPECT_THROW({++it;},std::logic_error);

}

