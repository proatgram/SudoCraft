#include <functional>

#ifndef __SAFE_DATA__
#define __SAFE_DATA__

template<typename T>
class SafeData {
public:
	SafeData() {

	};

	T get() {
		return m_data;
	};

	void set(T data) {
		m_data = data;
	}

	void accessData(std::function<void(T&)> func) {
		func(m_data);
	}
private:
	T m_data;
};
#endif