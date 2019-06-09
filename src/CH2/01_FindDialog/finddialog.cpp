#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QBoxLayout>
#include <QWidget>
#include "finddialog.h"

FindDialog::FindDialog(QWidget *parent)
	: QDialog(parent)
{
	label = new QLabel("Find &what:");
	lineEdit = new QLineEdit;
	label->setBuddy(lineEdit);

	caseCheckBox = new QCheckBox("Match &case");
	backwardCheckBox = new QCheckBox("Search &backward");

	findButton = new QPushButton("&Find");
	findButton->setDefault(true);
	findButton->setEnabled(false);

	closeButton = new QPushButton("Close");

	connect(lineEdit, SIGNAL(textChanged(const QString &)), SLOT(enableFindButton(const QString &)));
	connect(findButton, SIGNAL(clicked()), SLOT(findClicked()));
	connect(closeButton, SIGNAL(clicked()), SLOT(close()));

	QHBoxLayout *topLeftLayout = new QHBoxLayout;
	topLeftLayout->addWidget(label);
	topLeftLayout->addWidget(lineEdit);

	QVBoxLayout *leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topLeftLayout);
	leftLayout->addWidget(caseCheckBox);
	leftLayout->addWidget(backwardCheckBox);

	QVBoxLayout *rightLayout = new QVBoxLayout;
	rightLayout->addWidget(findButton);
	rightLayout->addWidget(closeButton);
	rightLayout->addStretch();

	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);

	setWindowTitle("Find");
	setFixedHeight(sizeHint().height());
}

void FindDialog::findClicked()
{
	QString text = lineEdit->text();
	Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;

	if (backwardCheckBox->isChecked()) {
		emit findPrevious(text, cs);
	} else {
		emit findNext(text, cs);
	}
}

void FindDialog::enableFindButton(const QString &text)
{
	findButton->setEnabled(!text.isEmpty());
}

/*
FindDialog::~FindDialog()
{
}
*/

