#include "View.h"
/*
void ConsoleView::displayMap(Manager* mngr, const int& oneSideViewField, const ViewMode& VMode) {
	if (mngr->getRobots().empty()) throw exception("Can't display map. Robots vector is empty.");
	IRobot* mainRobot = mngr->getRobots().at(0).second;
	if (mainRobot == nullptr) throw exception("Can't display map. Main robot pointer is nullptr.");
	
	system("cls");

	ptrdiff_t x = 0, y = 0;

	for (ptrdiff_t i = -oneSideViewField; i < oneSideViewField; ++i) {
		for (ptrdiff_t j = -oneSideViewField; j < oneSideViewField; ++j) {

			// x, y generation 
			
			x = static_cast<ptrdiff_t>(mainRobot->getCoordinates().x) + i;
			y = static_cast<ptrdiff_t>(mainRobot->getCoordinates().y) + j;

			// point is robot check
			if (robotInCell(mngr->getRobots(), x, y)) {
				for (auto item : mngr->getRobots()) {
					if (item.second->getCoordinates().x == x && item.second->getCoordinates().y == y) {
						if (item.second->getRobotClass() == RobotClass::explorer) {
							std::cout << "E ";
						}
						else if (item.second->getRobotClass() == RobotClass::sapper) {
							std::cout << "S ";
						}
					}
				}
				continue;
			}

			// map edge
			if (x < 0 || x > static_cast<ptrdiff_t>(mngr->getEnvironment()->getGlobalMap().getMapLength())) {
				std::cout << "  ";
				continue;
			}
			if (y < 0 || y > static_cast<ptrdiff_t>(mngr->getEnvironment()->getGlobalMap().getMapWidth())) {
				std::cout << "  ";
				continue;
			}

			ptrdiff_t _x = 0, _y = 0;
			if (x >= 0 && y >= 0) {
				_x = static_cast<size_t>(x);
				_y = static_cast<size_t>(y);
			}
			else {
				throw exception("Console view error. Coordinates can't be negative.");
			}

			// map display
			if (VMode == ViewMode::GlobalMap) {
				const Object& obj = mngr->getEnvironment()->getObject({ _x, _y });
				if (obj == Object::unknown) std::cout << "? ";
				else if (obj == Object::apple) std::cout << "A ";
				else if (obj == Object::bomb) std::cout << "B ";
				else if (obj == Object::empty) std::cout << ". ";
				else if (obj == Object::rock) std::cout << "# ";
			}
			else if(VMode == ViewMode::LocalMap) {
				const Object& obj = mngr->getRobotsMap().getObject({ _x, _y });
				if (obj == Object::unknown) std::cout << "? ";
				else if (obj == Object::apple) std::cout << "A ";
				else if (obj == Object::bomb) std::cout << "B ";
				else if (obj == Object::empty) std::cout << ". ";
				else if (obj == Object::rock) std::cout << "# ";
			}
			else {
				throw exception("ConsoleView displayMap error. Unknown view mode.");
			}
		}
		std::cout << std::endl;
	}
	cout << "Apples collected: " << mngr->getEnvironment()->getCollectedCnt() << endl;
}*/

void ConsoleView::displayMap(Manager* mngr, const int& oneSideViewField, const ViewMode& VMode) {
	if (mngr->getRobots().empty()) throw exception("Can't display map. Robots vector is empty.");
	IRobot* mainRobot = mngr->getRobots().at(0).second;
	if (mainRobot == nullptr) throw exception("Can't display map. Main robot pointer is nullptr.");
	
	system("cls");

	//ptrdiff_t x = 0, y = 0;
	Coordinates tmp;
	Object obj = Object::unknown;

	for (ptrdiff_t i = -oneSideViewField; i < oneSideViewField; ++i) {
		for (ptrdiff_t j = -oneSideViewField; j < oneSideViewField; ++j) {

			tmp.x = mainRobot->getCoordinates().x + i;
			tmp.y = mainRobot->getCoordinates().y + j;

			if (mngr->getEnvironment()->isOverGlobalMapEnd(tmp)) {
				cout << "  ";
				continue;
			}

			if (robotInCell(mngr->getRobots(), tmp)) {
				for (auto item : mngr->getRobots()) {
					if (item.second->getCoordinates().x == tmp.x && item.second->getCoordinates().y == tmp.y) {
						if (item.second->getRobotClass() == RobotClass::explorer) {
							std::cout << "E ";
						}
						else if (item.second->getRobotClass() == RobotClass::sapper) {
							std::cout << "S ";
						}
					}
				}
				continue;
			}

			if (tmp.x >= mainRobot->getMap().getMapLength() || tmp.y >= mainRobot->getMap().getMapWidth()) {
				cout << ", ";
				continue;
			}

			if (VMode == ViewMode::GlobalMap) {
				obj = mngr->getEnvironment()->getObject(tmp);
			}
			else if (VMode == ViewMode::LocalMap) {
				obj = mngr->getRobotsMap().getObject(tmp);
			}

			if (obj == Object::unknown) std::cout << "? ";
			else if (obj == Object::apple) std::cout << "@ ";
			else if (obj == Object::bomb) std::cout << "x ";
			else if (obj == Object::empty) std::cout << ". ";
			else if (obj == Object::rock) std::cout << "# ";
			else cout << "? ";

		}
		std::cout << std::endl;
	}
	cout << "Apples collected: " << mngr->getEnvironment()->getCollectedCnt() << endl;
}

bool ConsoleView::robotInCell(vector<pair<IMode*, IRobot*>>& robots, const Coordinates &coords) {
	for (auto item : robots) {
		if (item.second->getCoordinates().x == coords.x && item.second->getCoordinates().y == coords.y) {
			return true;
		}
	}
	return false;
}