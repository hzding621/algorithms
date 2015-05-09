#include <iostream>
#include <unordered_map>

using namespace std;

uint32_t reverseBits(uint32_t n) {
	static unordered_map<uint32_t, uint32_t> _map;

	if (_map.find(n) != _map.end())
		return _map.find(n)->first;
	uint32_t rn = 0;
	short c = (char)0;
	while (c++ < 32) {
		rn <<= 1;
		rn |= (n & 1); // extract lsb
		n >>= 1;
		// cout << rn << " ";
	}
	_map[n] = rn;
	_map[rn] = n;
	return rn;
}

int main() {

	cout << reverseBits(1) << endl;

	return 0;
}