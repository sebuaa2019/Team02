#include "main.h" 

void start(){//����׼���׶�

	if(nState == STATE_READY){
		nDelay ++;//ά��ʱ������������������õ�׼��ʱ��
		if(nDelay > 100){//׼��ʱ���ѵ���Ĭ��׼���Ѿ����
			nDelay = 0;//׼����ʱ����������������
			AddNewWaypoint("start");
			nState = STATE_FOLLOW;//׼����ɣ��������׶�
		}
	}

}

void follow(){//����׶�

	if(nState == STATE_FOLLOW){
		//���������ʱ��Ϊ0����˵������׼���ո����
		if(nDelay == 0){
			FollowSwitch(true, 0.7);//��������˽������״̬
		}
		//���������ʱ�䲻Ϊ0��˵������������ɣ��������Ѿ����ڸ���״̬

		nDelay ++;//ά��ʱ��������������˴��ڸ���״̬��ʱ��
	}

}
