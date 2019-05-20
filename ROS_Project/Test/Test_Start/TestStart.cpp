#include <gtest.h>
#include <iostream>
#include "preSet.h"
#include "start.h"

//��FollowSwitch���в���
TEST(FollowSwitch,case1){
	//��������ɹ�
	warnMsg[0]='1';
	FollowSwitch(true,0.7);
	//�����ɹ���ROS_WARN����ִ�У�warnMsg���ᱻ�޸�
	EXPECT_EQ('1',warnMsg[0]);

	//��������ʧ��
	warnMsg[0]='1';
	FollowSwitch(true,0.0);
	//����ʧ�ܣ�ROS_WARN��ִ�У�warnMsg�ᱻ�޸�
	EXPECT_NE('1',warnMsg[0]);

	//ֹͣ����ɹ�
	warnMsg[0]='1';
	srvFlw.request.thredhold=0.7;
	FollowSwitch(false,0.7);
	//ֹͣ�ɹ���ROS_WARN����ִ�У�warnMsg���ᱻ�޸�
	EXPECT_EQ('1',warnMsg[0]);

	//ֹͣ����ʧ��
	warnMsg[0]='1';
	srvFlw.request.thredhold=0.0;
	FollowSwitch(false,0.7);
	//ֹͣʧ�ܣ�ROS_WARN��ִ�У�warnMsg�ᱻ�޸�
	EXPECT_NE('1',warnMsg[0]);
}

//��start���в���
TEST(start,case2){
	//��������׼����
	addMsg[0]='1';
	nDelay=1;
	nState=0;
	start();

	EXPECT_EQ(2,nDelay);//����������Ӧ������
	EXPECT_EQ('1',addMsg[0]);//׼����δ������AddNewWaypoint���ᱻִ�У�addMsg���ᱻ�޸�
	EXPECT_EQ(0,nState);//׼����δ������nState���ᱻ�޸�

	//����׼�����
	addMsg[0]='1';
	nDelay=100;
	nState=0;
	start();

	EXPECT_EQ(0,nDelay);//����������Ӧ������
	EXPECT_NE('1',addMsg[0]);//׼��������AddNewWaypoint�ᱻִ�У�addMsg�ᱻ�޸�
	EXPECT_EQ(STATE_FOLLOW,nState);//׼��������nState�ᱻ�޸�
}

//��follow���в���
TEST(follow,case3){
	//����׼���ո����
	nDelay=0;
	srvFlw.request.thredhold=0.0;
	follow();

	EXPECT_LT(0.1,srvFlw.request.thredhold);//׼���ո���ɣ�FollowSwitch�����ã�thredhold������
	EXPECT_EQ(1,nDelay);//����������
	

	//����׼���������
	nDelay=10;
	srvFlw.request.thredhold=0.11;
	follow();

	EXPECT_LT(srvFlw.request.thredhold,0.12);//׼��������ɣ�FollowSwitch���ᱻ���ã�thredhold���ᱻ����
	EXPECT_EQ(11,nDelay);//����������
}

int main(int argc,char* argv[]){
	//��ʼ������������
	testing::InitGoogleTest(&argc, argv); 
	return RUN_ALL_TESTS();
}