#Day-1
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        for (string word : words) {
            bool consistent = true;
            for (char c : word) {
                if (allowed.find(c) == string::npos) {
                    consistent = false;
                    break;
                }
            }
            if (consistent) {
                count++;
            }
        }
        return count;
    }
};


#Day-2
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
      int n = arr.size();
    vector<int> prefixXor(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixXor[i + 1] = prefixXor[i] ^ arr[i];
    }

    vector<int> answer;
    for (auto& query : queries) {
        int left = query[0];
        int right = query[1];
        answer.push_back(prefixXor[right + 1] ^ prefixXor[left]);
    }

    return answer;
    }
};

#Day-3
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = 1;

        // step 01
        int mx = *max_element(nums.begin(),nums.end()); //O(n)

        // step 02
        int tmp_len=0;
        for(int i=0;i<nums.size();i++){ // O(n)
            if(nums[i]==mx){
                tmp_len++; // 3
            }
            else{
                len = max(len, tmp_len);
                tmp_len=0;
            }
        }

        len = max(len, tmp_len);

        return len;
    }
};


#Day-4
class Solution {
public:
    int findTheLongestSubstring(string s) {
     int n = s.size();
        int maxLen = 0;
        int bitmask = 0;
        unordered_map<int, int> seen;
        seen[0] = -1;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') bitmask ^= 1;
            if (s[i] == 'e') bitmask ^= 2;
            if (s[i] == 'i') bitmask ^= 4;
            if (s[i] == 'o') bitmask ^= 8;
            if (s[i] == 'u') bitmask ^= 16;

            if (seen.find(bitmask) != seen.end()) {
                maxLen = max(maxLen, i - seen[bitmask]);
            } else {
                seen[bitmask] = i;
            }
        }

        return maxLen;
    }
};


#Day-5
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
       vector<int> minutes;
        for (const string& time : timePoints) {
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));
            minutes.push_back(hour * 60 + minute);
        }
        sort(minutes.begin(), minutes.end());

        int minDiff = INT_MAX;
        for (int i = 1; i < minutes.size(); i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        minDiff = min(minDiff, minutes[0] + 1440 - minutes.back());

        return minDiff;
    }
};


#Day-6
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        std::unordered_map<std::string, int> freqMap;
    std::istringstream iss1(s1);
    std::istringstream iss2(s2);

    std::string word;
    while (iss1 >> word) {
        freqMap[word]++;
    }
    while (iss2 >> word) {
        freqMap[word]++;
    }

    std::vector<std::string> uncommonWords;
    for (const auto& pair : freqMap) {
        if (pair.second == 1) {
            uncommonWords.push_back(pair.first);
        }
    }

    return uncommonWords;
    }
};


#Day-7
class Solution {
public:
    string largestNumber(vector<int>& nums) {
     vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        sort(strNums.begin(), strNums.end(), [](string a, string b) {
            return a + b > b + a;
        });

        string res;
        for (string str : strNums) {
            res += str;
        }

        // Remove leading zeros
        int start = 0;
        while (start < res.size() && res[start] == '0') {
            start++;
        }
        if (start == res.size()) {
            return "0";
        }
        return res.substr(start);
    }
};


#Day-8
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
    vector<int> res;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);
                vector<int> leftRes = diffWaysToCompute(left);
                vector<int> rightRes = diffWaysToCompute(right);
                for (int l : leftRes) {
                    for (int r : rightRes) {
                        if (expression[i] == '+') res.push_back(l + r);
                        else if (expression[i] == '-') res.push_back(l - r);
                        else res.push_back(l * r);
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(expression));
        return res;
    }
};


#Day-9
class Solution {
public:
    string shortestPalindrome(string s) {
      int n = s.size();
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string lps = s + "#" + rev_s;
        int m = lps.size();
        vector<int> dp(m, 0);
        int j = 0;
        for (int i = 1; i < m; i++) {
            while (j > 0 && lps[i] != lps[j]) {
                j = dp[j - 1];
            }
            if (lps[i] == lps[j]) {
                j++;
            }
            dp[i] = j;
        }
        int k = dp[m - 1];
        return rev_s.substr(0, n - k) + s;
    }
};


#Day-10
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <= n; i++) {
            res.push_back(i);
        }
        sort(res.begin(), res.end(), [](int a, int b) {
            string sa = to_string(a), sb = to_string(b);
            return sa < sb;
        });
        return res;
    }
};


#Day-11
class Solution {
public:
    int findKthNumber(int n, int k) {
     long curr = 1;
        k--;
        while (k > 0) {
            long steps = calcSteps(n, curr, curr + 1);
            if (k >= steps) {
                k -= steps;
                curr += 1;
            } else {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }

private:
    long calcSteps(int n, long n1, long n2) {
        long steps = 0;
        while (n1 <= n) {
            steps += std::min(static_cast<long>(n) + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
};


#Day-12
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.length();
     unordered_set<string> dict(dictionary.begin(), dictionary.end());
    vector<int> dp(n + 1, n);  // Initialize with max possible value (n extra chars)

    dp[0] = 0;  // Base case: no extra characters if there's no substring

    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1;  // Start by assuming the current character is an extra one

        for (int j = 0; j < i; ++j) {
            if (dict.count(s.substr(j, i - j))) {
                dp[i] = min(dp[i], dp[j]);
            }
        }
    }

    return dp[n];
    }
};


#Day-13
struct Trie {
    Trie* next[10];
    bool isEnd = 0;

    Trie() {
        fill(next, next+10, (Trie*)NULL);
    }

    ~Trie() {
    //    cout<<"Destructor\n";
        for (int i=0; i<10; ++i) {
            if (next[i] !=NULL) {
                delete next[i];
            }
            next[i]=NULL;
        }
    }

    void insert(string&& word) {
        Trie* Node=this;
        for(char c: word){
            int i=c-'0';
            if(Node->next[i]==NULL)
                Node->next[i]=new Trie();
            Node=Node->next[i];
        }
        Node->isEnd=1;
    }

 int commonPrefix(string&& s) {
        Trie* Node = this;
        int len=0;
        for(char c : s){
            int i = c - '0';
            if(Node->next[i]==NULL) return len;
            Node = Node->next[i];
            len++;
        }
        return len;

    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
       Trie trie=Trie();
        for (int x: arr2)
            trie.insert(to_string(x));
        int maxLen=0;
        for (int x: arr1)
            maxLen=max(maxLen, trie.commonPrefix(to_string(x)));
        return maxLen;

    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

#Day-14
truct Node{
    int count=0;
    Node *list[26]={NULL};
    bool containKey(char ch){
        return list[ch-'a']!=NULL;
    }
    Node *get(char ch){
        return list[ch-'a'];
    }
    void put(char ch,Node *new_node){
        list[ch-'a']=new_node;
    }
    void inc(char ch){
        list[ch-'a']->count+=1;
    }
    int retCount(char ch){
        return list[ch-'a']->count;
    }
};
class Solution {
private:
Node *root;
public:
    Solution(){
        root=new Node;
    }
    void insert(string word){
        Node *node=root;
        for(auto ch:word){
            if(!node->containKey(ch)){
                node->put(ch,new Node);
            }
            node->inc(ch);
            node=node->get(ch);
        }
    }
    int search(string word){
        Node *node=root;
        int preCount=0;
        for(auto ch:word){
            preCount+=node->retCount(ch);
            node=node->get(ch);
        }
        return preCount;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        //This problem can be solved using the trie data structure
        for(auto word:words){
            insert(word);
        }
        int n=words.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            int preCount=search(words[i]);
            res[i]=preCount;
        }
        return res;
    }
};


#Day-15
class MyCalendar {

private:
    vector<pair<int, int>> events;  // To store the list of booked events

public:
    MyCalendar() {
        // Constructor to initialize the MyCalendar object
    }

    bool book(int start, int end) {
        for (auto& event : events) {
            // Check if there is any overlap
            if (max(event.first, start) < min(event.second, end)) {
                return false;  // If overlapping, return false
            }
        }
        // No overlap, add the event
        events.push_back({start, end});
        return true;
    }

};



