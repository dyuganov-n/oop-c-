#pragma once

#include "Robot.h"
#include "Repeater.h"

class Sapper : public IRobot {
private:
	const RobotClass _class = RobotClass::sapper;

public:
	Sapper() { 
		Coordinates coordinates = { 0, 0 };
		// init repeater
	}
	Sapper(const Map& _map) {
		this->_map = _map;
		Coordinates coordinates = { 0, 0 };
		// init repeater
	}
	Sapper(const Map& _map, const Coordinates& startPosition, Repeater* r) {
		this->_map = _map;
		pos = startPosition;
		// init repeater
	}
	virtual ~Sapper() {}

	// getting information about robot
	const RobotClass& getRobotClass() const {
		return this->_class;
	}

	// unique actions
	void defuse() {
		if (_map.getField()[pos.x][pos.y] == Object::bomb) {
			_map.setCell({ pos.x, pos.y }, Object::empty);
			repeater->notifyDefuse({ pos.x, pos.y });
			this->_map.setCell(pos, Object::empty);
		}
	}

};

