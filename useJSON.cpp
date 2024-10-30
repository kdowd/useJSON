
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using namespace std;
using namespace nlohmann;

// test json data:  https://jsonplaceholder.typicode.com/users
// video: https://www.youtube.com/watch?v=NuWQp_uAvwo

void userNotFoundMessage(string& s) {
	cout << "Sorry user " << s << " not found." << endl;
}

void prettyPrint(json& theData) {
	// pretty print for debugging
	cout << setw(4) << theData << endl;
}

void findUserByEmail(string user_email) {
	ifstream jsonData("./users/user_1.json");

	if (jsonData.is_open()) {

		json appData = json::parse(jsonData);
		//prettyPrint(appData);

		// find the key and if found get its value and check it.
		// res == iterator
		auto res = appData.find("email");


		if ((res != appData.end()) && (res.value() == user_email)) {
			cout << "FOUND USER" << endl;
			//cout << res.key() << " -- " << res.value() << endl;

			// loop through all user details
			for (auto it = appData.begin(); it != appData.end(); it++) {

				if (it.key() == "username") {
					cout << "Welcome back " << it.value().get<string>() << ", you are logged in. \n";
				}

			}
		}
		else {
			userNotFoundMessage(user_email);
		}

	}

}



int main() {
	// test email
	// Sincere@april.biz
	cout << "Please enter your email:\n";
	string userEmail;
	cin >> userEmail;

	findUserByEmail(userEmail);

	system("pause");

}




