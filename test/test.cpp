#include <gtest/gtest.h>
#include <CircularQueue.hpp>

TEST(dummy, should_pass) {
  EXPECT_EQ(1, 1);
}

TEST(TestingCircularQueueMethods, checking_default_variables) {
	CircularQueue<int> q;
	ASSERT_EQ(1,q.capacity());
	ASSERT_EQ(0,q.size());
	ASSERT_FALSE(q.isFull());
	ASSERT_TRUE(q.isEmpty());
}

TEST(TestingIntCircularQueue, checking_methods) {
	CircularQueue<int> q;
	int element;
	q.push(5);
	EXPECT_EQ(1,q.size());
	q.pop(&element);
	EXPECT_EQ(5,element);
}

TEST(TestingCharCircularQueue, by_passing_size_of_queue) {
	CircularQueue<char> q(5);
	ASSERT_EQ(5, q.capacity());
}

TEST(TestingPop_Pushfunctions, by_using_int_CQ) {
	CircularQueue<int> q(4);
	int element;
 	EXPECT_FALSE(q.pop(&element));
  	EXPECT_TRUE(q.push(1));
  	q.push(2);
  	q.push(3);
  	q.push(4);
  	ASSERT_EQ(4,q.size());
  	EXPECT_FALSE(q.push(5));
  	EXPECT_TRUE(q.pop(&element));
  	EXPECT_TRUE(q.push(5));
}