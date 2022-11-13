/**
 * @file Fish.h
 * @author Minsong Zheng
 *
 *
 */

#ifndef AQUARIUM_FISH_H
#define AQUARIUM_FISH_H

#include "Aquarium.h"


/**
 * Base class for a fish
 * This applies to all of the fish, but not the decor
 * items in the aquarium.
 */
class Fish : public Item {
private:
    /// Fish speed in the X direction
    /// in pixels per second
    double mSpeedX;

    /// Fish speed in the Y direction
    /// in pixels per second
    double mSpeedY;

public:
    /// Default constructor (disabled)
    Fish() = delete;

    /// Copy constructor (disabled)
    Fish(const Fish &) = delete;

/// Assignment operator
    void operator=(const Fish &) = delete;

    void Update(double elapsed);

    wxXmlNode* XmlSave(wxXmlNode* node);

    void XmlLoad(wxXmlNode* node) override;

    void SetSpeed(double x, double y);
protected:
    Fish(Aquarium* aquarium, const std::wstring& filename);

};

#endif //AQUARIUM_FISH_H
