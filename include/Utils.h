#include "Blocks.h"

#ifndef __UTILS_H__
#define __UTILS_H__

class Utils {
public:
	struct BiomeConstraints
	{
		static float oceanMax;
		static float oceanMin;

		static float plainsMax;
		static float plainsMin;

		static float desertMax;
		static float desertMin;

		static float tundraMax;
		static float tundraMin;

		static float mountainMax;
		static float mountainMin;

		static float jungleMax;
		static float jungleMin;
	};
	struct BiomeBlockConstraints {
		struct desert {
			struct sand {
				static float max;
				static float min;
			};
			struct gravel {
				static float max;
				static float min;
			};
		};
	};
	struct Math {
		static bool inRange(float min, float max, float val);
	};
};
#endif
