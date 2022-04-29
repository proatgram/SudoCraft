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

float Utils::BiomeBlockConstraints::tundra::ice::min = -1.0f;
float Utils::BiomeBlockConstraints::tundra::ice::max = -0.3f;

float Utils::BiomeBlockConstraints::tundra::ice::normalIce::min = -1.0f;
float Utils::BiomeBlockConstraints::tundra::ice::normalIce::max = 0.00f;

float Utils::BiomeBlockConstraints::tundra::ice::packedIce::min = 0.00f;
float Utils::BiomeBlockConstraints::tundra::ice::packedIce::max = 1.00f;

float Utils::BiomeBlockConstraints::tundra::snow::min = -0.3f;
float Utils::BiomeBlockConstraints::tundra::snow::max = 0.00f;

float Utils::BiomeBlockConstraints::tundra::snow::normalSnow::min = -1.0f;
float Utils::BiomeBlockConstraints::tundra::snow::normalSnow::max = 0.00f;

float Utils::BiomeBlockConstraints::tundra::snow::packedSnow::min = 0.00f;
float Utils::BiomeBlockConstraints::tundra::snow::packedSnow::max = 1.00f;

float Utils::BiomeBlockConstraints::tundra::snowyGrass::min = 0.00f;
float Utils::BiomeBlockConstraints::tundra::snowyGrass::max = 1.00f;

float Utils::BiomeBlockConstraints::mountain::normal::min = -1.0f;
float Utils::BiomeBlockConstraints::mountain::normal::max = 0.00f;

float Utils::BiomeBlockConstraints::mountain::normal::rocks::min = -1.0f;
float Utils::BiomeBlockConstraints::mountain::normal::rocks::max = 0.00f;

float Utils::BiomeBlockConstraints::mountain::normal::gravel::min = 0.00f;
float Utils::BiomeBlockConstraints::mountain::normal::gravel::max = 1.00f;

float Utils::BiomeBlockConstraints::mountain::snowyGrass::min = 0.00f;
float Utils::BiomeBlockConstraints::mountain::snowyGrass::max = 0.50f;

float Utils::BiomeBlockConstraints::mountain::snow::min = 0.50f;
float Utils::BiomeBlockConstraints::mountain::snow::max = 1.00f;

float Utils::BiomeBlockConstraints::mountain::snow::regularSnow::min = -1.0f;
float Utils::BiomeBlockConstraints::mountain::snow::regularSnow::max = 0.00f;

float Utils::BiomeBlockConstraints::mountain::snow::packedSnow::min = 0.00f;
float Utils::BiomeBlockConstraints::mountain::snow::packedSnow::max = 1.00f;

bool Utils::Math::inRange(float min, float max, float val) {
	if (val > max || val < min) {
		return false;
	}
	else {
		return true;
	}
}

double Utils::Math::Map::Double(double x, double in_min, double in_max, double out_min, double out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float Utils::Math::Map::Float(float x, float in_min, float in_max, float out_min, float out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int Utils::Math::Map::Int(int x, int in_min, int in_max, int out_min, int out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
