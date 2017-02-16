#include "Application.h"
using namespace std;

void Application::runApplication() const {
	int opt = -1;
	while (opt != 0) {
		cout << "Welcome to the Matrix Library!" << endl;

		cout << "\n1. Add two matrices" << endl;
		cout << "2. Subtract two matrices" << endl;
		cout << "3. Transpose two matrices" << endl;

		cout << "\n Please select from the options: " << flush;
		cin >> opt;

		if (opt == 1) {
			cout << "\n Okay, let's add two matrices!" << endl;
			cout << "Enter the file that contains the first matrix: " << flush;
			string fileName;
			cin >> fileName;
			Matrix m1;
			m1.readFrom(fileName);
			cout << "\nHere is the first matrix: " << endl;
			m1.writeTo(cout);

			cout <<"\nPlease enter a second matrix: " << flush;
			string fileName2;
			cin >> fileName2;
			Matrix m2;
			m2.readFrom(fileName2);
			cout << "\nHere is your second matrix: " << flush;
			m2.writeTo(cout);

			cout << "\nHere are the added matrices: " << endl;
			Matrix m3 = m1 + m2;
			m3.writeTo(cout);
		}

		else if (opt == 2) {
			cout << "\n Okay, let's subtract two matrices!" << endl;
			cout << "Enter the file that contains the first matrix: " << flush;
			string fileName3;
			cin >> fileName3;
			Matrix m3;
			m3.readFrom(fileName3);
			cout << "\nHere is the first matrix: " << endl;
			m3.writeTo(cout);

			cout <<"\nPlease enter a second matrix: " << flush;
			string fileName4;
			cin >> fileName4;
			Matrix m4;
			m4.readFrom(fileName4);
			cout << "\nHere is your second matrix" << flush;
			m4.writeTo(cout);

			cout <<"\n Here are the added matrices: " << endl;
			Matrix m5 = m3 - m4;
			m5.writeTo(cout);
		}

		else if (opt == 3) {
			cout << "\n Okay, let's transpose two matrices!" << endl;
			cout << "Enter the file that contains the first matrix: " << flush;
			string fileName5;
			cin >> fileName5;
			Matrix m6;
			m6.readFrom(fileName5);
			cout << "\nHere is the first matrix: " << endl;
			m6.writeTo(cout);

			cout <<"\n Here is the transposed matrix: " << endl;
			Matrix m8 = m6.getTranspose();
			m8.writeTo(cout);
		}
		else if (opt == 0) {
			cout << "\n Goodbye!" << endl;
		}
	}

}
