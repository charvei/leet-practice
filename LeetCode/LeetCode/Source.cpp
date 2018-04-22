#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public: 
	vector<int> TwoSum(vector<int>& nums, int target) {
		vector<int> result;
		int i = 1;
		for (int k = 0; k < nums.size(); k++) {
			int temp_sum = target;
			temp_sum -= nums[k];
			for (int j = i; j < nums.size(); j++) {
				if (temp_sum == nums[j]) {
					result.push_back(k);
					result.push_back(j);
					return result;
				}
			}
			i++;
		}
		result.push_back(0);
		result.push_back(0);
		return result;
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	int reverse(int x);
	void FizzBuzz();
};

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) { 
	ListNode node1 = ListNode(0);
	ListNode* current = &node1;
	int remainder = 0;
	while ((l1->next != NULL) || (l2->next != NULL) || (remainder != 0)) {
		cout << l1->val;
		int result_num = 0;
		if (l1 != NULL) {
			result_num += l1->val;
		}
		if (l2 != NULL) {
			result_num += l2->val;
		}
		result_num += remainder;
		remainder = result_num / 10;
		result_num -= remainder * 10;
		
		current->val = result_num;
		current->next = &(ListNode(1));

		current = current->next;
		
		l1 = l1->next;
		l2 = l2->next;
	}
	return &node1;
}

/*FizzBuzz - 
	- program that prints numbers 1 - 100, when multiple of 3 instead print "Fizz", when multiple of 5 instead print "Buzz",
	  when multiple of 3 and 5, print "FizzBuzz"*/
void Solution::FizzBuzz() {
	for (int i = 1; i <= 100; i++) {
		if (!(i % 3) && !(i % 5)) {
			cout << "FizzBuzz";
		}
		else if (!(i % 3)) {
			cout << "Fizz";
		}
		else if (!(i % 5)) {
			cout << "Buzz";
		}
		else {
			cout << i;
		}
		cout << endl;
	}
}

/*Reverse the digits of x. 
i.e. 312 -> 213*/
int Solution::reverse(int x) {
	int result = 0;
	while (x) {
		int temp = result * 10 + x % 10;
		result = temp;
		x /= 10;
	}
	cout << result;
	return result;
}

int main() {
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);
	Solution sol = Solution();
	vector<int> res;
	res = sol.TwoSum(nums, 9);
	for (int i : res) {
		//cout << i;
	}
	int x;

	ListNode a2 = ListNode(1);
	a2.next = &(ListNode(3));
	a2.next->next = &(ListNode(4));
	a2.next->next->next = &(ListNode(5));

	ListNode b2 = ListNode(2);
	b2.next = &(ListNode(3));
	b2.next->next = &(ListNode(4));
	b2.next->next->next = &(ListNode(5));


	//ListNode b = ListNode(4);
	//ListNode c = ListNode(3);
	//ListNode x1 = ListNode(5);
	//ListNode y1 = ListNode(2);
	//ListNode z1 = ListNode(4);
	
	//a.next = &b;
	//b.next = &c;
	//x1.next = &y1;
	//y1.next = &z1;

	//ListNode* res1 = sol.addTwoNumbers(&a2, &b2);
	//cout << res1->val << res1->next->val << res1->next->next->val << res1->next->next->next->val << res1->next->next->next->next->val << endl;
	//	cout << b2.val << b2.next->val << b2.next->next->val;

	//sol.FizzBuzz();
	cout << "um..";
	sol.reverse(312);

	char p;
	cin >> p;
}