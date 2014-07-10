#include "mapALG.h"


mapALG::mapALG(void)
{
}


mapALG::~mapALG(void)
{
}

int mapALG::preDefineParameters(int tileWidth, int tileHeight, const vector<int > & lodLevel, const vector<double > & lodResolution, double tileOriginLon, double tileOriginLat, const string & tileType, int tileBuffer)
{
	//vector<Lod> vecLod; 
	this->tileInfo.width=tileWidth;
	this->tileInfo.height=tileHeight;

	this->centerPoint.x=tileOriginLat;
	this->centerPoint.y=tileOriginLat;

	this->tileBuffer=tileBuffer;
	this->tileType=tileType;
	for(int i = 0; i < lodLevel.size(); ++i)
	{
		Lod temp;
		temp.level = lodLevel[i];
		temp.resolution = lodResolution[i];
		
		vecLod.push_back(temp);
	}
	return 1;
}
vector<ImageInfo>  mapALG::getImage(double map_left, double map_right, double map_bottom, double map_top, double resolution, const wstring & img_url, const wstring & img_path)
{
	// ��һ������   �����map �ǵ�ͼ�ϵľ��룿  ���ǵ�ͼ�ϵ����ؾ���/  ����

	int lodLevel=floor(sqrt(20037508.3427892 * 2 / 256/resolution)+0.5 );
	string typeSt="";
	if(this->tileType=="Satellite")
	{
		typeSt="s@140";// ����ͼ
		
	}
	else if(this->tileType=="Hybrid")
	{
		typeSt="t@128,r@177000000";//  ����ͼ
	}
	else
	{
		typeSt="m@177000000";// ��ͨͼ
	}
	

	int startX=floor((map_left-earthBounds.leftBottom.x)/resolution/tileInfo.width);//�������Ƭ��X���

	int startY=floor((map_bottom-earthBounds.leftBottom.y)/resolution/tileInfo.height);//���±���Ƭ��Y���

	int endX=floor((map_right-earthBounds.leftBottom.x)/resolution/tileInfo.width);//������Ƭ X ���

	int endY=floor((map_top-earthBounds.leftBottom.y)/resolution/tileInfo.height); //������Ƭ��Y ���

	double   startTilePositionX = earthBounds.leftBottom.x + (startX * 256 * resolution);
    double   startTilePositionY = earthBounds.leftBottom.y + (startY * 256 * resolution);
	double distanceX = (map_left -startTilePositionX ) / resolution;
	double distanceY = (map_bottom-startTilePositionY  ) / resolution;

	positionOfLeftBottom2ViewSize.width=distanceX;
	positionOfLeftBottom2ViewSize.height=distanceY;

	vector<ImageInfo> tempImages;
	//����Ϊ����ԭ�㣡�� 
	//����ͼƬ�������ԭ���λ�ü���

	int x, y;
	for (x=startX;x<=endX;x++)
		for(y=startY;y<=endY;y++)
		{
			ImageInfo _tempInfo;
			_tempInfo.left=x*256-map_left/resolution;
			_tempInfo.top=y*256-map_top/resolution;
			_tempInfo.name="http://mt"+NumToString((x+y)%3+1)+".google.cn/vt/lyrs="+typeSt+"&hl=zh-CN&gl=cn&x="+NumToString(x)+"&y="+NumToString(y)+"&z="+NumToString(lodLevel)+"&s=Galil";
			tempImages.push_back(_tempInfo);
		}
    return tempImages;
}

int main()
{
	int t=floor(log(20037508.3427892*2/76.437028285072728/256)/log(2.0)+0.5);
	cout<< t;
	getchar();

}