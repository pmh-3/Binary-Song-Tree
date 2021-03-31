//Heitkemper, Peter
//songbst.h
//2-17-21

//Description: The program below stores songs and their information in a binary search tree
// using a linked implementation. The driver automatically populates tree by reading in a local csv file. 
//User can choose to get information or remove a song. The song with the most number of weeks on the chart is returned.

//ASSUMPTIONS: This code will operate succesfully as long as there are no errors in the csv file. 
//User input is case sensitive. No two songs will have the same name. A song cannot appear on the chart more
//than there are weeks in the year.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;			                                                             

class SongBST {
public:

  SongBST();
 
  ~SongBST() {
    makeEmpty(root);                                                      
  }

  //default copy assignment operator
  SongBST& operator = (const SongBST& obj) {
    makeEmpty(root);
    t = obj.t;
    a = obj.a;
    d = obj.d;
    root = obj.root;
    return *this; 
  }
  //copy constructor called
  SongBST(const SongBST& rhs) : root{ nullptr }
  {
    root = clone(rhs.root); 
  }
  //inserts song and updates frequency and dates array if song appears twice
  void insert(string title, string artist, string date) {
    insertH(root, title, artist, date);                                        
  }

  //returns false if the song is not in the tree. 
  bool remove(string title) {
    if (contains(root, title)) {
      removeH(root, title);
     // cout << "true";
      return true;
    }
    return false; 
  }

  //prints the title and frequency of all the songs in the tree using an inorder traversal.
  void print() {
    printH(root);
  }

  //prints all the information about the song. Returns false if song is not in tree
  bool printSong(string title) {
    if (contains(root, title)) {
      printSongH(root, title);
      return true;
    }
    return false;
  }
  //returns the maximum number of times a single song appeared on the chart
  int topSong() {
    TreeNode* maxFreq = root;
    topSongH(root, maxFreq);   
    cout << "The top song was " << maxFreq->title;
    return maxFreq->frequency;
  }
                                                                                              
private:

  struct TreeNode {
    string title;//used as key
    string artist;
    string dates[52];//filled starting from index 0
    int frequency;    //should match # of elements in dates
    TreeNode* left;
    TreeNode* right;
  };
  string t;
  string a;
  string d;
  TreeNode* root;
  void makeEmpty(TreeNode*& n);  

  void insertH(TreeNode*& n, string t, string a, string d);
  void removeH(TreeNode*& n, string t);     
  bool contains(TreeNode* n, string t);
  void printH(TreeNode*);
  void printSongH(TreeNode* n, string title);
  void topSongH(TreeNode* n,TreeNode*& maxFreq);
  TreeNode* clone(TreeNode* n);
  TreeNode* findMin(TreeNode* n);

};
  
