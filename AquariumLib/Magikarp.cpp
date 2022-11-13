/**
 * @file Magikarp.cpp
 * @author Minsong Zheng
 */

#include "pch.h"
#include "Magikarp.h"
using namespace std;

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 200;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedX = 200;

/// Fish filename
const wstring MagikarpImageName = L"images/magikarp.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
Magikarp::Magikarp(Aquarium *aquarium) : Fish(aquarium, MagikarpImageName)
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
wxXmlNode* Magikarp::XmlSave(wxXmlNode* node)
{
    auto itemNode = Fish::XmlSave(node);
    itemNode->AddAttribute(L"type", L"magikarp");
    return itemNode;
}
