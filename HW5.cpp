#include "HW5.h"

  
/*
 * Add your key ideas to this comment.
 * How did you approach the problem?
 * Why does your code work?
 *

if the first letter of the word exists in the letters of the
given dictionary, then check the following conditions:

a) if the word has length 1, check for the 'terminating'
character in the dictionary to see if any valid word ends
in any subtree of this dictionary
  i) return true if found
  ii) return false if not found

b) else if the word length is > 1, and more letters other than
'$' exist
  - then recurse on the remaining letters of your word and
  the dictionary
 */
bool isValidWord(TreeNode<char>* dict, std::string word) {
  for(auto letter : dict->getChildren()){
    if(letter->getValue() == word[0]){
      if(word.length() == 1){
        for (auto it : letter->getChildren()){
          if(it->getValue() == '$'){ //could replace this with 'isLeaf()'
            return true;
          }
        }
        return false;
      }
      else{
        return isValidWord(letter, word.substr(1,word.length()-1));
      }
    }
  }
  return false;
}


/*
 * Add your key ideas to this comment.
 * How did you approach the problem?
 * Why does your code work?
 *
*/

bool addWord(TreeNode<char>* dict, std::string word) {
  TreeNode<char>* found;
  for(auto child : dict->getChildren()){ 
    if(word[0] == child->getValue()){
      //lines 56-62 are for when the word is already in there
      if(word.length() == 1){
        for(auto grandchild : child->getChildren()){
          if(grandchild->getValue() == '$'){
            return false;
          }
        }
      }
      return addWord(child, word.substr(1, word.length()-1));
    }
  }
  TreeNode<char>* temp;
  for(int i=0; i<word.length(); i++){
    temp = new TreeNode<char>(word[i]);
    dict->getChildren().push_back(temp);
    dict = temp;
  }
  dict->getChildren().push_back(new TreeNode<char>('$'));
  return true;
}

void printTree(TreeNode<char>* root, int depth = 0){
  if(!root){
    return;
  }
  for(int i=1; i<depth; i++){
    std::cout << "    ";
  }
  if(!depth){
    std::cout << root->getValue() << "\n";
  }
  else{
    std::cout << "+---" << root->getValue() << "\n";
  }
  for(auto child : root->getChildren()){
    printTree(child, depth+1);
  }
  }

//int j = 0;
//   TreeNode<char>* found;
//   for(auto child : dict->getChildren()){
//     if(child->getValue() == word[j]){
//       if(word.length()-j == 1){
//         for(auto grandchild : child->getChildren()){
//           if(grandchild->getValue() == '$'){
//             return false;
//           }
//           else{
//             grandchild->getChildren().push_back(new TreeNode<char>(word[j]));
//             return true;
//           }
//         }
//       }
//       found = child;
//       j++;
//     }
//   }
  
//   TreeNode<char>* temp;
//     for(int i = j; i<word.length(); i++){
//       temp = new TreeNode<char>(word[i]);
//       found->getChildren().push_back(temp);
//       std::cout << "adding" << word[i];
//       found = temp;
//     }
//   found->getChildren().push_back(new TreeNode<char>('$'));
//   return true;
// }


  // bool found = false;
  // for(auto subdict : dict->getChildren()){
  //   if(word[0] == subdict->getValue()){
  //     if(word.length() == 1){
  //       for(auto child : subdict->getChildren()){
  //         if(child->getValue() == '$'){
  //           found = true;
  //           return false;
  //         }
  //         else{
  //           TreeNode<char>* temp = new TreeNode<char>(word[0]);
  //           temp->getChildren().push_back(new TreeNode<char>('$'));
  //           subdict->getChildren().push_back(temp);
  //           return true;
  //         }
  //       }
  //     }
  //   }
  // }
  // if(!found){
  //   TreeNode<char>* temp;
  //   for(int i=0; i<word.length(); i++){
  //     temp = new TreeNode<char>(word[i]);
  //     dict->getChildren().push_back(temp);
  //     dict = temp;
  //   }
  //   temp->getChildren().push_back(new TreeNode<char>('$'));
  //   dict->getChildren().push_back(temp);
  //   return true;
  // }

  // for(auto subdict : dict->getChildren()){
  //   if(subdict->getValue() == word[0]){
  //     if(word.length() == 1){
  //       for(auto child : subdict->getChildren()){
  //         if(child->getValue() == '$'){
  //           return false;
  //         }
  //         else{
  //           TreeNode<char>* temp = new TreeNode<char>(word[0]);
  //           temp->getChildren().push_back(new TreeNode<char>('$'));
  //           subdict->getChildren().push_back(temp);
  //           return true;
  //         }
  //       }
  //     }
  //     addWord(subdict, word.substr(1, word.length()-1));
  //   }
  // }

// if the word is only one letter, check if the letter exists
// in the given subdictionary
//   a) if there is a subdictionary whose root value is equal
//   to the length 1 string (or: last letter of the word)
//     i) if it contains a child whose value is '$'
//       - return false
//     ii) if it does not contain a child whose value is '$'
//       - signify the end of a letter by adding a terminating char
//       - and return true

// if the word length is > 1 
//   a) if the first letter of the addendum word already exists, 
//   recurse on the remaining letters
  
//   b) if not, add the letters which do not exist

// */
// bool addWord(TreeNode<char>* dict, std::string word) {
//   int dupes = 0;
//   for(auto subDict : dict->getChildren()){
//     if(subDict->getValue() == word[0]){
//       dupes++;
//       if(word.length()-dupes == 1){ //this never evaluates as true for some reason
//         for(auto child : subDict->getChildren()){
//           if(child->getValue() == '$'){
//             return false;
//           }
//         }
//         //would need to change this to be a recursive call, and add each letter as we go
//         subDict->getChildren().push_back(new TreeNode<char>('$'));
//         return true;
//       }
//       else{
//         return addWord(subDict, word.substr(dupes-1, word.length()-dupes));
//       }
//     }
//     else{ // change approach to insert current letter then remaining word?
//       TreeNode<char>* subDict;
//       for(auto insertion : word){
//         subDict = new TreeNode<char>(insertion);
//         dict->getChildren().push_back(subDict);
//         dict = subDict;
//       }
//       dict->getChildren().push_back(new TreeNode<char>('$'));
//       return true;
//     }
//   }
//   return false;
// }

// bool addWord(TreeNode<char>* dict, std::string word) {
//   for(int i=0; dict->getChildren().size(); i++){
//     if(dict->getChildren()[i]->getValue() == word[0]){
//       if(i == dict->getChildren().size()-1){
//         for(auto child : dict->getChildren()){
//           if(child->getValue() == '$'){
//             return false;
//           }
//         }
//         std::cout << 'test';
//         TreeNode<char> *temp = new TreeNode<char>(word[0]);
//         dict->getChildren()[i]->getChildren().push_back(temp);
//         temp->getChildren().push_back(new TreeNode<char>('$'));
//         return true;
//       }
//       word = word.substr(1, word.length()-1);
//     }
//     else{
//       TreeNode<char> *temp; 
//       for(int i = 0; i<word.size(); i++){
//         temp = new TreeNode<char>(word[i]);
//         dict->getChildren().push_back(temp);
//         dict = temp;
//       }
//       dict->getChildren().push_back(new TreeNode<char>('$'));
//       return true;
//     }
//   }
  
// }