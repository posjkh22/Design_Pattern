
#include <iostream>
#include <string>

using namespace std;

class Image
{
public:
	virtual void ShowImage() = 0;

};

class RealImage : public Image
{
public:
	RealImage(const string& name) : mFile(name){}

public:
	void LoadImage(){ cout << "disk from loading file: " << mFile << endl; }
	void ShowImage(){ cout << "show image: " << mFile << endl; }

private:
	string mFile;

};

class ProxyImage : public Image
{
public:
	ProxyImage(const string& name) : mFile(name), mImage(NULL){}
	~ProxyImage(){ if(mImage) delete mImage; }

public:
	void ShowImage()
	{
		if(!mImage)
		{	
			mImage = new RealImage(mFile);
			mImage->LoadImage();

		}

		mImage->ShowImage();
	}

private:
	RealImage* mImage;
	string mFile;
};

int main()
{
	Image* pImage = new ProxyImage("Image.png");
	pImage->ShowImage();
	pImage->ShowImage();
	pImage->ShowImage();

	delete pImage;

	return 0;
}






