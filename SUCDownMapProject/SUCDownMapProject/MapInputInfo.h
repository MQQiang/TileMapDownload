#pragma once
class MapInputInfo
{
public:
	MapInputInfo(void);
	~MapInputInfo(void);
	Pos2D  left_top_degree;// ���Ͼ�γ��
	Pos2D  right_down_degree;//���¾�γ��
	string  imageFormart;//ͼƬ��ʽ  png,jpg
	string  mapSererUrl;// ������url
	int minLevel;// ��С��
	int maxLevel;// ����
	string defaultFilePath; // �ļ��洢·��
	int  threadNum;// �߳���
};

