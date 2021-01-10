#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";
	int arr[4][3] = { 0, }, size = numbers.size();
	pair<int, int> left = { 3,0 }, right = { 3,2 };
	for (int i = 0; i < size; ++i) {
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
			answer.push_back('L');
			left.second = 0;
			if (numbers[i] == 1) left.first = 0;
			else if (numbers[i] == 4) left.first = 1;
			else if (numbers[i] == 7) left.first = 2;
		}
			
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
			answer.push_back('R');
			right.second = 2;
			if (numbers[i] == 3) right.first = 0;
			else if (numbers[i] == 6) right.first = 1;
			else if (numbers[i] == 9) right.first = 2;
		}
			
		else {
			pair<int, int> temp;
			temp.second = 1;
			if (numbers[i] == 2)temp.first = 0; 
			else if (numbers[i] == 5)temp.first = 1;
			else if (numbers[i] == 8)temp.first = 2;
			else if (numbers[i] == 0)temp.first = 3;
			int dis_L = abs(temp.first - left.first) + abs(temp.second - left.second);
			int dis_R = abs(temp.first - right.first) + abs(temp.second - right.second);
			if (dis_L < dis_R) answer.push_back('L');
			else if (dis_L > dis_R) answer.push_back('R');
			else {
				if(hand == "right")answer.push_back('R');
				else answer.push_back('L');
			}
			if (answer[i] == 'L') {
				left.first = temp.first; left.second = temp.second;
			}
			else {
				right.first = temp.first; right.second = temp.second;
			}
		}
	}
	return answer;
}