#ifndef WORKERTHREAD_HPP_
#define WORKERTHREAD_HPP_

#include <QtCore>
#include <QMutex>
#include "StringFormula.hpp"
#include "TruthTree.hpp"

class WorkerThread public QThread{
	Q_OBJECT

	TruthTree truthTree;
	bool stop;
	QMutex stopLock;
	void run();

public:
	WorkerThread(StringFormula formula);
	WorkerThread(string formula);

public slots:
	startComputation();
	abortComputation();

signals:
	stepDone(string forrmatedTree);
	allDone(string forrmatedTree, bool result);

};



#endif /* WORKERTHREAD_HPP_ */
