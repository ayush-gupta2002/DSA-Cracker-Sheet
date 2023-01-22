//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends



int countRev (string str)
{
  stack<char> s;
  int cost = 0;
  stack<char> extra;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '}' && !s.empty() && s.top() == '{') {
      s.pop();
    }
    else if (str[i] == '{') {
      s.push(str[i]);
    }
    else if (str[i] == '}' && s.empty() || (str[i] == '}' && s.top() == '}')) {
      s.push(str[i]);
    }
  }
  if(s.size() % 2 != 0){
    return -1;
  }

  vector<int> cPair(2,'p');
  while (!s.empty()) {
    char topChar = s.top();
    s.pop();

    if(cPair[0] == 'p' && cPair[1] == 'p'){
      cPair[1] = topChar;
    } else if (cPair[0] == 'p') {
      cPair[0] = topChar;
      if (topChar == cPair[1]) {
        cost++;
      }
      else{
        cost += 2;
      }
      cPair[0] = 'p';
      cPair[1] = 'p';
    }
  }

  return cost;
}
