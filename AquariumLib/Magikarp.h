/**
 * @file Magikarp.h
 * @author Minsong Zheng
 *
 * Magikarp fish class
 */

#ifndef AQUARIUM_MAGIKARP_H
#define AQUARIUM_MAGIKARP_H

#include "Items.h"
#include "Fish.h"

/**
 * Magikarp fish class
 */
class Magikarp : public Fish
{
private:

public:
    Magikarp(Aquarium* aquarium);

    /// Default constructor (disabled)
    Magikarp() = delete;

    /// Copy constructor (disabled)
    Magikarp(const Magikarp &) = delete;

    /// Assignment operator
    void operator=(const Magikarp &) = delete;

    wxXmlNode* XmlSave(wxXmlNode* node) override;
};

#endif //AQUARIUM_MAGIKARP_H
