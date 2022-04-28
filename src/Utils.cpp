#include "Utils.h"

float Utils::BiomeConstraints::oceanMin = 0.90f;
float Utils::BiomeConstraints::oceanMax = 1.00f;

float Utils::BiomeConstraints::desertMin = 0.00f;
float Utils::BiomeConstraints::desertMax = 0.30f;

float Utils::BiomeConstraints::plainsMin = 0.30f;
float Utils::BiomeConstraints::plainsMax = 0.90f;

float Utils::BiomeConstraints::jungleMin = -0.2f;
float Utils::BiomeConstraints::jungleMax = 0.00f;

float Utils::BiomeConstraints::tundraMin = -0.6f;
float Utils::BiomeConstraints::tundraMax = -0.2f;

float Utils::BiomeConstraints::mountainMin = -1.0f;
float Utils::BiomeConstraints::mountainMax = -0.6f;

float Utils::BiomeBlockConstraints::desert::gravel::min = -1.0f;
float Utils::BiomeBlockConstraints::desert::gravel::max = 0.30f;

float Utils::BiomeBlockConstraints::desert::sand::min = 0.30f;
float Utils::BiomeBlockConstraints::desert::sand::max = 1.00f;

float Utils::BiomeBlockConstraints::jungle::water::min = -1.0f;
float Utils::BiomeBlockConstraints::jungle::water::max = 0.30f;

float Utils::BiomeBlockConstraints::jungle::sand::min = 0.30f;
float Utils::BiomeBlockConstraints::jungle::sand::max = 0.50f;

float Utils::BiomeBlockConstraints::jungle::grass::min = 0.50f;
float Utils::BiomeBlockConstraints::jungle::grass::max = 1.00f;

uint16_t Utils::BiomeBlockConstraints::jungle::treeDisplacement = 6;
uint16_t Utils::BiomeBlockConstraints::jungle::treeFrequency = 20;

float Utils::BiomeBlockConstraints::plains::water::min = -1.0f;
float Utils::BiomeBlockConstraints::plains::water::max = -0.3f;

float Utils::BiomeBlockConstraints::plains::sand::min = -0.3f;
float Utils::BiomeBlockConstraints::plains::sand::max = -0.7f;

float Utils::BiomeBlockConstraints::plains::gravel::min = -0.7f;
float Utils::BiomeBlockConstraints::plains::gravel::max = -0.8f;

float Utils::BiomeBlockConstraints::plains::grass::min = -0.8f;
float Utils::BiomeBlockConstraints::plains::grass::max = 1.00f;

float Utils::BiomeBlockConstraints::ocean::water::min = -1.0f;
float Utils::BiomeBlockConstraints::ocean::water::max = 0.70f;

float Utils::BiomeBlockConstraints::ocean::gravel::min = 0.70f;
float Utils::BiomeBlockConstraints::ocean::gravel::max = 0.80f;

float Utils::BiomeBlockConstraints::ocean::sand::min = 0.80f;
float Utils::BiomeBlockConstraints::ocean::sand::max = 1.00f;

bool Utils::Math::inRange(float min, float max, float val) {
	if (val > max || val < min) {
		return false;
	}
	else {
		return true;
	}
}
