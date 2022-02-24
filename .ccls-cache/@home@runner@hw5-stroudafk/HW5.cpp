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
if the word is only one letter, check if the letter exists
in the given subdictionary
  a) if there is a subdictionary whose root value is equal
  to the length 1 string (or: last letter of the word)
    i) if it contains a child whose value is '$'
      - return false
    ii) if it does not contain a child whose value is '$'
      - signify the end of a letter by adding a terminating char
      - and return true

if the word length is > 1 
  a) if the first letter of the addendum word already exists, 
  recurse on the remaining letters
  
  b) if not, add the letters which do not exist

*/
bool addWord(TreeNode<char>* dict, std::string word) {
  for(auto subDict : dict->getChildren()){
    if(subDict->getValue() == word[0]){
      if(word.length() == 1){
        for(auto child : subDict->getChildren()){
          if(child->getValue() == '$'){
            return false;
          }
        }
        //if the word is already in there but not counted as a 
        //valid word, does it get returned as true or false?
        subDict->getChildren().push_back(new TreeNode<char>('$'));
        return true;
      }
      else{
        return addWord(subDict, word.substr(1, word.length()-1));
      }
    }
    else{
      TreeNode<char>* subDict;
      for(auto insertion : word){
        subDict = new TreeNode<char>(insertion);
        dict->getChildren().push_back(subDict);
        dict = subDict;
      }
      dict->getChildren().push_back(new TreeNode<char>('$'));
      std::cout << "test" << std::endl;
      return true;
    }
  }
  return false;
}
