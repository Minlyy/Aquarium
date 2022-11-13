/**
 * @file DecorCastle.cpp
 * @author Minsong Zheng
 */

#include "DecorCastle.h"
#include "pch.h"

using namespace std;

/// Decor filename
const wstring DecorImageName = L"images/castle.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
DecorCastle::DecorCastle(Aquarium *aquarium) : Item(aquarium, DecorImageName)
{
}

/**
 * Save this decoration to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* DecorCastle::XmlSave(wxXmlNode* node)
{
    auto itemNode = Item::XmlSave(node);
    itemNode->AddAttribute(L"type", L"castle");
    return itemNode;
}