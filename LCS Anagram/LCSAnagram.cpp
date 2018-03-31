/*
Sample Input 0
cde
abc
Sample Output 0
4
Explanation 0
We need to delete 4 characters to make both strings anagram i.e.  and  from first string and  and  from second string.
*/

#include <cmath>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    char s1[10010], s2[10010];
    cin >> s1 >> s2;
    int a[26] = {0};
    for(int i = 0; i < strlen(s1); i++) {
        a[s1[i] - 'a']++;   
    }
    for(int i = 0; i < strlen(s2); i++) {
        a[s2[i] - 'a']--;
    }
    long long int ans = 0;
    for(int i = 0; i < 26; i++)
        ans += abs(a[i]);/* FILL THE MISSING LINE HERE */
    cout << ans << endl;
    return 0;
}
