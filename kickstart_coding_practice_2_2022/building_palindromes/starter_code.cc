#include <bits/stdc++.h>

using namespace std;

int positiveAnswersCount(int N, int Q, string blockCharacters, vector<int> L,
                         vector<int> R) {
  // TODO: Complete this function to count number of questions Anna can answer
  // "yes" to

  
  return 0;
}

int main() {
  int T;
  // Get number of test cases
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    int N, Q;
    // Get number of blocks and number of questions
    cin >> N >> Q;

    string blockCharacters;
    // Get the string representing the characters on the blocks
    cin >> blockCharacters;

    vector<int> L(Q), R(Q);
    for (int i = 0; i < Q; i++) {
      cin >> L[i] >> R[i];
    }

    cout << "Case #" << tc << ": "
         << positiveAnswersCount(N, Q, blockCharacters, L, R) << endl;
  }
  return 0;
}
