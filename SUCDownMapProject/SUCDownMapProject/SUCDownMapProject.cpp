// SUCDownMapProject.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "SUCMapDownloadUtil.h"

#pragma comment(lib, "urlmon.lib")
//using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	
	// ��������������Ϣ
	MapInputInfo * mapInfo = new MapInputInfo;
	if (mapInfo == NULL)
		return 0;
	// ���ع�����
	SUCMapDownloadUtil * mapUtil  = new SUCMapDownloadUtil;
	if (mapUtil == NULL)
		return 0;
	/*mapUtil->setMapInputInfo( mapInfo );*/
	std::cout << "download start"<< endl;
	mapUtil->DownLoadMapFromServer( mapInfo ) ;
	
	delete mapInfo;
	mapInfo = NULL;
	delete mapUtil;
	mapUtil = NULL;

	std::cout << "download complete"<< endl;
	system("pause");
    return 0;
}