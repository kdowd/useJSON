
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using namespace std;
using namespace nlohmann;

// data:  https://jsonplaceholder.typicode.com/users
// video: https://www.youtube.com/watch?v=NuWQp_uAvwo


int main() {

	ifstream jsonData("simpleData.json");

	if (jsonData.is_open()) {

		json appData = json::parse(jsonData);

		//cout << setw(4) << appData[0]["address"] << endl;

		auto res = appData.find("id");

		if (res != appData.end()) {
			cout << "GOTCHA" << endl;
			cout << res.key() << " -- " << res.value() << endl;
		}

		for (auto it = appData.begin(); it != appData.end(); it++) {
			cout << it.key() << " -- " << it.value() << endl;
		}


	}
}


//int xxmain()
//{
//	ifstream jsonData("data.json");
//
//	if (jsonData.is_open()) {
//
//		json appData = json::parse(jsonData);
//
//		//cout << setw(4) << appData[0]["address"] << endl;
//
//		auto res = appData.find("id");
//
//		if (res != appData.end()) {
//			cout << "GOTCHA" << endl;
//		}
//		/*for (auto it = appData.begin(); it != appData.end(); ++it) {
//			cout << it[0].key() << endl;
//		}*/
//
//		cout << string(50, '#') << endl;
//
//		for (int i = 0; i < appData.size(); i++) {
//			cout << appData[i]["company"]["catchPhrase"].get<string>() << endl;
//		}
//
//
//
//
//
//
//		for (auto i : appData[0]) {
//			if (i.is_object()) {
//				for (auto j : i) {
//					cout << "----- " << j << endl;
//				}
//			}
//			else {
//				cout << "%%%%% " << i << endl;
//			}
//
//		}
//
//
//	}
//
//
//
//	cin.get();
//
//}

