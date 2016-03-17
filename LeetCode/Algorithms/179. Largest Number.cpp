string largestNumber(vector<int>& num) {
    /*
    收获好多..
    lambda表达式
    transform <algorithm> 将num中的元素通过lambda表达式转换到arr中
    back_inserter <iterator>中 设置arr的后向插入
    accumlate <numeric>中 加arr..
    */
	vector<string> arr;
	arr.reserve(num.size());

	transform(num.begin(), num.end(), back_inserter(arr),
		[](int x) {return to_string(x); });
	sort(arr.begin(), arr.end(), [](string &s1, string &s2) { return s1 + s2 > s2 + s1; });
	auto result = accumulate(arr.begin(), arr.end(), string());

	return (!result.size() || result[0] == '0') ? "0" : result;
}