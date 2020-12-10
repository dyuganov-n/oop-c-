#pragma once

#include "Robot.h"
#include "Explorer.h"
#include "Sapper.h"

// modes could be singletones

class IMode {
public:
	void virtual invokeCommand(IRobot* robot) = 0;
};

class IdlingMode : public IMode {
public:
	void invokeCommand(IRobot* robot) override;
	static IdlingMode* getInstance();

private:
	static IdlingMode* p_instance;
	IdlingMode() = default;
	~IdlingMode() { delete p_instance; }
};

class ManualMode : public IMode {
public:
	void invokeCommand(IRobot* robot) override;
	static ManualMode* getInstance();

private:
	static ManualMode* p_instance;
	ManualMode() = default;
	~ManualMode() {
		delete p_instance;
	}
};

class ScanMode : public IMode {
public:
	void invokeCommand(IRobot* robot) override;
	static ScanMode* getInstance();
	
private:
	static ScanMode* p_instance;
	ScanMode() = default;
	~ScanMode() { delete p_instance; }
};

class AutoMode : public IMode {
public:
	void invokeCommand(IRobot* robot) override;
	static AutoMode* getInstance();

private:
	static AutoMode* p_instance;
	AutoMode() = default;
	~AutoMode() {
		delete p_instance;
	}
};


