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
          if(it->getValue() == '$'){
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
  throw std::logic_error("not implemented");
}
