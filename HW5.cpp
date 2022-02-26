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
//   a) if the first letter of the word to add already exists, 
//     return the result of recursion on the remaining letters
  
//   b) if not, add the letters which do not exist and the node
//      to signify a valid word ends here
//        return true (since we added nodes which did not already
//         exist
*/

bool addWord(TreeNode<char>* dict, std::string word) {
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
    else if(word == "" && child->getValue() == '$'){
      return false;
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


