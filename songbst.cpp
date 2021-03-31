#include "songbst.h"

SongBST::SongBST() :t{ }, a{ }, d{ }, root{ nullptr }{}                        


SongBST::TreeNode* SongBST::clone(TreeNode* n) {
  if (n == nullptr){ return nullptr; }
    
  TreeNode* copyObj = new TreeNode;

  copyObj->title = n->title;
  copyObj->artist = n->artist;
  copyObj->dates[51] = n->dates[51];
  copyObj->frequency = n->frequency;
  copyObj->left = clone(n->left);
  copyObj->right = clone(n->right);
  return copyObj;
   // return new TreeNode{ n->title, n->artist, n->dates[52], n->frequency,clone(n->left),clone(n->right) };
}

  void SongBST::insertH(TreeNode*& n, string t, string a, string d) {
    if (n == nullptr) {
      n = new TreeNode;
      n->title = t;
      n->artist = a;
      n->dates[0] = d;
      n->frequency = 1;
      n->left = nullptr;
      n->right = nullptr;
    }
    else if (n->title > t) {
      insertH(n->left, t, a, d);
    }
    else if (n->title < t) {
      insertH(n->right, t, a, d);
    }
    else if (n->title == t) {
      n->dates[n->frequency++] = d;
    }
    else
      cout << "uh oh";
  }
  bool SongBST::contains(TreeNode* n, string t) {
    if (n == nullptr) {
      return false;
    }
    if (n->title == t) {
      return true;
    }

    bool flag1 = contains(n->left, t);
    if (flag1) return true;

    bool flag2 = contains(n->right, t);
    return flag2;
  }

  void SongBST::removeH(TreeNode*& n, string t) {
    //passing in root as n
    if (!n) {
      
      return;
    }
    else if (t < n->title) {     
     removeH(n->left, t);
    }
    else if (t > n->title) {
     removeH(n->right, t);

    }
    //k=n->key

    //2 children
    else if (n->left && n->right) {
       n->title = findMin(n->right)->title;
       removeH(n->right, n->title);
       //cout << "Break5" << endl;
       
    }
    else {
      TreeNode* oldNode = n;
      //replace with child
      n = (n->left) ? n->left : n->right;
      delete oldNode;
      //cout << "Break6" << endl;
      return;
    }
  }

  SongBST::TreeNode* SongBST::findMin(TreeNode* n) {     
    if (!n) {
      return nullptr;
    }
    if (!n->left)
      return n;
    return findMin(n->left);
  }

  void SongBST::printH(TreeNode* n) {
    if (!n) {
      return;
    }
    printH(n->left);
    cout << n->title << " x " << n->frequency << endl;
    printH(n->right);
  }

  void SongBST::printSongH(TreeNode* n, string title) {
    if (!n) {
      return;
    }
      printSongH(n->left, title);
      printSongH(n->right, title);
      if (n->title == title) {
        cout << "Title: " << n->title << endl;
        cout << "Artist: " <<  n->artist << endl;
        cout <<"Appeared on the Billboard chart " << n->frequency << " times on: " << endl;
        for (int i = 0; i < (n->frequency); i++) {
          cout << n->dates[i] << endl;
        }
      return;    
    }
  }

 void SongBST::topSongH(TreeNode* n, TreeNode*& maxFreq) {
    if (n) {
      topSongH(n->left,maxFreq);
      topSongH(n->right,maxFreq);
      if (n->frequency > maxFreq->frequency)
        maxFreq = n;
    }
    return;
  }

  void SongBST::makeEmpty(TreeNode*& n) {                                    
    if (n) {
      makeEmpty(n->right);
      makeEmpty(n->left);
      //cout << "deleting: " << n->value << endl;
      delete n;
    }
    return;
  }

