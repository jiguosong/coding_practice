/*
 * editdistance.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: songjiguo
 */

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <array>   // difference between this and vector?

class editdistance {
public:
	int minDistance(string word1, string word2) {
		int m = word1.length();
		int n = word2.length();
		int dist[m+1][n+1];

		//for(int i = 0; i < m*n; i++) dist[i/m][i%m] = 0;
		//for(auto& tt:dist) {}   -- this is another way to iterate through the array

		for(int i = 0; i <= m; i++) dist[i][0] = i;
		for(int i = 0; i <= n; i++) dist[0][i] = i;

		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				if(word1[i-1] == word2[j-1]) {
					dist[i][j] = dist[i-1][j-1];
				} else {
					dist[i][j] = min(dist[i-1][j-1], min(dist[i][j-1], dist[i-1][j])) + 1;
				}
			}
		}

		return dist[m][n];

	}
};

int main(int argc, char **argv) {
	editdistance test;
	string word1 = "asdsd";
	string word2 = "zxy";
	int ans = test.minDistance(word1, word2);
	cout << ans << endl;
}


