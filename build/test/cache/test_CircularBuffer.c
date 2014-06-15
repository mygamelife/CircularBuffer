#include "unity.h"
#include "CircularBuffer.h"
#include "CException.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void test_circularBufferNew_given_6_should_allotcate_CircularBuffer_obeject_with_a_buffer_of_6(void)

{

 CircularBuffer *cb = circularBufferNew(6);

 if ((((cb)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)17);;};

 if ((((cb->buffer)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)18);;};

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((cb->length)), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((cb->size)), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_UP)((cb->buffer)), (_U_SINT)(_UP)((cb->head)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((cb->buffer)), (_U_SINT)(_UP)((cb->tail)), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_HEX32);

 circularBufferDel(cb);

}



void test_circularBufferAdd_given_5_should_return_5_in_first_buffer_location(void)

{

 CircularBuffer *cb = circularBufferNew(6);

 circularBufferAdd(cb, 10);

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((cb->buffer[0])), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_INT);

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



 UnityAssertEqualNumber((_U_SINT)((11)), (_U_SINT)((cb->buffer[0])), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((12)), (_U_SINT)((cb->buffer[1])), (((void *)0)), (_U_UINT)44, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((13)), (_U_SINT)((cb->buffer[2])), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((14)), (_U_SINT)((cb->buffer[3])), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((15)), (_U_SINT)((cb->buffer[4])), (((void *)0)), (_U_UINT)47, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((cb->buffer[5])), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_INT);

}



void test_circularBufferAdd_when_buffer_full_head_return_back_to_first_location(void)

{

 unsigned int err;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  CircularBuffer *cb = circularBufferNew(6);

  circularBufferAdd(cb, 10);

  circularBufferAdd(cb, 1);

  circularBufferAdd(cb, 2);

  circularBufferAdd(cb, 3);

  circularBufferAdd(cb, 4);

  circularBufferAdd(cb, 5);



  UnityAssertEqualNumber((_U_SINT)(_UP)((cb->buffer)), (_U_SINT)(_UP)((cb->head)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((cb->tail)), (_U_SINT)(_UP)((cb->head)), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_HEX32);



 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityFail( ("Buffer is FULL!"), (_U_UINT)71);;

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



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((circularBufferRemove(cb))), (((void *)0)), (_U_UINT)86, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((cb->buffer[0])), (((void *)0)), (_U_UINT)87, UNITY_DISPLAY_STYLE_INT);

}



void test_circularBufferRemove_return_error_if_buffer_is_empty(void)

{

 unsigned int err;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  CircularBuffer *cb = circularBufferNew(6);

  circularBufferAdd(cb, 10);

  circularBufferAdd(cb, 4);

  circularBufferAdd(cb, 5);

  circularBufferAdd(cb, 6);

  circularBufferAdd(cb, 7);

  circularBufferAdd(cb, 8);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((circularBufferRemove(cb))), (((void *)0)), (_U_UINT)104, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((circularBufferRemove(cb))), (((void *)0)), (_U_UINT)105, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((circularBufferRemove(cb))), (((void *)0)), (_U_UINT)106, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((circularBufferRemove(cb))), (((void *)0)), (_U_UINT)107, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((circularBufferRemove(cb))), (((void *)0)), (_U_UINT)108, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((circularBufferRemove(cb))), (((void *)0)), (_U_UINT)109, UNITY_DISPLAY_STYLE_INT);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((cb->buffer[0])), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((cb->buffer[1])), (((void *)0)), (_U_UINT)112, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((cb->buffer[2])), (((void *)0)), (_U_UINT)113, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((cb->buffer[3])), (((void *)0)), (_U_UINT)114, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((cb->buffer[4])), (((void *)0)), (_U_UINT)115, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((cb->buffer[5])), (((void *)0)), (_U_UINT)116, UNITY_DISPLAY_STYLE_INT);

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityFail( ("Buffer is EMPTY!"), (_U_UINT)120);;

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



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((circularBufferRemove(cb))), (((void *)0)), (_U_UINT)136, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((circularBufferRemove(cb))), (((void *)0)), (_U_UINT)137, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((circularBufferRemove(cb))), (((void *)0)), (_U_UINT)138, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((circularBufferRemove(cb))), (((void *)0)), (_U_UINT)139, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((circularBufferRemove(cb))), (((void *)0)), (_U_UINT)140, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((circularBufferRemove(cb))), (((void *)0)), (_U_UINT)141, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)(_UP)((cb->buffer)), (_U_SINT)(_UP)((cb->tail)), (((void *)0)), (_U_UINT)143, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((cb->head)), (_U_SINT)(_UP)((cb->tail)), (((void *)0)), (_U_UINT)144, UNITY_DISPLAY_STYLE_HEX32);

}
