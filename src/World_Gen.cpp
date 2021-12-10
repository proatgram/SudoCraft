#include <cstdio>
#include <cstdint>

class wGen {
	
	public:
		int returnSeed() {
			return m_seed;
		}
		int setSeed(int seed) {
			m_seed = seed;
			return m_seed;
		}
	private:
		int m_seed = 0x00;
		
}
