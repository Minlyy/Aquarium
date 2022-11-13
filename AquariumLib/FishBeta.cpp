/**
 * @file FishBeta.cpp
 * @author Minsong Zheng
 */

#include "pch.h"
#include "FishBeta.h"
using namespace std;

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 20;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedX = 5;

/// Fish filename
const wstring FishBetaImageName = L"images/beta.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishBeta::FishBeta(Aquarium *aquarium) : Fish(aquarium, FishBetaImageName)
{
    std::uniform_real_distribution<> distribution(MinSpeedX, MaxSpeedX);
    double speedX = distribution(aquarium->GetRandom());
    double speedY = distribution(aquarium->GetRandom());
    SetSpeed(speedX,speedY);
}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* FishBeta::XmlSave(wxXmlNode* node)
{
    auto itemNode = Fish::XmlSave(node);
    itemNode->AddAttribute(L"type", L"beta");

    return itemNode;
}


