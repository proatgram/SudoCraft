#include "Utils.h"

float Utils::BiomeConstraints::oceanMin = -0.8f;
float Utils::BiomeConstraints::oceanMax = 0.1f;

float Utils::BiomeConstraints::desertMin = 0.1f;
float Utils::BiomeConstraints::desertMax = 0.2f;

float Utils::BiomeConstraints::plainsMin = 0.2f;
float Utils::BiomeConstraints::plainsMax = 0.4f;

float Utils::BiomeConstraints::jungleMin = 0.2f;
float Utils::BiomeConstraints::jungleMax = 0.5f;

float Utils::BiomeConstraints::tundraMin = 0.5f;
float Utils::BiomeConstraints::tundraMax = 0.7f;

float Utils::BiomeConstraints::mountainMin = 0.7f;
float Utils::BiomeConstraints::mountainMax = 1.0f;

float Utils::BiomeBlockConstraints::desert::gravel::min = -1.0f;
float Utils::BiomeBlockConstraints::desert::gravel::max = 0.0f;

float Utils::BiomeBlockConstraints::desert::sand::min = 0.0f;
float Utils::BiomeBlockConstraints::desert::sand::max = 1.0f;

bool Utils::Math::inRange(float min, float max, float val) {
	if (val > max || val < min) {
		return false;
	}
	else {
		return true;
	}
}