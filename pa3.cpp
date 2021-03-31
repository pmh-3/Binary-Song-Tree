//Heitkemper, Peter
//pa3.cpp
//2-17-21

#include "songbst.h"

int main() {

	string fileName = "top1.csv";
	string title;
	string artist;
	string date;
	string first;
	string song;

	SongBST s;

	/*
	//copy constructor 
	title = "here";
	artist = "is my";
	date = "test";
	s.insert(title, artist, date);
	SongBST b(s);
	b.printSong(title);

  //copy asignment
	SongBST a;
	a = s;
	a.printSong(title);
	*/

	cout << "Welcome! Processing the " << fileName << " file..." << endl;
	cout << endl;
	//reading in file
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "ERROR";
		return -1;
	}
	getline (file, first);	//first line discarded

	while (file.good())
	{
		getline(file, title, ',');
		//cout << title << endl;
		getline(file, artist, ',');
		//cout << artist << endl;
		getline(file, date);
		//cout << date << endl;
		s.insert(title, artist, date);
	}

	cout << "Printing the tree: " << endl;
	s.print();
	cout << endl;

	cout << "Which song would you like to print?" << endl;
	getline(cin, song);
	cout << endl;
	while (!s.printSong(song)) {
		cout << "Please enter a title that is on Billboard 100  ";
		getline(cin, song);
	}
	cout << endl;
	cout << endl;
	cout << "Which song would you like to remove?  ";

	getline(cin, song);
	while(!s.remove(song)) {
		cout << "Please enter a title that is on Billboard 100  ";
		getline(cin, song);
	}
	cout << endl;
	cout << endl;
	cout << song << " has been removed. Printing updated tree: " << endl;
	cout << endl;
	cout << endl;

	s.print();
	cout << endl;
	cout << endl;
	//TOP song
	cout << " and appeared " << s.topSong() <<" times on Billboard 100."  << endl;

	file.close();
  return 0;
}
