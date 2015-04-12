#ifndef STRATEGY_H
#define STRATEGY_H

class Strategy {
	public:
		int getStrategy();
		virtual void execute();
		Strategy();
};

#endif