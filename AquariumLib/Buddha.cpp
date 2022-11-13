/**
 * @file Buddha.cpp
 * @author Minsong Zheng
 */

#include "pch.h"
#include "Buddha.h"
using namespace std;

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 40;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedX = 30;

/// Fish filename
const wstring BuddhaImageName = L"images/buddha.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
Buddha::Buddha(Aquarium *aquarium) : Fish(aquarium, BuddhaImageName)
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
wxXmlNode* Buddha::XmlSave(wxXmlNode* node)
{
    auto itemNode = Fish::XmlSave(node);
    itemNode->AddAttribute(L"type", L"buddha");
    return itemNode;
}