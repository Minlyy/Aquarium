/**
 * @file Fish.cpp
 * @author Minsong Zheng
 */

#include "pch.h"
#include "Fish.h"
#include "Aquarium.h"
/**
 * Constructor
 * @param aquarium The aquarium we are in
 * @param filename Filename for the image we use
 */
Fish::Fish(Aquarium *aquarium, const std::wstring &filename) :
        Item(aquarium, filename)
{
}

/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * @param elapsed Time elapsed since the class call
 */
void Fish::Update(double elapsed)
{
    SetLocation(GetX() + mSpeedX * elapsed,
            GetY() + mSpeedY * elapsed);
    int wid = GetBitMapWidth();
    int height = GetBitMapHeight();
    if(mSpeedX > 0)
        SetMirror(false);
    else if(mSpeedX < 0)
        SetMirror(true);
    if (GetX() >= (GetAquarium()->GetWidth() - 10 - wid/2))
    {
        mSpeedX = -mSpeedX;
        SetMirror(true);
    }
    else if(GetX() <= 10 + wid/2)
    {
        mSpeedX = -mSpeedX;
        SetMirror(false);
    }
    else if(mSpeedY > 0 && GetY() >= (GetAquarium()->GetHeight() - 10 - height/2))
    {
        mSpeedY = -mSpeedY;
    }
    else if(mSpeedY < 0 && GetY() <= 10 + height/2)
    {
        mSpeedY = -mSpeedY;
    }
}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return wxXmlNode that we saved the item into
 */
wxXmlNode* Fish::XmlSave(wxXmlNode* node)
{
    auto itemNode = Item::XmlSave(node);
    itemNode->AddAttribute(L"SpeedX",wxString::FromDouble(mSpeedX));
    itemNode->AddAttribute(L"SpeedY",wxString::FromDouble(mSpeedY));

    return itemNode;
}

/**
 * Load the attributes for an item node.
 *
 *
 * @param node The Xml node we are loading the item from
 */
void Fish::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);
    node->GetAttribute(L"SpeedX", L"0").ToDouble(&mSpeedX);
    node->GetAttribute(L"SpeedY", L"0").ToDouble(&mSpeedY);
}

/**
 * Setter for speed
 * @param x direction speed
 * @param y direction speed
 */
void Fish::SetSpeed(double x, double y)
{
    mSpeedX = x;
    mSpeedY = y;
}