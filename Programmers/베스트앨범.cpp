#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
//1. 가장 많이 재생된 장르
//2. 같은 장르에서 많이 재생된 노래
//3. 재생횟수가 같은 노래 중에서 고유 번호가 낮은 노래 먼저

struct MUSIC {
	string genres;
	int plays, idx;
};

bool cmp_genres(MUSIC a, MUSIC b) {
	return a.plays > b.plays;
}
bool cmp_music(MUSIC a, MUSIC b) {
	if (a.plays == b.plays)return a.idx < b.idx;
	return a.plays > b.plays;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	int plays_size = plays.size();
	map<string, int> m;
	for (int i = 0; i < plays_size; ++i) {
		m[genres[i]] += plays[i];
	}

	//1. 가장 많이 재생된 장르
	vector<MUSIC> most_play;
	map<string, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); ++iter) {
		most_play.push_back({ iter->first, iter->second });
	}
	sort(most_play.begin(), most_play.end(), cmp_genres);

	//2, 3 같은 장르에서 많이 재생된 노래, 고유번호 낮은 노래
	for (int i = 0; i < most_play.size();++i) {
		vector<MUSIC> temp_music;
		for (int j = 0; j < plays_size; ++j) {
			if (most_play[i].genres == genres[j])
				temp_music.push_back({ genres[j], plays[j], j });
		}
		sort(temp_music.begin(), temp_music.end(), cmp_music);
		for (int j = 0; j < temp_music.size(); ++j) {
			if (j == 2)break;
			answer.push_back(temp_music[j].idx);
		}
	}
	return answer;
}