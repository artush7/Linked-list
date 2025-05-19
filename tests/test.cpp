#include <gtest/gtest.h>
#include "/home/artush/main/c++_project/homework/linked_list/src/linked_list.h"

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
