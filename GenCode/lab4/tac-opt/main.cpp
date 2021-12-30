#include<bits/stdc++.h>

using namespace std;

map<long, string> instMap;
map<long, vector<string> > basicBlock;
set<long> leaders;
vector<vector<long> > bbgraph;
vector<pair<long, long> > loop_detected;
vector<vector<long> > doms;

long to_int(string val) {
	istringstream ss(val);
	long x;
	ss >> x;
	return x;
}

void genFlowGraph() {
	bbgraph.resize(basicBlock.size());
	for (auto it = basicBlock.begin(); it!=basicBlock.end(); it++) {
		string lastStmt = it->second.back();
		long ind = lastStmt.rfind("goto");
		if (ind != -1) {
			bbgraph[it->first].push_back(to_int(lastStmt.substr(ind + 5)));
			if (ind!=0 && it->first!=basicBlock.size() - 1) {
				bbgraph[it->first].push_back(it->first + 1);
			}
		} else {
			if (it->first!=basicBlock.size() - 1)
				bbgraph[it->first].push_back(it->first + 1);
		}
	}
}
void displayFlowGraph() {
	cout << "Flow Graph:" << endl;
	for (long i = 0; i < bbgraph.size(); i++) {
		cout << i << ": ";
		for (long j = 0; j < bbgraph[i].size(); j++) {
			cout << bbgraph[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
}

void findLeaders() {
	bool flag = true;
	for (auto it = instMap.begin(); it!=instMap.end(); it++) {
		if (flag) {
			leaders.insert(it->first);
			int ind = it->second.rfind("goto");
			if (ind!=-1) {
				leaders.insert(to_int(it->second.substr(ind + 5)));
				flag = true;
				continue;
			}
			flag = false;
		}

		int ind = it->second.rfind("goto");

		if (ind!=-1) {
			leaders.insert(to_int(it->second.substr(ind + 5)));
			flag = true;
			continue;
		}
	}
}
void displayLeaders() {
	cout << "Leaders:" << endl;
	for (auto it = leaders.begin(); it!=leaders.end(); it++) {
		cout << *it << endl;
	}
}
void genBasicBlock() {
	findLeaders();
	map<long, long> lineToBlock;
	long bbno = -1;
	for (auto it = instMap.begin(); it!=instMap.end(); it++) {
		if (leaders.find(it->first)!=leaders.end()) {
			bbno++;
		}

		lineToBlock[it->first] = bbno;
	}
	bbno = -1;

	for (auto it = instMap.begin(); it!=instMap.end(); it++) {
		if (leaders.find(it->first)!=leaders.end()) {
			bbno++;
		}
		int ind = -1;
		string bbinst = it->second;
		if ((ind = it->second.rfind("goto"))!=-1) {
			bbinst = it->second.substr(0, ind + 5) + to_string(lineToBlock[to_int(it->second.substr(ind + 5))]);
		}
		basicBlock[bbno].push_back(bbinst);
	}
}
void displayBasicBlocks() {
	cout << "Basic Blocks:" << endl;
	for (auto it = basicBlock.begin(); it!=basicBlock.end(); it++) {
		cout << "Block " << it->first << ":" << endl;
		for (long i = 0; i < it->second.size(); i++) {
			cout << "\t" << it->second[i] << endl;
		}
		cout << endl;
	}
}

void displayInst() {
	cout << "Three Address Statements:" << endl;
	for (auto it = instMap.begin(); it!=instMap.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;
}

void DFS_util(int v, bool visited[], int skip) {
	// Mark the current node as visited and
	// print it
	visited[v] = true;

	// Recur for along the vertices adjacent
	// to this vertex
	vector<long>::iterator i;
	for (i = bbgraph[v].begin(); i!=bbgraph[v].end(); ++i)
		if (!visited[*i] && (*i!=skip))
			DFS_util(*i, visited, skip);
}

void DFS(int v, bool visited[]) {
	// Mark the current node as visited and
	// print it
	visited[v] = true;

	// Recur for all the vertices adjacent
	// to this vertex
	vector<long>::iterator i;
	for (i = bbgraph[v].begin(); i!=bbgraph[v].end(); ++i)
		if (!visited[*i])
			DFS(*i, visited);
}

void dominator_blocks() {
	int i;
	int V = bbgraph.size();
	bool visited[V];
	for (i = 0; i < V; i++) {
		visited[i] = false;
		vector<long> t;
		t.push_back(0);
		doms.push_back(t);
	}
	DFS(0, visited);
	for (i = 1; i < V; i++) {
		bool temp[V];
		int j;
		for (j = 0; j < V; j++) {
			temp[j] = false;
		}
		DFS_util(0, temp, i);
		for (j = 0; j < V; j++) {
			if (visited[j] && !temp[j]) {
				doms[j].push_back(i);
			}
		}
	}
	cout << "\n";
	cout << "All Dominator blocks for these blocks are: " << "\n";
	cout << "\n";
	for (i = 0; i < V; i++) {
		int k;
		cout << i << " : ";
		for (k = 0; k < doms[i].size(); k++) {
			cout << doms[i][k] << " ";
		}
		cout << "\n";
	}

}

bool isCyclicUtil(long v, bool visited[], bool *recStack) {
	int f = 0;
	if (!visited[v]) {
		// Mark the current node as visited and part of recursion stack
		visited[v] = true;
		recStack[v] = true;

		// Recur for all the vertices adjacent to this vertex
		vector<long>::iterator i;
		for (i = bbgraph[v].begin(); i!=bbgraph[v].end(); ++i) {
			if (!visited[*i] && isCyclicUtil(*i, visited, recStack)) {
				f = 1;
			} else if (recStack[*i]) {
				f = 1;
				loop_detected.push_back({*i, v});
			}
		}
		if (f==1) {
			return true;
		}
	}
	recStack[v] = false;  // remove the vertex from recursion stack
	return false;
}

void isCyclic() {
	int V = bbgraph.size();
	//cout << V << "\n";
	// Mark all the vertices as not visited and not part of recursion stack
	bool *visited = new bool[V];
	bool *recStack = new bool[V];
	for (int i = 0; i < bbgraph.size(); i++) {
		visited[i] = false;
		recStack[i] = false;
	}
	int f;
	f = 0;
	// Call the recursive helper function to detect cycle in different
	// DFS trees
	for (int i = 0; i < bbgraph.size(); i++) {
		if (isCyclicUtil(i, visited, recStack)) {
			f = 1;
		}
	}
	if (f==1) {
		cout << "Loop detected in the code" << "\n";
		cout << "\n";
		cout << "Total no. of loop pairs are: " << loop_detected.size() << "\n";
		cout << '\n';
		int j;
		for (j = 0; j < loop_detected.size(); j++) {
			cout << "Loop detected between blocks:" << loop_detected[j].first << " ---- " << loop_detected[j].second
				 << "\n";
		}
	} else {
		cout << "No loop detected at all" << "\n";
	}
}

void detect_unused_code() {

	//do a simple DFS from start block
	//blocks that cannot be reached from start block are dead
	int V = bbgraph.size();
	bool visited[V];

	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	DFS(0, visited);

	cout << "\nDead Code detection :\n\n";

	int flag = 0;
	for (int i = 0; i < V; i++) {
		if (visited[i]==false) {
			flag = 1;
			cout << "basic block number: " << i << " is a dead code" << "\n";
		}
	}

	if (!flag) {
		cout << "No Dead code detected" << "\n";
	}

}

//splits the given 3 address instruction
std::vector<std::string> split_expression(string str) {

	string word = "";
	vector<string> result;
	for (auto x : str) {
		if (x==' ') {
			result.push_back(word);
			word = "";
		} else {
			word = word + x;
		}
	}
	result.push_back(word);
	return result;
}

//comnines the splitted expression into a single string
string combine_expression(std::vector<std::string> res) {
	string result = "";
	int i = 0;
	for (i = 0; i < res.size(); i++) {
		result += res[i];
		if (i!=res.size() - 1) {
			result += " ";
		}
	}

	return result;
}

//checks if expression is normal assignment or
//arithmetic computation
int is_candidate_of_optimization(string exp) {
	vector<string> res = split_expression(exp);

	if (res.size()==5) {

		return 1;
	}
	return 0;
}

//checks if expression is not a goto or a conditional
int is_arithmetic_expr(string exp) {
	int is_goto = exp.find("goto");
	int is_if = exp.find("if");
	if (is_goto==-1 && is_if==-1) {
		return 1;
	}

	return 0;
}

//cheks if number is perfect power of 2
bool is_power_of_two(string s) {
	int n = stoi(s);
	if (n==0) {
		return false;
	}

	return (ceil(log2(n))==floor(log2(n)));

}

//power of 2
int cal_power(int num) {
	return (log2(num));
}

//checks if a string is a numerical value
bool is_constant(string s) {
	std::string::const_iterator it = s.begin();
	while (it!=s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it==s.end();
}

//checks if a expresion arithmetic strenght can be reduced
//via shift operations
//for simplicity assumes that constant is always present on right most
string get_reduced_expression(string exp) {
	vector<string> res = split_expression(exp);

	string operation = res[3];
	string operand = res[4];

	if (operation=="*") {
		if (is_constant(operand)) {
			if (is_power_of_two(operand)) {
				operand = to_string(cal_power(stoi(operand)));
				operation = "<<";
			}
		}
	}

	if (operation=="/") {
		if (is_constant(operand)) {
			if (is_power_of_two(operand)) {
				operand = to_string(cal_power(stoi(operand)));
				operation = ">>";
			}
		}
	}

	res[4] = operand;
	res[3] = operation;

	return combine_expression(res);

}

//eliminates neutral expressions
//assumes constant always on rightmost
string get_neutral_expression(string exp) {
	vector<string> res = split_expression(exp);

	string operation = res[3];
	string post = res[4];
	string pre = res[2];

	if (operation=="*") {
		if (post=="0") {
			post = "";
			operation = "";
			pre = "0";
		} else if (post=="1") {
			post = "";
			operation = "";
		}
	} else if (operation=="/") {
		if (post=="1") {
			post = "";
			operation = "";
		}
	} else if (operation=="+") {
		if (post=="0") {
			post = "";
			operation = "";
		}
	} else if (operation=="-") {
		if (post=="0") {
			post = "";
			operation = "";
		}
	}

	res[2] = pre;
	res[4] = post;
	res[3] = operation;

	return combine_expression(res);
}


//performs constant folding

string get_constant_folded_expression(string exp) {
	vector<string> res = split_expression(exp);

	string operation = res[3];
	string post = res[4];
	string pre = res[2];

	if (is_constant(post) && is_constant(pre)) {
		int num1 = stoi(pre);
		int num2 = stoi(post);
		int result;

		if (operation=="+") {
			result = num1 + num2;
		} else if (operation=="-") {
			result = num1 - num2;
		} else if (operation=="*") {
			result = num1*num2;
		} else if (operation=="/") {
			result = num1/num2;
		}

		pre = to_string(result);
		post = "";
		operation = "";
	}

	res[2] = pre;
	res[4] = post;
	res[3] = operation;

	return combine_expression(res);

}

void local_optimizations() {

	cout << "\n\nAfter Neutral Elimination : \n\n";
	for (map<long, vector<string> >::iterator it = basicBlock.begin(); it!=basicBlock.end(); it++) {
		cout << "Block " << it->first << ":" << endl;
		for (long i = 0; i < it->second.size(); i++) {
			if (is_arithmetic_expr(it->second[i])) {
				if (is_candidate_of_optimization(it->second[i])) {
					it->second[i] = get_neutral_expression(it->second[i]);
				}
			}
			cout << "\t" << it->second[i] << endl;
		}
		cout << endl;
	}

	cout << "\n\nAfter Constant Folding : \n\n";

	for (map<long, vector<string> >::iterator it = basicBlock.begin(); it!=basicBlock.end(); it++) {
		cout << "Block " << it->first << ":" << endl;
		for (long i = 0; i < it->second.size(); i++) {
			if (is_arithmetic_expr(it->second[i])) {
				if (is_candidate_of_optimization(it->second[i])) {
					it->second[i] = get_constant_folded_expression(it->second[i]);
				}
			}
			cout << "\t" << it->second[i] << endl;
		}
		cout << endl;
	}

	cout << "\n\nAfter Strength reduction Optimization : \n\n";

	for (map<long, vector<string> >::iterator it = basicBlock.begin(); it!=basicBlock.end(); it++) {
		cout << "Block " << it->first << ":" << endl;
		for (long i = 0; i < it->second.size(); i++) {
			if (is_arithmetic_expr(it->second[i])) {
				if (is_candidate_of_optimization(it->second[i])) {
					it->second[i] = get_reduced_expression(it->second[i]);
				}
			}
			cout << "\t" << it->second[i] << endl;
		}
		cout << endl;
	}

}

void initialize_instuction_list() {
	/* instMap[0] = "c = 5";
	 instMap[1] = "b = 5";
	 instMap[2] = "t0 = b + d";
	 instMap[3] =  "a = t0";
	 instMap[4] =  "t1 = d - a";
	 instMap[5] =  "b = t1";
	 instMap[6] =  "b = 8";
	 instMap[7] =  "t2 = b - a";
	 instMap[8] = "a = t2";
	 instMap[9] =  "if a < b goto 10";
	 instMap[10] = "b = 3";
	 instMap[11] = "goto 12" ;
	 instMap[12] = "c = d";
	 instMap[13] = "b = 9";
	 instMap[14] = "goto 0";

	 */
/*
   instMap[0] = "f = a * 2";
   instMap[1] = "i = a / 8";
   instMap[2] = "m = a * 0";
   instMap[3] = "n = a * 1";
   instMap[4] = "goto 10";
   instMap[5] = "t1 = f * i";
   instMap[6] = "f = t1";
   instMap[7] = "t2 = i + 1";
   instMap[8] = "i = t2";
   instMap[9] = "goto 1";
   instMap[10] = "goto 11";
   instMap[11] = "b = 9";
   instMap[12] = "b = c - 0";
   instMap[13] = "b = d + 0";
   instMap[14] = "b = e / 1";
   instMap[15] = "b = 7 - 2";
   instMap[16] = "b = 6 + 1";
   instMap[17] = "b = 6 / 3";
   instMap[18] = "b = 6 * 3";
   instMap[18] = "goto 1";

   */



	instMap[0] = "f = 1";
	instMap[1] = "i = 2";
	instMap[2] = "if i > x goto 8";
	instMap[3] = "t1 = f * i";
	instMap[4] = "f = t1";
	instMap[5] = "t2 = i + 1";
	instMap[6] = "i = t2";
	instMap[7] = "goto 2";
	instMap[8] = "b = 5";


	//instMap[insCount++]=inst;

}

int main() {
	initialize_instuction_list();
	displayInst();

	genBasicBlock();
	displayLeaders();
	displayBasicBlocks();
	genFlowGraph();
	displayFlowGraph();
	isCyclic();
	dominator_blocks();
	detect_unused_code();
	local_optimizations();

	return 0;
}