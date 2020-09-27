#include <qapplication.h>
#include <qwidget.h>
#include <qpushbutton.h>

class PbEx:public QWidget{
public:
	PbEx();
private:
	QPushButton *p;
};

PbEx::PbEx()
{
	resize(100,80);
	p = new QPushButton("Push Button1", this);
	p->setGeometry(10,10,40,20);
};

int main(int argc, char** argv)
{
	QApplication app(argc,argv);
	PbEx myPb;
	myPb.show();
}
