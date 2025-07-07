#include <gtest/gtest.h>
#include "linked_list.h"

TEST(list,head)
{
    linked_list<int> lst;
    lst.insert_head(5);
    auto head = lst.get_head();
    EXPECT_EQ(head->data,5);
}

 TEST(list,head_1)
 {
     linked_list<double> lst;
     lst.insert_head(6.7);
     lst.insert_head(5.7);

     auto head = lst.get_head();
     EXPECT_EQ(head->next_address->data,6.7);
     EXPECT_EQ(head->data,5.7);
 }

TEST(list,insert)
{
    linked_list<int> lst;
    lst.insert(0, 10);
    lst.insert(1, 20);
    lst.insert(1, 15);

    auto head = lst.get_head();

    EXPECT_EQ(head->data, 10);
    EXPECT_EQ(head->next_address->data, 15);
    EXPECT_EQ(head->next_address->next_address->data, 20);

}

TEST(list,insert_tail)
{
    linked_list<double> lst;
    lst.insert_tail(1.5);
    lst.insert_tail(2.5);

    auto head = lst.get_head();

    EXPECT_EQ(head->data,1.5);
    EXPECT_EQ(head->next_address->data,2.5);
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

    auto head = lst1.get_head();

    EXPECT_EQ(head->data,4);
    EXPECT_EQ(head->next_address->data,5);

    auto head1 = lst.get_head();

    head1->data = 999;
    EXPECT_EQ(head->data, 4); 
    
}

TEST(list,copy_operator)
{
    linked_list<int> original;
    original.insert_head(5);


    linked_list<int> copy;


    copy.insert_head(11);
    copy.insert_head(10);


    original = copy;
    auto head_o = original.get_head();
    EXPECT_EQ(head_o->data, 10); 

}

TEST(list,move_constructor)
{
    linked_list<int> original;
    original.insert_head(11);
    original.insert_head(10);

    linked_list<int> move(std::move(original));

    auto head = move.get_head();
    EXPECT_EQ(head->data, 10); 

}

TEST(list,move_operator)
{
    linked_list<int> original;

    original.insert_head(11);
    original.insert_head(10);
    linked_list<int> move;

    move.insert_head(9);

    move = std::move(original);
    auto head = move.get_head();
    EXPECT_EQ(head->data,10); 
}

TEST(list,lambda)
{
    linked_list<int> original;

    original.insert_head(12);
    original.insert_head(11);
    original.insert_head(10);

    original.ForEach([](int& x){x = x * x;});

        auto head = original.get_head();

    EXPECT_EQ(head->data,100);
    EXPECT_EQ(head->next_address->data,121);
    EXPECT_EQ(head->next_address->next_address->data,144);


}

TEST(list,lambda_2)
{
    linked_list<int> original;

    original.insert_head(12);
    original.insert_head(11);
    original.insert_head(10);

    original.ForEach([](int& x){x = x - 1;});

    auto head = original.get_head();

    EXPECT_EQ(head->data,9);
    EXPECT_EQ(head->next_address->data,10);
    EXPECT_EQ(head->next_address->next_address->data,11);


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