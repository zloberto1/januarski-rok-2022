#include <iostream>

using namespace std;

struct Date {
    int d, m, y;
};

bool IsValidDate(Date* date) {
	if((*date).y < 1900 || (*date).y > 2100) return false;

	switch((*date).m) {
	    case 2: {
	    	 if((*date).d < 1) return false;
	        else if((*date).y % 4 == 0 && (*date).d <= 29) return true;
			 else if((*date).y % 4 != 0 && (*date).d > 28) return false;
			 else return true;
			 break;
	    }
	    
	    case 1:
	    case 3:
	    case 5:
	    case 7:
	    case 8:
	    case 10:
	    case 12:{
	        if((*date).d < 1 || (*date).d > 31) return false;
			 else return true;
			 break;
	    }
	    
	    case 4:
	    case 6:
	    case 9:
	    case 11: {
	        if((*date).d < 1 || (*date).d > 30) return false;
			 else return true;
			 break;
	    }
	    
	    default: {
	        return false;
	    }
	}
}

struct Student {
    int studentID;
    char studentName[32];
    Date DateOfBirth;
    float AverageGrade;

    void NewStudent();
    void ShowStudent();
};

void Student::NewStudent() {
    cout << "Unesite broj indeksa studenta: "; cin >> studentID;

    cout << "Unesite ime i prezime studenta: ";
    cin.ignore();
    cin.getline(studentName, sizeof(studentName));

    do {
        cout << "Unesite dan rodjenja studenta: "; cin >> DateOfBirth.d;
        cout << "Unesite mjesec rodjenja studenta: "; cin >> DateOfBirth.m;
        cout << "Unesite godinu rodjenja studenta: "; cin >> DateOfBirth.y;
        if(!IsValidDate(&DateOfBirth)) {
            cout << " !!! POGRESAN UNOS !!! " << endl;
        }
    } while(!IsValidDate(&DateOfBirth));

    cout << "Unesite prosjek studenta: "; cin >> AverageGrade;

    cout << endl;
}

void Student::ShowStudent() {
    cout << "Broj indeksa: " << studentID << endl;
    cout << "Ime i prezime: " << studentName << endl;
    cout << "Datum rodjenja: " << DateOfBirth.d << "." << DateOfBirth.m << "." << DateOfBirth.y << "." << endl;
    cout << "Prosjecna ocjena: " << AverageGrade << endl;
}

int BestRow(Student** s, int rows, int cols) {
    float tempAverage[rows];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            tempAverage[i] += (*(s + i) + j)->AverageGrade;
        }
        tempAverage[i] /= cols;
    }

    int bestRow = 0;
    for(int i = 1; i < rows; i++) {
        if(tempAverage[i] > tempAverage[bestRow]) {
            bestRow = i;
        }
    }

    return bestRow;
}

int WorstCol(Student** s, int rows, int cols) {
    float tempAverage[rows];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            tempAverage[i] += (*(s + i) + j)->AverageGrade;
        }
        tempAverage[i] /= cols;
    }

    int worstCol = 0;
    for(int i = 1; i < rows; i++) {
        if(tempAverage[i] < tempAverage[worstCol]) {
            worstCol = i;
        }
    }

    return worstCol;
}

int main()
{
    int
        rows, cols;

    do {
        cout << "Unesite broj generacija: "; cin >> rows;
    } while(rows <= 0);

    do {
        cout << "Unesite broj predmeta: "; cin >> cols;
    } while(cols <= 0);

    cout << endl;

    Student** Students = new Student*[rows];

    for(int i = 0; i < rows; i++) {
        Students[i] = new Student[cols];
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            (*(Students + i) + j)->NewStudent();
        }
    }

    cout << endl;

    for(int i = 0; i < rows; i++) {
        cout << endl << "GENERACIJA " << i + 1<< endl;
        for(int j = 0; j < cols; j++) {
            cout << endl << "PREDMET " << j + 1<< endl;
            (*(Students + i) + j)->ShowStudent();
        }
    }
    
    for(int i = 0; i < rows; i++) {
        delete[] Students[i];
    }
    
    delete[] Students;
    return 0;
}