/****************************************************************************/
// Author- Ayden Mason
// May 9th 2019
// Counting instances of words in a file. 
// C++ 
/****************************************************************************/

#include <iostream>
#include <map>
#include <iterator> 
#include <string>
#include <algorithm>

using namespace std;

template <typename A, typename B>
multimap<B, A> flip_map(map<A,B> & src) {

    multimap<B,A> dst;

    for(typename map<A, B>::const_iterator it = src.begin(); it != src.end(); ++it)
        dst.insert(pair<B, A>(it -> second, it -> first));

    return dst;
}

int main(int argv, char *argc[]){

  std::map<string, int> MyMap;
  std::istream_iterator<string> begin(cin); 
  std::istream_iterator<string> end;
  
   while(begin != end){

     string word = *begin;

     transform(word.begin(), word.end(), word.begin(), ::tolower); 

     for (int i = 0, len = word.size(); i < len; i++){
        if (ispunct(word[i])){
          word.erase(i--, 1);
          len = word.size();
        }
     }     

    if(*begin == string("\0"))
      break;
    
    MyMap[word]++;
        *begin++;
    }
    
    multimap<int, string> reverseTest = flip_map(MyMap);

    cout << "\nContents of flipped map in descending order:\n" << endl;
    for(multimap<int, string>::const_reverse_iterator it = reverseTest.rbegin(); it != reverseTest.rend(); ++it)
        cout << it -> first << " " << it -> second << endl; 

return 0;
}   
