#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n;
vector<vector<string>> enter_split_chat;

void input() {
	string chat;
	int idx = -1;

	cin >> n;
	// 채팅을 ENTER 기준으로 split
	for(int i = 0; i < n; i++) {
		cin >> chat;
		if (chat == "ENTER") {
			enter_split_chat.push_back(vector<string>());
			idx++;
			continue;
		}
		enter_split_chat[idx].push_back(chat);
	}
}

void sol() {
	int answer = 0;

	// 각 채팅마다 중복을 제거하고, 곰곰티콘 개수를 센다.
	for (auto& chat_list : enter_split_chat) {
		sort(ALL(chat_list));
		chat_list.erase(unique(ALL(chat_list)), chat_list.end());
		answer += chat_list.size();
	}

	cout << answer;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}