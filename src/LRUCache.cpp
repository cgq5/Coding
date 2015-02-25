// We made some modifications on 22/02/2015
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <utility>
// We have the key and the value.. 
// E.g. "a->b->c->d", and their corresponding values are "is, what, am, she".
//
using namespace std;
typedef pair<string, string> KV; // key value pair
class LRUCache{
private:
// Obsolete
	struct dList{
		string value;
		dList* prev; dList* next;
		dList(string v){
			value = v; prev = 0; next = 0;
		}
	};
	typedef pair<string, string> KV; // key value pair
	struct LNode{
		KV kv;
		LNode(KV key_value) : kv(key_value){}
	};
	list<LNode> cacheList;
	int capacity;
	map<string, list<LNode>::iterator> cacheMap;
public:
	LRUCache(int capacity){
		this-> capacity = capacity;
	}
	string get(string key){
		map<string, list<LNode>::iterator>::const_iterator got = cacheMap.find(key);
		if (got == cacheMap.end()){
			// cout << "not found" << endl;
			return "not found";
		}else{
			cout << "The corresonding value of " << key << "is " << got->first << endl;
		}
		// We do not need to do the re-connection if we could move the element to the front..
		cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
		LNode output = cacheList.front();
		cacheList.pop_front();
		return output.kv.second;
	}
	void set(KV kv){
		if (cacheMap.find(kv.first) == cacheMap.end()){
			if (cacheMap.size() == capacity){
				cacheMap.erase(cacheList.back().kv.first);
				cacheList.pop_back();
			}
			cacheList.push_front(LNode(kv));
			cacheMap[kv.first] = cacheList.begin();
		}
		else{ // update the key and value
			cacheList.splice(cacheList.begin(), cacheList, cacheMap[kv.first]);
			cacheMap[kv.first] = cacheList.begin();
			cacheMap[kv.first] -> kv.second = kv.second;
		}
	}
};
int main(){
	KV kv_pairs[] = {{"a", "is"}, {"b", "what"}, {"c", "am"}, {"b", "it"}};
	int capacity = 3;
	LRUCache* cache = new LRUCache(capacity);
	cache -> set(kv_pairs[0]);
	cache -> set(kv_pairs[1]);
	cache -> set(kv_pairs[2]);
	cache -> set(kv_pairs[3]);
	cout << cache -> get(kv_pairs[3].first) << endl;
	return 0;
}

