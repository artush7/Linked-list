#include <gtest/gtest.h>
#include "linked_list.h"

TEST(list,head)
{
    linked_list<int> lst;
    lst.insert_head(5);
    EXPECT_EQ(lst.head->data,5);
}

TEST(list,head_1)
{
    linked_list<double> lst;
    lst.insert_head(6.7);
    lst.insert_head(5.7);
    EXPECT_EQ(lst.head->next_address->data,6.7);
    EXPECT_EQ(lst.head->data,5.7);
}

TEST(list,insert)
{
    linked_list<int> lst;
    lst.insert(0, 10);
    lst.insert(1, 20);
    lst.insert(1, 15);

    EXPECT_EQ(lst.head->data, 10);
    EXPECT_EQ(lst.head->next_address->data, 15);
    EXPECT_EQ(lst.head->next_address->next_address->data, 20);

}

TEST(list,insert_tail)
{
    linked_list<double> lst;
    lst.insert_tail(1.5);
    lst.insert_tail(2.5);
    EXPECT_EQ(lst.head->data,1.5);
    EXPECT_EQ(lst.head->next_address->data,2.5);
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

    EXPECT_EQ(lst1.head->data,4);
    EXPECT_EQ(lst1.head->next_address->data,5);

    lst.head->data = 999;
    EXPECT_EQ(lst1.head->data, 4); 
    
}

TEST(list,copy_operator)
{
    linked_list<int> original;
    original.insert_head(5);

    linked_list<int> copy;

    copy.insert_head(11);
    copy.insert_head(10);

    original = copy;

    EXPECT_EQ(original.head->data, 10); 

}

TEST(list,move_constructor)
{
    linked_list<int> original;
    original.insert_head(11);
    original.insert_head(10);

    linked_list<int> move(std::move(original));


    EXPECT_EQ(move.head->data, 10); 

}

TEST(list,move_operator)
{
    linked_list<int> original;

    original.insert_head(11);
    original.insert_head(10);
    linked_list<int> move;

    move.insert_head(9);

    move = std::move(original);

    EXPECT_EQ(move.head->data,10); 
}

