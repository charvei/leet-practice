//node script.js

/*Reverse signed 32 bit integer; i.e. 312 -> 213*/
var reverse = function(x) {
	var temp = 0;
	var result = 0;
	while (x) {
		temp = (temp * 10) + (x % 10);
		x = parseInt(x / 10);
	}
	return temp;
};

/**
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
 *
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    var result = 0;
    var temp;
    var division_test;
    for (i = 0; i < s.length; i++) {
    	temp = convert_single(s.charAt(i));
    	if (i != s.length-1) {
    		division_test = convert_single(s.charAt(i+1)) / temp;
    		if ((division_test == 5) || (division_test == 10)) {
    			temp *= -1;
    		}
    	}
    	result += temp;
    }
    return result;
};

function convert_single(roman) {
	switch (roman) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
	}
}

/*
Longest common prefix
write a function to find the longest common prefix string amongst an array of strings
if there is no common prefix return ""
*/
var LongestCommonPrefix = function(strs) {
	var result = "";
	var smallestString;
	var equalFlag = true;
	var temp;
    strs.length == 0 ? smallestString = -1 : smallestString = strs[0].length;
	for (i = 0; i < smallestString; i++) {
		for (j = 0; j < strs.length; j++) {
			if ((i == 0) && (smallestString > strs[j].length)) {
				smallestString = strs[j].length;
			}
			temp = strs[0].charAt(i);
			if (temp == strs[j].charAt(i)) {
				equalFlag = true;
			} else {
				equalFlag = false;
				break;
			}
		}
		if (equalFlag) {
			result += temp;
		} else {
			break;
		}
	}
	return result;
};


var isValid = function(s) {
	var stack = [];
	for (i = 0; i < s.length; i++) {
		if ((s.charAt(i) == '(') || (s.charAt(i) == '[') || (s.charAt(i) == '{')) {
			stack.push(s.charAt(i));
		} else {
			if ((s.charAt(i) == ')') && (stack[stack.length-1] == '(')) {
				stack.pop();
				continue;
			} else if ((s.charAt(i) == ']') && (stack[stack.length-1] == '[')) {
				stack.pop();
				continue;
			} else if ((s.charAt(i) == '}') && (stack[stack.length-1] == '{')) {
				stack.pop();
				continue;
			}
			return false;
		}
	}
	if (stack.length != 0) {
		return false;
	} else {
		return true;
	}
};

/*Reverse tests*/
//console.log(reverse(12345));

/*RomanToInt tests*/
//console.log(romanToInt("XII"));
//console.log(romanToInt("IX"));
//console.log(romanToInt("MCMXCIV"));

/*LongestCommonPrefix tests*/
//console.log(LongestCommonPrefix([]));
//console.log(LongestCommonPrefix(["cat", "car", "cart"]));

/*isValid tests*/
//console.log(isValid("()[]()(){}][{}"));
//console.log(isValid("(((((((("));
//console.log(isValid("{}})()(("));
//console.log(isValid("([{}])()[[]]"));