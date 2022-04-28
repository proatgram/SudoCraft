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
		struct jungle {
			struct water {
				static float max;
				static float min;
			};
			struct grass {
				static float max;
				static float min;
			};
			struct sand {
				static float max;
				static float min;
			};
			static uint16_t treeDisplacement;
			static uint16_t treeFrequency;
		};
		struct plains {
			struct grass {
				static float min;
				static float max;
			};
			struct water {
				static float min;
				static float max;
			};
			struct sand {
				static float min;
				static float max;
			};
			struct gravel {
				static float min;
				static float max;
			};
		};
		struct ocean {
			struct water {
				static float min;
				static float max;
			};
			struct gravel {
				static float min;
				static float max;
			};
			struct sand {
				static float min;
				static float max;
			};
		};
	};
	struct Math {
		static bool inRange(float min, float max, float val);
		struct Map {
			static double Double(double x, double in_min, double in_max, double out_min, double out_max) {
  				return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
			}
			static float Float(float x, float in_min, float in_max, float out_min, float out_max) {
  				return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
			}
			static int Int(int x, int in_min, int in_max, int out_min, int out_max) {
  				return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
			}
		};
	};
};
#endif
