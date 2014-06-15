#include <stdio.h>
#include "unity.h"
#include "CException.h"
#include "CircularBuffer.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_circularBufferNew_given_6_should_allotcate_CircularBuffer_obeject_with_a_buffer_of_6(void)
{
	CircularBuffer *cb = circularBufferNew(6);
	TEST_ASSERT_NOT_NULL(cb);
	TEST_ASSERT_NOT_NULL(cb->buffer);
	TEST_ASSERT_EQUAL(6,cb->length);
	TEST_ASSERT_EQUAL(0,cb->size);
	TEST_ASSERT_EQUAL_PTR(cb->buffer,cb->head);
	TEST_ASSERT_EQUAL_PTR(cb->buffer,cb->tail);
	circularBufferDel(cb);
}

void test_circularBufferAdd_given_5_should_return_5_in_first_buffer_location(void)
{
	CircularBuffer *cb = circularBufferNew(6);
	circularBufferAdd(cb, 10);
	TEST_ASSERT_EQUAL(10 , cb->buffer[0]);
}

void test_circularBufferAdd_given_11_12_13_14_15_16_buffer_should_contain_11_12_13_14_15_16(void)
{
	CircularBuffer *cb = circularBufferNew(6);
	circularBufferAdd(cb, 11);
	circularBufferAdd(cb, 12);
	circularBufferAdd(cb, 13);
	circularBufferAdd(cb, 14);
	circularBufferAdd(cb, 15);
	circularBufferAdd(cb, 16);
		
	TEST_ASSERT_EQUAL(11, cb->buffer[0]);
	TEST_ASSERT_EQUAL(12, cb->buffer[1]);
	TEST_ASSERT_EQUAL(13, cb->buffer[2]);
	TEST_ASSERT_EQUAL(14, cb->buffer[3]);
	TEST_ASSERT_EQUAL(15, cb->buffer[4]);
	TEST_ASSERT_EQUAL(16, cb->buffer[5]);
}

void test_circularBufferAdd_when_buffer_full_head_return_back_to_first_location(void)
{
	CEXCEPTION_T err;
	
	Try
	{
		CircularBuffer *cb = circularBufferNew(6);
		circularBufferAdd(cb, 10);
		circularBufferAdd(cb, 1);
		circularBufferAdd(cb, 2);
		circularBufferAdd(cb, 3);
		circularBufferAdd(cb, 4);
		circularBufferAdd(cb, 5);
		
		TEST_ASSERT_EQUAL_PTR(cb->buffer , cb->head);
		TEST_ASSERT_EQUAL_PTR(cb->tail , cb->head);
		
	}
	Catch(err)
	{
		TEST_FAIL_MESSAGE("Buffer is FULL!");
	}
}

void test_circularBufferRemove_remove_one_element_and_remove_first_element(void)
{
	
	CircularBuffer *cb = circularBufferNew(6);
	circularBufferAdd(cb, 10);
	circularBufferAdd(cb, 4);
	circularBufferAdd(cb, 5);
	circularBufferAdd(cb, 6);
	circularBufferAdd(cb, 7);
	circularBufferAdd(cb, 8);
	
	TEST_ASSERT_EQUAL(1 , circularBufferRemove(cb));
	TEST_ASSERT_EQUAL(0 , cb->buffer[0]); //first element is removed;
}

void test_circularBufferRemove_return_error_if_buffer_is_empty(void)
{
	CEXCEPTION_T err;
	
	Try
	{
		CircularBuffer *cb = circularBufferNew(6);
		circularBufferAdd(cb, 10);
		circularBufferAdd(cb, 4);
		circularBufferAdd(cb, 5);
		circularBufferAdd(cb, 6);
		circularBufferAdd(cb, 7);
		circularBufferAdd(cb, 8);
		
		TEST_ASSERT_EQUAL(1 , circularBufferRemove(cb));
		TEST_ASSERT_EQUAL(1 , circularBufferRemove(cb));
		TEST_ASSERT_EQUAL(1 , circularBufferRemove(cb));
		TEST_ASSERT_EQUAL(1 , circularBufferRemove(cb));
		TEST_ASSERT_EQUAL(1 , circularBufferRemove(cb));
		TEST_ASSERT_EQUAL(1 , circularBufferRemove(cb)); 
		
		TEST_ASSERT_EQUAL(0 , cb->buffer[0]); //first element is removed;
		TEST_ASSERT_EQUAL(0 , cb->buffer[1]);
		TEST_ASSERT_EQUAL(0 , cb->buffer[2]);
		TEST_ASSERT_EQUAL(0 , cb->buffer[3]);
		TEST_ASSERT_EQUAL(0 , cb->buffer[4]);
		TEST_ASSERT_EQUAL(0 , cb->buffer[5]);
	}
	Catch(err)
	{
		TEST_FAIL_MESSAGE("Buffer is EMPTY!");
	}
	
}

void test_circularBufferRemove_when_all_element_is_removed_tail_return_to_first_location(void)
{
	
	CircularBuffer *cb = circularBufferNew(6);
	circularBufferAdd(cb, 9);
	circularBufferAdd(cb, 8);
	circularBufferAdd(cb, 7);
	circularBufferAdd(cb, 6);
	circularBufferAdd(cb, 5);
	circularBufferAdd(cb, 4);
	
	TEST_ASSERT_EQUAL(1 , circularBufferRemove(cb));
	TEST_ASSERT_EQUAL(1 , circularBufferRemove(cb));
	TEST_ASSERT_EQUAL(1 , circularBufferRemove(cb));
	TEST_ASSERT_EQUAL(1 , circularBufferRemove(cb));
	TEST_ASSERT_EQUAL(1 , circularBufferRemove(cb));
	TEST_ASSERT_EQUAL(1 , circularBufferRemove(cb));
	
	TEST_ASSERT_EQUAL_PTR(cb->buffer , cb->tail);
	TEST_ASSERT_EQUAL_PTR(cb->head , cb->tail); //now tail and head should point to the same place
}