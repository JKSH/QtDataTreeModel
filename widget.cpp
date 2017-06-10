#include "widget.h"
#include "ui_widget.h"

#include "jsontreemodel.h"

#include <QDebug>

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{
	ui->setupUi(this);

///*
	QJsonArray modelData{
		QJsonObject{
			{"str1", "Hello"},
			{"str2", "World"}
		},
		"Yabba",
		"Dabba",
		QJsonObject{
			{"str1", "Scooby"},
			{"str2", "Doo"}
		},
		QJsonArray{
			QJsonObject{
				{"obj1", QJsonObject{
						{"str1", "So"},
						{"str2", "Long"}
					}
				},
				{"obj2", QJsonObject{
						{"str1", "Fare"},
						{"str2", "Well"}
					}
				}
			},
			"Yee",
			"Haw"
		}
	};
//*/

/*
	QJsonArray modelData{
		QJsonObject{
			{"str1", "Hello"}
		}
	};
*/

	qDebug() << modelData;

	auto model = new JsonTreeModel(this);
	model->setJson(modelData);

	qDebug() << "rowCount:" << model->rowCount();
	qDebug() << "columnCount:" << model->columnCount();

	ui->treeView->setModel(model);
}

Widget::~Widget()
{
	delete ui;
}
