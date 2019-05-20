//#include<gtest.h>
#include<iostream>
#include<assert.h>
//#include"GrabMoniter.h"




TEST(GrabSwitch, my_test_1) {
   //����ץȡģʽ
   GrabSwitch(true);
   assert(behavior_msg.data == "grab start");
   //�ر�ץȡģʽ
   GrabSwitch(false);
   assert(behavior_msg.data == "grab stop");
}

TEST(PassSwitch, my_test_2) {
   //����ץȡģʽ
   PassSwitch(true);
   assert(behavior_msg.data == "pass start");
   //�ر�ץȡģʽ
   PassSwitch(false);
   assert(behavior_msg.data == "pass stop");
}

TEST(PassSwitch, my_test_3) {
   //�����ݸ�ģʽ
   PassSwitch(true);
   assert(behavior_msg.data == "pass start");
   //�رյݸ�ģʽ
   PassSwitch(false);
   assert(behavior_msg.data == "pass stop");
}

TEST(GrabResultCallback, my_test_4) {
   const std_msgs::String::ConstPtr& res1 = "done";
   const std_msgs::String::ConstPtr& res2 = "not yet";
   //δ���������Ϣ
   GrabResultCallback(res2);
   assert(bGrabDone != true);
   //���������Ϣ
   GrabResultCallback(res1);
   assert(bGrabDone == true);
}

TEST(PassResultCallback, my_test_5) {
   const std_msgs::String::ConstPtr& res1 = "done";
   const std_msgs::String::ConstPtr& res2 = "not yet";
   //δ���������Ϣ
   PassResultCallback(res2);
   assert(bPassDone != true);
   //���������Ϣ
   PassResultCallback(res1);
   assert(bPassDone == true);
}

TEST(GrabObj, my_test_6) {
    //��ʼץȡ����ǰ
    nDelay = 0;
    bGrabDone = false;
    GrabObj();
    assert(bGrabDone == false);
    assert(nDelay == 1);

    //����ץȡ������
    nDelay = 10;
    bGrabDone = false;
    GrabObj();
    assert(bGrabDone == false);
    assert(nDelay == 11);

    //����ץȡ����
    nDelay = 10;
    bGrabDone = true;
    GrabObj();
    assert(nState == STATE_COMEBACK);
    assert(nDelay == 11);
}

TEST(PassObj(), my_test_6) {
    //��ʼ�ݸ�����ǰ
    nDelay = 0;
    bPassDone = false;
    PassObj();
    assert(bPassDone == false);
    assert(nDelay == 1);

    //���еݸ�������
    nDelay = 10;
    bPassDone = false;
    PassObj();
    assert(bPassDone == false);
    assert(nDelay == 11);

    //�����ݸ�����
    nDelay = 10;
    bPassDone = true;
    PassObj();
    assert(nState == STATE_ASK);
    assert(nDelay == 11);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
