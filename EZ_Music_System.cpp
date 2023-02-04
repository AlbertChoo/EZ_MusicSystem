// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;
#include <iostream>
#include <string>
#include <iomanip>

struct Track {
	int index, year;
	string artist, song, genre;
	double length;
	Track* next;
};

struct Track* start = NULL;

int countNodes(Track* head) {
	int count = 1;
	Track* current = head;
	while (current != nullptr) {
		count++;
		current = current->next;
	}
	return count;
}

void addTrackAtBeginning(Track*& head, Track*& tail) {
	//There is no validation in the code below

	Track* newTrack = new Track();
	cout << "Enter artist name: ";
	cin >> newTrack->artist;
	cout << "Enter song name: ";
	cin >> newTrack->song;
	cout << "Enter year released: ";
	cin >> newTrack->year;
	cout << "Enter genre type: ";
	cin >> newTrack->genre;
	cout << "Enter length of the song: ";
	cin >> newTrack->length;

	newTrack->index = countNodes(head);

	if (head == nullptr) {
		head = newTrack;
		tail = newTrack;
	}
	else {
		newTrack->next = head;
		head = newTrack;
	}
}

void addTrackAtEnd(Track*& head, Track*& tail) {
	Track* newTrack = new Track();
	cout << "Enter artist name: ";
	cin >> newTrack->artist;
	cout << "Enter song name: ";
	cin >> newTrack->song;
	cout << "Enter year released: ";
	cin >> newTrack->year;
	cout << "Enter genre type: ";
	cin >> newTrack->genre;
	cout << "Enter length of the song: ";
	cin >> newTrack->length;

	newTrack->index = countNodes(head);

	tail->next = newTrack;
	tail = newTrack;
}

void displayTrackListNoSort(Track*& head) {
	Track* current = head;
	cout << "Current Track List:" << endl;
	cout << "Index\tArtist\t\t\tSong\t\t\tReleased\tGenre\tLength" << endl;
	while (current != nullptr) {
		cout << left <<setw(2) << current->index
			<< "\t" << left << setw(20) << current->artist
			<< "\t" << left << setw(20) << current->song
			<< "\t" << left << setw(6) << current->year
			<< "\t\t" << left << setw(6) << current->genre
			<< "\t" << left << setw(6) << fixed << setprecision(2) <<
			current->length
			<< endl;

		//fixed << setprecision(2) is to display the floating point number
		//with a specific number of decimal places, 4.30 -> 4.30 instead of 4.3

		current = current->next;
	}
}

void TrackListSort(Track*& head) {
	Track* ptr1 = head;
	Track* ptr2;
	int tempIndex, tempYear;
	string tempArt, tempSong, tempGen;
	double tempLen;

	while (ptr1->next != NULL) {
		ptr2 = ptr1->next;
		while (ptr2 != NULL) {
			if (ptr1->index > ptr2->index) {
				tempIndex = ptr1->index;
				tempArt = ptr1->artist;
				tempSong = ptr1->song;
				tempYear = ptr1->year;
				tempGen = ptr1->genre;
				tempLen = ptr1->length;

				ptr1->index = ptr2->index;
				ptr1->artist = ptr2->artist;
				ptr1->song = ptr2->song;
				ptr1->year = ptr2->year;
				ptr1->genre = ptr2->genre;
				ptr1->length = ptr2->length;

				ptr2->index = tempIndex;
				ptr2->artist = tempArt;
				ptr2->song = tempSong;
				ptr2->year = tempYear;
				ptr2->genre = tempGen;
				ptr2->length = tempLen;
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}


int main() {
	Track* head = nullptr;
	Track* tail = nullptr;

	head = new Track();
	head->index = 1;
	head->artist = "Celien Dion";
	head->song = "Just Walk Away";
	head->year = 1993;
	head->genre = "Pop";
	head->length = 4.58;
	head->next = new Track();

	head->next->index = 2;
	head->next->artist = "Taylor Swift";
	head->next->song = "You Belong With Me";
	head->next->year = 2008;
	head->next->genre = "Pop";
	head->next->length = 3.48;
	head->next->next = new Track();

	head->next->next->index = 3;
	head->next->next->artist = "The Cranberries";
	head->next->next->song = "Promises";
	head->next->next->year = 1999;
	head->next->next->genre = "Rock";
	head->next->next->length = 4.30;
	head->next->next->next = nullptr;
	tail = head->next->next;

	Track* current = head;
	int no = 1;
	cout << "Current Track List:" << endl;
	cout << "Index\tArtist\t\t\tSong\t\t\tReleased\tGenre\tLength" << endl;
	while (current != nullptr) {
		cout << no << "\t" << left << setw(20) << current->artist
			<< "\t" << left << setw(20) << current->song
			<< "\t" << left << setw(6) << current->year
			<< "\t\t" << left << setw(6) << current->genre
			<< "\t" << left << setw(6) << fixed << setprecision(2) << 
			current->length
			<< endl;

		current->index = no;
		current = current->next;
		no++;
	}
	
	cout << "\nFunction 1: Add new track at the beginning of the track list: " << endl;
	addTrackAtBeginning(head, tail);

	cout << "\nFunction 2: Add new track at the end of the track list: " << endl;
	addTrackAtEnd(head, tail);

	cout << "\nFunction 3: Display the Track List after Changes without sorting: " << endl;
	displayTrackListNoSort(head);

	cout << "\nFunction 4: Display the sorted Track List after Changes: " << endl;
	TrackListSort(head);
	displayTrackListNoSort(head);

	return 0;
};
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
